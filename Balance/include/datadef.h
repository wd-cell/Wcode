// datadef.h:
//		
//  1.����:
//      ������������ݡ�ϵͳ������صĺ�����ݽṹ��
//      �������ð�����ͨ�������������豸�����������Ĵ�����ģ
//		���ݽṹ���������ߣ���״������������Ϣ�����������豸ģ��
//		
//  2.����: �ܻ��
//  3.��������: 2008.10.13
//  4.�޸ļ�¼:
//		�޸���: XXX  �޸�ʱ��:

#ifndef __DATA_DEF_H__
#define __DATA_DEF_H__

#include "hncdatadef.h"

//For Linux shared memory
#define SYS_SHM_ID_DATA	0xa000100 //�Ĵ���\����\����\����\����\�ӹ�����
#define SYS_SHM_ID_CTRL	0xa000108 //��������ͨ�����������������
//#define SYS_SHM_DEV_DICT 0xa000109 //�豸�����ֵ�
//#define SYS_SHM_ID_PLC	0xa000109 //PLC����
//#define SYS_SHM_ID_SMPL	0xa000110 //�û���������
//#define SYS_SHM_ID_VBLK	0xa000111 //У�����ɵĳ����
//#define SYS_SHM_ID_TRACE 0xa000110 //������Ϣ��PLC�����û��������ݡ�У�����ɵĳ����

//For Linux user call command
#define SYS_REQUEST_ID 0xa000120 //ϵͳ����
//...End of linux use define

#define INTEGRATE_SIZE 4096 //�ٶȻ���������

//1 ��������

#define DCD_GLBVAR_BASE		1000 //������ȫ�ֱ�������ʼ��ţ������ߵĽǶ� 000~999 
#define DECODER_VAR_NUM		3000 //������ȫ�ֱ�������ֹ��ţ������ߵĽǶ� 1000~2999 
#define LOCAL_VAR_NUM		50	 //ģ̬�еľֲ�����������ǰ���ӳ���ľֲ�����
#define STACK_VAR_BASE		200	 //ģ̬�г���ջ��������ַ
#define SYS_VAR_BASE	40000	//ϵͳ���ݵı����ӿ���ʼ���
#define AXES_VAR_BASE	60000	//�����ݵı����ӿ���ʼ���
#define TOOL_VAR_BASE	70000	//�������ݵı�����ʼ���

#define NEW_USR_VAR_BASE 500    //����FANUC,�����ʽ��#500~#999Ϊ�û��Զ���������ϵ籣��

//ϵͳȫ������[ʵ����]
#define VAR_SYS_BASE	0
#define VAR_SYS_VNUM	10000
#define VAR_CHAN_VNUM	2000
#define VAR_AXIS_VNUM	400 //trunckר�ã��ϲ����벻���

#define VAR_CHAN_BASE	VAR_SYS_VNUM

#define MAX_SMC_LEAD_NUM	5
#define AXES_CMD_BUF_SIZE	100
#define CMD_SMOOTH_BUF_SIZE	100

#ifdef _HNC_10_
	#define SYS_CHAN_NUM	1
	#define SYS_AXES_NUM	4
	#define SYS_SPDL_NUM	2 //������
	#define SYS_NCBRD_NUM	1 //�������豸��
	#define SYS_NCOBJ_NUM	15 //���豸���ƶ��󣨲�������������+RS232+LAN+USB+MCP+NCKB+I/O��
	#define CHAN_AXES_NUM	9
	#define CHAN_SPDL_NUM   2	//ͨ�����������
	#define MAX_SMC_AXES_NUM 2	//����˿�����
    #define SYS_MCODE_NUM       (100)   //ϵͳ���M������
	
// 	#define VAR_AXES_BASE	12000//10000 + (1+1)1000
// 	#define GLB_VAR_NUM	 12600//12000 + 6*100
#endif //_HNC_10_ 90.4K

#ifdef _HNC_20_
	#define SYS_CHAN_NUM	2
	#define SYS_AXES_NUM	8 
	#define SYS_SPDL_NUM	4 //������
	#define SYS_NCBRD_NUM	2 //�������豸��
	#define SYS_NCOBJ_NUM	30 //���豸���ƶ��󣨲�������������+RS232+LAN+USB+MCP+NCKB+I/O��
	#define CHAN_AXES_NUM	9 //ͨ�����߼�����
	#define CHAN_SPDL_NUM   2	//ͨ�����������
	#define MAX_SMC_AXES_NUM 4	//����˿�����
    #define SYS_MCODE_NUM       (200)   //ϵͳ���M������

// 	#define VAR_AXES_BASE	13000 //10000 + (2+1)*1000
// 	#define GLB_VAR_NUM	14200 //13000 * 12*100
#endif //_HNC_20_  92.8k

#ifdef _HNC_30_
	#define SYS_CHAN_NUM		(4)		// ϵͳ���ͨ����
	#define SYS_AXES_NUM		(24)	// ϵͳ����������
	#define SYS_SPDL_NUM		(8)		// ϵͳ���������
	#define SYS_NCBRD_NUM		(4)		// �������豸��
	#define SYS_NCOBJ_NUM		(80)	// ���豸���ƶ��󣨲�������
	#define CHAN_AXES_NUM		(9)		// ͨ���������
	#define CHAN_SPDL_NUM		(4)		// ͨ�����������
	#define MAX_SMC_AXES_NUM	(16)	// ����˿�����
	#define SYS_MCODE_NUM       (500)   //ϵͳ���M���������ݲ����ǲ�ͬͨ��m�������Բ�һ��

// 	#define VAR_AXES_BASE	15000 // 10000 + (4+1)*1000
// 	#define GLB_VAR_NUM	18200 // 15000 + 32*100
#endif // _HNC_30_ [28200*4=112.8K]

#ifdef _HNC_80_
	#define SYS_CHAN_NUM	8
	#define SYS_AXES_NUM	64
	#define SYS_SPDL_NUM	16//������
	#define SYS_NCBRD_NUM	8 //�������豸��
	#define SYS_NCOBJ_NUM	120 //���豸���ƶ��󣨲�������������+RS232+LAN+USB+MCP+NCKB+I/O��
	#define CHAN_AXES_NUM	9
	#define CHAN_SPDL_NUM   4	//ͨ�����������
	#define MAX_SMC_AXES_NUM 32	//����˿�����
	#define SYS_MCODE_NUM       (1000)   //ϵͳ���M������

// 	#define VAR_AXES_BASE	22000//10000 + (11+1)*1000
// 	#define GLB_VAR_NUM	30000//22000 + 80*100
#endif //_HNC_80_ [30000*4=120K]

#define TOTAL_AXES_NUM (SYS_AXES_NUM+SYS_SPDL_NUM)
#define SYS_PART_NUM	SYS_NCOBJ_NUM //ϵͳ�豸�ӿ���
#define VAR_AXES_BASE	(VAR_SYS_VNUM+(SYS_CHAN_NUM+1)*VAR_CHAN_VNUM)
#define GLB_VAR_NUM	    (VAR_AXES_BASE+TOTAL_AXES_NUM*VAR_AXIS_VNUM)
#define	USER_VAR_NUM	5000	//�û����� #50000 ~ #54999
#define USER_DATA_NUM	1000000	//�û����� 100���,4M�ռ�,��Ҫ���ڴ���б�����\���ģ��������
#define NEW_USER_VAR_NUM 500    //#500 ~ #999

#define MAX_MONITOR_NUM	4
#define MAX_SEMPHORE_NUM 40
//#define MAX_MUTEX_NUM 128
#define G5EXT_WCS_NUM	60
#define MAX_TCS_NUM	20
#define MAX_CHG_WCS_NUM 8 // ��������ʱ����ʱ��������ϵ����

//ϵͳ����
enum
{
	VAR_DECODER_SIZE,
	VAR_CHANCTRL_SIZE,
	VAR_AXISCTRL_SIZE,
	VAR_SMXCTRL_SIZE,
	VAR_SYS_CRDS_CHAN=4,//Monitor�������õ�����ϵ����ͨ��[���4��Monitor]
	VAR_SYS_DISP_CHAN=8,//Monitor����ʾͨ����¼[���4��]
	VAR_DECODER_BAK_SIZE=12,
//	VAR_SYS_ACT_CHAN=12,//8����λ�Ļͨ��
	//VAR_SYS_MUTEX_FLAG=20,//ϵͳȫ����4*32=128��
	VAR_SYS_SEMPHORE=20,//ϵͳȫ���ź���40����16λ��
	
	VAR_SYS_G5EX_IDCH=40, //60����չ��������ϵ��ID��ͨ����,��16λΪ�����룬��16λΪͨ����
	VAR_SYS_G5EX_ZERO=100,	//60����չ��������ϵ���60*18[64λ]=1080

	//MDI ��Ϣ
	VAR_SYS_MDI_MODE = 1900, //MDIģʽ:mode ret
	VAR_SYS_MDI_ROW,		//MDI�����������
	VAR_SYS_MDI_CHAN,		//MDI���е�ͨ��
	VAR_SYS_SMX_NUM0,		//��̬��������
	VAR_SYS_SMX_NUM,		//����������
	VAR_DCDVAR_OFFSET,		//�������еľֲ�����ƫ����
	
	VAR_SYS_ALARM_COPY = 1910,	//1910~1917
	VAR_SYS_ALARM_FLAG = 1918,	//1918~1925
	VAR_SYS_NOTE_COPY = 1926,	//1926~1937
	VAR_SYS_NOTE_FLAG = 1938,	//1938~1949

	VAR_SYS_CHG_WCS_N = 1950,	//��������ʱ���޸ĵĹ�������ϵ��
	VAR_SYS_CHG_WCS_I,	//1951~1958����������ʱ���޸ĵĹ�������ϵ������ͨ���ż�����������
	VAR_SYS_CHG_TOOL_N=1959,	//��������ʱ���޸ĵĵ��߸���
	VAR_SYS_CHG_TOOL_I=1960,	//1960~1969 ��������ʱ���޸ĵĵ��߱�� 
	VAR_SYS_G5X_TEMP=1970,		//1970~2113 �˸���������ʱ����ʱ��������ϵ 8*18 = 144

	VAR_SYS_YMD=2114,//��¼ϵͳʱ�� ��+��+��
	VAR_SYS_HMS,//ϵͳʱ�䣬Сʱ+����+��
	VAR_SYS_POWER_OFF_PERIOD, // ϵͳ�ϴιػ������ο�����ʱ����λ���룬δ��ȡ��ʱ��ʱΪ0

	//�б���Ϣ
	VAR_SYS_TAB_NUM = 2144, //�б���� 50���б����Ϣ
	VAR_SYS_TAB_COL,		//��һ���б��������������
	VAR_SYS_TAB_OFF,		//��һ���б����ݵ���ʼ��ַƫ��
//	VAR_SYS_TAB_COL,		//��n���б��������������
//	VAR_SYS_TAB_OFF,		//2145 ~ 2244 ��n���б����ݵ���ʼ��ַƫ��

	VAR_SYS_G31_8 = 2245,		//G31.8�����㻺�� #42245 ~ #42499	
	VAR_SYS_DEBUG_INF = 2500,	//������Ϣ42500 ~ 43499 
	
	VAR_SMPL_PERIOD = 3500,		//������������,Ϊ�岹���ڵ���Ȼ������16������ͨ������
	VAR_SMPL_LMT,				//������ֹ����������ͨ������
	VAR_SMPL_IDX,				//����ͨ��дָ�룬����ͨ������
	VAR_SMPL_READ_PT,			//����ͨ����ָ�룬����ͨ������
	VAR_SMPL_TYPE = 3504,		//3504~3535 ����ͨ�����ͣ���32��
	VAR_SMPL_AXIS=3536,			//3536~3567	����ͨ����ţ���32��
	VAR_SMPL_OFFSET=3568,		//3568~3599 ����ͨ��ƫ��������32��
	VAR_SMPL_DATA_LEN=3600,		//3600~3631 ����ͨ�����ݳ��ȣ���32��
	VAR_SMPL_USED_CHAN_NUM = 3632,	//��ʹ�õĲ���ͨ����
	VAR_EVENT_SUBSCRIBED,		//�Ƿ����¼�����
	VAR_ALARM_SUBSCRIBED,		//�Ƿ��ı�������

	VAR_TOOLMEAS_CALIBATION_TYPE = 3700,	// ����ʽ����(Bit32)   3700~3749���߲���ʹ��
	VAR_TOOLMEAS_BLOW_OPEN,					// ������Mָ��(Bit32)
	VAR_TOOLMEAS_BLOW_CLOSE,				// ������Mָ��(Bit32)
	VAR_TOOLMEAS_LASER_OPEN,				// ���⿪Mָ��(Bit32)
	VAR_TOOLMEAS_LASER_CLOSE,				// �����Mָ��(Bit32)
	VAR_TOOLMEAS_LASER_DOOR_OPEN,			// �����ſ�Mָ��(Bit32)
	VAR_TOOLMEAS_LASER_DOOR_CLOSE,			// �����Ź�Mָ��(Bit32)
	VAR_TOOLMEAS_M_NUM,						// ��������(Bit32)
	VAR_TOOLMEAS_SAVE_HEIGTH,				// ��ȫ����߶�(Bit32*100000)
	VAR_TOOLMEAS_M_F2,						// �����ٶ�(Bit32*100000)
	VAR_TOOLMEAS_M_F3,						// �����ٶ�(Bit32*100000)
	VAR_TOOLMEAS_M_S,						// ����ת��(Bit32*100000)
	VAR_TOOLMEAS_M_THINKNESS,				// ���Ǻ��(Bit32*100000)
    VAR_STARTNO,                            // ��ʼ���ߺ�(Bit32)

	VAR_TOOLMEAR_T_F1,                      //���������ٶ�(Bit32*100000)
	VAR_TOOLMEAR_T_F2,                      //�����Ӵ��ٶ�(Bit32*100000)
	VAR_TOOLMEAR_T_LENGTH,                  //�������ǳ���(Bit32*100000)
	VAR_TOOLMEAR_T_WIDTH,                   //�������ǿ��(Bit32*100000)
	VAR_TOOLMEAR_T_NUM,                     //������������(Bit32)
	VAR_TOOLMEAS_M_BASE_TOOL_LENGTH,		//ϳ����׼���߳���(Bit32*100000)

	VAR_TOOLMEAS_T_REF_DIR_X = 3730,		//�굶����X	
	VAR_TOOLMEAS_T_REF_DIR_Z,				//�굶����Z

	VAR_G12_POLOR_LEFTRIGHT = 3740, //����λ�ã��ڼ�����߻����ұ�
	VAR_G12_POLOR_TYPE, //��������
	VAR_RIGHT_CONFIG = 3742, // 3742~3748 ��ǰȨ��mcp��尴ťʹ��
	VAR_G97_S = 3750,
	
	VAR_KEY_PRESS = 3800,						// �������±�־	(�������Զ��ػ�ʹ��)		
	VAR_NO_PRESS_TIME = 3801,				// ����û�а������µ�ʱ��(�������Զ��ػ�ʹ��)
//mark1 trunck�汾ר�ã��ϲ�����ʱ�����˲���
	// RFID
	VAR_RFID_ON_OFF = 3810,	// RFID��д����
	VAR_RFID_ID,			// RFID��д��ID��
	VAR_RFID_RW_FLAG,		// RFID��д���
	VAR_RFID_RESULT,		// RFID��д���

	VAR_RFID_RW_TOOL_NO,	// RFID��д���ߺ�
	VAR_RFID_RW_DATA_CFG,	// RFID��д����
//end of mark1

	VAR_SYS_G68_POINT = 4000, //12*21 G68������������
	VAR_SYS_G68_ZERO = 4252, //6*21 [Bit64]
	VAR_SYS_G68_VCT = 4378, //18*21��[fBit64] x y z�����������

	VAR_SYS_TEACH_IN = 5000,	//ʾ�̼�¼ #45000 ~ #49999	

