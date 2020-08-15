// datadef.h:
//		
//  1.概述:
//      定义与核心数据、系统配置相关的宏和数据结构。
//      核心配置包括：通道数、轴数、设备数、变量及寄存器规模
//		数据结构包括：刀具（形状参数、刀库信息）、参数、设备模块
//		
//  2.作者: 周会成
//  3.创作日期: 2008.10.13
//  4.修改记录:
//		修改者: XXX  修改时间:

#ifndef __DATA_DEF_H__
#define __DATA_DEF_H__

#include "hncdatadef.h"

//For Linux shared memory
#define SYS_SHM_ID_DATA	0xa000100 //寄存器\变量\参数\刀具\刀库\加工程序
#define SYS_SHM_ID_CTRL	0xa000108 //解释器、通道控制器、轴控制器
//#define SYS_SHM_DEV_DICT 0xa000109 //设备数据字典
//#define SYS_SHM_ID_PLC	0xa000109 //PLC程序
//#define SYS_SHM_ID_SMPL	0xa000110 //用户采样数据
//#define SYS_SHM_ID_VBLK	0xa000111 //校验生成的程序段
//#define SYS_SHM_ID_TRACE 0xa000110 //跟踪信息：PLC程序、用户采样数据、校验生成的程序段

//For Linux user call command
#define SYS_REQUEST_ID 0xa000120 //系统调用
//...End of linux use define

#define INTEGRATE_SIZE 4096 //速度积分区长度

//1 变量部分

#define DCD_GLBVAR_BASE		1000 //译码器全局变量的起始编号，访问者的角度 000~999 
#define DECODER_VAR_NUM		3000 //译码器全局变量的终止编号，访问者的角度 1000~2999 
#define LOCAL_VAR_NUM		50	 //模态中的局部变量数，当前宏子程序的局部变量
#define STACK_VAR_BASE		200	 //模态中程序栈变量基地址
#define SYS_VAR_BASE	40000	//系统数据的变量接口起始编号
#define AXES_VAR_BASE	60000	//轴数据的变量接口起始编号
#define TOOL_VAR_BASE	70000	//刀具数据的变量起始编号

#define NEW_USR_VAR_BASE 500    //兼容FANUC,三菱格式，#500~#999为用户自定义变量，断电保存

//系统全局数据[实变量]
#define VAR_SYS_BASE	0
#define VAR_SYS_VNUM	10000
#define VAR_CHAN_VNUM	2000
#define VAR_AXIS_VNUM	400 //trunck专用，合并代码不检查

#define VAR_CHAN_BASE	VAR_SYS_VNUM

#define MAX_SMC_LEAD_NUM	5
#define AXES_CMD_BUF_SIZE	100
#define CMD_SMOOTH_BUF_SIZE	100

#ifdef _HNC_10_
	#define SYS_CHAN_NUM	1
	#define SYS_AXES_NUM	4
	#define SYS_SPDL_NUM	2 //主轴数
	#define SYS_NCBRD_NUM	1 //主控制设备数
	#define SYS_NCOBJ_NUM	15 //从设备控制对象（部件）数【轴数+RS232+LAN+USB+MCP+NCKB+I/O】
	#define CHAN_AXES_NUM	9
	#define CHAN_SPDL_NUM   2	//通道最多主轴数
	#define MAX_SMC_AXES_NUM 2	//最多运控轴数
    #define SYS_MCODE_NUM       (100)   //系统最大M代码数
	
// 	#define VAR_AXES_BASE	12000//10000 + (1+1)1000
// 	#define GLB_VAR_NUM	 12600//12000 + 6*100
#endif //_HNC_10_ 90.4K

#ifdef _HNC_20_
	#define SYS_CHAN_NUM	2
	#define SYS_AXES_NUM	8 
	#define SYS_SPDL_NUM	4 //主轴数
	#define SYS_NCBRD_NUM	2 //主控制设备数
	#define SYS_NCOBJ_NUM	30 //从设备控制对象（部件）数【轴数+RS232+LAN+USB+MCP+NCKB+I/O】
	#define CHAN_AXES_NUM	9 //通道的逻辑轴数
	#define CHAN_SPDL_NUM   2	//通道最多主轴数
	#define MAX_SMC_AXES_NUM 4	//最多运控轴数
    #define SYS_MCODE_NUM       (200)   //系统最大M代码数

// 	#define VAR_AXES_BASE	13000 //10000 + (2+1)*1000
// 	#define GLB_VAR_NUM	14200 //13000 * 12*100
#endif //_HNC_20_  92.8k

#ifdef _HNC_30_
	#define SYS_CHAN_NUM		(4)		// 系统最大通道数
	#define SYS_AXES_NUM		(24)	// 系统最大进给轴数
	#define SYS_SPDL_NUM		(8)		// 系统最大主轴数
	#define SYS_NCBRD_NUM		(4)		// 主控制设备数
	#define SYS_NCOBJ_NUM		(80)	// 从设备控制对象（部件）数
	#define CHAN_AXES_NUM		(9)		// 通道最大轴数
	#define CHAN_SPDL_NUM		(4)		// 通道最大主轴数
	#define MAX_SMC_AXES_NUM	(16)	// 最多运控轴数
	#define SYS_MCODE_NUM       (500)   //系统最大M代码数，暂不考虑不同通道m代码属性不一致

// 	#define VAR_AXES_BASE	15000 // 10000 + (4+1)*1000
// 	#define GLB_VAR_NUM	18200 // 15000 + 32*100
#endif // _HNC_30_ [28200*4=112.8K]

#ifdef _HNC_80_
	#define SYS_CHAN_NUM	8
	#define SYS_AXES_NUM	64
	#define SYS_SPDL_NUM	16//主轴数
	#define SYS_NCBRD_NUM	8 //主控制设备数
	#define SYS_NCOBJ_NUM	120 //从设备控制对象（部件）数【轴数+RS232+LAN+USB+MCP+NCKB+I/O】
	#define CHAN_AXES_NUM	9
	#define CHAN_SPDL_NUM   4	//通道最多主轴数
	#define MAX_SMC_AXES_NUM 32	//最多运控轴数
	#define SYS_MCODE_NUM       (1000)   //系统最大M代码数

// 	#define VAR_AXES_BASE	22000//10000 + (11+1)*1000
// 	#define GLB_VAR_NUM	30000//22000 + 80*100
#endif //_HNC_80_ [30000*4=120K]

#define TOTAL_AXES_NUM (SYS_AXES_NUM+SYS_SPDL_NUM)
#define SYS_PART_NUM	SYS_NCOBJ_NUM //系统设备接口数
#define VAR_AXES_BASE	(VAR_SYS_VNUM+(SYS_CHAN_NUM+1)*VAR_CHAN_VNUM)
#define GLB_VAR_NUM	    (VAR_AXES_BASE+TOTAL_AXES_NUM*VAR_AXIS_VNUM)
#define	USER_VAR_NUM	5000	//用户变量 #50000 ~ #54999
#define USER_DATA_NUM	1000000	//用户数据 100万个,4M空间,主要用于存放列表曲线\大规模测量数据
#define NEW_USER_VAR_NUM 500    //#500 ~ #999

#define MAX_MONITOR_NUM	4
#define MAX_SEMPHORE_NUM 40
//#define MAX_MUTEX_NUM 128
#define G5EXT_WCS_NUM	60
#define MAX_TCS_NUM	20
#define MAX_CHG_WCS_NUM 8 // 进给保持时的临时工件坐标系个数

//系统变量
enum
{
	VAR_DECODER_SIZE,
	VAR_CHANCTRL_SIZE,
	VAR_AXISCTRL_SIZE,
	VAR_SMXCTRL_SIZE,
	VAR_SYS_CRDS_CHAN=4,//Monitor正在设置的坐标系所属通道[最多4个Monitor]
	VAR_SYS_DISP_CHAN=8,//Monitor的显示通道记录[最多4个]
	VAR_DECODER_BAK_SIZE=12,
//	VAR_SYS_ACT_CHAN=12,//8个工位的活动通道
	//VAR_SYS_MUTEX_FLAG=20,//系统全局锁4*32=128个
	VAR_SYS_SEMPHORE=20,//系统全局信号量40个【16位】
	
	VAR_SYS_G5EX_IDCH=40, //60个扩展工件坐标系的ID及通道号,低16位为轴掩码，高16位为通道号
	VAR_SYS_G5EX_ZERO=100,	//60个扩展工件坐标系零点60*18[64位]=1080

	//MDI 信息
	VAR_SYS_MDI_MODE = 1900, //MDI模式:mode ret
	VAR_SYS_MDI_ROW,		//MDI输入程序行数
	VAR_SYS_MDI_CHAN,		//MDI运行的通道
	VAR_SYS_SMX_NUM0,		//静态耦合轴个数
	VAR_SYS_SMX_NUM,		//总耦合轴个数
	VAR_DCDVAR_OFFSET,		//解释器中的局部变量偏移量
	
	VAR_SYS_ALARM_COPY = 1910,	//1910~1917
	VAR_SYS_ALARM_FLAG = 1918,	//1918~1925
	VAR_SYS_NOTE_COPY = 1926,	//1926~1937
	VAR_SYS_NOTE_FLAG = 1938,	//1938~1949

	VAR_SYS_CHG_WCS_N = 1950,	//进给保持时，修改的工件坐标系数
	VAR_SYS_CHG_WCS_I,	//1951~1958，进给保持时，修改的工件坐标系所属的通道号及工件坐标编号
	VAR_SYS_CHG_TOOL_N=1959,	//进给保持时，修改的刀具个数
	VAR_SYS_CHG_TOOL_I=1960,	//1960~1969 进给保持时，修改的刀具编号 
	VAR_SYS_G5X_TEMP=1970,		//1970~2113 八个进给保持时的临时工件坐标系 8*18 = 144

	VAR_SYS_YMD=2114,//记录系统时间 年+月+日
	VAR_SYS_HMS,//系统时间，小时+分钟+秒
	VAR_SYS_POWER_OFF_PERIOD, // 系统上次关机到本次开机的时间差，单位：秒，未读取到时间时为0

	//列表信息
	VAR_SYS_TAB_NUM = 2144, //列表个数 50个列表的信息
	VAR_SYS_TAB_COL,		//第一个列表的列数及主列数
	VAR_SYS_TAB_OFF,		//第一个列表数据的起始地址偏移
//	VAR_SYS_TAB_COL,		//第n个列表的列数及主列数
//	VAR_SYS_TAB_OFF,		//2145 ~ 2244 第n个列表数据的起始地址偏移

	VAR_SYS_G31_8 = 2245,		//G31.8测量点缓存 #42245 ~ #42499	
	VAR_SYS_DEBUG_INF = 2500,	//调试信息42500 ~ 43499 
	
	VAR_SMPL_PERIOD = 3500,		//采样周期设置,为插补周期的自然数倍，16个采样通道共用
	VAR_SMPL_LMT,				//采样截止条件，采样通道共用
	VAR_SMPL_IDX,				//采样通道写指针，采样通道共用
	VAR_SMPL_READ_PT,			//采样通道读指针，采样通道共用
	VAR_SMPL_TYPE = 3504,		//3504~3535 采样通道类型，共32个
	VAR_SMPL_AXIS=3536,			//3536~3567	采样通道轴号，共32个
	VAR_SMPL_OFFSET=3568,		//3568~3599 采样通道偏移量，共32个
	VAR_SMPL_DATA_LEN=3600,		//3600~3631 采样通道数据长度，共32个
	VAR_SMPL_USED_CHAN_NUM = 3632,	//已使用的采样通道数
	VAR_EVENT_SUBSCRIBED,		//是否订阅事件数据
	VAR_ALARM_SUBSCRIBED,		//是否订阅报警数据

	VAR_TOOLMEAS_CALIBATION_TYPE = 3700,	// 激光式测量(Bit32)   3700~3749刀具测量使用
	VAR_TOOLMEAS_BLOW_OPEN,					// 吹气开M指令(Bit32)
	VAR_TOOLMEAS_BLOW_CLOSE,				// 吹气关M指令(Bit32)
	VAR_TOOLMEAS_LASER_OPEN,				// 激光开M指令(Bit32)
	VAR_TOOLMEAS_LASER_CLOSE,				// 激光关M指令(Bit32)
	VAR_TOOLMEAS_LASER_DOOR_OPEN,			// 激光门开M指令(Bit32)
	VAR_TOOLMEAS_LASER_DOOR_CLOSE,			// 激光门关M指令(Bit32)
	VAR_TOOLMEAS_M_NUM,						// 测量次数(Bit32)
	VAR_TOOLMEAS_SAVE_HEIGTH,				// 安全距离高度(Bit32*100000)
	VAR_TOOLMEAS_M_F2,						// 测量速度(Bit32*100000)
	VAR_TOOLMEAS_M_F3,						// 触发速度(Bit32*100000)
	VAR_TOOLMEAS_M_S,						// 主轴转速(Bit32*100000)
	VAR_TOOLMEAS_M_THINKNESS,				// 量仪厚度(Bit32*100000)
    VAR_STARTNO,                            // 起始刀具号(Bit32)

	VAR_TOOLMEAR_T_F1,                      //车床测量速度(Bit32*100000)
	VAR_TOOLMEAR_T_F2,                      //车床接触速度(Bit32*100000)
	VAR_TOOLMEAR_T_LENGTH,                  //车床量仪长度(Bit32*100000)
	VAR_TOOLMEAR_T_WIDTH,                   //车床量仪宽度(Bit32*100000)
	VAR_TOOLMEAR_T_NUM,                     //车床测量次数(Bit32)
	VAR_TOOLMEAS_M_BASE_TOOL_LENGTH,		//铣床标准刀具长度(Bit32*100000)

	VAR_TOOLMEAS_T_REF_DIR_X = 3730,		//标刀方向X	
	VAR_TOOLMEAS_T_REF_DIR_Z,				//标刀方向Z

	VAR_G12_POLOR_LEFTRIGHT = 3740, //极点位置，在极点左边还是右边
	VAR_G12_POLOR_TYPE, //极点类型
	VAR_RIGHT_CONFIG = 3742, // 3742~3748 当前权限mcp面板按钮使能
	VAR_G97_S = 3750,
	
	VAR_KEY_PRESS = 3800,						// 按键按下标志	(屏保与自动关机使用)		
	VAR_NO_PRESS_TIME = 3801,				// 键盘没有按键按下的时间(屏保与自动关机使用)
//mark1 trunck版本专用，合并代码时不检查此部分
	// RFID
	VAR_RFID_ON_OFF = 3810,	// RFID读写开关
	VAR_RFID_ID,			// RFID读写器ID号
	VAR_RFID_RW_FLAG,		// RFID读写标记
	VAR_RFID_RESULT,		// RFID读写结果

	VAR_RFID_RW_TOOL_NO,	// RFID读写刀具号
	VAR_RFID_RW_DATA_CFG,	// RFID读写配置
//end of mark1

	VAR_SYS_G68_POINT = 4000, //12*21 G68的两个辅助点
	VAR_SYS_G68_ZERO = 4252, //6*21 [Bit64]
	VAR_SYS_G68_VCT = 4378, //18*21个[fBit64] x y z三个轴的向量

