#ifndef MOTECSERIAL_H_
#define MOTECSERIAL_H_

#include "Config.h"
/*****************************����Э�����*************************************/
/*
	MOTECT ������ÿһ֡���� 8���ֽ� ���У��
	�������¿�
		������ֵ��ʱ����˳ʱ��ת
		���ø�ֵ��ʱ������ʱ��ת
*/
#define MAX_RECEIVE_ORIGNAL_BUFLEN  700
#define MAX_RECEIVE_BUFLEN 			100


#define MOTOR_ADDRESS				0x00
#define MOTECSERIAL_LEN				8
#define MOTOR_REVOLUTION			16384

/*�����б�*/
#define MOTEC_EchoTest				0x0E
#define MOTEC_EnableMotor			0x15
#define MOTEC_Disable				0x16
#define MOTEC_ClearError		    0x17
#define MOTEC_MoveAbs				0x28
#define MOTEC_MoveRel				0x29
#define MOTEC_Go					0x32
#define MOTEC_EmergencyStop			0x3B
#define MOTEC_Stop					0x3C
#define MOTEC_GetError				0x3D
#define MOTEC_SetMaxV				0X2A
#define MOTEC_GetStatus				0x64
#define MOTEC_ClearMotionFlags		0x66


typedef struct MotecSerial_parameter_all{

	char 	m_receive_buff[MAX_RECEIVE_BUFLEN];
	int 	m_receive_index;//���ڻ�ȡ��������
	int 	m_receive_tail;//��ȡ���һ�����ݼ���
	char 	m_receive_orignal_buff[MAX_RECEIVE_ORIGNAL_BUFLEN];
	int 	m_receive_head;//������ݼ���

} MotecSerial_parameter;

void MotecSerial_init(MotecSerial_parameter* CMySerial_para);
void MotecSerial_addCmdtoOrignal_buff(MotecSerial_parameter* CMySerial_para, char readBuff);
boolean MotecSerial_getCmd(MotecSerial_parameter* CMySerial_para, char** buf, int* len);
void MotecSerial_sendCommand(uint8_t comID, uint32_t sData);
void MotecSerial_setStep(uint8_t comID, uint32_t sData);
/*****************************����Э����� END*********************************/

#endif