	VAR_SYS_SPDL_SYNC_ERR = 6000,  //��Ƶ����˿ʱ��ͬ�����
	VAR_SYS_NOSENSORHEAT_SUMONE=6010,
	VAR_SYS_NOSENSORHEAT_SUMONE_,
	VAR_SYS_NOSENSORHEAT_SUMTWO,
	VAR_SYS_NOSENSORHEAT_SUMTWO_,
	VAR_SYS_NOSENSORHEAT_SUMTHREE,
	VAR_SYS_NOSENSORHEAT_SUMTHREE_,
	VAR_SYS_NOSENSORHEAT_SUMFOUR,
	VAR_SYS_NOSENSORHEAT_SUMFOUR_,
	VAR_SYS_NOSENSORHEAT_SPDL_SUMONE,
	VAR_SYS_NOSENSORHEAT_SPDL_SUMONE_,
	VAR_SYS_NOSENSORHEAT_SPDL_SUMTWO,
	VAR_SYS_NOSENSORHEAT_SPDL_SUMTWO_,
	VAR_SYS_NOSENSORHEAT_SPDL_SUMTHREE,
	VAR_SYS_NOSENSORHEAT_SPDL_SUMTHREE_,
	VAR_SYS_NOSENSORHEAT_Z_DEFORMATION,//Z�������
	VAR_SYS_NOSENSORHEAT_Z_DEFORMATION_,
	VAR_SYS_NOSENSORHEAT_SPDL_DEFORMATION,//���������Z�������
	VAR_SYS_NOSENSORHEAT_SPDL_DEFORMATION_,
	VAR_SYS_NOSENSORHEAT_NUM=6028,//�ܺ����޴������¶Ȳ������������ݸ���
	VAR_SYS_NOSENSORHEAT_PERIOD = 6029,//�ܺ����޴������¶Ȳ���������ʵ��ʱ����
	VAR_SYS_NOSENSORHEAT_CUR_STEP = 6030,//�ܺ����޴������¶Ȳ����������궨����
	VAR_SYS_NOSENSORHEAT_CUR_TIME = 6031,//�ܺ����޴������¶Ȳ����������궨ʵ��ʱ��
	VAR_SYS_NOSENSORHEAT_DATA = 6032,//�ܺ����޴������¶Ȳ�������������100����#46032 ~ #46131����λ΢��

	VAR_SYS_TOTAL = VAR_SYS_VNUM //10000
};



// ͨ������
enum
{
	VAR_CHAN_SEL_PROG=0,//ѡ��ĳ�����
	VAR_CHAN_DEST_ROW,//����/��ת����Ŀ�������
	VAR_CHAN_DCD_ROW,//���ڽ��͵���
	VAR_CHAN_DCD_OROW,	//��������ĳ�����
	VAR_CHAN_RUN_ROW,	//�������еĳ�����
	VAR_CHAN_FIN_ROW,	//�Ѿ���ɵĳ�����
	VAR_CHAN_DCD_PROG,	//���ڽ��͵ĳ���
	VAR_CHAN_RUN_PROG,	//�������еĳ���
	VAR_CHAN_MAIN_ROW,	//���е���������
	VAR_CHAN_PART_STATI,	//�ӹ�����ͳ��

	VAR_CHAN_CMD_FEED,	//ͨ���ϳ�ָ���ٶ�
	VAR_CHAN_ACT_FEED,	//ͨ��ʵ�ʺϳ��ٶ�
	VAR_CHAN_SYNC_FLAG, //ͬ�����	
	VAR_CHAN_BP_ID,	//�ϵ�����
	VAR_CHAX_G5X_ID,	//G5x�ı�־λ
	VAR_CHAX_G55_ID,
	VAR_CHAX_G56_ID,
	VAR_CHAX_G57_ID,
	VAR_CHAX_G58_ID,
	VAR_CHAX_G59_ID,

	VAR_CHAX_G54_ZERO=20,	//40 ��G5X����㣬������64λ���ͱ���
	VAR_CHAX_G55_ZERO=38,
	VAR_CHAX_G56_ZERO=56,
	VAR_CHAX_G57_ZERO=74,
	VAR_CHAX_G58_ZERO=92,
	VAR_CHAX_G59_ZERO=110,
	VAR_CHAX_G92_ZERO=128,  //��G92��� 90
	VAR_CHAX_REL_ZERO=146,	//���������ϵ���
	VAR_CHAN_LEFT_TOGO=164,	//�Ÿ��߼���ʣ�����[�岹��ֵ]
	VAR_CHAX_BP_POS=182,	//�ϵ�λ��[�岹��ֵ]

	//ͨ��������ģ̬
	VAR_DCD_MDL_DATA=200,
	VAR_DCD_AX_FLAG=VAR_DCD_MDL_DATA, //axis1,axis2,axis3,resvb8;	//����ƽ���������ţ���3���,��ǰ�����ϵ��53 54~59 92,
	VAR_DCD_G928_FLAG, //uBit16 g92_flag,g28_axes;//G92��G28���������
	VAR_DCD_SPDL_IDX,//Bit16 s_i,reserved;	//��ǰ����ţ���������
	VAR_DCD_RAAX_FLAG, //Bit16 r_ax,a_ax;	//�����ᣬ�����ᣬ����֧�����л�
	VAR_DCD_CMD_FLAG,//uBit16 flag1,flag2;
	VAR_DCD_SPDL_SPD,//Bit32 s[CHAN_SPDL_NUM],t,t_r,t_l;
	VAR_DCD_G93_L=212,//Bit16 g93_l,mem_grp,mem_g1,mem_g2;//G93�Ĳ���
	VAR_DCD_POLAR_CYL=214,//Bit64 polar_x0,polar_y0,cyl_r;//������ԭ�㣬������岹�İ뾶
	VAR_DCD_WCS_ZERO=220,//Bit64 wzero[9]��ǰ�Ĺ�������ϵ��� ��G92
	VAR_DCD_PRG_POS=238, //Bit64 prg_pos[9]�������λ��
	VAR_DCD_TRNS_POS=256, //Bit64 trns_pos[9]�任����λ��
	VAR_DCD_MCS_POS=274, //Bit64 mcs_zero[9]��������λ��
	VAR_DCD_G28_POS=292, //Bit64 g28[9]G28�м��λ��
	VAR_DCD_G52_ZERO=310, //Bit64 g52[9]G52ԭ��λ��
	VAR_DCD_G106_POS=328, //Bit64 g106[9]G106���˵�λ��
	VAR_DCD_G106_FLAG=346, //uBit16 g106_axes,cyl_ax,m345,gvel_ax;
	VAR_DCD_F_CMD=348,//fBit64 g94_f,reserv_f,g32_f,g95_f;	Fָ����˵�λ���ʵ� 
	VAR_DCD_CRDS_I=356,
	VAR_DCD_CYC_AX=358,
	VAR_DCD_CYC_REG,
	VAR_DCD_MDL_GRP=360, //G��ģ̬��������ģ̬ 360~399 80��
	VAR_DCD_MDL_REG=400, //~599 SDataUnion regvar[LOCAL_VAR_NUM];

	//ͨ���ڵĽ�������������
	VAR_IIP_CMD_TYPE=600,//��ǰִ�е�ָ��/�ӹ��������ͣ�������ʾ
	
	VAR_SMPL_AX_FLAG,//��16λ �������� ��16λ G31״̬
	
	VAR_DATA_FILE,	//�������������ļ�����������7�ַ�
	VAR_DATA_FILE2,
	VAR_DATA_TYPE,	//�����������ݵ�����[0 G�������ֻ�Լ�����Ч�� 1 ���� 2 ���� 3 ���� 4 �Ĵ��� 5 ��������]
	VAR_DATA_START,	//��������������ʼ������
	VAR_DATA_NUM,	//�����������ݵı�������

	VAR_INTP_POS=610,	//610~627: �岹���ĵ�ǰ���λ�ã���������
	VAR_INTP_ZERO=628,	//628~645: �岹���Ĺ������
	VAR_CHAN_NOTE_COPY=646, //646~647
	VAR_CHAN_ALARM_COPY=648, //648~649
	VAR_CHAN_NOTE_FLAG=650, //650~651
	VAR_CHAN_ALARM_FLAG=652, //652~653
	VAR_CHAN_G95_F=654,
	VAR_CHAN_G43_AX,//��ǰ����������
	VAR_CHAN_G43_L,//��ǰ������ 656~657

	VAR_CRDS_FRAME=658,//658~675��������ϵ
	VAR_HOLD_BLK_EPOS=676,//676~693��ͣ���յ�
	VAR_RUN_START_POS=694,//694~711�������λ��

	VAR_BP_EXT_CMD = 712,//�ϵ��ⲿ���ƫ����

	VAR_INTP_WCS=800,	//800~817: �岹���ĵ�ǰ���λ�ã���������
	VAR_INTP_VCS_FLAG=818, //����������ϵ��־
	VAR_VWCS_FLAG,			//���⹤������ϵ��־
	VAR_ACT_WCS=820,	//820~837: ��������ʵ��λ��
	VAR_TAX_ENABLE=850,         //��б�����ʹ��
	VAR_TAX_ORTH_AX,            //������ͨ�����
	VAR_TAX_TILT_AX,            //��б��ͨ�����
	VAR_TAX_ANGLE,              //��б�Ƕ�
	VAR_TAX_COMPEN,             //���岹��ֵ
	VAR_INTP_H_D,				//�岹������ʹ�õ�H��/D��
	VAR_TANGENT_ANGLE,          //G115L5��������߽Ƕ�
	VAR_PROG_MDI_SWITCH,        //������MDI�л�����
	VAR_MAIN_PROG_LINE,         //�������кš���������
//	VAR_CYC_H_D,                //����̶�ѭ��ʱ���ݴ�H/D��

	VAR_TANGENT_ABC=870,//870~875��ǰ�岹��ĽǶ�λ�á��������߸��桿

	VAR_INTP_MODAL=900,	//900~939 �岹����G��Mģ̬����80��
	VAR_LOADFILE_STATUS=940,//��̬װ�ش����ļ���״̬
	VAR_DCD_TYPE, //��������������
	VAR_INTP_BLKI,//�岹��ִ�еĶκ�
	VAR_DCD_BLKI,//���������ͳ��Ķκ�
	VAR_RANDOM_ROW_STATUS,//������״̬

	VAR_PROG_FLOW_IDX,//�ӳ�������ѡ����
	VAR_TAP_CMD_S0, // ���Թ�˿ʱ���洢�����ָ��ת��
	VAR_TAP_CMD_S1, 
	VAR_TAP_CMD_S2, 
	VAR_TAP_CMD_S3, 
	VAR_TAP_F,//��˿�ݾ�

	VAR_STR_LEN = 951,//��ӡ�ַ�������
	VAR_STR_ADDR,//��ӡ�ַ�����ַ 952~966,��װ��64���ַ�
    VAR_DCD_FAST_VERIFY = 967,
    VAR_THREAD_RATIO,
    VAR_BREAK_LINE,//�Զ������У������ж��ӳ���ʱ��¼���жϳ������
	VAR_SUBR_PROG_RUN_ROW = 970,//ÿ�㵱ǰ�����к�(0~8)970~978
	VAR_SUBR_NUM = 979,//��ǰ�������ӳ������
    
	VAR_CHAX_G54_ZERO1=1000,	//��G5X����㣬������64λ���ͱ���
	VAR_CHAX_G55_ZERO1=1018,
	VAR_CHAX_G56_ZERO1=1036,
	VAR_CHAX_G57_ZERO1=1054,
	VAR_CHAX_G58_ZERO1=1072,
	VAR_CHAX_G59_ZERO1=1090,
	VAR_JOG_INTP_POS = 1108,//1108~1126

	VAR_RANDOM_AXIS_MOVE_INVALID = 1127,// ɨ��ģʽָ������m6��־����ʱ��ִ���ƶ�ָ��

	VAR_PROG_DIST_2END, //1128 �����㵽�յ�ı�̾���
	VAR_PROG_DIST_2END_,

	VAR_BLK_LEFT_TIME,//1130 ��ǰ��ʣ��ʱ��
	VAR_BLK_LOAD_PROG_NO,	// 1131 ����ĳ����
//mark2 trunck�汾ר�ã��ϲ�����ʱ�����˲���
	VAR_FAST_VERIFY_RUN_ROW_NO,	// 1132 ����У������У���к�(HMIʹ��)
	VAR_FAST_VERIFY_FINISH,	// 1133 ����У���յ�����¼�(HMIʹ��)
//end of mark2	
	VAR_CUR_PROG_ID = 1139, // ��ǰ�����Ψһid

	VAR_TIME_VAR_WRITE = 1140,
	VAR_TIME_VAR_READ,
//mark3 trunck�汾ר�ã��ϲ�����ʱ�����˲���
	VAR_CUTTING_PLCTIME,
	VAR_CUTTING_PLCTIMEFLAG,
//end of mark3

	VAR_CHAN_RUN_ROW1,	//�������еĳ�����
	VAR_CUR_PROG_ID1,

	VAR_ROBOT_DATA = 1200, //1200-1700 500*4 bytes

	VAR_CHAN_TOTAL = VAR_CHAN_VNUM //2000
};

//������
enum
{//#[50000 + ax*100 + ?]
	VAR_AXIS_CHN_INF=0,	//��16λ����ͨ���ڵ��߼���� ��16λ�����ݲ�����־
	VAR_AXIS_MEAN_VEL,	//���ƽ���ٶ�
	VAR_AXIS_THREAD_POS0,	//�ӹ�����ʱ�����������λ��
	VAR_AXIS_THREAD_POS0_,	//
	VAR_AXIS_THREAD_POS1,	//�ӹ�����ʱ���ͬ��λ��
	VAR_AXIS_THREAD_POS1_,	//
	VAR_AXIS_THREAD_POS2,	//�ӹ�����ʱ��ļ���λ��
	VAR_AXIS_THREAD_POS2_,	//
	VAR_AXIS_THREAD_POS3,	//�ӹ�����ʱ���ֹͣλ��
	VAR_AXIS_THREAD_POS3_,	//
	VAR_AXIS_MEA_CMD_POS,	//�����źŻ��ʱ��ָ��λ�� G31
	VAR_AXIS_MEA_CMD_POS_,	//
	VAR_AXIS_MEA_ACT_POS,	//�����źŻ��ʱ��ʵ��λ��
	VAR_AXIS_MEA_ACT_POS_,	//
	VAR_AXIS_MEA_ACT_POS2,	//�����źŻ��ʱ��2�ű�����λ��
	VAR_AXIS_MEA_ACT_POS2_,	//
	VAR_AXIS_MEA_VEL,	//�����źŻ��ʱ���ٶ�
	VAR_AXIS_MEA_TRQ,	//�����źŻ��ʱ�ĵ���
	VAR_AXIS_DIST_POS1, //����������һ������ʵ��λ��
	VAR_AXIS_DIST_POS1_,
	VAR_AXIS_DIST_POS2, //�������2�����ľ���λ��
	VAR_AXIS_DIST_POS2_,
	VAR_AXIS_SYNC_ZOFF0, //ͬ��������ʼƫ����
	VAR_AXIS_SYNC_ZOFF0_,
	VAR_AXIS_SPDL_NO, //���������
	VAR_AXIS_0_RESERV_, 
	VAR_AXIS_1_RESERV,//�������ڴ������ʱ��λ��
	VAR_AXIS_1_RESERV_, //
	VAR_AXIS_LEAD_DIST,//��������������
	VAR_AXIS_LEAD_DIST_, //29
	VAR_AXIS_EG_DIST, 
	VAR_AXIS_EG_PULSE,
	VAR_AXIS_IN_PULSE1,
	VAR_AXIS_OUT_PULSE1,
	VAR_AXIS_IN_PULSE2,
	VAR_AXIS_OUT_PULSE2, //35
	VAR_AXIS_EG_DIST2, 
	VAR_AXIS_EG_PULSE2,
	VAR_AXIS_2_RESERV,//����ı�׼ͬ��ƫ��
	VAR_AXIS_2_RESERV_,
	VAR_AXIS_PINC_SUM,//��Ļ���ʱ���ڵ������ۻ�����
	VAR_AXIS_PINC_SUM_,
	VAR_AXIS_HOME_CRDS, //�ο�������
	VAR_AXIS_HOME_CRDS_, //43
	VAR_AXIS_LOCK_POS, //������ʱ��ָ��λ��
	VAR_AXIS_LOCK_POS_, //45
	VAR_AXIS_LOCK_PULSE, //������ʱ��ָ������λ��
	VAR_AXIS_LOCK_PULSE_, //47
	VAR_AXIS_NOTE_COPY, //48
	VAR_AXIS_NOTE_COPY_, //49
	VAR_AXIS_ALARM_COPY, //50
	VAR_AXIS_ALARM_COPY_, //51
	VAR_AXIS_NOTE_FLAG, //52
	VAR_AXIS_NOTE_FLAG_, //53
	VAR_AXIS_ALARM_FLAG, //54
	VAR_AXIS_ALARM_FLAG_, //55
	VAR_AXIS_ENCOFF_PULSE, //������ƫ�õ�������56
	VAR_AXIS_ENCOFF_PULSE_, //57
	VAR_AXIS_ENCOFF_PULSE2, //У���ı�����ƫ��������58
	VAR_AXIS_ENCOFF_PULSE2_, //59

