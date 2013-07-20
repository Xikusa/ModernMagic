////////////////////////////////////////////////////////////////////////////////
/// @file  fuiEvent.h
/// @brief fancyUI �ؼ��¼���ί��
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <fcyRefObj.h>
#include <fcyException.h>
#include <fcyMisc/fcyFunctor.h>

#include <fcyMath.h>

#include <vector>
#include <unordered_map>

class fuiControl;
class fuiEventArgs;

////////////////////////////////////////////////////////////////////////////////
/// @brief ί��
////////////////////////////////////////////////////////////////////////////////
class fuiDelegate
{
public:
	typedef fcyFunctor<void(fuiControl*, fuiEventArgs*)> EventCallBack;
	static fuiEventArgs EmptyEventArgs;
protected:
	std::vector<EventCallBack> m_FunctorList;
public:
	fuiDelegate& operator=(const fuiDelegate& Right);
	void operator()(fuiControl* pControl, fuiEventArgs* pArgs);
	fuiDelegate& operator+=(const EventCallBack& CallBack);
public:
	void Append(const EventCallBack& CallBack);
	void Clear();
	void Exec(fuiControl* pControl, fuiEventArgs* pArgs = &EmptyEventArgs);
public:
	fuiDelegate();
	fuiDelegate(const fuiDelegate& Right);
	~fuiDelegate();
};

////////////////////////////////////////////////////////////////////////////////
/// @brief �¼�����
////////////////////////////////////////////////////////////////////////////////
class fuiEventSet
{
protected:
	/// @brief �¼��б�
	std::unordered_map<std::wstring, fuiDelegate> m_EventList;

	/// @brief �¼���ֹ������
	std::unordered_map<std::wstring, fBool> m_EventFlag;
protected:
	/// @brief ע���¼�
	void RegisterEvent(const std::wstring& Str);
	/// @brief ִ���¼�
	void ExecEvent(const std::wstring& Str, fuiControl* pControl, fuiEventArgs* pArgs);
public: // �¼�����
	fuiDelegate& GetEvent(const std::wstring& EventName);
public:
	fuiEventSet() {}
	~fuiEventSet() {}
};

////////////////////////////////////////////////////////////////////////////////
/// @brief �ص��¼�����
////////////////////////////////////////////////////////////////////////////////
class fuiEventArgs
{
public:
	/// @brief �¼�����
	enum EVENTTYPE
	{
		EVENTTYPE_USER,         ///< @brief �û��¼�
		EVENTTYPE_CANCELABLE,   ///< @brief �ɳ����¼�
		EVENTTYPE_POSITION,     ///< @brief λ���¼�
		EVENTTYPE_OBJECT,       ///< @brief UI�����¼�
		EVENTTYPE_KEY,          ///< @brief �����¼�
		EVENTTYPE_CHAR,         ///< @brief �ַ��¼�
		EVENTTYPE_STRING,       ///< @brief �ַ����¼�
		EVENTTYPE_IMECANDIDATE  ///< @brief IME��ѡ���¼�
	};
public:
	/// @brief     ��ѯ�¼�
	/// @param[in] Type �Ƿ�֧�ֵ��¼�
	/// @return    ��֧���¼����򷵻���Ӧ�Ķ���
	virtual void* QueryEvent(EVENTTYPE Type)
	{
		return NULL;
	}
public:
	fuiEventArgs() {}
	virtual ~fuiEventArgs() {}
};

////////////////////////////////////////////////////////////////////////////////
/// @brief �ɳ����¼�
////////////////////////////////////////////////////////////////////////////////
class fuiCancelableEventArgs :
	public fuiEventArgs
{
protected:
	fBool m_bCancel;
public:
	fBool GetCancel()const
	{
		return m_bCancel;
	}
	void SetCancel(fBool V)
	{
		m_bCancel = V;
	}
public: // �ӿ�ʵ��
	void* QueryEvent(EVENTTYPE Type)
	{
		if(Type == EVENTTYPE_CANCELABLE)
			return this;
		else
			return NULL;
	}
public:
	fuiCancelableEventArgs()
		: m_bCancel(false) {}
	~fuiCancelableEventArgs() {}
};

