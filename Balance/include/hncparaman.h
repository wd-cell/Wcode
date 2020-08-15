/*! 
 * @file hncparaman.h
 * @brief 参数管理
 * @version V1.00
 * @date 2017/01/10
 * @author HNC-8 Team
 * @copyright 武汉华中数控股份有限公司软件开发部
 */

#ifndef __HNC_PARA_MAN_H__
#define __HNC_PARA_MAN_H__

#include "hncparamandef.h"

/*!	@brief 参数管理器初始化
 * 
 * @return 
 * -  0:成功;
 * - -1:参数结构文件载入失败;
 * - -2:上次保存参数文件有异常,请核实参数数据;
 * - -3:参数载入失败，载入默认参数;
 
 * @attention 
 * @par 示例:
 * @code
   //说明
 * @endcode     

 * @see :: 
 */
extern Bit32  HNC_ParamanInit();

/*!	@brief 参数管理器退出
 * 
 * @return 
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   HNC_ParamanExit();
 * @endcode     

 * @see :: 
 */
extern void  HNC_ParamanExit();

/*!	@brief 加载参数数据文件
 * 
 * @param [in] fileName :参数数据文件名；
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * - <0:失败，参见返回值说明；
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_ParamanLoad(fileName,clientNo);
 * @endcode     

 * @see :: 返回值说明 hncparamandef.h
 */
HNCAPI Bit32 HNC_ParamanLoad(Bit8 *fileName, Bit16 clientNo = 0);

/*!	@brief 保存参数数据文件
 * 
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * - <0:失败，参见返回值说明；
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_ParamanSave(clientNo);
 * @endcode     

 * @see :: 返回值说明 hncparamandef.h
 */
HNCAPI Bit32 HNC_ParamanSave(Bit16 clientNo = 0);

/*!	@brief 另存为参数数据文件
 * 
 * @param [in] lpFileName :参数数据文件名
 * @param [in] clientNo   :网络连接号
 * @return 
 * -  0:成功;
 * - <0:失败;
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_ParamanSaveAs(lpFileName,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32  HNC_ParamanSaveAs(Bit8* lpFileName, Bit16 clientNo = 0);

/*!	@brief 获取参数属性的值
 * 
 * @param [in] parmId     :参数编号
 * @param [in] propType   :参数属性的类型
 * @param [out] propValue :参数属性的值
 * @param [in] clientNo   :网络连接号
 * @return 
 * -  0:成功;
 * - <0:失败，参见返回值说明；
 
 * @attention 参数编号说明：详细说明参见《华中8型数控系统参数说明书》；
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_ParamanGetParaPropEx(parmId,propType,propValue,clientNo);
 * @endcode     

 * @see :: 参数属性的类型 ParaPropType 返回值说明 hncparamandef.h
 */
HNCAPI Bit32 HNC_ParamanGetParaPropEx(Bit32 parmId, Bit8 propType, SDataProperty *propValue, Bit16 clientNo = 0);

/*!	@brief 设置参数属性的值（包括参数值、最大值、最小值、缺省值、名称）
 * 
 * @param [in] parmId    :参数编号
 * @param [in] propType  :参数属性的类型
 * @param [in] propValue :参数属性的值
 * @param [in] clientNo  :网络连接号
 * @return 
 * -  0:成功;
 * - <0:失败，参见返回值说明；
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_ParamanSetParaPropEx(parmId,propType,propValue,clientNo);
 * @endcode     

 * @see :: 参数属性的类型 ParaPropType 返回值说明 hncparamandef.h
 */
HNCAPI Bit32 HNC_ParamanSetParaPropEx(Bit32 parmId, Bit8 propType, const SDataProperty *propValue, Bit16 clientNo = 0);

/*!	@brief 设置参数属性值,属性包括: 参数值、最大值、最小值、缺省值、名称
 * 
 * @param [in] filetype  :参数类别
 * @param [in] subid     :子类号
 * @param [in] index     :索引偏移地址
 * @param [in] propType  :参数属性
 * @param [in] propValue :参数属性值 
 * @param [in] clientNo  :网络连接号网络连接号
 * @return 
 * -  0:成功;
 * - -1:失败;
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_ParamanSetParaProp(filetype,subid,index,propType,propValue,clientNo);
 * @endcode     

 * @see :: 参数属性的类型 ParaPropType
 */
HNCAPI Bit32  HNC_ParamanSetParaProp(Bit32 filetype, Bit32 subid, Bit32 index,
							 Bit8 propType,const SDataProperty *propValue, Bit16 clientNo = 0);

