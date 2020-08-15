/*! 
 * @file hncregdef.h
 * @brief �Ĵ�������
 * @version V1.00
 * @date 2017/09/20
 * @author HNC-8 Team
 * @copyright �人�������عɷ����޹�˾
 */

#ifndef _HNC_REG_DEF_H_
#define _HNC_REG_DEF_H_

/*!  �Ĵ������� */
enum HncRegType
{
	REG_TYPE_X = 0,	/*!<  X�Ĵ��� Bit8 */
	REG_TYPE_Y,		/*!<  Y�Ĵ��� Bit8 */
	REG_TYPE_F,		/*!<  F�Ĵ��� Bit16 */
	REG_TYPE_G,		/*!<  G�Ĵ��� Bit16 */
	REG_TYPE_R,		/*!<  R�Ĵ��� Bit8 */
	REG_TYPE_W,		/*!<  W�Ĵ��� Bit16 */
	REG_TYPE_D,		/*!<  D�Ĵ��� Bit32 */
	REG_TYPE_B,		/*!<  B�Ĵ��� Bit32 */
	REG_TYPE_P,		/*!<  P�Ĵ��� Bit32 */
	REG_TYPE_I,		/*!<  I�Ĵ��� Bit8 */
	REG_TYPE_Q,		/*!<  Q�Ĵ��� Bit8 */
	REG_TYPE_K,		/*!<  K�Ĵ��� Bit8 */
	REG_TYPE_T,		/*!<  T�Ĵ��� Bit32 */
	REG_TYPE_C,		/*!<  C�Ĵ��� Bit32 */
	REG_TYPE_TOTAL
};

/*!  FG�Ĵ�������ַ */
enum HncRegFGBaseType
{
	REG_FG_SYS_BASE = (REG_TYPE_TOTAL + 1),	/*!<  ϵͳ���ݻ�ַ {Get(Bit32)} */
	REG_FG_CHAN_BASE,		/*!<  ͨ�����ݻ�ַ {Get(Bit32)} */
	REG_FG_AXIS_BASE,		/*!<  �����ݻ�ַ {Get(Bit32)} */
	REG_FG_SYS_EXT_BASE,
	REG_FG_CHAN_EXT_BASE,	
	REG_FG_AXIS_EXT_BASE,
	REG_FG_BASE_TYPE_TOTAL
};

#endif