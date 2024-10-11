#include "common.h"
#include "7B0A0.h"

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

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008E074.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008E190.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008E328.s")

void func_8008E3B0(s16* arg0) {
    u32 CurrentObject;

    CurrentObject = D_80134D48[arg0[0]].ObjectID;
    func_8001C158(CurrentObject, arg0[1], arg0[2]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008E418.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008E4A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008E788.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008E81C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008E8A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008E918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008E9DC.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008EBEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008EC3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008ECD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008ED64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008ED8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008EF8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008F078.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090A84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090B00.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80093618.s")

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
