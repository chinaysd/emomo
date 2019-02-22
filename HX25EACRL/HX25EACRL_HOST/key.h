#ifndef __KEY_H__
#define __KEY_H__

#define   PRESS_PUSHROD_TIMEOUT    (INT8U)120//单位秒，当按住推杆键超过这个时间，操作失效


extern  unsigned int   Key_Buf;		   //保存TouchKeyScan()的返回值

extern  bit		TouchKey_Flag;
extern  INT8U   u8LoadProgram;
extern  INT8U   keyStates[6];
extern  bit     Start_Counttime_A;
extern  bit     Start_Counttime_B;
extern  INT8U   Start_Counttime_Cnt;

extern	void   Keyfunction(void);

#endif