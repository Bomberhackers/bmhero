#ifndef _12AF0_H
#define _12AF0_H




struct UnkStruct_800142F0
{
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
};

struct UnkStruct_80013814
{
    s32 unk0;
    s32 unk4;
    s32 unk8;
    void *unkC;
    void *unk10;
    s32 unk14;
    void *unk18;
    void *unk1C;
};

struct UnkStruct_80013948
{
    s32 unk0;
    struct UnkStruct_80013814 *unk4;
    s32 unk8;
    s32 unkC;
};

struct UnkStruct_80013754
{
    s32 unk0;
    struct UnkStruct_8001369C *unk4;
    s32 unk8;
};

struct UnkStruct_8001369C
{
    void *unk0;
    s32 unk4;
    char pad[0x24];
};

struct UnkStruct800122F0_4
{
    s32 *unk0;
    s32 unk4;
    s32 unk8;
    s32 *unkC;
    s32 *unk10;
    s32 unk14;
    s32 *unk18;
    f32 *unk1C;
}; // Size = 0x2C

struct UnkStruct800122F0_3
{
    s32 unk0;
    struct UnkStruct800122F0_4 *unk4;
    s32 unk8;
    s32 unkC;
};

struct UnkStruct800122F0_2
{
    s32 *unk0;
    s32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
}; // Size = 0x2C

struct UnkStruct800122F0_1
{
    s32 unk0;
    struct UnkStruct800122F0_2 *unk4;
    s32 unk8;
}; // Size = 0xC

struct UnkStruct800122F0
{
    char unk0[0xC];
    s32 unkC[1];
    char filler10[0x8];
    s32 unk18[1];
    char filler1C[0x2C];
    u32 unk48;
    char filler4C[0x18];
    struct UnkStruct800122F0_1 *unk64;
    s32 unk68;
    struct UnkStruct800122F0_3 *unk6C;
    s32 unk70;
    char filler70[0x86];
};

struct UnkStruct800122F0_Arg0
{
    s32 unk0;
    u32 unk4;
    u32 unk8;
};

void func_80011EF0(struct UnkStruct800122F0 *arg0);
void func_800120FC(struct UnkStruct800120FC *arg0);
void *func_800122F0(struct UnkStruct800122F0_Arg0 *arg0);
void func_8001369C(struct UnkStruct_8001369C *arg0, s32 arg1);
void func_80013754(struct UnkStruct800120FC *arg0);   
void func_80013814(struct UnkStruct_80013814 *arg0, s32 arg1);  
void func_80013948(struct UnkStruct800120FC *arg0);
void func_80013A00(struct UnkStruct800120FC *arg0); 
void func_80013AE0(f32 *arg0, f32 arg1, f32 arg2, f32 arg3);
void func_80013B70(f32 *arg0, f32 arg1, f32 arg2, f32 arg3);
void func_80013C0C(float mf1[3][4], float mf2[3][3]); 
void func_80013D68(f32 arg0[3][4], f32 arg1, f32 arg2, f32 arg3);
void func_80013F6C(f32 *arg0, f32 arg1);
void func_80014098(f32 *arg0, f32 arg1);
void func_800141C4(f32 *arg0, f32 arg1);
UNUSED void func_800142F0(Gfx *arg0, struct UnkStruct_800142F0 *arg1);
UNUSED s32 func_80014414(u8 c);
UNUSED void func_8001445C(Gfx *arg0, u8 *arg1);  
UNUSED void func_800144F4(Gfx *arg0, u8 *arg1, u8 *arg2); 
UNUSED void func_800145A8(Gfx *arg0, u32 arg1); 
UNUSED u32 func_800145C8(char *arg0);
UNUSED void func_800146F8(Gfx *arg0, char *arg1, char *arg2, char *arg3);
UNUSED void func_80014A00(Gfx *arg0, char *arg1, char *arg2);
UNUSED f32 func_80014A44(f32 arg0);
#endif /* _12AF0_H */

