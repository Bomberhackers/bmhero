#ifndef _BMHERO_1050_H_
#define _BMHERO_1050_H_

extern OSMesg D_8004D3F0;
extern u8 D_8004D3F8[0x318];
extern OSMesgQueue D_8004D710;
extern OSMesgQueue D_8004D728;
extern OSMesg D_8004D740;
extern struct UnkStruct80001CF0 D_8004D748;
extern OSMesgQueue *D_8004D9D0;
extern u8 D_8004D9D8[0x2000]; // unk thread stack
extern OSThread D_8004F9D8;
extern OSThread gIdleThread;
extern u8 D_8004FD38[0x1000];
extern u64 D_80050D38[0x200]; // needs to be same file to match
extern u64 gIdleThreadStack[0x200];
extern u32 D_80052D38[2];

// functions
void thread1_idle(void* arg);
void thread6_func(void* arg);
void func_80001CF0(struct UnkStruct80001CF0* arg0, void* arg1, s32 arg2, u8 arg3, u8 arg4);
void func_80001E78(struct UnkStruct80001CF0* arg0, u32* arg1, s32 arg2);
OSMesgQueue *func_80001FDC(struct UnkStruct80001CF0 *arg0);
void thread4_func(void*);
void func_80002130(struct UnkStruct80001CF0* arg0);
void func_800022A0(struct UnkStruct80001CF0* arg0);
void func_80002424(struct UnkStruct80001CF0* arg0);
s32 func_80002574(s32 arg0, struct UnkStruct80002424* arg1);
void func_8000265C(struct UnkStruct80001CF0* arg0, struct UnkStruct8000265C* arg1);
void func_800026F4(struct UnkStruct80001CF0* arg0, struct UnkStruct800026F4_Arg1* arg1, struct UnkStruct800026F4_Arg2* arg2);
void func_8000281C(struct UnkStruct80001CF0* arg0);

#endif // _BMHERO_1050_H_
