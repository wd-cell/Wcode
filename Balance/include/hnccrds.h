/*! 
 * @file hnccrds.h
 * @brief 坐标系数据接口
 * @note 返回值说明：\n
 *	0：成功；\n
 *	-1：参数输入不正确；\n
 *	-2：接口不提供该功能
 * @version V1.00
 * @date 2017/01/06
 * @author HNC-8 Team
 * @copyright 武汉华中数控股份有限公司软件开发部
 */

#ifndef __HNC_CRDS_H__
#define __HNC_CRDS_H__

#include "hnccrdsdef.h"

/*!	@brief 获取坐标系数据的值
 * 
 * @param [in] type     :坐标系数据的类型
 * @param [in] ax       :轴号
 * @param [out] value    :坐标系数据的值
 * @param [in] ch       :通道号
 * @param [in] crds     :坐标系编号
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * - 非0:失败，参见返回值说明;
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_CrdsGetValue(type,ax,value,ch,crds,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_CrdsGetValue(Bit32 type, Bit32 ax, void *value, Bit32 ch = -1, Bit32 crds = -1, Bit16 clientNo = 0);

/*!	@brief 
 * 
 * @param [in] type     :坐标系数据的类型
 * @param [in] ax       :轴号
 * @param [in] val      :坐标系数据的值
 * @param [in] ch       :通道号
 * @param [in] crds     :坐标系编号
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * - 非0:失败，参见返回值说明;
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_CrdsSetValue(type,ax,val,ch,crds,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_CrdsSetValue(Bit32 type, Bit32 ax, void *val, Bit32 ch = -1, Bit32 crds = -1, Bit16 clientNo = 0);

/*!	@brief 取系统定义的各类坐标系数目
 * 
 * @param [in] type     :系统定义的各类坐标系
 * @param [in] clientNo :网络连接号
 * @return 
 * -  返回type对应的坐标系数目;
 * - -1:错误;
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_CrdsGetMaxNum(type,clientNo);
 * @endcode     

 * @see :: type HncCrdsMaxNum
 */
HNCAPI Bit32 HNC_CrdsGetMaxNum(Bit32 type, Bit16 clientNo = 0);

/*!	@brief 坐标系数据从文件加载
 * 
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * - -1:上次保存坐标系文件有异常,请核实坐标系数据;
 * - -2:载入失败;
 
 * @attention 优先载入原文件，如果原文件损坏将载入备份文件
 * @par 示例:
 * @code
   //说明
   HNCAPI Bit32 ret = HNC_CrdsLoad(clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_CrdsLoad(Bit16 clientNo = 0);

/*!	@brief 坐标数据保存
 * 
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * - -1:失败;
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_CrdsSave(clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_CrdsSave(Bit16 clientNo = 0);

#endif // __HNC_CRDS_H__
