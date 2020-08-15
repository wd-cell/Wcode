#ifndef _HNC_API_H_
#define _HNC_API_H_

#include <string>
#include <list>
#include <map>
#include "structdef.h"

#ifdef _DLL_EXPORT_
#define HNC_API __declspec(dllexport)
#else
#define HNC_API __declspec(dllimport)
#endif

using namespace std;

typedef void(*CallbackFun)(const string& content, Bit32 result);
typedef void(*ConnectCallbackFun)(const string& ip, uBit16 port, bool result);

class HNC_API HncApi
{
private:
	void *m_ptr;

public:
	HncApi();
	~HncApi();

	const Bit8 *GetName();

	Bit32 GetAddress(Bit8 *ip, uBit16 &port);

	/**
	* @defgroup network  网络初始化和连接
	* @{
	*/
	/*!	@brief 网络初始化
	* @param[in] ip ：IP地址
	* @param[in] port ：端口号
	* @param[in] name ：进程名
	* @return
	* -  0：网络初始化成功；
	* - -1：网络初始化失败；

	* @attention 使用HNC_NetConnect函数之前必须先调用本函数
	* @par 示例:
	* @code
	//此处输入的IP为上位机本地IP
	int ret = HNC_NetInit("10.10.56.40", 10001, "CppTest");
	* @endcode

	* @see :: HNC_NetConnect
	*/
	Bit32 HNC_NetInit(const Bit8 *ip, uBit16 port, const Bit8 *name);
	/*!	@brief 网络连接
	* @param[in] ip ：IP地址
	* @param[in] port ：端口号
	* @return
	* - 0~255: 返回机器号；
	* - -1：连接失败；

	* @attention 使用本函数之前必须先调用HNC_NetInit，连接是否成功不能通过返回值判断
	* @par 示例:
	* @code
	//此处输入的IP为要连接的下位机IP
	int ret = HNC_NetConnect("10.10.56.223", 10001);
	* @endcode

	* @see :: HNC_NetInit
	*/
	Bit32 HNC_NetConnect(const Bit8 *ip, uBit16 port);
	/*!	@brief 网络连接
	* @param[in] ip ：IP地址
	* @param[in] port ：端口号
	* @param[in] ConnectHandler ：连接回调函数，用来判断连接是否成功
	* @return
	* - 0~255: 返回机器号；
	* - -1：连接失败；

	* @attention 使用本函数之前必须先调用HNC_NetInit，连接是否成功不能通过返回值判断
	* @par 示例:
	* @code
	//此处输入的IP为要连接的下位机IP
	void ConnectCallback(string ip, uBit16 port, bool result)
	{
	if (result == true)
	cout << "连接成功";
	else
	cout << "连接超时";
	}
	...
	int ret = HNC_NetConnect("10.10.56.223", 10001, ConnectCallback);
	* @endcode

	* @see :: HNC_NetInit
	*/
	Bit32 HNC_NetConnect(const Bit8 *ip, uBit16 port, ConnectCallbackFun ConnectHandler);

	/*!	@brief 判断网络是否连接
	* @return
	* -  0：已连接；
	* - -1：未连接；

	* @attention 使用本函数之前必须先调用HNC_NetInit
	* @par 示例:
	* @code
	//说明
	int ret = HNC_NetIsConnect();
	* @endcode

	* @see :: HNC_NetInit
	*/
	Bit16 HNC_NetIsConnect();
	/*!	@brief 断开网络

	* @attention 注意事项
	* @par 示例:
	* @code
	HNC_NetExit();
	* @endcode

	* @see :: HNC_NetConnect
	*/
	void HNC_NetExit();
	/** @} */

	/**
	* @defgroup REG  寄存器
	* @{
	*/
	/*!	@brief 获取寄存器的值
	*
	* @param[in] type ：寄存器类型
	* @param[in] index ：寄存器索引号
	* @param[out] value ：寄存器值
	* @return
	* -  0：取值成功；
	* - -1：取值失败；

	* @attention X,Y,R,F,G寄存器取值后需要转为正值
	* @par 示例:
	* @code
	//获取寄存器X[1]的值
	int type = REG_TYPE_X;
	int index = 1;
	int value = 0;
	int ret = HNC_RegGetValue(type, index, value);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_RegGetValue(Bit32 type, Bit32 index, Bit32 &value);
	/*!	@brief 获取多个寄存器的值
	*
	* @param[in] type ：寄存器类型
	* @param[in] index ：寄存器索引号
	* @param[in] num ：要获取的寄存器个数
	* @param[out] value ：要获取的寄存器数组
	* @return
	* -  0：取值成功；
	* - -1：取值失败；

	* @attention X,Y,R,F,G寄存器取值后需要转为正值
	* @par 示例:
	* @code
	//获取寄存器X[1]及之后的5个值
	uBit8 value[5];
	Bit32 ret = HNC_RegGetMultiValues(REG_TYPE_X, 1, 5, value);
	* @endcode

	* @see :: HNC_RegGetValue
	*/
	Bit32 HNC_RegGetMultiValues(Bit32 type, Bit32 index, Bit32 num, Bit8 value[]);
	/*!	@brief 设置寄存器的值
	*
	* @param[in] type ：寄存器类型
	* @param[in] index ：寄存器索引号
	* @param[in] value ：待写入的寄存器值
	* @param[in] Func ：写值回调函数指针，默认为NULL

	* @attention 写值回调函数指针默认参数为NULL
	* @par 示例:
	* @code
	//设置寄存器X[1]的值为2，写值后回调RegSetValCallBack
	void RegSetValCallBack(std::string content, Bit32 result) { ... }
	int type = REG_TYPE_X;
	int index = 1;
	int value = 2;
	HNC_RegSetValue(type, index, value, RegSetValCallBack);
	* @endcode
	*/
	void HNC_RegSetValue(Bit32 type, Bit32 index, Bit32 value, CallbackFun Func = NULL);
	/*!	@brief 获取寄存器的总组数
	*
	* @param[in] type ：寄存器类型
	* @param[out] num ：寄存器组数
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention num = -1表示寄存器类型不匹配
	* @par 示例:
	* @code
	//获取寄存器X的总组数
	int type = REG_TYPE_X;
	int num = 0;
	HNC_RegGetNum(type, num);
	* @endcode
	*/
	Bit32 HNC_RegGetNum(Bit32 type, Bit32 &num);
	/*!	@brief 将寄存器数据某一位置1
	*
	* @param[in] type ：寄存器类型
	* @param[in] index ：寄存器索引号
	* @param[in] bit ：X, Y, R：-1~7，F, G, W：-1~31，D, B, P：-1~31
	* @param[in] Func ：写值回调函数指针，默认为NULL
	* @return
	* -  0：只返回0

	* @attention 写值成功与否都返回0，如要判断请添加Func参数
	* @par 示例:
	* @code
	//将寄存器X[1]的第2位置1，置位后回调RegSetBitlCallBack
	void RegSetBitCallBack(std::string content, Bit32 result) { ... }
	int type = REG_TYPE_X;
	int index = 1;
	int bit = 2;
	HNC_RegSetBit(type, index, bit, RegSetBitCallBack);
	* @endcode
	*/
	Bit32 HNC_RegSetBit(Bit32 type, Bit32 index, Bit32 bit, CallbackFun Func = NULL);
	/*!	@brief 将寄存器数据某一位清0
	*
	* @param[in] type ：寄存器类型
	* @param[in] index ：寄存器索引号
	* @param[in] bit ：X, Y, R：-1~7，F, G, W：-1~31，D, B, P：-1~31
	* @param[in] Func ：写值回调函数指针，默认为NULL
	* @return
	* -  0：只返回0

	* @attention 写值成功与否都返回0，如要判断请添加Func参数
	* @par 示例:
	* @code
	//将寄存器X[1]的第2位清零，清零后回调RegClrBitlCallBack
	void RegClrBitCallBack(std::string content, Bit32 result) { ... }
	int type = REG_TYPE_X;
	int index = 1;
	int bit = 2;
	HNC_RegClrBit(type, index, bit, RegClrBitCallBack);
	* @endcode
	*/
	Bit32 HNC_RegClrBit(Bit32 type, Bit32 index, Bit32 bit, CallbackFun Func = NULL);
	/*!	@brief 获取FG寄存器的基址
	*
	* @param[in] baseType ：FG寄存器基址类型
	* @param[out] baseIndex ：基址寄存器组号
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//获取FG寄存器系统数据基址
	int baseType = REG_FG_SYS_BASE;
	int baseIndex = 0;
	HNC_RegGetFGBase(baseTye, baseIndex);
	* @endcode
	*/
	Bit32 HNC_RegGetFGBase(Bit32 baseType, Bit32 &baseIndex);
	/** @} */

