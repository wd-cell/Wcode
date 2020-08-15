/*! 
 * @file hncparamandef.h
 * @brief ��������
 * @version V1.00
 * @date 2013/09/25
 * @author HNC-8 Team
 * @copyright �人�������عɷ����޹�˾
 */

#ifndef _HNC_PARAMAN_DEF_H_
#define _HNC_PARAMAN_DEF_H_

#include "hncdatatype.h"
#include "hncdatadef.h"

#define DATA_STRING_LEN (64)

#define  DEV_NCUC_AXIS 0
#define  DEV_ETHERCAT_AXIS 1
/*! 
 * @name ����ֵ
 * @{
 */
#define	PARA_FILE_OPEN_FAIL		(-1)	/*!<  �ļ���ʧ�� */
#define	PARA_FILE_SEEK_FAIL		(-2)	/*!<  �ļ�seekʧ�� */
#define	PARA_FILE_READ_FAIL		(-3)	/*!<  �ļ���ʧ�� */
#define	PARA_FILE_WRITE_FAIL	(-4)	/*!<  �ļ�дʧ�� */
#define	PARA_FILE_DATA_FAIL 	(-5)	/*!<  �ļ����ݴ��� */
#define	PARA_POINT_NULL_ERR 	(-6)	/*!<  ��ָ�� */
#define PARA_FILENO_ERR			(-7)	/*!<  ���������� */
#define PARA_SUBNO_ERR			(-8)	/*!<  �����Խ�� */
#define PARA_ROWNO_ERR			(-9)	/*!<  �к�Խ�� */
#define PARA_ROWXNO_ERR			(-10)	/*!<  ���к�Խ�� */
#define PARA_INDEX_ERR			(-11)	/*!<  ����Խ�� */
#define PARA_STRING_LIMIT		(-12)	/*!<  �ַ���̫�� */
#define PARA_PARMNO_ERR			(-13)	/*!<  ������Խ�� */
#define PARA_PARMANTYPE_ERR		(-14)	/*!<  �������ʹ��� */
#define PARM_MAPINDEX_ERR		(-15)	/*!<  ���������Ŵ�	 */
#define PARM_MAPROWNO_ERR		(-16)	/*!<  �����кŴ� */
#define PARM_SVWRITE_ERR        (-17)   /*!<  д�ŷ�����ʧ�� */
#define PARM_SVSAVE_ERR         (-18)    /*!<  �����ŷ�����ʧ�� */
#define PAEM_SVSTATE_ERR        (-19)    /*!<  ����ͨѶδ׼����,�޷�д���ŷ����� */
#define PAEM_SVRESET_ERR        (-20)    /*!<  ����δ�ɹ���λ */
#define PARM_XML_VERSION_ERR    (-21)    /*!<  �����ṹ�汾������ */
 #define PARM_EXPRESION_ERR      (-22)    /*!<  �������㹫ʽʧ�� */
/*!@}*/

/*!  ������������ */
enum ParaPropType
{
	PARA_PROP_VALUE,	/*!<  ����ֵ �����ṹ�ļ����� */
	PARA_PROP_MAXVALUE,	/*!<  ���ֵ �����ṹ�ļ����� */
	PARA_PROP_MINVALUE,	/*!<  ��Сֵ �����ṹ�ļ����� */
	PARA_PROP_DFVALUE,	/*!<  ȱʡֵ �����ṹ�ļ����� */
	PARA_PROP_NAME,		/*!<  ����  STRING */
	PARA_PROP_ACCESS,	/*!<  Ȩ��  INT */
	PARA_PROP_ACT,		/*!<  ��Ч��ʽ INT */
	PARA_PROP_STORE,	/*!<  �洢����  INT */
	PARA_PROP_ID,		/*!<  ������� INT */
	PARA_PROP_SIZE,		/*!<  ��С INT */
	PARA_PROP_RELATIONID /*!<  ��չ���� */
};

/*!  ������Ч��ʽö�ٶ��� */
enum ParaActType
{
	PARA_ACT_SAVE, /*!<  ������Ч */
	PARA_ACT_NOW,  /*!<  ������Ч */
	PARA_ACT_RST,  /*!<  ��λ��Ч */
	PARA_ACT_PWR,  /*!<  ������Ч */
	PARA_ACT_HIDE  /*!<  ����δ���� */
};


/*!  �������Զ��� */
enum ParaSubClassProp
{
	SUBCLASS_NAME,		/*!<  ������ */
	SUBCLASS_ROWNUM,	/*!<  �������� */
	SUBCLASS_NUM,		/*!<  ������ */
	SUBCLASS_MAXNUM     /*!< ������� */
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

/*!  �����ļ�ͷ */
typedef struct
{
	uBit32 HeadInfoSize;
	uBit32 MajorVersion;
	uBit32 MinorVersion; 
	uBit32 DataSize;
	uBit32 Chksum;
	Bit8 Userver[12]; /*!<  �û��汾�� */
} ParmFileHead;

#endif  //__HNC_PARA_MAN_DEF_H__