/*! 
 * @file hncsys.h
 * @brief ϵͳ���ݽӿ�
 * @note ����ֵ˵����\n
 *           0���ɹ���\n
 *           -1���������벻��ȷ��\n
 *           -2���ӿڲ��ṩ�ù��ܣ�
 * @version V1.00
 * @date 2017/01/09
 * @author HNC-8 Team
 * @copyright �人�������عɷ����޹�˾���������
 */

#ifndef __HNC_SYS_H__
#define __HNC_SYS_H__

#include "hncsysdef.h"

/*!	@brief ��ȡϵͳ���ݵ�ֵ
 * 
 * @param [in] type     :ϵͳ���ݵ�����
 * @param [out] value   :ϵͳ���ݵ�ֵ
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - <0:ʧ�ܣ��μ�����ֵ˵��;
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_SystemGetValue(type,value,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_SystemGetValue(Bit32 type, void *value, Bit16 clientNo = 0);

/*!	@brief ����ϵͳ���ݵ�ֵ
 * 
 * @param [in] type     :ϵͳ���ݵ�����
 * @param [in] value    :ϵͳ���ݵ�ֵ
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - <0:ʧ�ܣ��μ�����ֵ˵��;
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_SystemSetValue(type,value,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_SystemSetValue(Bit32 type, void *value = NULL, Bit16 clientNo = 0);

/*!	@brief ��ȡ�û�ʵʱ����
 * 
 * @param [out] value   :ϵͳ���ݵ�ֵ������6400
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - -1:��ָ��;
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_SystemGetUserRealTimeData(value,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_SystemGetUserRealTimeData(Bit8 *value, Bit16 clientNo = 0);

/*!	@brief �����û�ʵʱ����
 * 
 * @param [in] value    :ϵͳ���ݵ�ֵ������6400
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - -1:��ָ��;
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_SystemSetUserRealTimeData(value,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_SystemSetUserRealTimeData(Bit8 *value, Bit16 clientNo = 0);




#endif // __HNC_SYS_H__