	VAR_SYS_TEACH_IN = 5000,	//示教记录 #45000 ~ #49999	

	VAR_SYS_SPDL_SYNC_ERR = 6000,  //变频器攻丝时的同步误差
	VAR_SYS_NOSENSORHEAT_SUMONE=6010,
	VAR_SYS_NOSENSORHEAT_SUMONE_,
	VAR_SYS_NOSENSORHEAT_SUMTWO,
	VAR_SYS_NOSENSORHEAT_SUMTWO_,
	VAR_SYS_NOSENSORHEAT_SUMTHREE,
	VAR_SYS_NOSENSORHEAT_SUMTHREE_,
	VAR_SYS_NOSENSORHEAT_SUMFOUR,
	VAR_SYS_NOSENSORHEAT_SUMFOUR_,
	VAR_SYS_NOSENSORHEAT_SPDL_SUMONE,
	VAR_SYS_NOSENSORHEAT_SPDL_SUMONE_,
	VAR_SYS_NOSENSORHEAT_SPDL_SUMTWO,
	VAR_SYS_NOSENSORHEAT_SPDL_SUMTWO_,
	VAR_SYS_NOSENSORHEAT_SPDL_SUMTHREE,
	VAR_SYS_NOSENSORHEAT_SPDL_SUMTHREE_,
	VAR_SYS_NOSENSORHEAT_Z_DEFORMATION,//Z轴变形量
	VAR_SYS_NOSENSORHEAT_Z_DEFORMATION_,
	VAR_SYS_NOSENSORHEAT_SPDL_DEFORMATION,//主轴引起的Z轴变形量
	VAR_SYS_NOSENSORHEAT_SPDL_DEFORMATION_,
	VAR_SYS_NOSENSORHEAT_NUM=6028,//能耗型无传感器温度补偿变形量数据个数
	VAR_SYS_NOSENSORHEAT_PERIOD = 6029,//能耗型无传感器温度补偿变形量实际时间间隔
	VAR_SYS_NOSENSORHEAT_CUR_STEP = 6030,//能耗型无传感器温度补偿变形量标定步骤
	VAR_SYS_NOSENSORHEAT_CUR_TIME = 6031,//能耗型无传感器温度补偿变形量标定实际时间
	VAR_SYS_NOSENSORHEAT_DATA = 6032,//能耗型无传感器温度补偿变形量数据100个，#46032 ~ #46131，单位微米

	VAR_SYS_TOTAL = VAR_SYS_VNUM //10000
};



// 通道变量
enum
{
	VAR_CHAN_SEL_PROG=0,//选择的程序编号
	VAR_CHAN_DEST_ROW,//运行/跳转到的目标程序行
	VAR_CHAN_DCD_ROW,//正在解释的行
	VAR_CHAN_DCD_OROW,	//解释输出的程序行
	VAR_CHAN_RUN_ROW,	//正在运行的程序行
	VAR_CHAN_FIN_ROW,	//已经完成的程序行
	VAR_CHAN_DCD_PROG,	//正在解释的程序
	VAR_CHAN_RUN_PROG,	//正在运行的程序
	VAR_CHAN_MAIN_ROW,	//运行的主程序行
	VAR_CHAN_PART_STATI,	//加工件数统计

	VAR_CHAN_CMD_FEED,	//通道合成指令速度
	VAR_CHAN_ACT_FEED,	//通道实际合成速度
	VAR_CHAN_SYNC_FLAG, //同步标记	
	VAR_CHAN_BP_ID,	//断点轴标记
	VAR_CHAX_G5X_ID,	//G5x的标志位
	VAR_CHAX_G55_ID,
	VAR_CHAX_G56_ID,
	VAR_CHAX_G57_ID,
	VAR_CHAX_G58_ID,
	VAR_CHAX_G59_ID,

	VAR_CHAX_G54_ZERO=20,	//40 轴G5X粗零点，以下是64位整型变量
	VAR_CHAX_G55_ZERO=38,
	VAR_CHAX_G56_ZERO=56,
	VAR_CHAX_G57_ZERO=74,
	VAR_CHAX_G58_ZERO=92,
	VAR_CHAX_G59_ZERO=110,
	VAR_CHAX_G92_ZERO=128,  //轴G92零点 90
	VAR_CHAX_REL_ZERO=146,	//轴相对坐标系零点
	VAR_CHAN_LEFT_TOGO=164,	//九个逻辑轴剩余进给[插补后值]
	VAR_CHAX_BP_POS=182,	//断点位置[插补后值]

	//通道译码器模态
	VAR_DCD_MDL_DATA=200,
	VAR_DCD_AX_FLAG=VAR_DCD_MDL_DATA, //axis1,axis2,axis3,resvb8;	//坐标平面两个轴标号，第3轴号,当前活动坐标系：53 54~59 92,
	VAR_DCD_G928_FLAG, //uBit16 g92_flag,g28_axes;//G92、G28定义的轴标记
	VAR_DCD_SPDL_IDX,//Bit16 s_i,reserved;	//当前主轴号，用于螺纹
	VAR_DCD_RAAX_FLAG, //Bit16 r_ax,a_ax;	//径向轴，轴向轴，用于支持纵切机
	VAR_DCD_CMD_FLAG,//uBit16 flag1,flag2;
	VAR_DCD_SPDL_SPD,//Bit32 s[CHAN_SPDL_NUM],t,t_r,t_l;
	VAR_DCD_G93_L=212,//Bit16 g93_l,mem_grp,mem_g1,mem_g2;//G93的参数
	VAR_DCD_POLAR_CYL=214,//Bit64 polar_x0,polar_y0,cyl_r;//极坐标原点，柱坐标插补的半径
	VAR_DCD_WCS_ZERO=220,//Bit64 wzero[9]当前的工件坐标系零点 含G92
	VAR_DCD_PRG_POS=238, //Bit64 prg_pos[9]编程坐标位置
	VAR_DCD_TRNS_POS=256, //Bit64 trns_pos[9]变换坐标位置
	VAR_DCD_MCS_POS=274, //Bit64 mcs_zero[9]机床坐标位置
	VAR_DCD_G28_POS=292, //Bit64 g28[9]G28中间点位置
	VAR_DCD_G52_ZERO=310, //Bit64 g52[9]G52原点位置
	VAR_DCD_G106_POS=328, //Bit64 g106[9]G106回退点位置
	VAR_DCD_G106_FLAG=346, //uBit16 g106_axes,cyl_ax,m345,gvel_ax;
	VAR_DCD_F_CMD=348,//fBit64 g94_f,reserv_f,g32_f,g95_f;	F指令，乘了单位倍率的 
	VAR_DCD_CRDS_I=356,
	VAR_DCD_CYC_AX=358,
	VAR_DCD_CYC_REG,
	VAR_DCD_MDL_GRP=360, //G组模态，解释器模态 360~399 80组
	VAR_DCD_MDL_REG=400, //~599 SDataUnion regvar[LOCAL_VAR_NUM];

	//通道内的交互操作数据区
	VAR_IIP_CMD_TYPE=600,//当前执行的指令/加工特征类型，用于显示
	
	VAR_SMPL_AX_FLAG,//低16位 采样轴标记 高16位 G31状态
	
	VAR_DATA_FILE,	//保存或加载数据文件名，不超过7字符
	VAR_DATA_FILE2,
	VAR_DATA_TYPE,	//保存或加载数据的类型[0 G代码程序（只对加载有效） 1 变量 2 刀具 3 参数 4 寄存器 5 采样数据]
	VAR_DATA_START,	//保存或加载数据起始变量号
	VAR_DATA_NUM,	//保存或加载数据的变量个数

	VAR_INTP_POS=610,	//610~627: 插补器的当前输出位置：机床坐标
	VAR_INTP_ZERO=628,	//628~645: 插补器的工件零点
	VAR_CHAN_NOTE_COPY=646, //646~647
	VAR_CHAN_ALARM_COPY=648, //648~649
	VAR_CHAN_NOTE_FLAG=650, //650~651
	VAR_CHAN_ALARM_FLAG=652, //652~653
	VAR_CHAN_G95_F=654,
	VAR_CHAN_G43_AX,//当前刀长补的轴
	VAR_CHAN_G43_L,//当前刀长补 656~657

	VAR_CRDS_FRAME=658,//658~675基架坐标系
	VAR_HOLD_BLK_EPOS=676,//676~693暂停段终点
	VAR_RUN_START_POS=694,//694~711运行起点位置

	VAR_BP_EXT_CMD = 712,//断点外部零点偏置量

	VAR_INTP_WCS=800,	//800~817: 插补器的当前输出位置：工件坐标
	VAR_INTP_VCS_FLAG=818, //虚拟轴坐标系标志
	VAR_VWCS_FLAG,			//虚拟工件坐标系标志
	VAR_ACT_WCS=820,	//820~837: 工件坐标实际位置
	VAR_TAX_ENABLE=850,         //倾斜轴控制使能
	VAR_TAX_ORTH_AX,            //正交轴通道轴号
	VAR_TAX_TILT_AX,            //倾斜轴通道轴号
	VAR_TAX_ANGLE,              //倾斜角度
	VAR_TAX_COMPEN,             //脉冲补偿值
	VAR_INTP_H_D,				//插补器正在使用的H号/D号
	VAR_TANGENT_ANGLE,          //G115L5算出的切线角度
	VAR_PROG_MDI_SWITCH,        //程序与MDI切换步骤
	VAR_MAIN_PROG_LINE,         //主程序行号【玻璃机】
//	VAR_CYC_H_D,                //进入固定循环时，暂存H/D号

	VAR_TANGENT_ABC=870,//870~875当前插补点的角度位置【用于切线跟随】

	VAR_INTP_MODAL=900,	//900~939 插补器的G、M模态，共80个
	VAR_LOADFILE_STATUS=940,//动态装载磁盘文件的状态
	VAR_DCD_TYPE, //解释器机床类型
	VAR_INTP_BLKI,//插补器执行的段号
	VAR_DCD_BLKI,//解释器解释出的段号
	VAR_RANDOM_ROW_STATUS,//任意行状态

	VAR_PROG_FLOW_IDX,//子程序流程选择标记
	VAR_TAP_CMD_S0, // 刚性攻丝时，存储主轴的指令转速
	VAR_TAP_CMD_S1, 
	VAR_TAP_CMD_S2, 
	VAR_TAP_CMD_S3, 
	VAR_TAP_F,//攻丝螺距

	VAR_STR_LEN = 951,//打印字符串长度
	VAR_STR_ADDR,//打印字符串地址 952~966,可装入64个字符
    VAR_DCD_FAST_VERIFY = 967,
    VAR_THREAD_RATIO,
    VAR_BREAK_LINE,//自动运行中，调用中断子程序时记录被中断程序的行
	VAR_SUBR_PROG_RUN_ROW = 970,//每层当前运行行号(0~8)970~978
	VAR_SUBR_NUM = 979,//当前所处的子程序层数
    
	VAR_CHAX_G54_ZERO1=1000,	//轴G5X精零点，以下是64位整型变量
	VAR_CHAX_G55_ZERO1=1018,
	VAR_CHAX_G56_ZERO1=1036,
	VAR_CHAX_G57_ZERO1=1054,
	VAR_CHAX_G58_ZERO1=1072,
	VAR_CHAX_G59_ZERO1=1090,
	VAR_JOG_INTP_POS = 1108,//1108~1126

	VAR_RANDOM_AXIS_MOVE_INVALID = 1127,// 扫描模式指定行有m6标志，此时不执行移动指令

	VAR_PROG_DIST_2END, //1128 启动点到终点的编程距离
	VAR_PROG_DIST_2END_,

	VAR_BLK_LEFT_TIME,//1130 当前段剩余时间
	VAR_BLK_LOAD_PROG_NO,	// 1131 导入的程序号
//mark2 trunck版本专用，合并代码时不检查此部分
	VAR_FAST_VERIFY_RUN_ROW_NO,	// 1132 快速校验运行校验行号(HMI使用)
	VAR_FAST_VERIFY_FINISH,	// 1133 快速校验收到完成事件(HMI使用)
//end of mark2	
	VAR_CUR_PROG_ID = 1139, // 当前程序的唯一id

	VAR_TIME_VAR_WRITE = 1140,
	VAR_TIME_VAR_READ,
//mark3 trunck版本专用，合并代码时不检查此部分
	VAR_CUTTING_PLCTIME,
	VAR_CUTTING_PLCTIMEFLAG,
//end of mark3

	VAR_CHAN_RUN_ROW1,	//正在运行的程序行
	VAR_CUR_PROG_ID1,

	VAR_ROBOT_DATA = 1200, //1200-1700 500*4 bytes

	VAR_CHAN_TOTAL = VAR_CHAN_VNUM //2000
};

//物理轴
enum
{//#[50000 + ax*100 + ?]
	VAR_AXIS_CHN_INF=0,	//低16位：在通道内的逻辑轴号 高16位：数据采样标志
	VAR_AXIS_MEAN_VEL,	//轴的平均速度
	VAR_AXIS_THREAD_POS0,	//加工螺纹时轴的启动加速位置
	VAR_AXIS_THREAD_POS0_,	//
	VAR_AXIS_THREAD_POS1,	//加工螺纹时轴的同步位置
	VAR_AXIS_THREAD_POS1_,	//
	VAR_AXIS_THREAD_POS2,	//加工螺纹时轴的减速位置
	VAR_AXIS_THREAD_POS2_,	//
	VAR_AXIS_THREAD_POS3,	//加工螺纹时轴的停止位置
	VAR_AXIS_THREAD_POS3_,	//
	VAR_AXIS_MEA_CMD_POS,	//测量信号获得时的指令位置 G31
	VAR_AXIS_MEA_CMD_POS_,	//
	VAR_AXIS_MEA_ACT_POS,	//测量信号获得时的实际位置
	VAR_AXIS_MEA_ACT_POS_,	//
	VAR_AXIS_MEA_ACT_POS2,	//测量信号获得时的2号编码器位置
	VAR_AXIS_MEA_ACT_POS2_,	//
	VAR_AXIS_MEA_VEL,	//测量信号获得时的速度
	VAR_AXIS_MEA_TRQ,	//测量信号获得时的电流
	VAR_AXIS_DIST_POS1, //距离码回零第一个零点的实际位置
	VAR_AXIS_DIST_POS1_,
	VAR_AXIS_DIST_POS2, //距离码第2个零点的绝对位置
	VAR_AXIS_DIST_POS2_,
	VAR_AXIS_SYNC_ZOFF0, //同步轴零点初始偏移量
	VAR_AXIS_SYNC_ZOFF0_,
	VAR_AXIS_SPDL_NO, //轴的主轴编号
	VAR_AXIS_0_RESERV_, 
	VAR_AXIS_1_RESERV,//引导轴在从轴零点时的位置
	VAR_AXIS_1_RESERV_, //
	VAR_AXIS_LEAD_DIST,//从轴检查引导距离
	VAR_AXIS_LEAD_DIST_, //29
	VAR_AXIS_EG_DIST, 
	VAR_AXIS_EG_PULSE,
	VAR_AXIS_IN_PULSE1,
	VAR_AXIS_OUT_PULSE1,
	VAR_AXIS_IN_PULSE2,
	VAR_AXIS_OUT_PULSE2, //35
	VAR_AXIS_EG_DIST2, 
	VAR_AXIS_EG_PULSE2,
	VAR_AXIS_2_RESERV,//从轴的标准同步偏差
	VAR_AXIS_2_RESERV_,
	VAR_AXIS_PINC_SUM,//轴的积分时间内的周期累积增量
	VAR_AXIS_PINC_SUM_,
	VAR_AXIS_HOME_CRDS, //参考点坐标
	VAR_AXIS_HOME_CRDS_, //43
	VAR_AXIS_LOCK_POS, //轴锁定时的指令位置
	VAR_AXIS_LOCK_POS_, //45
	VAR_AXIS_LOCK_PULSE, //轴锁定时的指令脉冲位置
	VAR_AXIS_LOCK_PULSE_, //47
	VAR_AXIS_NOTE_COPY, //48
	VAR_AXIS_NOTE_COPY_, //49
	VAR_AXIS_ALARM_COPY, //50
	VAR_AXIS_ALARM_COPY_, //51
	VAR_AXIS_NOTE_FLAG, //52
	VAR_AXIS_NOTE_FLAG_, //53
	VAR_AXIS_ALARM_FLAG, //54
	VAR_AXIS_ALARM_FLAG_, //55
	VAR_AXIS_ENCOFF_PULSE, //编码器偏置的脉冲量56
	VAR_AXIS_ENCOFF_PULSE_, //57
	VAR_AXIS_ENCOFF_PULSE2, //校正的编码器偏置脉冲量58
	VAR_AXIS_ENCOFF_PULSE2_, //59

