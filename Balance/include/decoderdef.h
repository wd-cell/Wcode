#ifndef _DECODER_DEF_H_
#define _DECODER_DEF_H_

#include "hncdatatype.h"
#include "datadef.h"

#define TRANS_STK_NUM   4		//变换栈数

#define MAX_PROG_NUM 9			//子程序嵌套调用最大层数
#define MAX_NEST_NUM 9			//流程嵌套最大层数
#define MAX_CONDITION_LEN 128	//条件表达式字符串长度
#define MAX_STRM_BLK	12		//循环类流程的最大段数
#define LOCAL_VAR_NUM	50		//局部变量数
#define MAX_CYCLE_VAR	50		//循环的模态变量数
//#define REG_VAR_NUM		30		//一行的寄存器变量个数

#define SYN_SPDL_ON 0X8000
#define SYN_SPDL_MASTER_MASK 0X7F
#define SYN_SPDL_SLAVE_MASK  0XFF

//译码器模态数据结构[修改此数据结构时，要更新通道变量的定义]
typedef struct DCD_MODAL_DATA
{
	Bit8 axis1,axis2,axis3,axis_t;	//坐标平面两个轴标号，第3轴号,刀具轴[一般为Z轴]
	uBit16 g92_flag,g28_axes;//G92、G28定义的轴标记
	Bit16 s_i,img_axes;	//当前主轴号，用于螺纹
	Bit16 r_ax,a_ax;	//径向轴，轴向轴，用于支持纵切机
	uBit16 flag1,flag2;
	Bit16 g96_si,g96_ax;
	Bit16 prev_crds,has_g95f;
	Bit32 g96_spd,rprg_def,t,tool_r,tool_h;
	Bit16 g93_l,mem_grp,mem_g1,mem_g2;//G93的参数、执行G代码的模态组号和模态代码
#ifdef _TRUE_64_
	Bit64 polar_x0,polar_y0,cyl_r;//极坐标编程原点，柱坐标插补的半径
	Bit64 pwcs_zero[CHAN_AXES_NUM];//当前工件坐标零点，指向通道变量中的VAR_CHAX_WCS_ZERO 复用g92
	Bit64 prg_pos[CHAN_AXES_NUM];	//当前工件程编位置，指向通道变量中的VAR_CHAX_PRG_POS
	Bit64 trns_pos[CHAN_AXES_NUM];	//几何变换前的起点位置，指向通道变量中的VAR_CHAX_TRNS_POS
	Bit64 mcs_pos[CHAN_AXES_NUM];	//当前机床程编位置，指向通道变量中的VAR_CHAX_WCS_POS
	Bit64 g28_pos[CHAN_AXES_NUM];	//g28中间点位置，指向通道变量中的VAR_CHAX_G28_POS
	Bit64 g52_zero[CHAN_AXES_NUM];	//局部坐标系零点，指向通道变量中的VAR_DCD_G52_ZERO
	Bit64 g106_pos[CHAN_AXES_NUM];	//刀具回退点位置，指向通道变量中的VAR_DCD_g106_POS
#else
	Bit64 polar_x0,polar_y0,cyl_r,reserv3[3];//极坐标编程原点，柱坐标插补的半径
	Bit64 pwcs_zero[CHAN_AXES_NUM],reserv4[CHAN_AXES_NUM];//当前工件坐标零点，指向通道变量中的VAR_CHAX_WCS_ZERO 复用g92
	Bit64 prg_pos[CHAN_AXES_NUM],reserv5[CHAN_AXES_NUM];	//当前工件程编位置，指向通道变量中的VAR_CHAX_PRG_POS
	Bit64 trns_pos[CHAN_AXES_NUM],reserv6[CHAN_AXES_NUM];	//几何变换后的编程位置，指向通道变量中的VAR_CHAX_TRNS_POS
	Bit64 mcs_pos[CHAN_AXES_NUM],reserv7[CHAN_AXES_NUM];	//当前机床程编位置，指向通道变量中的VAR_CHAX_WCS_POS
	Bit64 g28_pos[CHAN_AXES_NUM],reserv8[CHAN_AXES_NUM];	//g28中间点位置，指向通道变量中的VAR_CHAX_G28_POS
	Bit64 g52_zero[CHAN_AXES_NUM],reserv9[CHAN_AXES_NUM];	//局部坐标系零点，指向通道变量中的VAR_DCD_G52_ZERO
	Bit64 g106_pos[CHAN_AXES_NUM],reservA[CHAN_AXES_NUM];	//刀具回退点位置，指向通道变量中的VAR_DCD_g106_POS
#endif
	uBit16 g106_axes,cyl_ax,m345,gvel_ax;	//g106轴标记、圆柱插补的旋转轴、m345模态、齿轮/合成速度轴标志
	fBit64 g94_f,g95_f,g32_f,g16_ang;		//F指令，乘了单位倍率的,极坐标编程的模态角度
	Bit16 crds_i,g43_mode,updt_crds,rprg_ax;		//新定义坐标系转编程轴
	uBit16 cyc_ax,irq_ax;			// 复合循环的轴标志，中断后复位轴标志
	uBit32 cyc_reg;					//循环的参数标志
	Bit16 mdl[MAX_GGRP_NUM];			//数控G代码组模态
	SDataUnion regvar[LOCAL_VAR_NUM];	//一行的寄存器变量数组，直接以浮点存储编程数据
}SDcdModal;


#define CNC_MILL		0		/* 铣床数控系统 */
#define CNC_LATHE		1		/* 车床数控系统 */
#define CNC_LATHE_MILL	2		/* 车铣复合数控系统 */

#endif  //_DECODER_DEF_H_
