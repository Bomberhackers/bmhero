#ifndef F280_H
#define F280_H

// Public things
typedef struct UnkStruct_F280_s {
    UNK_TYPE unk0;
    Vec3f unk4;
    Vec3f unk10;
    Vec3f unk1C;
    struct UnkStruct_F280_s* unk28;
    s32 unk2C;
}UnkStruct_F280;

typedef struct  {
    s32 pad[2];
    struct UnkInputStruct8000EEE8_SPE4 unk8;
    struct UnkInputStruct8000EEE8_SPEC unkC;
}UnkStruct_F280_1;

typedef struct {
    Vec3f unk0;
    Vec3f unkC; 
    Vec3f unk18;
} UnkStruct_8000F888;

// Private
//s32 func_8000E944(Gfx** gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
s32 func_8000EEE8(Gfx** gfx, UnkStruct_F280_1* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
s32 func_8000F888(UnkStruct_8000F888* arg0, Gfx** arg1, s32 arg2, UNUSED s32 arg3, s32* unused, s32* arg5);
s32 func_8000FC08(struct UnkInputStruct8000FC08* arg0, Gfx** arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);

// Public

void Math_Mat3f_Inverse(Matrix mf, Matrix mf1);
s32 func_8000FD9C(struct UnkInputStruct8000FC08* arg0, Gfx** arg1, UnkStruct_F280_1* arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
#endif /* F280_H */
