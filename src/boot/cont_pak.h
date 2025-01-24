#ifndef CONT_PAK_H
#define CONT_PAK_H

/* Private */
void Debug_BackMemTest_Read_Eeprom(void);
void Debug_BackMemTest_Write2Eeeprom(void);UNUSED void Debug_BackupMemTest(void);
UNUSED void Debug_BackupMemTest_Menu(void);void Debug_BackupMemTest_Unk(void);
void Debug_ShockTest(void);
void Debug_ShockTest_Menu(void);
int GetSi_Status(void);
void func_8001EED8(void);
void func_8001EFD0(struct UnkStruct_8001EFD0 *arg0, s32 arg1);
void func_8001F088(struct UnkStruct_8001EFD0 *arg0);
void func_8001F174(struct UnkStruct_8001EFD0 *arg0, s32 arg1);
void func_8001F238(struct UnkStruct_8001EFD0 *arg0);
s32 func_8001F328(struct UnkStruct_8001EFD0 *arg0, s32 arg1, s32 arg2, OSPfsState *arg3);
s32 func_8001F38C(struct UnkStruct_8001EFD0 *arg0, s32 arg1);
s32 func_8001F4B8(struct UnkStruct_8001EFD0 *arg0, s32 arg1);
s32 func_8001F550(struct UnkStruct_8001EFD0 *arg0, s32 arg1);
s32 func_8001F5F0(struct UnkStruct_8001EFD0 *arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4);
s32 func_8001F68C(struct UnkStruct_8001EFD0 *arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4);
s32 func_8001F728(struct UnkStruct_8001EFD0 *arg0, s32 arg1, OSPfsState *arg2);
s32 func_8001F8A0(void);
s32 func_8001FB3C(s32 arg0, s32 arg1, s32 arg2);
void func_8001FBAC(void);
void func_8001FDF4(void);
void func_8001FF80(void);
void func_800200D8(void);
void func_8002021C(void);
s32 func_80021158(void);

/* Public */
s32 RestartPak(void);
void Check_PakState(void);
void Init_Pak(void);
s32 Eeprom_Read(OSMesgQueue *mq, u8 *buf, u8 addr, u16 half_bytes);
s32 Eeprom_Write(OSMesgQueue *mq, u8 *buf, u8 addr, u16 half_bytes);

#endif /* CONT_PAK_H */
