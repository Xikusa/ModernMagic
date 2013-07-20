////////////////////////////////////////////////////////////////////////////////
/// @file   f2dRenderer.h
/// @brief  fancy2D������Ⱦ���ӿڶ���
/// @note   ������f2D����Ⱦ���ӿ�
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include "f2dInterface.h"

#include "f2dRenderDevice.h"

/// @addtogroup f2d��Ⱦϵͳ
/// @brief fancy2d�����е���Ⱦϵͳ���ṩ��2Dͼ�ε���Ⱦ֧�֡�
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @brief fancy2D ���鷭תѡ��
////////////////////////////////////////////////////////////////////////////////
enum F2DSPRITEFLIP
{
	F2DSPRITEFLIP_NONE,  ///< @brief �޷�ת
	F2DSPRITEFLIP_H,     ///< @brief ˮƽ��ת
	F2DSPRITEFLIP_V,     ///< @brief ��ֱ��ת
	F2DSPRITEFLIP_HV     ///< @brief ˮƽ��ֱ��ת
};

////////////////////////////////////////////////////////////////////////////////
/// @brief fancy2D ����
////////////////////////////////////////////////////////////////////////////////
struct f2dSprite : 
	public f2dInterface
{
	/// @brief ��þ���󶨵�����
	virtual f2dTexture2D* GetTexture()=0;

	/// @brief     ����һ���µ�����
	/// @param[in] pTex ����
	virtual fResult SetTexture(f2dTexture2D* pTex)=0;

	/// @brief ���ض�Ӧ����ľ���
	virtual const fcyRect& GetTexRect()const=0;

	/// @brief ���ö�Ӧ����ľ���
	virtual fResult SetTexRect(const fcyRect& Rect)=0;

	/// @brief �����ȵ�
	virtual const fcyVec2& GetHotSpot()const=0;

	/// @brief     �����ȵ�
	/// @param[in] Point �ȵ�
	virtual fResult SetHotSpot(const fcyVec2& Point)=0;

	/// @brief ���ط�ת��ʽ
	virtual F2DSPRITEFLIP GetFlipType()const=0;
	
	/// @brief     ���÷�ת��ʽ
	/// @param[in] Type ��ת��ʽ
	virtual fResult SetFlipType(F2DSPRITEFLIP Type)=0;

	/// @brief ����Zֵ
	virtual fFloat GetZ()const=0;

	/// @brief     ����Zֵ
	/// @param[in] Value �µ�Zֵ
	virtual fResult SetZ(fFloat Value)=0;

	/// @brief     ���ض������ɫ
	/// @param[in] Index ��������[0~3]������˳ʱ�뷽��λ
	virtual fcyColor GetColor(fuInt Index)const=0;

	/// @brief     �������ж������ɫ
	/// @param[in] Color �����ɫ
	virtual fResult SetColor(fcyColor Color)=0;

	/// @brief ���ö�����ɫ
	/// @param[in] Index ��������[0~3]������˳ʱ�뷽��λ
	/// @param[in] Color �����ɫ
	virtual fResult SetColor(fuInt Index, fcyColor Color)=0;

	/// @brief ���ƾ���
	/// @param[in] pGraph ��ͼ����ָ��
	/// @param[in] Dest   Ŀ�����
	virtual fResult Draw(f2dGraphics2D* pGraph, const fcyRect& Dest)=0;

	/// @brief ���ƾ���
	/// @param[in] pGraph ��ͼ����ָ��
	/// @param[in] Dest   Ŀ�����
	/// @param[in] SubTex ����������[0~1, 0~1]
	virtual fResult Draw(f2dGraphics2D* pGraph, const fcyRect& Dest, const fcyRect& SubTex)=0;

	/// @brief ���ƾ���
	/// @param[in] pGraph ��ͼ����ָ��
	/// @param[in] Center ������ʾ����
	virtual fResult Draw(f2dGraphics2D* pGraph, const fcyVec2& Center)=0;

	/// @brief ���ƾ���
	/// @param[in] pGraph ��ͼ����ָ��
	/// @param[in] Center ������ʾ����
	/// @param[in] Scale  ����
	virtual fResult Draw(f2dGraphics2D* pGraph, const fcyVec2& Center, const fcyVec2& Scale)=0;

	/// @brief ���ƾ���
	/// @param[in] pGraph ��ͼ����ָ��
	/// @param[in] Center ������ʾ����
	/// @param[in] Scale  ����
	/// @param[in] SubTex ����������[0~1, 0~1]
	virtual fResult Draw(f2dGraphics2D* pGraph, const fcyVec2& Center, const fcyVec2& Scale, const fcyRect& SubTex)=0;

	/// @brief ���ƾ���
	/// @param[in] pGraph   ��ͼ����ָ��
	/// @param[in] Center   ������ʾ����
	/// @param[in] Scale    ����
	/// @param[in] Rotation ˳ʱ����ת�Ƕȣ������ơ�
	virtual fResult Draw(f2dGraphics2D* pGraph, const fcyVec2& Center, const fcyVec2& Scale, fFloat Rotation)=0;
	
	/// @brief ���ƾ���
	/// @param[in] pGraph   ��ͼ����ָ��
	/// @param[in] Center   ������ʾ����
	/// @param[in] Scale    ����
	/// @param[in] Rotation ˳ʱ����ת�Ƕȣ������ơ�
	/// @param[in] SubTex   ����������[0~1, 0~1]
	virtual fResult Draw(f2dGraphics2D* pGraph, const fcyVec2& Center, const fcyVec2& Scale, fFloat Rotation, const fcyRect& SubTex)=0;
};