	VAR_AXIS_SYNC_ACT_POS,	//从动轴在主动轴坐标系中的实际位置
	VAR_AXIS_SYNC_ACT_POS_,
	VAR_AXIS_SYNC_CMD_POS,		  //从动轴在主动轴坐标系中的指令位置
	VAR_AXIS_SYNC_CMD_POS_,
	VAR_AXIS_reserv1,
	VAR_AXIS_reserv2,
	//VAR_AXIS_SPDL_MIN, //螺纹加工时的主轴最小周期增量 60
	//VAR_AXIS_SPDL_MAX, //螺纹加工时的主轴最大周期增量 61
	//VAR_AXIS_SPDL_MEAN, //螺纹加工时的主轴平均周期增量 62
	//VAR_AXIS_THREAD_ACCL,//螺纹加工时的长轴加速距离 63
	//VAR_AXIS_THREAD_NACC,//螺纹加工时的加速周期数 64
	//VAR_AXIS_THREAD_LVEL,//螺纹加工时的长轴周期增量 65
	
	VAR_AXIS_POWEROFF_POS,	//轴关机前的位置
	VAR_AXIS_POWEROFF_POS_,	//轴关机前的位置
	VAR_AXIS_MPG_SPOS,	//手摇开始位置
	VAR_AXIS_MPG_SPOS_,	

	VAR_AXIS_MPG_CNT0=70,
	VAR_AXIS_MPG_CNTN=79,
	
	VAR_AXIS_TOTAL_EXT_CMD, //外部叠加指令总量
	VAR_AXIS_TOTAL_EXT_CMD_, 
	VAR_AXIS_LAST_EXT_CMD,//已经输出的外部叠加指令
	VAR_AXIS_LAST_EXT_CMD_,

	VAR_AXIS_TOTAL_TANG_CMD, //切线跟随叠加指令总量,根据标记判断为实轴或虚轴
	VAR_AXIS_TOTAL_TANG_CMD_, 
	VAR_AXIS_LAST_TANG_CMD,//已经输出的切线跟随叠加指令
	VAR_AXIS_LAST_TANG_CMD_,
	VAR_AXIS_BINORMAL_CENTER,//副法线跟随的刀具中心位置
	VAR_AXIS_BINORMAL_CENTER_,

	//64位脉冲计数，目前仅用于长行程直线轴配绝对式编码器
	VAR_AXIS_ABSCYC_CNT=90,
	VAR_AXIS_ABSCYC_PUL,
	VAR_AXIS_ABSCYC_ROTPUL, //旋转轴反馈脉冲循环计数
	
	//激光PID轴控制
	VAR_AX_JUMP_A,//蛙跳系数A
	VAR_AX_JUMP_B,//蛙跳系数B
	VAR_AX_JUMP_C,//蛙跳系数C
	VAR_AX_JUMP_LEFT_TPGO,//蛙跳剩余进给
	VAR_AX_JUMP_INIT_POS, //蛙跳初始位置
	
    VAR_AXIS_TOTAL_MPG_INTER, //手轮中断量
	VAR_AXIS_ACC_COMP,	//反向时的加速度

	VAR_AXIS_TOTAL = VAR_AXIS_VNUM //100
};
#define VAR_AXIS_G5X_ZERO VAR_AXIS_G54_ZERO

// 2 刀具部分：


#define MAX_CHG_TOOL	10		//暂停时修改的刀具数

#ifdef _HNC_10_ //单通道
	#define MAX_TOOL_NUM	1014	// 最大刀具数【0-1023】
	#define MAX_MAGZ_NUM	32		// 刀库表个数
	#define MAGZ_HEAD_BASE	186		// 表头起始地址
	#define MAGZ_LOC_BASE	698		// 刀位数据起始地址
	#define MAX_RFID_NUM	3	//最大的RFID读写器个数
#endif // _HNC_10_

#ifdef _HNC_20_ // 双通道
	#define MAX_TOOL_NUM	1014	// 最大刀具数【0-1023】
	#define MAX_MAGZ_NUM	32		// 刀库表个数
	#define MAGZ_HEAD_BASE	186		// 表头起始地址
	#define MAGZ_LOC_BASE	698		// 刀位数据起始地址
	#define MAX_RFID_NUM	3	//最大的RFID读写器个数
#endif // _HNC_20_

#ifdef _HNC_30_ // 多通道
	#define MAX_TOOL_NUM	1014	// 最大刀具数【0-1023】
	#define MAX_MAGZ_NUM	32		// 刀库表个数
	#define MAGZ_HEAD_BASE	186		// 表头起始地址
	#define MAGZ_LOC_BASE	698		// 刀位数据起始地址
	#define MAX_RFID_NUM	3	//最大的RFID读写器个数
#endif // _HNC_30_

#ifdef _HNC_80_ // 多通道
	#define MAX_TOOL_NUM	2038	// 最大刀具数【0-2047】
	#define MAX_MAGZ_NUM	64		// 刀库表个数
	#define MAGZ_HEAD_BASE	372		// 表头起始地址
	#define MAGZ_LOC_BASE	1396	// 刀位数据起始地址
	#define MAX_RFID_NUM	3	//最大的RFID读写器个数
#endif // _HNC_80_

// 刀具基本参数
#define MAX_TOOL_INF	5


//3 参数部分：



//各部分参数个数定义[无视型号，统一]
#define NCU_PARAM_NUM		1000	//数控单元参数个数 通讯
#define MAC_PARAM_NUM		1000	//机床/用户参数个数（含用户报警信息）
#define CHAN_PARAM_NUM		500		//通道参数个数
#define AXIS_PARAM_NUM		1000	//轴及伺服参数个数
#define CPAX_PARAM_NUM		200		//轴补偿描述参数个数
#define NCBRD_PARAM_NUM		200		//主站参数个数
#define NCOBJ_PARAM_NUM		20		//从站参数个数


#ifdef _HNC_80_ //12(2)通道，80轴(64进给+16主轴)，8主站，160部件
	#define TABLE_PARAM_NUM		40000 //总数据表参数个数

	//各类参数基地址
	#define PAR_NCU_BASE 0	//数控单元参数基地址
	#define PAR_MAC_BASE 1000	//机床参数基地址
	#define PAR_CHAN_BASE 2000	//通道参数基地址
	#define PAR_AXIS_BASE 8000	//2000+12*500轴及伺服参数基地址
	#define PAR_CMPE_BASE 88000  //8000+(64+16)*1000 轴补偿参数基地址
	#define PAR_BOARD_BASE 104000 //88000+(64+16)*200
	#define PAR_PART_BASE 105600  //104000+8*200控制对象参数基地址
	#define PAR_TABLE_BASE 108800 //105600 +160*20数据表参数基地址
    #define PAR_USERREALTIMEDATA_BASE 148000 //用户自定义数据参数基地址
	#define TOTAL_PARAM_NUM	148800 //108800+40000总参数个数
#endif //_HNC_80_ [108800*8=1162K]

#ifdef _HNC_30_ //4(5)通道，32轴(24进给+8主轴)，4主站，80部件
	#define TABLE_PARAM_NUM		20000 //总数据表参数个数
	
	//各类参数基地址
	#define PAR_NCU_BASE 0	//数控单元参数基地址
	#define PAR_MAC_BASE 1000	//机床参数基地址
	#define PAR_CHAN_BASE 2000	//通道参数基地址
	#define PAR_AXIS_BASE 4000	//2000+4*500轴及伺服参数基地址
	#define PAR_CMPE_BASE 36000  //4000+(24+8)*1000 轴补偿参数基地址 从单独的存储区开始
	#define PAR_BOARD_BASE 42400 //36000+(24+8)*200
	#define PAR_PART_BASE 43200  //42400+4*200控制对象参数基地址
	#define PAR_TABLE_BASE 44800 //43200+80*20数据表参数基地址
    #define PAR_USERREALTIMEDATA_BASE 64000 //用户自定义数据参数读操作基地址
	#define TOTAL_PARAM_NUM	64800 //44800+20000总参数个数
#endif //_HNC_30_ [48800*8=506K]


#ifdef _HNC_20_	//2通道，8轴，4主轴，2主站，30部件
	#define TABLE_PARAM_NUM		8000 //总数据表参数个数

	//各类参数基地址
	#define PAR_NCU_BASE 0	//数控单元参数基地址
	#define PAR_MAC_BASE 1000	//机床参数基地址
	#define PAR_CHAN_BASE 2000	//通道参数基地址
	#define PAR_AXIS_BASE 3000	//2000+2*500轴及伺服参数基地址
	#define PAR_CMPE_BASE 15000  //3000+12*1000轴补偿参数基地址 从单独的存储区开始
	#define PAR_BOARD_BASE 17400  //15000+12*200控制对象参数基地址
	#define PAR_PART_BASE 17800  //17400+2*200控制对象参数基地址
	#define PAR_TABLE_BASE 18400 //17800+30*20数据表参数基地址
	#define PAR_USERREALTIMEDATA_BASE 25600 //用户自定义数据参数读操作基地址
	#define TOTAL_PARAM_NUM	26400 //18400+8000总参数个数
#endif //_HNC_20_


#ifdef _HNC_10_	//1通道，3 轴，2主轴，1主站，15部件
	#define TABLE_PARAM_NUM		5000 //总数据表参数个数
	
	//各类参数基地址
	#define PAR_NCU_BASE 0	//数控单元参数基地址
	#define PAR_MAC_BASE 1000	//机床参数基地址
	#define PAR_CHAN_BASE 2000	//通道参数基地址
	#define PAR_AXIS_BASE 2500	//2000+1*500轴及伺服参数基地址
	#define PAR_CMPE_BASE 7500 //2500+5*1000轴补偿参数基地址 从单独的存储区开始
	#define PAR_BOARD_BASE 8500 //7500+5*200控制对象参数基地址
	#define PAR_PART_BASE 8700  //8500+1*200控制器参数基地址
	#define PAR_TABLE_BASE 9000 //8700+15*20数据表参数基地址
	#define PAR_USERREALTIMEDATA_BASE 13200 //用户自定义数据参数读操作基地址
	#define TOTAL_PARAM_NUM	14000 //9000+5000总参数个数
#endif //_HNC_10_




#define	THREAD_SMOOTH_ON	0x0001	//主轴速度均匀处理
#define	THREAD_COMPEN_ON	0x0002	//起点偏差补偿开启
#define	THREAD_ACTVEL_ON	0x0004	//实际转速校验开启
#define	THREAD_RE_DEC_OPT	0x0008	//保证退尾点还是保证加速度 0 保证退尾段加速不超过给定 1 保证退尾点不提前


#define MAX_MAC_MODEL_PARA 30


#define SWIVEL_TYPE_NUM	7
//	[TABLE_TYPE_NUM]={ "A","B","C","CA","CB","BA","BJ"};
#define TABLE_TYPE_NUM	6
//	[SWIVEL_TYPE_NUM]={ "ZA","ZB","ZCA","ZCB","YXCA","ZBA"};

//RTCP 参数定义【在SChanCtrl中的序号，1==PAR_CH_RTCP_PARA0】
#define MAX_RTCPARA			50	//RTCP最多参数个数

#define PAR_RTCP_PARA0	0 //第一个参数是角度分辨倍率
#define PAR_RTCP_ANG_TYPE 1 //刀具对刀点的角度类型，0：-180～180【一般用于刀具旋转】  1：0~360【一般用于工件旋转】
//#define PAR_RTCP0_BARM_LEN 2 //刀具摆臂长度



#define MAX_SMX_PARAM_NUM 10








//设备数据字典定义，主要用于伺服参数的非周期通讯
#define SYS_GRP_OBJ_NUM (SYS_NCOBJ_NUM+1) //数据字典总设备数
#define MAX_OBJ_PAR_NUM	600               //设备数据字典最大参数个数

#define SERVO_PARA_NUM   500 //伺服进给轴从站PARM参数个数，必须小于等于MAX_OBJ_PAR_NUMSERVO_PARA_NUM
#define SERVO_PARA_NCUC_NUM   100 // 对于NCUC伺服参数大于100会溢出

#define SERVO_STA_NUM    10  //伺服进给轴从站STA参数个数（保留）
#define SPINDLE_PARA_NUM 500 //伺服主轴从站PARM参数个数（保留）
#define SPINDLE_STA_NUM  10  //伺服主轴从站STA参数个数（保留）

//rwflag标志
#define NCUC_UD_LOAD_READ  0x0001 //读从站参数
#define NCUC_UD_LOAD_WRITE 0x0002 //写从站参数
#define NCUC_UD_LOAD_CHECK 0x0004 //校验从站参数
#define NCUC_UD_LOAD_DIFF  0x0008 //从站与系统参数“不同”标志
#define NCUC_UD_LOAD_DONE  0x8000 //读写完成

//spFunc标志
#define NCUC_UD_LOAD_SAVE    0x0001 //保存从站非周期通讯参数
#define NCUC_UD_LOAD_DEFAULT 0x0002 //设置从站非周期通讯参数为默认值
#define NCUC_UD_LOAD_CHANGE  0x1000 //标记从站非周期通讯参数已修改