	/**
	* @defgroup VAR  变量
	* @{
	*/
	/*!	@brief 按类型获取变量的值
	*
	* @param[in] type ：变量类型(VAR_TYPE_AXIS, VAR_TYPE_CHANNEL, VAR_TYPE_SYSTEM)
	* @param[in] no ：轴号或者通道号
	VAR_TYPE_AXIS: 0~31
	VAR_TYPE_CHANNEL: 0~3
	VAR_TYPE_SYSTEM: no无效
	* @param[in] index ：索引号
	VAR_TYPE_AXIS: 0~399
	VAR_TYPE_CHANNEL: 0~1999
	VAR_TYPE_SYSTEM: 0~9999
	* @param[out] value ：变量值
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention 1.当type为VAR_TYPE_AXIS, VAR_TYPE_CHANNEL, VAR_TYPE_SYSTEM时调用
	2.轴变量个数由100扩容到400
	3.取轴变量时，未配置轴的轴变量无法取值
	* @par 示例:
	* @code
	//获取轴变量0通道1索引的值
	int value = 0;
	int ret = HNC_VarGetValue(VAR_TYPE_AXIS, 0, 1, value);
	* @endcode
	*/
	Bit32 HNC_VarGetValue(Bit32 type, Bit32 no, Bit32 index, Bit32 &value);
	/*!	@brief 按类型获取变量的值
	*
	* @param[in] type ：变量类型(VAR_TYPE_SYSTEM_F)
	* @param[in] no ：轴号或者通道号
	VAR_TYPE_SYSTEM_F: no无效
	* @param[in] index ：索引号
	VAR_TYPE_SYSTEM_F: 0~9999
	* @param[out] value ：变量值
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention 当type为VAR_TYPE_SYSTEM_F时调用
	* @par 示例:
	* @code
	//获取系统变量0通道1索引的值
	double value = 0;
	int ret = HNC_VarGetValue(VAR_TYPE_SYSTEM_F, 0, 1, value);
	* @endcode
	*/
	Bit32 HNC_VarGetValue(Bit32 type, Bit32 no, Bit32 index, fBit64 &value);
	/*!	@brief 批量获取变量值
	*
	* @param[in] type ：变量类型
	* @param[in] index ：索引号
	* @param[in] num ：获取变量值数目
	* @param[out] value ：变量值数组
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention 不能获取浮点型系统变量。轴变量总数：轴数*400；通道变量总数：通道数*2000；系统变量总数100000
	* @par 示例:
	* @code
	//获取通道变量通道2索引3的5个变量值
	Bit32 value[5];
	Bit32 ret = HNC_VarGetMultiValues(VAR_TYPE_CHANNEL, 2*2000+3, 5, value);
	* @endcode

	* @see :: HNC_VarGetValue
	*/
	Bit32 HNC_VarGetMultiValues(Bit32 type, Bit32 index, Bit32 num, Bit32 value[]);
	/*!	@brief 按类型设置变量的值
	*
	* @param[in] type ：变量类型
	* @param[in] no ：轴号或通道号，参见HNC_VarGetValue
	* @param[in] index ：索引号，参见HNC_VarGetValue
	* @param[in] value ：变量值
	* @param[in] Func ：写值回调函数指针，默认为NULL

	* @attention 当type为VAR_TYPE_AXIS, VAR_TYPE_CHANNEL, VAR_TYPE_SYSTEM时调用
	* @par 示例:
	* @code
	//设置轴变量0通道1索引的值为2
	HNC_VarSetValue(VAR_TYPE_AXIS, 0, 1, 2);
	* @endcode

	* @see :: HNC_VarGetValue
	*/
	void HNC_VarSetValue(Bit32 type, Bit32 no, Bit32 index, Bit32 value, CallbackFun Func = NULL);
	/*!	@brief 按类型设置变量的值
	*
	* @param[in] type ：变量类型
	* @param[in] no ：轴号或通道号，参见HNC_VarGetValue
	* @param[in] index ：索引号，参见HNC_VarGetValue
	* @param[in] value ：变量值
	* @param[in] Func ：写值回调函数指针，默认为NULL

	* @attention 当type为VAR_TYPE_SYSTEM_F时调用，写值后回调VarSetValCallBack
	* @par 示例:
	* @code
	//设置系统变量0通道1索引的值为2
	void VarSetValCallBack(std::string content, Bit32 result) { ... }
	HNC_VarSetValue(VAR_TYPE_SYSTEM_F, 0, 1, 2, VarSetValCallBack);
	* @endcode

	* @see :: HNC_VarGetValue
	*/
	void HNC_VarSetValue(Bit32 type, Bit32 no, Bit32 index, fBit64 value, CallbackFun Func = NULL);
	/*!	@brief 按类型设置变量数据的一位（置1)
	*
	* @param[in] type ：变量类型
	* @param[in] no ：轴号或通道号，参见HNC_VarGetValue
	* @param[in] index ：索引号，参见HNC_VarGetValue
	* @param[in] bit ：变量位号-1~31
	* @param[in] Func ：写值回调函数指针，默认为NULL
	* @return
	* -  0：只返回0

	* @attention 1.当bit=-1，设置变量值为1；当bit>-1，将变量的第bit位设置为1
	*			  2.VAR_TYPE_SYSTEM_F不支持位设置
	*			  3.写值成功与否都返回0，如要判断请添加Func参数
	* @par 示例:
	* @code
	//轴变量0通道1索引第2位置1
	HNC_VarSetBit(VAR_TYPE_AXIS, 0, 1, 2);
	* @endcode

	* @see :: HNC_VarGetValue
	*/
	Bit32 HNC_VarSetBit(Bit32 type, Bit32 no, Bit32 index, Bit16 bit, CallbackFun Func = NULL);
	/*!	@brief 按类型清除变量数据的一位（置0)
	*
	* @param[in] type ：变量类型
	* @param[in] no ：轴号或通道号，参见HNC_VarGetValue
	* @param[in] index ：索引号，参见HNC_VarGetValue
	* @param[in] bit ：变量位号-1~31
	* @param[in] Func ：写值回调函数指针，默认为NULL
	* @return
	* -  0：只返回0

	* @attention 1.当bit=-1，设置变量值为0；当bit>-1，将变量的第bit位设置为0
	*			  2.VAR_TYPE_SYSTEM_F不支持位清零
	*			  3.写值成功与否都返回0，如要判断请添加Func参数
	* @par 示例:
	* @code
	//轴变量0通道1索引第2位清零，清零后回调VarClrBitCallBack
	void VarClrBitCallBack(std::string content, Bit32 result) { ... }
	HNC_VarClrBit(VAR_TYPE_AXIS, 0, 1, 2, VarClrBitCallBack);
	* @endcode

	* @see :: HNC_VarGetValue
	*/
	Bit32 HNC_VarClrBit(Bit32 type, Bit32 no, Bit32 index, Bit16 bit, CallbackFun Func = NULL);
	/*!	@brief 按编号获取宏变量的值
	*
	* @param[in] no ：变量编号
	[0, 2999]: 通道变量
	[40000, 59999]: 系统变量；其中，[50000, 54999]：用户自定义变量
	[60000, 69999]: 轴变量
	[70000, 99999]: 刀具变量
	* @param[out] value ：宏变量值
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//获取宏变量54000的值
	SDataUnion val;
	memset(&val, 0, sizeof(SDataUnion));
	int ret = HNC_MacroVarGetValue(54000, val);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_MacroVarGetValue(Bit32 no, SDataUnion &value);
	/*!	@brief 批量获取宏变量的值
	*
	* @param[in] startNo ：宏变量起始编号
	[0, 2999]: 通道变量
	[40000, 59999]: 系统变量；其中，[50000, 54999]：用户自定义变量
	[60000, 69999]: 轴变量
	[70000, 99999]: 刀具变量
	* @param[in] num ：要获取的宏变量个数
	* @param[out] value ：宏变量值
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention 只能获取用户自定义宏变量[50000, 54999]
	* @par 示例:
	* @code
	//获取54000到54004的宏变量值
	int num = 5;
	SDataUnion[] val = new SDataUnion[num];
	int ret = HNC_MacroVarGetMultiValues(54000, num, ref val);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_MacroVarGetMultiValues(Bit32 startNo, Bit32 num, SDataUnion value[]);
	/*!	@brief 按编号设置宏变量的值
	*
	* @param[in] no ：变量编号，参见HNC_MacroVarGetValue
	* @param[in] value ：宏变量值
	* @param[in] Func ：写值回调函数指针，默认为NULL

	* @attention
	* @par 示例:
	* @code
	//设置宏变量54000的值，设置后回调CallBack
	void CallBack(std::string content, Bit32 result) { ... }
	SDataUnion val;
	memset(&val, 0, sizeof(SDataUnion));
	val.g90 = 0;
	val.type = 1;
	val.v.i = 2;
	HNC_MacroVarSetValue(54000, val, CallBack);
	* @endcode
	* @see :: HNC_MacroVarGetValue
	*/
	void HNC_MacroVarSetValue(Bit32 no, SDataUnion value, CallbackFun Func = NULL);
	/** @} */

