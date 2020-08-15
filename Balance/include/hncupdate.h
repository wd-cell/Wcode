/*! 
 * @file hncupdate.h
 * @brief ϵͳ��������
 * @version V1.00
 * @date 2017/01/10
 * @author HNC-8 Team
 * @copyright �人�������عɷ����޹�˾���������
 */


#ifndef __HNC_UPDATE_H__
#define __HNC_UPDATE_H__

#include "hncdatatype.h"

/*! 
 * @name ϵͳ��������flag
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

/*!	@brief ϵͳ����
 * 
 * @param [in] flag     :��������
 * @param [in] PathName :�����ļ���
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ļ���������;
 * - -1:tar�ļ�����;
 * - -2: �ļ�����ʧ��;
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_SysBackup(flag,PathName,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_SysBackup(Bit32 flag,Bit8* PathName, Bit16 clientNo=0);

/*!	@brief ϵͳ����
 * 
 * @param [in] flag     :��������
 * @param [in] PathName :�����ļ���
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ļ������ɹ�;
 * - -1:tar�ļ�����;
 * - -2: ����ʧ��;
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
    Bit32 ret = HNC_SysUpdate(fla,PathName,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_SysUpdate(Bit32 flag,Bit8* PathName, Bit16 clientNo=0);

#endif // __HNC_SYS_H__