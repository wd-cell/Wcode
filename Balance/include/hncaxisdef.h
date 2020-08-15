/*! 
 * @file hncaxisdef.h
 * @brief ����������
 * @version V1.00
 * @date 2017/01/10
 * @author HNC-8 Team
 * @copyright �人�������عɷ����޹�˾���������
 */

#ifndef __HNC_AXIS_DEF_H__
#define __HNC_AXIS_DEF_H__

#include "hncdatatype.h"

/*!  ���������� \n
 Get(Bit32)��ʾGet����ʱvoid *ΪBit32 */
enum HncAxis
{
	HNC_AXIS_NAME = 0,		/*!< ���� {Get(Bit8[PARAM_STR_LEN])} */
	HNC_AXIS_TYPE,			/*!< ������ {Get(Bit32)} */
	HNC_AXIS_CHAN,			/*!< ��ȡͨ���� {Get(Bit32)} */
	HNC_AXIS_CHAN_INDEX,	/*!< ��ȡ��ͨ���е���� {Get(Bit32)} */
	HNC_AXIS_CHAN_SINDEX,	/*!< ��ȡ��ͨ���е������ {Get(Bit32)} */
	HNC_AXIS_LEAD,			/*!< ��ȡ������ {Get(Bit32)} */
	HNC_AXIS_ACT_POS,		/*!< ����ʵ��λ�� {Get(Bit32)} */
	HNC_AXIS_ACT_POS2,		/*!< ����ʵ��λ��2 {Get(Bit32)} */
	HNC_AXIS_CMD_POS,		/*!< ����ָ��λ�� {Get(Bit32)} */
	HNC_AXIS_ACT_POS_WCS,	/*!< ����ʵ��λ�� {Get(Bit32)} */
	HNC_AXIS_CMD_POS_WCS,	/*!< ����ָ��λ�� {Get(Bit32)} */
	HNC_AXIS_ACT_POS_RCS,	/*!< ���ʵ��λ�� {Get(Bit32)} */
	HNC_AXIS_CMD_POS_RCS,	/*!< ���ָ��λ�� {Get(Bit32)} */
	HNC_AXIS_ACT_PULSE,		/*!< ʵ������λ�� {Get(Bit32)} */
	HNC_AXIS_CMD_PULSE,		/*!< ָ������λ�� {Get(Bit32)} */
	HNC_AXIS_PROG_POS,		/*!< ���λ�� {Get(Bit32)} */
	HNC_AXIS_ENC_CNTR,		/*!< ���λ�� {Get(Bit32)} */
	HNC_AXIS_CMD_VEL,		/*!< ָ���ٶ� {Get(Bit32)} */
	HNC_AXIS_ACT_VEL,		/*!< ʵ���ٶ� {Get(fBit64)} */
	HNC_AXIS_LEFT_TOGO,		/*!< ʣ����� {Get(Bit32)} */
	HNC_AXIS_WCS_ZERO,		/*!< ������� {Get(Bit32)} */
	HNC_AXIS_WHEEl_OFF,		/*!< �����ж�ƫ���� {Get(Bit32)} */
	HNC_AXIS_FOLLOW_ERR,	/*!< ������� {Get(Bit32)} */
	HNC_AXIS_SYN_ERR,		/*!< ͬ�����	{Get(Bit32)} */
	HNC_AXIS_COMP,			/*!< �Ჹ��ֵ {Get(Bit32)} */
	HNC_AXIS_ZSW_DIST,		/*!< Z����ƫ�� {Get(Bit32)} */
	HNC_AXIS_REAL_ZERO,		/*!< ������ {Get(Bit32)} */
	HNC_AXIS_MOTOR_REV,		/*!< ���ת�� {Get(fBit64)} */
	HNC_AXIS_DRIVE_CUR,		/*!< ������Ԫ���� {Get(fBit64)} */
	HNC_AXIS_LOAD_CUR,		/*!< ���ص��� {Get(fBit64)} */
	HNC_AXIS_RATED_CUR,		/*!< ����� {Get(fBit64)} */
	HNC_AXIS_IS_HOMEF,		/*!< ������� {Get(Bit32)} */
	HNC_AXIS_WAVE_FREQ,		/*!< ����Ƶ�� {Get(fBit64)} */
	HNC_AXIS_DRIVE_VER,     /*!< �ŷ������汾 {Get(Bit8[32])} */
	HNC_AXIS_MOTOR_TYPE,    /*!< �ŷ����� {Get(Bit8[32])} */
	HNC_AXIS_MOTOR_TYPE_FLAG,/*!< �ŷ����ͳ����־ {Get(Bit32)} */
	HNC_AXIS_Z_SPACE1,		/*!< Z�����1 {Get(Bit32)} */
	HNC_AXIS_Z_SPACE2,		/*!< Z�����2 {Get(Bit32)} */

	/*! 
	 * @name �������ݹ��û�ֱ��ȡʵ��ֵ�������û����μ���
	 * @{
	 */
	HNC_AXIS_ACT_POS_EX,		/*!< ����ʵ��λ�� {Get(fBit64)} */
	HNC_AXIS_ACT_POS2_EX,		/*!< ����ʵ��λ��2 {Get(fBit64)} */
	HNC_AXIS_CMD_POS_EX,		/*!< ����ָ��λ�� {Get(fBit64)} */
	HNC_AXIS_ACT_POS_WCS_EX,	/*!< ����ʵ��λ�� {Get(fBit64)} */
	HNC_AXIS_CMD_POS_WCS_EX,	/*!< ����ָ��λ�� {Get(fBit64)} */
	HNC_AXIS_ACT_POS_RCS_EX,	/*!< ���ʵ��λ�� {Get(fBit64)} */
	HNC_AXIS_CMD_POS_RCS_EX,	/*!< ���ָ��λ�� {Get(fBit64)} */
	HNC_AXIS_PROG_POS_EX,		/*!< ���λ�� {Get(fBit64)} */
	HNC_AXIS_CMD_VEL_EX,		/*!< ָ���ٶ� {Get(fBit64)} */
	HNC_AXIS_ACT_VEL_EX,		/*!< ʵ���ٶ� {Get(fBit64)} */
	HNC_AXIS_LEFT_TOGO_EX,		/*!< ʣ����� {Get(fBit64)} */
	HNC_AXIS_WCS_ZERO_EX,		/*!< ������� {Get(fBit64)} */
	HNC_AXIS_WHEEL_OFF_EX,		/*!< �����ж�ƫ���� {Get(fBit64)} */
	HNC_AXIS_FOLLOW_ERR_EX,		/*!< ������� {Get(fBit64)} */
	HNC_AXIS_SYN_ERR_EX,		/*!< ͬ�����	{Get(fBit64)} */
	HNC_AXIS_COMP_EX,			/*!< �Ჹ��ֵ {Get(fBit64)} */
	HNC_AXIS_ZSW_DIST_EX,		/*!< Z����ƫ�� {Get(fBit64)} */
	HNC_AXIS_REAL_ZERO_EX,		/*!< ������ {Get(fBit64)} */
	/*!@}*/

	HNC_AXIS_DEV_TYPE,			/*!<���豸����	{Get(Bit32)} */

	HNC_AXIS_TOTAL
};

#endif // __HNC_AXIS_DEF_H__