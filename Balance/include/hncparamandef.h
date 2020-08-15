/*! 
 * @file hncparamandef.h
 * @brief 参数管理
 * @version V1.00
 * @date 2013/09/25
 * @author HNC-8 Team
 * @copyright 武汉华中数控股份有限公司
 */

#ifndef _HNC_PARAMAN_DEF_H_
#define _HNC_PARAMAN_DEF_H_

#include "hncdatatype.h"
#include "hncdatadef.h"

#define DATA_STRING_LEN (64)

#define  DEV_NCUC_AXIS 0
#define  DEV_ETHERCAT_AXIS 1
/*! 
 * @name 返回值
 * @{
 */
#define	PARA_FILE_OPEN_FAIL		(-1)	/*!<  文件打开失败 */
#define	PARA_FILE_SEEK_FAIL		(-2)	/*!<  文件seek失败 */
#define	PARA_FILE_READ_FAIL		(-3)	/*!<  文件读失败 */
#define	PARA_FILE_WRITE_FAIL	(-4)	/*!<  文件写失败 */
#define	PARA_FILE_DATA_FAIL 	(-5)	/*!<  文件数据错误 */
#define	PARA_POINT_NULL_ERR 	(-6)	/*!<  空指针 */
#define PARA_FILENO_ERR			(-7)	/*!<  参数类别错误 */
#define PARA_SUBNO_ERR			(-8)	/*!<  子类号越界 */
#define PARA_ROWNO_ERR			(-9)	/*!<  行号越界 */
#define PARA_ROWXNO_ERR			(-10)	/*!<  总行号越界 */
#define PARA_INDEX_ERR			(-11)	/*!<  索引越界 */
#define PARA_STRING_LIMIT		(-12)	/*!<  字符串太长 */
#define PARA_PARMNO_ERR			(-13)	/*!<  参数号越界 */
#define PARA_PARMANTYPE_ERR		(-14)	/*!<  参数类型错误 */
#define PARM_MAPINDEX_ERR		(-15)	/*!<  参数索引号错	 */
#define PARM_MAPROWNO_ERR		(-16)	/*!<  参数行号错 */
#define PARM_SVWRITE_ERR        (-17)   /*!<  写伺服参数失败 */
#define PARM_SVSAVE_ERR         (-18)    /*!<  保存伺服参数失败 */
#define PAEM_SVSTATE_ERR        (-19)    /*!<  总线通讯未准备好,无法写入伺服参数 */
#define PAEM_SVRESET_ERR        (-20)    /*!<  总线未成功复位 */
#define PARM_XML_VERSION_ERR    (-21)    /*!<  参数结构版本不兼容 */
 #define PARM_EXPRESION_ERR      (-22)    /*!<  参数计算公式失败 */
/*!@}*/

/*!  参数属性类型 */
enum ParaPropType
{
	PARA_PROP_VALUE,	/*!<  参数值 参数结构文件定义 */
	PARA_PROP_MAXVALUE,	/*!<  最大值 参数结构文件定义 */
	PARA_PROP_MINVALUE,	/*!<  最小值 参数结构文件定义 */
	PARA_PROP_DFVALUE,	/*!<  缺省值 参数结构文件定义 */
	PARA_PROP_NAME,		/*!<  名字  STRING */
	PARA_PROP_ACCESS,	/*!<  权限  INT */
	PARA_PROP_ACT,		/*!<  生效方式 INT */
	PARA_PROP_STORE,	/*!<  存储类型  INT */
	PARA_PROP_ID,		/*!<  参数编号 INT */
	PARA_PROP_SIZE,		/*!<  大小 INT */
	PARA_PROP_RELATIONID /*!<  扩展参数 */
};

/*!  参数生效方式枚举定义 */
enum ParaActType
{
	PARA_ACT_SAVE, /*!<  保存生效 */
	PARA_ACT_NOW,  /*!<  立即生效 */
	PARA_ACT_RST,  /*!<  复位生效 */
	PARA_ACT_PWR,  /*!<  重启生效 */
	PARA_ACT_HIDE  /*!<  隐藏未启用 */
};


/*!  子类属性定义 */
enum ParaSubClassProp
{
	SUBCLASS_NAME,		/*!<  子类名 */
	SUBCLASS_ROWNUM,	/*!<  子类行数 */
	SUBCLASS_NUM,		/*!<  子类数 */
	SUBCLASS_MAXNUM     /*!< 最大行数 */
};

typedef struct
{
	Bit8 type;
	union
	{
		fBit64 val_real;
		uBit32 val_uint;
		Bit32  val_int;
		Bit8   val_string[DATA_STRING_LEN];
		Bit8   val_bool;
		Bit32  val_hex4;
		Bit8   val_byte[PARAM_STR_LEN];
	} value;
} SDataProperty;

/*!  参数文件头 */
typedef struct
{
	uBit32 HeadInfoSize;
	uBit32 MajorVersion;
	uBit32 MinorVersion; 
	uBit32 DataSize;
	uBit32 Chksum;
	Bit8 Userver[12]; /*!<  用户版本号 */
} ParmFileHead;

#endif  //__HNC_PARA_MAN_DEF_H__