////////////////////////////////////////////////////////////////////////////////
/// @file  fuiIME.h
/// @brief fancyUI ���뷨�ؼ�
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <fcyRefObj.h>
#include <fcyParser/fcyXml.h>

#include "fuiLabel.h"

#define FUIIME_LAYERPRIORITY 900.f

////////////////////////////////////////////////////////////////////////////////
/// @brief fancyUI ���뷨�ؼ�
////////////////////////////////////////////////////////////////////////////////
class fuiIME :
	public fuiControl
{
protected: // ����
	std::wstring m_SingleLineSkin;  ///< @brief ����Ƥ��
	std::wstring m_MultiLineSkin;   ///< @brief ����Ƥ��
	fBool m_bMultiLine;             ///< @brief ����ģʽ
	fBool m_bHMode;                 ///< @brief ˮƽģʽ
	fcyVec2 m_InputBoxOffset;       ///< @brief �����������λ��
	fcyRect m_CompositionMargin;    ///< @brief ƴд��߾�
	fcyRect m_CandidateMargin;      ///< @brief ��ѡ��߾�
	std::wstring m_FontName;        ///< @brief ��������
	fcyColor m_FontColor;           ///< @brief ������ɫ
	fcyColor m_ActiveFontColor;     ///< @brief ����������ɫ
	fcyColor m_CandidateFontColor;  ///< @brief ��ѡ������ɫ

	// ������
	fuiPropertyAccessor<std::wstring> m_SingleLineSkin_Accessor;
	fuiPropertyAccessor<std::wstring> m_MultiLineSkin_Accessor;
	fuiPropertyAccessor<fBool> m_bMultiLine_Accessor;
	fuiPropertyAccessor<fBool> m_bHMode_Accessor;
	fuiPropertyAccessor<fcyVec2> m_InputBoxOffset_Accessor;
	fuiPropertyAccessor<fcyRect> m_CompositionMargin_Accessor;
	fuiPropertyAccessor<fcyRect> m_CandidateMargin_Accessor;
	fuiPropertyAccessor<std::wstring> m_FontName_Accessor;
	fuiPropertyAccessor<fcyColor> m_FontColor_Accessor;
	fuiPropertyAccessor<fcyColor> m_ActiveFontColor_Accessor;
	fuiPropertyAccessor<fcyColor> m_CandidateFontColor_Accessor;
protected: // ��Ⱦ����
	fcyRefPointer<fuiBorderSprite> m_pSingleLineSkin;
	fcyRefPointer<fuiBorderSprite> m_pMultiLineSkin;
	fcyRefPointer<fuiFont> m_Font;
	f2dFontProvider* m_pFontProvider;
	f2dFontRenderer* m_pFontRenderer;
protected: // ���뷨����
	std::wstring m_CompositionStr;
	std::vector<std::wstring> m_CandidateList;
	fcyRect m_CompStrSize;
	fcyRect m_CandidateStrSize;
	fInt m_ActiveIndex;

	fBool m_bInInput;
	fBool m_bInComposition;
protected:
	void recalcuStr();
	void readCandidate(f2dIMECandidateList* pList);
	void showIME();
protected:
	void OnIMEClosed(fuiControl* pThis, fuiEventArgs* pArgs);
	void OnIMEActivated(fuiControl* pThis, fuiEventArgs* pArgs);
	void OnIMEStartComposition(fuiControl* pThis, fuiEventArgs* pArgs);
	void OnIMEEndComposition(fuiControl* pThis, fuiEventArgs* pArgs);
	void OnIMEComposition(fuiControl* pThis, fuiEventArgs* pArgs);
	void OnIMEOpenCandidate(fuiControl* pThis, fuiEventArgs* pArgs);
	void OnIMECloseCandidate(fuiControl* pThis, fuiEventArgs* pArgs);
	void OnIMEChangeCandidate(fuiControl* pThis, fuiEventArgs* pArgs);

	void OnTextInputStart(fuiControl* pThis, fuiEventArgs* pArgs);
	void OnTextInputPosChanged(fuiControl* pThis, fuiEventArgs* pArgs);
	void OnTextInputEnd(fuiControl* pThis, fuiEventArgs* pArgs);

	void OnStyleChanged(fuiControl* pThis, fuiEventArgs* pArgs);
public: // ʵ�ֽӿ�
	void Update(fDouble ElapsedTime);
	void Render(fuiGraphics* pGraph);
public:
	fuiIME(fuiPage* pRootPage, const std::wstring& Name);
	~fuiIME();
};
