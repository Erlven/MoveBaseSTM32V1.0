#ifndef CMYSERIAL_H_
#define CMYSERIAL_H_
#include "commen.h"
#define MAX_RECEIVE_ORIGNAL_BUFLEN  400
#define MAX_RECEIVE_BUFLEN 			300

#define CHANGE_ID_LEN		3
#define CHANGE_PWR_LEN  	3
#define CHANGE_ANTDELY_LEN  3
#define CHANGE_SENDPOWER_LEN_ONE  2
#define CHANGE_SENDPOWER_LEN_TWO  3
#define CHANGE_MODE_LEN 		2
#define CHANGE_CHANNEL_LEN		2
#define CHANGE_USERDATA_LEN		16
#define CHANGE_FRE_LEN			3
#define CHANGE_BAUD				4
#define CHANGE_ALLSET			11
//typedef enum {
//	CMD_OP_HELP = 0,
//	//������Ϣ
//	CMD_OP_ID,
//	CMD_OP_PWR,
//	CMD_OP_FRE,
//	CMD_OP_ANTDELAY,
//	CMD_OP_SENDPOWER,
//	CMD_OP_CHANNEL,
//	CMD_OP_MODE,
//	CMD_OP_USERDATA,
//	CMD_OP_BAUD,
//	CMD_OP_SETALL,
//	CMD_OP_UNLOCK,
//	//ģ������
//	CMD_OP_TDOA_TAG,
//	CMD_OP_TDOA_SLAVEANCHOR,
//	CMD_OP_TDOA_MASTERSLAVEANCHOR,
//	CMD_OP_NEED_TO_BE_CONFIG,
//	//������Ϣ
//	CMD_OP_DEBUG,
//	CMD_OP_MTYDEBUG,
//	//��ʾ��Ϣ
//	CMD_OP_UCANSENDDATA,
//	CMD_OP_PARAM_ERROR,
//	CMD_OP_RTCOS_ERROR,
//	CMD_OP_RTCOS_SET,
//	CMD_OP_RTC_TIME,
//	CMD_OP_RTC_COUNTDOWNERROR,
//	CMD_OP_POWER_OFF,
//	CMD_OP_RTC_START_ERROR,
//	CMD_OP_RTC_SETTIME_ERROR,
//	CMD_OP_RECEIVEUSERDATA,
//	CMD_OP_CANUSERDATASEND,
//	CMD_OP_USERDATASENDOVER,
//	CMD_OP_PARAMETER,
//	CMD_OP_TDOA_ANCHORDATA,//anchor���յ�����Ϣ
//	CMD_OP_SYNC_SENDERROR,
//	CMD_OP_BLINK_SENDERROR,
//	CMD_OP_SEQUENCE,
//	CMD_OP_WAIT_RTC_START,
//	CMD_OP_NUM
//} CMD_OP;

typedef struct CMySerial_parameter_all{
	
	char 	m_receive_buff[MAX_RECEIVE_BUFLEN];
	int 	m_receive_index;
	int 	m_receive_tail;
	char 	m_receive_orignal_buff[MAX_RECEIVE_ORIGNAL_BUFLEN];
	int 	m_receive_head;
	
} CMySerial_parameter;

/*�ṹ�������ʼ��*/
void CMySerial_init(CMySerial_parameter* CMySerial_para);

/*�жϽ��մ������ݵ�������*/
void CMySerial_addCmdtoOrignal_buff(CMySerial_parameter* CMySerial_para, char readBuff);

/*��ȡ����������*/
boolean CMySerial_getCmd_reeman(CMySerial_parameter* CMySerial_para, char** buf, int* len);
extern CMySerial_parameter CCmd;

#endif
