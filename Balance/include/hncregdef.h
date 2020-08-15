/*! 
 * @file hncregdef.h
 * @brief 寄存器定义
 * @version V1.00
 * @date 2017/09/20
 * @author HNC-8 Team
 * @copyright 武汉华中数控股份有限公司
 */

#ifndef _HNC_REG_DEF_H_
#define _HNC_REG_DEF_H_

/*!  寄存器类型 */
enum HncRegType
{
	REG_TYPE_X = 0,	/*!<  X寄存器 Bit8 */
	REG_TYPE_Y,		/*!<  Y寄存器 Bit8 */
	REG_TYPE_F,		/*!<  F寄存器 Bit16 */
	REG_TYPE_G,		/*!<  G寄存器 Bit16 */
	REG_TYPE_R,		/*!<  R寄存器 Bit8 */
	REG_TYPE_W,		/*!<  W寄存器 Bit16 */
	REG_TYPE_D,		/*!<  D寄存器 Bit32 */
	REG_TYPE_B,		/*!<  B寄存器 Bit32 */
	REG_TYPE_P,		/*!<  P寄存器 Bit32 */
	REG_TYPE_I,		/*!<  I寄存器 Bit8 */
	REG_TYPE_Q,		/*!<  Q寄存器 Bit8 */
	REG_TYPE_K,		/*!<  K寄存器 Bit8 */
	REG_TYPE_T,		/*!<  T寄存器 Bit32 */
	REG_TYPE_C,		/*!<  C寄存器 Bit32 */
	REG_TYPE_TOTAL
};

/*!  FG寄存器基地址 */
enum HncRegFGBaseType
{
	REG_FG_SYS_BASE = (REG_TYPE_TOTAL + 1),	/*!<  系统数据基址 {Get(Bit32)} */
	REG_FG_CHAN_BASE,		/*!<  通道数据基址 {Get(Bit32)} */
	REG_FG_AXIS_BASE,		/*!<  轴数据基址 {Get(Bit32)} */
	REG_FG_SYS_EXT_BASE,
	REG_FG_CHAN_EXT_BASE,	
	REG_FG_AXIS_EXT_BASE,
	REG_FG_BASE_TYPE_TOTAL
};

#endif