	/**
	* @defgroup PARAMAN  参数
	* @{
	*/
	/*!	@brief 获取参数属性值（按parmId参数编号设置）
	*
	* @param[in] parmId ：参数编号
	* @param[in] propType ：参数属性的类型
	* @param[out] propValue ：参数属性的值
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//示例
	SDataProperty prop;
	int ret = HNC_ParamanGetParaProp(105210, PARA_PROP_NAME, prop);
	string name = prop.value.val_string; //"最大转矩电流限幅"
	ret = HNC_ParamanGetParaProp(105210, PARA_PROP_DFVALUE, prop);
	int def = prop.value.val_int; //200
	ret = HNC_ParamanGetParaProp(105210, PARA_PROP_VALUE, prop);
	int value = prop.value.val_int; //200
	* @endcode

	* @see
	*/
	Bit32 HNC_ParamanGetParaProp(Bit32 parmId, Bit8 propType, SDataProperty &propValue);
	/*!	@brief 批量获取参数属性值（按parmId参数编号设置）
	*
	* @param[in] parmId ：参数编号
	* @param[in] propType ：参数属性的类型，该参数无效
	* @param[out] props ：参数属性值结构体变量
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention propType参数无效
	* @par 示例:
	* @code
	//批量获取参数属性值
	SParmProperty props;
	Bit32 ret = HNC_ParamanGetProps(10033, 0, props);
	* @endcode

	* @see :: HNC_ParamanGetParaProp
	*/
	Bit32 HNC_ParamanGetProps(Bit32 parmId, Bit8 propType, SParmProperty &props);
	/*!	@brief 设置参数属性的值（包括参数值、最大值、最小值、缺省值名称）
	*
	* @param[in] parmId ：参数编号
	* @param[in] propType ：参数属性的类型
	* @param[in] propValue ：参数属性的值
	* @param[in] Func ：写值回调函数指针，默认为NULL
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention 1.当修改PARA_PROP_VALUE参数值后，必须调用保存接口HNC_ParamanSave，否则重启后修改无效。
	2.当修改PARA_PROP_MAXVALUE、PARA_PROP_MINVALUE、PARA_PROP_DFVALUE、PARA_PROP_NAME后，
	必须调用保存接口HNC_ParamanSaveStrFile，否则重启后修改无效。
	* @par 示例:
	* @code
	//设置参数属性的值
	void CallBack(std::string content, Bit32 result) { ... }
	SDataProperty prop;
	...
	HNC_ParamanSetParaProp(105210, PARA_PROP_NAME, prop, CallBack);
	* @endcode

	* @see :: HNC_ParamanSaveStrFile
	*/
	void HNC_ParamanSetParaProp(Bit32 parmId, Bit8 propType, SDataProperty propValue, CallbackFun Func = NULL);
	/*!	@brief 保存参数数据文件
	*
	* @return
	* -  0：只返回0

	* @attention 1.调用二次开发接口修改参数值后，必须调用该接口保存数据。否则重启后修改无效。
	*			  2.不支持最大值、最小值、缺省值、名字的修改保存。
	*			  3.写值成功与否都返回0
	* @par 示例:
	* @code
	//保存参数数据文件
	HNC_ParamanSave();
	* @endcode

	* @see :: HNC_ParamanSetParaProp
	*/
	Bit32 HNC_ParamanSave();
	/*!	@brief 载入参数数据文件
	* @param[in] name ：参数文件名
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//载入参数数据文件
	HNC_ParamanLoad("parmFileName");
	* @endcode

	* @see ::
	*/
	Bit32 HNC_ParamanLoad(const Bit8 *name);
	/*!	@brief 保存参数结构文件
	*
	* @return
	* -  0：只返回0

	* @attention 1.当修改PARA_PROP_MAXVALUE、PARA_PROP_MINVALUE、PARA_PROP_DFVALUE、PARA_PROP_NAME后，
	必须调用保存接口HNC_ParamanSaveStrFile，否则重启后修改无效。
	*			  2.写值成功与否都返回0
	* @par 示例:
	* @code
	//保存参数结构文件
	HNC_ParamanSaveStrFile();
	* @endcode

	* @see :: HNC_ParamanSetParaProp
	*/
	Bit32 HNC_ParamanSaveStrFile();
	/** @} */

