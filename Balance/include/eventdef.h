/*! 
 * @file eventdef.h
 * @brief ϵͳ�¼�����
 * @version V1.00
 * @date 2017/01/03
 * @author HNC-8 Team
 * @copyright �人�������عɷ����޹�˾���������
 */

#ifndef __EVENT_DEF_H__
#define __EVENT_DEF_H__

#include "hncdatatype.h"

#define MAX_EVENT_NUM 512
#define MAX_RESERVE_DATA_LEN	128

typedef struct _EventElement
{
    Bit16 src;	  /*!< �¼���Դ */
    uBit16 code;  /*!< �¼����� */
	Bit8 buf[MAX_RESERVE_DATA_LEN];
} SEventElement;

typedef struct _MSTInfo
{
	Bit16 num;
	Bit32 line;
}mstinfo;

#define _hncevent_get_size() sizeof(SEventElement)*(MAX_EVENT_NUM+8)


/*! 
 * @name һ. �����¼���Դ
 * @{
 */
/*! ϵͳ�¼� */ 
#define	EV_SRC_SYS	0x010

/*! ͨ��0�¼� 0x100~0x10f */
#define	EV_SRC_CH0	0x100

/*! MDI���¼� */
#define	EV_SRC_MDI	0x110

/*! �����¼� */
#define EV_SRC_KBD	0x200

/*! ���¼� */
#define EV_SRC_AX0	0x300

/*! �����¼� */
#define EV_SRC_NET	0x400
/*!@}*/

/*! 
 * @name  ��. �����¼�����
 * @verbatim
   1. ������̴���
         0x   0   009
             ---  ---
        ���  |    |  ����
    ------------  --------------
     0�������飬��׼ASCII�룬Ŀǰ�������࣬1���ַ�����0x00yy
                                           2�����ܼ�, 0x01yy
     1��ctrl�飬��ϼ�=0x1000+����ֵ
     2��alt�飬��ϼ�=0x2000+����ֵ
     3��shift�飬��ϼ�=0x3000+����ֵ
     7������
     �ݲ�����������ϼ�
   @endverbatim
 * @{
 */										
#define kbNoKey		0x0000

/*! 
 * @name 1.1 00---�ַ�������׼ASCA�붨�壺'A'~'Z','0'~'9','*','!'.....
 * @{
 */
#define kbSpace		0x0020
#define kbBack      0x0008
#define kbTab		0x0009
#define kbEnter		0x000d

/*!@}*/
/*! 
 * @name 1.2 01---���ܼ�
 * @{
 */
#define kbShift		0x0110
#define kbCtrl		0x0111
#define kbAlt		0x0112
#define kbPause		0x0113
#define kbCapsLk	0x0114
#define kbEsc       0x011b

#define kbPgUp      0x0121
#define kbPgDn      0x0122
#define kbEnd       0x0123
#define kbHome      0x0124
#define kbLeft      0x0125
#define kbUp        0x0126
#define kbRight     0x0127
#define kbDown      0x0128
#define kbIns       0x012d
#define kbDel       0x012e

#define kbF1        0x0170
#define kbF2        0x0171
#define kbF3        0x0172
#define kbF4        0x0173
#define kbF5        0x0174
#define kbF6        0x0175
#define kbF7        0x0176
#define kbF8        0x0177
#define kbF9        0x0178
#define kbF10       0x0179
#define kbF11       0x017a
#define kbF12       0x017b
/*!@}*/

/*! 
 * @name 1.3 ctrl��ϼ�
 * @{
 */
#define CtrlBase	0x1000

