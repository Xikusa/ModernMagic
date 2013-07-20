#pragma once

#include "../Util/StringUtil.h"

#include <sstream>

#define theMMPropertyHelper ::ModernMagic::PropertyHelper::GetInstance()

#define MM_REG_PRO_PARSER_BEGIN(t, pro, str)\
	theMMPropertyHelper.RegisterParser<t>([](DyBasicProperty *pro, const String &str) -> bool {

#define MM_REG_PRO_PARSER_END });

MM_BEGIN

class PropertyHelper
{
public:
	// �����ݴ� String ��ȡ�����浽ָ�������еĽ�����
	// �����Ƿ����������ɹ�
	typedef std::function<bool(DyBasicProperty*, const String&)>	ParserFunc;
	typedef std::unordered_map<size_t, ParserFunc>					ParserFuncContainer;

public:
	static PropertyHelper &GetInstance() {
		static PropertyHelper helper;
		return helper;
	}

	/**
	 * ע��һ�� String �� Property �Ľ�����
	 *
	 * @param ��������Ե��������͵Ĺ�ϣֵ
	 * @param ����������
	 */
	void RegisterParser(size_t hash, const ParserFunc &parser);
	template <typename T>
	void RegisterParser(const ParserFunc &parser) {
		this->RegisterParser(typeid(T).hash_code(), parser);
	}

	/**
	 * ʹ�� stringstream ��ͨ�ý�����ע�ắ��
	 */
	template <typename T>
	void RegisterParser() {
		this->RegisterParser<T>([](DyBasicProperty *pro, const String &str) -> bool {
			using namespace std;
			
			T tmp;
			std::istringstream ss(str);
			ss >> tmp;

			if (ss.fail()) {
				return false;
			}

			// GetPropertyFromString ����������Ȩ���Ƿ�ƥ��
			// �������ֱ��ʹ�� UnsafeSet
			pro->UnsafeSet<T>(tmp);
			return true;
		});
	}

	/**
	 * �� str �е�����ת����ȡ��ָ����������
	 *
	 * @return �Ƿ��ȡ�ɹ�
	 */
	bool GetPropertyFromString(DyBasicProperty *pro, const String &str);
	bool GetPropertyFromString(Object *obj, const String &proname, const String &str);

private:
	PropertyHelper();

	ParserFuncContainer _pfuncs;
};

MM_END