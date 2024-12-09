#include "common.h"
#include "7B0A0.h"

void func_8008E4A4(u32); 
void func_8008E788(u32, s16);                          /* extern */

//BYTECODE PARSER

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008BCC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008C128.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008C61C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008C638.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008C650.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008C66C.s")

void func_8008C684(s16* arg0) {
    s32 sp4;
    for(sp4 = 0; sp4 < 0x4E; sp4++)
    {
        if(gObjects[sp4].unkE4 == arg0[0])
        {
            D_80134D48[arg0[1]].ObjectID = sp4;
            D_80134D48[arg0[1]].unk4 = arg0[2] / 10.0f;
            D_80134D48[arg0[1]].unk8 = arg0[3] / 10.0f;
            break;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008C778.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008C9B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008CADC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008CC04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008CD2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008CE8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008D074.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008D114.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008D188.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008D3F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008D530.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008DA20.s")

void func_8008DC8C(s16* arg0) {
    u32 ObjectID;

    ObjectID = D_80134D48[arg0[0]].ObjectID;
    gObjects[ObjectID].Vel.y = arg0[1] / 10.0f;
    gObjects[ObjectID].unk4C = arg0[2] / 10.0f;
    D_80134D18[arg0[0]] = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008DD54.s")

s32 func_8008E074(s32 arg0, f32* arg1, f32 arg2) {
    struct Vec3f sp1C;

    sp1C.z = gObjects[arg0].Pos.x + gObjects[arg0].Vel.x;
    sp1C.y = gObjects[arg0].Pos.y + gObjects[arg0].Vel.y + arg2;
    sp1C.x = gObjects[arg0].Pos.z + gObjects[arg0].Vel.z;

    func_80067748(sp1C.z, sp1C.y, sp1C.x);

    *arg1 = D_80177760[1];
    return D_801776E0 & 1; 
}

void func_8008E190(s16 arg0) {
    u32 spC;
    s32 sp8;
    s16 sp6;
    s16 temp_t4;
    /*struct ObjectStruct* temp_t2;
    struct ObjectStruct* temp_t5;
    struct ObjectStruct* temp_t8;*/

    spC = D_80134D48[arg0].ObjectID;
    for(sp6 = 0; sp6 < 0xA; sp6++)
    {
        sp8 = gObjects[spC].unkE8[sp6];
        if (sp8 != -1) {
            gObjects[sp8].Rot.x = gObjects[spC].Rot.x + gObjects[spC].unk30.x; 
            gObjects[sp8].Rot.y = gObjects[spC].Rot.y + gObjects[spC].unk30.y; 
            gObjects[sp8].Rot.z = gObjects[spC].Rot.z + gObjects[spC].unk30.z; 
        }
    }
}

void func_8008E328(s16* arg0) {
    u32 sp24;

    sp24 = D_80134D48[arg0[0]].ObjectID;
    func_8008E4A4(sp24);
    func_8001C0EC((s32) sp24, D_80134FB0, (s32) arg0[1], D_80134FB4, D_80134FB8);
}

void func_8008E3B0(s16* arg0) {
    u32 CurrentObject;

    CurrentObject = D_80134D48[arg0[0]].ObjectID;
    func_8001C158(CurrentObject, arg0[1], arg0[2]);
}

void func_8008E418(s16* arg0) {
    u32 sp24;

    sp24 = D_80134D48[arg0[0]].ObjectID;
    func_8008E788(sp24, arg0[1]);
    func_8001C0EC(sp24, arg0[1], arg0[2], D_80134FB4, D_80134FB8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008E4A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008E788.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008E81C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008E8A4.s")

void func_8008E918(s16* arg0) {
    u32 sp4;

    sp4 = D_80134D48[arg0[0]].ObjectID;
    gObjects[sp4].unk5C = (f32) arg0[1] / 10.0f;
    if (arg0[2] == 1) {
        D_80134D48[arg0[0]].unkC= 1;
    } else {
        D_80134D48[arg0[0]].unkC= 0;
    }
}

void func_8008E9DC(s16 arg0) {
    u32 spC;
    UNUSED s32 sp8;
    UNUSED s32 sp4;

    spC = D_80134D48[arg0].ObjectID;
    gObjects[spC].unk3C += gObjects[spC].unk5C;
    gObjects[spC].unk44 += gObjects[spC].unk60;
    
    if(D_80134D48[arg0].unkC == 1)
    {
        gObjects[spC].Rot.y = gObjects[spC].unk3C + gObjects[spC].unk5C;
    }
}

void func_8008EAE4(s16* arg0) {
    D_80134D48[arg0[0]].unkE = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008EB10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008EB40.s")

void func_8008EB6C(s16* arg0) {
    D_80134D48[arg0[0]].unk10= 1;
}

void func_8008EB9C(s16* arg0) {
    func_8001BBDC(D_80134D48[arg0[0]].ObjectID, 1);
}

void func_8008EBEC(s16* arg0) {
    func_8001BBDC((s32) D_80134D48[arg0[0]].ObjectID, 0);
}

void func_8008EC3C(s16* arg0) {
    func_8001BB34((s32) D_80134D48[arg0[0]].ObjectID, 0);
    gObjects[D_80134D48[arg0[0]].ObjectID].unk13A = 0;
}

void func_8008ECD0(s16* arg0) {
    func_8001BB34((s32) D_80134D48[arg0[0]].ObjectID, 1);
    gObjects[D_80134D48[arg0[0]].ObjectID].unk13A = 1;
}

void func_8008ED64(s16* arg0) {
    D_80134CB8[arg0[0]] = arg0[1];
}

void func_8008ED8C(s16 arg0) {
    u32 sp2C;
    s32 sp28;
    s16 sp26;

    sp2C = D_80134D48[arg0].ObjectID;
    func_8001BB34((s32) sp2C, !(D_80134CB8[arg0] & 1));
    if (D_80134CB8[arg0] & 1) {
        gObjects[sp2C].unk13A = 0;
    } else {
        gObjects[sp2C].unk13A = 1;
    }

    for(sp26 = 0; sp26 < 0xA; sp26++)
    {
        sp28 = (s32) gObjects[sp2C].unkE8[sp26];
        if(sp28 != -1)
        {
            func_8001BB34(sp28, !(D_80134CB8[arg0] & 1));

            if (D_80134CB8[arg0] & 1)
            {
                gObjects[sp28].unk13A = 0;
            }
            else
            {
                gObjects[sp28].unk13A = 1;
            }
        }
    }
}


void ByteParser_SetObjectScale(s16* arg0) {
    u32 spC;
    UNK_TYPE UNUSED sp8;
    UNK_TYPE UNUSED sp4;

    spC = D_80134D48[arg0[0]].ObjectID;
    gObjects[spC].Scale.x = arg0[1] / 10.0f;
    gObjects[spC].Scale.y = arg0[2] / 10.0f;
    gObjects[spC].Scale.z = arg0[3] / 10.0f;
}

void func_8008F078(s16* arg0) {
    UNUSED UNK_TYPE spC;
    UNUSED UNK_TYPE sp8;
    u32 sp4;
    
    sp4 = D_80134D48[arg0[0]].ObjectID;
    gObjects[sp4].unkD8 = ((arg0[1] / 10.0f) - gObjects[sp4].Scale.x) / arg0[4];
    gObjects[sp4].unkDC = ((arg0[2] / 10.0f) - gObjects[sp4].Scale.y) / arg0[4];
    gObjects[sp4].unkE0 = ((arg0[3] / 10.0f) - gObjects[sp4].Scale.z) / arg0[4];

    D_80134CE8[arg0[0]] = arg0[4];
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008F1DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008F3D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008F63C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008F6AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008F710.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008FFB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090060.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800900DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090158.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800901EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090268.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800903CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090448.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800904DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090590.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8009060C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800906A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8009071C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090798.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090848.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800908C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090940.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800909D4.s")

void func_80090A84(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80111474, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, (f32) D_80165100->unk8);
}

void func_80090B00(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80111480, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, (f32) D_80165100->unk8);
    func_8001ABF4(sp24, 0, 0, &D_80112414);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090B94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090C10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090C8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090D08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090D84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090E50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090ECC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090F48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090FC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800910BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091138.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800911B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800912AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091328.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800913A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091420.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8009149C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091518.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091594.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091644.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800916C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8009173C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800917D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800918E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8009195C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800919F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091AA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091B34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091BC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091C44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091CC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091D8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091E3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091EB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091F4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091FE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092074.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092108.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8009219C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092218.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092294.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092310.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800923DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092458.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800924D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092568.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800925E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092680.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800926FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092790.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092824.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800928B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092954.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800929D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092A6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092AE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092B9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092C38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092CCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092D68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092E04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092EA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092F1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092FB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80093054.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800930F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8009318C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80093228.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800932C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80093374.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80093408.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80093484.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80093520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8009359C.s")

void func_80093618(void) {
    s32 sp24;
    s32 sp20;

    sp24 = func_80027464(2, &D_80111838, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, (f32) D_80165100->unk8);
    if (sp24 != -1) {
        func_80027B34(sp24, &D_80111828);
        sp20 =  (gObjects[sp24].unkE8[0]);
        func_8001ABF4(sp20, 0, 0, &D_8011698C);
        func_8001ABF4(sp20, 1, 0, &D_8011698C + (0x1C / 4));
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80093714.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80093810.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800938C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80093940.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80093968.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80093AB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80093B64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80093F30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8009409C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80094128.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800941C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80094370.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80094570.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800945E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80094680.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8009473C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8009476C.s")
