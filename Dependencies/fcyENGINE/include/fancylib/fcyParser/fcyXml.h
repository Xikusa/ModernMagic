//////////////////////////////////////////////////////////////////////////
/// @file  fcyXml.h
/// @brief fcyXml������
/// @note  ����֧��һ���ʽ��Xml
//////////////////////////////////////////////////////////////////////////
#pragma once
#include "fcyLexicalParser.h"

#include <unordered_map>
#include <string>
#include <vector>

/// @addtogroup fancy���������
/// @{

//////////////////////////////////////////////////////////////////////////
/// @brief XML�ڵ�
//////////////////////////////////////////////////////////////////////////
class fcyXmlNode
{
	friend class fcyXml;
public:
	class AttributeIterator
	{
		friend class fcyXmlNode;
	private:
		std::unordered_map<std::wstring, std::wstring>::iterator i;
	public:
		fcStrW GetName()const
		{
			return i->first.c_str();
		}
		fcStrW GetContent()const
		{
			return i->second.c_str();
		}
		void SetContent(fcStrW Content)
		{
			i->second = Content;
		}
	public:
		AttributeIterator& operator=(const AttributeIterator& Right)
		{
			i = Right.i;
		}
		fBool operator==(const AttributeIterator& Right)const
		{
			return (i == Right.i);
		}
		fBool operator!=(const AttributeIterator& Right)const
		{
			return (i != Right.i);
		}
		AttributeIterator& operator--()
		{
			i--;
			return *this;
		}
		AttributeIterator& operator++()
		{
			i++;
			return *this;
		}
	protected:
		AttributeIterator(const std::unordered_map<std::wstring, std::wstring>::iterator& _i)
			: i(_i) {}
	public:
		AttributeIterator() {}
		AttributeIterator(const AttributeIterator& Org)
			: i(Org.i) {}
	};
private:
	std::wstring m_Name;                                               ///< @brief ����
	std::wstring m_Content;                                            ///< @brief �ڵ�����
	std::vector<fcyXmlNode> m_Nodes;                                   ///< @brief �ڵ��б�
	std::unordered_map<std::wstring, std::wstring> m_Atti;             ///< @brief �����б�
	std::unordered_map<std::wstring, std::vector<fcyXmlNode*>> m_Dict; ///< @brief �ڵ㻺��
protected:
	/// @brief      д���ַ���
	/// @param[out] pOut        ������ַ���
	/// @param[in]  Indentation ����
	void writeToStr(std::wstring& pOut, fuInt Indentation);
public:
	/// @brief ����
	fcyXmlNode& operator=(const fcyXmlNode& Org);
public:
	/// @brief ��ýڵ����
	fcStrW GetName()const;

	/// @brief ���ýڵ����
	void SetName(fcStrW Name);

	/// @brief ��ýڵ��ı�
	fcStrW GetContent()const;

	/// @brief ���ýڵ��ı�
	void SetContent(fcStrW Context);

	/// @brief ����ӽڵ����
	fuInt GetNodeCount()const;

	/// @brief ���ͬ���ӽڵ����
	fuInt GetNodeCount(fcStrW NodeName);
	
	/// @brief     ����ӽڵ�
	/// @param[in] Index �ӽڵ�����
	/// @return    �������Խ�磬�򷵻�NULL
	fcyXmlNode* GetNode(fuInt Index);

	/// @brief     ����ӽڵ�
	/// @param[in] Name  �ڵ����
	/// @param[in] Index ��ͬ�����б��е�����
	/// @return    �������Խ����߲����ڼ������򷵻�NULL
	fcyXmlNode* GetNodeByName(fcStrW Name, fuInt Index);

	/// @brief     ׷���ӽڵ�
	/// @note      ���Զ�����׷�ӵ��ӽڵ�
	/// @param[in] pNode �½ڵ��ָ��
	void AppendNode(const fcyXmlNode& pNode);

	/// @brief     �Ƴ��ӽڵ�
	/// @param[in] Index �ӽڵ������
	/// @return    ���ز����Ƿ�ɹ�
	fResult RemoveNode(fuInt Index);

	/// @brief ����ӽڵ㲢�ͷ��ڴ�
	void ClearNode();

	/// @brief     �������
	/// @param[in] Name ������
	/// @return    ����ֵ
	fcStrW GetAttribute(fcStrW Name)const;

	/// @brief     �������
	/// @param[in] Name  ������
	/// @param[in] Value ����ֵ
	void SetAttribute(fcStrW Name, fcStrW Value);

	/// @brief     �Ƿ�������
	/// @param[in] Name ������
	/// @return    ���������Ƿ����
	fBool HasAttribute(fcStrW Name)const;

	/// @brief ���ص�һ������
	AttributeIterator GetFirstAttribute();

	/// @brief �������һ������
	AttributeIterator GetLastAttribute();

	/// @brief �Ƴ�����
	fBool RemoveAttribute(fcStrW Name);
	
	/// @brief �Ƴ�����
	AttributeIterator RemoveAttribute(AttributeIterator Iter);
public:
	/// @brief ���캯��
	fcyXmlNode();
	/// @brief �������캯��
	fcyXmlNode(const fcyXmlNode& Org);
	~fcyXmlNode();
};

//////////////////////////////////////////////////////////////////////////
/// @brief XML������
/// @note  ��������ֻ�������һ���ӽڵ㣬�����XML�Ϸ��Խ��м�顣
//////////////////////////////////////////////////////////////////////////
class fcyXml
{
private:
	fcyXmlNode m_pRoot;    ///< @brief ���ڵ�
private: // Ԥ����
	fBool checkUTF8(fcyStream* pStream);
	fBool checkUTF16LE(fcyStream* pStream);
	std::wstring preprocessXml(fcyStream* pStream);                    ///< @brief Ԥ����������ַ�����
private: // ����
	fBool ignoreComment(fcyLexicalReader& tReader);                    ///< @brief ����ע��
	fBool ignorePreprocess(fcyLexicalReader& tReader);                 ///< @brief ����Ԥ����ָ��
	fBool tryReadCDATA(fcyLexicalReader& tReader, std::wstring& tOut); ///< @brief ��ͼ��ȡCDATA
	fCharW praseEscape(fcyLexicalReader& tReader);                     ///< @brief ����ת���
	std::wstring readName(fcyLexicalReader& tReader);                  ///< @brief ��ȡ����
	std::wstring readString(fcyLexicalReader& tReader);                ///< @brief ��ȡ�ַ���
	void readAttribute(fcyLexicalReader& tReader, fcyXmlNode* pNode);  ///< @brief ��ȡ����
	void readNodes(fcyLexicalReader& tReader, fcyXmlNode* pNode);      ///< @brief ��ȡ�ڵ�
	fcyXmlNode parserNode(fcyLexicalReader& tReader);                 ///< @brief �����ڵ�
protected:
	/// @brief ��ֹ��������
	fcyXml(const fcyXml& Org) {}
	/// @brief ��ֹ��������
	fcyXml& operator=(const fcyXml& Org) {}
public:
	fcyXmlNode* GetRoot();                 ///< @brief ��ø��ڵ�
	void SetRoot(const fcyXmlNode& pNode); ///< @brief ���ø��ڵ�

	void WriteToStr(std::wstring& pOut); ///< @brief д���ַ���
	void WriteToStream(fcyStream* pOut); ///< @brief д����
public:
	fcyXml();                            ///< @brief ����յ�XML
	fcyXml(const std::wstring& Str);     ///< @brief ���ַ�������XML
	fcyXml(fcyStream* pStream);          ///< @brief ��������Xml
	~fcyXml();
};

/// @}