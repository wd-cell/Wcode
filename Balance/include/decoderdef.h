#ifndef _DECODER_DEF_H_
#define _DECODER_DEF_H_

#include "hncdatatype.h"
#include "datadef.h"

#define TRANS_STK_NUM   4		//�任ջ��

#define MAX_PROG_NUM 9			//�ӳ���Ƕ�׵���������
#define MAX_NEST_NUM 9			//����Ƕ��������
#define MAX_CONDITION_LEN 128	//�������ʽ�ַ�������
#define MAX_STRM_BLK	12		//ѭ�������̵�������
#define LOCAL_VAR_NUM	50		//�ֲ�������
#define MAX_CYCLE_VAR	50		//ѭ����ģ̬������
//#define REG_VAR_NUM		30		//һ�еļĴ�����������

#define SYN_SPDL_ON 0X8000
#define SYN_SPDL_MASTER_MASK 0X7F
#define SYN_SPDL_SLAVE_MASK  0XFF

//������ģ̬���ݽṹ[�޸Ĵ����ݽṹʱ��Ҫ����ͨ�������Ķ���]
typedef struct DCD_MODAL_DATA
{
	Bit8 axis1,axis2,axis3,axis_t;	//����ƽ���������ţ���3���,������[һ��ΪZ��]
	uBit16 g92_flag,g28_axes;//G92��G28���������
	Bit16 s_i,img_axes;	//��ǰ����ţ���������
	Bit16 r_ax,a_ax;	//�����ᣬ�����ᣬ����֧�����л�
	uBit16 flag1,flag2;
	Bit16 g96_si,g96_ax;
	Bit16 prev_crds,has_g95f;
	Bit32 g96_spd,rprg_def,t,tool_r,tool_h;
	Bit16 g93_l,mem_grp,mem_g1,mem_g2;//G93�Ĳ�����ִ��G�����ģ̬��ź�ģ̬����
#ifdef _TRUE_64_
	Bit64 polar_x0,polar_y0,cyl_r;//��������ԭ�㣬������岹�İ뾶
	Bit64 pwcs_zero[CHAN_AXES_NUM];//��ǰ����������㣬ָ��ͨ�������е�VAR_CHAX_WCS_ZERO ����g92
	Bit64 prg_pos[CHAN_AXES_NUM];	//��ǰ�����̱�λ�ã�ָ��ͨ�������е�VAR_CHAX_PRG_POS
	Bit64 trns_pos[CHAN_AXES_NUM];	//���α任ǰ�����λ�ã�ָ��ͨ�������е�VAR_CHAX_TRNS_POS
	Bit64 mcs_pos[CHAN_AXES_NUM];	//��ǰ�����̱�λ�ã�ָ��ͨ�������е�VAR_CHAX_WCS_POS
	Bit64 g28_pos[CHAN_AXES_NUM];	//g28�м��λ�ã�ָ��ͨ�������е�VAR_CHAX_G28_POS
	Bit64 g52_zero[CHAN_AXES_NUM];	//�ֲ�����ϵ��㣬ָ��ͨ�������е�VAR_DCD_G52_ZERO
	Bit64 g106_pos[CHAN_AXES_NUM];	//���߻��˵�λ�ã�ָ��ͨ�������е�VAR_DCD_g106_POS
#else
	Bit64 polar_x0,polar_y0,cyl_r,reserv3[3];//��������ԭ�㣬������岹�İ뾶
	Bit64 pwcs_zero[CHAN_AXES_NUM],reserv4[CHAN_AXES_NUM];//��ǰ����������㣬ָ��ͨ�������е�VAR_CHAX_WCS_ZERO ����g92
	Bit64 prg_pos[CHAN_AXES_NUM],reserv5[CHAN_AXES_NUM];	//��ǰ�����̱�λ�ã�ָ��ͨ�������е�VAR_CHAX_PRG_POS
	Bit64 trns_pos[CHAN_AXES_NUM],reserv6[CHAN_AXES_NUM];	//���α任��ı��λ�ã�ָ��ͨ�������е�VAR_CHAX_TRNS_POS
	Bit64 mcs_pos[CHAN_AXES_NUM],reserv7[CHAN_AXES_NUM];	//��ǰ�����̱�λ�ã�ָ��ͨ�������е�VAR_CHAX_WCS_POS
	Bit64 g28_pos[CHAN_AXES_NUM],reserv8[CHAN_AXES_NUM];	//g28�м��λ�ã�ָ��ͨ�������е�VAR_CHAX_G28_POS
	Bit64 g52_zero[CHAN_AXES_NUM],reserv9[CHAN_AXES_NUM];	//�ֲ�����ϵ��㣬ָ��ͨ�������е�VAR_DCD_G52_ZERO
	Bit64 g106_pos[CHAN_AXES_NUM],reservA[CHAN_AXES_NUM];	//���߻��˵�λ�ã�ָ��ͨ�������е�VAR_DCD_g106_POS
#endif
	uBit16 g106_axes,cyl_ax,m345,gvel_ax;	//g106���ǡ�Բ���岹����ת�ᡢm345ģ̬������/�ϳ��ٶ����־
	fBit64 g94_f,g95_f,g32_f,g16_ang;		//Fָ����˵�λ���ʵ�,�������̵�ģ̬�Ƕ�
	Bit16 crds_i,g43_mode,updt_crds,rprg_ax;		//�¶�������ϵת�����
	uBit16 cyc_ax,irq_ax;			// ����ѭ�������־���жϺ�λ���־
	uBit32 cyc_reg;					//ѭ���Ĳ�����־
	Bit16 mdl[MAX_GGRP_NUM];			//����G������ģ̬
	SDataUnion regvar[LOCAL_VAR_NUM];	//һ�еļĴ����������飬ֱ���Ը���洢�������
}SDcdModal;


#define CNC_MILL		0		/* ϳ������ϵͳ */
#define CNC_LATHE		1		/* ��������ϵͳ */
#define CNC_LATHE_MILL	2		/* ��ϳ��������ϵͳ */

#endif  //_DECODER_DEF_H_
