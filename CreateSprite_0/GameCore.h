#pragma once
#include "CDevice.h"
#include "CUiObj.h"
#include "CInput.h"
#include "CTimer.h"
#include "CEffect.h"
#include "CDxWrite.h"
class GameCore : public CDevice
{
public:
	CDxWrite			m_dxWrite;
	CTimer				m_GameTime;
	ID3D11SamplerState* m_pDefaultSS = nullptr;
	ID3D11SamplerState* m_pDefaultSSPoint = nullptr;
	ID3D11BlendState* m_pAlphaBlendEnable = nullptr;
	ID3D11BlendState* m_pAlphaBlendDisable = nullptr;

public:
	CPlaneShape		m_DefaultPlane;

public:
	bool    AlphaBlendState();
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
	virtual bool	GameInit()		override;
	virtual bool	GameFrame()		override;
	virtual bool	GameRender()	override;
	virtual bool	GameRelease()	override;
};

