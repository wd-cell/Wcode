/*! 
 * @file hncchan.h
 * @brief ͨ�����ݽӿ�
 * @note ����ֵ˵����\n
 *	0���ɹ���\n
 *	-1���������벻��ȷ��\n
 *	-2���ӿڲ��ṩ�ù���
 * @version V1.00
 * @date 2017/01/06
 * @author HNC-8 Team
 * @copyright �人�������عɷ����޹�˾���������
 */

#ifndef __HNC_CHANNEL_H__
#define __HNC_CHANNEL_H__

#include "hncchandef.h"


/*!	@brief ��ȡͨ�����ݵ�ֵ
 * 
 * @param [in] type     :ͨ�����ݵ�����
 * @param [in] ch       :ͨ����
 * @param [in] index    :ͨ�����/ͨ�������
 * @param [out] value   :ͨ�����ݵ�ֵ
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * @return 
 * -  0:�ɹ�;
 * - ��0:ʧ�ܣ��μ�����ֵ˵��;
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_ChannelGetValue(type,ch,index,value,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_ChannelGetValue(Bit32 type, Bit32 ch, Bit32 index, void *value, Bit16 clientNo = 0);

/*!	@brief ����ͨ�����ݵ�ֵ
 * 
 * @param [in] type     :ͨ�����ݵ�����
 * @param [in] ch       :ͨ����
 * @param [in] index    :ͨ�����/ͨ�������
 * @param [in] value    :ͨ�����ݵ�ֵ
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * @return 
 * -  0:�ɹ�;
 * - ��0:ʧ�ܣ��μ�����ֵ˵��;
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_ChannelSetValue(type,ch,index,value,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_ChannelSetValue(Bit32 type, Bit32 ch, Bit32 index = 0, void *value = NULL, Bit16 clientNo = 0);

#endif // __HNC_CHANNEL_H__