	/**
	* @defgroup SYS_CHAN_AXIS_CRDS  系统、通道、轴、坐标系
	* @{
	*/
	/*!	@brief 获取系统数据的值
	*
	* @param[in] type ：系统数据的类型
	* @param[out] propValue ：系统数据的值
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//获得当前通道
	Bit32 ch = 0;
	Bit32 ret = HNC_SystemGetValue(HNC_SYS_ACTIVE_CHAN, ch);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_SystemGetValue(Bit32 type, Bit32 &propValue);
	/*!	@brief 获取系统数据的值
	*
	* @param[in] type ：系统数据的类型
	* @param[out] propValue ：系统数据的值。字符串最小长度为128。
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//获得NC版本
	char str[128];
	memset(str, 0, sizeof(str));
	Bit32 ret = HNC_SystemGetValue(HNC_SYS_NC_VER, str);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_SystemGetValue(Bit32 type, Bit8 *propValue);
	/*!	@brief 获取通道数据的值
	*
	* @param[in] type ：通道数据的类型
	* @param[in] ch ：通道号
	* @param[in] index ：通道轴号/通道主轴号
	* @param[out] value ：通道数据的值
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//机床当前类型
	Bit32 nmacType = 0;
	Bit32 ret = HNC_ChannelGetValue(HNC_CHAN_MAC_TYPE, 0, 0, nmacType);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_ChannelGetValue(Bit32 type, Bit32 ch, Bit32 index, Bit32 &value);
	/*!	@brief 获取通道数据的值
	*
	* @param[in] type ：通道数据的类型
	* @param[in] ch ：通道号
	* @param[in] index ：通道轴号/通道主轴号
	* @param[out] value ：通道数据的值
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//指令进给速度
	fBit64 spd = 0;
	Bit32 ret = HNC_ChannelGetValue(HNC_CHAN_CMD_FEEDRATE, 0, 0, spd);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_ChannelGetValue(Bit32 type, Bit32 ch, Bit32 index, fBit64 &value);
	/*!	@brief 获取通道数据的值
	*
	* @param[in] type ：通道数据的类型
	* @param[in] ch ：通道号
	* @param[in] index ：通道轴号/通道主轴号
	* @param[out] value ：通道数据的值。字符串最小长度为32
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//通道名
	char name[32] = {0};
	Bit32 ret = HNC_ChannelGetValue(HNC_CHAN_NAME, 0, 0, name);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_ChannelGetValue(Bit32 type, Bit32 ch, Bit32 index, Bit8 *value);
	/*!	@brief 批量取通道数据
	* @param[in] ch ：通道号
	* @param[out] value ：通道数据结构体
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//取通道0所有数据
	NCChannel value;
	Bit32 ret = HNC_ChannelGetMultiValues(0, value);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_ChannelGetMultiValues(Bit32 ch, NCChannel &value);
	/*!	@brief 获取轴数据的值
	*
	* @param[in] type ：轴数据的类型
	* @param[in] ax ：轴号
	* @param[out] value ：轴数据的值
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention 当轴没有配时，与参数文件配置保持一致。比如取轴名，若该轴未配，取出来的值是AX。
	* @par 示例:
	* @code
	//轴类型
	Bit32 type = 0;
	Bit32 ret = HNC_AxisGetValue(HNC_AXIS_TYPE, 0, type);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_AxisGetValue(Bit32 type, Bit32 ax, Bit32 &value);
	/*!	@brief 获取轴数据的值
	*
	* @param[in] type ：轴数据的类型
	* @param[in] ax ：轴号
	* @param[out] value ：轴数据的值
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention 当轴没有配时，与参数文件配置保持一致。比如取轴名，若该轴未配，取出来的值是AX。
	* @par 示例:
	* @code
	//机床实际位置
	fBit64 pos = 0;
	Bit32 ret = HNC_AxisGetValue(HNC_AXIS_ACT_POS, 0, pos);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_AxisGetValue(Bit32 type, Bit32 ax, fBit64 &value);
	/*!	@brief 获取轴数据的值
	*
	* @param[in] type ：轴数据的类型
	* @param[in] ax ：轴号
	* @param[out] value ：轴数据的值。字符串最小长度为32
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention 当轴没有配时，与参数文件配置保持一致。比如取轴名，若该轴未配，取出来的值是AX。
	* @par 示例:
	* @code
	//轴名
	char name[32] = {0};
	Bit32 ret = HNC_AxisGetValue(HNC_AXIS_NAME, 0, name);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_AxisGetValue(Bit32 type, Bit32 ax, Bit8 *value);
	/*!	@brief 批量取轴数据
	* @param[in] ax ：轴号
	* @param[out] value ：轴数据结构体
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//取x轴所有数据
	NCAxis value;
	HNC_AxisGetMultiValues(0, value);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_AxisGetMultiValues(Bit32 ax, NCAxis &value);
	/*!	@brief 坐标系保存
	*

	* @attention
	* @par 示例:
	* @code
	//坐标系保存
	HNC_CrdsSave();
	* @endcode

	* @see ::
	*/
	Bit32 HNC_CrdsSave();
	/*!	@brief 获取坐标系数据的值
	*
	* @param[in] type ：坐标系数据的类型
	* @param[in] ax ：轴号
	* @param[out] value ：坐标系数据的值
	* @param[in] ch ：通道号
	* @param[in] crds ：坐标系编号
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//获取指定0通道x轴G54坐标系零点
	Bit32 axisValue = 0;
	Bit32 ret = HNC_CrdsGetValue(HNC_CRDS_CH_G5X_ZERO, 0, axisValue, 0, 54);
	* @endcode

	* @see :: HNC_CrdsSetValue
	*/
	Bit32 HNC_CrdsGetValue(Bit32 type, Bit32 ax, Bit32 &value, Bit32 ch, Bit32 crds);
	/*!	@brief 获取坐标系数据的值
	*
	* @param[in] type ：坐标系数据的类型
	* @param[in] ax ：轴号
	* @param[out] value ：坐标系数据的值
	* @param[in] ch ：通道号
	* @param[in] crds ：坐标系编号
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//获取指定0通道x轴G68特性坐标系向量
	fBit64 val = 0;
	Bit32 ret = HNC_CrdsGetValue(HNC_CRDS_G68_VCT0, val, 0, 68);
	* @endcode

	* @see :: HNC_CrdsSetValue
	*/
	Bit32 HNC_CrdsGetValue(Bit32 type, Bit32 ax, fBit64 &value, Bit32 ch, Bit32 crds);
	/*!	@brief 设置坐标系数据的值
	*
	* @param[in] type ：坐标系数据的类型
	* @param[in] ax ：轴号
	* @param[in] value ：坐标系数据的值
	* @param[in] ch ：通道号
	* @param[in] crds ：坐标系编号
	* @param[in] Func ：写值回调函数指针，默认为NULL

	* @attention 不支持HNC_CRDS_CH_WCS_ZERO类型设置
	* @par 示例:
	* @code
	//设置指定0通道x轴G54坐标系零点，设置后回调CallBack
	void CallBack(std::string content, Bit32 result) { ... }
	HNC_CrdsSetValue(HNC_CRDS_CH_G5X_ZERO, 0, axisValue, 0, 54, CallBack);
	* @endcode

	* @see :: HNC_CrdsGetValue
	*/
	void HNC_CrdsSetValue(Bit32 type, Bit32 ax, Bit32 value, Bit32 ch, Bit32 crds, CallbackFun Func = NULL);
	/*!	@brief 设置坐标系数据的值
	*
	* @param[in] type ：坐标系数据的类型
	* @param[in] ax ：轴号
	* @param[in] value ：坐标系数据的值
	* @param[in] ch ：通道号
	* @param[in] crds ：坐标系编号
	* @param[in] Func ：写值回调函数指针，默认为NULL

	* @attention 不支持HNC_CRDS_CH_WCS_ZERO类型设置
	* @par 示例:
	* @code
	//设置指定0通道x轴G68特性坐标系向量
	fBit64 val = 0;
	HNC_CrdsSetValue(HNC_CRDS_G68_VCT0, val, 0, 68);
	* @endcode

	* @see :: HNC_CrdsGetValue
	*/
	void HNC_CrdsSetValue(Bit32 type, Bit32 ax, fBit64 value, Bit32 ch, Bit32 crds, CallbackFun Func = NULL);
	/*!	@brief 取系统定义的各类坐标系数目
	*
	* @param[in] type ：各类坐标系数目类型
	* @return
	* 返回系统定义的各类坐标系数目。
	* - -1：类型越界或指针为空；

	* @attention
	* @par 示例:
	* @code
	//取系统定义的各类坐标系数目
	Bit32 num = HNC_CrdsGetMaxNum(G5EXT_MAX_NUM);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_CrdsGetMaxNum(Bit32 type);
	/** @} */

