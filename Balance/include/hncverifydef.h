/*! 
 * @file hncverifydef.h
 * @brief 定义校验相关数据结构
 * @version V1.00
 * @date 2017/01/09
 * @author HNC-8 Team
 * @copyright 武汉华中数控股份有限公司软件开发部
 */

#ifndef __VERIFY_DEF_H__
#define __VERIFY_DEF_H__
#include "hncdatatype.h"
#include "hncdatadef.h"

enum TCURVETYPE
{
	TCURVE_TYPE_NONE,	/*!< 没有曲线类型 */
	TCURVE_TYPE_LINE,	/*!< 直线 */
	TCURVE_TYPE_CYCLE,		/*!< 圆弧 */
	TCURVE_TYPE_THREAD,        /*!< 螺纹 */
	TCURVE_TYPE_TOOL = 10,  /*!< 换刀 */
};


enum
{
	CIRCLE_CW_ARC, /*!< 顺圆 */
	CIRCLE_CCW_ARC, /*!< 逆圆 */
};


typedef struct 
{
	Bit32 spos[3], epos1[3];/*!< 起点、终点 */
	Bit32 epos2[3];/*!< 终点1 */
	Bit32 center[3]; /*!< 圆心 */
	fBit64 radius;/*!< 半径 */
	Bit32 ntype;/*!< 顺圆、逆圆 */
	Bit8  ncircle; /*!< 整圆切分成2个半圆 */
 	fBit64 sAngle, eAngle; // 起始角度，终点角度(单位：弧度)
}hnc_arc;

typedef struct
{
   Bit64 spos[CHAN_AXES_NUM];
   Bit64 epos[CHAN_AXES_NUM];
}hnc_line;

typedef struct
{
  Bit8 curvetype;	 /*!< G代码加工类型 */
  Bit8 rtcpflag;     /*!< 三轴和五轴加工标志 */
  Bit32 lineno;	     /*!< 行号 */
  Bit16 toolLen;     /*!< 刀具长度补偿号 */
  Bit32 cmd;		/*!< G执行指令 */
  Bit32 cmdType;	/*!< G执行指令分类 */

  union
  {
	  hnc_arc  arc;/*!< 圆弧校验数据 */
	  hnc_line line;/*!< 直线段校验数据 */
      Bit32    toolindex;/*!< 刀具号 */
  }data;
}hnc_verify;

#endif