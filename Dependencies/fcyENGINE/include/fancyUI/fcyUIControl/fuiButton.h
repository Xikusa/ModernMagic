////////////////////////////////////////////////////////////////////////////////
/// @file  fuiButton.h
/// @brief fancyUI ��ť
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include "../fcyUIBase/fuiControl.h"

#include "fuiLabel.h"

////////////////////////////////////////////////////////////////////////////////
/// @brief UI ��ť
////////////////////////////////////////////////////////////////////////////////
class fuiButton :
	public fuiControl
{
protected:
	enum BUTTONSTATE
	{
		BUTTONSTATE_DEFAULT,
		BUTTONSTATE_MOUSEON,
		BUTTONSTATE_MOUSEDOWN
	};
protected: // �ӿؼ�
	fcyRefPointer<fuiLabel> m_pTextLabel;
protected: // ����
	std::wstring m_DefaultSprite;
	std::wstring m_MouseOnSprite;
	std::wstring m_MouseDownSprite;
	fcyVec2 m_LabelOffsetWhenDown;

	fuiPropertyAccessor<std::wstring> m_DefaultSprite_Accessor;
	fuiPropertyAccessor<std::wstring> m_MouseOnSprite_Accessor;
	fuiPropertyAccessor<std::wstring> m_MouseDownSprite_Accessor;
	fuiPropertyAccessor<fcyVec2> m_LabelOffsetWhenDown_Accessor;
protected: // ״̬
	BUTTONSTATE m_ButtonState;
protected: // ��ͼ��Դ
	fcyRefPointer<fuiBorderSprite> m_pDefault;
	fcyRefPointer<fuiBorderSprite> m_pMouseOn;
	fcyRefPointer<fuiBorderSprite> m_pMouseDown;
protected:
	void OnStyleChanged(fuiControl* pThis, fuiEventArgs* pArgs);
	void OnSizeChanged(fuiControl* pThis, fuiEventArgs* pArgs);

	void OnMouseMove(fuiControl* pThis, fuiEventArgs* pArgs);
	void OnMouseLeave(fuiControl* pThis, fuiEventArgs* pArgs);
	void OnMouseLButtonDown(fuiControl* pThis, fuiEventArgs* pArgs);
	void OnMouseLButtonUp(fuiControl* pThis, fuiEventArgs* pArgs);
public: // ʵ�ֽӿ�
	void Update(fDouble ElapsedTime);
	void Render(fuiGraphics* pGraph);
public:
	fuiButton(fuiPage* pRootPage, const std::wstring& Name);
	~fuiButton();
};
