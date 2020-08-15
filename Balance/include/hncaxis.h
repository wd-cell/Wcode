/*! 
 * @file hncaxis.h
 * @brief 轴接口（逻辑轴）
 * @note 返回值说明：\n
 *	0：成功；\n
 *	-1：参数输入不正确；\n
 *	-2：接口不提供该功能
 * @version V1.00
 * @date 2017/01/06
 * @author HNC-8 Team
 * @copyright 武汉华中数控股份有限公司软件开发部
 */

#ifndef __HNC_AXIS_H__
#define __HNC_AXIS_H__

#include "hncaxisdef.h"

/*!	@brief 获取轴数据的值
 * 
 * @param [in] type     :轴数据的类型
 * @param [in] ax       :轴号
 * @param [in] value    :轴数据的值
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * - 非0:失败，参见返回值说明;
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_AxisGetValue(type,ax,value,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_AxisGetValue(Bit32 type, Bit32 ax, void *value, Bit16 clientNo = 0);

#endif // __HNC_AXIS_H__
