/*! 
 * @file hncchan.h
 * @brief 通道数据接口
 * @note 返回值说明：\n
 *	0：成功；\n
 *	-1：参数输入不正确；\n
 *	-2：接口不提供该功能
 * @version V1.00
 * @date 2017/01/06
 * @author HNC-8 Team
 * @copyright 武汉华中数控股份有限公司软件开发部
 */

#ifndef __HNC_CHANNEL_H__
#define __HNC_CHANNEL_H__

#include "hncchandef.h"


/*!	@brief 获取通道数据的值
 * 
 * @param [in] type     :通道数据的类型
 * @param [in] ch       :通道号
 * @param [in] index    :通道轴号/通道主轴号
 * @param [out] value   :通道数据的值
 * @param [in] clientNo :网络连接号
 * @return 
 * @return 
 * -  0:成功;
 * - 非0:失败，参见返回值说明;
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_ChannelGetValue(type,ch,index,value,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_ChannelGetValue(Bit32 type, Bit32 ch, Bit32 index, void *value, Bit16 clientNo = 0);

/*!	@brief 设置通道数据的值
 * 
 * @param [in] type     :通道数据的类型
 * @param [in] ch       :通道号
 * @param [in] index    :通道轴号/通道主轴号
 * @param [in] value    :通道数据的值
 * @param [in] clientNo :网络连接号
 * @return 
 * @return 
 * -  0:成功;
 * - 非0:失败，参见返回值说明;
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_ChannelSetValue(type,ch,index,value,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_ChannelSetValue(Bit32 type, Bit32 ch, Bit32 index = 0, void *value = NULL, Bit16 clientNo = 0);

#endif // __HNC_CHANNEL_H__