/*!	@brief 获取参数属性值,属性包括: 参数值、最大值、最小值、 缺省值、名称、权限、生效方式、单位、内存大小
 * 
 * @param [in] filetype   :参数类别
 * @param [in] subid      :子类号
 * @param [in] index      :索引偏移地址
 * @param [in] propType   :参数属性
 * @param [out] propValue :参数属性值 
 * @param [in] clientNo   :网络连接号
 * @return 
 * -  0:成功;
 * - -1:失败;
 
 * @attention 
 * @par 示例:
 * @code
   //说明
    Bit32 ret = HNC_ParamanGetParaProp(filetyp,subid,index,propType,propValue,clientNo);
 * @endcode     

 * @see :: 参数属性的类型 ParaPropType
 */
HNCAPI Bit32  HNC_ParamanGetParaProp(Bit32 filetype, Bit32 subid, Bit32 index,
									 Bit8 propType, SDataProperty *propValue, Bit16 clientNo = 0);

/*!	@brief 获取参数类别的名字
 * 
 * @param [in] fileNo   :参数类别
 * @param [out] buf     :名字
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * - <0:失败，参见返回值说明；
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_ParamanGetFileName(fileNo,buf,clientNo);
 * @endcode     

 * @see ::  返回值说明 hncparamandef.h
 */
HNCAPI Bit32 HNC_ParamanGetFileName(Bit32 fileNo, Bit8 *buf, Bit16 clientNo = 0);

/*!	@brief 获取参数子类属性的值
 * 
 * @param [in] fileNo     :参数类别
 * @param [in] SubNo      :子类号
 * @param [in] propType   :子类属性的类型
 * @param [out] propValue :子类属性的值
 * @param [in] clientNo   :网络连接号
 * @return 
 * -  0:成功;
 * - <0:失败，参见返回值说明；
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_ParamanGetSubClassProp(fileNo,SubNo,propType,propValue,clientNo);
 * @endcode     

 * @see :: 参数属性的类型 ParaPropType 返回值说明 hncparamandef.h
 */
HNCAPI Bit32 HNC_ParamanGetSubClassProp (Bit32 fileNo, Bit32 SubNo, Bit8 propType, SDataProperty *propValue, Bit16 clientNo = 0);

/*!	@brief 获取参数索引列表总显示行数
 * 
 * @param [out] rowNum  :总行数
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * - <0:失败，参见返回值说明；
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_ParamanGetTotalRowNum(rowNum,clientNo);
 * @endcode     

 * @see ::  返回值说明 hncparamandef.h
 */
HNCAPI Bit32 HNC_ParamanGetTotalRowNum(Bit32 *rowNum, Bit16 clientNo = 0);

/*!	@brief 通过参数类别、子类号、行号获取指定参数的索引值
 * 
 * @param [in] fileNo   :参数类别
 * @param [in] subNo    :子类号
 * @param [in] rowNo    :子类行号
 * @param [out] index   :参数的索引值
 * @param [out] dupNum  :参数重复个数
 * @param [out] dupNo   :参数重复编号
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * - <0:失败，参见返回值说明；
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_ParamanTransRow2Index(fileNo,subNo,rowNo,index,dupNum,dupNo,clientNo);
 * @endcode     

 * @see ::  返回值说明 hncparamandef.h
 */
HNCAPI Bit32 HNC_ParamanTransRow2Index (Bit32 fileNo, Bit32 subNo, Bit32 rowNo, Bit32 *index, Bit16 *dupNum, Bit16 *dupNo, Bit16 clientNo = 0);

/*!	@brief 通过参数行总索引号获取参数类别，子类号，以及子类行号
 * 
 * @param [in] rowx     :总索引号
 * @param [out] fileNo  :参数类别
 * @param [out] subNo   :子类号
 * @param [out] row     :子类行号
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * - <0:失败，参见返回值说明；
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_ParamanTransRowx2Row(rowx,fileNo,subNo,row,clientNo);
 * @endcode     

 * @see ::  返回值说明 hncparamandef.h
 */
HNCAPI Bit32 HNC_ParamanTransRowx2Row (Bit32 rowx, Bit32 *fileNo, Bit32 *subNo, Bit32 *row, Bit16 clientNo = 0);

/*!	@brief 通过参数编号获取行总索引号
 * 
 * @param [in] parmId   :参数编号
 * @param [out] rowx    :总索引号
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * - <0:失败，参见返回值说明；
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_ParamanTransId2Rowx(parmId,rowx,clientNo);
 * @endcode     

 * @see ::  返回值说明 hncparamandef.h
 */
HNCAPI Bit32 HNC_ParamanTransId2Rowx(Bit32 parmId, Bit32 *rowx, Bit16 clientNo = 0);

/*!	@brief 加载参数子类的结构
 * 
 * @param [in] fileNo   :参数类别
 * @param [in] subNo    :子类号
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * - 非0:失败，参见返回值说明；
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_ParamanRewriteSubClass(fileNo,subNo,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_ParamanRewriteSubClass(Bit32 fileNo, Bit32 subNo, Bit16 clientNo = 0);

/*!	@brief 保存参数结构文件
 * 
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * - <0:失败，参见返回值说明；
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_ParamanSaveStrFile(clientNo);
 * @endcode     

 * @see ::  返回值说明 hncparamandef.h
 */