	VAR_AXIS_SYNC_ACT_POS,	//�Ӷ���������������ϵ�е�ʵ��λ��
	VAR_AXIS_SYNC_ACT_POS_,
	VAR_AXIS_SYNC_CMD_POS,		  //�Ӷ���������������ϵ�е�ָ��λ��
	VAR_AXIS_SYNC_CMD_POS_,
	VAR_AXIS_reserv1,
	VAR_AXIS_reserv2,
	//VAR_AXIS_SPDL_MIN, //���Ƽӹ�ʱ��������С�������� 60
	//VAR_AXIS_SPDL_MAX, //���Ƽӹ�ʱ����������������� 61
	//VAR_AXIS_SPDL_MEAN, //���Ƽӹ�ʱ������ƽ���������� 62
	//VAR_AXIS_THREAD_ACCL,//���Ƽӹ�ʱ�ĳ�����پ��� 63
	//VAR_AXIS_THREAD_NACC,//���Ƽӹ�ʱ�ļ��������� 64
	//VAR_AXIS_THREAD_LVEL,//���Ƽӹ�ʱ�ĳ����������� 65
	
	VAR_AXIS_POWEROFF_POS,	//��ػ�ǰ��λ��
	VAR_AXIS_POWEROFF_POS_,	//��ػ�ǰ��λ��
	VAR_AXIS_MPG_SPOS,	//��ҡ��ʼλ��
	VAR_AXIS_MPG_SPOS_,	

	VAR_AXIS_MPG_CNT0=70,
	VAR_AXIS_MPG_CNTN=79,
	
	VAR_AXIS_TOTAL_EXT_CMD, //�ⲿ����ָ������
	VAR_AXIS_TOTAL_EXT_CMD_, 
	VAR_AXIS_LAST_EXT_CMD,//�Ѿ�������ⲿ����ָ��
	VAR_AXIS_LAST_EXT_CMD_,

	VAR_AXIS_TOTAL_TANG_CMD, //���߸������ָ������,���ݱ���ж�Ϊʵ�������
	VAR_AXIS_TOTAL_TANG_CMD_, 
	VAR_AXIS_LAST_TANG_CMD,//�Ѿ���������߸������ָ��
	VAR_AXIS_LAST_TANG_CMD_,
	VAR_AXIS_BINORMAL_CENTER,//�����߸���ĵ�������λ��
	VAR_AXIS_BINORMAL_CENTER_,

	//64λ���������Ŀǰ�����ڳ��г�ֱ���������ʽ������
	VAR_AXIS_ABSCYC_CNT=90,
	VAR_AXIS_ABSCYC_PUL,
	VAR_AXIS_ABSCYC_ROTPUL, //��ת�ᷴ������ѭ������
	
	//����PID�����
	VAR_AX_JUMP_A,//����ϵ��A
	VAR_AX_JUMP_B,//����ϵ��B
	VAR_AX_JUMP_C,//����ϵ��C
	VAR_AX_JUMP_LEFT_TPGO,//����ʣ�����
	VAR_AX_JUMP_INIT_POS, //������ʼλ��
	
    VAR_AXIS_TOTAL_MPG_INTER, //�����ж���
	VAR_AXIS_ACC_COMP,	//����ʱ�ļ��ٶ�

	VAR_AXIS_TOTAL = VAR_AXIS_VNUM //100
};
#define VAR_AXIS_G5X_ZERO VAR_AXIS_G54_ZERO

// 2 ���߲��֣�


#define MAX_CHG_TOOL	10		//��ͣʱ�޸ĵĵ�����

#ifdef _HNC_10_ //��ͨ��
	#define MAX_TOOL_NUM	1014	// ��󵶾�����0-1023��
	#define MAX_MAGZ_NUM	32		// ��������
	#define MAGZ_HEAD_BASE	186		// ��ͷ��ʼ��ַ
	#define MAGZ_LOC_BASE	698		// ��λ������ʼ��ַ
	#define MAX_RFID_NUM	3	//����RFID��д������
#endif // _HNC_10_

#ifdef _HNC_20_ // ˫ͨ��
	#define MAX_TOOL_NUM	1014	// ��󵶾�����0-1023��
	#define MAX_MAGZ_NUM	32		// ��������
	#define MAGZ_HEAD_BASE	186		// ��ͷ��ʼ��ַ
	#define MAGZ_LOC_BASE	698		// ��λ������ʼ��ַ
	#define MAX_RFID_NUM	3	//����RFID��д������
#endif // _HNC_20_

#ifdef _HNC_30_ // ��ͨ��
	#define MAX_TOOL_NUM	1014	// ��󵶾�����0-1023��
	#define MAX_MAGZ_NUM	32		// ��������
	#define MAGZ_HEAD_BASE	186		// ��ͷ��ʼ��ַ
	#define MAGZ_LOC_BASE	698		// ��λ������ʼ��ַ
	#define MAX_RFID_NUM	3	//����RFID��д������
#endif // _HNC_30_

#ifdef _HNC_80_ // ��ͨ��
	#define MAX_TOOL_NUM	2038	// ��󵶾�����0-2047��
	#define MAX_MAGZ_NUM	64		// ��������
	#define MAGZ_HEAD_BASE	372		// ��ͷ��ʼ��ַ
	#define MAGZ_LOC_BASE	1396	// ��λ������ʼ��ַ
	#define MAX_RFID_NUM	3	//����RFID��д������
#endif // _HNC_80_

// ���߻�������
#define MAX_TOOL_INF	5


//3 �������֣�



//�����ֲ�����������[�����ͺţ�ͳһ]
#define NCU_PARAM_NUM		1000	//���ص�Ԫ�������� ͨѶ
#define MAC_PARAM_NUM		1000	//����/�û��������������û�������Ϣ��
#define CHAN_PARAM_NUM		500		//ͨ����������
#define AXIS_PARAM_NUM		1000	//�ἰ�ŷ���������
#define CPAX_PARAM_NUM		200		//�Ჹ��������������
#define NCBRD_PARAM_NUM		200		//��վ��������
#define NCOBJ_PARAM_NUM		20		//��վ��������


#ifdef _HNC_80_ //12(2)ͨ����80��(64����+16����)��8��վ��160����
	#define TABLE_PARAM_NUM		40000 //�����ݱ��������

	//�����������ַ
	#define PAR_NCU_BASE 0	//���ص�Ԫ��������ַ
	#define PAR_MAC_BASE 1000	//������������ַ
	#define PAR_CHAN_BASE 2000	//ͨ����������ַ
	#define PAR_AXIS_BASE 8000	//2000+12*500�ἰ�ŷ���������ַ
	#define PAR_CMPE_BASE 88000  //8000+(64+16)*1000 �Ჹ����������ַ
	#define PAR_BOARD_BASE 104000 //88000+(64+16)*200
	#define PAR_PART_BASE 105600  //104000+8*200���ƶ����������ַ
	#define PAR_TABLE_BASE 108800 //105600 +160*20���ݱ��������ַ
    #define PAR_USERREALTIMEDATA_BASE 148000 //�û��Զ������ݲ�������ַ
	#define TOTAL_PARAM_NUM	148800 //108800+40000�ܲ�������
#endif //_HNC_80_ [108800*8=1162K]

#ifdef _HNC_30_ //4(5)ͨ����32��(24����+8����)��4��վ��80����
	#define TABLE_PARAM_NUM		20000 //�����ݱ��������
	
	//�����������ַ
	#define PAR_NCU_BASE 0	//���ص�Ԫ��������ַ
	#define PAR_MAC_BASE 1000	//������������ַ
	#define PAR_CHAN_BASE 2000	//ͨ����������ַ
	#define PAR_AXIS_BASE 4000	//2000+4*500�ἰ�ŷ���������ַ
	#define PAR_CMPE_BASE 36000  //4000+(24+8)*1000 �Ჹ����������ַ �ӵ����Ĵ洢����ʼ
	#define PAR_BOARD_BASE 42400 //36000+(24+8)*200
	#define PAR_PART_BASE 43200  //42400+4*200���ƶ����������ַ
	#define PAR_TABLE_BASE 44800 //43200+80*20���ݱ��������ַ
    #define PAR_USERREALTIMEDATA_BASE 64000 //�û��Զ������ݲ�������������ַ
	#define TOTAL_PARAM_NUM	64800 //44800+20000�ܲ�������
#endif //_HNC_30_ [48800*8=506K]


#ifdef _HNC_20_	//2ͨ����8�ᣬ4���ᣬ2��վ��30����
	#define TABLE_PARAM_NUM		8000 //�����ݱ��������

	//�����������ַ
	#define PAR_NCU_BASE 0	//���ص�Ԫ��������ַ
	#define PAR_MAC_BASE 1000	//������������ַ
	#define PAR_CHAN_BASE 2000	//ͨ����������ַ
	#define PAR_AXIS_BASE 3000	//2000+2*500�ἰ�ŷ���������ַ
	#define PAR_CMPE_BASE 15000  //3000+12*1000�Ჹ����������ַ �ӵ����Ĵ洢����ʼ
	#define PAR_BOARD_BASE 17400  //15000+12*200���ƶ����������ַ
	#define PAR_PART_BASE 17800  //17400+2*200���ƶ����������ַ
	#define PAR_TABLE_BASE 18400 //17800+30*20���ݱ��������ַ
	#define PAR_USERREALTIMEDATA_BASE 25600 //�û��Զ������ݲ�������������ַ
	#define TOTAL_PARAM_NUM	26400 //18400+8000�ܲ�������
#endif //_HNC_20_


#ifdef _HNC_10_	//1ͨ����3 �ᣬ2���ᣬ1��վ��15����
	#define TABLE_PARAM_NUM		5000 //�����ݱ��������
	
	//�����������ַ
	#define PAR_NCU_BASE 0	//���ص�Ԫ��������ַ
	#define PAR_MAC_BASE 1000	//������������ַ
	#define PAR_CHAN_BASE 2000	//ͨ����������ַ
	#define PAR_AXIS_BASE 2500	//2000+1*500�ἰ�ŷ���������ַ
	#define PAR_CMPE_BASE 7500 //2500+5*1000�Ჹ����������ַ �ӵ����Ĵ洢����ʼ
	#define PAR_BOARD_BASE 8500 //7500+5*200���ƶ����������ַ
	#define PAR_PART_BASE 8700  //8500+1*200��������������ַ
	#define PAR_TABLE_BASE 9000 //8700+15*20���ݱ��������ַ
	#define PAR_USERREALTIMEDATA_BASE 13200 //�û��Զ������ݲ�������������ַ
	#define TOTAL_PARAM_NUM	14000 //9000+5000�ܲ�������
#endif //_HNC_10_




#define	THREAD_SMOOTH_ON	0x0001	//�����ٶȾ��ȴ���
#define	THREAD_COMPEN_ON	0x0002	//���ƫ�������
#define	THREAD_ACTVEL_ON	0x0004	//ʵ��ת��У�鿪��
#define	THREAD_RE_DEC_OPT	0x0008	//��֤��β�㻹�Ǳ�֤���ٶ� 0 ��֤��β�μ��ٲ��������� 1 ��֤��β�㲻��ǰ


#define MAX_MAC_MODEL_PARA 30


#define SWIVEL_TYPE_NUM	7
//	[TABLE_TYPE_NUM]={ "A","B","C","CA","CB","BA","BJ"};
#define TABLE_TYPE_NUM	6
//	[SWIVEL_TYPE_NUM]={ "ZA","ZB","ZCA","ZCB","YXCA","ZBA"};

//RTCP �������塾��SChanCtrl�е���ţ�1==PAR_CH_RTCP_PARA0��
#define MAX_RTCPARA			50	//RTCP����������

#define PAR_RTCP_PARA0	0 //��һ�������ǽǶȷֱ汶��
#define PAR_RTCP_ANG_TYPE 1 //���߶Ե���ĽǶ����ͣ�0��-180��180��һ�����ڵ�����ת��  1��0~360��һ�����ڹ�����ת��
//#define PAR_RTCP0_BARM_LEN 2 //���߰ڱ۳���



#define MAX_SMX_PARAM_NUM 10








//�豸�����ֵ䶨�壬��Ҫ�����ŷ������ķ�����ͨѶ
#define SYS_GRP_OBJ_NUM (SYS_NCOBJ_NUM+1) //�����ֵ����豸��
#define MAX_OBJ_PAR_NUM	600               //�豸�����ֵ�����������

#define SERVO_PARA_NUM   500 //�ŷ��������վPARM��������������С�ڵ���MAX_OBJ_PAR_NUMSERVO_PARA_NUM
#define SERVO_PARA_NCUC_NUM   100 // ����NCUC�ŷ���������100�����

#define SERVO_STA_NUM    10  //�ŷ��������վSTA����������������
#define SPINDLE_PARA_NUM 500 //�ŷ������վPARM����������������
#define SPINDLE_STA_NUM  10  //�ŷ������վSTA����������������

//rwflag��־
#define NCUC_UD_LOAD_READ  0x0001 //����վ����
#define NCUC_UD_LOAD_WRITE 0x0002 //д��վ����
#define NCUC_UD_LOAD_CHECK 0x0004 //У���վ����
#define NCUC_UD_LOAD_DIFF  0x0008 //��վ��ϵͳ��������ͬ����־
#define NCUC_UD_LOAD_DONE  0x8000 //��д���

//spFunc��־
#define NCUC_UD_LOAD_SAVE    0x0001 //�����վ������ͨѶ����
#define NCUC_UD_LOAD_DEFAULT 0x0002 //���ô�վ������ͨѶ����ΪĬ��ֵ
#define NCUC_UD_LOAD_CHANGE  0x1000 //��Ǵ�վ������ͨѶ�������޸�




//SP������ز���
#define PAR_DEV_SP_ENC_IDX    PAR_DEV_AX_ENCOD_TYPE   //��������������豸��
#define PAR_DEV_SP_DA_IDX     PAR_DEV_AX_RESERVE1     //����DA����豸��
#define PAR_DEV_SP_ENC_PORT   PAR_DEV_AX_RESERVE2     //��������������˿ں�
#define PAR_DEV_SP_DA_PORT    PAR_DEV_AX_RESERVE3     //����DA����˿ں�

//��ڿ���ز���
#define PAR_DEV_AX_ENC_IDX    PAR_DEV_AX_ENCOD_TYPE   //�Ῠ�����������豸��
#define PAR_DEV_AX_OUT_IDX    PAR_DEV_AX_RESERVE1     //�Ῠ��������豸��
#define PAR_DEV_AX_ENC_PORT   PAR_DEV_AX_RESERVE2     //�Ῠ�����������˿ں�
#define PAR_DEV_AX_OUT_PORT   PAR_DEV_AX_RESERVE3     //�Ῠ��������˿ں�

//PIDCλ�ذ���ز���
#define PAR_DEV_PIDC_P		  PAR_DEV_AX_RESERVE1     //λ�û���������
#define PAR_DEV_PIDC_K		  PAR_DEV_AX_RESERVE2     //ǰ������
#define PAR_DEV_PIDC_DIR_OFF  PAR_DEV_AX_RESERVE3     //���ᶨ��ƫ��������



//���ڹ�������IO�壬temp
#define	PAR_DEV_AD_OFF 	PAR_DEV_ENCOD1_TYPE	//AD����ƫ������
#define	PAR_DEV_DA_OFF 	PAR_DEV_ENCOD1_PPR	//DA���ƫ������

//����ENCOD�������ӿڰ壬temp
#define PAR_DEV_ENCOD_X_BASE PAR_DEV_IN_X_BASE





//4 �Ĵ�������
#define SYS_MPG_NUM		10	//ͬʱ�ӵ���ҡ��,��ҡ���ݹ���ϵͳ������

#define AXIS_DWORD_NUM	40	//���FG�Ĵ���˫�ָ���
#define CHAN_DWORD_NUM	40	//ͨ����FG�Ĵ���˫�ָ���
#define SYS_DWORD_NUM	80	//ϵͳ��FG�Ĵ���˫�ָ���

#define AXIS_REG_NUM	80	//���FG�Ĵ����ָ���
#define CHAN_REG_NUM	80	//ͨ����FG�Ĵ����ָ���
#define SYS_REG_NUM		160	//ϵͳ��FG�Ĵ����ָ���

#ifdef _HNC_10_
	//FG�Ĵ����е��ᡢͨ����ϵͳ�õ�������ʼƫ��������
	#define REG_AXIS_BASE 0		//+32*40
	#define REG_CHAN_BASE 1280	//+40*[4+1] [MDI]
	#define REG_SYS_BASE 1480	//+80
	#define REG_FG_TOTAL 1560	//=1560

	//���Ĵ����������� �˴�һ��Ϊ4�ֽ�
	#define REG_R_NUM   (572)	//number of R register
	#define REG_X_NUM   (128)	//number of X register
	#define REG_Y_NUM   (128)	//number of Y register
	#define REG_F_NUM   (REG_FG_TOTAL)	//number of F register
	#define REG_G_NUM   (REG_FG_TOTAL)	//number of G register
	#define REG_B_NUM   (1722)   //number of B register

	#define REG_R_BASE	0
		#define REG_R16_BASE		100 //˫�ֽڼĴ�����ʼλ��
		#define REG_R32_BASE		200 //���ֽڼĴ�����ʼλ��
		#define REG_RT_STATE_BASE	300 //��ʱ��״̬��ʼλ��
		#define REG_RT_BASE			308 //��ʱ����ʼλ��
		#define REG_RC_STATE_BASE	436 //������״̬��ʼλ��
		#define REG_RC_BASE			444 //��������ʼλ��
		#define MAX_R8_NUM			400 //���ֽڼĴ�������
		#define MAX_R16_NUM			200 //˫�ֽڼĴ�������
		#define MAX_R32_NUM			100 //���ֽڼĴ�������
		#define MAX_RT_NUM			128 //�Ƕϵ籣�涨ʱ������
		#define MAX_RC_NUM			128 //�Ƕϵ籣�����������
	#define REG_X_BASE	572
	#define REG_Y_BASE	700	
	#define REG_F_BASE	828		//+1560
	#define REG_G_BASE	2388	//+1560
	#define REG_B_BASE	3948	//+1722
		#define REG_BT_STATE_BASE	50 // �ϵ籣�涨ʱ��״̬��ʼλ��
		#define REG_BT_BASE			54 // �ϵ籣�涨ʱ����ʼλ��
		#define REG_BC_STATE_BASE	118 // �ϵ籣�������״̬��ʼλ��
		#define REG_BC_BASE			122 // �ϵ籣�漼������ʼλ�� 
		#define MAX_BU_NUM			50 //�û��Զ���Ĵ���
		#define MAX_BT_NUM			64 //�ϵ籣�涨ʱ������
		#define MAX_BC_NUM			64 //�ϵ籣�����������

	#define REG_DWORD_NUM	5670	//[=23K]
#endif //_HNC_10_


#ifdef _HNC_20_
	//FG�Ĵ����е��ᡢͨ����ϵͳ�õ�������ʼƫ��������
	#define REG_AXIS_BASE 0		//+32*40
	#define REG_CHAN_BASE 1280	//+40*[4+1] [MDI]
	#define REG_SYS_BASE 1480	//+80
	#define REG_FG_TOTAL 1560	//=1560

	//���Ĵ����������� �˴�һ��Ϊ4�ֽ�
	#define REG_R_NUM   (572)	//number of R register
	#define REG_X_NUM   (128)	//number of X register
	#define REG_Y_NUM   (128)	//number of Y register
	#define REG_F_NUM   (REG_FG_TOTAL)	//number of F register
	#define REG_G_NUM   (REG_FG_TOTAL)	//number of G register
	#define REG_B_NUM   (1722)   //number of B register

	#define REG_R_BASE	0
		#define REG_R16_BASE		100 //˫�ֽڼĴ�����ʼλ��
		#define REG_R32_BASE		200 //���ֽڼĴ�����ʼλ��
		#define REG_RT_STATE_BASE	300 //��ʱ��״̬��ʼλ��
		#define REG_RT_BASE			308 //��ʱ����ʼλ��
		#define REG_RC_STATE_BASE	436 //������״̬��ʼλ��
		#define REG_RC_BASE			444 //��������ʼλ��
		#define MAX_R8_NUM			400 //���ֽڼĴ�������
		#define MAX_R16_NUM			200 //˫�ֽڼĴ�������
		#define MAX_R32_NUM			100 //���ֽڼĴ�������
		#define MAX_RT_NUM			128 //�Ƕϵ籣�涨ʱ������
		#define MAX_RC_NUM			128 //�Ƕϵ籣�����������
	#define REG_X_BASE	572
	#define REG_Y_BASE	700	
	#define REG_F_BASE	828		//+1560
	#define REG_G_BASE	2388	//+1560
	#define REG_B_BASE	3948	//+1722
		#define REG_BT_STATE_BASE	50 // �ϵ籣�涨ʱ��״̬��ʼλ��
		#define REG_BT_BASE			54 // �ϵ籣�涨ʱ����ʼλ��
		#define REG_BC_STATE_BASE	118 // �ϵ籣�������״̬��ʼλ��
		#define REG_BC_BASE			122 // �ϵ籣�漼������ʼλ�� 
		#define MAX_BU_NUM			50 //�û��Զ���Ĵ���
		#define MAX_BT_NUM			64 //�ϵ籣�涨ʱ������
		#define MAX_BC_NUM			64 //�ϵ籣�����������

	#define REG_DWORD_NUM	5670	//[=23K]
#endif //_HNC_20_

#ifdef _HNC_30_
	//FG�Ĵ����е��ᡢͨ����ϵͳ�õ�������ʼƫ��������
	#define REG_AXIS_BASE 0		//+32*40
	#define REG_CHAN_BASE 1280	//+40*[4+1] [MDI]
	#define REG_SYS_BASE 1480	//+80
//mark4 trunck�汾ר�ã��ϲ�����ʱ�����˲���
#	define REG_FG_TOTAL 1864	//=1864
#	define REG_AXIS_EXT_BASE 1560	//+32*8//ÿ������չ16
#	define REG_CHAN_EXT_BASE 1816	//+8*[4+1]
#	define REG_SYS_EXT_BASE  1856	//+8
//end of mark4
	//���Ĵ����������� �˴�һ��Ϊ4�ֽ�
	#define REG_R_NUM   (512)	//���ֽڼĴ�������
	#define REG_X_NUM   (128)	//number of X register
	#define REG_Y_NUM   (128)	//number of Y register
	#define REG_F_NUM   (REG_FG_TOTAL)	//number of F register
	#define REG_G_NUM   (REG_FG_TOTAL)	//number of G register
	#define REG_B_NUM   (1722)   //number of B register

//mark5 trunck�汾ר�ã��ϲ�����ʱ�����˲���	
	#define REG_W_NUM	(128)	//˫�ֽڼĴ�������
	#define REG_D_NUM	(256)	//˫�ֽڼĴ�������
	#define REG_I_NUM   (32)   //number of I register
	#define REG_Q_NUM   (32)   //number of Q register
	#define REG_K_NUM	(6)		//number of K register
	#define REG_T_NUM	(512)	//number of T register
	#define REG_C_NUM	(512)	//number of C register

	#define REG_R_BASE		0	//+512
	#define REG_W_BASE	512 //+128
	#define REG_D_BASE	640	 //+256
	#define REG_X_BASE	896		//+128
	#define REG_Y_BASE	1024	//+128
	#define REG_F_BASE	1152	//+1864
	#define REG_G_BASE	3016	//+1864
	#define REG_B_BASE	4880	//+1722
	#define REG_I_BASE 6602 //+32
	#define REG_Q_BASE 6634	//+32
	#define REG_K_BASE 6666	//+6
	#define REG_T_STATE_BASE 6672	//+32	//��ʱ��״̬��ʼλ��
	#define REG_T_BASE 6704	//+512*2
	#define REG_C_STATE_BASE 7728	//+32	//������״̬��ʼλ��
	#define REG_C_BASE 7760	//+512*2



	#define REG_DWORD_NUM	8784	//[8196*4=32K]
//end of mark5
#endif //_HNC_30_


#ifdef _HNC_80_
	//FG�Ĵ����е��ᡢͨ����ϵͳ�õ�������ʼƫ��������
	#define REG_AXIS_BASE 0		//+80*40
	#define REG_CHAN_BASE 3200	//+40*[12+3]
	#define REG_SYS_BASE 3800	//+200
	#define REG_FG_TOTAL 4000	//=

	//���Ĵ����������� �˴�һ��Ϊ4�ֽ�
	#define REG_R_NUM   (572)	//number of R register
	#define REG_X_NUM   (128)	//number of X register
	#define REG_Y_NUM   (128)	//number of Y register
	#define REG_F_NUM   (REG_FG_TOTAL)	//number of F register
	#define REG_G_NUM   (REG_FG_TOTAL)	//number of G register
	#define REG_B_NUM   (3444)   //number of B register

	#define REG_R_BASE	0
		#define REG_R16_BASE		100 // ˫�ֽڼĴ�����ʼλ��
		#define REG_R32_BASE		200 // ���ֽڼĴ�����ʼλ��
		#define REG_RT_STATE_BASE	300 // ��ʱ��״̬��ʼλ��
		#define REG_RT_BASE			308 // ��ʱ����ʼλ��
		#define REG_RC_STATE_BASE	436 // ������״̬��ʼλ��
		#define REG_RC_BASE			444 // ��������ʼλ��
		#define MAX_R8_NUM			400 // ���ֽڼĴ�������
		#define MAX_R16_NUM			200 // ˫�ֽڼĴ�������
		#define MAX_R32_NUM			100 // ���ֽڼĴ�������
		#define MAX_RT_NUM			128 // �Ƕϵ籣�涨ʱ������
		#define MAX_RC_NUM			128 // �Ƕϵ籣�����������
	
	#define REG_X_BASE	572
	#define REG_Y_BASE	700	
	#define REG_F_BASE	828		//+4000
	#define REG_G_BASE	4828	//+4000
	#define REG_B_BASE	8828	//+3444
		#define REG_BT_STATE_BASE	100 // �ϵ籣�涨ʱ��״̬��ʼλ��
		#define REG_BT_BASE			108 // �ϵ籣�涨ʱ����ʼλ��
		#define REG_BC_STATE_BASE	236 // �ϵ籣�������״̬��ʼλ��
		#define REG_BC_BASE			244 // �ϵ籣�漼������ʼλ�� 
		#define MAX_BU_NUM			100 //�û��Զ���Ĵ���
		#define MAX_BT_NUM			128 //�ϵ籣�涨ʱ������
		#define MAX_BC_NUM			128 //�ϵ籣�����������

	#define REG_DWORD_NUM	12272	//[=48K]
#endif //_HNC_80_

//�Ĵ�������
#define _hnc_get_r_num() (REG_R_NUM*4) //RΪһ���ֽ�
#define _hnc_get_x_num() (REG_X_NUM*4) //XΪһ���ֽ�
#define _hnc_get_y_num() (REG_Y_NUM*4) //YΪһ���ֽ�
#define _hnc_get_b_num() (REG_B_NUM)   //BΪ�ĸ��ֽ�
#define _hnc_get_f_num() (REG_F_NUM*2) //FΪ�����ֽ�
#define _hnc_get_g_num() (REG_G_NUM*2) //GΪ�����ֽ�
//mark6 trunck�汾ר�ã��ϲ�����ʱ�����˲���
#	define _hnc_get_w_num() (REG_W_NUM*2)//	WΪ�����ֽ�
#	define _hnc_get_d_num() (REG_D_NUM)	//	DΪ�ĸ��ֽ�
#	define _hnc_get_i_num() (REG_I_NUM*4) //IΪһ���ֽ�
#	define _hnc_get_q_num() (REG_Q_NUM*4) //QΪһ���ֽ�
#	define _hnc_get_k_num() (REG_K_NUM*4) //KΪһ���ֽ�
#	define _hnc_get_t_num() (REG_T_NUM) //TΪ�ĸ��ֽ�
#	define _hnc_get_c_num() (REG_C_NUM) //CΪ�ĸ��ֽ�

//PLCϵͳ����(K�Ĵ���)
#	define REG_PLC_SET_STATE0 16 //PLCϵͳ����״̬��0
	#	define PLC_SET_LAD_SHOW_EN		0x01	//	������ͼ��ʾ
	#	define PLC_SET_RAM_WR_EN		0x02	//	����ǿ�ƹ���
	#	define PLC_SET_REG_LOCK_EN		0x04	//	����Ĵ�������
	#	define PLC_SET_LAD_EDIT_EN		0x08	//	������ͼ�༭

	#	define PLC_SET_PLC_START 		0x10	//	PLC���з�ʽ
	#	define PLC_SET_PLC_STOP_EN 	0x20	//	����PLCֹͣ
	#	define PLC_SET_ONLINE_EN 		0x40	//	����PLC���ߵ���
	#	define PLC_SET_LAD_PARA_EN		0x80	//	������ͼ������ʾ

#	define REG_PLC_SET_STATE1 17 //PLCϵͳ����״̬��1
	#	define PLC_SET_COIL_CHECK_TYPE 	0x01	//	˫��Ȧ��鷽ʽ
	#	define PLC_SET_REG_VAL_VIEW_TYPE 	0x02	//	��ͼ��Ͻ���Ĵ���ֵ��ʾ��ʽ(Ĭ����ʾ�Ĵ�������ֵ)
//end of mark6
//��״̬�Ĵ���
//REG_AXIS_BASE+i*AXIS_REG_NUM
#define REG_AX_STATE 0	//��״̬��0
	#define AX_STATE_MOVING	0x0001	
	#define AX_STATE_HOME1	0x0002
	#define AX_STATE_HOME2	0x0004
	#define AX_HOME_CANCEL	0x0008

	#define AX_STATE_HOMEF	0x0010
	#define AX_SLAVE_HOMING	0x0020 //���������
 	#define AX_SLAVE_CHEKED	0x0040 //������������
	#define AX_SLAVE_OFF	0x0080 //����ĸ���״̬�Ѿ����

	#define AX_STATE_ONREF1	0x0100 //�ڲο�����	
	#define AX_STATE_ONREF2	0x0200
	#define AX_STATE_ONREF3	0x0400
	#define AX_STATE_ONREF4	0x0800
	#define AX_STATE_ONREFS 0x0F00

	#define AX_STATE_OVERLOAD 0x1000 //�����
	#define AX_STATE_VALID	 0x2000	//ϵͳ��Ĳ�������Ч����ʼ���
	#define AX_STATE_LOCKED	  0x4000 //���Ѿ���ס
	#define AX_STATE_POS_UPDT 0x8000 //���Ѿ��ض�λ
 