#define	kbCtrlA		(CtrlBase+'A')
#define kbCtrlB     (CtrlBase+'B')
#define kbCtrlC     (CtrlBase+'C')
#define kbCtrlD     (CtrlBase+'D')
#define kbCtrlE     (CtrlBase+'E')
#define kbCtrlF     (CtrlBase+'F')
#define kbCtrlG     (CtrlBase+'G')
#define kbCtrlH     (CtrlBase+'H')
#define kbCtrlI     (CtrlBase+'I')
#define kbCtrlJ     (CtrlBase+'J')
#define kbCtrlK     (CtrlBase+'K')
#define kbCtrlL     (CtrlBase+'L')
#define kbCtrlM     (CtrlBase+'M')
#define kbCtrlN     (CtrlBase+'N')
#define kbCtrlO     (CtrlBase+'O')
#define kbCtrlP     (CtrlBase+'P')
#define kbCtrlQ     (CtrlBase+'Q')
#define kbCtrlR     (CtrlBase+'R')
#define kbCtrlS     (CtrlBase+'S')
#define kbCtrlT     (CtrlBase+'T')
#define kbCtrlU     (CtrlBase+'U')
#define kbCtrlV     (CtrlBase+'V')
#define kbCtrlW     (CtrlBase+'W')
#define kbCtrlX     (CtrlBase+'X')
#define kbCtrlY     (CtrlBase+'Y')
#define kbCtrlZ     (CtrlBase+'Z')

#define kbCtrlF1    (CtrlBase+kbF1)
#define kbCtrlF2    (CtrlBase+kbF2)
#define kbCtrlF3    (CtrlBase+kbF3)
#define kbCtrlF4    (CtrlBase+kbF4)
#define kbCtrlF5    (CtrlBase+kbF5)
#define kbCtrlF6    (CtrlBase+kbF6)
#define kbCtrlF7    (CtrlBase+kbF7)
#define kbCtrlF8    (CtrlBase+kbF8)
#define kbCtrlF9    (CtrlBase+kbF9)
#define kbCtrlF10   (CtrlBase+kbF10)
#define kbCtrlF11   (CtrlBase+kbF11)
#define kbCtrlF12   (CtrlBase+kbF12)

#define kbCtrlSpace	(CtrlBase+kbSpace)
#define kbCtrlPgUp  (CtrlBase+kbPgUp)
#define kbCtrlPgDn  (CtrlBase+kbPgDn)
#define kbCtrlEnd   (CtrlBase+kbEnd)
#define kbCtrlHome  (CtrlBase+kbHome)
#define kbCtrlLeft  (CtrlBase+kbLeft)
#define kbCtrlUp    (CtrlBase+kbUp)
#define kbCtrlRight (CtrlBase+kbRight)
#define kbCtrlDown  (CtrlBase+kbDown)
#define kbCtrlIns   (CtrlBase+kbIns)
#define kbCtrlDel   (CtrlBase+kbDel)

#define kbCtrlBack  (CtrlBase+kbBack)
#define kbCtrlEnter (CtrlBase+kbEnter)
/*!@}*/

/*! 
 * @name 1.4 alt��ϼ�
 * @{
 */
#define AltBase		0x2000

#define kbAltSpace  (AltBase+kbSpace)

#define kbAltA      (AltBase+'A')
#define kbAltB      (AltBase+'B')
#define kbAltC      (AltBase+'C')
#define kbAltD      (AltBase+'D')
#define kbAltE      (AltBase+'E')
#define kbAltF      (AltBase+'F')
#define kbAltG      (AltBase+'G')
#define kbAltH      (AltBase+'H')
#define kbAltI      (AltBase+'I')
#define kbAltJ      (AltBase+'J')
#define kbAltK      (AltBase+'K')
#define kbAltL      (AltBase+'L')
#define kbAltM      (AltBase+'M')
#define kbAltN      (AltBase+'N')
#define kbAltO      (AltBase+'O')
#define kbAltP      (AltBase+'P')
#define kbAltQ      (AltBase+'Q')
#define kbAltR      (AltBase+'R')
#define kbAltS      (AltBase+'S')
#define kbAltT      (AltBase+'T')
#define kbAltU      (AltBase+'U')
#define kbAltV      (AltBase+'V')
#define kbAltW      (AltBase+'W')
#define kbAltX      (AltBase+'X')
#define kbAltY      (AltBase+'Y')
#define kbAltZ      (AltBase+'Z')

