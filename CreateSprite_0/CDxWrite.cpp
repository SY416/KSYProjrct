#include "CDxWrite.h"
#include "Std.h"

void CDxWrite::Draw30(float x, float y, std::wstring msg, D2D1::ColorF color)
{
	m_pRT->BeginDraw();
	D2D1_RECT_F rtf = { x, y, 800.0f, 600.0f };
	m_pDefaultBrush->SetColor(color);
	m_pRT->DrawText(msg.c_str(), msg.size(), m_pTextFormat, rtf, m_pDefaultBrush);
	m_pRT->EndDraw();
}

void CDxWrite::Draw20(float x, float y, std::wstring msg, D2D1::ColorF color)
{
	m_pRT->BeginDraw();
	D2D1_RECT_F rtf = { x, y, 800.0f, 600.0f };
	m_pDefaultBrush->SetColor(color);
	m_pRT->DrawText(msg.c_str(), msg.size(), m_pTextFormat20, rtf, m_pDefaultBrush);
	m_pRT->EndDraw();
}

bool CDxWrite::Init(IDXGISurface* dxgiSurface)
{
	HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_MULTI_THREADED, &m_pd2dFactory);
	if (FAILED(hr))
	{
		return false;
	}

	hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED,
		__uuidof(IDWriteFactory),
		(IUnknown**)&m_pDWriteFactory);
	if (FAILED(hr))
	{
		return false;
	}

	hr = m_pDWriteFactory->CreateTextFormat(
		L"±Ã¼­",
		NULL,
		DWRITE_FONT_WEIGHT_NORMAL,
		DWRITE_FONT_STYLE_NORMAL,
		DWRITE_FONT_STRETCH_NORMAL,
		30,
		L"ko-kr",
		&m_pTextFormat);
	if (FAILED(hr))
	{
		return false;
	}

	hr = m_pDWriteFactory->CreateTextFormat(
		L"°íµñ",
		NULL,
		DWRITE_FONT_WEIGHT_NORMAL,
		DWRITE_FONT_STYLE_NORMAL,
		DWRITE_FONT_STRETCH_NORMAL,
		20,
		L"ko-kr",
		&m_pTextFormat20);
	if (FAILED(hr))
	{
		return false;
	}

	//FLOAT x, y;
	UINT dpi = GetDpiForWindow(g_hWnd);
	D2D1_RENDER_TARGET_PROPERTIES rtp;

	rtp.type = D2D1_RENDER_TARGET_TYPE_DEFAULT;
	rtp.pixelFormat.format = DXGI_FORMAT_UNKNOWN;
	rtp.pixelFormat.alphaMode = D2D1_ALPHA_MODE_PREMULTIPLIED;
	rtp.dpiX = dpi;
	rtp.dpiY = dpi;
	rtp.usage = D2D1_RENDER_TARGET_USAGE_NONE;
	rtp.minLevel = D2D1_FEATURE_LEVEL_DEFAULT;

	hr = m_pd2dFactory->CreateDxgiSurfaceRenderTarget(
		dxgiSurface,
		&rtp,
		&m_pRT);//m_pRT null
	if (FAILED(hr))
	{
		return false;
	}

	D2D1_COLOR_F color;
	color.r = 0.0f;
	color.g = 0.0f;
	color.b = 0.0f;
	color.a = 1.0f;
	
	hr = m_pRT->CreateSolidColorBrush(
		color,
		&m_pDefaultBrush);
	if (FAILED(hr))
	{
		return false;
	}

	return true;
}

bool CDxWrite::Frame()
{
	return true;
}

bool CDxWrite::Render()
{
	if (m_pRT == nullptr) return true;

	std::wstring msg = L"°¡³ª´Ù¶óMaBaSa";
	m_pRT->BeginDraw();
	D2D1_RECT_F rtf = { 0.0f, 0.0f, 800.0f, 600.0f };
	D2D1_COLOR_F color;
	color.r = 1.0f;
	color.g = 0.0f;
	color.b = 1.0f;
	color.a = 1.0f;
	m_pDefaultBrush->SetColor(color);
	m_pRT->DrawText(msg.c_str(), msg.size(), m_pTextFormat, rtf, m_pDefaultBrush);
	m_pRT->EndDraw();

	return true;
}

bool CDxWrite::Release()
{
	if (m_pTextFormat20)m_pTextFormat20->Release();
	if (m_pTextFormat)m_pTextFormat->Release();
	if (m_pDefaultBrush)m_pDefaultBrush->Release();
	if (m_pDWriteFactory)m_pDWriteFactory->Release();
	if (m_pRT)m_pRT->Release();
	if (m_pd2dFactory)m_pd2dFactory->Release();
	return true;
}