	/**
	* @defgroup TOOL  刀具
	* @{
	*/
	/*!	@brief 刀具文件保存
	*
	* @return
	* -  0：只返回0

	* @attention 写值成功与否都返回0
	* @par 示例:
	* @code
	//刀具文件保存
	HNC_ToolSave();
	* @endcode

	* @see ::
	*/
	Bit32 HNC_ToolSave();
	/*!	@brief 获取系统最大刀具数目
	*
	* @return
	* 系统的刀具最大数目

	* @attention
	* @par 示例:
	* @code
	//取系统最大刀具数目
	Bit32 ret = HNC_ToolGetMaxToolNum();
	* @endcode

	* @see ::
	*/
	Bit32 HNC_ToolGetMaxToolNum();
	/*!	@brief 获取刀具参数
	*
	* @param[in] toolNo ：刀具号1~1024
	* @param[in] index ：索引号
	* @param[out] value ：参数值
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention HNC_ToolGetToolPara的index对应enum ToolParaIndex，
	其中，刀具一般信息（INFTOOL_ID到INFTOOL_STATE）的数据类型为Bit32，其它均为fBit64
	* @par 示例:
	* @code
	//取1号刀所属通道
	Bit32 temp=0;
	Bit32 ret = HNC_ToolGetToolPara(1, INFTOOL_CH, temp);
	* @endcode

	* @see :: HNC_ToolGetToolPara_Subscribe
	*/
	Bit32 HNC_ToolGetToolPara(Bit32 toolNo, Bit32 index, Bit32 &value);
	/*!	@brief 获取刀具参数
	*
	* @param[in] toolNo ：刀具号1~1024
	* @param[in] index ：索引号
	* @param[out] value ：参数值
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention HNC_ToolGetToolPara的index对应enum ToolParaIndex，
	其中，刀具一般信息（INFTOOL_ID到INFTOOL_STATE）的数据类型为Bit32，其它均为fBit64
	* @par 示例:
	* @code
	//取1号刀S转速限制
	fBit64 = 0;
	Bit32 ret = HNC_ToolGetToolPara(1, EXTOOL_S_LIMIT, temp);
	* @endcode

	* @see :: HNC_ToolGetToolPara_Subscribe
	*/
	Bit32 HNC_ToolGetToolPara(Bit32 toolNo, Bit32 index, fBit64 &value);
	/*!	@brief 设置刀具参数
	*
	* @param[in] toolNo ：刀具号1~1024
	* @param[in] index ：索引号
	* @param[in] value ：参数值
	* @param[in] Func ：写值回调函数指针，默认为NULL

	* @attention
	* @par 示例:
	* @code
	//设置1号刀所属通道为3
	HNC_ToolSetToolPara(1, INFTOOL_CH, 3);
	* @endcode

	* @see :: HNC_ToolGetToolPara
	*/
	void HNC_ToolSetToolPara(Bit32 toolNo, Bit32 index, Bit32 value, CallbackFun Func = NULL);
	/*!	@brief 设置刀具参数
	*
	* @param[in] toolNo ：刀具号1~1024
	* @param[in] index ：索引号
	* @param[in] value ：参数值
	* @param[in] Func ：写值回调函数指针，默认为NULL

	* @attention
	* @par 示例:
	* @code
	//设置1号刀S转速限制
	HNC_ToolSetToolPara(1, EXTOOL_S_LIMIT, 0.0);
	* @endcode

	* @see :: HNC_ToolGetToolPara
	*/
	void HNC_ToolSetToolPara(Bit32 toolNo, Bit32 index, fBit64 value, CallbackFun Func = NULL);
	/*!	@brief 保存刀库表
	*
	* @return
	* -  0：只返回0

	* @attention 写值成功与否都返回0
	* @par 示例:
	* @code
	//刀库文件保存
	HNC_ToolMagSave();
	* @endcode

	* @see ::
	*/
	Bit32 HNC_ToolMagSave();
	/*!	@brief 获取系统刀库表头起始地址
	*
	* @return
	* 返回系统刀库表头的起始地址

	* @attention
	* @par 示例:
	* @code
	//获取系统刀库表头起始地址
	Bit32 addr = HNC_ToolGetMagHeadBase();
	* @endcode

	* @see ::
	*/
	Bit32 HNC_ToolGetMagHeadBase();
	/*!	@brief 获取系统最大刀库数目
	*
	* @return
	* 返回系统定义的最大刀库数目

	* @attention
	* @par 示例:
	* @code
	//返回系统定义的最大刀库数目
	Bit32 num = HNC_ToolGetMaxMagNum();
	* @endcode

	* @see ::
	*/
	Bit32 HNC_ToolGetMaxMagNum();
	/*!	@brief 获取系统刀位数据起始地址
	*
	* @return
	* 返回系统刀位数据的起始地址

	* @attention 在调用本函数之前必须先调用HNC_ToolGetPotDataBase_Subscribe
	* @par 示例:
	* @code
	//获取系统刀位数据起始地址
	Bit32 addr = HNC_ToolGetPotDataBase();
	* @endcode

	* @see :: HNC_ToolGetPotDataBase_Subscribe
	*/
	Bit32 HNC_ToolGetPotDataBase();
	/*!	@brief 订阅系统刀位数据起始地址
	*
	* @param[in] cancel ：是否订阅，false表示订阅，true表示取消订阅

	* @attention 在获取系统刀位数据起始地址之前必须先调用本函数
	* @par 示例:
	* @code
	//订阅系统刀位数据起始地址
	HNC_ToolGetPotDataBase_Subscribe(false);
	* @endcode

	* @see :: HNC_ToolGetPotDataBase
	*/
	void HNC_ToolGetPotDataBase_Subscribe(bool cancel);
	/*!	@brief 获取刀库数据
	*
	* @param[in] magNo ：刀库号1~32
	* @param[in] index ：索引号
	* @param[out] value ：刀库数据
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//获取获取刀库表中刀具数
	Bit32 num=0;
	Bit32 ret = HNC_ToolGetMagBase(1, MAGZTAB_TOOL_NUM, num);
	* @endcode

	* @see :: HNC_ToolSetMagBase
	*/
	Bit32 HNC_ToolGetMagBase(Bit32 magNo, Bit32 index, Bit32 &value);
	/*!	@brief 设置刀库数据
	*
	* @param[in] magNo ：刀库号1~32
	* @param[in] index ：索引号
	* @param[in] value ：刀库数据
	* @param[in] Func ：写值回调函数指针，默认为NULL

	* @attention
	* @par 示例:
	* @code
	//设置刀库表中刀具数
	HNC_ToolSetMagBase(1, MAGZTAB_TOOL_NUM, num);
	* @endcode

	* @see :: HNC_ToolGetMagBase
	*/
	void HNC_ToolSetMagBase(Bit32 magNo, Bit32 index, Bit32 value, CallbackFun Func = NULL);
	/*!	@brief 获取刀库中刀位的刀具号
	*
	* @param[out] magNo ：刀库号1~32
	* @param[out] potNo ：刀位号
	* @param[out] value ：刀具号
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention 在调用本函数之前必须先调用HNC_ToolMagGetToolNo_Subscribe
	* @par 示例:
	* @code
	//设置刀库中刀位的刀具号
	Bit32 magToolNo =0;
	Bit32 ret = HNC_ToolMagGetToolNo(1, 1, magToolNo);
	* @endcode

	* @see :: HNC_ToolMagGetToolNo_Subscribe
	*/
	Bit32 HNC_ToolMagGetToolNo(Bit32 magNo, Bit32 potNo, Bit32 &value);
	/*!	@brief 订阅刀库中刀位的刀具号
	*
	* @param[in] magNo ：刀库号1~32
	* @param[in] potNo ：刀位号
	* @param[in] cancel ：是否订阅，false表示订阅，true表示取消订阅

	* @attention 在获取刀库中刀位的刀具号之前必须先调用本函数
	* @par 示例:
	* @code
	//订阅刀库中刀位的刀具号
	HNC_ToolMagGetToolNo_Subscribe(1, 1, false);
	* @endcode

	* @see :: HNC_ToolMagGetToolNo
	*/
	void HNC_ToolMagGetToolNo_Subscribe(Bit32 magNo, Bit32 potNo, bool cancel);
	/*!	@brief 设置刀库中刀位的刀具号
	*
	* @param[in] magNo ：刀库号1~32
	* @param[in] potNo ：刀位号
	* @param[in] value ：刀具号
	* @return
	* -  0：只返回0

	* @attention 写值成功与否都返回0
	* @par 示例:
	* @code
	//设置刀库中刀具的刀位号
	Bit32 tempI = 1;
	HNC_ToolMagSetToolNo(1, 1, tempI);
	* @endcode

	* @see :: HNC_ToolMagGetToolNo
	*/
	Bit32 HNC_ToolMagSetToolNo(Bit32 magNo, Bit32 potNo, Bit32 value);
	/*!	@brief 获取刀库中刀位的刀位属性
	*
	* @param[in] magNo ：刀库号 1~32
	* @param[in] potNo ：刀位号
	* @param[out] value ：刀位属性
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention 在获取刀库中刀位的刀位属性之前必须先调用HNC_ToolGetPotAttri_Subscribe
	* @par 示例:
	* @code
	//获取刀库中刀位属性
	Bit32 tempI = 1;
	Bit32 ret = HNC_ToolGetPotAttri(1, 1, tempI);
	* @endcode

	* @see :: HNC_ToolGetPotAttri_Subscribe
	*/
	Bit32 HNC_ToolGetPotAttri(Bit32 magNo, Bit32 potNo, Bit32 &value);
	/*!	@brief 订阅刀库中刀位的刀位属性
	*
	* @param[in] magNo ：刀库号 1~32
	* @param[in] potNo ：刀位号
	* @param[in] cancel ：是否订阅，false表示订阅，true表示取消订阅

	* @attention 在获取刀库中刀位的刀位属性之前必须先调用本函数
	* @par 示例:
	* @code
	//订阅刀库中刀位属性
	HNC_ToolGetPotAttri_Subscribe(1, 1, false);
	* @endcode

	* @see :: HNC_ToolGetPotAttri
	*/
	void HNC_ToolGetPotAttri_Subscribe(Bit32 magNo, Bit32 potNo, bool cancel);;
	/*!	@brief 设置刀库中刀位的刀位属性
	*
	* @param[in] magNo ：刀库号 1~32
	* @param[in] potNo ：刀位号
	* @param[in] value ：刀位属性
	* @return
	* -  0：只返回0

	* @attention 写值成功与否都返回0
	* @par 示例:
	* @code
	//设置刀库表中刀位属性
	Bit32 tempI = 1;
	HNC_ToolSetPotAttri(1, 1, tempI);
	* @endcode

	* @see :: HNC_ToolGetPotAttri
	*/
	Bit32 HNC_ToolSetPotAttri(Bit32 magNo, Bit32 potNo, Bit32 value);
	/** @} */

	/**
	* @defgroup ALARM  报警
	* @{
	*/
	/*!	@brief 订阅报警信息
	*
	* @param[in] cancel ：是否订阅，false表示订阅，true表示取消订阅

	* @attention 在获取报警信息之前必须先调用本函数
	* @par 示例:
	* @code
	//订阅报警信息
	HNC_AlarmSubscribe(false);
	* @endcode

	* @see ::
	*/
	void HNC_AlarmSubscribe(bool cancel);
	/*!	@brief 获取报警的数目
	*
	* @param[out] num ：报警数目
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention 调用本函数之前必须先调用HNC_AlarmSubscribe
	* @par 示例:
	* @code
	//获取报警的数目
	Bit32 errNum = 0;
	Bit32 ret = HNC_AlarmGetNum(errNum);
	* @endcode

	* @see :: HNC_AlarmSubscribe
	*/
	Bit32 HNC_AlarmGetNum(Bit32 &num);
	/*!	@brief 获取当前报警的报警号和报警文本
	*
	* @param[in] index ：报警索引号
	* @param[out] alarmNo ：输出报警号
	* @param[out] alarmText ：输出报警文本，最少字符串长度为64
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention 调用本函数之前必须先调用HNC_AlarmSubscribe
	* @par 示例:
	* @code
	//获取当前报警的报警号和报警文本
	Bit32 index = 0;
	Bit32 alarmNo = 0;
	char alarmText[64] = {0};
	Bit32 ret = HNC_AlarmGetData(0, alarmNo, alarmText);
	* @endcode

	* @see :: HNC_AlarmSubscribe
	*/
	Bit32 HNC_AlarmGetData(Bit32 index, Bit32 &alarmNo, Bit8 *alarmText);
	/** @} */