//SP主轴相关参数
#define PAR_DEV_SP_ENC_IDX    PAR_DEV_AX_ENCOD_TYPE   //主轴编码器反馈设备号
#define PAR_DEV_SP_DA_IDX     PAR_DEV_AX_RESERVE1     //主轴DA输出设备号
#define PAR_DEV_SP_ENC_PORT   PAR_DEV_AX_RESERVE2     //主轴编码器反馈端口号
#define PAR_DEV_SP_DA_PORT    PAR_DEV_AX_RESERVE3     //主轴DA输出端口号

//轴口卡相关参数
#define PAR_DEV_AX_ENC_IDX    PAR_DEV_AX_ENCOD_TYPE   //轴卡编码器反馈设备号
#define PAR_DEV_AX_OUT_IDX    PAR_DEV_AX_RESERVE1     //轴卡脉冲输出设备号
#define PAR_DEV_AX_ENC_PORT   PAR_DEV_AX_RESERVE2     //轴卡编码器反馈端口号
#define PAR_DEV_AX_OUT_PORT   PAR_DEV_AX_RESERVE3     //轴卡脉冲输出端口号

//PIDC位控板相关参数
#define PAR_DEV_PIDC_P		  PAR_DEV_AX_RESERVE1     //位置环比例增益
#define PAR_DEV_PIDC_K		  PAR_DEV_AX_RESERVE2     //前馈因子
#define PAR_DEV_PIDC_DIR_OFF  PAR_DEV_AX_RESERVE3     //主轴定向偏移脉冲数



//用于工程中心IO板，temp
#define	PAR_DEV_AD_OFF 	PAR_DEV_ENCOD1_TYPE	//AD输入偏移组数
#define	PAR_DEV_DA_OFF 	PAR_DEV_ENCOD1_PPR	//DA输出偏移组数

//用于ENCOD编码器接口板，temp
#define PAR_DEV_ENCOD_X_BASE PAR_DEV_IN_X_BASE





//4 寄存器部分
#define SYS_MPG_NUM		10	//同时接的手摇数,手摇数据归在系统数据中

#define AXIS_DWORD_NUM	40	//轴的FG寄存器双字个数
#define CHAN_DWORD_NUM	40	//通道的FG寄存器双字个数
#define SYS_DWORD_NUM	80	//系统的FG寄存器双字个数

#define AXIS_REG_NUM	80	//轴的FG寄存器字个数
#define CHAN_REG_NUM	80	//通道的FG寄存器字个数
#define SYS_REG_NUM		160	//系统的FG寄存器字个数

#ifdef _HNC_10_
	//FG寄存器中的轴、通道、系统用的数据起始偏移量定义
	#define REG_AXIS_BASE 0		//+32*40
	#define REG_CHAN_BASE 1280	//+40*[4+1] [MDI]
	#define REG_SYS_BASE 1480	//+80
	#define REG_FG_TOTAL 1560	//=1560

	//各寄存器个数定义 此处一个为4字节
	#define REG_R_NUM   (572)	//number of R register
	#define REG_X_NUM   (128)	//number of X register
	#define REG_Y_NUM   (128)	//number of Y register
	#define REG_F_NUM   (REG_FG_TOTAL)	//number of F register
	#define REG_G_NUM   (REG_FG_TOTAL)	//number of G register
	#define REG_B_NUM   (1722)   //number of B register

	#define REG_R_BASE	0
		#define REG_R16_BASE		100 //双字节寄存器起始位置
		#define REG_R32_BASE		200 //四字节寄存器起始位置
		#define REG_RT_STATE_BASE	300 //定时器状态起始位置
		#define REG_RT_BASE			308 //定时器起始位置
		#define REG_RC_STATE_BASE	436 //计数器状态起始位置
		#define REG_RC_BASE			444 //技术器起始位置
		#define MAX_R8_NUM			400 //单字节寄存器数量
		#define MAX_R16_NUM			200 //双字节寄存器数量
		#define MAX_R32_NUM			100 //四字节寄存器数量
		#define MAX_RT_NUM			128 //非断电保存定时器数量
		#define MAX_RC_NUM			128 //非断电保存计数器数量
	#define REG_X_BASE	572
	#define REG_Y_BASE	700	
	#define REG_F_BASE	828		//+1560
	#define REG_G_BASE	2388	//+1560
	#define REG_B_BASE	3948	//+1722
		#define REG_BT_STATE_BASE	50 // 断电保存定时器状态起始位置
		#define REG_BT_BASE			54 // 断电保存定时器起始位置
		#define REG_BC_STATE_BASE	118 // 断电保存计数器状态起始位置
		#define REG_BC_BASE			122 // 断电保存技术器起始位置 
		#define MAX_BU_NUM			50 //用户自定义寄存器
		#define MAX_BT_NUM			64 //断电保存定时器数量
		#define MAX_BC_NUM			64 //断电保存计数器数量

	#define REG_DWORD_NUM	5670	//[=23K]
#endif //_HNC_10_


#ifdef _HNC_20_
	//FG寄存器中的轴、通道、系统用的数据起始偏移量定义
	#define REG_AXIS_BASE 0		//+32*40
	#define REG_CHAN_BASE 1280	//+40*[4+1] [MDI]
	#define REG_SYS_BASE 1480	//+80
	#define REG_FG_TOTAL 1560	//=1560

	//各寄存器个数定义 此处一个为4字节
	#define REG_R_NUM   (572)	//number of R register
	#define REG_X_NUM   (128)	//number of X register
	#define REG_Y_NUM   (128)	//number of Y register
	#define REG_F_NUM   (REG_FG_TOTAL)	//number of F register
	#define REG_G_NUM   (REG_FG_TOTAL)	//number of G register
	#define REG_B_NUM   (1722)   //number of B register

	#define REG_R_BASE	0
		#define REG_R16_BASE		100 //双字节寄存器起始位置
		#define REG_R32_BASE		200 //四字节寄存器起始位置
		#define REG_RT_STATE_BASE	300 //定时器状态起始位置
		#define REG_RT_BASE			308 //定时器起始位置
		#define REG_RC_STATE_BASE	436 //计数器状态起始位置
		#define REG_RC_BASE			444 //技术器起始位置
		#define MAX_R8_NUM			400 //单字节寄存器数量
		#define MAX_R16_NUM			200 //双字节寄存器数量
		#define MAX_R32_NUM			100 //四字节寄存器数量
		#define MAX_RT_NUM			128 //非断电保存定时器数量
		#define MAX_RC_NUM			128 //非断电保存计数器数量
	#define REG_X_BASE	572
	#define REG_Y_BASE	700	
	#define REG_F_BASE	828		//+1560
	#define REG_G_BASE	2388	//+1560
	#define REG_B_BASE	3948	//+1722
		#define REG_BT_STATE_BASE	50 // 断电保存定时器状态起始位置
		#define REG_BT_BASE			54 // 断电保存定时器起始位置
		#define REG_BC_STATE_BASE	118 // 断电保存计数器状态起始位置
		#define REG_BC_BASE			122 // 断电保存技术器起始位置 
		#define MAX_BU_NUM			50 //用户自定义寄存器
		#define MAX_BT_NUM			64 //断电保存定时器数量
		#define MAX_BC_NUM			64 //断电保存计数器数量

	#define REG_DWORD_NUM	5670	//[=23K]
#endif //_HNC_20_

#ifdef _HNC_30_
	//FG寄存器中的轴、通道、系统用的数据起始偏移量定义
	#define REG_AXIS_BASE 0		//+32*40
	#define REG_CHAN_BASE 1280	//+40*[4+1] [MDI]
	#define REG_SYS_BASE 1480	//+80
//mark4 trunck版本专用，合并代码时不检查此部分
#	define REG_FG_TOTAL 1864	//=1864
#	define REG_AXIS_EXT_BASE 1560	//+32*8//每个轴扩展16
#	define REG_CHAN_EXT_BASE 1816	//+8*[4+1]
#	define REG_SYS_EXT_BASE  1856	//+8
//end of mark4
	//各寄存器个数定义 此处一个为4字节
	#define REG_R_NUM   (512)	//单字节寄存器数量
	#define REG_X_NUM   (128)	//number of X register
	#define REG_Y_NUM   (128)	//number of Y register
	#define REG_F_NUM   (REG_FG_TOTAL)	//number of F register
	#define REG_G_NUM   (REG_FG_TOTAL)	//number of G register
	#define REG_B_NUM   (1722)   //number of B register

//mark5 trunck版本专用，合并代码时不检查此部分	
	#define REG_W_NUM	(128)	//双字节寄存器数量
	#define REG_D_NUM	(256)	//双字节寄存器数量
	#define REG_I_NUM   (32)   //number of I register
	#define REG_Q_NUM   (32)   //number of Q register
	#define REG_K_NUM	(6)		//number of K register
	#define REG_T_NUM	(512)	//number of T register
	#define REG_C_NUM	(512)	//number of C register

	#define REG_R_BASE		0	//+512
	#define REG_W_BASE	512 //+128
	#define REG_D_BASE	640	 //+256
	#define REG_X_BASE	896		//+128
	#define REG_Y_BASE	1024	//+128
	#define REG_F_BASE	1152	//+1864
	#define REG_G_BASE	3016	//+1864
	#define REG_B_BASE	4880	//+1722
	#define REG_I_BASE 6602 //+32
	#define REG_Q_BASE 6634	//+32
	#define REG_K_BASE 6666	//+6
	#define REG_T_STATE_BASE 6672	//+32	//定时器状态起始位置
	#define REG_T_BASE 6704	//+512*2
	#define REG_C_STATE_BASE 7728	//+32	//计数器状态起始位置
	#define REG_C_BASE 7760	//+512*2



	#define REG_DWORD_NUM	8784	//[8196*4=32K]
//end of mark5
#endif //_HNC_30_


#ifdef _HNC_80_
	//FG寄存器中的轴、通道、系统用的数据起始偏移量定义
	#define REG_AXIS_BASE 0		//+80*40
	#define REG_CHAN_BASE 3200	//+40*[12+3]
	#define REG_SYS_BASE 3800	//+200
	#define REG_FG_TOTAL 4000	//=

	//各寄存器个数定义 此处一个为4字节
	#define REG_R_NUM   (572)	//number of R register
	#define REG_X_NUM   (128)	//number of X register
	#define REG_Y_NUM   (128)	//number of Y register
	#define REG_F_NUM   (REG_FG_TOTAL)	//number of F register
	#define REG_G_NUM   (REG_FG_TOTAL)	//number of G register
	#define REG_B_NUM   (3444)   //number of B register

	#define REG_R_BASE	0
		#define REG_R16_BASE		100 // 双字节寄存器起始位置
		#define REG_R32_BASE		200 // 四字节寄存器起始位置
		#define REG_RT_STATE_BASE	300 // 定时器状态起始位置
		#define REG_RT_BASE			308 // 定时器起始位置
		#define REG_RC_STATE_BASE	436 // 计数器状态起始位置
		#define REG_RC_BASE			444 // 计数器起始位置
		#define MAX_R8_NUM			400 // 单字节寄存器数量
		#define MAX_R16_NUM			200 // 双字节寄存器数量
		#define MAX_R32_NUM			100 // 四字节寄存器数量
		#define MAX_RT_NUM			128 // 非断电保存定时器数量
		#define MAX_RC_NUM			128 // 非断电保存计数器数量
	
	#define REG_X_BASE	572
	#define REG_Y_BASE	700	
	#define REG_F_BASE	828		//+4000
	#define REG_G_BASE	4828	//+4000
	#define REG_B_BASE	8828	//+3444
		#define REG_BT_STATE_BASE	100 // 断电保存定时器状态起始位置
		#define REG_BT_BASE			108 // 断电保存定时器起始位置
		#define REG_BC_STATE_BASE	236 // 断电保存计数器状态起始位置
		#define REG_BC_BASE			244 // 断电保存技术器起始位置 
		#define MAX_BU_NUM			100 //用户自定义寄存器
		#define MAX_BT_NUM			128 //断电保存定时器数量
		#define MAX_BC_NUM			128 //断电保存计数器数量

	#define REG_DWORD_NUM	12272	//[=48K]
#endif //_HNC_80_

//寄存器数量
#define _hnc_get_r_num() (REG_R_NUM*4) //R为一个字节
#define _hnc_get_x_num() (REG_X_NUM*4) //X为一个字节
#define _hnc_get_y_num() (REG_Y_NUM*4) //Y为一个字节
#define _hnc_get_b_num() (REG_B_NUM)   //B为四个字节
#define _hnc_get_f_num() (REG_F_NUM*2) //F为两个字节
#define _hnc_get_g_num() (REG_G_NUM*2) //G为两个字节
//mark6 trunck版本专用，合并代码时不检查此部分
#	define _hnc_get_w_num() (REG_W_NUM*2)//	W为二个字节
#	define _hnc_get_d_num() (REG_D_NUM)	//	D为四个字节
#	define _hnc_get_i_num() (REG_I_NUM*4) //I为一个字节
#	define _hnc_get_q_num() (REG_Q_NUM*4) //Q为一个字节
#	define _hnc_get_k_num() (REG_K_NUM*4) //K为一个字节
#	define _hnc_get_t_num() (REG_T_NUM) //T为四个字节
#	define _hnc_get_c_num() (REG_C_NUM) //C为四个字节

//PLC系统配置(K寄存器)
#	define REG_PLC_SET_STATE0 16 //PLC系统配置状态字0
	#	define PLC_SET_LAD_SHOW_EN		0x01	//	允许梯图显示
	#	define PLC_SET_RAM_WR_EN		0x02	//	允许强制功能
	#	define PLC_SET_REG_LOCK_EN		0x04	//	允许寄存器锁定
	#	define PLC_SET_LAD_EDIT_EN		0x08	//	允许梯图编辑

	#	define PLC_SET_PLC_START 		0x10	//	PLC运行方式
	#	define PLC_SET_PLC_STOP_EN 	0x20	//	允许PLC停止
	#	define PLC_SET_ONLINE_EN 		0x40	//	允许PLC在线调试
	#	define PLC_SET_LAD_PARA_EN		0x80	//	允许梯图参数显示

#	define REG_PLC_SET_STATE1 17 //PLC系统配置状态字1
	#	define PLC_SET_COIL_CHECK_TYPE 	0x01	//	双线圈检查方式
	#	define PLC_SET_REG_VAL_VIEW_TYPE 	0x02	//	梯图诊断界面寄存器值显示方式(默认显示寄存器锁存值)
//end of mark6
//轴状态寄存器
//REG_AXIS_BASE+i*AXIS_REG_NUM
#define REG_AX_STATE 0	//轴状态字0
	#define AX_STATE_MOVING	0x0001	
	#define AX_STATE_HOME1	0x0002
	#define AX_STATE_HOME2	0x0004
	#define AX_HOME_CANCEL	0x0008

	#define AX_STATE_HOMEF	0x0010
	#define AX_SLAVE_HOMING	0x0020 //从轴回零中
 	#define AX_SLAVE_CHEKED	0x0040 //从轴零点检查完成
	#define AX_SLAVE_OFF	0x0080 //从轴的跟随状态已经解除

	#define AX_STATE_ONREF1	0x0100 //在参考点上	
	#define AX_STATE_ONREF2	0x0200
	#define AX_STATE_ONREF3	0x0400
	#define AX_STATE_ONREF4	0x0800
	#define AX_STATE_ONREFS 0x0F00

	#define AX_STATE_OVERLOAD 0x1000 //轴过载
	#define AX_STATE_VALID	 0x2000	//系统轴的参数已生效，开始监控
	#define AX_STATE_LOCKED	  0x4000 //轴已经锁住
	#define AX_STATE_POS_UPDT 0x8000 //轴已经重定位
 
