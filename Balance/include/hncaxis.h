/*! 
 * @file hncaxis.h
 * @brief ��ӿڣ��߼��ᣩ
 * @note ����ֵ˵����\n
 *	0���ɹ���\n
 *	-1���������벻��ȷ��\n
 *	-2���ӿڲ��ṩ�ù���
 * @version V1.00
 * @date 2017/01/06
 * @author HNC-8 Team
 * @copyright �人�������عɷ����޹�˾���������
 */

#ifndef __HNC_AXIS_H__
#define __HNC_AXIS_H__

#include "hncaxisdef.h"

/*!	@brief ��ȡ�����ݵ�ֵ
 * 
 * @param [in] type     :�����ݵ�����
 * @param [in] ax       :���
 * @param [in] value    :�����ݵ�ֵ
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - ��0:ʧ�ܣ��μ�����ֵ˵��;
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_AxisGetValue(type,ax,value,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_AxisGetValue(Bit32 type, Bit32 ax, void *value, Bit16 clientNo = 0);

#endif // __HNC_AXIS_H__
