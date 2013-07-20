#pragma once

#include "../Util/StringUtil.h"

#define theMMClassFactory ::ModernMagic::ClassFactory::GetInstance()

MM_BEGIN

class ClassFactory
{
public:
	typedef std::function<Object*()>					ObjectCreator;
	typedef std::unordered_map<String, ObjectCreator>	CreatorContainer;

public:
	ClassFactory() {  }

	static ClassFactory &GetInstance()
	{
		static ClassFactory cf;
		return cf;
	}

	/**
	 * �� ClassFactory ע��һ���࣬�������ӵ����Ч��Ĭ�Ϲ��캯��
	 */
	template <typename T>
	void Register(const String &name) {
		this->Register(name, []() -> Object* {
			return new T();
		});
	}

	/**
	 * �� ClassFactory ע��һ����
	 *
	 * @param ���͵��ַ�����
	 * @param ���ô��������͵Ķ���ĺ���
	 */
	void Register(const String &name, const ObjectCreator &creator) {
		_creators[name] = creator;
	}

	/**
	 * ͨ�����͹�������һ������
	 */
	Object *CreateObject(const String &className) {
		auto iter = _creators.find(className);
		if (iter == _creators.end()) {
			return nullptr;
		}
		return iter->second();
	}

	/**
	 * 
	 */
	template <typename T>
	T *CreateObject(const String &className) {
		T *ptr = dynamic_cast<T*>(this->CreateObject(className));
		return ptr;
	}

private:
	CreatorContainer _creators;
};

MM_END