#pragma once
#include "Device.h"
#include "UiObj.h"
#include "Input.h"
#include "Timer.h"
#include "Effect.h"
#include "Write.h"
#include "SoundMgr.h"
class Core : public Device
{
public:
	Write			m_Write;
	Timer				m_GameTimer;
	PlaneShape	m_UiObj;
	ID3D11SamplerState* m_pDefaultSS = nullptr;
	ID3D11SamplerState* m_pDefaultSSPoint = nullptr;
	ID3D11BlendState* m_pAlphaBlendEnable = nullptr;
	ID3D11BlendState* m_pAlphaBlendDisable = nullptr;
public:
	PlaneShape						m_DefaultPlane;
public:
	bool    AlphaBlendState();
	bool	CreatePixelShader();
	bool	CreateSampleState();
public:
	virtual bool    Init() {
		return true;
	};
	virtual bool    Frame() {
		return true;
	};
	virtual bool    Render() {
		return true;
	};
	virtual bool    Release() {
		return true;
	};
	virtual bool	GameInit() override;
	virtual bool	GameFrame() override;
	virtual bool	GameRender()override;
	virtual bool	GameRelease()override;
};