#define REG_AX_STATE1 1	//轴状态字1
	#define AX_FLAG1_MOV_EN	 0x0001 //PLC移动控制使能
	#define AX_FLAG1_S_ABC	 0x0002 //主轴模式还是ABC轴模式
	#define AX_FLAG1_S_ZP	 0x0004 //主轴零脉到达

	#define AX_FLAG1_G00_MOV 0x0010 //快移进给状态（用于第2反向间隙补偿值切换）
	#define AX_FLAG1_ORI_FIN 0x0020	//进给主轴定向完成
	#define AX_FLAG1_ZERO_OK 0x0040	//进给主轴零速到达
	#define AX_FLAG1_SPD_OK	 0x0080	//进给主轴转速到达

	#define AX_FLAG1_VEL_POS	0x0100	//PID轴工作在位置模式
	#define AX_FLAG1_VEL_FOL	0x0200	//PID轴工作在随动模式
	#define AX_FLAG1_VEL_JUMP	0x0400	//PID轴工作在蛙跳模式
	#define AX_FLAG1_VEL_MASK	0x0700	//PID轴掩码
	#define AX_VEL_FOL_REACH	0x0800	//PID轴随动到位

	#define AX_FLAG1_SPDL_POS 0x1000	//主轴工作在位置模式
	#define AX_FLAG1_TURNON	  0x2000	//通知PLC把轴打开 PLC拿到此信号，解开轴销 上使能
	#define AX_FLAG1_ON_IDX	  0x4000	//已在分度位置
	#define AX_FLAG1_TURNOFF  0x8000	//轴关闭指令,PLC拿到此信号，在停止到位置后清除轴的使能

#define REG_SV_STATE 2	//伺服状态字0
	#define SV_STATE_ZERO_GOT  0x0001 //编码器Z脉冲捕获
	#define SV_STATE_BUF_RDY   0x0002 //RESERVE  Axis bi-buffer is ready to receive
	#define SV_STATE_ZERO2_GOT 0x0008 //第2编码器Z脉冲捕获

	#define SV_STATE_HOMEF	   0x0010 //回零完成
	#define SV_STATE_CYC_VALID 0x0040 //零位捕获，循环有效
	#define SV_STATE_PARM_SW   0x0080 //伺服参数切换状态，0：默认参数 1：已切换为第2套伺服参数
	
	#define SV_STATE_RDY	   0x0100 //伺服使能准备好
	#define SV_MODE_POS		   0x0200 //位置工作模式
	#define SV_MODE_VEL		   0x0400 //速度工作模式
	#define SV_MODE_TRQ		   0x0800 //力矩工作模式
	#define SV_MODE_MASK	   0x0E00 //工作模式掩码

	#define SV_STATE_ZERO	   0x1000 //z脉冲捕获	
	#define SV_GAIN_OK		   0x2000 //增益切换完成
	#define SV_SPEED_REACH	   0x4000 //主轴速度到达
	#define	SV_SPEED_ZERO	   0x8000 //主轴零速到达

#define REG_SV_STATE1 3	//伺服状态字1
	#define SV_STATE_OK        0x0001 //伺服正常无报警/提示
    #define SV_STATE_ALM       0x0002 //伺服报警，报警号在轴控制字REG_AX_SV_ALM_NO
	#define SV_STATE_MSG	   0x0004 //伺服提示，提示号在轴控制字REG_AX_SV_MSG_NO

// 	#define SV_STATE_STEP      0x0010 //伺服阶跃响应状态位
	#define SV_STATE_SPORIN	   0x0100 //主轴定向完成
	#define SV_STATE_HOME_FIN  0x0200 //伺服回零完成
	#define SV_STATE_HOME_ALM  0x0400 //伺服回零报警

#define REG_AX_CHAN_IDX     4	//4  轴所属的通道
#define REG_AX_SLAVE_NUM    5	//5  引导的从轴个数 

#define REG_AX_POS_INC      6   //6~7   实时的输出指令增量，电机坐标
#define REG_AX_POS_CMD      8	//8~11  实时的输出指令位置，电机坐标

#define REG_AX_CMD_PULSE    12	//12~15 输出指令脉冲位置，脉冲单位
#define REG_AX_PULSE_INC    16	//16~17 输出指令脉冲增量，脉冲单位
#define REG_AX_TRQ_CMD      18	//18~19 输出指令力矩

#define REG_AX_POS_ACT      20	//20~23 1号编码器反馈实际位置，米度单位
#define REG_AX_POS2_ACT     24	//24~27 2号编码器反馈实际位置，米度单位

#define REG_AX_MAC_CMD      28	//28~31 机床指令位置，米度单位
#define REG_AX_MAC_ACT      32	//32~35 机床实际位置，米度单位

#define REG_AX_ERR_FLAG     36  //36~37 轴报警
#define REG_AX_NOTE_FLAG    38  //38~39 轴提示信息标志 定义在 syserr.h

#define REG_AX_BIG_VEL      40	//40~41
#define REG_AX_Z_SW_DIST    42  //42~43 回零开关至Z脉的距离
#define REG_AX_BIG_ACC      44	
#define REG_AX_WAVE_CYLE    45	//45    波形指令周期
#define REG_AX_TOL_CMPE     46  //46~49 总补偿值，包括静态补偿和动态补偿
#define REG_AX_SYNC_LAG     50  //50~53 同步位置偏差
#define REG_AX_SYNC_VEL_ERR 54  //54~55 同步速度偏差
#define REG_AX_SYNC_TRQ_ERR 56  //56~57 同步电流偏差
#define REG_AX_FREE_INC		58  //58~59 轴自由状态下的累计增量

#define REG_AX_BIGAV_NUM	60  //60 实际速度累计超速次数
								//61 保留
#define REG_AX_FLAG_G00		62	//62~63 G00指令增量标志 同步轴与引导轴相同
#define REG_AX_VEL_FWD		64	//64~65 速度前馈
#define REG_AX_TRQ_FWD		66	//66~67 扭矩前馈

#define REG_AX_OFF_ALARM    68  //轴反馈误差报警
#define REG_AX_CRC_ERR		69	//轴校验出错

#define REG_AX_TYPE_STATE	70	//轴控制模式，2为手轮中断，3为PMC模式
#define REG_AX_PID_DEM_STEP	71	//随动轴标定步骤
#define REG_AX_PID_DEM_NUM	72	//随动轴标定次数
#define REG_AX_PID_STATE	73	//PID轴状态
	#define REG_AX_PID_DEM	   0x0001	//PID轴标定完成
    #define REG_AX_PID_PB	   0x0002	//PID轴碰板信号
    #define REG_AX_PID_DY1     0x0004   //PID轴标定输出1
    #define REG_AX_PID_DY2     0x0008   //PID轴标定输出2
	#define AX_FOLLOW_SP_M3    0x0010   //从轴正转
	#define AX_FOLLOW_SP_M4    0x0020   //从轴反转
    #define AX_FOLLOW_SP_STOP  0x0040   //从轴停止
	#define AX_FREQTAP_SP_M3   0x0100   //变频主轴正转
	#define AX_FREQTAP_SP_M4   0x0200   //变频主轴反转
	#define AX_FREQTAP_SP_STOP 0x0400   //变频主轴停止
#define REG_AX_SHELF_TAR	74	//轴当前档位
#define REG_AX_LEAD_NO  75  //从动轴的导引轴轴号
	#define REG_AX_LEAD_EXIST	0xC000 //此轴存在导引轴
	#define REG_AX_LEAD_RIGID	0x8000 //此轴存在导引轴(刚性同步，类型1)
	#define REG_AX_LEAD_FIEX	0x4000 //此轴存在导引轴(柔性同步，类型11)

#define REG_AX_STATE2	76	//轴状态字2
	#define AX_FLAG2_SYNC_OK	0x0001	//同步完成
	#define	AX_FLAG2_FREQTAP	0X0002  //变频主轴攻丝动作中
	#define AX_FLAG2_SERVO_SW	0x0004	//伺服回零开始
	#define AX_FLAG2_HOME_GO	0x0008	//回零开始，只生效一个周期，用于通知从轴开始回零

#define REG_AX_SHELF_ACT	77  //轴当前档位
//#define REG_AX_CYC_PULSE	78	//78~79 轴实际脉冲循环清零脉冲数，用于多档主轴换挡时更改循环清零脉冲数
#define REG_AX_SHELF_OUTP	78	//轴当前档位分子
#define REG_AX_SHELF_FBKP	79	//轴当前档位分母
//以下为轴F扩展寄存器定义
#define REG_AX_EX_ELECTRICITY_SPEC 0 // 0~1 驱动单元电流规格
// 以下为轴F扩展寄存器定义
#define  REG_AX_EX_ELECTRICITY_SPEC 0 // 0~1 驱动器电流规格

//轴控制寄存器
//REG_AXIS_BASE+i*AXIS_REG_NUM
#define REG_AX_CTRL 0	//轴控制字0
	#define AX_CTRL_LSP_SW		0x0001	//正限位开关
	#define AX_CTRL_LSN_SW		0x0002	//负限位开关
	#define AX_CTRL_DIS_P		0x0004	//正向禁止
	#define AX_CTRL_DIS_N		0x0008	//负向禁止

	#define AX_CTRL_HOME_CMD	0x0010	//回零指令	
	#define AX_CTRL_HOME_SW		0x0020	//回零挡块
	#define AX_CTRL_LOCK		0x0040	//机床轴锁住
	#define AX_CTRL_EN_SW		0x0080	//轴监控开

//	#define AX_CTRL_GO_SAFE1	0x0100	//走向#1安全位置
//	#define AX_CTRL_GO_SAFE2	0x0200	//走向#2安全位置
//	#define AX_CTRL_GO_SAFE3	0x0400	//

	#define AX_CTRL_VEL_POS		0x0100	//PID轴位置模式请求
	#define AX_CTRL_VEL_FOL		0x0200	//PID轴随动模式请求
	#define AX_CTRL_VEL_JUMP	0x0400	//PID轴蛙跳模式请求
	#define AX_CTRL_VEL_MASK	0x0700	//PID轴掩码

	#define AX_FREE_SLAVE		0x0800	//从轴耦合解除 PLC或系统置 作用到跟随轴

	#define AX_CTRL_GO_SAFE1	0x1000	//走向#1安全位置
	#define AX_CTRL_GO_SAFE2	0x2000	//走向#2安全位置
	#define AX_CTRL_EXCOMP		0x4000	//补偿扩展
	#define AX_CTRL_UPDT_POS	0x8000	//轴更新位置(DISABLE-ENABLE-REPOS)	
	
#define REG_AX_CTRL1 1	//轴控制字1
	#define AX_CTRL1_MOV2		0x0001	//PMC轴运动到目标位置 往复轴启动 
	#define AX_CTRL1_MOV		0x0002	//PMC轴增量运动控制   往复轴停泊在参考位置
	#define AX_CTRL1_LMT2		0x0004	//第2软限位使能		  往复轴停泊在参考位置2
	#define AX_CTRL1_LMT3		0x0008	//扩展软限位使能	  往复轴停泊在参考位置3

	#define AX_CTRL1_SP_JOG		0x0010	//进给主轴点动
	#define AX_CTRL1_SP_ORI		0x0020	//进给主轴定向
	#define AX_CTRL1_SP_M3		0x0040	//进给主轴正转
	#define AX_CTRL1_SP_M4		0x0080	//进给主轴反转
	#define AX_CTRL1_SP_MASK	0x00F0	//进给主轴指令掩码

	#define AX_CTRL1_SLV_SYNC	0x0100	//指令从动轴回到同步位置
	#define AX_CTRL1_SLV_PMOV	0x0200	//指令从动轴正向微动
	#define AX_CTRL1_SLV_NMOV	0x0400	//指令从动轴负向微动
	#define AX_CTRL1_SLV_EN_M	0x0800	//指令从动轴微动使能
	#define AX_CTRL1_SLV_MASK	0x0700	//指令从动轴掩码

	#define AX_CTRL1_POS_RDY	0x1000	//切换位置模式准备好
	#define AX_CTRL1_RST_S2C	0x2000	//切换的C轴复位后恢复为主轴
	#define AX_CTRL1_ON_ACK		0x4000	//轴打开松开应答【鼠牙分度轴、销钉定位转台】
	#define AX_CTRL1_OFF_ACK	0x8000	//轴关闭锁紧应答【鼠牙分度轴、销钉定位转台】

#define REG_SV_CTRL 2	//伺服控制字0
	#define SV_CTRL_TRAP_ZERO   0x0001  //捕获编码器零脉
	#define SV_CTRL_WAIT_ZERO   0x0002  //RESERVE  For spindle      
	#define SV_CTRL_ZERO_DIS    0x0004  //RESERVE  G bit, Disable the zero pulse function
	#define SV_CTRL_TRAP_ZERO2  0x0008  //捕获第2编码器零脉，直线光栅尺距离编码
	
	#define SV_CTRL_CLR_VALID	0x0010	//清除主轴零点，重新回零
	#define SV_CTRL_ERRRRRR		0x0020	//测试，模拟干扰
	#define SV_CTRL_SPDL_ZERO   0x0040  //RESERVE  主轴零脉计数使能
	#define SV_CTRL_PARM_SW     0x0080  //伺服参数切换 0：默认参数 1：切换为第2套参数
	
	#define SV_CTRL_JAIN_SW		0x0100	//伺服增益切换
	#define SV_CTRL_MODE_POS	0x0200  //切换到位置控制
	#define SV_CTRL_MODE_VEL	0x0400  //切换到速度控制
	#define SV_CTRL_MODE_TRQ	0x0800  //切换到力矩控制

	#define SV_CTRL_SPDL_DIR    0x1000  //主轴定向
	#define SV_CTRL_SPDL_SHIFT  0x2000  //主轴换高档，工程中心光纤总线伺服用
	#define SV_CTRL_SPDL_DIRMODE	0x4000  //主轴定向换挡
	#define SV_CTRL_SPDL_LIMIT	0x8000//主轴限流

#define REG_SV_CTRL1 3	//伺服控制字1
	#define SV_CTRL_EN_SW	    0x0001  //伺服使能开关
	#define SV_CTRL_ALM_RST     0x0002  //伺服报警复位

	#define SV_CTRL_START_SAMP	0x0010  //伺服采集启动
	#define SV_CTRL_QUERY_STATE 0x0020
	#define SV_CTRL_READ_DATA	0x0040
	#define  SV_CTRL_SHIELD		0x0080	//伺服屏蔽字

	#define SV_CTRL_HOME_SW		0x0100	//伺服回零开始
