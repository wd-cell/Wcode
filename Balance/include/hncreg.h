/*! 
 * @file hncreg.h
 * @brief 寄存器接口
 * @note 返回值说明：\n
 *  0：成功；\n
 *  1：异步获取寄存器，未获取到寄存器数据；\n
 *  -1：寄存器类型错误；\n
 *  -2：寄存器组号超过最大限制；\n
 *  -3：寄存器位号超过最大限制；\n
 *  -4：寄存器不允许修改（P寄存器）；\n
 *  -5：寄存器值指针为空；\n
 * @version V1.00
 * @date 2017/01/06
 * @author HNC-8 Team
 * @copyright 武汉华中数控股份有限公司软件开发部
 */

#ifndef __HNC_REG_H__
#define __HNC_REG_H__

#include "hncdatatype.h"
#include "hncregdef.h"

/*!	@brief 获取寄存器的值
 * 
 * @param [in] type     :寄存器类型
 * @param [in] index    :寄存器组号；
 * @param [out] value   :寄存器值；
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * -  非0;失败，参见返回值说明；
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_RegGetValue(type,index,value,clientNo);
 * @endcode     

 * @see :: 寄存器类型 HncRegType
 */
HNCAPI Bit32 HNC_RegGetValue(Bit32 type, Bit32 index, void *value, Bit16 clientNo = 0);

/*!	@brief 设置寄存器的值
 * 
 * @param [in] type     :寄存器类型
 * @param [in] index    :寄存器组号
 * @param [in] value    :寄存器值
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * -  非0;失败，参见返回值说明；
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_RegSetValue(type,index,value,clientNo);
 * @endcode     

 * @see :: 寄存器类型 HncRegType
 */
HNCAPI Bit32 HNC_RegSetValue(Bit32 type, Bit32 index, void *value, Bit16 clientNo = 0);

/*!	@brief 设置寄存器数据的一位
 * 
 * @param [in] type     :寄存器类型
 * @param [in] index    :寄存器组号
 * @param [in] bit      :寄存器位号
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * -  非0;失败，参见返回值说明；
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_RegSetBit(type,index,bit,clientNo);
 * @endcode     

 * @see :: 寄存器类型 HncRegType
 */
HNCAPI Bit32 HNC_RegSetBit(Bit32 type, Bit32 index, Bit32 bit, Bit16 clientNo = 0);

/*!	@brief 清除寄存器数据的一位
 * 
 * @param [in] type     :寄存器类型
 * @param [in] index    :寄存器组号
 * @param [in] bit      :寄存器位号
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * -  非0;失败，参见返回值说明；
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_RegClrBit(type,index,bit,clientNo);
 * @endcode     

 * @see :: 寄存器类型 HncRegType
 */
HNCAPI Bit32 HNC_RegClrBit(Bit32 type, Bit32 index, Bit32 bit, Bit16 clientNo = 0);

/*!	@brief  获取寄存器的总组数
 * 
 * @param [in] type     :寄存器类型
 * @param [out] num     :寄存器组数
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * -  非0;失败，参见返回值说明；
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_RegGetNum(type,num,clientNo);
 * @endcode     

 * @see :: 寄存器类型 HncRegType
 */
HNCAPI Bit32 HNC_RegGetNum(Bit32 type, Bit32 *num, Bit16 clientNo = 0);

/*!	@brief 获取FG寄存器的基址
 * 
 * @param [in] baseType   :基址类型
 * @param [out] baseIndex :基址寄存器组号
 * @param [in] clientNo   :网络连接号
 * @return 
 * -  0:成功;
 * -  非0;失败，参见返回值说明；
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_RegGetFGBase(baseType,baseIndex,clientNo);
 * @endcode     

 * @see :: 基址类型 HncRegFGBaseType
 */
HNCAPI Bit32 HNC_RegGetFGBase(Bit32 baseType, Bit32 *baseIndex, Bit16 clientNo = 0);

#endif // __HNC_REG_H__