#define REG_AX_STATE1 1	//��״̬��1
	#define AX_FLAG1_MOV_EN	 0x0001 //PLC�ƶ�����ʹ��
	#define AX_FLAG1_S_ABC	 0x0002 //����ģʽ����ABC��ģʽ
	#define AX_FLAG1_S_ZP	 0x0004 //������������

	#define AX_FLAG1_G00_MOV 0x0010 //���ƽ���״̬�����ڵ�2�����϶����ֵ�л���
	#define AX_FLAG1_ORI_FIN 0x0020	//�������ᶨ�����
	#define AX_FLAG1_ZERO_OK 0x0040	//�����������ٵ���
	#define AX_FLAG1_SPD_OK	 0x0080	//��������ת�ٵ���

	#define AX_FLAG1_VEL_POS	0x0100	//PID�Ṥ����λ��ģʽ
	#define AX_FLAG1_VEL_FOL	0x0200	//PID�Ṥ�����涯ģʽ
	#define AX_FLAG1_VEL_JUMP	0x0400	//PID�Ṥ��������ģʽ
	#define AX_FLAG1_VEL_MASK	0x0700	//PID������
	#define AX_VEL_FOL_REACH	0x0800	//PID���涯��λ

	#define AX_FLAG1_SPDL_POS 0x1000	//���Ṥ����λ��ģʽ
	#define AX_FLAG1_TURNON	  0x2000	//֪ͨPLC����� PLC�õ����źţ��⿪���� ��ʹ��
	#define AX_FLAG1_ON_IDX	  0x4000	//���ڷֶ�λ��
	#define AX_FLAG1_TURNOFF  0x8000	//��ر�ָ��,PLC�õ����źţ���ֹͣ��λ�ú�������ʹ��

#define REG_SV_STATE 2	//�ŷ�״̬��0
	#define SV_STATE_ZERO_GOT  0x0001 //������Z���岶��
	#define SV_STATE_BUF_RDY   0x0002 //RESERVE  Axis bi-buffer is ready to receive
	#define SV_STATE_ZERO2_GOT 0x0008 //��2������Z���岶��

	#define SV_STATE_HOMEF	   0x0010 //�������
	#define SV_STATE_CYC_VALID 0x0040 //��λ����ѭ����Ч
	#define SV_STATE_PARM_SW   0x0080 //�ŷ������л�״̬��0��Ĭ�ϲ��� 1�����л�Ϊ��2���ŷ�����
	
	#define SV_STATE_RDY	   0x0100 //�ŷ�ʹ��׼����
	#define SV_MODE_POS		   0x0200 //λ�ù���ģʽ
	#define SV_MODE_VEL		   0x0400 //�ٶȹ���ģʽ
	#define SV_MODE_TRQ		   0x0800 //���ع���ģʽ
	#define SV_MODE_MASK	   0x0E00 //����ģʽ����

	#define SV_STATE_ZERO	   0x1000 //z���岶��	
	#define SV_GAIN_OK		   0x2000 //�����л����
	#define SV_SPEED_REACH	   0x4000 //�����ٶȵ���
	#define	SV_SPEED_ZERO	   0x8000 //�������ٵ���

#define REG_SV_STATE1 3	//�ŷ�״̬��1
	#define SV_STATE_OK        0x0001 //�ŷ������ޱ���/��ʾ
    #define SV_STATE_ALM       0x0002 //�ŷ����������������������REG_AX_SV_ALM_NO
	#define SV_STATE_MSG	   0x0004 //�ŷ���ʾ����ʾ�����������REG_AX_SV_MSG_NO

// 	#define SV_STATE_STEP      0x0010 //�ŷ���Ծ��Ӧ״̬λ
	#define SV_STATE_SPORIN	   0x0100 //���ᶨ�����
	#define SV_STATE_HOME_FIN  0x0200 //�ŷ��������
	#define SV_STATE_HOME_ALM  0x0400 //�ŷ����㱨��

#define REG_AX_CHAN_IDX     4	//4  ��������ͨ��
#define REG_AX_SLAVE_NUM    5	//5  �����Ĵ������ 

#define REG_AX_POS_INC      6   //6~7   ʵʱ�����ָ���������������
#define REG_AX_POS_CMD      8	//8~11  ʵʱ�����ָ��λ�ã��������

#define REG_AX_CMD_PULSE    12	//12~15 ���ָ������λ�ã����嵥λ
#define REG_AX_PULSE_INC    16	//16~17 ���ָ���������������嵥λ
#define REG_AX_TRQ_CMD      18	//18~19 ���ָ������

#define REG_AX_POS_ACT      20	//20~23 1�ű���������ʵ��λ�ã��׶ȵ�λ
#define REG_AX_POS2_ACT     24	//24~27 2�ű���������ʵ��λ�ã��׶ȵ�λ

#define REG_AX_MAC_CMD      28	//28~31 ����ָ��λ�ã��׶ȵ�λ
#define REG_AX_MAC_ACT      32	//32~35 ����ʵ��λ�ã��׶ȵ�λ

#define REG_AX_ERR_FLAG     36  //36~37 �ᱨ��
#define REG_AX_NOTE_FLAG    38  //38~39 ����ʾ��Ϣ��־ ������ syserr.h

#define REG_AX_BIG_VEL      40	//40~41
#define REG_AX_Z_SW_DIST    42  //42~43 ���㿪����Z���ľ���
#define REG_AX_BIG_ACC      44	
#define REG_AX_WAVE_CYLE    45	//45    ����ָ������
#define REG_AX_TOL_CMPE     46  //46~49 �ܲ���ֵ��������̬�����Ͷ�̬����
#define REG_AX_SYNC_LAG     50  //50~53 ͬ��λ��ƫ��
#define REG_AX_SYNC_VEL_ERR 54  //54~55 ͬ���ٶ�ƫ��
#define REG_AX_SYNC_TRQ_ERR 56  //56~57 ͬ������ƫ��
#define REG_AX_FREE_INC		58  //58~59 ������״̬�µ��ۼ�����

#define REG_AX_BIGAV_NUM	60  //60 ʵ���ٶ��ۼƳ��ٴ���
								//61 ����
#define REG_AX_FLAG_G00		62	//62~63 G00ָ��������־ ͬ��������������ͬ
#define REG_AX_VEL_FWD		64	//64~65 �ٶ�ǰ��
#define REG_AX_TRQ_FWD		66	//66~67 Ť��ǰ��

#define REG_AX_OFF_ALARM    68  //�ᷴ������
#define REG_AX_CRC_ERR		69	//��У�����

#define REG_AX_TYPE_STATE	70	//�����ģʽ��2Ϊ�����жϣ�3ΪPMCģʽ
#define REG_AX_PID_DEM_STEP	71	//�涯��궨����
#define REG_AX_PID_DEM_NUM	72	//�涯��궨����
#define REG_AX_PID_STATE	73	//PID��״̬
	#define REG_AX_PID_DEM	   0x0001	//PID��궨���
    #define REG_AX_PID_PB	   0x0002	//PID�������ź�
    #define REG_AX_PID_DY1     0x0004   //PID��궨���1
    #define REG_AX_PID_DY2     0x0008   //PID��궨���2
	#define AX_FOLLOW_SP_M3    0x0010   //������ת
	#define AX_FOLLOW_SP_M4    0x0020   //���ᷴת
    #define AX_FOLLOW_SP_STOP  0x0040   //����ֹͣ
	#define AX_FREQTAP_SP_M3   0x0100   //��Ƶ������ת
	#define AX_FREQTAP_SP_M4   0x0200   //��Ƶ���ᷴת
	#define AX_FREQTAP_SP_STOP 0x0400   //��Ƶ����ֹͣ
#define REG_AX_SHELF_TAR	74	//�ᵱǰ��λ
#define REG_AX_LEAD_NO  75  //�Ӷ���ĵ��������
	#define REG_AX_LEAD_EXIST	0xC000 //������ڵ�����
	#define REG_AX_LEAD_RIGID	0x8000 //������ڵ�����(����ͬ��������1)
	#define REG_AX_LEAD_FIEX	0x4000 //������ڵ�����(����ͬ��������11)

#define REG_AX_STATE2	76	//��״̬��2
	#define AX_FLAG2_SYNC_OK	0x0001	//ͬ�����
	#define	AX_FLAG2_FREQTAP	0X0002  //��Ƶ���ṥ˿������
	#define AX_FLAG2_SERVO_SW	0x0004	//�ŷ����㿪ʼ
	#define AX_FLAG2_HOME_GO	0x0008	//���㿪ʼ��ֻ��Чһ�����ڣ�����֪ͨ���Ὺʼ����

#define REG_AX_SHELF_ACT	77  //�ᵱǰ��λ
//#define REG_AX_CYC_PULSE	78	//78~79 ��ʵ������ѭ�����������������ڶ൵���ỻ��ʱ����ѭ������������
#define REG_AX_SHELF_OUTP	78	//�ᵱǰ��λ����
#define REG_AX_SHELF_FBKP	79	//�ᵱǰ��λ��ĸ
//����Ϊ��F��չ�Ĵ�������
#define REG_AX_EX_ELECTRICITY_SPEC 0 // 0~1 ������Ԫ�������
// ����Ϊ��F��չ�Ĵ�������
#define  REG_AX_EX_ELECTRICITY_SPEC 0 // 0~1 �������������

//����ƼĴ���
//REG_AXIS_BASE+i*AXIS_REG_NUM
#define REG_AX_CTRL 0	//�������0
	#define AX_CTRL_LSP_SW		0x0001	//����λ����
	#define AX_CTRL_LSN_SW		0x0002	//����λ����
	#define AX_CTRL_DIS_P		0x0004	//�����ֹ
	#define AX_CTRL_DIS_N		0x0008	//�����ֹ

	#define AX_CTRL_HOME_CMD	0x0010	//����ָ��	
	#define AX_CTRL_HOME_SW		0x0020	//���㵲��
	#define AX_CTRL_LOCK		0x0040	//��������ס
	#define AX_CTRL_EN_SW		0x0080	//���ؿ�

//	#define AX_CTRL_GO_SAFE1	0x0100	//����#1��ȫλ��
//	#define AX_CTRL_GO_SAFE2	0x0200	//����#2��ȫλ��
//	#define AX_CTRL_GO_SAFE3	0x0400	//

	#define AX_CTRL_VEL_POS		0x0100	//PID��λ��ģʽ����
	#define AX_CTRL_VEL_FOL		0x0200	//PID���涯ģʽ����
	#define AX_CTRL_VEL_JUMP	0x0400	//PID������ģʽ����
	#define AX_CTRL_VEL_MASK	0x0700	//PID������

	#define AX_FREE_SLAVE		0x0800	//������Ͻ�� PLC��ϵͳ�� ���õ�������

	#define AX_CTRL_GO_SAFE1	0x1000	//����#1��ȫλ��
	#define AX_CTRL_GO_SAFE2	0x2000	//����#2��ȫλ��
	#define AX_CTRL_EXCOMP		0x4000	//������չ
	#define AX_CTRL_UPDT_POS	0x8000	//�����λ��(DISABLE-ENABLE-REPOS)	
	
#define REG_AX_CTRL1 1	//�������1
	#define AX_CTRL1_MOV2		0x0001	//PMC���˶���Ŀ��λ�� ���������� 
	#define AX_CTRL1_MOV		0x0002	//PMC�������˶�����   ������ͣ���ڲο�λ��
	#define AX_CTRL1_LMT2		0x0004	//��2����λʹ��		  ������ͣ���ڲο�λ��2
	#define AX_CTRL1_LMT3		0x0008	//��չ����λʹ��	  ������ͣ���ڲο�λ��3

	#define AX_CTRL1_SP_JOG		0x0010	//��������㶯
	#define AX_CTRL1_SP_ORI		0x0020	//�������ᶨ��
	#define AX_CTRL1_SP_M3		0x0040	//����������ת
	#define AX_CTRL1_SP_M4		0x0080	//�������ᷴת
	#define AX_CTRL1_SP_MASK	0x00F0	//��������ָ������

	#define AX_CTRL1_SLV_SYNC	0x0100	//ָ��Ӷ���ص�ͬ��λ��
	#define AX_CTRL1_SLV_PMOV	0x0200	//ָ��Ӷ�������΢��
	#define AX_CTRL1_SLV_NMOV	0x0400	//ָ��Ӷ��Ḻ��΢��
	#define AX_CTRL1_SLV_EN_M	0x0800	//ָ��Ӷ���΢��ʹ��
	#define AX_CTRL1_SLV_MASK	0x0700	//ָ��Ӷ�������

	#define AX_CTRL1_POS_RDY	0x1000	//�л�λ��ģʽ׼����
	#define AX_CTRL1_RST_S2C	0x2000	//�л���C�Ḵλ��ָ�Ϊ����
	#define AX_CTRL1_ON_ACK		0x4000	//����ɿ�Ӧ�������ֶ��ᡢ������λת̨��
	#define AX_CTRL1_OFF_ACK	0x8000	//��ر�����Ӧ�������ֶ��ᡢ������λת̨��

#define REG_SV_CTRL 2	//�ŷ�������0
	#define SV_CTRL_TRAP_ZERO   0x0001  //�������������
	#define SV_CTRL_WAIT_ZERO   0x0002  //RESERVE  For spindle      
	#define SV_CTRL_ZERO_DIS    0x0004  //RESERVE  G bit, Disable the zero pulse function
	#define SV_CTRL_TRAP_ZERO2  0x0008  //�����2������������ֱ�߹�դ�߾������
	
	#define SV_CTRL_CLR_VALID	0x0010	//���������㣬���»���
	#define SV_CTRL_ERRRRRR		0x0020	//���ԣ�ģ�����
	#define SV_CTRL_SPDL_ZERO   0x0040  //RESERVE  ������������ʹ��
	#define SV_CTRL_PARM_SW     0x0080  //�ŷ������л� 0��Ĭ�ϲ��� 1���л�Ϊ��2�ײ���
	
	#define SV_CTRL_JAIN_SW		0x0100	//�ŷ������л�
	#define SV_CTRL_MODE_POS	0x0200  //�л���λ�ÿ���
	#define SV_CTRL_MODE_VEL	0x0400  //�л����ٶȿ���
	#define SV_CTRL_MODE_TRQ	0x0800  //�л������ؿ���

	#define SV_CTRL_SPDL_DIR    0x1000  //���ᶨ��
	#define SV_CTRL_SPDL_SHIFT  0x2000  //���ỻ�ߵ����������Ĺ��������ŷ���
	#define SV_CTRL_SPDL_DIRMODE	0x4000  //���ᶨ�򻻵�
	#define SV_CTRL_SPDL_LIMIT	0x8000//��������

#define REG_SV_CTRL1 3	//�ŷ�������1
	#define SV_CTRL_EN_SW	    0x0001  //�ŷ�ʹ�ܿ���
	#define SV_CTRL_ALM_RST     0x0002  //�ŷ�������λ

	#define SV_CTRL_START_SAMP	0x0010  //�ŷ��ɼ�����
	#define SV_CTRL_QUERY_STATE 0x0020
	#define SV_CTRL_READ_DATA	0x0040
	#define  SV_CTRL_SHIELD		0x0080	//�ŷ�������

	#define SV_CTRL_HOME_SW		0x0100	//�ŷ����㿪ʼ
