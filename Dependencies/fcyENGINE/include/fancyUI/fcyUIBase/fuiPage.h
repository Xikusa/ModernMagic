////////////////////////////////////////////////////////////////////////////////
/// @file  fuiPage.h
/// @brief fancyUI ���ؼ�
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <fcyRefObj.h>
#include <fcyParser/fcyXml.h>

#include "fuiControl.h"
#include "fuiStyle.h"

////////////////////////////////////////////////////////////////////////////////
/// @brief fancyUI ���ؼ�
////////////////////////////////////////////////////////////////////////////////
class fuiPage :
	public fuiControl
{
	friend class fuiControl;
public:
	/// @brief ��갴��
	enum MOUSEBUTTON
	{
		MOUSEBUTTON_L,  ///< @brief ������
		MOUSEBUTTON_M,  ///< @brief ����м�
		MOUSEBUTTON_R   ///< @brief ����Ҽ�
	};
public:
	static F2DINPUTKEYCODE VKKeyToF2DKey(fuInt VKCode);
protected:
	/// @brief �ؼ���
	std::unordered_map<std::wstring, fuiControl*> m_ControlMap;

	/// @brief Ĭ����ʽ
	fcyRefPointer<fuiStyle> m_pDefaultStyle;

	/// @brief ��Ⱦ��
	fuiGraphics m_pGraphics;

	/// @brief DEBUG����
	fBool m_bDebug;

	/// @brief ���λ�õĿؼ�
	fuiControl* m_pControlAtMousePos;

	/// @brief ���λ�õĿؼ���������λ��
	fcyVec2 m_ControlMousePos;

	/// @brief ��һ����������ƶ���Ϣ�Ŀؼ����Ͻ�����
	fcyVec2 m_ControlOrigin;

	/// @brief ��һ����������ƶ���Ϣ�Ŀؼ�
	fuiControl* m_pLastMouseMoveControl;

	/// @brief �����������
	fuiControl* m_pLockMouseControl;

	/// @brief ��������Ϣ
	MOUSEBUTTON m_MouseUnlockEvent;

	/// @brief ���� ����һ�������������
	fuiControl* m_pFocus;

	/// @brief �����һ��λ��
	fcyVec2 m_MouseLastPos;
private:
	/// @brief  ���ز��ֽڵ�
	void loadLayoutNode(fcyXmlNode* pNode, fuiControl* pParent);
	/// @brief  DEBUG��ͼ
	void debugDraw(fuiGraphics* pGraph, fuiControl* pControl);
	/// @brief     �����괦�Ŀؼ�
	/// @param[in] pControl Ҫ���ԵĿؼ�
	/// @param[in] Pos      �����Ը��ؼ���λ��
	fuiControl* getControlAtPos(fuiControl* pControl, const fcyVec2& Pos, fcyVec2& PosOut);
	/// @brief �ݹ鴥����ʽ���
	void execStyleChanged(fuiControl* p);
	/// @brief Ͷ���Ӷ���ʧ������Ϣ
	void sendSubControlLostFocusMsg(fuiControl* pControl)
	{
		fuiObjectEventArgs tArgs;
		tArgs.SetObj(pControl);

		fuiControl* p = pControl->GetParent();

		while(p && p != p->GetRoot())
		{
			p->ExecEvent(L"OnSubcontrolLostFocus", &tArgs);
			p = p->GetParent();
		}
	}
	/// @brief Ͷ���Ӷ����ý�����Ϣ
	void sendSubControlGetFocusMsg(fuiControl* pControl)
	{
		fuiObjectEventArgs tArgs;
		tArgs.SetObj(pControl);

		fuiControl* p = pControl->GetParent();

		while(p && p != p->GetRoot())
		{
			p->ExecEvent(L"OnSubcontrolGetFocus");
			p = p->GetParent();
		}
	}
	/// @brief     ��������ƶ���Ϣ
	/// @param[in] MousePos ����ڸ��ؼ�����Ļ����λ��
	void sendMouseMove(const fcyVec2& MousePos);
	/// @brief     ������갴����Ϣ
	/// @param[in] Button   ��ť
	/// @param[in] MousePos ��ѡ���λ�ã����·�����Ϣ��SendMouseMove
	void sendMouseButtonDown(MOUSEBUTTON Button, fcyVec2* MousePos);
	/// @brief     �������ſ���Ϣ
	/// @param[in] Button   ��ť
	/// @param[in] MousePos ��ѡ���λ�ã����·�����Ϣ��SendMouseMove
	void sendMouseButtonUp(MOUSEBUTTON Button, fcyVec2* MousePos);
protected: // for fuiControl
	/// @brief  ע��һ���ؼ�
	void RegisterControl(fuiControl* pControl);
	/// @brief  ȡ���ؼ�ע��
	void UnregisterControl(fuiControl* pControl);
public:
	/// @brief  ���ز����ļ�
	void LoadLayoutFromFile(fcyStream* pStream);
	/// @brief  Ѱ�ҿؼ�
	/// @return �ؼ������û���NULL
	fuiControl* FindControl(const std::wstring& Name);
	/// @brief  �Ƿ�DEBUG
	fBool GetDebugMode()const { return m_bDebug; }
	/// @brief  DEBUGģʽ
	void SetDebugMode(fBool Value) { m_bDebug = Value; }
	/// @brief  ���������һ�ξ���λ��
	const fcyVec2& GetMouseLastPos() { return m_MouseLastPos; }
	/// @brief ���ؽ���
	fuiControl* GetFocusControl() { return m_pFocus; }
	/// @brief ���ý���
	void SetFocusControl(fuiControl* p);
public: // �ӿ�ʵ��
	fuiStyle* GetControlStyle()const;
	void SetControlStyle(fuiStyle* pStyle);

	void Update(fDouble ElapsedTime);
	void Render(fuiGraphics* pGraph=NULL);
public: // UI��Ϣ
	/// @brief ����f2d��Ϣ
	void DealF2DMsg(const f2dMsg& Msg);
public:
	fuiPage(const std::wstring& Name, f2dRenderer* pRenderer, f2dGraphics2D* pGraph);
protected:
	~fuiPage();
};
