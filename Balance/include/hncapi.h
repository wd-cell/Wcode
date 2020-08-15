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
	* @defgroup network  �����ʼ��������
	* @{
	*/
	/*!	@brief �����ʼ��
	* @param[in] ip ��IP��ַ
	* @param[in] port ���˿ں�
	* @param[in] name ��������
	* @return
	* -  0�������ʼ���ɹ���
	* - -1�������ʼ��ʧ�ܣ�

	* @attention ʹ��HNC_NetConnect����֮ǰ�����ȵ��ñ�����
	* @par ʾ��:
	* @code
	//�˴������IPΪ��λ������IP
	int ret = HNC_NetInit("10.10.56.40", 10001, "CppTest");
	* @endcode

	* @see :: HNC_NetConnect
	*/
	Bit32 HNC_NetInit(const Bit8 *ip, uBit16 port, const Bit8 *name);
	/*!	@brief ��������
	* @param[in] ip ��IP��ַ
	* @param[in] port ���˿ں�
	* @return
	* - 0~255: ���ػ����ţ�
	* - -1������ʧ�ܣ�

	* @attention ʹ�ñ�����֮ǰ�����ȵ���HNC_NetInit�������Ƿ�ɹ�����ͨ������ֵ�ж�
	* @par ʾ��:
	* @code
	//�˴������IPΪҪ���ӵ���λ��IP
	int ret = HNC_NetConnect("10.10.56.223", 10001);
	* @endcode

	* @see :: HNC_NetInit
	*/
	Bit32 HNC_NetConnect(const Bit8 *ip, uBit16 port);
	/*!	@brief ��������
	* @param[in] ip ��IP��ַ
	* @param[in] port ���˿ں�
	* @param[in] ConnectHandler �����ӻص������������ж������Ƿ�ɹ�
	* @return
	* - 0~255: ���ػ����ţ�
	* - -1������ʧ�ܣ�

	* @attention ʹ�ñ�����֮ǰ�����ȵ���HNC_NetInit�������Ƿ�ɹ�����ͨ������ֵ�ж�
	* @par ʾ��:
	* @code
	//�˴������IPΪҪ���ӵ���λ��IP
	void ConnectCallback(string ip, uBit16 port, bool result)
	{
	if (result == true)
	cout << "���ӳɹ�";
	else
	cout << "���ӳ�ʱ";
	}
	...
	int ret = HNC_NetConnect("10.10.56.223", 10001, ConnectCallback);
	* @endcode

	* @see :: HNC_NetInit
	*/
	Bit32 HNC_NetConnect(const Bit8 *ip, uBit16 port, ConnectCallbackFun ConnectHandler);

	/*!	@brief �ж������Ƿ�����
	* @return
	* -  0�������ӣ�
	* - -1��δ���ӣ�

	* @attention ʹ�ñ�����֮ǰ�����ȵ���HNC_NetInit
	* @par ʾ��:
	* @code
	//˵��
	int ret = HNC_NetIsConnect();
	* @endcode

	* @see :: HNC_NetInit
	*/
	Bit16 HNC_NetIsConnect();
	/*!	@brief �Ͽ�����

	* @attention ע������
	* @par ʾ��:
	* @code
	HNC_NetExit();
	* @endcode

	* @see :: HNC_NetConnect
	*/
	void HNC_NetExit();
	/** @} */

	/**
	* @defgroup REG  �Ĵ���
	* @{
	*/
	/*!	@brief ��ȡ�Ĵ�����ֵ
	*
	* @param[in] type ���Ĵ�������
	* @param[in] index ���Ĵ���������
	* @param[out] value ���Ĵ���ֵ
	* @return
	* -  0��ȡֵ�ɹ���
	* - -1��ȡֵʧ�ܣ�

	* @attention X,Y,R,F,G�Ĵ���ȡֵ����ҪתΪ��ֵ
	* @par ʾ��:
	* @code
	//��ȡ�Ĵ���X[1]��ֵ
	int type = REG_TYPE_X;
	int index = 1;
	int value = 0;
	int ret = HNC_RegGetValue(type, index, value);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_RegGetValue(Bit32 type, Bit32 index, Bit32 &value);
	/*!	@brief ��ȡ����Ĵ�����ֵ
	*
	* @param[in] type ���Ĵ�������
	* @param[in] index ���Ĵ���������
	* @param[in] num ��Ҫ��ȡ�ļĴ�������
	* @param[out] value ��Ҫ��ȡ�ļĴ�������
	* @return
	* -  0��ȡֵ�ɹ���
	* - -1��ȡֵʧ�ܣ�

	* @attention X,Y,R,F,G�Ĵ���ȡֵ����ҪתΪ��ֵ
	* @par ʾ��:
	* @code
	//��ȡ�Ĵ���X[1]��֮���5��ֵ
	uBit8 value[5];
	Bit32 ret = HNC_RegGetMultiValues(REG_TYPE_X, 1, 5, value);
	* @endcode

	* @see :: HNC_RegGetValue
	*/
	Bit32 HNC_RegGetMultiValues(Bit32 type, Bit32 index, Bit32 num, Bit8 value[]);
	/*!	@brief ���üĴ�����ֵ
	*
	* @param[in] type ���Ĵ�������
	* @param[in] index ���Ĵ���������
	* @param[in] value ����д��ļĴ���ֵ
	* @param[in] Func ��дֵ�ص�����ָ�룬Ĭ��ΪNULL

	* @attention дֵ�ص�����ָ��Ĭ�ϲ���ΪNULL
	* @par ʾ��:
	* @code
	//���üĴ���X[1]��ֵΪ2��дֵ��ص�RegSetValCallBack
	void RegSetValCallBack(std::string content, Bit32 result) { ... }
	int type = REG_TYPE_X;
	int index = 1;
	int value = 2;
	HNC_RegSetValue(type, index, value, RegSetValCallBack);
	* @endcode
	*/
	void HNC_RegSetValue(Bit32 type, Bit32 index, Bit32 value, CallbackFun Func = NULL);
	/*!	@brief ��ȡ�Ĵ�����������
	*
	* @param[in] type ���Ĵ�������
	* @param[out] num ���Ĵ�������
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention num = -1��ʾ�Ĵ������Ͳ�ƥ��
	* @par ʾ��:
	* @code
	//��ȡ�Ĵ���X��������
	int type = REG_TYPE_X;
	int num = 0;
	HNC_RegGetNum(type, num);
	* @endcode
	*/
	Bit32 HNC_RegGetNum(Bit32 type, Bit32 &num);
	/*!	@brief ���Ĵ�������ĳһλ��1
	*
	* @param[in] type ���Ĵ�������
	* @param[in] index ���Ĵ���������
	* @param[in] bit ��X, Y, R��-1~7��F, G, W��-1~31��D, B, P��-1~31
	* @param[in] Func ��дֵ�ص�����ָ�룬Ĭ��ΪNULL
	* @return
	* -  0��ֻ����0

	* @attention дֵ�ɹ���񶼷���0����Ҫ�ж������Func����
	* @par ʾ��:
	* @code
	//���Ĵ���X[1]�ĵ�2λ��1����λ��ص�RegSetBitlCallBack
	void RegSetBitCallBack(std::string content, Bit32 result) { ... }
	int type = REG_TYPE_X;
	int index = 1;
	int bit = 2;
	HNC_RegSetBit(type, index, bit, RegSetBitCallBack);
	* @endcode
	*/
	Bit32 HNC_RegSetBit(Bit32 type, Bit32 index, Bit32 bit, CallbackFun Func = NULL);
	/*!	@brief ���Ĵ�������ĳһλ��0
	*
	* @param[in] type ���Ĵ�������
	* @param[in] index ���Ĵ���������
	* @param[in] bit ��X, Y, R��-1~7��F, G, W��-1~31��D, B, P��-1~31
	* @param[in] Func ��дֵ�ص�����ָ�룬Ĭ��ΪNULL
	* @return
	* -  0��ֻ����0

	* @attention дֵ�ɹ���񶼷���0����Ҫ�ж������Func����
	* @par ʾ��:
	* @code
	//���Ĵ���X[1]�ĵ�2λ���㣬�����ص�RegClrBitlCallBack
	void RegClrBitCallBack(std::string content, Bit32 result) { ... }
	int type = REG_TYPE_X;
	int index = 1;
	int bit = 2;
	HNC_RegClrBit(type, index, bit, RegClrBitCallBack);
	* @endcode
	*/
	Bit32 HNC_RegClrBit(Bit32 type, Bit32 index, Bit32 bit, CallbackFun Func = NULL);
	/*!	@brief ��ȡFG�Ĵ����Ļ�ַ
	*
	* @param[in] baseType ��FG�Ĵ�����ַ����
	* @param[out] baseIndex ����ַ�Ĵ������
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//��ȡFG�Ĵ���ϵͳ���ݻ�ַ
	int baseType = REG_FG_SYS_BASE;
	int baseIndex = 0;
	HNC_RegGetFGBase(baseTye, baseIndex);
	* @endcode
	*/
	Bit32 HNC_RegGetFGBase(Bit32 baseType, Bit32 &baseIndex);
	/** @} */

	/**
	* @defgroup VAR  ����
	* @{
	*/
	/*!	@brief �����ͻ�ȡ������ֵ
	*
	* @param[in] type ����������(VAR_TYPE_AXIS, VAR_TYPE_CHANNEL, VAR_TYPE_SYSTEM)
	* @param[in] no ����Ż���ͨ����
	VAR_TYPE_AXIS: 0~31
	VAR_TYPE_CHANNEL: 0~3
	VAR_TYPE_SYSTEM: no��Ч
	* @param[in] index ��������
	VAR_TYPE_AXIS: 0~399
	VAR_TYPE_CHANNEL: 0~1999
	VAR_TYPE_SYSTEM: 0~9999
	* @param[out] value ������ֵ
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention 1.��typeΪVAR_TYPE_AXIS, VAR_TYPE_CHANNEL, VAR_TYPE_SYSTEMʱ����
	2.�����������100���ݵ�400
	3.ȡ�����ʱ��δ�������������޷�ȡֵ
	* @par ʾ��:
	* @code
	//��ȡ�����0ͨ��1������ֵ
	int value = 0;
	int ret = HNC_VarGetValue(VAR_TYPE_AXIS, 0, 1, value);
	* @endcode
	*/
	Bit32 HNC_VarGetValue(Bit32 type, Bit32 no, Bit32 index, Bit32 &value);
	/*!	@brief �����ͻ�ȡ������ֵ
	*
	* @param[in] type ����������(VAR_TYPE_SYSTEM_F)
	* @param[in] no ����Ż���ͨ����
	VAR_TYPE_SYSTEM_F: no��Ч
	* @param[in] index ��������
	VAR_TYPE_SYSTEM_F: 0~9999
	* @param[out] value ������ֵ
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention ��typeΪVAR_TYPE_SYSTEM_Fʱ����
	* @par ʾ��:
	* @code
	//��ȡϵͳ����0ͨ��1������ֵ
	double value = 0;
	int ret = HNC_VarGetValue(VAR_TYPE_SYSTEM_F, 0, 1, value);
	* @endcode
	*/
	Bit32 HNC_VarGetValue(Bit32 type, Bit32 no, Bit32 index, fBit64 &value);
	/*!	@brief ������ȡ����ֵ
	*
	* @param[in] type ����������
	* @param[in] index ��������
	* @param[in] num ����ȡ����ֵ��Ŀ
	* @param[out] value ������ֵ����
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention ���ܻ�ȡ������ϵͳ���������������������*400��ͨ������������ͨ����*2000��ϵͳ��������100000
	* @par ʾ��:
	* @code
	//��ȡͨ������ͨ��2����3��5������ֵ
	Bit32 value[5];
	Bit32 ret = HNC_VarGetMultiValues(VAR_TYPE_CHANNEL, 2*2000+3, 5, value);
	* @endcode

	* @see :: HNC_VarGetValue
	*/
	Bit32 HNC_VarGetMultiValues(Bit32 type, Bit32 index, Bit32 num, Bit32 value[]);
	/*!	@brief ���������ñ�����ֵ
	*
	* @param[in] type ����������
	* @param[in] no ����Ż�ͨ���ţ��μ�HNC_VarGetValue
	* @param[in] index �������ţ��μ�HNC_VarGetValue
	* @param[in] value ������ֵ
	* @param[in] Func ��дֵ�ص�����ָ�룬Ĭ��ΪNULL

	* @attention ��typeΪVAR_TYPE_AXIS, VAR_TYPE_CHANNEL, VAR_TYPE_SYSTEMʱ����
	* @par ʾ��:
	* @code
	//���������0ͨ��1������ֵΪ2
	HNC_VarSetValue(VAR_TYPE_AXIS, 0, 1, 2);
	* @endcode

	* @see :: HNC_VarGetValue
	*/
	void HNC_VarSetValue(Bit32 type, Bit32 no, Bit32 index, Bit32 value, CallbackFun Func = NULL);
	/*!	@brief ���������ñ�����ֵ
	*
	* @param[in] type ����������
	* @param[in] no ����Ż�ͨ���ţ��μ�HNC_VarGetValue
	* @param[in] index �������ţ��μ�HNC_VarGetValue
	* @param[in] value ������ֵ
	* @param[in] Func ��дֵ�ص�����ָ�룬Ĭ��ΪNULL

	* @attention ��typeΪVAR_TYPE_SYSTEM_Fʱ���ã�дֵ��ص�VarSetValCallBack
	* @par ʾ��:
	* @code
	//����ϵͳ����0ͨ��1������ֵΪ2
	void VarSetValCallBack(std::string content, Bit32 result) { ... }
	HNC_VarSetValue(VAR_TYPE_SYSTEM_F, 0, 1, 2, VarSetValCallBack);
	* @endcode

	* @see :: HNC_VarGetValue
	*/
	void HNC_VarSetValue(Bit32 type, Bit32 no, Bit32 index, fBit64 value, CallbackFun Func = NULL);
	/*!	@brief ���������ñ������ݵ�һλ����1)
	*
	* @param[in] type ����������
	* @param[in] no ����Ż�ͨ���ţ��μ�HNC_VarGetValue
	* @param[in] index �������ţ��μ�HNC_VarGetValue
	* @param[in] bit ������λ��-1~31
	* @param[in] Func ��дֵ�ص�����ָ�룬Ĭ��ΪNULL
	* @return
	* -  0��ֻ����0

	* @attention 1.��bit=-1�����ñ���ֵΪ1����bit>-1���������ĵ�bitλ����Ϊ1
	*			  2.VAR_TYPE_SYSTEM_F��֧��λ����
	*			  3.дֵ�ɹ���񶼷���0����Ҫ�ж������Func����
	* @par ʾ��:
	* @code
	//�����0ͨ��1������2λ��1
	HNC_VarSetBit(VAR_TYPE_AXIS, 0, 1, 2);
	* @endcode

	* @see :: HNC_VarGetValue
	*/
	Bit32 HNC_VarSetBit(Bit32 type, Bit32 no, Bit32 index, Bit16 bit, CallbackFun Func = NULL);
	/*!	@brief ����������������ݵ�һλ����0)
	*
	* @param[in] type ����������
	* @param[in] no ����Ż�ͨ���ţ��μ�HNC_VarGetValue
	* @param[in] index �������ţ��μ�HNC_VarGetValue
	* @param[in] bit ������λ��-1~31
	* @param[in] Func ��дֵ�ص�����ָ�룬Ĭ��ΪNULL
	* @return
	* -  0��ֻ����0

	* @attention 1.��bit=-1�����ñ���ֵΪ0����bit>-1���������ĵ�bitλ����Ϊ0
	*			  2.VAR_TYPE_SYSTEM_F��֧��λ����
	*			  3.дֵ�ɹ���񶼷���0����Ҫ�ж������Func����
	* @par ʾ��:
	* @code
	//�����0ͨ��1������2λ���㣬�����ص�VarClrBitCallBack
	void VarClrBitCallBack(std::string content, Bit32 result) { ... }
	HNC_VarClrBit(VAR_TYPE_AXIS, 0, 1, 2, VarClrBitCallBack);
	* @endcode

	* @see :: HNC_VarGetValue
	*/
	Bit32 HNC_VarClrBit(Bit32 type, Bit32 no, Bit32 index, Bit16 bit, CallbackFun Func = NULL);
	/*!	@brief ����Ż�ȡ�������ֵ
	*
	* @param[in] no ���������
	[0, 2999]: ͨ������
	[40000, 59999]: ϵͳ���������У�[50000, 54999]���û��Զ������
	[60000, 69999]: �����
	[70000, 99999]: ���߱���
	* @param[out] value �������ֵ
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//��ȡ�����54000��ֵ
	SDataUnion val;
	memset(&val, 0, sizeof(SDataUnion));
	int ret = HNC_MacroVarGetValue(54000, val);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_MacroVarGetValue(Bit32 no, SDataUnion &value);
	/*!	@brief ������ȡ�������ֵ
	*
	* @param[in] startNo ���������ʼ���
	[0, 2999]: ͨ������
	[40000, 59999]: ϵͳ���������У�[50000, 54999]���û��Զ������
	[60000, 69999]: �����
	[70000, 99999]: ���߱���
	* @param[in] num ��Ҫ��ȡ�ĺ��������
	* @param[out] value �������ֵ
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention ֻ�ܻ�ȡ�û��Զ�������[50000, 54999]
	* @par ʾ��:
	* @code
	//��ȡ54000��54004�ĺ����ֵ
	int num = 5;
	SDataUnion[] val = new SDataUnion[num];
	int ret = HNC_MacroVarGetMultiValues(54000, num, ref val);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_MacroVarGetMultiValues(Bit32 startNo, Bit32 num, SDataUnion value[]);
	/*!	@brief ��������ú������ֵ
	*
	* @param[in] no ��������ţ��μ�HNC_MacroVarGetValue
	* @param[in] value �������ֵ
	* @param[in] Func ��дֵ�ص�����ָ�룬Ĭ��ΪNULL

	* @attention
	* @par ʾ��:
	* @code
	//���ú����54000��ֵ�����ú�ص�CallBack
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
	* @defgroup PARAMAN  ����
	* @{
	*/
	/*!	@brief ��ȡ��������ֵ����parmId����������ã�
	*
	* @param[in] parmId ���������
	* @param[in] propType ���������Ե�����
	* @param[out] propValue ���������Ե�ֵ
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//ʾ��
	SDataProperty prop;
	int ret = HNC_ParamanGetParaProp(105210, PARA_PROP_NAME, prop);
	string name = prop.value.val_string; //"���ת�ص����޷�"
	ret = HNC_ParamanGetParaProp(105210, PARA_PROP_DFVALUE, prop);
	int def = prop.value.val_int; //200
	ret = HNC_ParamanGetParaProp(105210, PARA_PROP_VALUE, prop);
	int value = prop.value.val_int; //200
	* @endcode

	* @see
	*/
	Bit32 HNC_ParamanGetParaProp(Bit32 parmId, Bit8 propType, SDataProperty &propValue);
	/*!	@brief ������ȡ��������ֵ����parmId����������ã�
	*
	* @param[in] parmId ���������
	* @param[in] propType ���������Ե����ͣ��ò�����Ч
	* @param[out] props ����������ֵ�ṹ�����
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention propType������Ч
	* @par ʾ��:
	* @code
	//������ȡ��������ֵ
	SParmProperty props;
	Bit32 ret = HNC_ParamanGetProps(10033, 0, props);
	* @endcode

	* @see :: HNC_ParamanGetParaProp
	*/
	Bit32 HNC_ParamanGetProps(Bit32 parmId, Bit8 propType, SParmProperty &props);
	/*!	@brief ���ò������Ե�ֵ����������ֵ�����ֵ����Сֵ��ȱʡֵ���ƣ�
	*
	* @param[in] parmId ���������
	* @param[in] propType ���������Ե�����
	* @param[in] propValue ���������Ե�ֵ
	* @param[in] Func ��дֵ�ص�����ָ�룬Ĭ��ΪNULL
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention 1.���޸�PARA_PROP_VALUE����ֵ�󣬱�����ñ���ӿ�HNC_ParamanSave�������������޸���Ч��
	2.���޸�PARA_PROP_MAXVALUE��PARA_PROP_MINVALUE��PARA_PROP_DFVALUE��PARA_PROP_NAME��
	������ñ���ӿ�HNC_ParamanSaveStrFile�������������޸���Ч��
	* @par ʾ��:
	* @code
	//���ò������Ե�ֵ
	void CallBack(std::string content, Bit32 result) { ... }
	SDataProperty prop;
	...
	HNC_ParamanSetParaProp(105210, PARA_PROP_NAME, prop, CallBack);
	* @endcode

	* @see :: HNC_ParamanSaveStrFile
	*/
	void HNC_ParamanSetParaProp(Bit32 parmId, Bit8 propType, SDataProperty propValue, CallbackFun Func = NULL);
	/*!	@brief ������������ļ�
	*
	* @return
	* -  0��ֻ����0

	* @attention 1.���ö��ο����ӿ��޸Ĳ���ֵ�󣬱�����øýӿڱ������ݡ������������޸���Ч��
	*			  2.��֧�����ֵ����Сֵ��ȱʡֵ�����ֵ��޸ı��档
	*			  3.дֵ�ɹ���񶼷���0
	* @par ʾ��:
	* @code
	//������������ļ�
	HNC_ParamanSave();
	* @endcode

	* @see :: HNC_ParamanSetParaProp
	*/
	Bit32 HNC_ParamanSave();
	/*!	@brief ������������ļ�
	* @param[in] name �������ļ���
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//������������ļ�
	HNC_ParamanLoad("parmFileName");
	* @endcode

	* @see ::
	*/
	Bit32 HNC_ParamanLoad(const Bit8 *name);
	/*!	@brief ��������ṹ�ļ�
	*
	* @return
	* -  0��ֻ����0

	* @attention 1.���޸�PARA_PROP_MAXVALUE��PARA_PROP_MINVALUE��PARA_PROP_DFVALUE��PARA_PROP_NAME��
	������ñ���ӿ�HNC_ParamanSaveStrFile�������������޸���Ч��
	*			  2.дֵ�ɹ���񶼷���0
	* @par ʾ��:
	* @code
	//��������ṹ�ļ�
	HNC_ParamanSaveStrFile();
	* @endcode

	* @see :: HNC_ParamanSetParaProp
	*/
	Bit32 HNC_ParamanSaveStrFile();
	/** @} */

	/**
	* @defgroup SYS_CHAN_AXIS_CRDS  ϵͳ��ͨ�����ᡢ����ϵ
	* @{
	*/
	/*!	@brief ��ȡϵͳ���ݵ�ֵ
	*
	* @param[in] type ��ϵͳ���ݵ�����
	* @param[out] propValue ��ϵͳ���ݵ�ֵ
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//��õ�ǰͨ��
	Bit32 ch = 0;
	Bit32 ret = HNC_SystemGetValue(HNC_SYS_ACTIVE_CHAN, ch);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_SystemGetValue(Bit32 type, Bit32 &propValue);
	/*!	@brief ��ȡϵͳ���ݵ�ֵ
	*
	* @param[in] type ��ϵͳ���ݵ�����
	* @param[out] propValue ��ϵͳ���ݵ�ֵ���ַ�����С����Ϊ128��
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//���NC�汾
	char str[128];
	memset(str, 0, sizeof(str));
	Bit32 ret = HNC_SystemGetValue(HNC_SYS_NC_VER, str);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_SystemGetValue(Bit32 type, Bit8 *propValue);
	/*!	@brief ��ȡͨ�����ݵ�ֵ
	*
	* @param[in] type ��ͨ�����ݵ�����
	* @param[in] ch ��ͨ����
	* @param[in] index ��ͨ�����/ͨ�������
	* @param[out] value ��ͨ�����ݵ�ֵ
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//������ǰ����
	Bit32 nmacType = 0;
	Bit32 ret = HNC_ChannelGetValue(HNC_CHAN_MAC_TYPE, 0, 0, nmacType);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_ChannelGetValue(Bit32 type, Bit32 ch, Bit32 index, Bit32 &value);
	/*!	@brief ��ȡͨ�����ݵ�ֵ
	*
	* @param[in] type ��ͨ�����ݵ�����
	* @param[in] ch ��ͨ����
	* @param[in] index ��ͨ�����/ͨ�������
	* @param[out] value ��ͨ�����ݵ�ֵ
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//ָ������ٶ�
	fBit64 spd = 0;
	Bit32 ret = HNC_ChannelGetValue(HNC_CHAN_CMD_FEEDRATE, 0, 0, spd);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_ChannelGetValue(Bit32 type, Bit32 ch, Bit32 index, fBit64 &value);
	/*!	@brief ��ȡͨ�����ݵ�ֵ
	*
	* @param[in] type ��ͨ�����ݵ�����
	* @param[in] ch ��ͨ����
	* @param[in] index ��ͨ�����/ͨ�������
	* @param[out] value ��ͨ�����ݵ�ֵ���ַ�����С����Ϊ32
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//ͨ����
	char name[32] = {0};
	Bit32 ret = HNC_ChannelGetValue(HNC_CHAN_NAME, 0, 0, name);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_ChannelGetValue(Bit32 type, Bit32 ch, Bit32 index, Bit8 *value);
	/*!	@brief ����ȡͨ������
	* @param[in] ch ��ͨ����
	* @param[out] value ��ͨ�����ݽṹ��
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//ȡͨ��0��������
	NCChannel value;
	Bit32 ret = HNC_ChannelGetMultiValues(0, value);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_ChannelGetMultiValues(Bit32 ch, NCChannel &value);
	/*!	@brief ��ȡ�����ݵ�ֵ
	*
	* @param[in] type �������ݵ�����
	* @param[in] ax �����
	* @param[out] value �������ݵ�ֵ
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention ����û����ʱ��������ļ����ñ���һ�¡�����ȡ������������δ�䣬ȡ������ֵ��AX��
	* @par ʾ��:
	* @code
	//������
	Bit32 type = 0;
	Bit32 ret = HNC_AxisGetValue(HNC_AXIS_TYPE, 0, type);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_AxisGetValue(Bit32 type, Bit32 ax, Bit32 &value);
	/*!	@brief ��ȡ�����ݵ�ֵ
	*
	* @param[in] type �������ݵ�����
	* @param[in] ax �����
	* @param[out] value �������ݵ�ֵ
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention ����û����ʱ��������ļ����ñ���һ�¡�����ȡ������������δ�䣬ȡ������ֵ��AX��
	* @par ʾ��:
	* @code
	//����ʵ��λ��
	fBit64 pos = 0;
	Bit32 ret = HNC_AxisGetValue(HNC_AXIS_ACT_POS, 0, pos);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_AxisGetValue(Bit32 type, Bit32 ax, fBit64 &value);
	/*!	@brief ��ȡ�����ݵ�ֵ
	*
	* @param[in] type �������ݵ�����
	* @param[in] ax �����
	* @param[out] value �������ݵ�ֵ���ַ�����С����Ϊ32
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention ����û����ʱ��������ļ����ñ���һ�¡�����ȡ������������δ�䣬ȡ������ֵ��AX��
	* @par ʾ��:
	* @code
	//����
	char name[32] = {0};
	Bit32 ret = HNC_AxisGetValue(HNC_AXIS_NAME, 0, name);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_AxisGetValue(Bit32 type, Bit32 ax, Bit8 *value);
	/*!	@brief ����ȡ������
	* @param[in] ax �����
	* @param[out] value �������ݽṹ��
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//ȡx����������
	NCAxis value;
	HNC_AxisGetMultiValues(0, value);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_AxisGetMultiValues(Bit32 ax, NCAxis &value);
	/*!	@brief ����ϵ����
	*

	* @attention
	* @par ʾ��:
	* @code
	//����ϵ����
	HNC_CrdsSave();
	* @endcode

	* @see ::
	*/
	Bit32 HNC_CrdsSave();
	/*!	@brief ��ȡ����ϵ���ݵ�ֵ
	*
	* @param[in] type ������ϵ���ݵ�����
	* @param[in] ax �����
	* @param[out] value ������ϵ���ݵ�ֵ
	* @param[in] ch ��ͨ����
	* @param[in] crds ������ϵ���
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//��ȡָ��0ͨ��x��G54����ϵ���
	Bit32 axisValue = 0;
	Bit32 ret = HNC_CrdsGetValue(HNC_CRDS_CH_G5X_ZERO, 0, axisValue, 0, 54);
	* @endcode

	* @see :: HNC_CrdsSetValue
	*/
	Bit32 HNC_CrdsGetValue(Bit32 type, Bit32 ax, Bit32 &value, Bit32 ch, Bit32 crds);
	/*!	@brief ��ȡ����ϵ���ݵ�ֵ
	*
	* @param[in] type ������ϵ���ݵ�����
	* @param[in] ax �����
	* @param[out] value ������ϵ���ݵ�ֵ
	* @param[in] ch ��ͨ����
	* @param[in] crds ������ϵ���
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//��ȡָ��0ͨ��x��G68��������ϵ����
	fBit64 val = 0;
	Bit32 ret = HNC_CrdsGetValue(HNC_CRDS_G68_VCT0, val, 0, 68);
	* @endcode

	* @see :: HNC_CrdsSetValue
	*/
	Bit32 HNC_CrdsGetValue(Bit32 type, Bit32 ax, fBit64 &value, Bit32 ch, Bit32 crds);
	/*!	@brief ��������ϵ���ݵ�ֵ
	*
	* @param[in] type ������ϵ���ݵ�����
	* @param[in] ax �����
	* @param[in] value ������ϵ���ݵ�ֵ
	* @param[in] ch ��ͨ����
	* @param[in] crds ������ϵ���
	* @param[in] Func ��дֵ�ص�����ָ�룬Ĭ��ΪNULL

	* @attention ��֧��HNC_CRDS_CH_WCS_ZERO��������
	* @par ʾ��:
	* @code
	//����ָ��0ͨ��x��G54����ϵ��㣬���ú�ص�CallBack
	void CallBack(std::string content, Bit32 result) { ... }
	HNC_CrdsSetValue(HNC_CRDS_CH_G5X_ZERO, 0, axisValue, 0, 54, CallBack);
	* @endcode

	* @see :: HNC_CrdsGetValue
	*/
	void HNC_CrdsSetValue(Bit32 type, Bit32 ax, Bit32 value, Bit32 ch, Bit32 crds, CallbackFun Func = NULL);
	/*!	@brief ��������ϵ���ݵ�ֵ
	*
	* @param[in] type ������ϵ���ݵ�����
	* @param[in] ax �����
	* @param[in] value ������ϵ���ݵ�ֵ
	* @param[in] ch ��ͨ����
	* @param[in] crds ������ϵ���
	* @param[in] Func ��дֵ�ص�����ָ�룬Ĭ��ΪNULL

	* @attention ��֧��HNC_CRDS_CH_WCS_ZERO��������
	* @par ʾ��:
	* @code
	//����ָ��0ͨ��x��G68��������ϵ����
	fBit64 val = 0;
	HNC_CrdsSetValue(HNC_CRDS_G68_VCT0, val, 0, 68);
	* @endcode

	* @see :: HNC_CrdsGetValue
	*/
	void HNC_CrdsSetValue(Bit32 type, Bit32 ax, fBit64 value, Bit32 ch, Bit32 crds, CallbackFun Func = NULL);
	/*!	@brief ȡϵͳ����ĸ�������ϵ��Ŀ
	*
	* @param[in] type ����������ϵ��Ŀ����
	* @return
	* ����ϵͳ����ĸ�������ϵ��Ŀ��
	* - -1������Խ���ָ��Ϊ�գ�

	* @attention
	* @par ʾ��:
	* @code
	//ȡϵͳ����ĸ�������ϵ��Ŀ
	Bit32 num = HNC_CrdsGetMaxNum(G5EXT_MAX_NUM);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_CrdsGetMaxNum(Bit32 type);
	/** @} */

	/**
	* @defgroup TOOL  ����
	* @{
	*/
	/*!	@brief �����ļ�����
	*
	* @return
	* -  0��ֻ����0

	* @attention дֵ�ɹ���񶼷���0
	* @par ʾ��:
	* @code
	//�����ļ�����
	HNC_ToolSave();
	* @endcode

	* @see ::
	*/
	Bit32 HNC_ToolSave();
	/*!	@brief ��ȡϵͳ��󵶾���Ŀ
	*
	* @return
	* ϵͳ�ĵ��������Ŀ

	* @attention
	* @par ʾ��:
	* @code
	//ȡϵͳ��󵶾���Ŀ
	Bit32 ret = HNC_ToolGetMaxToolNum();
	* @endcode

	* @see ::
	*/
	Bit32 HNC_ToolGetMaxToolNum();
	/*!	@brief ��ȡ���߲���
	*
	* @param[in] toolNo �����ߺ�1~1024
	* @param[in] index ��������
	* @param[out] value ������ֵ
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention HNC_ToolGetToolPara��index��Ӧenum ToolParaIndex��
	���У�����һ����Ϣ��INFTOOL_ID��INFTOOL_STATE������������ΪBit32��������ΪfBit64
	* @par ʾ��:
	* @code
	//ȡ1�ŵ�����ͨ��
	Bit32 temp=0;
	Bit32 ret = HNC_ToolGetToolPara(1, INFTOOL_CH, temp);
	* @endcode

	* @see :: HNC_ToolGetToolPara_Subscribe
	*/
	Bit32 HNC_ToolGetToolPara(Bit32 toolNo, Bit32 index, Bit32 &value);
	/*!	@brief ��ȡ���߲���
	*
	* @param[in] toolNo �����ߺ�1~1024
	* @param[in] index ��������
	* @param[out] value ������ֵ
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention HNC_ToolGetToolPara��index��Ӧenum ToolParaIndex��
	���У�����һ����Ϣ��INFTOOL_ID��INFTOOL_STATE������������ΪBit32��������ΪfBit64
	* @par ʾ��:
	* @code
	//ȡ1�ŵ�Sת������
	fBit64 = 0;
	Bit32 ret = HNC_ToolGetToolPara(1, EXTOOL_S_LIMIT, temp);
	* @endcode

	* @see :: HNC_ToolGetToolPara_Subscribe
	*/
	Bit32 HNC_ToolGetToolPara(Bit32 toolNo, Bit32 index, fBit64 &value);
	/*!	@brief ���õ��߲���
	*
	* @param[in] toolNo �����ߺ�1~1024
	* @param[in] index ��������
	* @param[in] value ������ֵ
	* @param[in] Func ��дֵ�ص�����ָ�룬Ĭ��ΪNULL

	* @attention
	* @par ʾ��:
	* @code
	//����1�ŵ�����ͨ��Ϊ3
	HNC_ToolSetToolPara(1, INFTOOL_CH, 3);
	* @endcode

	* @see :: HNC_ToolGetToolPara
	*/
	void HNC_ToolSetToolPara(Bit32 toolNo, Bit32 index, Bit32 value, CallbackFun Func = NULL);
	/*!	@brief ���õ��߲���
	*
	* @param[in] toolNo �����ߺ�1~1024
	* @param[in] index ��������
	* @param[in] value ������ֵ
	* @param[in] Func ��дֵ�ص�����ָ�룬Ĭ��ΪNULL

	* @attention
	* @par ʾ��:
	* @code
	//����1�ŵ�Sת������
	HNC_ToolSetToolPara(1, EXTOOL_S_LIMIT, 0.0);
	* @endcode

	* @see :: HNC_ToolGetToolPara
	*/
	void HNC_ToolSetToolPara(Bit32 toolNo, Bit32 index, fBit64 value, CallbackFun Func = NULL);
	/*!	@brief ���浶���
	*
	* @return
	* -  0��ֻ����0

	* @attention дֵ�ɹ���񶼷���0
	* @par ʾ��:
	* @code
	//�����ļ�����
	HNC_ToolMagSave();
	* @endcode

	* @see ::
	*/
	Bit32 HNC_ToolMagSave();
	/*!	@brief ��ȡϵͳ�����ͷ��ʼ��ַ
	*
	* @return
	* ����ϵͳ�����ͷ����ʼ��ַ

	* @attention
	* @par ʾ��:
	* @code
	//��ȡϵͳ�����ͷ��ʼ��ַ
	Bit32 addr = HNC_ToolGetMagHeadBase();
	* @endcode

	* @see ::
	*/
	Bit32 HNC_ToolGetMagHeadBase();
	/*!	@brief ��ȡϵͳ��󵶿���Ŀ
	*
	* @return
	* ����ϵͳ�������󵶿���Ŀ

	* @attention
	* @par ʾ��:
	* @code
	//����ϵͳ�������󵶿���Ŀ
	Bit32 num = HNC_ToolGetMaxMagNum();
	* @endcode

	* @see ::
	*/
	Bit32 HNC_ToolGetMaxMagNum();
	/*!	@brief ��ȡϵͳ��λ������ʼ��ַ
	*
	* @return
	* ����ϵͳ��λ���ݵ���ʼ��ַ

	* @attention �ڵ��ñ�����֮ǰ�����ȵ���HNC_ToolGetPotDataBase_Subscribe
	* @par ʾ��:
	* @code
	//��ȡϵͳ��λ������ʼ��ַ
	Bit32 addr = HNC_ToolGetPotDataBase();
	* @endcode

	* @see :: HNC_ToolGetPotDataBase_Subscribe
	*/
	Bit32 HNC_ToolGetPotDataBase();
	/*!	@brief ����ϵͳ��λ������ʼ��ַ
	*
	* @param[in] cancel ���Ƿ��ģ�false��ʾ���ģ�true��ʾȡ������

	* @attention �ڻ�ȡϵͳ��λ������ʼ��ַ֮ǰ�����ȵ��ñ�����
	* @par ʾ��:
	* @code
	//����ϵͳ��λ������ʼ��ַ
	HNC_ToolGetPotDataBase_Subscribe(false);
	* @endcode

	* @see :: HNC_ToolGetPotDataBase
	*/
	void HNC_ToolGetPotDataBase_Subscribe(bool cancel);
	/*!	@brief ��ȡ��������
	*
	* @param[in] magNo �������1~32
	* @param[in] index ��������
	* @param[out] value ����������
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//��ȡ��ȡ������е�����
	Bit32 num=0;
	Bit32 ret = HNC_ToolGetMagBase(1, MAGZTAB_TOOL_NUM, num);
	* @endcode

	* @see :: HNC_ToolSetMagBase
	*/
	Bit32 HNC_ToolGetMagBase(Bit32 magNo, Bit32 index, Bit32 &value);
	/*!	@brief ���õ�������
	*
	* @param[in] magNo �������1~32
	* @param[in] index ��������
	* @param[in] value ����������
	* @param[in] Func ��дֵ�ص�����ָ�룬Ĭ��ΪNULL

	* @attention
	* @par ʾ��:
	* @code
	//���õ�����е�����
	HNC_ToolSetMagBase(1, MAGZTAB_TOOL_NUM, num);
	* @endcode

	* @see :: HNC_ToolGetMagBase
	*/
	void HNC_ToolSetMagBase(Bit32 magNo, Bit32 index, Bit32 value, CallbackFun Func = NULL);
	/*!	@brief ��ȡ�����е�λ�ĵ��ߺ�
	*
	* @param[out] magNo �������1~32
	* @param[out] potNo ����λ��
	* @param[out] value �����ߺ�
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention �ڵ��ñ�����֮ǰ�����ȵ���HNC_ToolMagGetToolNo_Subscribe
	* @par ʾ��:
	* @code
	//���õ����е�λ�ĵ��ߺ�
	Bit32 magToolNo =0;
	Bit32 ret = HNC_ToolMagGetToolNo(1, 1, magToolNo);
	* @endcode

	* @see :: HNC_ToolMagGetToolNo_Subscribe
	*/
	Bit32 HNC_ToolMagGetToolNo(Bit32 magNo, Bit32 potNo, Bit32 &value);
	/*!	@brief ���ĵ����е�λ�ĵ��ߺ�
	*
	* @param[in] magNo �������1~32
	* @param[in] potNo ����λ��
	* @param[in] cancel ���Ƿ��ģ�false��ʾ���ģ�true��ʾȡ������

	* @attention �ڻ�ȡ�����е�λ�ĵ��ߺ�֮ǰ�����ȵ��ñ�����
	* @par ʾ��:
	* @code
	//���ĵ����е�λ�ĵ��ߺ�
	HNC_ToolMagGetToolNo_Subscribe(1, 1, false);
	* @endcode

	* @see :: HNC_ToolMagGetToolNo
	*/
	void HNC_ToolMagGetToolNo_Subscribe(Bit32 magNo, Bit32 potNo, bool cancel);
	/*!	@brief ���õ����е�λ�ĵ��ߺ�
	*
	* @param[in] magNo �������1~32
	* @param[in] potNo ����λ��
	* @param[in] value �����ߺ�
	* @return
	* -  0��ֻ����0

	* @attention дֵ�ɹ���񶼷���0
	* @par ʾ��:
	* @code
	//���õ����е��ߵĵ�λ��
	Bit32 tempI = 1;
	HNC_ToolMagSetToolNo(1, 1, tempI);
	* @endcode

	* @see :: HNC_ToolMagGetToolNo
	*/
	Bit32 HNC_ToolMagSetToolNo(Bit32 magNo, Bit32 potNo, Bit32 value);
	/*!	@brief ��ȡ�����е�λ�ĵ�λ����
	*
	* @param[in] magNo ������� 1~32
	* @param[in] potNo ����λ��
	* @param[out] value ����λ����
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention �ڻ�ȡ�����е�λ�ĵ�λ����֮ǰ�����ȵ���HNC_ToolGetPotAttri_Subscribe
	* @par ʾ��:
	* @code
	//��ȡ�����е�λ����
	Bit32 tempI = 1;
	Bit32 ret = HNC_ToolGetPotAttri(1, 1, tempI);
	* @endcode

	* @see :: HNC_ToolGetPotAttri_Subscribe
	*/
	Bit32 HNC_ToolGetPotAttri(Bit32 magNo, Bit32 potNo, Bit32 &value);
	/*!	@brief ���ĵ����е�λ�ĵ�λ����
	*
	* @param[in] magNo ������� 1~32
	* @param[in] potNo ����λ��
	* @param[in] cancel ���Ƿ��ģ�false��ʾ���ģ�true��ʾȡ������

	* @attention �ڻ�ȡ�����е�λ�ĵ�λ����֮ǰ�����ȵ��ñ�����
	* @par ʾ��:
	* @code
	//���ĵ����е�λ����
	HNC_ToolGetPotAttri_Subscribe(1, 1, false);
	* @endcode

	* @see :: HNC_ToolGetPotAttri
	*/
	void HNC_ToolGetPotAttri_Subscribe(Bit32 magNo, Bit32 potNo, bool cancel);;
	/*!	@brief ���õ����е�λ�ĵ�λ����
	*
	* @param[in] magNo ������� 1~32
	* @param[in] potNo ����λ��
	* @param[in] value ����λ����
	* @return
	* -  0��ֻ����0

	* @attention дֵ�ɹ���񶼷���0
	* @par ʾ��:
	* @code
	//���õ�����е�λ����
	Bit32 tempI = 1;
	HNC_ToolSetPotAttri(1, 1, tempI);
	* @endcode

	* @see :: HNC_ToolGetPotAttri
	*/
	Bit32 HNC_ToolSetPotAttri(Bit32 magNo, Bit32 potNo, Bit32 value);
	/** @} */

	/**
	* @defgroup ALARM  ����
	* @{
	*/
	/*!	@brief ���ı�����Ϣ
	*
	* @param[in] cancel ���Ƿ��ģ�false��ʾ���ģ�true��ʾȡ������

	* @attention �ڻ�ȡ������Ϣ֮ǰ�����ȵ��ñ�����
	* @par ʾ��:
	* @code
	//���ı�����Ϣ
	HNC_AlarmSubscribe(false);
	* @endcode

	* @see ::
	*/
	void HNC_AlarmSubscribe(bool cancel);
	/*!	@brief ��ȡ��������Ŀ
	*
	* @param[out] num ��������Ŀ
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention ���ñ�����֮ǰ�����ȵ���HNC_AlarmSubscribe
	* @par ʾ��:
	* @code
	//��ȡ��������Ŀ
	Bit32 errNum = 0;
	Bit32 ret = HNC_AlarmGetNum(errNum);
	* @endcode

	* @see :: HNC_AlarmSubscribe
	*/
	Bit32 HNC_AlarmGetNum(Bit32 &num);
	/*!	@brief ��ȡ��ǰ�����ı����źͱ����ı�
	*
	* @param[in] index ������������
	* @param[out] alarmNo �����������
	* @param[out] alarmText ����������ı��������ַ�������Ϊ64
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention ���ñ�����֮ǰ�����ȵ���HNC_AlarmSubscribe
	* @par ʾ��:
	* @code
	//��ȡ��ǰ�����ı����źͱ����ı�
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
	* @defgroup EVENT  �¼�
	* @{
	*/
	/*!	@brief ������Ϣ�����е��¼�
	*
	* @param[in] cancel ���Ƿ��ģ�false��ʾ���ģ�true��ʾȡ������

	* @attention ����Ϣ�����л�ȡ�¼�֮ǰ�����ȵ��ñ�����
	* @par ʾ��:
	* @code
	//�����¼�
	HNC_EventSubscribe(false);
	* @endcode

	* @see :: HNC_EventGetSysEv
	*/
	void HNC_EventSubscribe(bool cancel);
	/*!	@brief ����Ϣ�����л�ȡ�¼�
	*
	* @param[out] ev ���¼�
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention ���ñ�����֮ǰ�����ȵ���HNC_EventSubscribe
	* @par ʾ��:
	* @code
	//����Ϣ�����л�ȡ
	SEventElement ev1 = {0, kbNoKey};
	Bit32 ret = HNC_EventGetSysEv(ev1);
	* @endcode

	* @see :: HNC_EventSubscribe
	*/
	Bit32 HNC_EventGetSysEv(SEventElement &ev);
	/** @} */

	/**
	* @defgroup SAMPLE  ����
	* @{
	*/
	/*!	@brief ��ȡ����ͨ��
	*
	* @param[in] ch ������ͨ����0~31��
	* @param[out] type �������������������
	* @param[out] axisNo ���߼����
	* @param[out] offset ��ƫ����
	* @param[out] dataLen �������������ݳ���
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//��ȡ����ͨ����
	Bit32 type = 0;
	Bit32 axisNo = 0;
	Bit32 offset = 0;
	Bit32 dataLen = 0;
	Bit32 ret = HNC_SamplGetChannel(0, type, axisNo, offset, dataLen);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_SamplGetChannel(Bit32 ch, Bit32 &type, Bit32 &axisNo, Bit32 &offset, Bit32 &dataLen);
	/*!	@brief ���ò���ͨ��
	*
	* @param[in] ch ������ͨ����0~31��
	* @param[in] type �������������������
	* @param[in] axisNo ���߼����
	* @param[in] offset ��ƫ����
	* @param[in] dataLen �������������ݳ���

	* @attention
	* @par ʾ��:
	* @code
	//���ò���ͨ����
	...
	HNC_SamplSetChannel(0, type, axisNo, offset, dataLen);
	* @endcode

	* @see ::
	*/
	void HNC_SamplSetChannel(Bit32 ch, Bit32 type, Bit32 axisNo, Bit32 offset, Bit32 dataLen);	
	/*!	@brief ��ȡ��������
	*
	* @param[out] data ����������
	* @param[out] chNum ��ͨ����
	* @param[out] numPerCh ��ÿͨ����������
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�
	* - -2��dataָ��δ�����ڴ�

	* @attention data�е����ݰ�ͨ�����У�����˳��Ϊ��0ͨ�����ݡ�1ͨ�����ݡ�3ͨ�����ݣ����2ͨ��δ���ã�1ͨ��������3ͨ�����ݣ�
	* @par ʾ��:
	* @code
	//��ȡ��������	
	Bit32 chNum = 0;
	Bit32 numPerCh = 0;
	Bit32 data[32 * 10000]; //��ȡ��������������32*10000
	memset(data, 0, 32 * 10000);
	Bit32 ret = HNC_SamplGetData(data, chNum, numPerCh);

	//����������ת�浽list<list<Bit32>>��
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
	/*!	@brief �Ƴ������ͻ��˵�ĳ����������
	*
	* @param[in] type ����������
	* @param[in] axis �����
	* @param[in] offset ��ƫ����
	* @param[in] dataLen �����ݳ���
	* @param[in] clientName ��������
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//�Ƴ������ͻ��˵�ĳ����������
	...
	Bit32 ret = HNC_SamplRemoveConfig(type, axis, offset, dataLen, "Cpp");
	* @endcode

	* @see ::
	*/
	void HNC_SamplRemoveConfig(Bit32 type, Bit32 axis, Bit32 offset, Bit32 dataLen);
	/*!	@brief ��ȡ��������
	*
	* @param[out] tick ���������ڣ��岹���ڵ���������
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//�������ڣ��岹���ڵ���������
	Bit32 tick = 0;
	Bit32 ret = HNC_SamplGetPeriod(tick);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_SamplGetPeriod(Bit32 &tick);
	/*!	@brief ���ò�������
	*
	* @param[in] tick ���������ڣ��岹���ڵ���������

	* @attention
	* @par ʾ��:
	* @code
	//���ò�������
	Bit32 tick = 100;
	HNC_SamplSetPeriod(tick);
	* @endcode

	* @see ::
	*/
	void HNC_SamplSetPeriod(Bit32 tick);
	/*!	@brief ������������
	*

	* @attention ��ʼ����ǰ���������ò���ͨ����Ŀ
	* @par ʾ��:
	* @code
	//˵��
	HNC_SamplTriggerOn();
	* @endcode

	* @see ::
	*/
	void HNC_SamplTriggerOn();
	/*!	@brief �رղ�������
	*

	* @attention
	* @par ʾ��:
	* @code
	//˵��
	HNC_SamplTriggerOff();
	* @endcode

	* @see ::
	*/
	void HNC_SamplTriggerOff();
	/*!	@brief ��ȡ��ǰ������״̬
	*
	* @return
	* - 1�����ڲ�����
	* - 0��û�в�����

	* @attention
	* @par ʾ��:
	* @code
	//��ȡ��ǰ������״̬
	Bit32 ret = HNC_SamplGetStat();
	* @endcode

	* @see ::
	*/
	Bit32 HNC_SamplGetStat();
	/*!	@brief ���ò�����ֹ�ķ�ʽ�Ͳ�������
	*
	* @param[in] type ������ֹͣ�ķ�ʽ
	* @param[in] n ����������[1-10000] ��n����type=1ʱ��Ч��������n����10000��10000����

	* @attention
	* @par ʾ��:
	* @code
	//���ò�����ֹ�ķ�ʽ�Ͳ�������
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
	/*!	@brief MDI����
	*
	* @param[in] ch ��ͨ����
	* @param[in] Func ��дֵ�ص�����ָ�룬Ĭ��ΪNULL
	* @return
	* - 1���ɹ���
	* - 0��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//����0ͨ����MDI
	Bit32 ret = HNC_MdiOpen(0);
	* @endcode

	* @see :: HNC_MdiClose
	*/
	Bit32 HNC_MdiOpen(Bit32 ch, CallbackFun Func = NULL);
	/*!	@brief ����MDI���ı�
	*
	* @param[in] content �����õ��ı�
	* @param[in] Func ��дֵ�ص�����ָ�룬Ĭ��ΪNULL
	* @return
	* - 1���ɹ���
	* - 0��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//����MDI���ı�
	Bit32 ret = HNC_MdiSetContent("G00X100Y200Z300");
	* @endcode

	* @see :: HNC_MdiOpen
	*/
	Bit32 HNC_MdiSetContent(const Bit8 *content, CallbackFun Func = NULL);
	/*!	@brief MDI�ر�
	*
	* @param[in] Func ��дֵ�ص�����ָ�룬Ĭ��ΪNULL
	* @return
	* - 1���ɹ���
	* - 0��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//�ر�0ͨ����MDI
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
	/*!	@brief ǿ������Ԫ����ͨ
	*
	* @param[in] index ����������е�����λ��
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//ǿ������Ԫ����ͨ
	Bit32 ret = HNC_LadEnableBlk(0);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_LadEnableBlk(Bit32 index);
	/*!	@brief ǿ�ƽ�ֹԪ����ͨ
	*
	* @param[in] index ����������е�����λ��
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//ǿ�ƽ�ֹԪ����ͨ
	Bit32 ret = HNC_LadDisableBlk(0);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_LadDisableBlk(Bit32 index);
	/*!	@brief �ָ�Ԫ��ǿ��״̬
	*
	* @param[in] index ����������е�����λ��
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//�ָ�Ԫ��ǿ��״̬
	Bit32 ret = HNC_LadRestoreBlk(0);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_LadRestoreBlk(Bit32 index);
	/*!	@brief ����һ�������Ĵ���
	*
	* @param[in] index ����������е�����λ��
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//����һ�������Ĵ���
	Bit32 ret = HNC_LadAddRegLockList(0);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_LadAddRegLockList(Bit32 index);
	/*!	@brief ɾ��һ�������Ĵ���
	*
	* @param[in] index ����������е�����λ��
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//ɾ��һ�������Ĵ���
	Bit32 ret = HNC_LadDelRegLockList(0);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_LadDelRegLockList(Bit32 index);
	/*!	@brief ���¼���
	*
	* @param[in] flag ��flag���
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//���¼���
	Bit32 ret = HNC_LadReload('\000');
	* @endcode

	* @see ::
	*/
	Bit32 HNC_LadReload(Bit8 flag);
	/*!	@brief ��ȡԪ��ǿ��״̬
	*
	* @param[in] index ����������е�����λ��
	* @param[out] status ��Ԫ��ǿ��״̬
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//��ȡԪ��ǿ��״̬
	Bit32 status = 0;
	Bit32 ret = HNC_LadGetBlkForceState(0, status);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_LadGetBlkForceState(Bit32 index, Bit32 &status);
	/*!	@brief ��ȡ�Ĵ�����������
	*
	* @param[in] index ����������е�����λ��
	* @param[in] num ���к�
	* @param[out] status ���Ĵ�����������
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention �ڵ��ñ�����֮ǰ�����ȵ���HNC_LadGetRegCacheStatus��������
	* @par ʾ��:
	* @code
	//��ȡ�Ĵ�����������
	Bit32 status = 0;
	Bit32 ret = HNC_LadGetRegCacheStatus(0, 0, status);
	* @endcode

	* @see :: HNC_LadGetStatus_Subscribe
	*/
	Bit32 HNC_LadGetRegCacheStatus(Bit32 index, Bit32 num, Bit32 &status);
	/*!	@brief ��ȡDIT�ļ�У����
	*
	* @param[out] verify ��DITУ����
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//��ȡDIT�ļ�У����
	Bit32 verity = 0;
	Bit32 ret = HNC_LadGetFileVerify(verity);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_LadGetFileVerify(Bit32 &verify);
	/*!	@brief ��ȡ�����Ĵ�����Ŀ
	*
	* @param[out] num �������Ĵ�����Ŀ
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//��ȡ�����Ĵ�����Ŀ
	Bit32 num = 0;
	Bit32 ret = HNC_LadGetRegLockNum(num);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_LadGetRegLockNum(Bit32 &num);
	/*!	@brief ��ȡ�Ĵ�����������
	*
	* @param[in] index ����������е�����λ��
	* @param[out] value ���Ĵ�����������
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention �ڵ��ñ�����֮ǰ�����ȵ���HNC_LadGetRegLockStatus_Subscribe��������
	* @par ʾ��:
	* @code
	//��ȡ�Ĵ�����������
	SLadRegLick value;
	Bit32 ret = HNC_LadGetRegLockStatus(0, (Bit8*)&SLadRegLock);
	* @endcode

	* @see :: HNC_LadGetRegLockStatus_Subscribe
	*/
	Bit32 HNC_LadGetRegLockStatus(Bit32 index, Bit8 *value);
	/*!	@brief ���üĴ�������״̬
	*
	* @param[in] index ����������е�����λ��
	* @param[in] value ���Ĵ�������״̬
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//���üĴ�������״̬
	SLadRegLick value;
	...
	Bit32 ret = HNC_LadSetRegLockStatus(0, (Bit8*)&SLadRegLock);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_LadSetRegLockStatus(Bit32 index, Bit8 *value);
	/*!	@brief ���ļĴ�����������
	*
	* @param[in] cmd ����������е�����λ��
	* @param[in] index ���к�
	* @param[in] num ����Ŀ
	* @param[in] cancel ���Ƿ��ģ�false��ʾ���ģ�true��ʾȡ������

	* @attention �ڻ�ȡ�Ĵ�����������֮ǰ�����ȵ��ñ�����
	* @par ʾ��:
	* @code
	//���ļĴ�����������
	HNC_LadGetStatus_Subscribe(0, 0, 5, false);
	* @endcode

	* @see :: HNC_LadGetRegCacheStatus
	*/
	void HNC_LadGetStatus_Subscribe(Bit32 cmd, Bit32 index, Bit32 num, bool cancel);
	/*!	@brief ���ļĴ�������״̬
	*
	* @param[in] index ����������е�����λ��
	* @param[in] cancel ���Ƿ��ģ�false��ʾ���ģ�true��ʾȡ������
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention �ڻ�ȡ�Ĵ�������״̬֮ǰ�����ȵ��ñ���������
	* @par ʾ��:
	* @code
	//���ļĴ�������״̬
	Bit32 ret = HNC_LadGetRegLockStatus_Subscribe(0, false);
	* @endcode

	* @see :: HNC_LadGetRegLockStatus
	*/
	Bit32 HNC_LadGetRegLockStatus_Subscribe(Bit32 index, bool cancel);
	/** @} */

	/**
	* @defgroup other  �����ӿ�
	* @{
	*/
	/*!	@brief ϵͳ����
	*
	* @param[in] flag ����������
	* @param[in] pathName �������ļ�������󳤶�Ϊ128
	* @param[in] Func ��дֵ�ص�����ָ�룬Ĭ��ΪNULL

	* @attention
	* @par ʾ��:
	* @code
	//���ݵ�ǰ��λ��G���뵽�ļ�backup
	HNC_SysBackup(0x0080, "../backup.tar");
	* @endcode

	* @see :: HNC_SysUpdate
	*/
	void HNC_SysBackup(Bit32 flag, const Bit8 *pathName, CallbackFun Func = NULL);
	/*!	@brief ϵͳ����
	*
	* @param[in] flag ����������
	* @param[in] pathName �������ļ�������󳤶�Ϊ128
	* @param[in] Func ��дֵ�ص�����ָ�룬Ĭ��ΪNULL

	* @attention
	* @par ʾ��:
	* @code
	//����update.tar�ļ�����ǰ��λ��G����
	HNC_SysUpdate(0x0080, "../update.tar");
	* @endcode

	* @see :: HNC_SysBackup
	*/
	void HNC_SysUpdate(Bit32 flag, const Bit8 *pathName, CallbackFun Func = NULL);
	/*!	@brief ִ�������й���
	*
	* @param[in] ch ��ͨ����
	* @param[in] line ���к�
	* @param[in] flag ��flag���
	* @param[in] mst ��mst
	* @param[in] bNthLine ��true��ʾG����N�ţ�false��ʾG�����к�
	* @param[in] Func ���ص�����ָ�룬Ĭ��ΪNULL

	* @attention
	* @par ʾ��:
	* @code
	//��0ͨ��G�������к���ת��300��
	const char *mstContent = "";
	HNC_RandomRow(0, 300, 0, mstContent, false);
	* @endcode

	* @see ::
	*/
	void HNC_RandomRow(Bit32 ch, Bit32 line, Bit32 flag, const Bit8 *mst, bool bNthLine, CallbackFun Func = NULL);
	/*!	@brief ����λ��������Ϣ
	*
	* @param[in] msg �����͵���Ϣ

	* @attention ��������ҪNC�汾����V1.30
	* @par ʾ��:
	* @code
	//����λ��������Ϣ
	HNC_PutMessage("hello!");
	* @endcode

	* @see ::
	*/
	void HNC_PutMessage(const Bit8 *msg);
	/*!	@brief ��λ

	* @attention
	* @par ʾ��:
	* @code
	//˵��
	HNC_SysReset();
	* @endcode

	* @see ::
	*/
	void HNC_SysReset();

	/*!	@brief ��ȡ���������������·����
	*
	* @param[in] ch ��ͨ����0~4
	* @param[out] progName ���ļ���������·������󳤶�60
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//ȡͨ�����صĳ�������֣���·����
	Bit8 filename[PATH_NAME_LEN] ={0};
	Bit32 ret = HNC_FprogGetFullName(0, filename);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_FprogGetFullName(Bit32 ch, Bit8 *progName);
	/*!	@brief ��������
	*
	* @param[in] ip ��Ҫ�������̵�IP��ַ,16λ�ַ���
	* @param[in] progPath ��Ҫ�������̵��ļ������ƣ�32λ�ַ���
	* @param[in] userName �������û�����32λ�ַ���
	* @param[in] password �������û����룬9λ�ַ���
	* @param[in] Func ���ص�����ָ�룬Ĭ��ΪNULL
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//�������̣������û���Ϊguest
	Bit32 ret = HNC_NetDiskMount("10.10.56.56", "net", "guest", "123456");
	* @endcode

	* @see ::
	*/
	Bit32 HNC_NetDiskMount(const Bit8 *ip, const Bit8 *progPath, const Bit8 *userName, const Bit8 *password, CallbackFun Func = NULL);
	/*!	@brief ����λ������G�������
	*
	* @param[in] ch ��ͨ����
	* @param[in] name ����λ��G�����ļ�����·���ļ���������·������󳤶�60
	* @param[in] Func ���ص�����ָ�룬Ĭ��ΪNULL
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//����λ������G����
	Bit32 ret = HNC_SysCtrlSelectProg(0, "../prog/O00F1");
	* @endcode

	* @see ::
	*/
	Bit32 HNC_SysCtrlSelectProg(Bit32 ch, const Bit8 *name, CallbackFun Func = NULL);
	/*!	@brief ����λ������G�����ӳ���
	*
	* @param[in] ch ��ͨ����
	* @param[in] subProgNo ���ӳ����
	* @param[in] name ��Ҫ���ص��ӳ�����
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//����λ������G�����ӳ���
	Bit32 ret = HNC_FprogLoadSubProg(0, 5, "/net/O00F1");
	* @endcode

	* @see ::
	*/
	Bit32 HNC_FprogLoadSubProg(Bit32 ch, Bit32 subProgNo, const Bit8 *name);
	/*!	@brief ��������ֹͣ�ĳ���
	*
	* @param[in] ch ��ͨ����
	* @param[in] Func ���ص�����ָ�룬Ĭ��ΪNULL
	* @return
	* -  0��ֻ����0

	* @attention дֵ�ɹ���񶼷���0
	* @par ʾ��:
	* @code
	//��������ֹͣ�ĳ���
	HNC_SysCtrlResetProg(0);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_SysCtrlResetProg(Bit32 ch, CallbackFun Func = NULL);
	/*!	@brief ֹͣͨ���������еĳ���
	*
	* @param[in] ch ��ͨ����
	* @param[in] Func ���ص�����ָ�룬Ĭ��ΪNULL
	* @return
	* -  0��ֻ����0

	* @attention дֵ�ɹ���񶼷���0
	* @par ʾ��:
	* @code
	//ֹͣ0ͨ���������еĳ���
	HNC_SysCtrlStopProg(0);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_SysCtrlStopProg(Bit32 ch, CallbackFun Func = NULL);
	/*!	@brief ��ȡ������
	*
	* @param[out] axisMask ��������
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//��ȡ������
	Bit32 axisMask = 0;
	Bit32 ret = HNC_GetAxisMask(axisMask);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_GetAxisMask(Bit32 &axisMask);
	/*!	@brief ��ȡ�豸״̬��
	*
	* @param[out] devMask ���豸״̬��
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//��ȡ�豸״̬��
	Bit32 devMask = 0;
	Bit32 ret = HNC_GetDevMask(devMask);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_GetDevMask(Bit32 &devMask);
	/*!	@brief ��ȡϵͳ����
	*
	* @param[in] type ���ػ�ȡ��ϵͳ��������
	* @param[out] config ��ϵͳ����
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//��ȡϵͳ����	
	Bit8 config[128] = {0};
	Bit32 ret = HNC_SysCtrlGetConfig(HNC_SYS_CFG_BIN_PATH, config);
	* @endcode

	* @see ::
	*/
	Bit32 HNC_SysCtrlGetConfig(Bit32 type, Bit8 *config);
	/*!	@brief ��ȡ������ʼ�ż���Ŀ
	*
	* @param[out] toolStartNo ��������ʼ��
	* @param[out] toolNum ��������Ŀ
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention
	* @par ʾ��:
	* @code
	//��ȡ������ʼ�ż���Ŀ
	Bit32 toolStartNo = 0;
	Bit32 toolNum = 0;
	Bit32 ret = HNC_SysGetToolNum(toolStartNo, toolNum);
	* @endcode

	* @see ::
	*/
	void HNC_SysGetToolNum(Bit32 &toolStartNo, Bit32 &toolNum);
	/*!	@brief ���ݳ���ID��ȡ������
	 * @param[in] progId ������ID
	 * @param[out] progName ��������������·����
	 * @return 
	 * -  0���ɹ���
	 * - -1��ʧ�ܣ�
	 
	 * @attention 
	 * @par ʾ��:
	 * @code
	   //���ݳ���ID��ȡ������
	   string progName = "";
	   HNC_FprogGetProgById(0, progName);
	 * @endcode    
	
	 * @see ::
	 */
	 Bit32 HNC_FprogGetProgPathByIdx(Bit32 progId, string &progName);
	/*!	@brief ��ȡ������ID��
	 * @param[out] progIdMap ��������ID��
	 * @return 
	 * -  0���ɹ���
	 * - -1��ʧ�ܣ�
	 
	 * @attention ����λ���������������ID���ˢ��
	 * @par ʾ��:
	 * @code
	   //��ȡ������ID��
	   map<int, string> progIdMap;
	   HNC_FprogGetProgIdMap(progIdMap);
	 * @endcode    
	
	 * @see ::
	 */
	 Bit32 HNC_FprogGetProgIdMap(map<int, string> &progIdMap);
	/** @} */

#ifdef _848_VER_
	/*!	@brief ����У��״̬Ϊ����
	*
	* @param[in] ch ��ͨ����
	* @param[in] stat ��У��״̬
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention ��ȡУ������֮ǰ�����ȵ��ñ���������У�飬��ȡ��ϱ����ٵ��ñ������ر�У��
	* @par ʾ��:
	* @code
	//����У��״̬Ϊ����
	Bit32 ret = HNC_VerifySetStatus(0, 1); //����У��
	Bit32 ret = HNC_VerifySetStatus(0, 0); //�ر�У��
	* @endcode

	* @see :: HNC_VerifyGetData
	*/
	Bit32 HNC_VerifySetStatus(Bit32 ch, Bit32 stat);
	/*!	@brief ��ȡУ������
	*
	* @param[in] ch ��ͨ����
	* @param[out] value ��У������
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention ��ȡУ������֮ǰ�����ȵ���HNC_VerifySetStatus
	* @par ʾ��:
	* @code
	//��ȡУ������
	HNC_VerifySetStatus(0, 1); //����У��
	hnc_verity = data;
	Bit32 ret = HNC_VerifyGetData(0, data);
	* @endcode

	* @see :: HNC_VerifySetStatus
	*/
	Bit32 HNC_VerifyGetData(Bit32 ch, hnc_verify &value);
	/*!	@brief ��ȡͨ��DCDģ̬
	*
	* @param[in] ch ��ͨ����
	* @param[out] modal ��ͨ��DCDģ̬
	* @return
	* -  0���ɹ���
	* - -1��ʧ�ܣ�

	* @attention ʹ�ñ�����֮ǰ�����ȵ���HNC_DecoderGetData_Subscribe����
	* @par ʾ��:
	* @code
	//��ȡͨ��DCDģ̬
	SDcdModal = modal;
	Bit32 ret = HNC_DecoderGetData(0, modal);
	* @endcode

	* @see :: HNC_DecoderGetData_Subscribe
	*/
	Bit32 HNC_DecoderGetData(Bit32 ch, SDcdModal &modal);
	/*!	@brief ��ȡͨ��DCDģ̬��ɨ������е�m/s/tֵ
	*
	* @param[in] ch ��ͨ����
	* @param[out] modal ��ͨ��DCDģ̬
	* @param[out] m �����mָ��
	* @param[out] s �����sָ��
	* @param[out] t �����tָ��
	* @param[out] row ����ɨ�赽�����е�����
	* @return
	* -  0��ȡMSTֵ�ɹ���
	* - -1��ȡMSTֵʧ�ܣ�

	* @attention ʹ�ñ�����֮ǰ�����ȵ���HNC_DecoderGetData_Subscribe��HNC_RandomRow
	* @par ʾ��:
	* @code
	//��ȡͨ��DCDģ̬��ɨ������е�m/s/tֵ
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
	/*!	@brief ���Ľ���������
	*
	* @param[in] ch ��ͨ����
	* @param[in] cancel ���Ƿ��ģ�false��ʾ���ģ�true��ʾȡ������

	* @attention ʹ�û�ȡ����������֮ǰ�����ȵ��ñ�����
	* @par ʾ��:
	* @code
	//���Ľ���������
	HNC_DecoderGetData_Subscribe(0, false);
	* @endcode

	* @see :: HNC_DecoderGetData
	*/
	void HNC_DecoderGetData_Subscribe(Bit32 ch, bool cancel);
	/*!	@brief Mָ�����ý������
	* @param[in] index ��M�����
	* @param[in] group �����

	* @attention
	* @par ʾ��:
	* @code
	//Mָ�����ý������
	Hncapi::HNC_MCodeSetGroup(0, 5);
	* @endcode

	* @see ::
	*/
	void HNC_MCodeSetGroup(Bit16 index, Bit16 group);
	/*!	@brief ����M����Ķ�д��ʽ
	* @param[in] index ��M�����
	* @param[in] type ����д��ʽ

	* @attention
	* @par ʾ��:
	* @code
	//����M����Ķ�д��ʽ
	Hncapi::HNC_MCodeSetAttrib(0, 0);
	* @endcode

	* @see ::
	*/
	void HNC_MCodeSetAttrib(Bit16 index, Bit16 type);
#endif // _848_VER_
};

#endif