// 	#define SV_CTRL_STEP        0x0010  //�ŷ���Ծ��Ӧ����λ
	#define SV_CTRL_ALL			0x4000	//�ϴ�ȫ�ջ�
	#define SV_CTRL_HALF_ALL	0x8000	//�ϴ���ջ���ȫ�ջ�ƫ��

#define REG_AX_JOG_SW		4	//��ĵ㶯��������
#define REG_AX_STEP_SW		5	//��Ĳ�����������

#define REG_AX_JOG_VEL		6	//6~7   �㶯�ٶ�ֵ[0,ֹͣ;1,�����е��ֶ��ٶ�;2�����еĿ��ƶ��ٶ�;>2�Զ�����ٶȵ�λ����/����]
#define REG_AX_STEP_MUL		8	//��������
#define REG_AX_MPG_MUL		9	//��ҡ����
#define REG_AX_MPG_CNT		10 	//10~11 ��ҡ������

#define REG_AX_ACT_PULSE	12	//12~15 �ᷴ������λ�ã����嵥λ
#define REG_AX_ACT_PULSE_2	16	//16~19 �ᷴ������λ��2�����嵥λ

#define REG_AX_ACT_INC		20	//20~21 �ᷴ���������������嵥λ
#define REG_AX_ACT_INC_2	22	//22~23 �ᷴ����������2�����嵥λ

#define REG_AX_ACT_TRQ		24	//24~25 �ᷴ�����ص���
#define REG_AX_FOLLOW_ERR	26	//26~27 �ᷴ�����������嵥λ

#define REG_AX_ENC_CNTR1	28  //28~31 ������1�ļ�����ֵ
#define REG_AX_ENC_CNTR2	32  //32~35 ������2�ļ�����ֵ

#define REG_AX_RT_CMPE		36	//36~37 ʵʱ����ֵ
#define REG_AX_TIME_STAMP	38	//38~39 ����ʱ���

#define REG_AX_LATCH_PUL1	40	//40~43 ����λ��1 ����G31\���������
#define REG_AX_LATCH_PUL2	44	//44~47 ����λ��2

#define REG_AX_PMC_POS		48	//48~51 PMCĿ��λ��
#define REG_AX_PMC_DIST		52	//52~55 PMC����λ��

#define REG_AX_SV_ALM_NO    56  //56~57 �ŷ�������
#define REG_AX_SV_MSG_NO    58  //58~59 �ŷ���ʾ��

#define REG_AX_TYPE_REQ		60	//�����ģʽ�л�����2Ϊ�����жϣ�3ΪPMCģʽ

#define REG_AX_PMC_RATIO	61	//PMC���޵�
#define REG_AX_CTRL2		62	//�������2
	#define AX_CTRL2_PMC_STOP		0x0001	//PMC��ֹͣ
	#define AX_CTRL2_EXT_CLEAR		0x0002	//�����ж�������
	#define AX_CTRL2_TANG			0x0004	//�������߿��ƹ���
	#define AX_TURNOFF_SWITCH		0x0010	//�ֶ��Ὺ��
    #define AX_FREE_SLAVE_SYNC		0x0020	//������ϻָ�ʱ��ͬ��ͬ�����λ��
	#define AX_CTRL2_SYNC11			0x0040	//����ģʽΪ11��ͬ���Ὺʼͬ��
	#define AX_CTRL2_SYNC_RESIDENT	0x0080	//����ģʽΪ11��ͬ����פ��
	#define AX_CTRL2_SPDL_CTRL		0x0100	//������ƣ�������ʵ��ת��д��ָ���У�����˫�ٵ��
    #define AX_SHIFT_SPEED  0x0200//�������ỻ��ת��

#define REG_AX_PID_CTRL		63	//PID����ָ��
	#define REG_AX_PID_DEM_CMD	0x0001	//PID��궨��ʼ
	#define REG_AX_PID_DEM_SW	0x0002	//PID�ᴥ���ź�
	#define REG_AX_PID_POS_SW	0x0004	//PIDλ�ñ�������ЧʱPID��λ��ģʽ���½�������ź���Чʱ����ֹ�½�

#define REG_AX_SHELF_CUR	64	//�ᵱǰ��λ

#define REG_AX_EXT_LOAD		65	// �ⲿ����ĸ��أ���ɣ�

#define REG_AX_ACT_PULSE1	66	//�൵ʱ��ʹ�õ��ᷴ������λ�ã����嵥λ����ǰλ�ö�ÿ��������ȡ�࣬�õ��Ĵ���12
#define REG_AX_ACT_PULSE1_2	67

#define REG_AX_Z_POS		68//Z����λ��
#define REG_AX_Z_POS_		69
#define REG_AX_Z_SPACE1		70//Z������1
#define REG_AX_Z_SPACE1_	71
#define REG_AX_Z_SPACE2		72//Z������2
#define REG_AX_Z_SPACE2_	73

#define REG_AX_DIVSOR		74//ѭ������Ĺ�Լ��
#define REG_COMP_CYCLE		75//ǰ��������ǰ����

#define REG_AX_SAMP_DATA0	78	//�ŷ���������
#define REG_AX_SAMP_DATA1	79

//ͨ��״̬�Ĵ���
//REG_CHAN_BASE+i*CHAN_REG_NUM 
#define REG_CH_STATE 0 //ͨ��״̬��0
		//���4λ0~7 ��ǰ����ģʽ	
		#define	CH_MODE_RESET	0
		#define	CH_MODE_AUTO	1
		#define	CH_MODE_JOG		2
		#define	CH_MODE_STEP	3
		#define	CH_MODE_MPG		4
		#define	CH_MODE_HOME	5
		#define	CH_MODE_PMC		6 
#ifdef _MCPMDI // MCP����л�MDI��ʽ
		#define CH_MODE_MDI	7

	#define CH_STATE_SBL		0x0008
#else
		#define CH_MODE_SBL		7

	#define CH_STATE_MDI		0x0008
#endif

	#define  CH_AUTO_MASK	0x00F0
	#define CH_STATE_HOLDING	0x0010
	#define CH_STATE_CYCLING	0x0020 //�Զ�������
	#define CH_STATE_MOVING		0x0040 //���Զ�ʱ���˶�
	#define CH_STATE_INTERVEN	0x0080 //���˶����û���Ԥ��
	
	#define CH_STATE_CUTTING	0x0100
	#define CH_STATE_THREADING	0x0200
	#define CH_STATE_PARKING	0x0400
	#define CH_STATE_VERIFYING	0x0800

	#define CH_STATE_HMI_RST	0x1000 //�ϲ㸴λ	
	#define CH_STATE_PAUSE_REQ	0x2000 //��ͣ����
	#define CH_STATE_RESETING	0x4000 //��λ��
	#define CH_STATE_HOMING		0x8000 //ͨ�������������Z���壬��ֹ�л�ģʽ

#define REG_CH_STAT1 1 //ͨ��״̬��1 [��λ����]
	#define CH_STATE_PROGSEL	0x0001 //����ѡ�У���������
	#define CH_STATE_TRYSTART	0x0002 //����������ͨ��������
	#define CH_STATE_PROGEND	0x0004 //������ɣ�ͨ��������
	#define CH_STATE_IRQ_FIN	0x0008 //G28/G31���ж�ָ�����
	#define CH_STATE_IRQ_SKIP	0x0010 //�ж�ָ������
	#define CH_STATE_WAIT_FIN	0x0020 //�ȴ�ָ�����
	#define CH_STATE_REWINDED	0x0040 //���������и�λ
	#define CH_STATE_SBL_FIN	0x0080 //�����������

	#define CH_STATE_BP_LOAD	0x0100	//ͨ�����ضϵ�
	#define CH_STATE_AX_UPDT	0x0200	//ͨ���������λ�ã�������ס��
	#define CH_STATE_FLUSH2		0x0400	//ͨ��������嵽���ж�
	#define CH_STATE_S_RESET	0x0800	//ͨ�������ḴλΪ����

	#define CH_STATE_IRQ_WAIT	0x1000	//�ȴ��жϵ���Ӧ
	#define CH_RTCP_ON			0x2000	//RTCP���ܿ���
	//#define CH_STATE_S_FLUCT	0x2000  //���Შ���ѿ���
	#define CH_STATE_FLUSHING	0x4000  //
    #define CH_TAX_VCS          0x8000  //б�Ṧ�ܿ���

#define REG_CH_MSTB_CMD 2 //ͨ��MSTָ����
	#define CH_MSTB_MMASK	0x00FF //MAX_MPER_ROW��4��8����Mָ��
	#define CH_MSTB_TBMASK	0x0500 //TB����
	#define CH_MSTB_TFLAG	0x0100  //ѡ�����
	#define CH_MSTB_TOFFS	0x0200	//��ƫ���[T�к���ƫ��]
	#define CH_MSTB_INDEX	0x0400  //�зֶ���ָ����
	#define CH_MSTB_G96		0x0800	//������� ��
	#define CH_MSTB_SMASK	0xF000 //4��Sָ��
	#define CH_MSTB_S1FLAG	0x1000 //��1��Sָ��
	#define CH_MSTB_S2FLAG	0x2000 //��2��Sָ��
	#define CH_MSTB_S3FLAG	0x4000 //��3��Sָ��
	#define CH_MSTB_S4FLAG	0x8000 //��4��Sָ��

	//���� ����Reg ���	
	#define CH_MSTB_SSTART	12 //S��־����ʼλ��

#define REG_CH_OUT_FLAG		4	//4~7 �����PLC��ͨ����־
								//8����					

#define REG_CH_T_OFFS  9 //9 T��ƫ�� 16λ
#define REG_CH_S_CODE 10 //10~17 ͨ������Sָ�4�����ᡣ��λr/min

#define REG_CH_G31WAIT_IDX	18 //��ǰ�ȴ��źŵ�G31���
#define REG_CH_RUN_CRDS		20 //��ǰ���е�����ϵ
#define REG_CH_AXES_IDX		21 //21~29  ͨ�����
#define REG_CH_SPDL_IDX		30 //30~33  ͨ�������
#define REG_CH_ERR_SYNTAX	34 //34~35  �﷨������
#define REG_CH_ERR_FLAG		36 //36~39  ͨ�������� 64��ͨ������
#define REG_CH_NOTE_FLAG	40 //40~43  ͨ����ʾ��Ϣ��־ ������ syserr.h
#define REG_CH_USER_OUT		44 //44~47  �û����
#define REG_CH_M_COMMAND	48 //ͨ��Mָ���ͬʱִ��8��Mָ��
#define REG_CH_T_COMMAND	56 //T���ߺ� 16λ 
#define REG_CH_B_COMMAND	57 //�۴�B��PLCִ��,����ֶ���Bָ��
#define	REG_CH_T_READY		58 //��ǰ׼���ý����ĵ���
#define REG_CH_DA_OUT		60 //60~68  �û���ֵ��� 
#define REG_CH_FLUSH_STEP	70	//�ڲ���λ����
#define REG_CH_RESET_STEP	71	//�ⲿ��λ����
#define REG_CH_ALARM_TOOL	72 // �����ĵ��ߺ�
#define REG_CH_FILTER_WIDTH	73 // ͨ����ǰָ���˲����
#define REG_CH_HANDLE_BUF   74  //wx,�������л���
#define REG_CH_HANDLE_RATIO 75  //wx,�������б��ʣ���Чʱ��������޵��Ϳ����޵�
#define REG_CH_STAT2        76 // ͨ��״̬��2
	#define CH_STATE_RESET	    0x0001  //ͨ����λ
    #define CH_STATE_STOP_CHECK 0x0002  //����׼ͣ��λ
    #define CH_STATE_TAX_VCS    0x0004  //�ϸ����ڵ�б���־���ڽ���б��������ж�ʱʹ��
	#define CH_STATE_G0         0x0008  //ͨ�����в岹ָ��
	#define CH_STATE_SPDL_SYNC  0x0010  //����ͬ�����
	#define CH_STATE_HANDLE_DIR	0x0020	//���ֽ�������

#define REG_CH_PROG_FLOW		77	//�ӳ����������
    #define CH_PROG_FLOW_GO	    0x0001	//�ӳ������̿�ʼ
    #define CH_PROG_FLOW_WAIT	0x0002	//�ӳ���ȴ��������֣�����ϵ�
    #define CH_PROG_FLOW_FLAG	0x0004	//�ϵ��־
    #define CH_PROG_FLOW_LOAD	0x0008	//��ʼ�����ӳ���
    #define CH_PROG_FLOW_LOADOK	0x0010	//�������
    #define CH_PROG_FLOW_RUN	0x0020	//��ʼ����
    #define CH_PROG_FLOW_RUNOK	0x0040	//�������
    #define CH_PROG_FLOW_RESUME	0x0080	//�ϵ�ָ����
    #define CH_PROG_FLOW_FINISH	0x0100	//���̽���
    #define CH_PROG_FLOW_ERR	0x0200	//���̴���
    #define CH_PROG_FLOW_RESET  0x0400  //���̸�λ
	#define CH_PROG_FLOW_DCD_OK 0X0800  //���̵ȴ���������λ���
	#define CH_PROG_FLOW_MASK   0X0FFF
#define REG_CH_LIFE             78  //��������
    #define REG_CH_LIFE_COUNT	0x0001	//�������������ۼӱ��

//ͨ�����ƼĴ���
//REG_CHAN_BASE+i*CHAN_REG_NUM 
#define REG_CH_CTRL 0 //ͨ��������
	#define CH_MODE_MASK		0x0007
//		#define	CH_MODE_RESET	0
//		#define	CH_MODE_AUTO	1
//		#define	CH_MODE_JOG		2
//		#define	CH_MODE_STEP	3
//		#define	CH_MODE_MPG		4
//		#define	CH_MODE_HOME	5
//		#define	CH_MODE_PMC		6
//		#define CH_MODE_SBL		7
	
	#define CH_CTRL_HOLD_SW		0x0010
	#define CH_CTRL_CYCLE_SW	0x0020
	#define CH_CTRL_DRY_RUN		0x0040
	#define CH_CTRL_ESC_SW		0x0080	//�����ж�

	#define CH_CTRL_VERIFY	0x0100  //У��
	#define CH_CTRL_RST_ACK	0x0200  //PLC��NC��λ��Ӧ��	
	#define CH_CTRL_HMI_RST	0x0400	//�ڲ���λ[�û�������]
	#define CH_CTRL_ESTOP	0x0800	//ESTOP

	#define CH_CTRL_FLUSH	0x1000	//��ͨ������  
	#define CH_CTRL_RESET	0x2000	//��λͨ�����ⲿ��
	#define CH_CTRL_RESUME	0x4000	//ͨ�����ݻָ�
	#define CH_CTRL_SAVE	0x8000	//ͨ�����ݱ���

#define CH_CTRL_PROC_MSK	0xFF00 //ͨ�������־��
	
#define REG_CH_CTRL1 1 //������������
	#define CH_CTRL_PRG_RUN	0x0001 //����������
	#define CH_CTRL_PRGRWD2	0x0002 //�����������е�2��
	#define CH_CTRL_SKIP	0x0004	//����
	#define CH_CTRL_SELSTP	0x0008	//ѡ��ͣ
	#define CH_CTRL_DCD_RST	0x0010 //��������λ
	#define CH_CTRL_PRG_RWD	0x0020 //������������
	#define CH_CTRL_RUN_ROW	0x0040 //��������������
	#define CH_CTRL_RESUME2	0x0080 //���������ݻָ�
	#define CH_CTRL_SAVE2	0x0100 //���������ݱ���
	#define CH_CTRL_STOPCHK	0x0200	//׼ͣ���
	#define CH_CTRL_USER_MC	0x0400  //�û��˶�����
	#define CH_CTRL_IRQ		0x0800	//�ⲿ�ж�	
	#define CH_CTRL_MPG_INTER	0x1000//���������ж�
	#define CH_CTRL_OVERRIDE    0x2000  //�����޵�Ϊ0ʱ,�ý����޵�����g00,���25%
	#define CH_CTRL_CHG_PRG	    0x4000	//�����޸ı�־
	#define CH_CTRL_WT_CHG	    0x8000	//�����򹤾�����仯���������½��͡�HMI�á�

