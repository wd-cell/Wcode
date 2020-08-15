/*! 
 * @file hncupdate.h
 * @brief 系统备份升级
 * @version V1.00
 * @date 2017/01/10
 * @author HNC-8 Team
 * @copyright 武汉华中数控股份有限公司软件开发部
 */


#ifndef __HNC_UPDATE_H__
#define __HNC_UPDATE_H__

#include "hncdatatype.h"

/*! 
 * @name 系统备份升级flag
 * @{
 */
#define SELECT_BASE (0x0000)
#define SELECT_BIN  (0x0001)
#define SELECT_BMP	(0x0002)
#define SELECT_DATA (0x0004)
#define SELECT_HLP  (0x0008)
#define SELECT_N    (0x0010)
#define SELECT_PARM (0x0020)
#define SELECT_PLC  (0x0040)
#define SELECT_PROG (0x0080)
#define SELECT_TMP  (0x0100)
#define SELECT_ALLBTF  (0x0200)
/*!@}*/

/*!	@brief 系统备份
 * 
 * @param [in] flag     :升级内容
 * @param [in] PathName :备份文件名
 * @param [in] clientNo :网络链接号
 * @return 
 * -  0:文件正常备份;
 * - -1:tar文件出错;
 * - -2: 文件备份失败;
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_SysBackup(flag,PathName,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_SysBackup(Bit32 flag,Bit8* PathName, Bit16 clientNo=0);

/*!	@brief 系统升级
 * 
 * @param [in] flag     :升级内容
 * @param [in] PathName :备份文件名
 * @param [in] clientNo :网络链接号
 * @return 
 * -  0:文件升级成功;
 * - -1:tar文件出错;
 * - -2: 升级失败;
 
 * @attention 
 * @par 示例:
 * @code
   //说明
    Bit32 ret = HNC_SysUpdate(fla,PathName,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_SysUpdate(Bit32 flag,Bit8* PathName, Bit16 clientNo=0);

#endif // __HNC_SYS_H__