HNCAPI Bit32 HNC_ParamanSaveStrFile(Bit16 clientNo = 0);

/*!	@brief 获取参数值
 * 
 * @param [in] fileno   :参数类别
 * @param [in] subno    :子类号  
 * @param [in] index    :索引
 * @param [out] value   :参数数据
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * - <0:失败;
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_ParamanGetI32(fileno,subno,index,value,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_ParamanGetI32(Bit32 fileno, Bit32 subno, Bit32 index, Bit32* value, Bit16 clientNo = 0);

/*!	@brief 设置参数值
 * 
 * @param [in] fileno   :参数类别
 * @param [in] subno    :子类号
 * @param [in] index    :索引
 * @param [in] value    :参数数据
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * - <0:失败;

 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_ParamanSetI32(fileno,subno,index,value,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_ParamanSetI32(Bit32 fileno, Bit32 subno, Bit32 index, Bit32 value, Bit16 clientNo = 0);

/*!	@brief 获取参数值
 * 
 * @param [in] fileno   :参数类别
 * @param [in] subno    :子类号
 * @param [in] index    :索引
 * @param [out] value   :参数数据  
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * - <0:失败;
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_ParamanGetFloat(fileno,subno,index,value,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_ParamanGetFloat(Bit32 fileno, Bit32 subno, Bit32 index, fBit64* value, Bit16 clientNo = 0);

/*!	@brief 设置参数值
 * 
 * @param [in] fileno   :参数类别
 * @param [in] subno    :子类号
 * @param [in] index    :索引
 * @param [in] value    :参数数据  
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * - -1:失败;
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_ParamanSetFloat(fileno,subno,index,value,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_ParamanSetFloat(Bit32 fileno, Bit32 subno, Bit32 index, fBit64 value, Bit16 clientNo = 0);

/*!	@brief 获取参数值
 * 
 * @param [in] fileno   :参数类别
 * @param [in] subno    :子类号
 * @param [in] index    :索引
 * @param [out] value   :参数数据  
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * - <0:失败;
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_ParamanGetStr(fileno,subno,index,value,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_ParamanGetStr(Bit32 fileno, Bit32 subno, Bit32 index, Bit8* value, Bit16 clientNo = 0);

/*!	@brief 设置参数值
 * 
 * @param [in] fileno   :参数类别
 * @param [in] subno    :子类号
 * @param [in] index    :索引
 * @param [in] value    :参数数据 
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * - <0:失败;
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_ParamanSetStr(fileno,subno,index,value,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_ParamanSetStr(Bit32 fileno, Bit32 subno, Bit32 index, Bit8* value, Bit16 clientNo = 0);

/*!	@brief 获取参数值
 * 
 * @param [in] fileno   :参数类别
 * @param [in] subno    :子类号
 * @param [in] index    :索引
 * @param [out] value   :参数数据  
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * - <0:失败;
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_ParamanGetItem(fileno,subno,index,value,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_ParamanGetItem(Bit32 fileno, Bit32 subno, Bit32 index, SParamValue* value, Bit16 clientNo = 0);

/*!	@brief 设置参数值
 * 
 * @param [in] fileno   :参数类别
 * @param [in] subno    :子类号
 * @param [in] index    :索引
 * @param [in] value    :参数数据  
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * - <0:失败;
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_ParamanSetItem(fileno,subno,index,value,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_ParamanSetItem(Bit32 fileno, Bit32 subno, Bit32 index, SParamValue* value, Bit16 clientNo = 0);


/*!	@brief 获取用户参数版本号
 * 
 * @param [out] userVer   :用户版本号
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * - <0:失败;
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_ParamanGetUserVer(userVer,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_ParamanGetUserVer(Bit8* userVer, Bit16 clientNo = 0);

/*!	@brief 设置用户参数版本号
 * 
 * @param [in] userVer    :用户版本号
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * - <0:失败;
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_ParamanSetUserVer(userVer,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_ParamanSetUserVer(Bit8* userVer, Bit16 clientNo = 0);

/*!	@brief 通过轴号，获取轴设备类型NCUC轴和ethercat轴
 * 
 * @param [in] axisno   :轴号
 * @param [in] clientNo :网络连接号
 * @return 
 * -  0:成功;
 * - -1:失败;
 
 * @attention 
 * @par 示例:
 * @code
   //说明
   Bit32 ret = HNC_ParamanGetAxisDevType(axisno,clientNo);
 * @endcode     

 * @see :: 
 */
HNCAPI Bit32 HNC_ParamanGetAxisDevType(Bit32 axisno, Bit16 clientNo = 0);
#endif // __HNC_PARA_MAN_H__