////////////////////////////////////////////////////////////////////////////////
/// @brief fancy2D�򵥼�������Ⱦ��
////////////////////////////////////////////////////////////////////////////////
struct f2dGeometryRenderer : 
	public f2dInterface
{
	/// @brief ���Zֵ
	virtual fFloat GetZ()=0;

	/// @brief     ����Zֵ
	/// @param[in] ZValue Zֵ
	virtual void SetZ(fFloat ZValue)=0;

	/// @brief     ��û��ʵ���ɫ
	/// @param[in] Index ����[0~2]��0=�����ɫ��1=�м���ɫ��2=�ڲ���ɫ
	virtual fcyColor GetPenColor(fuInt Index)=0;

	/// @brief     ���û�����ɫ
	/// @param[in] Index ����[0~2]��0=�����ɫ��1=�м���ɫ��2=�ڲ���ɫ
	/// @param[in] Color ��ɫֵ
	virtual void SetPenColor(fuInt Index, const fcyColor& Color)=0;

	/// @brief ��û��ʴ�С
	virtual fFloat GetPenSize()=0;

	/// @brief     ���û��ʴ�С
	/// @param[in] Size ���ʴ�С
	virtual void SetPenSize(fFloat Size)=0;

	/// @brief     ����
	/// @param[in] pGraph ��ͼָ��
	/// @param[in] Begin  ���
	/// @param[in] End    �յ�
	virtual fResult DrawLine(f2dGraphics2D* pGraph, const fcyVec2& Begin, const fcyVec2& End)=0;

	/// @brief     ���ƾ���
	/// @param[in] pGraph ��ͼָ��
	/// @param[in] Rect   ����
	virtual fResult DrawRectangle(f2dGraphics2D* pGraph, const fcyRect& Rect)=0;

	/// @brief     ����Բ
	/// @param[in] pGraph ��ͼָ��
	/// @param[in] Center ����
	/// @param[in] R      �뾶
	/// @param[in] Divide ϸ��
	virtual fResult DrawCircle(f2dGraphics2D* pGraph, const fcyVec2& Center, float R, fuInt Divide=50)=0;

	/// @brief     ������
	/// @param[in] pGraph    ��ͼָ��
	/// @param[in] Rect      �������
	/// @param[in] pColorArr ��ɫ����[0~3]��˳ʱ���ĸ��ǵ���ɫ
	virtual fResult FillRectangle(f2dGraphics2D* pGraph, const fcyRect& Rect, const fcyColor* pColorArr)=0;

	/// @brief     ���Բ
	/// @param[in] pGraph      ��ͼָ��
	/// @param[in] Center      ����
	/// @param[in] R           �뾶
	/// @param[in] CenterColor ������ɫ
	/// @param[in] BoundColor  �߽���ɫ
	/// @param[in] Divide      ϸ��
	virtual fResult FillCircle(f2dGraphics2D* pGraph, const fcyVec2& Center, float R, const fcyColor& CenterColor, const fcyColor& BoundColor, fuInt Divide=50)=0;
};

////////////////////////////////////////////////////////////////////////////////
/// @brief fancy2D ��������
////////////////////////////////////////////////////////////////////////////////
struct f2dGlyphInfo
{
	fcyRect GlyphPos;    ///< @brief �����������ϵ�uv����
	fcyVec2 GlyphSize;   ///< @brief ���δ�С
	fcyVec2 BrushPos;    ///< @brief �ʴ������������Ͻ�����
	fcyVec2 Advance;     ///< @brief �ʴ���ǰ����(����)
};

