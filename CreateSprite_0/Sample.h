#pragma once
#include "GameCore.h"

class Sample : public GameCore
{
public:
	ID3D11PixelShader* m_pPixelShaderAlphaTest = nullptr;

	std::vector<std::shared_ptr<CUIObj>> m_uiList;
	std::shared_ptr<CUIObj> m_bk;
	std::shared_ptr<CUIObj> m_ui;
	std::shared_ptr<CUIObj> m_ui_0;
	std::shared_ptr<CUIObj> m_ui_1;
	std::shared_ptr<CUIObj> m_number;
	std::shared_ptr<CEffect> m_EffectA;
	
	bool	CreatePixelShader();

public:
	bool Init() override;
	bool Frame() override;
	bool Render() override;
	bool Release() override;
};