#define kbAlt1      (AltBase+'1')
#define kbAlt2      (AltBase+'2')
#define kbAlt3      (AltBase+'3')
#define kbAlt4      (AltBase+'4')
#define kbAlt5      (AltBase+'5')
#define kbAlt6      (AltBase+'6')
#define kbAlt7      (AltBase+'7')
#define kbAlt8      (AltBase+'8')
#define kbAlt9      (AltBase+'9')
#define kbAlt0      (AltBase+'0')

#define kbAltF1     (AltBase+kbF1)
#define kbAltF2     (AltBase+kbF2)
#define kbAltF3     (AltBase+kbF3)
#define kbAltF4     (AltBase+kbF4)
#define kbAltF5     (AltBase+kbF5)
#define kbAltF6     (AltBase+kbF6)
#define kbAltF7     (AltBase+kbF7)
#define kbAltF8     (AltBase+kbF8)
#define kbAltF9     (AltBase+kbF9)
#define kbAltF10    (AltBase+kbF10)
#define kbAltF11    (AltBase+kbF11)
#define kbAltF12    (AltBase+kbF12)

#define kbAltMinus  (AltBase+'-')
#define kbAltEqual  (AltBase+'=')

#define kbAltUp		(AltBase+kbUp)
#define kbAltDown	(AltBase+kbDown)
#define kbAltLeft	(AltBase+kbLeft)
#define kbAltRight	(AltBase+kbRight)	
/*! @} */	

/*! 
 * @name 1.5 shift��ϼ�
 * @{
 */
#define ShiftBase	0x3000

#define kbShiftF1   (ShiftBase+kbF1)
#define kbShiftF2   (ShiftBase+kbF2)
#define kbShiftF3   (ShiftBase+kbF3)
#define kbShiftF4   (ShiftBase+kbF4)
#define kbShiftF5   (ShiftBase+kbF5)
#define kbShiftF6   (ShiftBase+kbF6)
#define kbShiftF7   (ShiftBase+kbF7)
#define kbShiftF8   (ShiftBase+kbF8)
#define kbShiftF9   (ShiftBase+kbF9)
#define kbShiftF10  (ShiftBase+kbF10)
#define kbShiftF11  (ShiftBase+kbF11)
#define kbShiftF12  (ShiftBase+kbF12)

#define kbShiftIns  (ShiftBase+kbIns)
#define kbShiftDel  (ShiftBase+kbDel)
#define kbShiftTab  (ShiftBase+kbTab)
/*! @} */

#define kbIdle		(0x7fff)
/*! ֻҪϵͳ��ѯ�¼�����������ִ�� */
#define kbRealRe	(0x7ffe)

#define kbReset		kbCtrlZ 
/*! �ڶ����ؼ� */	
#define kbReturn	kbF11
/*! @} */

/*! 
 * @name 2. ����ͨ���¼�
 * @{
 */
/*! ��������*/
#define	ncEvtPrgStart	0xa001	
/*! �������*/
#define ncEvtPrgEnd		0xa002	
/*! Hold���*/
#define	ncEvtPrgHold	0xa003		
/*! break���*/	
#define	ncEvtPrgBreak	0xa004	
/*! G92���*/
#define	ncEvtG92Fin		0xa005	
/*! �ϵ縴λ���*/
#define	ncEvtRstFin		0xa006	
/*! ���������*/
#define	ncEvtRwndFin	0xa007	
/*! MDI׼����*/
#define ncEvtMdiRdy		0xa008	
/*! MDI�˳�*/
#define	ncEvtMdiExit	0xa009	
/*! MDI�н������*/
#define	ncEvtMdiAck		0xa00a	
/*! ��������*/
#define	ncEvtRunStart	0xa00b	

