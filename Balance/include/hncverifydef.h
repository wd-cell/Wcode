/*! 
 * @file hncverifydef.h
 * @brief ����У��������ݽṹ
 * @version V1.00
 * @date 2017/01/09
 * @author HNC-8 Team
 * @copyright �人�������عɷ����޹�˾���������
 */

#ifndef __VERIFY_DEF_H__
#define __VERIFY_DEF_H__
#include "hncdatatype.h"
#include "hncdatadef.h"

enum TCURVETYPE
{
	TCURVE_TYPE_NONE,	/*!< û���������� */
	TCURVE_TYPE_LINE,	/*!< ֱ�� */
	TCURVE_TYPE_CYCLE,		/*!< Բ�� */
	TCURVE_TYPE_THREAD,        /*!< ���� */
	TCURVE_TYPE_TOOL = 10,  /*!< ���� */
};


enum
{
	CIRCLE_CW_ARC, /*!< ˳Բ */
	CIRCLE_CCW_ARC, /*!< ��Բ */
};


typedef struct 
{
	Bit32 spos[3], epos1[3];/*!< ��㡢�յ� */
	Bit32 epos2[3];/*!< �յ�1 */
	Bit32 center[3]; /*!< Բ�� */
	fBit64 radius;/*!< �뾶 */
	Bit32 ntype;/*!< ˳Բ����Բ */
	Bit8  ncircle; /*!< ��Բ�зֳ�2����Բ */
 	fBit64 sAngle, eAngle; // ��ʼ�Ƕȣ��յ�Ƕ�(��λ������)
}hnc_arc;

typedef struct
{
   Bit64 spos[CHAN_AXES_NUM];
   Bit64 epos[CHAN_AXES_NUM];
}hnc_line;

typedef struct
{
  Bit8 curvetype;	 /*!< G����ӹ����� */
  Bit8 rtcpflag;     /*!< ���������ӹ���־ */
  Bit32 lineno;	     /*!< �к� */
  Bit16 toolLen;     /*!< ���߳��Ȳ����� */
  Bit32 cmd;		/*!< Gִ��ָ�� */
  Bit32 cmdType;	/*!< Gִ��ָ����� */

  union
  {
	  hnc_arc  arc;/*!< Բ��У������ */
	  hnc_line line;/*!< ֱ�߶�У������ */
      Bit32    toolindex;/*!< ���ߺ� */
  }data;
}hnc_verify;

#endif