// 	#define SV_CTRL_STEP        0x0010  //伺服阶跃响应控制位
	#define SV_CTRL_ALL			0x4000	//上传全闭环
	#define SV_CTRL_HALF_ALL	0x8000	//上传半闭环与全闭环偏差

#define REG_AX_JOG_SW		4	//轴的点动按键开关
#define REG_AX_STEP_SW		5	//轴的步进按键开关

#define REG_AX_JOG_VEL		6	//6~7   点动速度值[0,停止;1,参数中的手动速度;2参数中的快移动速度;>2自定义的速度单位脉冲/周期]
#define REG_AX_STEP_MUL		8	//步进倍率
#define REG_AX_MPG_MUL		9	//手摇倍率
#define REG_AX_MPG_CNT		10 	//10~11 手摇脉冲数

#define REG_AX_ACT_PULSE	12	//12~15 轴反馈脉冲位置，脉冲单位
#define REG_AX_ACT_PULSE_2	16	//16~19 轴反馈脉冲位置2，脉冲单位

#define REG_AX_ACT_INC		20	//20~21 轴反馈脉冲增量，脉冲单位
#define REG_AX_ACT_INC_2	22	//22~23 轴反馈脉冲增量2，脉冲单位

#define REG_AX_ACT_TRQ		24	//24~25 轴反馈力矩电流
#define REG_AX_FOLLOW_ERR	26	//26~27 轴反馈跟踪误差，脉冲单位

#define REG_AX_ENC_CNTR1	28  //28~31 编码器1的计数器值
#define REG_AX_ENC_CNTR2	32  //32~35 编码器2的计数器值

#define REG_AX_RT_CMPE		36	//36~37 实时补偿值
#define REG_AX_TIME_STAMP	38	//38~39 采样时间戳

#define REG_AX_LATCH_PUL1	40	//40~43 锁存位置1 用于G31\距离码回零
#define REG_AX_LATCH_PUL2	44	//44~47 锁存位置2

#define REG_AX_PMC_POS		48	//48~51 PMC目的位置
#define REG_AX_PMC_DIST		52	//52~55 PMC增量位移

#define REG_AX_SV_ALM_NO    56  //56~57 伺服报警号
#define REG_AX_SV_MSG_NO    58  //58~59 伺服提示号

#define REG_AX_TYPE_REQ		60	//轴控制模式切换请求，2为手轮中断，3为PMC模式

#define REG_AX_PMC_RATIO	61	//PMC轴修调
#define REG_AX_CTRL2		62	//轴控制字2
	#define AX_CTRL2_PMC_STOP		0x0001	//PMC轴停止
	#define AX_CTRL2_EXT_CLEAR		0x0002	//手轮中断量清零
	#define AX_CTRL2_TANG			0x0004	//开启切线控制功能
	#define AX_TURNOFF_SWITCH		0x0010	//分度轴开关
    #define AX_FREE_SLAVE_SYNC		0x0020	//从轴耦合恢复时，同步同步轴的位置
	#define AX_CTRL2_SYNC11			0x0040	//控制模式为11的同步轴开始同步
	#define AX_CTRL2_SYNC_RESIDENT	0x0080	//控制模式为11的同步轴驻留
	#define AX_CTRL2_SPDL_CTRL		0x0100	//主轴控制，将主轴实际转速写到指令中，用于双速电机
    #define AX_SHIFT_SPEED  0x0200//启动主轴换挡转速

#define REG_AX_PID_CTRL		63	//PID控制指令
	#define REG_AX_PID_DEM_CMD	0x0001	//PID轴标定开始
	#define REG_AX_PID_DEM_SW	0x0002	//PID轴触板信号
	#define REG_AX_PID_POS_SW	0x0004	//PID位置保护，无效时PID轴位置模式，下降到砰板信号有效时，禁止下降

#define REG_AX_SHELF_CUR	64	//轴当前档位

#define REG_AX_EXT_LOAD		65	// 外部导入的负载（沈飞）

#define REG_AX_ACT_PULSE1	66	//多档时，使用的轴反馈脉冲位置，脉冲单位，当前位置对每档脉冲数取余，得到寄存器12
#define REG_AX_ACT_PULSE1_2	67

#define REG_AX_Z_POS		68//Z脉冲位置
#define REG_AX_Z_POS_		69
#define REG_AX_Z_SPACE1		70//Z脉冲间距1
#define REG_AX_Z_SPACE1_	71
#define REG_AX_Z_SPACE2		72//Z脉冲间距2
#define REG_AX_Z_SPACE2_	73

#define REG_AX_DIVSOR		74//循环清零的公约数
#define REG_COMP_CYCLE		75//前馈补偿提前周期

#define REG_AX_SAMP_DATA0	78	//伺服采样数据
#define REG_AX_SAMP_DATA1	79

//通道状态寄存器
//REG_CHAN_BASE+i*CHAN_REG_NUM 
#define REG_CH_STATE 0 //通道状态字0
		//最低4位0~7 当前工作模式	
		#define	CH_MODE_RESET	0
		#define	CH_MODE_AUTO	1
		#define	CH_MODE_JOG		2
		#define	CH_MODE_STEP	3
		#define	CH_MODE_MPG		4
		#define	CH_MODE_HOME	5
		#define	CH_MODE_PMC		6 
#ifdef _MCPMDI // MCP面板切换MDI方式
		#define CH_MODE_MDI	7

	#define CH_STATE_SBL		0x0008
#else
		#define CH_MODE_SBL		7

	#define CH_STATE_MDI		0x0008
#endif

	#define  CH_AUTO_MASK	0x00F0
	#define CH_STATE_HOLDING	0x0010
	#define CH_STATE_CYCLING	0x0020 //自动运行中
	#define CH_STATE_MOVING		0x0040 //非自动时有运动
	#define CH_STATE_INTERVEN	0x0080 //有运动的用户干预中
	
	#define CH_STATE_CUTTING	0x0100
	#define CH_STATE_THREADING	0x0200
	#define CH_STATE_PARKING	0x0400
	#define CH_STATE_VERIFYING	0x0800

	#define CH_STATE_HMI_RST	0x1000 //上层复位	
	#define CH_STATE_PAUSE_REQ	0x2000 //暂停请求
	#define CH_STATE_RESETING	0x4000 //复位中
	#define CH_STATE_HOMING		0x8000 //通道内有轴回零找Z脉冲，禁止切换模式

#define REG_CH_STAT1 1 //通道状态字1 [工位关联]
	#define CH_STATE_PROGSEL	0x0001 //程序选中：译码器置
	#define CH_STATE_TRYSTART	0x0002 //程序启动：通道控制置
	#define CH_STATE_PROGEND	0x0004 //程序完成：通道控制置
	#define CH_STATE_IRQ_FIN	0x0008 //G28/G31等中断指令完成
	#define CH_STATE_IRQ_SKIP	0x0010 //中断指令跳过
	#define CH_STATE_WAIT_FIN	0x0020 //等待指令完成
	#define CH_STATE_REWINDED	0x0040 //程序重运行复位
	#define CH_STATE_SBL_FIN	0x0080 //单段运行完成

	#define CH_STATE_BP_LOAD	0x0100	//通道加载断点
	#define CH_STATE_AX_UPDT	0x0200	//通道有轴更新位置（如解除锁住）
	#define CH_STATE_FLUSH2		0x0400	//通道清除缓冲到运行段
	#define CH_STATE_S_RESET	0x0800	//通道有主轴复位为主轴

	#define CH_STATE_IRQ_WAIT	0x1000	//等待中断点响应
	#define CH_RTCP_ON			0x2000	//RTCP功能开启
	//#define CH_STATE_S_FLUCT	0x2000  //主轴波动已开启
	#define CH_STATE_FLUSHING	0x4000  //
    #define CH_TAX_VCS          0x8000  //斜轴功能开启

#define REG_CH_MSTB_CMD 2 //通道MST指令字
	#define CH_MSTB_MMASK	0x00FF //MAX_MPER_ROW【4或8】个M指令
	#define CH_MSTB_TBMASK	0x0500 //TB掩码
	#define CH_MSTB_TFLAG	0x0100  //选刀标记
	#define CH_MSTB_TOFFS	0x0200	//刀偏标记[T中含刀偏号]
	#define CH_MSTB_INDEX	0x0400  //有分度轴指令标记
	#define CH_MSTB_G96		0x0800	//主轴恒线 速
	#define CH_MSTB_SMASK	0xF000 //4个S指令
	#define CH_MSTB_S1FLAG	0x1000 //第1个S指令
	#define CH_MSTB_S2FLAG	0x2000 //第2个S指令
	#define CH_MSTB_S3FLAG	0x4000 //第3个S指令
	#define CH_MSTB_S4FLAG	0x8000 //第4个S指令

	//这两 不是Reg 序号	
	#define CH_MSTB_SSTART	12 //S标志的起始位数

#define REG_CH_OUT_FLAG		4	//4~7 输出给PLC的通道标志
								//8保留					

#define REG_CH_T_OFFS  9 //9 T刀偏号 16位
#define REG_CH_S_CODE 10 //10~17 通道主轴S指令，4个主轴。单位r/min

#define REG_CH_G31WAIT_IDX	18 //当前等待信号的G31编号
#define REG_CH_RUN_CRDS		20 //当前运行的坐标系
#define REG_CH_AXES_IDX		21 //21~29  通道轴号
#define REG_CH_SPDL_IDX		30 //30~33  通道主轴号
#define REG_CH_ERR_SYNTAX	34 //34~35  语法错报警号
#define REG_CH_ERR_FLAG		36 //36~39  通道报警字 64个通道报警
#define REG_CH_NOTE_FLAG	40 //40~43  通道提示信息标志 定义在 syserr.h
#define REG_CH_USER_OUT		44 //44~47  用户输出
#define REG_CH_M_COMMAND	48 //通道M指令，可同时执行8个M指令
#define REG_CH_T_COMMAND	56 //T刀具号 16位 
#define REG_CH_B_COMMAND	57 //镗床B轴PLC执行,另外分度用B指令
#define	REG_CH_T_READY		58 //当前准备好交换的刀具
#define REG_CH_DA_OUT		60 //60~68  用户数值输出 
#define REG_CH_FLUSH_STEP	70	//内部复位步骤
#define REG_CH_RESET_STEP	71	//外部复位步骤
#define REG_CH_ALARM_TOOL	72 // 报警的刀具号
#define REG_CH_FILTER_WIDTH	73 // 通道当前指令滤波宽度
#define REG_CH_HANDLE_BUF   74  //wx,手轮试切缓存
#define REG_CH_HANDLE_RATIO 75  //wx,手轮试切倍率，生效时代替进给修调和快移修调
#define REG_CH_STAT2        76 // 通道状态字2
	#define CH_STATE_RESET	    0x0001  //通道复位
    #define CH_STATE_STOP_CHECK 0x0002  //程序准停到位
    #define CH_STATE_TAX_VCS    0x0004  //上个周期的斜轴标志，在进行斜轴的手轮中断时使用
	#define CH_STATE_G0         0x0008  //通道运行插补指令
	#define CH_STATE_SPDL_SYNC  0x0010  //主轴同步标记
	#define CH_STATE_HANDLE_DIR	0x0020	//手轮进给方向

#define REG_CH_PROG_FLOW		77	//子程序调用流程
    #define CH_PROG_FLOW_GO	    0x0001	//子程序流程开始
    #define CH_PROG_FLOW_WAIT	0x0002	//子程序等待进给保持，保存断点
    #define CH_PROG_FLOW_FLAG	0x0004	//断点标志
    #define CH_PROG_FLOW_LOAD	0x0008	//开始加载子程序
    #define CH_PROG_FLOW_LOADOK	0x0010	//加载完成
    #define CH_PROG_FLOW_RUN	0x0020	//开始运行
    #define CH_PROG_FLOW_RUNOK	0x0040	//运行完成
    #define CH_PROG_FLOW_RESUME	0x0080	//断点恢复完成
    #define CH_PROG_FLOW_FINISH	0x0100	//流程结束
    #define CH_PROG_FLOW_ERR	0x0200	//流程错误
    #define CH_PROG_FLOW_RESET  0x0400  //流程复位
	#define CH_PROG_FLOW_DCD_OK 0X0800  //流程等待解释器复位完成
	#define CH_PROG_FLOW_MASK   0X0FFF
#define REG_CH_LIFE             78  //刀具寿命
    #define REG_CH_LIFE_COUNT	0x0001	//刀具寿命换刀累加标记

//通道控制寄存器
//REG_CHAN_BASE+i*CHAN_REG_NUM 
#define REG_CH_CTRL 0 //通道控制字
	#define CH_MODE_MASK		0x0007
//		#define	CH_MODE_RESET	0
//		#define	CH_MODE_AUTO	1
//		#define	CH_MODE_JOG		2
//		#define	CH_MODE_STEP	3
//		#define	CH_MODE_MPG		4
//		#define	CH_MODE_HOME	5
//		#define	CH_MODE_PMC		6
//		#define CH_MODE_SBL		7
	
	#define CH_CTRL_HOLD_SW		0x0010
	#define CH_CTRL_CYCLE_SW	0x0020
	#define CH_CTRL_DRY_RUN		0x0040
	#define CH_CTRL_ESC_SW		0x0080	//测量中断

	#define CH_CTRL_VERIFY	0x0100  //校验
	#define CH_CTRL_RST_ACK	0x0200  //PLC对NC复位的应答	
	#define CH_CTRL_HMI_RST	0x0400	//内部复位[用户界面置]
	#define CH_CTRL_ESTOP	0x0800	//ESTOP

	#define CH_CTRL_FLUSH	0x1000	//清通道缓冲  
	#define CH_CTRL_RESET	0x2000	//复位通道【外部】
	#define CH_CTRL_RESUME	0x4000	//通道数据恢复
	#define CH_CTRL_SAVE	0x8000	//通道数据保存

#define CH_CTRL_PROC_MSK	0xFF00 //通道处理标志码
	
#define REG_CH_CTRL1 1 //解释器控制字
	#define CH_CTRL_PRG_RUN	0x0001 //解释器启动
	#define CH_CTRL_PRGRWD2	0x0002 //程序重新运行第2步
	#define CH_CTRL_SKIP	0x0004	//跳段
	#define CH_CTRL_SELSTP	0x0008	//选择停
	#define CH_CTRL_DCD_RST	0x0010 //解释器复位
	#define CH_CTRL_PRG_RWD	0x0020 //程序重新运行
	#define CH_CTRL_RUN_ROW	0x0040 //程序任意行运行
	#define CH_CTRL_RESUME2	0x0080 //解释器数据恢复
	#define CH_CTRL_SAVE2	0x0100 //解释器数据保存
	#define CH_CTRL_STOPCHK	0x0200	//准停检查
	#define CH_CTRL_USER_MC	0x0400  //用户运动控制
	#define CH_CTRL_IRQ		0x0800	//外部中断	
	#define CH_CTRL_MPG_INTER	0x1000//开启手轮中断
	#define CH_CTRL_OVERRIDE    0x2000  //快移修调为0时,用进给修调控制g00,最高25%
	#define CH_CTRL_CHG_PRG	    0x4000	//程序修改标志
	#define CH_CTRL_WT_CHG	    0x8000	//工件或工具坐标变化，请求重新解释【HMI置】