/*! ����������Ӧ��*/
#define	ncEvtRunRowAck	0xa00d	
/*! ������׼����*/
#define	ncEvtRunRowRdy	0xa00e	

/*! �ϵ㱣�����*/
#define ncEvtBpSaved	0xa011	
/*! �ϵ�ָ����*/
#define ncEvtBpResumed	0xa012	
/*! ִ�е�M92�ȴ��û���Ԥ*/
#define ncEvtIntvHold	0xa013	
/*! �ⲿ��ͣ*/
#define	ncEvtEstop		0xa014	
/*! ����������*/
#define	ncEvtLoadOK		0xa015	

/*! ��һ���﷨���޸ĺ�ɽ������С�*/
#define	ncEvtSyntax1	0xa016	
/*! �ڶ����﷨���޸ĺ��ͷ���С�*/
#define	ncEvtSyntax2	0xa017	

/*! �����е����ݱ���ָ��*/
#define	ncEvtGcodeSave	0xa018	
/*! �����е����ݼ���ָ��*/
#define ncEvtLoadData	0xa019	
/*! G�����޸��˵�������*/
#define ncEvtChgTool	0xa01a	
/*! G�����޸�������ϵ����*/
#define ncEvtChgCrds	0xa01b	
/*! ͨ�����鷢���˸ı�*/
#define ncEvtChgAxes	0xa01c	
/*! G�����޸ı���*/
#define ncEvtChgVar	    0xa01d	
/*!G�����޸Ĳ���*/
#define ncEvtChgParm    0xa022  

/*! ͨ����ʾ*/
#define ncEvtNckNote	0xa01e	
/*! ͨ������*/
#define ncEvtNckAlarm	0xa01f	
/*! sys_stop_prog���*/
#define ncEvtStopAck	0xa020	
/*! G�����޸�ʱ�����*/
#define ncEvtChgTimeVar	0xa021	

#define ncEvtVerifyFinish 0xa023
#define ncEvtFastVerifyFinish 0xa024
// #define ncEvtMcode      0xa021
// #define ncEvtS0code     0xa022
// #define ncEvtS1code     0xa023
// #define ncEvtS2code     0xa024
// #define ncEvtS3code     0xa025
// #define ncEvtTcode      0xa026
/*!������ɨ�����*/
#define ncEvtRandomRowFinish      0xa027 

//#define ncEVtRandomRowRunFinish   0xa028 //������ִ�����
/*!������ɨ��ģʽ������������׼���ó���*/
#define ncEVtRandomRowRequestProg 0xa029 
/*! �����ж�*/
#define ncEvtFaultIrq	0xa030	
/*! ���ݴ�����*/
#define ncEvtPackFin	0xa040	

/*! ��������������*/
#define ncEvtAlarmChg	0xa055	
/*! �ļ��޸�*/
#define ncEvtFileChg	0xa056	

/*! nc����*/
#define ncEvtConnect	0xa060	
/*! nc�Ͽ�����*/
#define ncEvtDisConnect	0xa061	
/*! �����ļ����*/
#define ncEvtFileSend	0xa062	
/*!@}*/


/*! 
 * @name 3. �������¼�
 * @{
 */
/*! ���������ʼλ�ù���*/
#define ncEvtMaxEncPos	0xa201	
/*! ����ٶȹ���*/
#define ncEvtMaxACC 	0xa202	
/*!@}*/

/*! 
 * @name 4. ����ϵͳ�¼�
 * @{
 */
/*! ϵͳ�ϵ�*/
#define ncEvtPoweroff	0xa800	
/*! ����ϵͳ����*/
#define ncEvtSaveData	0xa801	
/*! ϵͳ�˳�*/
#define ncEvtSysExit	0xa802	

/*! �û��Զ����¼� ����100��*/
#define ncEvtUserStart	0xb000	

