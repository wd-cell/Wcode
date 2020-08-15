/*! 
 * @file hncaxisdef.h
 * @brief 轴数据类型
 * @version V1.00
 * @date 2017/01/10
 * @author HNC-8 Team
 * @copyright 武汉华中数控股份有限公司软件开发部
 */

#ifndef __HNC_AXIS_DEF_H__
#define __HNC_AXIS_DEF_H__

#include "hncdatatype.h"

/*!  轴数据类型 \n
 Get(Bit32)表示Get数据时void *为Bit32 */
enum HncAxis
{
	HNC_AXIS_NAME = 0,		/*!< 轴名 {Get(Bit8[PARAM_STR_LEN])} */
	HNC_AXIS_TYPE,			/*!< 轴类型 {Get(Bit32)} */
	HNC_AXIS_CHAN,			/*!< 获取通道号 {Get(Bit32)} */
	HNC_AXIS_CHAN_INDEX,	/*!< 获取在通道中的轴号 {Get(Bit32)} */
	HNC_AXIS_CHAN_SINDEX,	/*!< 获取在通道中的主轴号 {Get(Bit32)} */
	HNC_AXIS_LEAD,			/*!< 获取引导轴 {Get(Bit32)} */
	HNC_AXIS_ACT_POS,		/*!< 机床实际位置 {Get(Bit32)} */
	HNC_AXIS_ACT_POS2,		/*!< 机床实际位置2 {Get(Bit32)} */
	HNC_AXIS_CMD_POS,		/*!< 机床指令位置 {Get(Bit32)} */
	HNC_AXIS_ACT_POS_WCS,	/*!< 工件实际位置 {Get(Bit32)} */
	HNC_AXIS_CMD_POS_WCS,	/*!< 工件指令位置 {Get(Bit32)} */
	HNC_AXIS_ACT_POS_RCS,	/*!< 相对实际位置 {Get(Bit32)} */
	HNC_AXIS_CMD_POS_RCS,	/*!< 相对指令位置 {Get(Bit32)} */
	HNC_AXIS_ACT_PULSE,		/*!< 实际脉冲位置 {Get(Bit32)} */
	HNC_AXIS_CMD_PULSE,		/*!< 指令脉冲位置 {Get(Bit32)} */
	HNC_AXIS_PROG_POS,		/*!< 编程位置 {Get(Bit32)} */
	HNC_AXIS_ENC_CNTR,		/*!< 电机位置 {Get(Bit32)} */
	HNC_AXIS_CMD_VEL,		/*!< 指令速度 {Get(Bit32)} */
	HNC_AXIS_ACT_VEL,		/*!< 实际速度 {Get(fBit64)} */
	HNC_AXIS_LEFT_TOGO,		/*!< 剩余进给 {Get(Bit32)} */
	HNC_AXIS_WCS_ZERO,		/*!< 工件零点 {Get(Bit32)} */
	HNC_AXIS_WHEEl_OFF,		/*!< 手轮中断偏移量 {Get(Bit32)} */
	HNC_AXIS_FOLLOW_ERR,	/*!< 跟踪误差 {Get(Bit32)} */
	HNC_AXIS_SYN_ERR,		/*!< 同步误差	{Get(Bit32)} */
	HNC_AXIS_COMP,			/*!< 轴补偿值 {Get(Bit32)} */
	HNC_AXIS_ZSW_DIST,		/*!< Z脉冲偏移 {Get(Bit32)} */
	HNC_AXIS_REAL_ZERO,		/*!< 相对零点 {Get(Bit32)} */
	HNC_AXIS_MOTOR_REV,		/*!< 电机转速 {Get(fBit64)} */
	HNC_AXIS_DRIVE_CUR,		/*!< 驱动单元电流 {Get(fBit64)} */
	HNC_AXIS_LOAD_CUR,		/*!< 负载电流 {Get(fBit64)} */
	HNC_AXIS_RATED_CUR,		/*!< 额定电流 {Get(fBit64)} */
	HNC_AXIS_IS_HOMEF,		/*!< 回零完成 {Get(Bit32)} */
	HNC_AXIS_WAVE_FREQ,		/*!< 波形频率 {Get(fBit64)} */
	HNC_AXIS_DRIVE_VER,     /*!< 伺服驱动版本 {Get(Bit8[32])} */
	HNC_AXIS_MOTOR_TYPE,    /*!< 伺服类型 {Get(Bit8[32])} */
	HNC_AXIS_MOTOR_TYPE_FLAG,/*!< 伺服类型出错标志 {Get(Bit32)} */
	HNC_AXIS_Z_SPACE1,		/*!< Z脉间距1 {Get(Bit32)} */
	HNC_AXIS_Z_SPACE2,		/*!< Z脉间距2 {Get(Bit32)} */

	/*! 
	 * @name 以下数据供用户直接取实际值，无需用户二次计算
	 * @{
	 */
	HNC_AXIS_ACT_POS_EX,		/*!< 机床实际位置 {Get(fBit64)} */
	HNC_AXIS_ACT_POS2_EX,		/*!< 机床实际位置2 {Get(fBit64)} */
	HNC_AXIS_CMD_POS_EX,		/*!< 机床指令位置 {Get(fBit64)} */
	HNC_AXIS_ACT_POS_WCS_EX,	/*!< 工件实际位置 {Get(fBit64)} */
	HNC_AXIS_CMD_POS_WCS_EX,	/*!< 工件指令位置 {Get(fBit64)} */
	HNC_AXIS_ACT_POS_RCS_EX,	/*!< 相对实际位置 {Get(fBit64)} */
	HNC_AXIS_CMD_POS_RCS_EX,	/*!< 相对指令位置 {Get(fBit64)} */
	HNC_AXIS_PROG_POS_EX,		/*!< 编程位置 {Get(fBit64)} */
	HNC_AXIS_CMD_VEL_EX,		/*!< 指令速度 {Get(fBit64)} */
	HNC_AXIS_ACT_VEL_EX,		/*!< 实际速度 {Get(fBit64)} */
	HNC_AXIS_LEFT_TOGO_EX,		/*!< 剩余进给 {Get(fBit64)} */
	HNC_AXIS_WCS_ZERO_EX,		/*!< 工件零点 {Get(fBit64)} */
	HNC_AXIS_WHEEL_OFF_EX,		/*!< 手轮中断偏移量 {Get(fBit64)} */
	HNC_AXIS_FOLLOW_ERR_EX,		/*!< 跟踪误差 {Get(fBit64)} */
	HNC_AXIS_SYN_ERR_EX,		/*!< 同步误差	{Get(fBit64)} */
	HNC_AXIS_COMP_EX,			/*!< 轴补偿值 {Get(fBit64)} */
	HNC_AXIS_ZSW_DIST_EX,		/*!< Z脉冲偏移 {Get(fBit64)} */
	HNC_AXIS_REAL_ZERO_EX,		/*!< 相对零点 {Get(fBit64)} */
	/*!@}*/

	HNC_AXIS_DEV_TYPE,			/*!<轴设备类型	{Get(Bit32)} */

	HNC_AXIS_TOTAL
};

#endif // __HNC_AXIS_DEF_H__