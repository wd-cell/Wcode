/*! 
 * @file hncreg.h
 * @brief �Ĵ����ӿ�
 * @note ����ֵ˵����\n
 *  0���ɹ���\n
 *  1���첽��ȡ�Ĵ�����δ��ȡ���Ĵ������ݣ�\n
 *  -1���Ĵ������ʹ���\n
 *  -2���Ĵ�����ų���������ƣ�\n
 *  -3���Ĵ���λ�ų���������ƣ�\n
 *  -4���Ĵ����������޸ģ�P�Ĵ�������\n
 *  -5���Ĵ���ֵָ��Ϊ�գ�\n
 * @version V1.00
 * @date 2017/01/06
 * @author HNC-8 Team
 * @copyright �人�������عɷ����޹�˾���������
 */

#ifndef __HNC_REG_H__
#define __HNC_REG_H__

#include "hncdatatype.h"
#include "hncregdef.h"

/*!	@brief ��ȡ�Ĵ�����ֵ
 * 
 * @param [in] type     :�Ĵ�������
 * @param [in] index    :�Ĵ�����ţ�
 * @param [out] value   :�Ĵ���ֵ��
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * -  ��0;ʧ�ܣ��μ�����ֵ˵����
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_RegGetValue(type,index,value,clientNo);
 * @endcode     

 * @see :: �Ĵ������� HncRegType
 */
HNCAPI Bit32 HNC_RegGetValue(Bit32 type, Bit32 index, void *value, Bit16 clientNo = 0);

/*!	@brief ���üĴ�����ֵ
 * 
 * @param [in] type     :�Ĵ�������
 * @param [in] index    :�Ĵ������
 * @param [in] value    :�Ĵ���ֵ
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * -  ��0;ʧ�ܣ��μ�����ֵ˵����
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_RegSetValue(type,index,value,clientNo);
 * @endcode     

 * @see :: �Ĵ������� HncRegType
 */
HNCAPI Bit32 HNC_RegSetValue(Bit32 type, Bit32 index, void *value, Bit16 clientNo = 0);

/*!	@brief ���üĴ������ݵ�һλ
 * 
 * @param [in] type     :�Ĵ�������
 * @param [in] index    :�Ĵ������
 * @param [in] bit      :�Ĵ���λ��
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * -  ��0;ʧ�ܣ��μ�����ֵ˵����
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_RegSetBit(type,index,bit,clientNo);
 * @endcode     

 * @see :: �Ĵ������� HncRegType
 */
HNCAPI Bit32 HNC_RegSetBit(Bit32 type, Bit32 index, Bit32 bit, Bit16 clientNo = 0);

/*!	@brief ����Ĵ������ݵ�һλ
 * 
 * @param [in] type     :�Ĵ�������
 * @param [in] index    :�Ĵ������
 * @param [in] bit      :�Ĵ���λ��
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * -  ��0;ʧ�ܣ��μ�����ֵ˵����
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_RegClrBit(type,index,bit,clientNo);
 * @endcode     

 * @see :: �Ĵ������� HncRegType
 */
HNCAPI Bit32 HNC_RegClrBit(Bit32 type, Bit32 index, Bit32 bit, Bit16 clientNo = 0);

/*!	@brief  ��ȡ�Ĵ�����������
 * 
 * @param [in] type     :�Ĵ�������
 * @param [out] num     :�Ĵ�������
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * -  ��0;ʧ�ܣ��μ�����ֵ˵����
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_RegGetNum(type,num,clientNo);
 * @endcode     

 * @see :: �Ĵ������� HncRegType
 */
HNCAPI Bit32 HNC_RegGetNum(Bit32 type, Bit32 *num, Bit16 clientNo = 0);

/*!	@brief ��ȡFG�Ĵ����Ļ�ַ
 * 
 * @param [in] baseType   :��ַ����
 * @param [out] baseIndex :��ַ�Ĵ������
 * @param [in] clientNo   :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * -  ��0;ʧ�ܣ��μ�����ֵ˵����
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_RegGetFGBase(baseType,baseIndex,clientNo);
 * @endcode     

 * @see :: ��ַ���� HncRegFGBaseType
 */
HNCAPI Bit32 HNC_RegGetFGBase(Bit32 baseType, Bit32 *baseIndex, Bit16 clientNo = 0);

#endif // __HNC_REG_H__