	/**
	* @defgroup EVENT  事件
	* @{
	*/
	/*!	@brief 订阅消息队列中的事件
	*
	* @param[in] cancel ：是否订阅，false表示订阅，true表示取消订阅

	* @attention 从消息队列中获取事件之前必须先调用本函数
	* @par 示例:
	* @code
	//订阅事件
	HNC_EventSubscribe(false);
	* @endcode

	* @see :: HNC_EventGetSysEv
	*/
	void HNC_EventSubscribe(bool cancel);
	/*!	@brief 从消息队列中获取事件
	*
	* @param[out] ev ：事件
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention 调用本函数之前必须先调用HNC_EventSubscribe
	* @par 示例:
	* @code
	//从消息队列中获取
	SEventElement ev1 = {0, kbNoKey};
	Bit32 ret = HNC_EventGetSysEv(ev1);
	* @endcode

	* @see :: HNC_EventSubscribe
	*/
	Bit32 HNC_EventGetSysEv(SEventElement &ev);
	/** @} */

	/**
	* @defgroup SAMPLE  采样
	* @{
	*/
	/*!	@brief 获取采样通道
	*
	* @param[in] ch ：采样通道（0~31）
	* @param[out] type ：采样对象的数据类型
	* @param[out] axisNo ：逻辑轴号
	* @param[out] offset ：偏移量
	* @param[out] dataLen ：单个采样数据长度
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//获取采样通道数
	Bit32 type = 0;
	Bit32 axisNo = 0;
	Bit32 offset = 0;
	Bit32 dataLen = 0;
	Bit32 ret = HNC_SamplGetChannel(0, type, axisNo, offset, dataLen);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_SamplGetChannel(Bit32 ch, Bit32 &type, Bit32 &axisNo, Bit32 &offset, Bit32 &dataLen);
	/*!	@brief 设置采样通道
	*
	* @param[in] ch ：采样通道（0~31）
	* @param[in] type ：采样对象的数据类型
	* @param[in] axisNo ：逻辑轴号
	* @param[in] offset ：偏移量
	* @param[in] dataLen ：单个采样数据长度

	* @attention
	* @par 示例:
	* @code
	//设置采样通道数
	...
	HNC_SamplSetChannel(0, type, axisNo, offset, dataLen);
	* @endcode

	* @see ::
	*/
	void HNC_SamplSetChannel(Bit32 ch, Bit32 type, Bit32 axisNo, Bit32 offset, Bit32 dataLen);	
	/*!	@brief 获取采样数据
	*
	* @param[out] data ：采样数据
	* @param[out] chNum ：通道数
	* @param[out] numPerCh ：每通道采样点数
	* @return
	* -  0：成功；
	* - -1：失败；
	* - -2：data指针未分配内存

	* @attention data中的数据按通道排列，排列顺序为：0通道数据、1通道数据、3通道数据（如果2通道未设置，1通道后面会接3通道数据）
	* @par 示例:
	* @code
	//获取采样数据	
	Bit32 chNum = 0;
	Bit32 numPerCh = 0;
	Bit32 data[32 * 10000]; //获取的最大采样点数：32*10000
	memset(data, 0, 32 * 10000);
	Bit32 ret = HNC_SamplGetData(data, chNum, numPerCh);

	//将采样数据转存到list<list<Bit32>>中
	list<list<Bit32>> data;
	for (Bit32 i = 0; i < chNum; i++)
	{
		list<Bit32> tmpData;
		for (Bit32 j = 0; j < numPerCh; j++)
		{
			tmpData.push_back(data[i * numPerCh + j]);
		}
		data.push_back(tmpData);
	}
	* @endcode

	* @see ::
	*/
	Bit32 HNC_SamplGetData(Bit32 data[32 * 10000], Bit32 &chNum, Bit32 &numPerCh);
	/*!	@brief 移除采样客户端的某个采样配置
	*
	* @param[in] type ：采样类型
	* @param[in] axis ：轴号
	* @param[in] offset ：偏移量
	* @param[in] dataLen ：数据长度
	* @param[in] clientName ：进程名
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//移除采样客户端的某个采样配置
	...
	Bit32 ret = HNC_SamplRemoveConfig(type, axis, offset, dataLen, "Cpp");
	* @endcode

	* @see ::
	*/
	void HNC_SamplRemoveConfig(Bit32 type, Bit32 axis, Bit32 offset, Bit32 dataLen);
	/*!	@brief 获取采样周期
	*
	* @param[out] tick ：采样周期（插补周期的整数倍）
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//采样周期（插补周期的整数倍）
	Bit32 tick = 0;
	Bit32 ret = HNC_SamplGetPeriod(tick);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_SamplGetPeriod(Bit32 &tick);
	/*!	@brief 设置采样周期
	*
	* @param[in] tick ：采样周期（插补周期的整数倍）

	* @attention
	* @par 示例:
	* @code
	//设置采样周期
	Bit32 tick = 100;
	HNC_SamplSetPeriod(tick);
	* @endcode

	* @see ::
	*/
	void HNC_SamplSetPeriod(Bit32 tick);
	/*!	@brief 开启采样功能
	*

	* @attention 开始采样前，必须设置采样通道数目
	* @par 示例:
	* @code
	//说明
	HNC_SamplTriggerOn();
	* @endcode

	* @see ::
	*/
	void HNC_SamplTriggerOn();
	/*!	@brief 关闭采样功能
	*

	* @attention
	* @par 示例:
	* @code
	//说明
	HNC_SamplTriggerOff();
	* @endcode

	* @see ::
	*/
	void HNC_SamplTriggerOff();
	/*!	@brief 获取当前采样的状态
	*
	* @return
	* - 1：正在采样；
	* - 0：没有采样；

	* @attention
	* @par 示例:
	* @code
	//获取当前采样的状态
	Bit32 ret = HNC_SamplGetStat();
	* @endcode

	* @see ::
	*/
	Bit32 HNC_SamplGetStat();
	/*!	@brief 设置采样截止的方式和采样个数
	*
	* @param[in] type ：采样停止的方式
	* @param[in] n ：采样个数[1-10000] 。n仅在type=1时生效。当输入n超过10000按10000处理。

	* @attention
	* @par 示例:
	* @code
	//设置采样截止的方式和采样个数
	HNC_SamplSetLmt(1, 500);
	* @endcode

	* @see ::
	*/
	void HNC_SamplSetLmt(Bit32 type, Bit32 n);
	/** @} */

	/**
	* @defgroup MDI  MDI
	* @{
	*/
	/*!	@brief MDI开启
	*
	* @param[in] ch ：通道号
	* @param[in] Func ：写值回调函数指针，默认为NULL
	* @return
	* - 1：成功；
	* - 0：失败；

	* @attention
	* @par 示例:
	* @code
	//开启0通道的MDI
	Bit32 ret = HNC_MdiOpen(0);
	* @endcode

	* @see :: HNC_MdiClose
	*/
	Bit32 HNC_MdiOpen(Bit32 ch, CallbackFun Func = NULL);
	/*!	@brief 设置MDI的文本
	*
	* @param[in] content ：设置的文本
	* @param[in] Func ：写值回调函数指针，默认为NULL
	* @return
	* - 1：成功；
	* - 0：失败；

	* @attention
	* @par 示例:
	* @code
	//设置MDI的文本
	Bit32 ret = HNC_MdiSetContent("G00X100Y200Z300");
	* @endcode

	* @see :: HNC_MdiOpen
	*/
	Bit32 HNC_MdiSetContent(const Bit8 *content, CallbackFun Func = NULL);
	/*!	@brief MDI关闭
	*
	* @param[in] Func ：写值回调函数指针，默认为NULL
	* @return
	* - 1：成功；
	* - 0：失败；

	* @attention
	* @par 示例:
	* @code
	//关闭0通道的MDI
	Bit32 ret = HNC_MdiClose(0);
	* @endcode

	* @see :: HNC_MdiOpen
	*/
	Bit32 HNC_MdiClose(CallbackFun Func = NULL);
	/** @} */