#define CH_DCD_PROC_MSK		0x81F0 //解释器处理标志码

#define REG_CH_MSTB_CTRL 2 //通道MST指令应答字
	//#define CH_MSTB_M_ACK	0x00FF
    #define CH_S1CODE_ACK   0x0001  //第一个S指令应答
    #define CH_S2CODE_ACK   0x0002  //第二个S指令应答
    #define CH_S3CODE_ACK   0x0004  //第三个S指令应答
    #define CH_S4CODE_ACK   0x0008  //第四个S指令应答
    #define CH_SCODE_MASK   0x000F     //S指令应答掩码
	#define CH_MSTB_HANDLE_BACK   0x0100  //  进给方向，0为前进，1为后退
	#define CH_MSTB_FROG_ON		  0x0200 //蛙跳控制开
	#define CH_MSTB_SPDL_CHK	  0x0400 //主轴速度检查
	#define CH_MSTB_LOCK		  0x0800
	#define CH_MSTB_SP_NORUN	  0x1000 //主轴未启动
	#define CH_MSTB_SP_NOTOK	  0x2000 //主轴转速未到达
	#define CH_MSTB_FOLLOW_ON	  0x4000 //跟随控制开启
    #define CH_MSTB_HANDLE_ON     0x8000  //  手轮倍率    

#define REG_CH_TOOL_USING	3 //T指令
#define REG_CH_FEED_RATIO	4 //进给修调
#define REG_CH_RAPID_RATIO	5 //快移修调
#define REG_CH_SPDL_RATIO	6 //6~9主轴1、2、3、4修调
#define REG_CH_SPDL_VALUE	10 //10~17主轴输出指令【PLC根据F中的s做换挡处理后给G】

#define REG_CH_MANUAL_CTRL	18   //手动控制字
	#define	REG_CH_WCS_CTRL		0x0001  //工件坐标系控制
	#define REG_CH_VCS_CTRL		0x0002  //虚轴坐标系控制
	#define TOOL_ROBOT_CTRL     0X0004  //1ms调用一次pos_vir_to_real
	#define REG_CH_TOOL_CTRL	0x0300 	//刀具坐标系控制
	#define TOOL_CTRL_INIT		0x0100		//刀具坐标系控制初始化
	#define TOOL_CTRL_RUN		0x0200		//刀具坐标系控制运行

#define REG_CH_PART_CNTR	19 //19 加工计件
#define REG_CH_IN_FBD_MASK	20 //内禁止掩码
#define REG_CH_EX_FBD_MASK	21 //外禁止掩码
#define REG_CH_ESC_IDX		22 //22 测量中断时G31的编号
#define REG_CH_PART_NEED	23 //加工需求
#define REG_CH_USER_IN		24 //24~27 用户位输入，
#define REG_CH_AD_IN		28 //28~47 用户数值输入，
#define REG_CH_MCODE_ACK	48
#define REG_CH_TCODE_ACK	56 
#define REG_CH_FOLLOW_TYPE	57 //旋转轴跟随控制类型 
	#define FLAG6_AX_FOLLOW_MASK	0x00FF//轴跟随掩码  
	#define FLAG6_TOOL_TANGENT_FOLLOW	1	//刀具切线跟随
	#define FLAG6_TABLE_TANGENT_FOLLOW	2	//工作台切线跟随
	#define	FLAG6_TOOL_CHORD_FOLLOW		11	//刀具弦线跟随
	#define FLAG6_TABLE_CHORD_FOLLOW	12	//工作台弦线跟随
	#define FLAG6_CH_FOLLOW_MASK	0xFF00//通道/合成量跟随掩码
	#define FLAG6_CH_FOLLOW1	0x0100//螺纹类跟随
	#define FLAG6_CH_FOLLOW2	0x0200//直接跟随
	#define FLAG6_CH_FOLLOW3	0x0300//	

#define REG_CH_IN_CTRL		60 //60~67 PLC输入给通道的控制字

#define REG_CH_SPDL_CMD		68 //68~75主轴输出指令转数，根据他与实际转数的偏差检测主轴波动
#define REG_CH_CTRL2        76 //通道控制字2
	#define CH_CTRL_RESET_START	0x0001 //通道复位【PLC置寄存器，通知HMI进行通道复位】
    #define CH_CTRL_READ_STOP   0x0002  //读入禁止，为1时，程序等待，为0时，程序继续运行
	#define CH_CTRL_RE_DECODE   0X0004 //通道重新解释
	#define CH_CTRL_IRQ2        0X0008 // IRQ控制
	#define CH_CTRL_RESET_FORBID      0X0010 // 通道禁止复位【Reset按键无效】
	#define CH_CTRL_LIFE_STOP 0X0020	//寿命计时/计数暂停
	#define CH_CTRL_EV_LOAD_PROG_FAIL 0X0040	// PLC事件载入程序失败标记【HMI使用】
    #define CH_CTRL_DCD_HAVE_BACKUP 0X0080      //内核数据已备份
    #define CH_CTRL_DCD_BACKUP 0X0100           //自动执行程序时，调用手动子程序，备份解释器
    #define CH_CTRL_DCD_RESUME 0X0200           //恢复之前备份的解释器数据
    #define CH_CTRL_JOG_PROG_AUTO_SBL_HOLDING 0X0400 //自动/单段状态时调用手动子程序的进给保持
	#define CH_CTRL_IS_RIGID 0X0800	// 刚性攻丝标志
    #define CH_CTRL_SPDL_TURN 0X1000    // 主轴旋转标记
	#define CH_CTRL_ONLY_DECODER_RESET 0X2000    // 仅解释器复位，用于校验模式

#define REG_CH_PROG_RUN		77	//子程序调用
	#define CH_CTRL_PROG1	0x0001
	#define CH_CTRL_PROG2	0x0002
	#define CH_CTRL_PROG3	0x0004
	#define CH_CTRL_PROG4	0x0008
	#define CH_CTRL_PROG5	0x0010
	#define CH_CTRL_PROG6	0x0020
	#define CH_CTRL_PROG7	0x0040
	#define CH_CTRL_PROG8	0x0080
	#define CH_CTRL_PROG9	0x0100
	#define CH_CTRL_PROG10	0x0200
	#define CH_CTRL_PROG11	0x0400
	#define CH_CTRL_PROG12	0x0800
	#define CH_CTRL_PROG13	0x1000
	#define CH_CTRL_PROG14	0x2000
	#define CH_CTRL_PROG15	0x4000
	#define CH_CTRL_PROG16	0x8000

#define REG_CH_PRE_TOOL		78  // PLC预选刀
#define REG_CH_TOOL_TIMES	79  // 换刀计数次数

//系统状态寄存器
#define SYS_NC_STATE	0 //系统状态字
	#define SYS_STATUS_ON	0x0001
	#define SYS_PLC_ONOFF	0x0002 //1运行 0停止
	#define SYS_FLAG_ESTOP	0x0004
	#define SYS_FLAG_RESET	0x0008

	#define SYS_FLAG_POWERDOWN	0x0010 //断电中
	#define SYS_FLAG_SAVINGDATA	0x0020 //保存数据中
	#define SYS_FLAG_SYNCHRO	0x0040 //扫描模式的同步状态
	#define SYS_FLAG_SUSPEND	0x0080 //挂起

	#define SYS_SAMPLE_ON	0x0100 //采样状态标记
	#define SYS_SAMPLE_FIN	0x0200 //采样结束标志
	#define SYS_SERVO_ADJUST_ON	0x0400 //伺服调整功能开
	#define SYS_NET_PROTECT	0x0800	//网络断开保护

	#define SYS_UPS_ACFAIL	0x1000 //UPS断电保护触发标志
	#define SYS_FORBID_RUN	0x2000 //系统禁止循环启动标志
	#define SYS_RESET_KEY	0x4000 //系统Reset按键复位
	#define SYS_INIT_FIN	0x8000 //轴参数准备好，轴参数未准备好时，请急停

#define SYS_NC_CHMSK	1 //通道屏蔽状态字

#define BUS_BOARD_FLAG	2 //2~3 预留2个总线通讯状态字
	#define BUS_FLAG_IDLE     0x0000	//空闲中
	#define BUS_FLAG_RESETING 0x0001	//复位中
	#define BUS_FLAG_PROBING  0x0002	//侦测中
	#define BUS_FLAG_SORTING  0x0004	//编址中
	#define BUS_FLAG_READING  0x0008	//读控制对象数据中
	#define BUS_FLAG_NETOK    0x0010	//网络OK
	#define BUS_FLAG_MAPPING  0x0020	//建立映射中
	#define BUS_FLAG_READY    0x0040	//总线准备好
	#define BUS_FLAG_RUN      0x0080	//通讯运行

#define BUS_NET_ASYN_ERR_CNT	4 //总线通讯非周期数据累计丢包计数
#define BUS_NET_SYNC_UNSENT_CNT 5 //总线通讯周期数据未成功发送计数
#define BUS_NET_SYNC_ERR_CNT	6 //总线通讯周期数据累计丢包计数
#define BUS_NET_SYNC_ERR_SEQ	8 //总线通讯周期数据连续丢包计数

#define BUS_BOARD_ALARM 10 //10~13 预留4个总线通讯报警字
	//NET
	#define BUS_ALARM_NET_UNOK      0x0001 //总线连接不正常
	#define BUS_ECAT_INIT_FAILED		0x0002 //ECAT主站初始化失败
	#define BUS_ALARM_NET_CRC_ERR   0x0004 //总线数据帧校验错误
	#define BUS_ECAT_CONF_BREAK		0x0008	//ECAT配置文件读取失败
	#define BUS_ECAT_SLV_NUM_UNMAT	0x0010	//ECAT配置文件中设备数目与实际不符
	//SLV 
	#define BUS_ALARM_SLV_UNREG     0x0020 //总线从站设备无法识别
	#define BUS_ALARM_SLV_CFG_ERR   0x0080 //总线从站模式配置出错
	//SV
	#define BUS_ALARM_SV_PARA_CHECK 0x0100 //校验伺服参数出错
	#define BUS_ALARM_SV_PARA_READ  0x0200 //读取伺服参数失败
	#define BUS_ALARM_SV_PARA_WRITE 0x0400 //设置伺服参数失败
	#define BUS_ALARM_SV_PARA_SAVE  0x0800 //保存伺服参数失败
	#define BUS_ALARM_SV_PARA_DFT   0x1000 //恢复伺服参数失败

#define BUS_ALARM_NET_CRC_ERR_PART 14//总线数据帧校验错误计数
#define SYS_HMI_ALARM_ERR1			15 // HMI相关报警1（ERR）
	#define SYS_HMI_ERR_TOOL_FILE_LOAD_FALSE	(0x0001)	// 刀具文件载入失败
	#define SYS_HMI_ERR_BREG_FILE_LOAD_FALSE	(0x0002)	// B寄存器文件载入失败
	#define SYS_HMI_ERR_PARM_FILE_LOAD_FALSE1	(0x0004)	// 上次保存参数文件有异常,请核实参数数据
	#define SYS_HMI_ERR_PARM_FILE_LOAD_FALSE2	(0x0008)	// 参数文件载入失败

	#define SYS_HMI_ERR_UPS_ERR					(0x0010)	// 上次断电数据保存失效,请检查UPS电源
	#define SYS_HMI_ERR_PROG_INIT_FALSE			(0x0020)	// 程序管理器初始化失败
	#define SYS_HMI_ERR_PLC_INIT_FALSE			(0x0040)	// PLC文件载入失败
	#define SYS_HMI_ERR_ALARM_INIT_FALSE		(0x0080)	// 报警模块初始化失败

	#define SYS_HMI_ERR_CRD_FILE_LOAD_FALSE1	(0x0100)	// 上次保存坐标系文件有异常,请核实坐标系数据
	#define SYS_HMI_ERR_CRD_FILE_LOAD_FALSE2	(0x0200)	// 坐标系文件载入失败
	#define SYS_HMI_ERR_GUI_INIT_FALSE			(0x0400)	// 界面控件初始化失败
	#define SYS_HMI_ERR_REG_NO					(0x0800)	// 系统未注册

	#define SYS_HMI_ERR_REG_OVER_TIME			(0x1000)	// 系统注册超期
	#define SYS_HMI_ERR_HANDLE_FALSE			(0x2000)	// 串口初始化失败
	#define SYS_HMI_ERR_POS_UPS_FALSE			(0x4000)	// 上次断电异常,加载了过期的位置文件,请核实坐标位置
	#define SYS_HMI_ERR_POS_FILE_FALSE			(0x8000)	// 位置文件加载失败,请核实坐标位置

#define SYS_HMI_ALARM_ERR2			16 // HMI相关报警2（ERR）

#define SYS_THREAD_SYNC_FLAG     17   //中断与系统控制任务的同步控制
#define SYS_ACTIVE_CHAN		18  //系统活动通道编号
#define SYS_NO_HEART_CNTS	19  //无插补心跳计数

#define SYS_MPG_COUNTS	20	//20~39手摇编码器周期计数增量
#define SYS_MPG_FLAG	40	//40~49手摇编码器的标志【输入】
	#define MPG_FLAG_ACTIVE	0x0100 //手摇准备好标志【手摇与步进共用模式选择开关时有效】
	#define MPG_FLAG_VALID	0x0200 //手摇有效

	#define MPG_FLAG_MUL_MSK 0x000F //手摇倍率掩码【对特定总线手摇生效】
	#define MPG_FLAG_AX_MSK	 0x00F0 //手摇轴选掩码【对特定总线手摇生效】

#define SYS_RANDOM_RESTART	41	//一键偏置步骤记录

#define SYS_PLC_STATUS		76	//16bits
	#define PLC_SYS_PLC_ONLINE		0x0001	//PLC在线调试
//mark7 trunck版本专用，合并代码时不检查此部分
#	define SYS_PLC2_CUR_CYCLE 77	//PLC2当前周期16bits
#	define SYS_PLC2_MIN_CYCLE 78	//PLC2最小周期16bits
#	define SYS_PLC2_MAX_CYCLE 79	//PLC2最大周期16bits
//end of mark7
#define SYS_NCKB_FLAG	80 //NC键盘的标志
#define SYS_HMI_ALARM_MSG	81 // HMI相关报警（MSG）
    #define SYS_HMI_MSG_DISK_FULL		0x0001	//系统盘空间满
	#define SYS_HMI_MSG_REG_WARNING		0x0002	//注册到期预警
	#define SYS_HMI_MSG_LACK_BMP		0x0004	//系统缺少图片

#define SYS_NCKB_KEY	82 //82~89,8个NC键盘的键值

