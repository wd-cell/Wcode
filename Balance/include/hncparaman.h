/*! 
 * @file hncparaman.h
 * @brief ��������
 * @version V1.00
 * @date 2017/01/10
 * @author HNC-8 Team
 * @copyright �人�������عɷ����޹�˾���������
 */

#ifndef __HNC_PARA_MAN_H__
#define __HNC_PARA_MAN_H__

#include "hncparamandef.h"

/*!	@brief ������������ʼ��
 * 
 * @return 
 * -  0:�ɹ�;
 * - -1:�����ṹ�ļ�����ʧ��;
 * - -2:�ϴα�������ļ����쳣,���ʵ��������;
 * - -3:��������ʧ�ܣ�����Ĭ�ϲ���;
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
 * @endcode     

 * @see :: 
 */
extern Bit32  HNC_ParamanInit();

/*!	@brief �����������˳�
 * 
 * @return 
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   HNC_ParamanExit();
 * @endcode     

 * @see :: 
 */
extern void  HNC_ParamanExit();

/*!	@brief ���ز��������ļ�
 * 
 * @param [in] fileName :���������ļ�����
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - <0:ʧ�ܣ��μ�����ֵ˵����
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_ParamanLoad(fileName,clientNo);
 * @endcode     

 * @see :: ����ֵ˵�� hncparamandef.h
 */
HNCAPI Bit32 HNC_ParamanLoad(Bit8 *fileName, Bit16 clientNo = 0);

/*!	@brief ������������ļ�
 * 
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - <0:ʧ�ܣ��μ�����ֵ˵����
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_ParamanSave(clientNo);
 * @endcode     

 * @see :: ����ֵ˵�� hncparamandef.h
 */
HNCAPI Bit32 HNC_ParamanSave(Bit16 clientNo = 0);

/*!	@brief ���Ϊ���������ļ�
 * 
 * @param [in] lpFileName :���������ļ���
 * @param [in] clientNo   :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - <0:ʧ��;
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_ParamanSaveAs(lpFileName,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32  HNC_ParamanSaveAs(Bit8* lpFileName, Bit16 clientNo = 0);

/*!	@brief ��ȡ�������Ե�ֵ
 * 
 * @param [in] parmId     :�������
 * @param [in] propType   :�������Ե�����
 * @param [out] propValue :�������Ե�ֵ
 * @param [in] clientNo   :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - <0:ʧ�ܣ��μ�����ֵ˵����
 
 * @attention �������˵������ϸ˵���μ�������8������ϵͳ����˵���顷��
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_ParamanGetParaPropEx(parmId,propType,propValue,clientNo);
 * @endcode     

 * @see :: �������Ե����� ParaPropType ����ֵ˵�� hncparamandef.h
 */
HNCAPI Bit32 HNC_ParamanGetParaPropEx(Bit32 parmId, Bit8 propType, SDataProperty *propValue, Bit16 clientNo = 0);

/*!	@brief ���ò������Ե�ֵ����������ֵ�����ֵ����Сֵ��ȱʡֵ�����ƣ�
 * 
 * @param [in] parmId    :�������
 * @param [in] propType  :�������Ե�����
 * @param [in] propValue :�������Ե�ֵ
 * @param [in] clientNo  :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - <0:ʧ�ܣ��μ�����ֵ˵����
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_ParamanSetParaPropEx(parmId,propType,propValue,clientNo);
 * @endcode     

 * @see :: �������Ե����� ParaPropType ����ֵ˵�� hncparamandef.h
 */
HNCAPI Bit32 HNC_ParamanSetParaPropEx(Bit32 parmId, Bit8 propType, const SDataProperty *propValue, Bit16 clientNo = 0);

/*!	@brief ���ò�������ֵ,���԰���: ����ֵ�����ֵ����Сֵ��ȱʡֵ������
 * 
 * @param [in] filetype  :�������
 * @param [in] subid     :�����
 * @param [in] index     :����ƫ�Ƶ�ַ
 * @param [in] propType  :��������
 * @param [in] propValue :��������ֵ 
 * @param [in] clientNo  :�������Ӻ��������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - -1:ʧ��;
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_ParamanSetParaProp(filetype,subid,index,propType,propValue,clientNo);
 * @endcode     

 * @see :: �������Ե����� ParaPropType
 */
HNCAPI Bit32  HNC_ParamanSetParaProp(Bit32 filetype, Bit32 subid, Bit32 index,
							 Bit8 propType,const SDataProperty *propValue, Bit16 clientNo = 0);

