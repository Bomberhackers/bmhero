#ifndef _2BF00_H
#define _2BF00_H

struct UnkStruct_8004A6C8
{
    s32 unk0;
    s32 unk4;
};



extern UnkStruct80165100 D_800576A8[];
extern float D_8004C00C;
extern u16 sContActiveButton;
extern f64 D_8004BFB8;
extern f64 D_8004BFC0;

extern struct Vec3f D_8004A660[];
extern u8 D_8004A6C0[];
extern s32 D_8004A6C8[1][2];
extern s32 D_8004A6CC[0x11][2];

/* Function prototypes of 2BF00.c */
void Handle_ObjView(void);
void Set_ObjView(f32 viewX, f32 viewY, f32 viewZ);
void func_8002B670(void);
s32 func_8002B830(void);
s32 func_8002B894(s32 arg0);      
void func_8002B9B8(void);  
s32 func_8002BA34(void);  
void func_8002BAC8(void);  
void func_8002BE04(void);  
void func_8002C144(f32 arg0, f32 arg1, f32 arg2);  
s32 func_8002C184(f32 x, f32 y, f32 z);   
void func_8002C92C(void);  
void func_8002CA80(void);  
s32 func_8002CF78(void);  
void func_8002D080(void);  
void func_8002D128(void);  
void func_8002D538(void);  
void func_8002D768(void);  
void func_8002D8FC(void);  
void func_8002D968(void);  
void func_8002D9D4(void);  
void func_8002DCA8(void);  
void func_8002E23C(void);  
void func_8002E524(void);  
void func_8002E6E8(void);  
void func_8002E8B4(void);  
void func_8002EA68(void);  
void Debug_SetMode_Menu(void);  
void Debug_ResetMode_Menu(void);  
void Debug_SaveMode_Menu(void);  
void Debug_ParseSetModeMenu(void);  
void func_8002F000(void);  
void func_8002F32C(void);  
void func_8002F598(void);  
void func_8002F738(void);  

#endif /* _2BF00_H */
