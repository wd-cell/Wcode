/*! 
 * @file hncchandef.h
 * @brief ͨ����������
 * @version V1.00
 * @date 2017/01/10
 * @author HNC-8 Team
 * @copyright �人�������عɷ����޹�˾���������
 */


#ifndef __HNC_CHANNEL_DEF_H__
#define __HNC_CHANNEL_DEF_H__

#include "hncdatatype.h"

/*! ͨ���������� \n
 Get(Bit32)��ʾGet����ʱvoid *ΪBit32 \n
 Set(NULL)��ʾ����ΪNULL�Ŀ������� */
enum HncChannel
{
	HNC_CHAN_IS_EXIST = 0,		/*!< ͨ���Ƿ���� {Get(Bit32)} */
	HNC_CHAN_MAC_TYPE,			/*!< ͨ���Ļ������� {Get(Bit32)} */
	HNC_CHAN_AXES_MASK,			/*!< ������ {Get(Bit32)} */
	HNC_CHAN_AXES_MASK1,		/*!< ������1 {Get(Bit32)} */
	HNC_CHAN_NAME,				/*!< ͨ���� {Get(Bit8[PARAM_STR_LEN])} */
	HNC_CHAN_CMD_TYPE,			/*!< ��ȡ��ǰG����ı�־ {Get(Bit32)} */
	HNC_CHAN_CMD_FEEDRATE,		/*!< ָ������ٶ� {Get(fBit64)} */
	HNC_CHAN_ACT_FEEDRATE,		/*!< ʵ�ʽ����ٶ� {Get(fBit64)} */
	HNC_CHAN_PROG_FEEDRATE,		/*!< ���ָ���ٶ� {Get(fBit64)} */
	HNC_CHAN_FEED_OVERRIDE,		/*!< �����޵� {Get(Bit32)} */
	HNC_CHAN_RAPID_OVERRIDE,	/*!< �����޵� {Get(Bit32)} */
	HNC_CHAN_MCODE,             /*!< ͨ����Mָ�� {Get(Bit32)} */
	HNC_CHAN_TCODE,				/*!< ͨ����Tָ�� {Get(Bit32)} */
	HNC_CHAN_TOFFS,				/*!< ͨ���еĵ�ƫ�� {Get(Bit32)} */
	HNC_CHAN_TOOL_USE,			/*!< ��ǰ���� {Get(Bit32)} */
	HNC_CHAN_TOOL_RDY,			/*!< ׼���ý����ĵ��� {Get(Bit32)} */
	HNC_CHAN_MODE,				/*!< ģʽ(����ֵ���ݶ��������) {Get(Bit32)} */
	HNC_CHAN_IS_MDI,			/*!< MDI {Get(Bit32)} */
	HNC_CHAN_CYCLE,				/*!< ѭ������ {Get(Bit32), Set(NULL)} */
	HNC_CHAN_HOLD,				/*!< �������� {Get(Bit32), Set(NULL)} */
	HNC_CHAN_IS_PROGSEL,		/*!< ��ѡ���� {Get(Bit32)} */
	HNC_CHAN_IS_PROGEND,		/*!< ����������� {Get(Bit32)} */
	HNC_CHAN_IS_THREADING,		/*!< ���Ƽӹ� {Get(Bit32)} */
	HNC_CHAN_IS_RIGID,			/*!< ���Թ�˿ {Get(Bit32)} */
	HNC_CHAN_IS_REWINDED,		/*!< �����и�λ״̬ {Get(Bit32)} */
	HNC_CHAN_IS_ESTOP,			/*!< ��ͣ {Get(Bit32)} */
	HNC_CHAN_IS_RESETTING,		/*!< ��λ {Get(Bit32)} */
	HNC_CHAN_IS_RUNNING,		/*!< ������ {Get(Bit32)} */
	HNC_CHAN_IS_HOMING,			/*!< ������ {Get(Bit32)} */
	HNC_CHAN_IS_MOVING,			/*!< ���ƶ��� {Get(Bit32)} */
	HNC_CHAN_DIAMETER,			/*!< ֱ�뾶��� {Get(Bit32)} */
	HNC_CHAN_VERIFY,			/*!< У�� {Get(Bit32), Set(Bit32)} */
	HNC_CHAN_RUN_ROW,			/*!< ������ {Get(Bit32)} */
	HNC_CHAN_DCD_ROW,			/*!< ������ {Get(Bit32)} */
	HNC_CHAN_SEL_PROG,			/*!< ѡ�����ı�� {Get(Bit32)} */
	HNC_CHAN_RUN_PROG,			/*!< ���г���ı�� {Get(Bit32)} */
	HNC_CHAN_PART_CNTR,			/*!< �ӹ����� {Get(Bit32), Set(Bit32)} */
	HNC_CHAN_PART_STATI,		/*!< �������� {Get(Bit32), Set(Bit32)} */
	HNC_CHAN_HMI_RESET,			/*!< HMI��λ {Set(NULL)} */
	HNC_CHAN_CHG_PROG,			/*!< �����޸ı�־ {Set(NULL)} */
	HNC_CHAN_PERIOD_TOTAL,		/*!< ��ʱ�� */
	HNC_CHAN_LAX,				/*!< ͨ�����Ӧ���߼���� {Get(Bit32)} */
	HNC_CHAN_AXIS_NAME,			/*!< ������� {Get(Bit8[PARAM_STR_LEN])} */
	HNC_CHAN_SPDL_NAME,			/*!< ��������� {Get(Bit8[PARAM_STR_LEN])} */
	HNC_CHAN_MODAL,				/*!< ͨ��ģ̬ ��80�� {Get(Bit32)} */
	HNC_CHAN_SPDL_LAX,			/*!< ͨ�������Ӧ���߼���ţ���̬ {Get(Bit32)} */
	HNC_CHAN_SPDL_PARA_LAX,		/*!< ͨ�������Ӧ���߼���ţ���̬ {Get(Bit32)} */
	HNC_CHAN_CMD_SPDL_SPEED,	/*!< ����ָ���ٶ� {Get(fBit64)} */
	HNC_CHAN_ACT_SPDL_SPEED,	/*!< ����ʵ���ٶ� {Get(fBit64)} */
	HNC_CHAN_SPDL_OVERRIDE,		/*!< �����޵� {Get(Bit32)} */
	HNC_CHAN_DO_HOLD,			/*!< ���ý�������  */
	HNC_CHAN_BP_POS,			/*!< �ϵ�λ�� {Get(Bit32)} */
	HNC_CHAN_PROG_FLOW,			/*!< ���ڵ����ֶ��ӳ��� {Get(Bit32)} */
	HNC_CHAN_H_OFF,				/*!< ��ǰʹ�õ��߳��Ȳ����� {Get(Bit32)} */
	HNC_CHAN_D_OFF,				/*!< ��ǰʹ�õ��߰뾶������ {Get(Bit32)} */
	HNC_CHAN_BP_POS_EX,
	HNC_CHAN_IS_SBL,			/*!< �Ƿ񵥶�ģʽ {Get(Bit32)} */
	HNC_CHAN_PART_NEED,			/*!< �ӹ������� {Get(Bit32), Set(Bit32)} */
	HNC_CHAN_TOTAL
};

/*! 
 * @name HNC_CHAN_MODE���ܷ���ֵ
 * @{
 */
#define	CHAN_MODE_RESET	(0)
#define	CHAN_MODE_AUTO	(1)
#define	CHAN_MODE_JOG	(2)
#define	CHAN_MODE_STEP	(3)
#define	CHAN_MODE_MPG	(4)
#define	CHAN_MODE_HOME	(5)
#define	CHAN_MODE_PMC	(6)
#ifdef _MCPMDI // MCP����л�MDI��ʽ
#define CHAN_MODE_MDI	(7)
#else
#define CHAN_MODE_SBL	(7)
#endif
/*!@}*/ 

#endif