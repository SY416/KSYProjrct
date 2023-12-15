#pragma once
#include "CUIObj.h"

class Sample : public CDevice
{
	ID3D11SamplerState* m_pDefaultSS;
	ID3D11SamplerState* m_pDefaultSSPoint;
	ID3D11BlendState* m_pAlphaBlendEnable;
	ID3D11BlendState* m_pAlphaBlendDisable;
	ID3D11PixelShader* m_pPixelShaderAlphaTest = nullptr;

	CUIObj m_bk;
	CUIObj m_ui;
	CUIObj m_ui_0;
	CUIObj m_ui_1;

	CUINumber m_number;

public:
	bool Init() override;
	bool Render() override;
	bool Release() override;

	bool    AlphaBlendState();
	bool	CreatePixelShader();
	bool	CreateSampleState();
};

