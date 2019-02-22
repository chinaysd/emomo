#ifndef __COMMAND_H__
#define __COMMAND_H__ 

#define KEY_COMPARE_TIME (INT8U)50      //去抖动处理所需的比较次数

#define KEY_LIGHT       ((INT8U)1)      //灯开关
#define KEY_PUSHRODA_H  ((INT8U)2)      //推杆升开关
#define KEY_PUSHRODA_L  ((INT8U)0)      //推杆降开关
#define KEY_MASSAGE     ((INT8U)4)      //马达开关
#define KEY_COLD        ((INT8U)3)      //制冷开关
#define KEY_LOCKER      ((INT8U)5)      //总开关，即对5个触摸按键锁住的开关

extern   INT8U   command;
extern   bit     switchState;

extern   bit     isColding;
extern   bit     isMassaging;
extern   INT16U  u16Cnt15Minutes;
extern   INT16U  u16Cnt4hours;

extern   INT8U   u8KeyValueTemp;
extern   INT8U   compareTimes;
extern   INT8U   u8ProcessKeyCnt;
extern   bit     bProcessKey ;
extern   bit     bHasResult;

extern   bit     processSender;
extern   INT8U   index;
extern   INT8U   u8Send0Cnt, u8Send1Cnt, u8SendHeaderCnt, u8SendEnderCnt, u8SenderCnt;

extern   bit     isBackLightOn;//第一个按键的指示灯


/*
 * 打开A灯
 * 第3，4bit用01表示
 * 只在带双色灯的HX25系列中生效
 */
extern  void  turnOnBackLight(void);
/*
 * 关闭A灯,蓝灯（背光灯）
 * 第3bit用0表示
 * 只在带双色灯的HX25系列中生效
 */
extern  void  turnOffBackLight(void);
/*
 * 打开B灯
 * 第3，4bit用10表示
 * 只在带双色灯的HX25系列中生效
 */
extern  void  turnOnColdLight(void);
/*
 * 关闭B灯，绿灯（制冷指示灯）
 * 第4bit用0表示
 * 只在带双色灯的HX25系列中生效
 */
extern  void  turnOffColdLight(void);

/*
 * 推杆A升高
 * 高三位用001表示
 */
extern  void  pushrodApushHigh(void);
/*
 * 推杆A降低
 * 高三位用010表示
 */
extern  void  pushrodApushLow(void);
/*
 * 推杆A动作完成
 * 高三位用000表示
 */
extern  void  pushrodAFinish(void);
/*
 * 推杆B升高
 * 高三位用101表示
 */
extern  void  pushrodBpushHigh(void);
/*
 * 推杆B降低
 * 高三位用110表示
 */
extern  void  pushrodBpushLow(void);
/*
 * 推杆B动作完成
 * 高三位用000表示
 */
extern  void  pushrodBFinish(void);
/*
 * 马达震动
 * 第2bit用1表示
 */
extern  void  turnOnMassage(void);
/*
 * 马达关闭
 * 第2bit用0表示
 */
extern  void  turnOffMassage(void);
/*
 * 打开制冷
 * 第1bit用1表示
 */
extern  void  turnOnCold(void);
/*
 * 关闭制冷
 * 第1bit用0表示
 */
extern  void  turnOffCold(void);
/*
 *使所有的触摸按键失效
 *在用户按上总开关的时候，这个方法被调用
 */
extern  void  disableAllTouchKey(void);
/*
 *使所有的触摸按键有效
 *在用户按上总开关的时候，这个方法被调用
 */
extern  void   enableAllTouchKey(void);

/*
 * 关闭机器
 * 所有数据全部重新初始化
 */
extern  void  shutDown(void);


extern void TurnOffCold_FootLight_CupLight(void);

extern  void  compareKeyValue(INT8U value); 


#endif 