/*!	@brief ��ȡ��������ֵ,���԰���: ����ֵ�����ֵ����Сֵ�� ȱʡֵ�����ơ�Ȩ�ޡ���Ч��ʽ����λ���ڴ��С
 * 
 * @param [in] filetype   :�������
 * @param [in] subid      :�����
 * @param [in] index      :����ƫ�Ƶ�ַ
 * @param [in] propType   :��������
 * @param [out] propValue :��������ֵ 
 * @param [in] clientNo   :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - -1:ʧ��;
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
    Bit32 ret = HNC_ParamanGetParaProp(filetyp,subid,index,propType,propValue,clientNo);
 * @endcode     

 * @see :: �������Ե����� ParaPropType
 */
HNCAPI Bit32  HNC_ParamanGetParaProp(Bit32 filetype, Bit32 subid, Bit32 index,
									 Bit8 propType, SDataProperty *propValue, Bit16 clientNo = 0);

/*!	@brief ��ȡ������������
 * 
 * @param [in] fileNo   :�������
 * @param [out] buf     :����
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - <0:ʧ�ܣ��μ�����ֵ˵����
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_ParamanGetFileName(fileNo,buf,clientNo);
 * @endcode     

 * @see ::  ����ֵ˵�� hncparamandef.h
 */
HNCAPI Bit32 HNC_ParamanGetFileName(Bit32 fileNo, Bit8 *buf, Bit16 clientNo = 0);

/*!	@brief ��ȡ�����������Ե�ֵ
 * 
 * @param [in] fileNo     :�������
 * @param [in] SubNo      :�����
 * @param [in] propType   :�������Ե�����
 * @param [out] propValue :�������Ե�ֵ
 * @param [in] clientNo   :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - <0:ʧ�ܣ��μ�����ֵ˵����
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_ParamanGetSubClassProp(fileNo,SubNo,propType,propValue,clientNo);
 * @endcode     

 * @see :: �������Ե����� ParaPropType ����ֵ˵�� hncparamandef.h
 */
HNCAPI Bit32 HNC_ParamanGetSubClassProp (Bit32 fileNo, Bit32 SubNo, Bit8 propType, SDataProperty *propValue, Bit16 clientNo = 0);

/*!	@brief ��ȡ���������б�����ʾ����
 * 
 * @param [out] rowNum  :������
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - <0:ʧ�ܣ��μ�����ֵ˵����
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_ParamanGetTotalRowNum(rowNum,clientNo);
 * @endcode     

 * @see ::  ����ֵ˵�� hncparamandef.h
 */
HNCAPI Bit32 HNC_ParamanGetTotalRowNum(Bit32 *rowNum, Bit16 clientNo = 0);

/*!	@brief ͨ�������������š��кŻ�ȡָ������������ֵ
 * 
 * @param [in] fileNo   :�������
 * @param [in] subNo    :�����
 * @param [in] rowNo    :�����к�
 * @param [out] index   :����������ֵ
 * @param [out] dupNum  :�����ظ�����
 * @param [out] dupNo   :�����ظ����
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - <0:ʧ�ܣ��μ�����ֵ˵����
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_ParamanTransRow2Index(fileNo,subNo,rowNo,index,dupNum,dupNo,clientNo);
 * @endcode     

 * @see ::  ����ֵ˵�� hncparamandef.h
 */
HNCAPI Bit32 HNC_ParamanTransRow2Index (Bit32 fileNo, Bit32 subNo, Bit32 rowNo, Bit32 *index, Bit16 *dupNum, Bit16 *dupNo, Bit16 clientNo = 0);

/*!	@brief ͨ���������������Ż�ȡ�����������ţ��Լ������к�
 * 
 * @param [in] rowx     :��������
 * @param [out] fileNo  :�������
 * @param [out] subNo   :�����
 * @param [out] row     :�����к�
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - <0:ʧ�ܣ��μ�����ֵ˵����
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_ParamanTransRowx2Row(rowx,fileNo,subNo,row,clientNo);
 * @endcode     

 * @see ::  ����ֵ˵�� hncparamandef.h
 */
HNCAPI Bit32 HNC_ParamanTransRowx2Row (Bit32 rowx, Bit32 *fileNo, Bit32 *subNo, Bit32 *row, Bit16 clientNo = 0);

/*!	@brief ͨ��������Ż�ȡ����������
 * 
 * @param [in] parmId   :�������
 * @param [out] rowx    :��������
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - <0:ʧ�ܣ��μ�����ֵ˵����
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_ParamanTransId2Rowx(parmId,rowx,clientNo);
 * @endcode     

 * @see ::  ����ֵ˵�� hncparamandef.h
 */
HNCAPI Bit32 HNC_ParamanTransId2Rowx(Bit32 parmId, Bit32 *rowx, Bit16 clientNo = 0);

/*!	@brief ���ز�������Ľṹ
 * 
 * @param [in] fileNo   :�������
 * @param [in] subNo    :�����
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - ��0:ʧ�ܣ��μ�����ֵ˵����
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_ParamanRewriteSubClass(fileNo,subNo,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_ParamanRewriteSubClass(Bit32 fileNo, Bit32 subNo, Bit16 clientNo = 0);

/*!	@brief ��������ṹ�ļ�
 * 
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - <0:ʧ�ܣ��μ�����ֵ˵����
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_ParamanSaveStrFile(clientNo);
 * @endcode     

 * @see ::  ����ֵ˵�� hncparamandef.h
 */
