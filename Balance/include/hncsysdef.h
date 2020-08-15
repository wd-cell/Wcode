/*! 
 * @file hncsysdef.h
 * @brief 系统数据类型
 * @version V1.00
 * @date 2017/01/10
 * @author HNC-8 Team
 * @copyright 武汉华中数控股份有限公司软件开发部
 */


#ifndef __HNC_SYS_DEF_H__
#define __HNC_SYS_DEF_H__

#include "hncdatatype.h"

/*! 
 * @name 系统数据类型
	Get(Bit32)表示Get数据时void *为Bit32 \n
	Set(NULL)表示参数为NULL的控制命令
 * @{
 */
enum HncSystem
{
	HNC_SYS_CHAN_NUM = 0,		/*!<  获取系统通道数 {Get(Bit32)} */
	HNC_SYS_MOVE_UNIT,			/*!<  长度分辨率 {Get(Bit32)} */
	HNC_SYS_TURN_UNIT,			/*!<  角度分辨率 {Get(Bit32)} */
	HNC_SYS_METRIC_DISP,		/*!<  公英制 {Get(Bit32)} */
	HNC_SYS_SHOW_TIME,			/*!<  是否显示时间 {Get(Bit32)} */
	HNC_SYS_POP_ALARM,			/*!<  报警自动显示 {Get(Bit32)} */
	HNC_SYS_GRAPH_ERASE,		/*!<  图形自动擦除 {Get(Bit32)} */
	HNC_SYS_MAC_TYPE,			/*!<  机床类型 */
	HNC_SYS_PREC,				/*!<  坐标系精度 {Get(Bit32)} */
	HNC_SYS_F_PREC,				/*!<  F精度 {Get(Bit32)} */
	HNC_SYS_S_PREC,				/*!<  S精度 {Get(Bit32)} */
	HNC_SYS_NCK_VER,			/*!<  NCK版本 {Get(Bit8[32])} */
	HNC_SYS_DRV_VER,			/*!<  DRV版本 {Get(Bit8[32])} */
	HNC_SYS_PLC_VER,			/*!<  PLC版本 {Get(Bit8[32])} */
	HNC_SYS_CNC_VER,			/*!<  CNC版本 {Get(Bit32) Set(Bit32)} */
	HNC_SYS_MCP_KEY,			/*!<  MCP面板钥匙开关 {Get(Bit32)} */
	HNC_SYS_ACTIVE_CHAN,		/*!<  活动通道 {Get(Bit32) Set(Bit32)} */
	HNC_SYS_REQUEST_CHAN,		/*!<  请求通道 {Get(Bit32)} */
	HNC_SYS_MDI_CHAN,			/*!<  MDI运行通道 {Get(Bit32)} */
	HNC_SYS_REQUEST_CHAN_MASK,	/*!<  请求的通道屏蔽字 {Get(Bit32)} */
	HNC_SYS_CHAN_MASK,			/*!<  通道屏蔽字 {Set(Bit32)} */
	HNC_SYS_PLC_STOP,			/*!<  plc停止 {Set(NULL)} */
	HNC_SYS_POWEROFF_ACT,		/*!<  断电应答 {Set(NULL)} */
	HNC_SYS_IS_HOLD_REDECODE,	/*!<  进给保持后是否重新解释 {Get(Bit32)} */
	HNC_SYS_NC_VER,             /*!<  NC版本 {Get(Bit8[32])} */
	HNC_SYS_SN_NUM,             /*!<  数控装置SN号 {Get(Bit8[32])} */
	HNC_SYS_MACHINE_TYPE,		/*!< 机床型号 {Get(Bit8[48]) Set(Bit8[48])} */
	HNC_SYS_MACHINE_INFO,		/*!< 机床信息 {Get(Bit8[48]) Set(Bit8[48])} */
	HNC_SYS_MACFAC_INFO,		/*!< 机床厂信息 {Get(Bit8[48]) Set(Bit8[48])} */
	HNC_SYS_USER_INFO,			/*!< 用户信息 {Get(Bit8[48]) Set(Bit8[48])} */
	HNC_SYS_MACHINE_NUM,		/*!< 机床编号 {Get(Bit8[48]) Set(Bit8[48])} */
	HNC_SYS_EXFACTORY_DATE,     /*!< 出厂时间 {Get(Bit8[32])} */
	HNC_SYS_ACCESS_LEVEL,		/*!< 权限等级 {Get(Bit32)} */
	HNC_SYS_MUL_CHAN_RESET,		/*!<  多通道复位流程启动标记 {Set(Bit32)[0/1]} */
	HNC_SYS_RIGHTS_KEY,			/*!<  权限钥匙锁 {Get(Bit32)} */
	HNC_SYS_REG_DAYS_REMANING,	/*!< 注册剩余天数 {Get(Bit32)} */
	HNC_SYS_PLC2_CUR_CYCLE,		/*!< PLC2当前运行周期 {Get(Bit32)} */
	HNC_SYS_PLC2_MIN_CYCLE,		/*!< PLC2最小运行周期 {Get(Bit32)} */
	HNC_SYS_PLC2_MAX_CYCLE,		/*!< PLC2最大运行周期 {Get(Bit32)} */
	HNC_SYS_PLC_ONLINE,			/*!< PLC在线调试 {Get(Bit8[48]) Set(Bit8[48])} */
	HNC_SYS_TOTAL
};
/*!@}*/ 

#define MAX_SYS_STR_LEN		(64)

#endif //  __HNC_SYS_H__