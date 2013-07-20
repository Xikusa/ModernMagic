////////////////////////////////////////////////////////////////////////////////
/// @file  fuiStyle.h
/// @brief fancyUI �ؼ���ʽ
/// @note  ����ؼ���Ⱦ��Դ�Ĺ���
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include "fuiGraphics.h"
#include "fuiRes.h"

#include <unordered_map>

////////////////////////////////////////////////////////////////////////////////
/// @brief ��ʽ����
////////////////////////////////////////////////////////////////////////////////
class fuiStyle :
	public fcyRefObjImpl<fcyRefObj>
{
protected:
	std::unordered_map<std::wstring, fcyRefPointer<fuiRes>> m_ResList;
public:
	/// @brief ע����Դ
	void RegisterRes(const std::wstring Name, fuiRes* pRes);
	
	/// @brief �Ƴ���Դ
	void UnregisterRes(const std::wstring Name);

	/// @brief ��ѯ��Դ
	/// @note  ����������
	fuiRes* QueryRes(const std::wstring Name);

	/// @brief ���ļ�����
	void LoadResFromFile(f2dStream* pStream, fuiResProvider* pProvider);
public:
	fuiStyle();
	~fuiStyle();
};
