////////////////////////////////////////////////////////////////////////////////
/// @file  fuiImageBox.h
/// @brief fancyUI ͼ���
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include "../fcyUIBase/fuiControl.h"

////////////////////////////////////////////////////////////////////////////////
/// @brief UI ͼ���
////////////////////////////////////////////////////////////////////////////////
class fuiImageBox :
	public fuiControl
{
public:
	enum IMAGEFILLMETHOD
	{
		IMAGEFILLMETHOD_LEFTTOP,
		IMAGEFILLMETHOD_FIT,
		IMAGEFILLMETHOD_STRETCH
	};
protected: // ����
	std::wstring m_Image;
	fcyColor m_BlendColor;
	IMAGEFILLMETHOD m_ImageFillMethod;
	
	fuiPropertyAccessor<std::wstring> m_Image_Accessor;
	fuiPropertyAccessor<fcyColor> m_BlendColor_Accessor;
	fuiPropertyAccessor<IMAGEFILLMETHOD> m_ImageFillMethod_Accessor;
protected: // ��ͼ��Դ
	fcyRefPointer<fuiSprite> m_pImageSprite;
	
	void OnStyleChanged(fuiControl* pThis, fuiEventArgs* pArgs);
public: // ʵ�ֽӿ�
	void Update(fDouble ElapsedTime);
	void Render(fuiGraphics* pGraph);
public:
	fuiImageBox(fuiPage* pRootPage, const std::wstring& Name);
	~fuiImageBox();
};
