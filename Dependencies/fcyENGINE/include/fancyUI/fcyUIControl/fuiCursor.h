////////////////////////////////////////////////////////////////////////////////
/// @file  fuiCursor.h
/// @brief fancyUI ��ť
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include "../fcyUIBase/fuiControl.h"

#define FUICURSOR_LAYERPRIORITY 1000.f

////////////////////////////////////////////////////////////////////////////////
/// @brief UI ��ť
////////////////////////////////////////////////////////////////////////////////
class fuiCursor :
	public fuiControl
{
protected: // ����
	std::wstring m_CursorSprite;
	fcyColor m_BlendColor;
	
	fuiPropertyAccessor<std::wstring> m_CursorSprite_Accessor;
	fuiPropertyAccessor<fcyColor> m_BlendColor_Accessor;
protected: // ��ͼ��Դ
	fcyRefPointer<fuiSprite> m_pCursorSprite;
	
	void OnStyleChanged(fuiControl* pThis, fuiEventArgs* pArgs);

	void OnGlobalMouseMove(fuiControl* pThis, fuiEventArgs* pArgs);
public: // ʵ�ֽӿ�
	void Update(fDouble ElapsedTime);
	void Render(fuiGraphics* pGraph);
public:
	fuiCursor(fuiPage* pRootPage, const std::wstring& Name);
	~fuiCursor();
};