HNCAPI Bit32 HNC_ParamanSaveStrFile(Bit16 clientNo = 0);

/*!	@brief ��ȡ����ֵ
 * 
 * @param [in] fileno   :�������
 * @param [in] subno    :�����  
 * @param [in] index    :����
 * @param [out] value   :��������
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - <0:ʧ��;
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_ParamanGetI32(fileno,subno,index,value,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_ParamanGetI32(Bit32 fileno, Bit32 subno, Bit32 index, Bit32* value, Bit16 clientNo = 0);

/*!	@brief ���ò���ֵ
 * 
 * @param [in] fileno   :�������
 * @param [in] subno    :�����
 * @param [in] index    :����
 * @param [in] value    :��������
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - <0:ʧ��;

 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_ParamanSetI32(fileno,subno,index,value,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_ParamanSetI32(Bit32 fileno, Bit32 subno, Bit32 index, Bit32 value, Bit16 clientNo = 0);

/*!	@brief ��ȡ����ֵ
 * 
 * @param [in] fileno   :�������
 * @param [in] subno    :�����
 * @param [in] index    :����
 * @param [out] value   :��������  
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - <0:ʧ��;
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_ParamanGetFloat(fileno,subno,index,value,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_ParamanGetFloat(Bit32 fileno, Bit32 subno, Bit32 index, fBit64* value, Bit16 clientNo = 0);

/*!	@brief ���ò���ֵ
 * 
 * @param [in] fileno   :�������
 * @param [in] subno    :�����
 * @param [in] index    :����
 * @param [in] value    :��������  
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - -1:ʧ��;
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_ParamanSetFloat(fileno,subno,index,value,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_ParamanSetFloat(Bit32 fileno, Bit32 subno, Bit32 index, fBit64 value, Bit16 clientNo = 0);

/*!	@brief ��ȡ����ֵ
 * 
 * @param [in] fileno   :�������
 * @param [in] subno    :�����
 * @param [in] index    :����
 * @param [out] value   :��������  
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - <0:ʧ��;
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_ParamanGetStr(fileno,subno,index,value,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_ParamanGetStr(Bit32 fileno, Bit32 subno, Bit32 index, Bit8* value, Bit16 clientNo = 0);

/*!	@brief ���ò���ֵ
 * 
 * @param [in] fileno   :�������
 * @param [in] subno    :�����
 * @param [in] index    :����
 * @param [in] value    :�������� 
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - <0:ʧ��;
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_ParamanSetStr(fileno,subno,index,value,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_ParamanSetStr(Bit32 fileno, Bit32 subno, Bit32 index, Bit8* value, Bit16 clientNo = 0);

/*!	@brief ��ȡ����ֵ
 * 
 * @param [in] fileno   :�������
 * @param [in] subno    :�����
 * @param [in] index    :����
 * @param [out] value   :��������  
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - <0:ʧ��;
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_ParamanGetItem(fileno,subno,index,value,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_ParamanGetItem(Bit32 fileno, Bit32 subno, Bit32 index, SParamValue* value, Bit16 clientNo = 0);

/*!	@brief ���ò���ֵ
 * 
 * @param [in] fileno   :�������
 * @param [in] subno    :�����
 * @param [in] index    :����
 * @param [in] value    :��������  
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - <0:ʧ��;
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_ParamanSetItem(fileno,subno,index,value,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_ParamanSetItem(Bit32 fileno, Bit32 subno, Bit32 index, SParamValue* value, Bit16 clientNo = 0);


/*!	@brief ��ȡ�û������汾��
 * 
 * @param [out] userVer   :�û��汾��
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - <0:ʧ��;
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_ParamanGetUserVer(userVer,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_ParamanGetUserVer(Bit8* userVer, Bit16 clientNo = 0);

/*!	@brief �����û������汾��
 * 
 * @param [in] userVer    :�û��汾��
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - <0:ʧ��;
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_ParamanSetUserVer(userVer,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_ParamanSetUserVer(Bit8* userVer, Bit16 clientNo = 0);

/*!	@brief ͨ����ţ���ȡ���豸����NCUC���ethercat��
 * 
 * @param [in] axisno   :���
 * @param [in] clientNo :�������Ӻ�
 * @return 
 * -  0:�ɹ�;
 * - -1:ʧ��;
 
 * @attention 
 * @par ʾ��:
 * @code
   //˵��
   Bit32 ret = HNC_ParamanGetAxisDevType(axisno,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_ParamanGetAxisDevType(Bit32 axisno, Bit16 clientNo = 0);
#endif // __HNC_PARA_MAN_H__
