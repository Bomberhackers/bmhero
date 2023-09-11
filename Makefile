#################################################################
#                    Bomberman Hero Makefile                    #
#################################################################

BASEROM = baserom.z64
TARGET = bmhero
NON_MATCHING ?= 0
RUN_CC_CHECK ?= 1
WERROR ?= 0

# Fail early if baserom does not exist
ifeq ($(wildcard $(BASEROM)),)
$(error Baserom `$(BASEROM)' not found.)
endif

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
  HOST_OS := linux
else ifeq ($(UNAME_S),Darwin)
  HOST_OS := macos
else
  $(error Unsupported host/building OS <$(UNAME_S)>)
endif

BUILD_DIR := build
ROM := $(TARGET).z64
ELF := $(BUILD_DIR)/$(TARGET).elf
LD_SCRIPT := $(TARGET).ld
LD_MAP := $(BUILD_DIR)/$(TARGET).map
ASM_DIRS := asm asm/data asm/libultra asm/libultra/os asm/libultra/io asm/libultra/gu asm/libultra/libc asm/libultra/al asm/libultra/audio
DATA_DIRS := bin assets
SRC_DIRS := $(shell find src -type d)

C_FILES := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
S_FILES := $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s))
DATA_FILES := $(foreach dir,$(DATA_DIRS),$(wildcard $(dir)/*.bin))

# Object files
O_FILES := $(foreach file,$(C_FILES),$(BUILD_DIR)/$(file:.c=.c.o)) \
           $(foreach file,$(S_FILES),$(BUILD_DIR)/$(file:.s=.s.o)) \
           $(foreach file,$(DATA_FILES),$(BUILD_DIR)/$(file:.bin=.bin.o)) \

DEP_FILES := $(O_FILES:.o=.d) $(DECOMP_C_OBJS:.o=.asmproc.d)

SPLAT_YAML := splat.yaml
SPLAT = $(PYTHON) tools/n64splat/split.py $(SPLAT_YAML)

##################### Compiler Options #######################
findcmd = $(shell type $(1) >/dev/null 2>/dev/null; echo $$?)

ifeq ($(call findcmd,mips-linux-gnu-ld),0)
  CROSS := mips-linux-gnu-
else ifeq ($(call findcmd,mips64-elf-ld),0)
  CROSS := mips64-elf-
else ifeq ($(call findcmd,mips-elf-ld),0)
  CROSS := mips-elf-
else
  $(error Missing cross compilation toolchain)
endif

AS = $(CROSS)as
LD = $(CROSS)ld
OBJDUMP = $(CROSS)objdump
OBJCOPY = $(CROSS)objcopy
ifeq ($(HOST_OS),macos)
  CPP := clang -E -P -x c
else
  CPP := cpp
endif

#CC         := $(QEMU_IRIX) -L tools/ido7.1_compiler tools/ido7.1_compiler/usr/bin/cc
#CC_OLD     := $(QEMU_IRIX) -L tools/ido5.3_compiler tools/ido5.3_compiler/usr/bin/cc

CC = tools/ido_recomp/$(HOST_OS)/7.1/cc
CC_OLD = tools/ido_recomp/$(HOST_OS)/5.3/cc
ASMPROC = python3 tools/asmproc/build.py
ASMPROC_FLAGS :=

MIPS_VERSION := -mips2

OPTFLAGS := -g

OBJDUMP_FLAGS := -d -r -z -Mreg-names=32

# include locations
INC_DIRS := include include/PR include/audio .
IINCS := $(foreach d,$(INC_DIRS),-I$d)
# defines for SGI IDO
CDEFS := -D_LANGUAGE_C -DF3DEX_GBI_2 -DNDEBUG -D_FINALROM -DBUILD_VERSION=VERSION_H

ifneq ($(RUN_CC_CHECK),0)
  CHECK_WARNINGS := -Wall -Wextra
  CHECK_DEFS := -D_MIPS_SZLONG=32 -DNON_MATCHING
  CHECK_FLAGS := -fno-builtin -funsigned-char -fdiagnostics-color -std=gnu89 $(CDEFS) $(CHECK_DEFS) $(IINCS) -nostdinc
  CC_CHECK := gcc -fsyntax-only

  ifeq ($(HOST_OS),linux)
    CC_CHECK += -m32
  endif

  ifneq ($(WERROR),0)
    CHECK_WARNINGS += -Werror
  endif
else
  CC_CHECK := @:
endif

######################## Flags #############################

ASFLAGS = -EB -mtune=vr4300 -march=vr4300 $(IINCS) -32

# we support Microsoft extensions such as anonymous structs, which the compiler does support but warns for their usage. Surpress the warnings with -woff.
CFLAGS  = -G 0 -non_shared -Xfullwarn -Xcpluscomm $(IINCS) -Wab,-r4300_mul $(CDEFS) -woff 649,838,712,807 $(MIPS_VERSION)

LDFLAGS = -T undefined_syms_auto.txt -T undefined_funcs_auto.txt -T $(BUILD_DIR)/$(LD_SCRIPT) -Map $(BUILD_DIR)/$(TARGET).map --no-check-sections


######################## Targets #############################

$(foreach dir,$(SRC_DIRS) $(ASM_DIRS) $(DATA_DIRS) $(COMPRESSED_DIRS) $(MAP_DIRS) $(BGM_DIRS),$(shell mkdir -p build/$(dir)))

# Libultra O1 files
build/src/libultra/os/%.c.o: CC := $(CC_OLD)
build/src/libultra/os/%.c.o: OPTFLAGS := -O1
build/src/libultra/io/%.c.o: CC := $(CC_OLD)
build/src/libultra/io/%.c.o: OPTFLAGS := -O1
build/src/libultra/unknown/%.c.o: CC := $(CC_OLD)
build/src/libultra/unknown/%.c.o: OPTFLAGS := -O1

######################## Build #############################

default: all

LD_SCRIPT = $(TARGET).ld

all: $(BUILD_DIR) $(BUILD_DIR)/$(ROM) verify

distclean:
	rm -rf asm bin assets $(BUILD_DIR) undefined_syms_auto.txt undefined_funcs_auto.txt

clean:
	rm -rf $(BUILD_DIR)

submodules:
	git submodule update --init --recursive

split:
	rm -rf $(DATA_DIRS) $(ASM_DIRS) && ./tools/n64splat/split.py $(SPLAT_YAML)

setup: distclean submodules split
	
$(BUILD_DIR):
	echo $(C_FILES)
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/$(LD_SCRIPT): $(LD_SCRIPT)
	@mkdir -p $(shell dirname $@)
	$(CPP) -P -DBUILD_DIR=$(BUILD_DIR) -o $@ $<

$(BUILD_DIR)/$(TARGET).bin: $(BUILD_DIR)/$(TARGET).elf
	$(OBJCOPY) $< $@ -O binary

$(BUILD_DIR)/$(TARGET).elf: $(O_FILES) $(BUILD_DIR)/$(LD_SCRIPT)
	@$(LD) $(LDFLAGS) -o $@

$(BUILD_DIR)/%.c.o: %.c
	$(CC_CHECK) $(CHECK_FLAGS) $(CHECK_WARNINGS) -MMD -MP -MT $@ -MF $(@:.o=.d) $<
	$(CC) -c $(CFLAGS) $(OPTFLAGS) -o $@ $<

$(BUILD_DIR)/src/libultra/libc/ll.c.o: src/libultra/libc/ll.c
	$(CC) -c $(CFLAGS) $(OPTFLAGS) -o $@ $<
	python3 tools/set_o32abi_bit.py $@
	@$(OBJDUMP) $(OBJDUMP_FLAGS) $@ > $(@:.o=.s)

$(BUILD_DIR)/src/libultra/libc/llcvt.c.o: src/libultra/libc/llcvt.c
	$(CC) -c $(CFLAGS) $(OPTFLAGS) -o $@ $<
	python3 tools/set_o32abi_bit.py $@
	@$(OBJDUMP) $(OBJDUMP_FLAGS) $@ > $(@:.o=.s)

$(BUILD_DIR)/%.s.o: %.s
	iconv --from UTF-8 --to EUC-JP $^ | $(AS) $(ASFLAGS) -o $@

$(BUILD_DIR)/%.bin.o: %.bin
	$(LD) -r -b binary -o $@ $<

# final z64 updates checksum
$(BUILD_DIR)/$(ROM): $(BUILD_DIR)/$(TARGET).bin
	@cp $< $@

verify: $(BUILD_DIR)/$(ROM)
	md5sum -c checksum.md5

.PHONY: all clean distclean default split setup

print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true

-include $(DEP_FILES)