//#define SYS_SAMPLE_IDX		98	//采样下标
//#define SYS_SAMPLE_LMT		100 //采样截止条件 -1 信号截止；0 循环采样； 1~32766：个数
//#define SYS_SAMPLE_CHN		101 //采样通道数
//高8位：物理设备号，
//低8位：采样类型 1 指令 2 实际 3 误差 4 指令速度 5 实际速度 6 负载电流
//#define SYS_SAMPLE_FLAG		102 //102~117 16个采样通道的标记，

#define	SYS_SYNC_RDY_IDX	118	//系统与驱动程序间同步缓冲的下标[插补器心跳]
#define SYS_SYNC_OUT_IDX	119	//[位控/设备驱动心跳]

#define SYS_NCK_VERSION		120 //NCK版本号
#define SYS_PLC_VERSION		122 //PLC版本号
#define SYS_DRV_VERSION		124 //DRV版本号：XX-XX-XX-XX 年-月-日-序号
#define SYS_CNC_VERSION		126 //CNC版本号

#define SYS_LAST_IIP_HEART		128 //插补心跳暂存
#define SYS_USER_RIGHT_LEVEL	129 // 用户权限等级
#define SYS_NCK_DEBUG		130

#define SYS_CNC_SAFETY_CNTR	140 // CNC安全计数器
#define SYS_HEART_BEAT		149 //系统心跳计数

#define SYS_NC_STATE1   150//系统状态字1
    #define SYS_FLAG_MCP_RESET  0x0001
	#define SYS_TOOL_TEST_START	0x0002	//(玻璃机增加)
	#define SYS_WCS_HOME		0x0004	//(玻璃机增加)

#define SYS_PRE_INT_VERSION		151	// 151 插补前预处理版本
#define SYS_NCK_SVN_VERSION		152	// 152~153 NCK版本号
#define SYS_PLC_SVN_VERSION		154 // 154~155 PLC版本号
#define SYS_DRV_SVN_VERSION		156 // 156~157 DRV版本号
#define SYS_CNC_SVN_VERSION		158 // 158~159 CNC版本号

//系统控制寄存器
#define SYS_NC_CTRL		0 //系统控制字
	#define SYS_CTRL_INIT		0x0001
	#define SYS_CTRL_EXIT		0x0002
	#define SYS_CTRL_ESTOP		0x0004 //外部急停
	#define SYS_CTRL_RESET		0x0008 //外部复位
	#define SYS_CTRL_POWEROFF	0x0010 //停电通知
	#define SYS_CTRL_SAVEDATA	0x0020 //数据保存通知
	#define SYS_CTRL_KEY		0x0040 // MCP面板的钥匙开关
	#define SYS_CTRL_SUSPEND	0x0080 //挂起

	#define SYS_CTRL_DIS_CHLMT	0x0100 //软限位预判取消
	#define SYS_CTRL_KILL_IIP	0x0200 //杀死插补线程【仅仅限于调试版本】
	#define SYS_CTRL_KILL_PLC	0x0400 //杀死PLC线程【仅仅限于调试版本】
    #define SYS_CTRL_MCP_RESET	0x0800 //外部面板复位

	#define SYS_CTRL_SAMPLE_EN		0x1000 //采样使能标记
	#define SYS_CTRL_SAMPLE_TRI_EN	0x2000 //采样触发时能标记
	#define SYS_CTRL_SMPL_HMI_EN	0x4000 //采样使能标记
	#define SYS_CTRL_SMPL_HMI_OFF	0x8000 //采样关闭标记

#define SYS_NC_MSK_REQ	1 //通道屏蔽请求字

#define BUS_BOARD_CTRL	2 //2~9 预留8个控制主站的控制字
	#define BUS_CTRL_INIT	0x0001	//初始化
	#define BUS_CTRL_RESET	0x0002	//复位
	#define BUS_CTRL_PROBE	0x0004	//侦测
	#define BUS_CTRL_SORT	0x0008	//编址
	#define BUS_CTRL_READ	0x0010	//读控制对象数据
	#define BUS_CTRL_MAP	0x0020	//BUS-NC数据地址映射
	#define BUS_CTRL_DISCONNECT	0x0040	//断开连接
	#define BUS_CTRL_RUN	0x0080	//运行

#define SYS_ACTCHN_REQ	18  //系统活动通道请求

#define SYS_RIGHTS_KEY	19  // 权限钥匙锁
#define SYS_MPG_CTRL	20	//20~29手摇的控制字【上一个轴选】
#define SYS_MPG_DISPLAY	30	//30~49手摇的显示输出

#define SYS_PLC_ALARM	50 //50~65 PLC外部报警，同时可有8*32=256种PLC外部报警
#define SYS_PLC_EVENT	80 //80~95 PLC外部事件，同时可有8*32=256种PLC外部事件
#define SYS_PLC_NOTE	96 //96~119 PLC外部提示信息标志，同时可有12*32种PLC提示信息 MC通道占用的定义在 syserr.h

#define SYS_HEAT_SENSOR 120 //120~139 温度传感器值 
#define SYS_PROBE_STAMP	140	//140~149 测头时间戳

#define SYS_RFID_RW_CTRL		150 // RFID读写控制
		#define RFID_1_RW_ON		0x0001 // 1号RFID读写标签启动
		#define RFID_2_RW_ON		0x0002 // 2号RFID读写标签启动
		#define RFID_3_RW_ON		0x0004 // 3号RFID读写标签启动
		#define RFID_RW_FLAG		0x0010 // RFID读写标记
		#define RFID_RW_RESULT		0x0100 // RFID读写结果

#define SYS_RFID_RW_TOOL_NO		151 // RFID读写刀具号
#define SYS_RFID_RW_CFG1		152 // RFID读写配置1(低16位)
#define SYS_RFID_RW_CFG2		153 // RFID读写配置2(高16位)

#define SYS_STATE_CTRL 154 
	#define IMPACT_DEFEND_STATE		0x0001 // 撞机保护状态
	#define MCP_LOCK_ON				0x0002 // MCP面板锁
//温度传感器最大接入个数
#define MAX_HEAT_SENSOR_NUM 20  
//mark8 trunck版本专用，合并代码时不检查此部分
//通道控制扩展寄存器
#define REG_CH_PROG_EXT_RUN		0	//子程序调用
	#define CH_CTRL_PROG17	0x0001
	#define CH_CTRL_PROG18	0x0002
	#define CH_CTRL_PROG19	0x0004
	#define CH_CTRL_PROG20	0x0008
	#define CH_CTRL_PROG21	0x0010
	#define CH_CTRL_PROG22	0x0020
	#define CH_CTRL_PROG23	0x0040
	#define CH_CTRL_PROG24	0x0080
	#define CH_CTRL_PROG25	0x0100
	#define CH_CTRL_PROG26	0x0200
	#define CH_CTRL_PROG27	0x0400
	#define CH_CTRL_PROG28	0x0800
	#define CH_CTRL_PROG29	0x1000
	#define CH_CTRL_PROG30	0x2000
	#define CH_CTRL_PROG31	0x4000
	#define CH_CTRL_PROG32	0x8000

#define REG_CH_PROG_EXT_RUN1		1	//子程序调用
	#define CH_CTRL_PROG33	0x0001
	#define CH_CTRL_PROG34	0x0002
	#define CH_CTRL_PROG35	0x0004
	#define CH_CTRL_PROG36	0x0008
	#define CH_CTRL_PROG37	0x0010
	#define CH_CTRL_PROG38	0x0020
	#define CH_CTRL_PROG39	0x0040
	#define CH_CTRL_PROG40	0x0080
	#define CH_CTRL_PROG41	0x0100
	#define CH_CTRL_PROG42	0x0200
	#define CH_CTRL_PROG43	0x0400
	#define CH_CTRL_PROG44	0x0800
	#define CH_CTRL_PROG45	0x1000
	#define CH_CTRL_PROG46	0x2000
	#define CH_CTRL_PROG47	0x4000
	#define CH_CTRL_PROG48	0x8000

#define REG_CH_PROG_EXT_RUN2		2	//子程序调用
	#define CH_CTRL_PROG49	0x0001
	#define CH_CTRL_PROG50	0x0002
	#define CH_CTRL_PROG51	0x0004
	#define CH_CTRL_PROG52	0x0008
	#define CH_CTRL_PROG53	0x0010
	#define CH_CTRL_PROG54	0x0020
	#define CH_CTRL_PROG55	0x0040
	#define CH_CTRL_PROG56	0x0080
	#define CH_CTRL_PROG57	0x0100
	#define CH_CTRL_PROG58	0x0200
	#define CH_CTRL_PROG59	0x0400
	#define CH_CTRL_PROG60	0x0800
	#define CH_CTRL_PROG61	0x1000
	#define CH_CTRL_PROG62	0x2000
	#define CH_CTRL_PROG63	0x4000
	#define CH_CTRL_PROG64	0x8000
//end of mark8
//5 Device部分
enum _DEV_MODE_STATE
{
	DEV_STATE_IDLE,		//空闲
	DEV_STATE_PROBE,	//检测编址[侦测拓扑结构]
	DEV_STATE_CONFIG,	//配置模式
	DEV_STATE_IDENTIFY,	//辨识
	DEV_STATE_UPDATE,	//更新参数[从控制对象中读数据]
	DEV_STATE_CHECK,    //对比检查参数
	DEV_STATE_READY,	//就绪
	DEV_STATE_RESET,	//复位
	DEV_STATE_TEST,		//测试
	DEV_STATE_RCONF,	//重构
	DEV_STATE_RUN,		//运行
	DEV_STATE_FAULT,	//故障
	DEV_STATE_EXIT		//退出
};

//数控主控制板类型定义
enum _DEV_NCBRD_TYPE 
{
	DEV_NCBRD_NULL, //0
	DEV_NCBRD_5301,
	DEV_NCBRD_5311A,
	DEV_NCBRD_5311B,
	DEV_NCBRD_5311C,
	DEV_NCBRD_NCUC1, //5
	//此处扩展新的类型
	DEV_BRD_TYPE_NUM
};


#define MAX_MPER_ROW 4	//一行内的M代码数
#define MAX_POSG_ROW 4  //一行内的带参数的G代码数
#define MAX_GMDL_NUM 4	//一行内的最大模态G代码组数


//用于LINUX 用户态的命令调用
enum _USER_CALL_ID
{
	USER_NULL_CMD,
	USER_SYS_INIT,	//1
	USER_SYS_EXIT,	//2
	USER_SEL_PROG,	//3
	USER_SKIP_ROW,	//4
	USER_RUN_ROW,	//5
	USER_VERIFY,	//6
	USER_PROG_STOP,
	USER_PROG_RERUN,
	USER_CHAN_RESET,
	USER_SYS_RESET,	
	USER_MDI_OPEN,	
	USER_MDI_DECODE,
	USER_MDI_GOTO_BP,
	USER_MDI_CLOSE,
	USER_BUS_INIT=20,	//20 以下用于总线调试
	USER_BUS_RESET,	//21
	USER_BUS_PROBE,	//22
	USER_BUS_SORT,	//23
	USER_BUS_READ,	//24 读从站信息
	USER_BUS_MAP,	//25 BUS-NC数据地址映射
	USER_BUS_DISCONNECT,	//25
	USER_BUS_RUN,	//26
	USER_BUS_START,	//20
	USER_PLC_INIT,	// PLC初始化
	USER_DICT_RESET
};

// G代码模态组定义
enum 
{
	MODAL_G04_92 = 0,	
	MODAL_G00_03,	// 1
	MODAL_G17_19,	// 2
	MODAL_G24_25,	// 3
	MODAL_G50_51,	// 4
	MODAL_G68_69,	// 5
	MODAL_G71_82,	// 6
	MODAL_G11_12,	// 7
	MODAL_G20_22,	// 8
	MODAL_G41_42,	// 9
	MODAL_G43_44,	// 10
	MODAL_G54_59,	// 11
	MODAL_G61_64,	// 12
	MODAL_G90_91,	// 13
	MODAL_G94_95,	// 14
	MODAL_G98_99,	// 15
	MODAL_G15_16,	// 16 极坐标编程
	MODAL_G36_37,	// 17 
	MODAL_G12_13,	// 18 极坐标插补
	MODAL_G96_97,	// 19
	MODAL_G38_39,	// 20 同步标志开关
	MODAL_G38_39_,	// 20 同步标志开关2
	MODAL_G66_67,	// 22 模态调用 ?
	MODAL_G125_126, // 23 双码方式开启
	MODAL_G135_136, // 24 倾斜轴虚轴坐标系编程
	MODAL_G140_143,	// 25 定向插补类型
	MODAL_G128_129,	// 26 机器人变换开启与关闭
	MODAL_G05P1_Q,  //G05.1Q的值
	MODAL_G97_FLAG,   //G97的状态
	MODAL_G71_G73_FLAG,//G71-G73调用的标记
	
	TWIN_MDL_SPL = 60,	//副文件模态-样条

	FLAG_G15_16 = 70,	// 极坐标编程标识字
	FLAG_G71_82,		// 固定循环切换标识字
	FLAG_H_IDX,			// 长度补偿寄存器编号
	FLAG_D_IDX,			// 半径补偿寄存器编号
	FLAG_T_OFF,			// 模态刀偏号
	FLAG_INDEX_AX_MASK, //记录轴状态
	FLAG_CS,           //记录C/S切换轴，用于任意行
	FLAG_CYC_TYPE,     //记录固定循环类型
	FLAG_SYN_SPDL,     //记录同步主轴信息
	FLAG_G12_13_PLANE,  //记录G12的加工平面
	MAX_GGRP_NUM = 80	// 模态指令组数，Simens是近60组
};

#define A_CS_MASK 0X100
#define B_CS_MASK 0X80
#define C_CS_MASK 0X40

// #define DEFALUT_G04_92  	
#define DEFALUT_G00_03 1
// #define DEFALUT_G17_19 //根据机床类型
#define DEFALUT_G24_25 25
#define DEFALUT_G50_51 50
#define DEFALUT_G68_69 69
// #define DEFALUT_G71_82 //根据机床类型
// #define DEFALUT_G11_12 
#define DEFALUT_G20_22 21
#define DEFALUT_G41_42 40
#define DEFALUT_G43_44 49
#define DEFALUT_G54_59 54
// #define DEFALUT_G61_64 //根据机床类型
#define DEFALUT_G90_91 90
#define DEFALUT_G94_95 94
#define DEFALUT_G98_99 98
#define DEFALUT_G15_16 15
// #define DEFALUT_G36_37 //根据机床类型
#define DEFALUT_G12_13 13
#define DEFALUT_G96_97 97
// #define DEFALUT_G38_39 
// #define DEFALUT_G38_39_
// #define DEFALUT_G66_67
#define DEFALUT_G125_126 126
#define DEFALUT_G135_136 136
// #define DEFALUT_G140_143
#define DEFALUT_G128_129 129
#define DEFALUT_G05P1_Q 0
#define MAX_IDLE_SCAN_ROW_NUM 100

enum 
{
	FAST_VERIFY_NONE,
	FAST_VERIFY_START,
	FAST_VERIFY_WORKING,
	FAST_VERIFY_NO_CC_START,
	FAST_VERIFY_NO_CC_WORKING,
};
#endif
