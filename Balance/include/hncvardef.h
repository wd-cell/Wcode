/*! 
 * @file hncvardef.h
 * @brief 变量类型
 * @version V1.00
 * @date 2017/01/10
 * @author HNC-8 Team
 * @copyright 武汉华中数控股份有限公司软件开发部
 */

#ifndef _HNC_VAR_DEF_H_
#define _HNC_VAR_DEF_H_

/*!  变量类型 */
enum HncVarType
{
	VAR_TYPE_AXIS = 0,	/*!<  轴变量 {Get(Bit32), Set(Bit32)} */
	VAR_TYPE_CHANNEL,	/*!<  通道变量 {Get(Bit32), Set(Bit32)} */
	VAR_TYPE_SYSTEM,	/*!<  系统变量 {Get(Bit32), Set(Bit32)} */
	VAR_TYPE_SYSTEM_F,	/*!<  浮点类型的系统变量 {Get(fBit64), Set(fBit64)} */
	VAR_TYPE_TOTAL
};

#endif