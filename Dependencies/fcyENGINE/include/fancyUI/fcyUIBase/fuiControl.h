////////////////////////////////////////////////////////////////////////////////
/// @file  fuiControl.h
/// @brief fancyUI �ؼ�����
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include "fuiProperty.h"
#include "fuiEvent.h"
#include "fuiStyle.h"

#include <string>
#include <unordered_map>

class fuiPage;

////////////////////////////////////////////////////////////////////////////////
/// @brief fancyUI�ؼ�����
////////////////////////////////////////////////////////////////////////////////
class fuiControl :
	public fcyRefObjImpl<fcyRefObj>, 
	public fuiPropertySet, 
	public fuiEventSet
{
	friend class fuiControl;
	friend class fuiPage;
protected:
	/// @brief ���ؼ�
	fuiPage* m_pRootPage;

	/// @brief �ؼ���ʽ
	fuiStyle* m_pStyle;

	/// @brief ������
	fuiControl* m_pParent;
	
	/// @brief �ӿؼ�
	/// @note  ����ԽСԽ�ײ�
	std::vector<fcyRefPointer<fuiControl> > m_SubControlList;

	// ========== ����&�¼� ==========
protected: // ����
	// ���Գ�Ա
	std::wstring m_Name;     ///< @brief [ֻ��] �ؼ���
	std::wstring m_Tag;      ///< @brief [��д] ��������
	fcyRect m_Rect;          ///< @brief [��д] �ؼ�λ��
	fBool m_bClip;           ///< @brief [��д] �ü�
	fBool m_bMouseTrans;     ///< @brief [��д] ��괩͸
	fFloat m_LayerPriority;  ///< @brief [��д] �������Ȩ
	fBool m_bVisiable;       ///< @brief [��д] �Ƿ�ɼ�

	// ������
	fuiPropertyAccessor<std::wstring> m_Name_Accessor;   ///< @brief �ؼ��������� 
	fuiPropertyAccessor<std::wstring> m_Tag_Accessor;    ///< @brief �������Է����� 
	fuiPropertyAccessor<fcyRect> m_Rect_Accessor;        ///< @brief �ؼ���Χ������
	fuiPropertyAccessor<float> m_Left_Accessor;          ///< @brief ����������� 
	fuiPropertyAccessor<float> m_Top_Accessor;           ///< @brief ���˾�������� 
	fuiPropertyAccessor<float> m_Width_Accessor;         ///< @brief ��ȷ����� 
	fuiPropertyAccessor<float> m_Height_Accessor;        ///< @brief �߶ȷ�����
	fuiPropertyAccessor<bool> m_Clip_Accessor;           ///< @brief �ü�������
	fuiPropertyAccessor<bool> m_MouseTrans_Accessor;     ///< @brief ��괩͸������
	fuiPropertyAccessor<float> m_LayerPriority_Accessor; ///< @brief �������Ȩ������
	fuiPropertyAccessor<bool> m_bVisiable_Accessor;      ///< @brief �ɼ��Է�����

	// ע������Ĭ������
	void registerAllProperty();
public: // �¼�
	/// @brief     ִ�пؼ��¼�
	/// @param[in] Str   �¼�����
	/// @param[in] pArgs �¼�����
	void ExecEvent(const std::wstring& Str, fuiEventArgs* pArgs = &fuiDelegate::EmptyEventArgs)
	{
		fuiEventSet::ExecEvent(Str, this, pArgs);
	}
protected:
	// ע������Ĭ���¼�
	void registerAllEvent();
	
	// ========== �ؼ��������Բ��� ==========
protected: // for fuiControl
	/// @brief  ����һ���ӿؼ�
	/// @return ���ظ��ؼ�ָ��
	virtual fuiControl* attachSubControl(fuiControl* pControl);
	/// @brief  �Ƴ�һ���ӿؼ�
	virtual void removeSubControl(fuiControl* pControl);
	/// @brief ��ѯ�ӿؼ��Ĳ��
	virtual fuInt getSubControlLayer(const fuiControl* pControl);
	/// @brief �����ӿؼ��Ĳ��
	virtual void setSubControlLayer(fuiControl* pControl, fInt Index);
	/// @brief �������пؼ�
	virtual void resortControl();
public:
	// === δע������ ===
	/// @brief ������Ļ����λ��
	fcyVec2 GetAbsolutePos();
	/// @brief ��ø��ؼ�
	fuiPage* GetRoot()const { return m_pRootPage; }
	/// @brief ��ø�����
	fuiControl* GetParent()const { return m_pParent; }
	/// @brief ���ø�����
	void SetParent(fuiControl* pParent);
	/// @brief ��ѯ�ڸ�����ľ��Բ��
	fuInt GetLayer()const;
	/// @brief     �����ڸ�����Ĳ��
	/// @param[in] Layer ��Բ�Σ�-1��ʾ���㣬0��ʾ�ײ�
	void SetLayer(fInt Layer);
	/// @brief �����ӿؼ���Ŀ
	virtual fuInt GetSubControlCount()const;
	/// @brief     �����ӿؼ�
	/// @note      ������
	/// @param[in] Layer ��Բ��
	virtual fuiControl* GetSubControl(fInt Layer);
	/// @brief ��ѯ�ؼ���ʽ
	virtual fuiStyle* GetControlStyle()const;
	/// @brief ���ÿؼ���ʽ
	virtual void SetControlStyle(fuiStyle* pStyle);

	// === ���ٷ������� ===
	/// @brief ��ÿؼ�Ψһ����
	const std::wstring& GetName()const { return m_Name; }
	/// @brief ���ض�������
	const std::wstring& GetTag()const { return m_Tag; }
	/// @brief ���ö�������
	void SetTag(const std::wstring& Str) { m_Tag = Str; }
	/// @brief ��ÿؼ�����λ��
	const fcyRect& GetRect()const { return m_Rect; }
	/// @brief ���ÿؼ�����λ��
	void SetRect(const fcyRect& Rect);
	/// @brief ��ÿؼ����λ��
	fFloat GetLeft()const { return m_Rect.a.x; }
	/// @brief ���ÿؼ����λ��
	void SetLeft(fFloat Value);
	/// @brief ��ÿؼ�����λ��
	fFloat GetTop()const { return m_Rect.a.y; }
	/// @brief ���ÿؼ�����λ��
	void SetTop(fFloat Value);
	/// @brief ���ؿؼ����
	fFloat GetWidth()const { return m_Rect.GetWidth(); }
	/// @brief ���ÿؼ����
	void SetWidth(fFloat Value);
	/// @brief ���ؿؼ��߶�
	fFloat GetHeight()const { return m_Rect.GetHeight(); }
	/// @brief ���ÿؼ��߶�
	void SetHeight(fFloat Value);
	/// @brief �����Ƿ�ü�
	fBool GetClip()const { return m_bClip; }
	/// @brief �����Ƿ�ü�
	void SetClip(fBool Value) { m_bClip = Value; }
	/// @brief �����Ƿ�͸
	fBool GetMouseTrans()const { return m_bMouseTrans; }
	/// @brief �����Ƿ�͸
	void SetMouseTrans(fBool Value) { m_bMouseTrans = Value; }
	/// @brief ���ز�����ȼ�
	fFloat GetLayerPriority()const { return m_LayerPriority; }
	/// @brief ���ò�����ȼ�
	void SetLayerPriority(fFloat Value);
	/// @brief ���ؿɼ���
	fBool GetVisiable()const { return m_bVisiable; }
	/// @brief ���ÿɼ���
	void SetVisiable(fBool Value) { m_bVisiable = Value; }
public:  // ��д����
	/// @brief ���¿ؼ�״̬
	virtual void Update(fDouble ElapsedTime);
	/// @brief ��Ⱦ�ؼ�
	virtual void Render(fuiGraphics* pGraph);
	/// @brief     Hit����
	/// @param[in] Pos ��Կؼ����Ͻǵ�λ��
	virtual fBool HitTest(const fcyVec2& Pos) { return true; }
private:   // ��ֹ����
	fuiControl(const fuiControl& Org);
	fuiControl& operator=(const fuiControl& Right);
protected: // ��ֹ����
	fuiControl(fuiPage* pRootControl, const std::wstring& Name);
protected: // ��ֹջ����
	virtual ~fuiControl();
};