#define CH_DCD_PROC_MSK		0x81F0 //�����������־��

#define REG_CH_MSTB_CTRL 2 //ͨ��MSTָ��Ӧ����
	//#define CH_MSTB_M_ACK	0x00FF
    #define CH_S1CODE_ACK   0x0001  //��һ��Sָ��Ӧ��
    #define CH_S2CODE_ACK   0x0002  //�ڶ���Sָ��Ӧ��
    #define CH_S3CODE_ACK   0x0004  //������Sָ��Ӧ��
    #define CH_S4CODE_ACK   0x0008  //���ĸ�Sָ��Ӧ��
    #define CH_SCODE_MASK   0x000F     //Sָ��Ӧ������
	#define CH_MSTB_HANDLE_BACK   0x0100  //  ��������0Ϊǰ����1Ϊ����
	#define CH_MSTB_FROG_ON		  0x0200 //�������ƿ�
	#define CH_MSTB_SPDL_CHK	  0x0400 //�����ٶȼ��
	#define CH_MSTB_LOCK		  0x0800
	#define CH_MSTB_SP_NORUN	  0x1000 //����δ����
	#define CH_MSTB_SP_NOTOK	  0x2000 //����ת��δ����
	#define CH_MSTB_FOLLOW_ON	  0x4000 //������ƿ���
    #define CH_MSTB_HANDLE_ON     0x8000  //  ���ֱ���    

#define REG_CH_TOOL_USING	3 //Tָ��
#define REG_CH_FEED_RATIO	4 //�����޵�
#define REG_CH_RAPID_RATIO	5 //�����޵�
#define REG_CH_SPDL_RATIO	6 //6~9����1��2��3��4�޵�
#define REG_CH_SPDL_VALUE	10 //10~17�������ָ�PLC����F�е�s������������G��

#define REG_CH_MANUAL_CTRL	18   //�ֶ�������
	#define	REG_CH_WCS_CTRL		0x0001  //��������ϵ����
	#define REG_CH_VCS_CTRL		0x0002  //��������ϵ����
	#define TOOL_ROBOT_CTRL     0X0004  //1ms����һ��pos_vir_to_real
	#define REG_CH_TOOL_CTRL	0x0300 	//��������ϵ����
	#define TOOL_CTRL_INIT		0x0100		//��������ϵ���Ƴ�ʼ��
	#define TOOL_CTRL_RUN		0x0200		//��������ϵ��������

#define REG_CH_PART_CNTR	19 //19 �ӹ��Ƽ�
#define REG_CH_IN_FBD_MASK	20 //�ڽ�ֹ����
#define REG_CH_EX_FBD_MASK	21 //���ֹ����
#define REG_CH_ESC_IDX		22 //22 �����ж�ʱG31�ı��
#define REG_CH_PART_NEED	23 //�ӹ�����
#define REG_CH_USER_IN		24 //24~27 �û�λ���룬
#define REG_CH_AD_IN		28 //28~47 �û���ֵ���룬
#define REG_CH_MCODE_ACK	48
#define REG_CH_TCODE_ACK	56 
#define REG_CH_FOLLOW_TYPE	57 //��ת������������ 
	#define FLAG6_AX_FOLLOW_MASK	0x00FF//���������  
	#define FLAG6_TOOL_TANGENT_FOLLOW	1	//�������߸���
	#define FLAG6_TABLE_TANGENT_FOLLOW	2	//����̨���߸���
	#define	FLAG6_TOOL_CHORD_FOLLOW		11	//�������߸���
	#define FLAG6_TABLE_CHORD_FOLLOW	12	//����̨���߸���
	#define FLAG6_CH_FOLLOW_MASK	0xFF00//ͨ��/�ϳ�����������
	#define FLAG6_CH_FOLLOW1	0x0100//���������
	#define FLAG6_CH_FOLLOW2	0x0200//ֱ�Ӹ���
	#define FLAG6_CH_FOLLOW3	0x0300//	

#define REG_CH_IN_CTRL		60 //60~67 PLC�����ͨ���Ŀ�����

#define REG_CH_SPDL_CMD		68 //68~75�������ָ��ת������������ʵ��ת����ƫ�������Შ��
#define REG_CH_CTRL2        76 //ͨ��������2
	#define CH_CTRL_RESET_START	0x0001 //ͨ����λ��PLC�üĴ�����֪ͨHMI����ͨ����λ��
    #define CH_CTRL_READ_STOP   0x0002  //�����ֹ��Ϊ1ʱ������ȴ���Ϊ0ʱ�������������
	#define CH_CTRL_RE_DECODE   0X0004 //ͨ�����½���
	#define CH_CTRL_IRQ2        0X0008 // IRQ����
	#define CH_CTRL_RESET_FORBID      0X0010 // ͨ����ֹ��λ��Reset������Ч��
	#define CH_CTRL_LIFE_STOP 0X0020	//������ʱ/������ͣ
	#define CH_CTRL_EV_LOAD_PROG_FAIL 0X0040	// PLC�¼��������ʧ�ܱ�ǡ�HMIʹ�á�
    #define CH_CTRL_DCD_HAVE_BACKUP 0X0080      //�ں������ѱ���
    #define CH_CTRL_DCD_BACKUP 0X0100           //�Զ�ִ�г���ʱ�������ֶ��ӳ��򣬱��ݽ�����
    #define CH_CTRL_DCD_RESUME 0X0200           //�ָ�֮ǰ���ݵĽ���������
    #define CH_CTRL_JOG_PROG_AUTO_SBL_HOLDING 0X0400 //�Զ�/����״̬ʱ�����ֶ��ӳ���Ľ�������
	#define CH_CTRL_IS_RIGID 0X0800	// ���Թ�˿��־
    #define CH_CTRL_SPDL_TURN 0X1000    // ������ת���
	#define CH_CTRL_ONLY_DECODER_RESET 0X2000    // ����������λ������У��ģʽ

#define REG_CH_PROG_RUN		77	//�ӳ������
	#define CH_CTRL_PROG1	0x0001
	#define CH_CTRL_PROG2	0x0002
	#define CH_CTRL_PROG3	0x0004
	#define CH_CTRL_PROG4	0x0008
	#define CH_CTRL_PROG5	0x0010
	#define CH_CTRL_PROG6	0x0020
	#define CH_CTRL_PROG7	0x0040
	#define CH_CTRL_PROG8	0x0080
	#define CH_CTRL_PROG9	0x0100
	#define CH_CTRL_PROG10	0x0200
	#define CH_CTRL_PROG11	0x0400
	#define CH_CTRL_PROG12	0x0800
	#define CH_CTRL_PROG13	0x1000
	#define CH_CTRL_PROG14	0x2000
	#define CH_CTRL_PROG15	0x4000
	#define CH_CTRL_PROG16	0x8000

#define REG_CH_PRE_TOOL		78  // PLCԤѡ��
#define REG_CH_TOOL_TIMES	79  // ������������

//ϵͳ״̬�Ĵ���
#define SYS_NC_STATE	0 //ϵͳ״̬��
	#define SYS_STATUS_ON	0x0001
	#define SYS_PLC_ONOFF	0x0002 //1���� 0ֹͣ
	#define SYS_FLAG_ESTOP	0x0004
	#define SYS_FLAG_RESET	0x0008

	#define SYS_FLAG_POWERDOWN	0x0010 //�ϵ���
	#define SYS_FLAG_SAVINGDATA	0x0020 //����������
	#define SYS_FLAG_SYNCHRO	0x0040 //ɨ��ģʽ��ͬ��״̬
	#define SYS_FLAG_SUSPEND	0x0080 //����

	#define SYS_SAMPLE_ON	0x0100 //����״̬���
	#define SYS_SAMPLE_FIN	0x0200 //����������־
	#define SYS_SERVO_ADJUST_ON	0x0400 //�ŷ��������ܿ�
	#define SYS_NET_PROTECT	0x0800	//����Ͽ�����

	#define SYS_UPS_ACFAIL	0x1000 //UPS�ϵ籣��������־
	#define SYS_FORBID_RUN	0x2000 //ϵͳ��ֹѭ��������־
	#define SYS_RESET_KEY	0x4000 //ϵͳReset������λ
	#define SYS_INIT_FIN	0x8000 //�����׼���ã������δ׼����ʱ���뼱ͣ

#define SYS_NC_CHMSK	1 //ͨ������״̬��

#define BUS_BOARD_FLAG	2 //2~3 Ԥ��2������ͨѶ״̬��
	#define BUS_FLAG_IDLE     0x0000	//������
	#define BUS_FLAG_RESETING 0x0001	//��λ��
	#define BUS_FLAG_PROBING  0x0002	//�����
	#define BUS_FLAG_SORTING  0x0004	//��ַ��
	#define BUS_FLAG_READING  0x0008	//�����ƶ���������
	#define BUS_FLAG_NETOK    0x0010	//����OK
	#define BUS_FLAG_MAPPING  0x0020	//����ӳ����
	#define BUS_FLAG_READY    0x0040	//����׼����
	#define BUS_FLAG_RUN      0x0080	//ͨѶ����

#define BUS_NET_ASYN_ERR_CNT	4 //����ͨѶ�����������ۼƶ�������
#define BUS_NET_SYNC_UNSENT_CNT 5 //����ͨѶ��������δ�ɹ����ͼ���
#define BUS_NET_SYNC_ERR_CNT	6 //����ͨѶ���������ۼƶ�������
#define BUS_NET_SYNC_ERR_SEQ	8 //����ͨѶ��������������������

#define BUS_BOARD_ALARM 10 //10~13 Ԥ��4������ͨѶ������
	//NET
	#define BUS_ALARM_NET_UNOK      0x0001 //�������Ӳ�����
	#define BUS_ECAT_INIT_FAILED		0x0002 //ECAT��վ��ʼ��ʧ��
	#define BUS_ALARM_NET_CRC_ERR   0x0004 //��������֡У�����
	#define BUS_ECAT_CONF_BREAK		0x0008	//ECAT�����ļ���ȡʧ��
	#define BUS_ECAT_SLV_NUM_UNMAT	0x0010	//ECAT�����ļ����豸��Ŀ��ʵ�ʲ���
	//SLV 
	#define BUS_ALARM_SLV_UNREG     0x0020 //���ߴ�վ�豸�޷�ʶ��
	#define BUS_ALARM_SLV_CFG_ERR   0x0080 //���ߴ�վģʽ���ó���
	//SV
	#define BUS_ALARM_SV_PARA_CHECK 0x0100 //У���ŷ���������
	#define BUS_ALARM_SV_PARA_READ  0x0200 //��ȡ�ŷ�����ʧ��
	#define BUS_ALARM_SV_PARA_WRITE 0x0400 //�����ŷ�����ʧ��
	#define BUS_ALARM_SV_PARA_SAVE  0x0800 //�����ŷ�����ʧ��
	#define BUS_ALARM_SV_PARA_DFT   0x1000 //�ָ��ŷ�����ʧ��

#define BUS_ALARM_NET_CRC_ERR_PART 14//��������֡У��������
#define SYS_HMI_ALARM_ERR1			15 // HMI��ر���1��ERR��
	#define SYS_HMI_ERR_TOOL_FILE_LOAD_FALSE	(0x0001)	// �����ļ�����ʧ��
	#define SYS_HMI_ERR_BREG_FILE_LOAD_FALSE	(0x0002)	// B�Ĵ����ļ�����ʧ��
	#define SYS_HMI_ERR_PARM_FILE_LOAD_FALSE1	(0x0004)	// �ϴα�������ļ����쳣,���ʵ��������
	#define SYS_HMI_ERR_PARM_FILE_LOAD_FALSE2	(0x0008)	// �����ļ�����ʧ��

	#define SYS_HMI_ERR_UPS_ERR					(0x0010)	// �ϴζϵ����ݱ���ʧЧ,����UPS��Դ
	#define SYS_HMI_ERR_PROG_INIT_FALSE			(0x0020)	// �����������ʼ��ʧ��
	#define SYS_HMI_ERR_PLC_INIT_FALSE			(0x0040)	// PLC�ļ�����ʧ��
	#define SYS_HMI_ERR_ALARM_INIT_FALSE		(0x0080)	// ����ģ���ʼ��ʧ��

	#define SYS_HMI_ERR_CRD_FILE_LOAD_FALSE1	(0x0100)	// �ϴα�������ϵ�ļ����쳣,���ʵ����ϵ����
	#define SYS_HMI_ERR_CRD_FILE_LOAD_FALSE2	(0x0200)	// ����ϵ�ļ�����ʧ��
	#define SYS_HMI_ERR_GUI_INIT_FALSE			(0x0400)	// ����ؼ���ʼ��ʧ��
	#define SYS_HMI_ERR_REG_NO					(0x0800)	// ϵͳδע��

	#define SYS_HMI_ERR_REG_OVER_TIME			(0x1000)	// ϵͳע�ᳬ��
	#define SYS_HMI_ERR_HANDLE_FALSE			(0x2000)	// ���ڳ�ʼ��ʧ��
	#define SYS_HMI_ERR_POS_UPS_FALSE			(0x4000)	// �ϴζϵ��쳣,�����˹��ڵ�λ���ļ�,���ʵ����λ��
	#define SYS_HMI_ERR_POS_FILE_FALSE			(0x8000)	// λ���ļ�����ʧ��,���ʵ����λ��

#define SYS_HMI_ALARM_ERR2			16 // HMI��ر���2��ERR��

#define SYS_THREAD_SYNC_FLAG     17   //�ж���ϵͳ���������ͬ������
#define SYS_ACTIVE_CHAN		18  //ϵͳ�ͨ�����
#define SYS_NO_HEART_CNTS	19  //�޲岹��������

#define SYS_MPG_COUNTS	20	//20~39��ҡ���������ڼ�������
#define SYS_MPG_FLAG	40	//40~49��ҡ�������ı�־�����롿
	#define MPG_FLAG_ACTIVE	0x0100 //��ҡ׼���ñ�־����ҡ�벽������ģʽѡ�񿪹�ʱ��Ч��
	#define MPG_FLAG_VALID	0x0200 //��ҡ��Ч

	#define MPG_FLAG_MUL_MSK 0x000F //��ҡ�������롾���ض�������ҡ��Ч��
	#define MPG_FLAG_AX_MSK	 0x00F0 //��ҡ��ѡ���롾���ض�������ҡ��Ч��

#define SYS_RANDOM_RESTART	41	//һ��ƫ�ò����¼

#define SYS_PLC_STATUS		76	//16bits
	#define PLC_SYS_PLC_ONLINE		0x0001	//PLC���ߵ���
//mark7 trunck�汾ר�ã��ϲ�����ʱ�����˲���
#	define SYS_PLC2_CUR_CYCLE 77	//PLC2��ǰ����16bits
#	define SYS_PLC2_MIN_CYCLE 78	//PLC2��С����16bits
#	define SYS_PLC2_MAX_CYCLE 79	//PLC2�������16bits
//end of mark7
#define SYS_NCKB_FLAG	80 //NC���̵ı�־
#define SYS_HMI_ALARM_MSG	81 // HMI��ر�����MSG��
    #define SYS_HMI_MSG_DISK_FULL		0x0001	//ϵͳ�̿ռ���
	#define SYS_HMI_MSG_REG_WARNING		0x0002	//ע�ᵽ��Ԥ��
	#define SYS_HMI_MSG_LACK_BMP		0x0004	//ϵͳȱ��ͼƬ

#define SYS_NCKB_KEY	82 //82~89,8��NC���̵ļ�ֵ

