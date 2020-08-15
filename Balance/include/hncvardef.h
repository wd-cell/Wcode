/*! 
 * @file hncvardef.h
 * @brief ��������
 * @version V1.00
 * @date 2017/01/10
 * @author HNC-8 Team
 * @copyright �人�������عɷ����޹�˾���������
 */

#ifndef _HNC_VAR_DEF_H_
#define _HNC_VAR_DEF_H_

/*!  �������� */
enum HncVarType
{
	VAR_TYPE_AXIS = 0,	/*!<  ����� {Get(Bit32), Set(Bit32)} */
	VAR_TYPE_CHANNEL,	/*!<  ͨ������ {Get(Bit32), Set(Bit32)} */
	VAR_TYPE_SYSTEM,	/*!<  ϵͳ���� {Get(Bit32), Set(Bit32)} */
	VAR_TYPE_SYSTEM_F,	/*!<  �������͵�ϵͳ���� {Get(fBit64), Set(fBit64)} */
	VAR_TYPE_TOTAL
};

#endif