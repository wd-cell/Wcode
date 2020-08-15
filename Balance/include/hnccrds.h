/*! 
 * @file hnccrds.h
 * @brief ����ϵ���ݽӿ�
 * @note ����ֵ˵����\n
 *	0���ɹ���\n
 *	-1���������벻��ȷ��\n
 *	-2���ӿڲ��ṩ�ù���
 * @version V1.00
 * @date 2017/01/06
 * @author HNC-8 Team
 * @copyright �人�������عɷ����޹�˾���������
 */

#ifndef __HNC_CRDS_H__
#define __HNC_CRDS_H__

#include "hnccrdsdef.h"

/*!	@brief ��ȡ����ϵ���ݵ�ֵ
 * 
 * @param [in] type     :����ϵ���ݵ�����
 * @param [in] ax       :���
 * @param [out] value    :����ϵ���ݵ�ֵ
 * @param [in] ch       :ͨ����
 * @param [in] crds     :����ϵ���
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - ��0:ʧ�ܣ��μ�����ֵ˵��;
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_CrdsGetValue(type,ax,value,ch,crds,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_CrdsGetValue(Bit32 type, Bit32 ax, void *value, Bit32 ch = -1, Bit32 crds = -1, Bit16 clientNo = 0);

/*!	@brief 
 * 
 * @param [in] type     :����ϵ���ݵ�����
 * @param [in] ax       :���
 * @param [in] val      :����ϵ���ݵ�ֵ
 * @param [in] ch       :ͨ����
 * @param [in] crds     :����ϵ���
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - ��0:ʧ�ܣ��μ�����ֵ˵��;
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_CrdsSetValue(type,ax,val,ch,crds,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_CrdsSetValue(Bit32 type, Bit32 ax, void *val, Bit32 ch = -1, Bit32 crds = -1, Bit16 clientNo = 0);

/*!	@brief ȡϵͳ����ĸ�������ϵ��Ŀ
 * 
 * @param [in] type     :ϵͳ����ĸ�������ϵ
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  ����type��Ӧ������ϵ��Ŀ;
 * - -1:����;
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_CrdsGetMaxNum(type,clientNo);
 * @endcode     

 * @see :: type HncCrdsMaxNum
 */
HNCAPI Bit32 HNC_CrdsGetMaxNum(Bit32 type, Bit16 clientNo = 0);

/*!	@brief ����ϵ���ݴ��ļ�����
 * 
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - -1:�ϴα�������ϵ�ļ����쳣,���ʵ����ϵ����;
 * - -2:����ʧ��;
 
 * @attention ��������ԭ�ļ������ԭ�ļ��𻵽����뱸���ļ�
 * @par ʾ��:
 * @code
   //˵��
   HNCAPI Bit32 ret = HNC_CrdsLoad(clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_CrdsLoad(Bit16 clientNo = 0);

/*!	@brief �������ݱ���
 * 
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - -1:ʧ��;
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_CrdsSave(clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_CrdsSave(Bit16 clientNo = 0);

#endif // __HNC_CRDS_H__
