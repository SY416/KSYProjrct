#pragma once
#include "CUIObj.h"
#include "CInput.h"
#include "CTimer.h"

class Sample : public CDevice
{
	CTimer				m_GameTime;
	ID3D11SamplerState* m_pDefaultSS;
	ID3D11SamplerState* m_pDefaultSSPoint;
	ID3D11BlendState* m_pAlphaBlendEnable;
	ID3D11BlendState* m_pAlphaBlendDisable;
	ID3D11PixelShader* m_pPixelShaderAlphaTest = nullptr;

	std::vector<std::shared_ptr<CUIObj>> m_uiList;
	std::shared_ptr<CUIObj> m_bk;
	std::shared_ptr<CUIObj> m_ui;
	std::shared_ptr<CUIObj> m_ui_0;
	std::shared_ptr<CUIObj> m_ui_1;
	std::shared_ptr<CUIObj> m_number;
	
	CPlaneShape		m_DefaultPlane;

public:
	bool Init() override;
	bool Frame() override;
	bool Render() override;
	bool Release() override;

	bool    AlphaBlendState();
	bool	CreatePixelShader();
	bool	CreateSampleState();
};