/*! Ӳ��λ���*/
#define ncEvtHardRstFin	(ncEvtUserStart+102)	
/*! ����B�Ĵ���*/
#define ncEvtSaveRegB	(ncEvtUserStart+103)	
/*! �����л�ͨ��*/
#define ncEvtUserReqChn	(ncEvtUserStart+104)	
/*! ��������ͨ��*/
#define ncEvtUserReqMsk	(ncEvtUserStart+105)
/*! �û�����PLC�¼�(DMTGʹ��) */
#define ncEvtReserve0   (ncEvtUserStart+106)
/*! �û�����PLC�¼�(DMTGʹ��) */
#define ncEvtReserve1   (ncEvtUserStart+107)
/*! �û�����PLC�¼�(DMTGʹ��) */
#define ncEvtReserve2   (ncEvtUserStart+108)
/*! �û�����PLC�¼�(DMTGʹ��) */
#define ncEvtReserve3   (ncEvtUserStart+109)
/*! ��ʱ�޸�����ƫ��(G54���뵶ƫ) */
#define ncEvtChOffset	(ncEvtUserStart+110)

/*! PLC֪ͨNC�嵥������ʱ�� */
#define ncEvtCleanCurTime	(ncEvtUserStart+111)

/*! ����ѭ������*/
#define ncEvtCycPress   (ncEvtUserStart+112) // �Զ���ѭ�����������¼�

/*! PLC�����ĸ�λ(PLC�������¼��������Reset����) */
#define ncEvtResetPlcKey	(ncEvtUserStart+115)

/*! ������VAR_BLK_LOAD_PROG_NOָ���ĳ���� */
#define ncEvtLoadPrg	(ncEvtUserStart+116)

/*! �����С��������� */
#define ncEvtProgRestart	(ncEvtUserStart+117)

/*! �Զ��Ե���ɡ��������� */
#define ncEvtToolProgFlowEnd	(ncEvtUserStart+118)

/*! ��mcp�������� */
#define ncEvtMcpPress	(ncEvtUserStart+119)

/*! ��λ��Ϣ(��ͨ��ʱ��PLCѡ���긴λ��ͨ�����͵��¼�) */
#define ncEvtRstMsg		(ncEvtUserStart+120)

/*! Կ�����л�Ȩ����Ϣ */
#define ncEvtRigChg		(ncEvtUserStart+121)

/*! RFID�����ӱ�ǩ���ݵ�CNC */
#define ncEvtRfidReadTag	(ncEvtUserStart+122)
/*! RFIDдCNC���ݵ����ӱ�ǩ */
#define ncEvtRfidWriteTag	(ncEvtUserStart+123)

/*! ͨ��0������� */
#define ncEvtToolChangeFin0	(ncEvtUserStart+124)
/*! ͨ��1������� */
#define ncEvtToolChangeFin1	(ncEvtUserStart+125)
/*! ͨ��2������� */
#define ncEvtToolChangeFin2	(ncEvtUserStart+126)
/*! ͨ��3������� */
#define ncEvtToolChangeFin3	(ncEvtUserStart+127)


/*! �����¼�*/
#define ncEvtNetStart	0xc000	

#define ncEvtPutMessage	(ncEvtNetStart)
#define ncEvtSmplStop	(ncEvtNetStart + 1)
#define ncEvtParmModify	(ncEvtNetStart + 2)
#define ncEvtToolModify	(ncEvtNetStart + 3)
#define ncEvtProgIdTabModify (ncEvtNetStart + 4)
/*!@}*/
/*!@}*/

/*!�����¼��ṹ����*/
typedef struct _SExtraEventParmModify
{
	Bit32 id;
	Bit32 retVal;
	Bit8 value[8];
}SExtraEventParmModify;

typedef struct _SExtraEventToolModify
{
	Bit32 no;
	Bit32 off;
	Bit32 retVal;
	Bit8 value[8];
}SExtraEventToolModify;


#endif // __EVENT_DEF_H__
