////////////////////////////////////////////////////////////////////////////////
/// @file  fuiLabel.h
/// @brief fancyUI ��ǩ
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include "../fcyUIBase/fuiControl.h"

////////////////////////////////////////////////////////////////////////////////
/// @brief UI ��ǩ
////////////////////////////////////////////////////////////////////////////////
class fuiLabel :
	public fuiControl
{
public:
	enum HALIGNMODE
	{
		HALIGNMODE_LEFT,
		HALIGNMODE_CENTER,
		HALIGNMODE_RIGHT
	};
	enum VALIGNMODE
	{
		VALIGNMODE_TOP,
		VALIGNMODE_CENTER,
		VALIGNMODE_BOTTOM
	};
protected: // ��������
	std::vector<std::wstring> m_Lines;
	std::vector<float> m_LineWidth;
	float m_TextHeight;
protected: // ����
	std::wstring m_Text;
	std::wstring m_FontName;
	fcyColor m_FontColor;
	HALIGNMODE m_HAlign;   // ˮƽ����
	VALIGNMODE m_VAlign;   // ��ֱ����

	fuiPropertyAccessor<std::wstring> m_Text_Accessor;
	fuiPropertyAccessor<std::wstring> m_FontName_Accessor;
	fuiPropertyAccessor<fcyColor> m_FontColor_Accessor;
	fuiPropertyAccessor<HALIGNMODE> m_HAlign_Accessor;
	fuiPropertyAccessor<VALIGNMODE> m_VAlign_Accessor;
protected: // ��ͼ��Դ
	fcyRefPointer<fuiFont> m_Font;
	f2dFontProvider* m_pFontProvider;
	f2dFontRenderer* m_pFontRenderer;

	void OnTextChanged(fuiControl* pThis, fuiEventArgs* pArgs);
	void OnStyleChanged(fuiControl* pThis, fuiEventArgs* pArgs);
public: // ʵ�ֽӿ�
	void Update(fDouble ElapsedTime);
	void Render(fuiGraphics* pGraph);
public:
	fuiLabel(fuiPage* pRootPage, const std::wstring& Name);
	~fuiLabel();
};
