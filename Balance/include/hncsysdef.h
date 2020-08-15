/*! 
 * @file hncsysdef.h
 * @brief ϵͳ��������
 * @version V1.00
 * @date 2017/01/10
 * @author HNC-8 Team
 * @copyright �人�������عɷ����޹�˾���������
 */


#ifndef __HNC_SYS_DEF_H__
#define __HNC_SYS_DEF_H__

#include "hncdatatype.h"

/*! 
 * @name ϵͳ��������
	Get(Bit32)��ʾGet����ʱvoid *ΪBit32 \n
	Set(NULL)��ʾ����ΪNULL�Ŀ�������
 * @{
 */
enum HncSystem
{
	HNC_SYS_CHAN_NUM = 0,		/*!<  ��ȡϵͳͨ���� {Get(Bit32)} */
	HNC_SYS_MOVE_UNIT,			/*!<  ���ȷֱ��� {Get(Bit32)} */
	HNC_SYS_TURN_UNIT,			/*!<  �Ƕȷֱ��� {Get(Bit32)} */
	HNC_SYS_METRIC_DISP,		/*!<  ��Ӣ�� {Get(Bit32)} */
	HNC_SYS_SHOW_TIME,			/*!<  �Ƿ���ʾʱ�� {Get(Bit32)} */
	HNC_SYS_POP_ALARM,			/*!<  �����Զ���ʾ {Get(Bit32)} */
	HNC_SYS_GRAPH_ERASE,		/*!<  ͼ���Զ����� {Get(Bit32)} */
	HNC_SYS_MAC_TYPE,			/*!<  �������� */
	HNC_SYS_PREC,				/*!<  ����ϵ���� {Get(Bit32)} */
	HNC_SYS_F_PREC,				/*!<  F���� {Get(Bit32)} */
	HNC_SYS_S_PREC,				/*!<  S���� {Get(Bit32)} */
	HNC_SYS_NCK_VER,			/*!<  NCK�汾 {Get(Bit8[32])} */
	HNC_SYS_DRV_VER,			/*!<  DRV�汾 {Get(Bit8[32])} */
	HNC_SYS_PLC_VER,			/*!<  PLC�汾 {Get(Bit8[32])} */
	HNC_SYS_CNC_VER,			/*!<  CNC�汾 {Get(Bit32) Set(Bit32)} */
	HNC_SYS_MCP_KEY,			/*!<  MCP���Կ�׿��� {Get(Bit32)} */
	HNC_SYS_ACTIVE_CHAN,		/*!<  �ͨ�� {Get(Bit32) Set(Bit32)} */
	HNC_SYS_REQUEST_CHAN,		/*!<  ����ͨ�� {Get(Bit32)} */
	HNC_SYS_MDI_CHAN,			/*!<  MDI����ͨ�� {Get(Bit32)} */
	HNC_SYS_REQUEST_CHAN_MASK,	/*!<  �����ͨ�������� {Get(Bit32)} */
	HNC_SYS_CHAN_MASK,			/*!<  ͨ�������� {Set(Bit32)} */
	HNC_SYS_PLC_STOP,			/*!<  plcֹͣ {Set(NULL)} */
	HNC_SYS_POWEROFF_ACT,		/*!<  �ϵ�Ӧ�� {Set(NULL)} */
	HNC_SYS_IS_HOLD_REDECODE,	/*!<  �������ֺ��Ƿ����½��� {Get(Bit32)} */
	HNC_SYS_NC_VER,             /*!<  NC�汾 {Get(Bit8[32])} */
	HNC_SYS_SN_NUM,             /*!<  ����װ��SN�� {Get(Bit8[32])} */
	HNC_SYS_MACHINE_TYPE,		/*!< �����ͺ� {Get(Bit8[48]) Set(Bit8[48])} */
	HNC_SYS_MACHINE_INFO,		/*!< ������Ϣ {Get(Bit8[48]) Set(Bit8[48])} */
	HNC_SYS_MACFAC_INFO,		/*!< ��������Ϣ {Get(Bit8[48]) Set(Bit8[48])} */
	HNC_SYS_USER_INFO,			/*!< �û���Ϣ {Get(Bit8[48]) Set(Bit8[48])} */
	HNC_SYS_MACHINE_NUM,		/*!< ������� {Get(Bit8[48]) Set(Bit8[48])} */
	HNC_SYS_EXFACTORY_DATE,     /*!< ����ʱ�� {Get(Bit8[32])} */
	HNC_SYS_ACCESS_LEVEL,		/*!< Ȩ�޵ȼ� {Get(Bit32)} */
	HNC_SYS_MUL_CHAN_RESET,		/*!<  ��ͨ����λ����������� {Set(Bit32)[0/1]} */
	HNC_SYS_RIGHTS_KEY,			/*!<  Ȩ��Կ���� {Get(Bit32)} */
	HNC_SYS_REG_DAYS_REMANING,	/*!< ע��ʣ������ {Get(Bit32)} */
	HNC_SYS_PLC2_CUR_CYCLE,		/*!< PLC2��ǰ�������� {Get(Bit32)} */
	HNC_SYS_PLC2_MIN_CYCLE,		/*!< PLC2��С�������� {Get(Bit32)} */
	HNC_SYS_PLC2_MAX_CYCLE,		/*!< PLC2����������� {Get(Bit32)} */
	HNC_SYS_PLC_ONLINE,			/*!< PLC���ߵ��� {Get(Bit8[48]) Set(Bit8[48])} */
	HNC_SYS_TOTAL
};
/*!@}*/ 

#define MAX_SYS_STR_LEN		(64)

#endif //  __HNC_SYS_H__