////////////////////////////////////////////////////////////////////////////////
/// @brief λ���¼�
////////////////////////////////////////////////////////////////////////////////
class fuiPositionEventArgs :
	public fuiEventArgs
{
protected:
	fcyVec2 m_Pos;
public:
	const fcyVec2& GetPos()const
	{
		return m_Pos;
	}
	void SetPos(const fcyVec2& V)
	{
		m_Pos = V;
	}
public: // �ӿ�ʵ��
	void* QueryEvent(EVENTTYPE Type)
	{
		if(Type == EVENTTYPE_POSITION)
			return this;
		else
			return NULL;
	}
public:
	fuiPositionEventArgs() {}
	~fuiPositionEventArgs() {}
};

////////////////////////////////////////////////////////////////////////////////
/// @brief �����¼�
////////////////////////////////////////////////////////////////////////////////
class fuiObjectEventArgs :
	public fuiEventArgs
{
protected:
	fuiControl* m_pObj;
public:
	fuiControl* GetObj()const
	{
		return m_pObj;
	}
	void SetObj(fuiControl* V)
	{
		m_pObj = V;
	}
public: // �ӿ�ʵ��
	void* QueryEvent(EVENTTYPE Type)
	{
		if(Type == EVENTTYPE_OBJECT)
			return this;
		else
			return NULL;
	}
public:
	fuiObjectEventArgs() {}
	~fuiObjectEventArgs() {}
};

enum F2DINPUTKEYCODE;

////////////////////////////////////////////////////////////////////////////////
/// @brief �����¼�
////////////////////////////////////////////////////////////////////////////////
class fuiKeyEventArgs :
	public fuiEventArgs
{
protected:
	F2DINPUTKEYCODE m_pObj;
public:
	F2DINPUTKEYCODE GetKeyCode()const
	{
		return m_pObj;
	}
	void SetKeyCode(F2DINPUTKEYCODE V)
	{
		m_pObj = V;
	}
public: // �ӿ�ʵ��
	void* QueryEvent(EVENTTYPE Type)
	{
		if(Type == EVENTTYPE_KEY)
			return this;
		else
			return NULL;
	}
public:
	fuiKeyEventArgs() {}
	~fuiKeyEventArgs() {}
};

////////////////////////////////////////////////////////////////////////////////
/// @brief �ַ��¼�
////////////////////////////////////////////////////////////////////////////////
class fuiCharEventArgs :
	public fuiEventArgs
{
protected:
	fCharW m_Value;
public:
	fCharW GetChar()const
	{
		return m_Value;
	}
	void SetChar(fCharW V)
	{
		m_Value = V;
	}
public: // �ӿ�ʵ��
	void* QueryEvent(EVENTTYPE Type)
	{
		if(Type == EVENTTYPE_CHAR)
			return this;
		else
			return NULL;
	}
public:
	fuiCharEventArgs() {}
	~fuiCharEventArgs() {}
};

////////////////////////////////////////////////////////////////////////////////
/// @brief �ַ����¼�
////////////////////////////////////////////////////////////////////////////////
class fuiStringEventArgs :
	public fuiEventArgs
{
protected:
	std::wstring m_Str;
public:
	const std::wstring& GetString()const
	{
		return m_Str;
	}
	void SetString(const std::wstring& V)
	{
		m_Str = V;
	}
public: // �ӿ�ʵ��
	void* QueryEvent(EVENTTYPE Type)
	{
		if(Type == EVENTTYPE_STRING)
			return this;
		else
			return NULL;
	}
public:
	fuiStringEventArgs() {}
	~fuiStringEventArgs() {}
};

struct f2dIMECandidateList;

////////////////////////////////////////////////////////////////////////////////
/// @brief IME��ѡ���¼�
////////////////////////////////////////////////////////////////////////////////
class fuiIMECandidateEventArgs :
	public fuiEventArgs
{
protected:
	f2dIMECandidateList* m_pList;
public:
	f2dIMECandidateList* GetList()const
	{
		return m_pList;
	}
	void SetList(f2dIMECandidateList* pList)
	{
		m_pList = pList;
	}
public: // �ӿ�ʵ��
	void* QueryEvent(EVENTTYPE Type)
	{
		if(Type == EVENTTYPE_IMECANDIDATE)
			return this;
		else
			return NULL;
	}
public:
	fuiIMECandidateEventArgs() {}
	~fuiIMECandidateEventArgs() {}
};