//#define SYS_SAMPLE_IDX		98	//�����±�
//#define SYS_SAMPLE_LMT		100 //������ֹ���� -1 �źŽ�ֹ��0 ѭ�������� 1~32766������
//#define SYS_SAMPLE_CHN		101 //����ͨ����
//��8λ�������豸�ţ�
//��8λ���������� 1 ָ�� 2 ʵ�� 3 ��� 4 ָ���ٶ� 5 ʵ���ٶ� 6 ���ص���
//#define SYS_SAMPLE_FLAG		102 //102~117 16������ͨ���ı�ǣ�

#define	SYS_SYNC_RDY_IDX	118	//ϵͳ�����������ͬ��������±�[�岹������]
#define SYS_SYNC_OUT_IDX	119	//[λ��/�豸��������]

#define SYS_NCK_VERSION		120 //NCK�汾��
#define SYS_PLC_VERSION		122 //PLC�汾��
#define SYS_DRV_VERSION		124 //DRV�汾�ţ�XX-XX-XX-XX ��-��-��-���
#define SYS_CNC_VERSION		126 //CNC�汾��

#define SYS_LAST_IIP_HEART		128 //�岹�����ݴ�
#define SYS_USER_RIGHT_LEVEL	129 // �û�Ȩ�޵ȼ�
#define SYS_NCK_DEBUG		130

#define SYS_CNC_SAFETY_CNTR	140 // CNC��ȫ������
#define SYS_HEART_BEAT		149 //ϵͳ��������

#define SYS_NC_STATE1   150//ϵͳ״̬��1
    #define SYS_FLAG_MCP_RESET  0x0001
	#define SYS_TOOL_TEST_START	0x0002	//(����������)
	#define SYS_WCS_HOME		0x0004	//(����������)

#define SYS_PRE_INT_VERSION		151	// 151 �岹ǰԤ����汾
#define SYS_NCK_SVN_VERSION		152	// 152~153 NCK�汾��
#define SYS_PLC_SVN_VERSION		154 // 154~155 PLC�汾��
#define SYS_DRV_SVN_VERSION		156 // 156~157 DRV�汾��
#define SYS_CNC_SVN_VERSION		158 // 158~159 CNC�汾��

//ϵͳ���ƼĴ���
#define SYS_NC_CTRL		0 //ϵͳ������
	#define SYS_CTRL_INIT		0x0001
	#define SYS_CTRL_EXIT		0x0002
	#define SYS_CTRL_ESTOP		0x0004 //�ⲿ��ͣ
	#define SYS_CTRL_RESET		0x0008 //�ⲿ��λ
	#define SYS_CTRL_POWEROFF	0x0010 //ͣ��֪ͨ
	#define SYS_CTRL_SAVEDATA	0x0020 //���ݱ���֪ͨ
	#define SYS_CTRL_KEY		0x0040 // MCP����Կ�׿���
	#define SYS_CTRL_SUSPEND	0x0080 //����

	#define SYS_CTRL_DIS_CHLMT	0x0100 //����λԤ��ȡ��
	#define SYS_CTRL_KILL_IIP	0x0200 //ɱ���岹�̡߳��������ڵ��԰汾��
	#define SYS_CTRL_KILL_PLC	0x0400 //ɱ��PLC�̡߳��������ڵ��԰汾��
    #define SYS_CTRL_MCP_RESET	0x0800 //�ⲿ��帴λ

	#define SYS_CTRL_SAMPLE_EN		0x1000 //����ʹ�ܱ��
	#define SYS_CTRL_SAMPLE_TRI_EN	0x2000 //��������ʱ�ܱ��
	#define SYS_CTRL_SMPL_HMI_EN	0x4000 //����ʹ�ܱ��
	#define SYS_CTRL_SMPL_HMI_OFF	0x8000 //�����رձ��

#define SYS_NC_MSK_REQ	1 //ͨ������������

#define BUS_BOARD_CTRL	2 //2~9 Ԥ��8��������վ�Ŀ�����
	#define BUS_CTRL_INIT	0x0001	//��ʼ��
	#define BUS_CTRL_RESET	0x0002	//��λ
	#define BUS_CTRL_PROBE	0x0004	//���
	#define BUS_CTRL_SORT	0x0008	//��ַ
	#define BUS_CTRL_READ	0x0010	//�����ƶ�������
	#define BUS_CTRL_MAP	0x0020	//BUS-NC���ݵ�ַӳ��
	#define BUS_CTRL_DISCONNECT	0x0040	//�Ͽ�����
	#define BUS_CTRL_RUN	0x0080	//����

#define SYS_ACTCHN_REQ	18  //ϵͳ�ͨ������

#define SYS_RIGHTS_KEY	19  // Ȩ��Կ����
#define SYS_MPG_CTRL	20	//20~29��ҡ�Ŀ����֡���һ����ѡ��
#define SYS_MPG_DISPLAY	30	//30~49��ҡ����ʾ���

#define SYS_PLC_ALARM	50 //50~65 PLC�ⲿ������ͬʱ����8*32=256��PLC�ⲿ����
#define SYS_PLC_EVENT	80 //80~95 PLC�ⲿ�¼���ͬʱ����8*32=256��PLC�ⲿ�¼�
#define SYS_PLC_NOTE	96 //96~119 PLC�ⲿ��ʾ��Ϣ��־��ͬʱ����12*32��PLC��ʾ��Ϣ MCͨ��ռ�õĶ����� syserr.h

#define SYS_HEAT_SENSOR 120 //120~139 �¶ȴ�����ֵ 
#define SYS_PROBE_STAMP	140	//140~149 ��ͷʱ���

#define SYS_RFID_RW_CTRL		150 // RFID��д����
		#define RFID_1_RW_ON		0x0001 // 1��RFID��д��ǩ����
		#define RFID_2_RW_ON		0x0002 // 2��RFID��д��ǩ����
		#define RFID_3_RW_ON		0x0004 // 3��RFID��д��ǩ����
		#define RFID_RW_FLAG		0x0010 // RFID��д���
		#define RFID_RW_RESULT		0x0100 // RFID��д���

#define SYS_RFID_RW_TOOL_NO		151 // RFID��д���ߺ�
#define SYS_RFID_RW_CFG1		152 // RFID��д����1(��16λ)
#define SYS_RFID_RW_CFG2		153 // RFID��д����2(��16λ)

#define SYS_STATE_CTRL 154 
	#define IMPACT_DEFEND_STATE		0x0001 // ײ������״̬
	#define MCP_LOCK_ON				0x0002 // MCP�����
//�¶ȴ��������������
#define MAX_HEAT_SENSOR_NUM 20  
//mark8 trunck�汾ר�ã��ϲ�����ʱ�����˲���
//ͨ��������չ�Ĵ���
#define REG_CH_PROG_EXT_RUN		0	//�ӳ������
	#define CH_CTRL_PROG17	0x0001
	#define CH_CTRL_PROG18	0x0002
	#define CH_CTRL_PROG19	0x0004
	#define CH_CTRL_PROG20	0x0008
	#define CH_CTRL_PROG21	0x0010
	#define CH_CTRL_PROG22	0x0020
	#define CH_CTRL_PROG23	0x0040
	#define CH_CTRL_PROG24	0x0080
	#define CH_CTRL_PROG25	0x0100
	#define CH_CTRL_PROG26	0x0200
	#define CH_CTRL_PROG27	0x0400
	#define CH_CTRL_PROG28	0x0800
	#define CH_CTRL_PROG29	0x1000
	#define CH_CTRL_PROG30	0x2000
	#define CH_CTRL_PROG31	0x4000
	#define CH_CTRL_PROG32	0x8000

#define REG_CH_PROG_EXT_RUN1		1	//�ӳ������
	#define CH_CTRL_PROG33	0x0001
	#define CH_CTRL_PROG34	0x0002
	#define CH_CTRL_PROG35	0x0004
	#define CH_CTRL_PROG36	0x0008
	#define CH_CTRL_PROG37	0x0010
	#define CH_CTRL_PROG38	0x0020
	#define CH_CTRL_PROG39	0x0040
	#define CH_CTRL_PROG40	0x0080
	#define CH_CTRL_PROG41	0x0100
	#define CH_CTRL_PROG42	0x0200
	#define CH_CTRL_PROG43	0x0400
	#define CH_CTRL_PROG44	0x0800
	#define CH_CTRL_PROG45	0x1000
	#define CH_CTRL_PROG46	0x2000
	#define CH_CTRL_PROG47	0x4000
	#define CH_CTRL_PROG48	0x8000

#define REG_CH_PROG_EXT_RUN2		2	//�ӳ������
	#define CH_CTRL_PROG49	0x0001
	#define CH_CTRL_PROG50	0x0002
	#define CH_CTRL_PROG51	0x0004
	#define CH_CTRL_PROG52	0x0008
	#define CH_CTRL_PROG53	0x0010
	#define CH_CTRL_PROG54	0x0020
	#define CH_CTRL_PROG55	0x0040
	#define CH_CTRL_PROG56	0x0080
	#define CH_CTRL_PROG57	0x0100
	#define CH_CTRL_PROG58	0x0200
	#define CH_CTRL_PROG59	0x0400
	#define CH_CTRL_PROG60	0x0800
	#define CH_CTRL_PROG61	0x1000
	#define CH_CTRL_PROG62	0x2000
	#define CH_CTRL_PROG63	0x4000
	#define CH_CTRL_PROG64	0x8000
//end of mark8
//5 Device����
enum _DEV_MODE_STATE
{
	DEV_STATE_IDLE,		//����
	DEV_STATE_PROBE,	//����ַ[������˽ṹ]
	DEV_STATE_CONFIG,	//����ģʽ
	DEV_STATE_IDENTIFY,	//��ʶ
	DEV_STATE_UPDATE,	//���²���[�ӿ��ƶ����ж�����]
	DEV_STATE_CHECK,    //�Աȼ�����
	DEV_STATE_READY,	//����
	DEV_STATE_RESET,	//��λ
	DEV_STATE_TEST,		//����
	DEV_STATE_RCONF,	//�ع�
	DEV_STATE_RUN,		//����
	DEV_STATE_FAULT,	//����
	DEV_STATE_EXIT		//�˳�
};

//���������ư����Ͷ���
enum _DEV_NCBRD_TYPE 
{
	DEV_NCBRD_NULL, //0
	DEV_NCBRD_5301,
	DEV_NCBRD_5311A,
	DEV_NCBRD_5311B,
	DEV_NCBRD_5311C,
	DEV_NCBRD_NCUC1, //5
	//�˴���չ�µ�����
	DEV_BRD_TYPE_NUM
};


#define MAX_MPER_ROW 4	//һ���ڵ�M������
#define MAX_POSG_ROW 4  //һ���ڵĴ�������G������
#define MAX_GMDL_NUM 4	//һ���ڵ����ģ̬G��������


//����LINUX �û�̬���������
enum _USER_CALL_ID
{
	USER_NULL_CMD,
	USER_SYS_INIT,	//1
	USER_SYS_EXIT,	//2
	USER_SEL_PROG,	//3
	USER_SKIP_ROW,	//4
	USER_RUN_ROW,	//5
	USER_VERIFY,	//6
	USER_PROG_STOP,
	USER_PROG_RERUN,
	USER_CHAN_RESET,
	USER_SYS_RESET,	
	USER_MDI_OPEN,	
	USER_MDI_DECODE,
	USER_MDI_GOTO_BP,
	USER_MDI_CLOSE,
	USER_BUS_INIT=20,	//20 �����������ߵ���
	USER_BUS_RESET,	//21
	USER_BUS_PROBE,	//22
	USER_BUS_SORT,	//23
	USER_BUS_READ,	//24 ����վ��Ϣ
	USER_BUS_MAP,	//25 BUS-NC���ݵ�ַӳ��
	USER_BUS_DISCONNECT,	//25
	USER_BUS_RUN,	//26
	USER_BUS_START,	//20
	USER_PLC_INIT,	// PLC��ʼ��
	USER_DICT_RESET
};

// G����ģ̬�鶨��
enum 
{
	MODAL_G04_92 = 0,	
	MODAL_G00_03,	// 1
	MODAL_G17_19,	// 2
	MODAL_G24_25,	// 3
	MODAL_G50_51,	// 4
	MODAL_G68_69,	// 5
	MODAL_G71_82,	// 6
	MODAL_G11_12,	// 7
	MODAL_G20_22,	// 8
	MODAL_G41_42,	// 9
	MODAL_G43_44,	// 10
	MODAL_G54_59,	// 11
	MODAL_G61_64,	// 12
	MODAL_G90_91,	// 13
	MODAL_G94_95,	// 14
	MODAL_G98_99,	// 15
	MODAL_G15_16,	// 16 ��������
	MODAL_G36_37,	// 17 
	MODAL_G12_13,	// 18 ������岹
	MODAL_G96_97,	// 19
	MODAL_G38_39,	// 20 ͬ����־����
	MODAL_G38_39_,	// 20 ͬ����־����2
	MODAL_G66_67,	// 22 ģ̬���� ?
	MODAL_G125_126, // 23 ˫�뷽ʽ����
	MODAL_G135_136, // 24 ��б����������ϵ���
	MODAL_G140_143,	// 25 ����岹����
	MODAL_G128_129,	// 26 �����˱任������ر�
	MODAL_G05P1_Q,  //G05.1Q��ֵ
	MODAL_G97_FLAG,   //G97��״̬
	MODAL_G71_G73_FLAG,//G71-G73���õı��
	
	TWIN_MDL_SPL = 60,	//���ļ�ģ̬-����

	FLAG_G15_16 = 70,	// �������̱�ʶ��
	FLAG_G71_82,		// �̶�ѭ���л���ʶ��
	FLAG_H_IDX,			// ���Ȳ����Ĵ������
	FLAG_D_IDX,			// �뾶�����Ĵ������
	FLAG_T_OFF,			// ģ̬��ƫ��
	FLAG_INDEX_AX_MASK, //��¼��״̬
	FLAG_CS,           //��¼C/S�л��ᣬ����������
	FLAG_CYC_TYPE,     //��¼�̶�ѭ������
	FLAG_SYN_SPDL,     //��¼ͬ��������Ϣ
	FLAG_G12_13_PLANE,  //��¼G12�ļӹ�ƽ��
	MAX_GGRP_NUM = 80	// ģָ̬��������Simens�ǽ�60��
};

#define A_CS_MASK 0X100
#define B_CS_MASK 0X80
#define C_CS_MASK 0X40

// #define DEFALUT_G04_92  	
#define DEFALUT_G00_03 1
// #define DEFALUT_G17_19 //���ݻ�������
#define DEFALUT_G24_25 25
#define DEFALUT_G50_51 50
#define DEFALUT_G68_69 69
// #define DEFALUT_G71_82 //���ݻ�������
// #define DEFALUT_G11_12 
#define DEFALUT_G20_22 21
#define DEFALUT_G41_42 40
#define DEFALUT_G43_44 49
#define DEFALUT_G54_59 54
// #define DEFALUT_G61_64 //���ݻ�������
#define DEFALUT_G90_91 90
#define DEFALUT_G94_95 94
#define DEFALUT_G98_99 98
#define DEFALUT_G15_16 15
// #define DEFALUT_G36_37 //���ݻ�������
#define DEFALUT_G12_13 13
#define DEFALUT_G96_97 97
// #define DEFALUT_G38_39 
// #define DEFALUT_G38_39_
// #define DEFALUT_G66_67
#define DEFALUT_G125_126 126
#define DEFALUT_G135_136 136
// #define DEFALUT_G140_143
#define DEFALUT_G128_129 129
#define DEFALUT_G05P1_Q 0
#define MAX_IDLE_SCAN_ROW_NUM 100

enum 
{
	FAST_VERIFY_NONE,
	FAST_VERIFY_START,
	FAST_VERIFY_WORKING,
	FAST_VERIFY_NO_CC_START,
	FAST_VERIFY_NO_CC_WORKING,
};
#endif
