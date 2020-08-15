/*! 
 * @file hncsys.h
 * @brief 系统数据接口
 * @note 返回值说明：\n
 *           0：成功；\n
 *           -1：参数输入不正确；\n
 *           -2：接口不提供该功能；
 * @version V1.00
 * @date 2017/01/09
 * @author HNC-8 Team
 * @copyright 武汉华中数控股份有限公司软件开发部
 */

#ifndef __HNC_SYS_H__
#define __HNC_SYS_H__

#include "hncsysdef.h"

/*!	@brief 获取系统数据的值
 * 
 * @param [in] type     :系统数据的类型
 * @param [out] value   :系统数据的值
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * - <0:失败，参见返回值说明;
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_SystemGetValue(type,value,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_SystemGetValue(Bit32 type, void *value, Bit16 clientNo = 0);

/*!	@brief 设置系统数据的值
 * 
 * @param [in] type     :系统数据的类型
 * @param [in] value    :系统数据的值
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * - <0:失败，参见返回值说明;
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_SystemSetValue(type,value,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_SystemSetValue(Bit32 type, void *value = NULL, Bit16 clientNo = 0);

/*!	@brief 获取用户实时数据
 * 
 * @param [out] value   :系统数据的值，长度6400
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * - -1:空指针;
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_SystemGetUserRealTimeData(value,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_SystemGetUserRealTimeData(Bit8 *value, Bit16 clientNo = 0);

/*!	@brief 设置用户实时数据
 * 
 * @param [in] value    :系统数据的值，长度6400
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * - -1:空指针;
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_SystemSetUserRealTimeData(value,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_SystemSetUserRealTimeData(Bit8 *value, Bit16 clientNo = 0);




#endif // __HNC_SYS_H__