////////////////////////////////////////////////////////////////////////////////
/// @brief fancy2D �����ṩ��
////////////////////////////////////////////////////////////////////////////////
struct f2dFontProvider :
	public f2dInterface
{
	/// @brief ���Ĭ���и�
	virtual fFloat GetLineHeight()=0;

	/// @brief ��û��ߵ������ߵľ���
	virtual fFloat GetAscender()=0;

	/// @brief ��Ascender�෴
	virtual fFloat GetDescender()=0;

	/// @brief ���ػ�������
	virtual f2dTexture2D* GetCacheTexture()=0;

	/// @breif     �����ַ���
	/// @note      ��Զ�̬�������ֵ��ض�����
	/// @param[in] String �ַ���
	virtual fResult CacheString(fcStrW String)=0;

	/// @brief      ����һ������
	/// @param[in]  pGraph    ����ʹ�õ���Ⱦ�����ձ�ʾֻ��ѯ��������
	/// @param[in]  Character ������ַ�
	/// @param[out] InfoOut   ���ص���������
	virtual fResult QueryGlyph(f2dGraphics* pGraph, fCharW Character, f2dGlyphInfo* InfoOut)=0;
};

////////////////////////////////////////////////////////////////////////////////
/// @brief fancy2D ����ѡ��
////////////////////////////////////////////////////////////////////////////////
enum F2DFONTFLAG
{
	F2DFONTFLAG_NONE,    ///< @brief ��ѡ��
	F2DFONTFLAG_OUTLINE  ///< @brief �������
};

////////////////////////////////////////////////////////////////////////////////
/// @brief fancy2D ������Ƽ�����
////////////////////////////////////////////////////////////////////////////////
struct f2dFontRendererListener
{
	/// @brief          ��׼����������
	/// @param[in]      Index     ���ַ����ı����е�����
	/// @param[in]      Character �ַ�
	/// @param[in][out] DrawPos   ��ʼ����λ��
	/// @param[in][out] Adv       ǰ����
	/// @return         �����Ƿ񱻻��ƣ�ע�������Ƿ���ƣ�ǰ�����������á�
	virtual fBool OnGlyphBeginDraw(fuInt Index, fCharW Character, fcyVec2& DrawPos, fcyVec2& Adv) { return true; }

	/// @brief          ��������
	/// @param[in][out] pVerts �������飬��СΪ4
	virtual void OnGlyphCalcuCoord(f2dGraphics2DVertex pVerts[]) { }
};

////////////////////////////////////////////////////////////////////////////////
/// @brief fancy2D ������Ⱦ��
////////////////////////////////////////////////////////////////////////////////
struct f2dFontRenderer :
	public f2dInterface
{
	/// @brief ���ؼ�����
	virtual f2dFontRendererListener* GetListener()=0;
	
	/// @brief ���ü�����
	virtual void SetListener(f2dFontRendererListener* pListener)=0;

	/// @brief ���������ṩ��
	virtual f2dFontProvider* GetFontProvider()=0;

	/// @brief     ���������ṩ��
	/// @param[in] pProvider �����ṩ�ߣ��ǿ�
	virtual fResult SetFontProvider(f2dFontProvider* pProvider)=0;

	/// @brief ���Zֵ
	virtual fFloat GetZ()=0;

	/// @brief     ����Zֵ
	/// @param[in] ZValue Zֵ
	virtual void SetZ(fFloat ZValue)=0;

	/// @brief     ��ö�����ɫ
	/// @param[in] Index ����[0~3]
	virtual fcyColor GetColor(fuInt Index)=0;

	/// @brief     ����������ɫ
	/// @param[in] Color ������ɫ
	virtual void SetColor(const fcyColor& Color)=0;

	/// @brief     ���ö�����ɫ
	/// @param[in] Index ����[0~3]
	/// @param[in] Color ��ɫ
	virtual void SetColor(fuInt Index, const fcyColor& Color)=0;

	/// @brief ��÷�ת��ʽ
	virtual F2DSPRITEFLIP GetFlipType()=0;

	/// @brief     ���÷�ת��ʽ
	/// @param[in] Type ��ת��ʽ
	virtual void SetFlipType(F2DSPRITEFLIP Type)=0;

	/// @brief     ����һ���ַ������ջ��ƵĴ�С
	/// @param[in] String �ַ���
	virtual fcyRect MeasureString(fcStrW String)=0;

	/// @brief     ����һ���ַ������ջ��ƵĿ��
	/// @param[in] String �ַ���
	virtual fFloat MeasureStringWidth(fcStrW String)=0;

	/// @brief     ��������
	/// @param[in] pGraph   ��Ⱦ��
	/// @param[in] Text     ����
	/// @param[in] StartPos ������ʼ��׼
	virtual fResult DrawTextW(f2dGraphics2D* pGraph, fcStrW Text, const fcyVec2& StartPos)=0;

	/// @brief     ��������
	/// @param[in]  pGraph   ��Ⱦ��
	/// @param[in]  Text     ����
	/// @param[in]  Count    ��������Ϊ-1��Ϊȫ������
	/// @param[in]  StartPos ������ʼ��׼
	/// @param[out] PosOut   ������ֹλ�ã��ɿ�
	virtual fResult DrawTextW(f2dGraphics2D* pGraph, fcStrW Text, fuInt Count, const fcyVec2& StartPos, fcyVec2* PosOut)=0;

	/// @brief      ��������
	/// @param[in]  pGraph   ��Ⱦ��
	/// @param[in]  Text     ����
	/// @param[in]  Count    ��������Ϊ-1��Ϊȫ������
	/// @param[in]  Bias     ��б�ǣ�0Ϊ����б
	/// @param[in]  StartPos ������ʼ��׼
	/// @param[out] PosOut   ������ֹλ�ã��ɿ�
	virtual fResult DrawTextW(f2dGraphics2D* pGraph, fcStrW Text, fuInt Count, fFloat Bias, const fcyVec2& StartPos, fcyVec2* PosOut)=0;
};