	/**
	* @defgroup LAD  PLC
	* @{
	*/
	/*!	@brief 强制允许元件导通
	*
	* @param[in] index ：在命令表中的索引位置
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//强制允许元件导通
	Bit32 ret = HNC_LadEnableBlk(0);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_LadEnableBlk(Bit32 index);
	/*!	@brief 强制禁止元件导通
	*
	* @param[in] index ：在命令表中的索引位置
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//强制禁止元件导通
	Bit32 ret = HNC_LadDisableBlk(0);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_LadDisableBlk(Bit32 index);
	/*!	@brief 恢复元件强制状态
	*
	* @param[in] index ：在命令表中的索引位置
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//恢复元件强制状态
	Bit32 ret = HNC_LadRestoreBlk(0);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_LadRestoreBlk(Bit32 index);
	/*!	@brief 增加一组锁定寄存器
	*
	* @param[in] index ：在命令表中的索引位置
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//增加一组锁定寄存器
	Bit32 ret = HNC_LadAddRegLockList(0);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_LadAddRegLockList(Bit32 index);
	/*!	@brief 删除一组锁定寄存器
	*
	* @param[in] index ：在命令表中的索引位置
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//删除一组锁定寄存器
	Bit32 ret = HNC_LadDelRegLockList(0);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_LadDelRegLockList(Bit32 index);
	/*!	@brief 重新加载
	*
	* @param[in] flag ：flag标记
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//重新加载
	Bit32 ret = HNC_LadReload('\000');
	* @endcode

	* @see ::
	*/
	Bit32 HNC_LadReload(Bit8 flag);
	/*!	@brief 获取元件强制状态
	*
	* @param[in] index ：在命令表中的索引位置
	* @param[out] status ：元件强制状态
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//获取元件强制状态
	Bit32 status = 0;
	Bit32 ret = HNC_LadGetBlkForceState(0, status);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_LadGetBlkForceState(Bit32 index, Bit32 &status);
	/*!	@brief 获取寄存器锁存数据
	*
	* @param[in] index ：在命令表中的索引位置
	* @param[in] num ：行号
	* @param[out] status ：寄存器锁存数据
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention 在调用本函数之前必须先调用HNC_LadGetRegCacheStatus函数订阅
	* @par 示例:
	* @code
	//获取寄存器锁存数据
	Bit32 status = 0;
	Bit32 ret = HNC_LadGetRegCacheStatus(0, 0, status);
	* @endcode

	* @see :: HNC_LadGetStatus_Subscribe
	*/
	Bit32 HNC_LadGetRegCacheStatus(Bit32 index, Bit32 num, Bit32 &status);
	/*!	@brief 获取DIT文件校验码
	*
	* @param[out] verify ：DIT校验码
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//获取DIT文件校验码
	Bit32 verity = 0;
	Bit32 ret = HNC_LadGetFileVerify(verity);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_LadGetFileVerify(Bit32 &verify);
	/*!	@brief 获取锁定寄存器数目
	*
	* @param[out] num ：锁定寄存器数目
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//获取锁定寄存器数目
	Bit32 num = 0;
	Bit32 ret = HNC_LadGetRegLockNum(num);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_LadGetRegLockNum(Bit32 &num);
	/*!	@brief 获取寄存器锁存数据
	*
	* @param[in] index ：在命令表中的索引位置
	* @param[out] value ：寄存器锁存数据
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention 在调用本函数之前必须先调用HNC_LadGetRegLockStatus_Subscribe函数订阅
	* @par 示例:
	* @code
	//获取寄存器锁存数据
	SLadRegLick value;
	Bit32 ret = HNC_LadGetRegLockStatus(0, (Bit8*)&SLadRegLock);
	* @endcode

	* @see :: HNC_LadGetRegLockStatus_Subscribe
	*/
	Bit32 HNC_LadGetRegLockStatus(Bit32 index, Bit8 *value);
	/*!	@brief 设置寄存器锁定状态
	*
	* @param[in] index ：在命令表中的索引位置
	* @param[in] value ：寄存器锁定状态
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//设置寄存器锁定状态
	SLadRegLick value;
	...
	Bit32 ret = HNC_LadSetRegLockStatus(0, (Bit8*)&SLadRegLock);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_LadSetRegLockStatus(Bit32 index, Bit8 *value);
	/*!	@brief 订阅寄存器锁存数据
	*
	* @param[in] cmd ：在命令表中的索引位置
	* @param[in] index ：行号
	* @param[in] num ：数目
	* @param[in] cancel ：是否订阅，false表示订阅，true表示取消订阅

	* @attention 在获取寄存器锁存数据之前必须先调用本函数
	* @par 示例:
	* @code
	//订阅寄存器锁存数据
	HNC_LadGetStatus_Subscribe(0, 0, 5, false);
	* @endcode

	* @see :: HNC_LadGetRegCacheStatus
	*/
	void HNC_LadGetStatus_Subscribe(Bit32 cmd, Bit32 index, Bit32 num, bool cancel);
	/*!	@brief 订阅寄存器锁定状态
	*
	* @param[in] index ：在命令表中的索引位置
	* @param[in] cancel ：是否订阅，false表示订阅，true表示取消订阅
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention 在获取寄存器锁定状态之前必须先调用本函数订阅
	* @par 示例:
	* @code
	//订阅寄存器锁定状态
	Bit32 ret = HNC_LadGetRegLockStatus_Subscribe(0, false);
	* @endcode

	* @see :: HNC_LadGetRegLockStatus
	*/
	Bit32 HNC_LadGetRegLockStatus_Subscribe(Bit32 index, bool cancel);
	/** @} */

	/**
	* @defgroup other  其他接口
	* @{
	*/
	/*!	@brief 系统备份
	*
	* @param[in] flag ：备份内容
	* @param[in] pathName ：备份文件名，最大长度为128
	* @param[in] Func ：写值回调函数指针，默认为NULL

	* @attention
	* @par 示例:
	* @code
	//备份当前下位机G代码到文件backup
	HNC_SysBackup(0x0080, "../backup.tar");
	* @endcode

	* @see :: HNC_SysUpdate
	*/
	void HNC_SysBackup(Bit32 flag, const Bit8 *pathName, CallbackFun Func = NULL);
	/*!	@brief 系统升级
	*
	* @param[in] flag ：升级内容
	* @param[in] pathName ：升级文件名，最大长度为128
	* @param[in] Func ：写值回调函数指针，默认为NULL

	* @attention
	* @par 示例:
	* @code
	//升级update.tar文件到当前下位机G代码
	HNC_SysUpdate(0x0080, "../update.tar");
	* @endcode

	* @see :: HNC_SysBackup
	*/
	void HNC_SysUpdate(Bit32 flag, const Bit8 *pathName, CallbackFun Func = NULL);
	/*!	@brief 执行任意行功能
	*
	* @param[in] ch ：通道号
	* @param[in] line ：行号
	* @param[in] flag ：flag标记
	* @param[in] mst ：mst
	* @param[in] bNthLine ：true表示G代码N号，false表示G代码行号
	* @param[in] Func ：回调函数指针，默认为NULL

	* @attention
	* @par 示例:
	* @code
	//将0通道G代码以行号跳转到300行
	const char *mstContent = "";
	HNC_RandomRow(0, 300, 0, mstContent, false);
	* @endcode

	* @see ::
	*/
	void HNC_RandomRow(Bit32 ch, Bit32 line, Bit32 flag, const Bit8 *mst, bool bNthLine, CallbackFun Func = NULL);
	/*!	@brief 向下位机推送消息
	*
	* @param[in] msg ：推送的消息

	* @attention 本功能需要NC版本高于V1.30
	* @par 示例:
	* @code
	//向下位机推送消息
	HNC_PutMessage("hello!");
	* @endcode

	* @see ::
	*/
	void HNC_PutMessage(const Bit8 *msg);
	/*!	@brief 复位

	* @attention
	* @par 示例:
	* @code
	//说明
	HNC_SysReset();
	* @endcode

	* @see ::
	*/
	void HNC_SysReset();

