/*! 
 * @file hnccrdsdef.h
 * @brief ����ϵ��������
 * @version V1.00
 * @date 2017/01/10
 * @author HNC-8 Team
 * @copyright �人�������عɷ����޹�˾���������
 */


#ifndef __HNC_CRDS_DEF_H__
#define __HNC_CRDS_DEF_H__

#include "hncdatatype.h"

/*! ����ϵ�������� \n
   δ��ע���͵���Bit32 */
enum HncCRDS
{
	HNC_CRDS_CH_G5X_ZERO = 0, /*!< ָ��ͨ��������ϵ��� */
	HNC_CRDS_CH_G5X_ID,       /*!< ָ��ͨ��������ϵID */
	HNC_CRDS_CH_WCS_ZERO,     /*!< ָ��ͨ���Ṥ������ϵ��� */
	HNC_CRDS_CH_REL_ZERO,     /*!< ָ��ͨ�����������ϵ��� */
	HNC_CRDS_CH_FRAME_ZERO,   /*!< ָ��ͨ�����������ϵ��� */
	HNC_CRDS_G68_PNT1,        /*!< ��������ϵ������1���� */
	HNC_CRDS_G68_PNT2,        /*!< ��������ϵ������2���� */
	HNC_CRDS_G68_ZERO,        /*!< ��������ϵ��� */
	HNC_CRDS_G68_VCT,         /*!< ��������ϵ���� fBit64 */
	HNC_CRDS_CH_G5X_OFFSET_ZERO,  /*!<ָ��ͨ��������ϵƫ����� */
	HNC_CRDS_TOTAL
};

/*!	ȡϵͳ����ĸ�������ϵ��Ŀ */
enum HncCrdsMaxNum
{
	G5EXT_MAX_NUM,		/*!<	G54.X��չ����ϵ����Ŀ */
	CHG_WCS_MAX_NUM,	/*!<	��������ʱ����ʱ��������ϵ��Ŀ */
	TCS_MAX_NUM			/*!<	TCS����ϵ��Ŀ */
};

#endif // __HNC_CRDS_DEF_H__