////////////////////////////////////////////////////////////////////////////////
/// @brief fancy2D��Ⱦ��
////////////////////////////////////////////////////////////////////////////////
struct f2dRenderer
{
	virtual f2dRenderDevice* GetDevice()=0;  ///< @brief �����Ⱦ�豸ָ��

	// === ���󴴽� ===
	/// @brief      ����Sprite2D
	/// @param[in]  pTex �󶨵�����
	/// @param[out] pOut ������Sprite
	virtual fResult CreateSprite2D(f2dTexture2D* pTex, f2dSprite** pOut)=0;

	/// @brief      ����Sprite2D
	/// @param[in]  pTex �󶨵�����
	/// @param[in]  Org  ԭʼ�������
	/// @param[out] pOut ������Sprite
	virtual fResult CreateSprite2D(f2dTexture2D* pTex, const fcyRect& Org, f2dSprite** pOut)=0;

	/// @brief      ����Sprite2D
	/// @param[in]  pTex    �󶨵�����
	/// @param[in]  Org     ԭʼ�������
	/// @param[in]  HotSopt �ȵ�
	/// @param[out] pOut    ������Sprite
	virtual fResult CreateSprite2D(f2dTexture2D* pTex, const fcyRect& Org, const fcyVec2& HotSopt, f2dSprite** pOut)=0;

	/// @brief      ������������Ⱦ��
	/// @param[out] pOut �������Ⱦ������
	virtual fResult CreateGeometryRenderer(f2dGeometryRenderer** pOut)=0;

	/// @brief      ����������Ⱦ��
	/// @param[in]  pProvider ����Դ
	/// @param[out] pOut      ������������
	virtual fResult CreateFontRenderer(f2dFontProvider* pProvider, f2dFontRenderer** pOut)=0;

	/// @brief      �������ļ���������
	/// @param[in]  pStream   �����ļ�����ȡ�����ļ�
	/// @param[in]  FaceIndex ���ж��Face������ָ��������0������Чֵ��
	/// @param[in]  Flag      ����ѡ��
	/// @param[out] pOut      ���ص��������
	virtual fResult CreateFontFromFile(f2dStream* pStream, fuInt FaceIndex, const fcyVec2& FontSize, F2DFONTFLAG Flag, f2dFontProvider** pOut)=0;

	/// @brief      �������������
	/// @param[in]  pDefineFile ���嶨���ļ�
	/// @param[in]  pTex        ����
	/// @param[out] pOut        ���ص��������
	virtual fResult CreateFontFromTex(f2dStream* pDefineFile, f2dTexture2D* pTex, f2dFontProvider** pOut)=0;
	
	/// @brief      �������������
	/// @param[in]  pDefineFile ���嶨��
	/// @param[in]  pTex        ����
	/// @param[out] pOut        ���ص��������
	virtual fResult CreateFontFromTex(fcStrW pDefineText, f2dTexture2D* pTex, f2dFontProvider** pOut)=0;
};

/// @}