	/*!	@brief 获取程序的完整名（含路径）
	*
	* @param[in] ch ：通道号0~4
	* @param[out] progName ：文件名，程序路径名最大长度60
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//取通道加载的程序的名字（含路径）
	Bit8 filename[PATH_NAME_LEN] ={0};
	Bit32 ret = HNC_FprogGetFullName(0, filename);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_FprogGetFullName(Bit32 ch, Bit8 *progName);
	/*!	@brief 挂载网盘
	*
	* @param[in] ip ：要挂载网盘的IP地址,16位字符串
	* @param[in] progPath ：要挂载网盘的文件夹名称，32位字符串
	* @param[in] userName ：网盘用户名，32位字符串
	* @param[in] password ：网盘用户密码，9位字符串
	* @param[in] Func ：回调函数指针，默认为NULL
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//挂载网盘，网盘用户名为guest
	Bit32 ret = HNC_NetDiskMount("10.10.56.56", "net", "guest", "123456");
	* @endcode

	* @see ::
	*/
	Bit32 HNC_NetDiskMount(const Bit8 *ip, const Bit8 *progPath, const Bit8 *userName, const Bit8 *password, CallbackFun Func = NULL);
	/*!	@brief 从下位机加载G代码程序
	*
	* @param[in] ch ：通道号
	* @param[in] name ：下位机G代码文件完整路径文件名，程序路径名最大长度60
	* @param[in] Func ：回调函数指针，默认为NULL
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//从下位机加载G代码
	Bit32 ret = HNC_SysCtrlSelectProg(0, "../prog/O00F1");
	* @endcode

	* @see ::
	*/
	Bit32 HNC_SysCtrlSelectProg(Bit32 ch, const Bit8 *name, CallbackFun Func = NULL);
	/*!	@brief 从下位机加载G代码子程序
	*
	* @param[in] ch ：通道号
	* @param[in] subProgNo ：子程序号
	* @param[in] name ：要加载的子程序名
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//从下位机加载G代码子程序
	Bit32 ret = HNC_FprogLoadSubProg(0, 5, "/net/O00F1");
	* @endcode

	* @see ::
	*/
	Bit32 HNC_FprogLoadSubProg(Bit32 ch, Bit32 subProgNo, const Bit8 *name);
	/*!	@brief 重新运行停止的程序
	*
	* @param[in] ch ：通道号
	* @param[in] Func ：回调函数指针，默认为NULL
	* @return
	* -  0：只返回0

	* @attention 写值成功与否都返回0
	* @par 示例:
	* @code
	//重新运行停止的程序
	HNC_SysCtrlResetProg(0);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_SysCtrlResetProg(Bit32 ch, CallbackFun Func = NULL);
	/*!	@brief 停止通道正在运行的程序
	*
	* @param[in] ch ：通道号
	* @param[in] Func ：回调函数指针，默认为NULL
	* @return
	* -  0：只返回0

	* @attention 写值成功与否都返回0
	* @par 示例:
	* @code
	//停止0通道正在运行的程序
	HNC_SysCtrlStopProg(0);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_SysCtrlStopProg(Bit32 ch, CallbackFun Func = NULL);
	/*!	@brief 获取轴掩码
	*
	* @param[out] axisMask ：轴掩码
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//获取轴掩码
	Bit32 axisMask = 0;
	Bit32 ret = HNC_GetAxisMask(axisMask);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_GetAxisMask(Bit32 &axisMask);
	/*!	@brief 获取设备状态字
	*
	* @param[out] devMask ：设备状态字
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//获取设备状态字
	Bit32 devMask = 0;
	Bit32 ret = HNC_GetDevMask(devMask);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_GetDevMask(Bit32 &devMask);
	/*!	@brief 获取系统配置
	*
	* @param[in] type ：特获取的系统配置类型
	* @param[out] config ：系统配置
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//获取系统配置	
	Bit8 config[128] = {0};
	Bit32 ret = HNC_SysCtrlGetConfig(HNC_SYS_CFG_BIN_PATH, config);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_SysCtrlGetConfig(Bit32 type, Bit8 *config);
	/*!	@brief 获取刀具起始号及数目
	*
	* @param[out] toolStartNo ：刀具起始号
	* @param[out] toolNum ：刀具数目
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention
	* @par 示例:
	* @code
	//获取刀具起始号及数目
	Bit32 toolStartNo = 0;
	Bit32 toolNum = 0;
	Bit32 ret = HNC_SysGetToolNum(toolStartNo, toolNum);
	* @endcode

	* @see ::
	*/
	void HNC_SysGetToolNum(Bit32 &toolStartNo, Bit32 &toolNum);
	/*!	@brief 根据程序ID获取程序名
	 * @param[in] progId ：程序ID
	 * @param[out] progName ：程序名（包含路径）
	 * @return 
	 * -  0：成功；
	 * - -1：失败；
	 
	 * @attention 
	 * @par 示例:
	 * @code
	   //根据程序ID获取程序名
	   string progName = "";
	   HNC_FprogGetProgById(0, progName);
	 * @endcode    
	
	 * @see ::
	 */
	 Bit32 HNC_FprogGetProgPathByIdx(Bit32 progId, string &progName);
	/*!	@brief 获取程序名ID表
	 * @param[out] progIdMap ：程序名ID表
	 * @return 
	 * -  0：成功；
	 * - -1：失败；
	 
	 * @attention 当下位机载入程序后程序名ID表才刷新
	 * @par 示例:
	 * @code
	   //获取程序名ID表
	   map<int, string> progIdMap;
	   HNC_FprogGetProgIdMap(progIdMap);
	 * @endcode    
	
	 * @see ::
	 */
	 Bit32 HNC_FprogGetProgIdMap(map<int, string> &progIdMap);
	/** @} */

#ifdef _848_VER_
	/*!	@brief 设置校验状态为开启
	*
	* @param[in] ch ：通道号
	* @param[in] stat ：校验状态
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention 获取校验数据之前必须先调用本函数开启校验，获取完毕必须再调用本函数关闭校验
	* @par 示例:
	* @code
	//设置校验状态为开启
	Bit32 ret = HNC_VerifySetStatus(0, 1); //开启校验
	Bit32 ret = HNC_VerifySetStatus(0, 0); //关闭校验
	* @endcode

	* @see :: HNC_VerifyGetData
	*/
	Bit32 HNC_VerifySetStatus(Bit32 ch, Bit32 stat);
	/*!	@brief 获取校验数据
	*
	* @param[in] ch ：通道号
	* @param[out] value ：校验数据
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention 获取校验数据之前必须先调用HNC_VerifySetStatus
	* @par 示例:
	* @code
	//获取校验数据
	HNC_VerifySetStatus(0, 1); //开启校验
	hnc_verity = data;
	Bit32 ret = HNC_VerifyGetData(0, data);
	* @endcode

	* @see :: HNC_VerifySetStatus
	*/
	Bit32 HNC_VerifyGetData(Bit32 ch, hnc_verify &value);
	/*!	@brief 获取通道DCD模态
	*
	* @param[in] ch ：通道号
	* @param[out] modal ：通道DCD模态
	* @return
	* -  0：成功；
	* - -1：失败；

	* @attention 使用本函数之前必须先调用HNC_DecoderGetData_Subscribe订阅
	* @par 示例:
	* @code
	//获取通道DCD模态
	SDcdModal = modal;
	Bit32 ret = HNC_DecoderGetData(0, modal);
	* @endcode

	* @see :: HNC_DecoderGetData_Subscribe
	*/
	Bit32 HNC_DecoderGetData(Bit32 ch, SDcdModal &modal);
	/*!	@brief 获取通道DCD模态及扫描队列中的m/s/t值
	*
	* @param[in] ch ：通道号
	* @param[out] modal ：通道DCD模态
	* @param[out] m ：输出m指令
	* @param[out] s ：输出s指令
	* @param[out] t ：输出t指令
	* @param[out] row ：已扫描到任意行的行数
	* @return
	* -  0：取MST值成功；
	* - -1：取MST值失败；

	* @attention 使用本函数之前必须先调用HNC_DecoderGetData_Subscribe和HNC_RandomRow
	* @par 示例:
	* @code
	//获取通道DCD模态及扫描队列中的m/s/t值
	SDcdModal = modal;
	Bit16 m[10];
	Bit32 s[4];
	Bit16 t = 0;
	Bit32 row = 0;
	Bit32 ret = HNC_DecoderGetData(0, modal, m, s, t, row);
	* @endcode

	* @see :: HNC_DecoderGetData_Subscribe
	*/
	Bit32 HNC_DecoderGetData(Bit32 ch, SDcdModal &modal, Bit16 *m, Bit32 *s, Bit16 &t, Bit32 &row);
	/*!	@brief 订阅解释器数据
	*
	* @param[in] ch ：通道号
	* @param[in] cancel ：是否订阅，false表示订阅，true表示取消订阅

	* @attention 使用获取解释器数据之前必须先调用本函数
	* @par 示例:
	* @code
	//订阅解释器数据
	HNC_DecoderGetData_Subscribe(0, false);
	* @endcode

	* @see :: HNC_DecoderGetData
	*/
	void HNC_DecoderGetData_Subscribe(Bit32 ch, bool cancel);
	/*!	@brief M指令设置界面绘制
	* @param[in] index ：M代码号
	* @param[in] group ：组号

	* @attention
	* @par 示例:
	* @code
	//M指令设置界面绘制
	Hncapi::HNC_MCodeSetGroup(0, 5);
	* @endcode

	* @see ::
	*/
	void HNC_MCodeSetGroup(Bit16 index, Bit16 group);
	/*!	@brief 设置M代码的读写方式
	* @param[in] index ：M代码号
	* @param[in] type ：读写方式

	* @attention
	* @par 示例:
	* @code
	//设置M代码的读写方式
	Hncapi::HNC_MCodeSetAttrib(0, 0);
	* @endcode

	* @see ::
	*/
	void HNC_MCodeSetAttrib(Bit16 index, Bit16 type);
#endif // _848_VER_
};

#endif