CC := gcc
CXX := g++
CFLAGS := -I . -Wall -Wextra -Wno-unused-parameter -pedantic -std=c99 -O2 -s
CXXFLAGS := -I . -Wall -Wextra -std=c++17
LDFLAGS := -lm
PROGRAMS := n64crc

default: all

n64crc_SOURCES := n64crc.c

all: $(PROGRAMS)

clean:
	rm -Rf $(PROGRAMS) $(BUILD_DIR)

distclean: clean

n64crc: n64crc.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

$(BUILD_DIR)/%.o: %.c
	$(CC) -c $^ -o $@ $(CFLAGS)
$(BUILD_DIR)/%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

.PHONY: all clean distclean default
