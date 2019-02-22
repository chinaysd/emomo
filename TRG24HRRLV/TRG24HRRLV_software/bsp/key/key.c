#include "key.h"
#include "timeout.h"

typedef enum {
    KEY_STATE_IDLE,
    KEY_STATE_JITTER,
    KEY_STATE_PRESS_DOWN,
    KEY_STATE_CP
} KEY_STATE;


static TIMEOUT_PARA Key_Scan_Timer,Key_Wait_Timer;
static KEY_STATE	KeyState;
static t_KEY_MSG Key_Msg;
static unsigned char PreKeyIndex = MSG_INVALID;
static void (*GetValueCb)(unsigned char);


/**
	@function: �����¼������ఴ��ʱ����Ӧ���Ӱ�������
	
*/
static xdata unsigned char KeyEvent[9][5]=
{
	//������ʼ(����)	    		�̰�								����					��������						�����ɿ�
	{MSG_KEY_NONE,					MSG_KEY_NONE,						MSG_KEY_NONE,			MSG_KEY_NONE,						MSG_KEY_NONE},			// �գ�����
	{MSG_KEY1_PRESS,				MSG_KEY1_SHORT_PRESS,				MSG_KEY1_LONGPRESS,	MSG_KEY1_LONGPRESS_HD,				MSG_KEY1_LONGPRESS_RE},		// key1
	{MSG_KEY2_PRESS,				MSG_KEY2_SHORT_PRESS,				MSG_KEY2_LONGPRESS,	MSG_KEY2_LONGPRESS_HD,				MSG_KEY2_LONGPRESS_RE},		// key2
	{MSG_KEY3_PRESS,				MSG_KEY3_SHORT_PRESS, 				MSG_KEY3_LONGPRESS, 	MSG_KEY3_LONGPRESS_HD,				MSG_KEY3_LONGPRESS_RE},	// key3	
	{MSG_KEY4_PRESS,				MSG_KEY4_SHORT_PRESS, 				MSG_KEY4_LONGPRESS, 	MSG_KEY4_LONGPRESS_HD,				MSG_KEY4_LONGPRESS_RE},	// key4	
	{MSG_KEY5_PRESS,				MSG_KEY5_SHORT_PRESS, 				MSG_KEY5_LONGPRESS, 	MSG_KEY5_LONGPRESS_HD,				MSG_KEY5_LONGPRESS_RE},	// key5
	{MSG_KEY6_PRESS,				MSG_KEY6_SHORT_PRESS, 				MSG_KEY6_LONGPRESS, 	MSG_KEY6_LONGPRESS_HD,				MSG_KEY6_LONGPRESS_RE},	// key6
	{MSG_KEY7_PRESS,				MSG_KEY7_SHORT_PRESS, 				MSG_KEY7_LONGPRESS, 	MSG_KEY7_LONGPRESS_HD,				MSG_KEY7_LONGPRESS_RE},	// key7
    {MSG_KEY8_PRESS,				MSG_KEY8_SHORT_PRESS, 				MSG_KEY8_LONGPRESS, 	MSG_KEY8_LONGPRESS_HD,				MSG_KEY8_LONGPRESS_RE},	// key7
};

/**
	@function:	��ȡ��������ֵ
	���ݰ����ĸ�������Ҫ����Ӧ���޸�
*/
static unsigned char GetKeyIndex(void)
{
	extern unsigned char Key_Port_Read(unsigned char num);
	unsigned char value = 0,cnt = 0;
    if(!Key_Port_Read(1) && !Key_Port_Read(2))
    {
      cnt ++,value = 8;  
      return value;
    }
	if(!Key_Port_Read(1))
		cnt ++,value = 1;
	if(!Key_Port_Read(2))
		cnt ++,value = 2;
	if(!Key_Port_Read(3))
		cnt ++,value = 3;
	if(!Key_Port_Read(4))
		cnt ++,value = 4;
	if(!Key_Port_Read(5))
		cnt ++,value = 5;
	if(!Key_Port_Read(6))
		cnt ++,value = 6;
	if(!Key_Port_Read(7))
		cnt ++,value = 7;
	if(cnt > 1)
		value = MSG_INVALID;
	return value;	
}

/**
	@function:IO �Ͱ���ɨ��״̬�ĳ�ʼ��
*/
void Key_Init(void){
	extern unsigned char Key_Port_Init(void);
	
	Key_Port_Init();
	KeyState=KEY_STATE_IDLE;
	TimeOut_Record(&Key_Scan_Timer,0);
}

/**
	@function:������ɨ��
	@return :t_KEY_MSG ���͵���Ϣ����Ϣ����t_KEY_MSG�ж���
*/
t_KEY_MSG Key_Scan(void){
	unsigned char KeyIndex;
	
	if(!(TimeOutDet_Check(&Key_Scan_Timer))){
		return MSG_INVALID;
	}
	
	TimeOut_Record(&Key_Scan_Timer,KEY_SCAN_TIME);
	
	KeyIndex=GetKeyIndex();
	if(KeyIndex == MSG_INVALID)
		return MSG_INVALID;

	switch(KeyState){
		case KEY_STATE_IDLE:{
			if(!KeyIndex){
				return MSG_KEY_NONE;
			}
			PreKeyIndex = KeyIndex;
			TimeOut_Record(&Key_Wait_Timer,KEY_JITTER_TIME);
			KeyState = KEY_STATE_JITTER;
			break;
		}
		
		case KEY_STATE_JITTER:{
			if(PreKeyIndex != KeyIndex){
				KeyState = KEY_STATE_IDLE;
			}else if(TimeOutDet_Check(&Key_Wait_Timer)){
				TimeOut_Record(&Key_Wait_Timer,KEY_CP_TIME);
				KeyState = KEY_STATE_PRESS_DOWN;
				return KeyEvent[PreKeyIndex][0];
			}
			break;
		}

		case KEY_STATE_PRESS_DOWN:{
			if(PreKeyIndex != KeyIndex){
				KeyState = KEY_STATE_IDLE;
				return KeyEvent[PreKeyIndex][1];
			}else if(TimeOutDet_Check(&Key_Wait_Timer)){
				TimeOut_Record(&Key_Wait_Timer,KEY_CPH_TIME);
				KeyState = KEY_STATE_CP;
				return KeyEvent[PreKeyIndex][2];
			}
			break;
		}
		
		case KEY_STATE_CP:{
			if(PreKeyIndex != KeyIndex){
				KeyState = KEY_STATE_IDLE;
				return KeyEvent[PreKeyIndex][4];
			}else if(TimeOutDet_Check(&Key_Wait_Timer)){
				TimeOut_Record(&Key_Wait_Timer,KEY_CPH_TIME);
				return KeyEvent[PreKeyIndex][3];
			}
			break;
		}
		
		default:{
			KeyState = KEY_STATE_IDLE;
			break;
		}
	}
	return MSG_INVALID;
}

void Key_Register(void (*cb)(unsigned char))
{
	if(cb){
		GetValueCb = cb;
	}
}

void Key_Poll(void)
{
	Key_Msg = Key_Scan();
	if(GetValueCb){
		GetValueCb(Key_Msg);
	}
}

