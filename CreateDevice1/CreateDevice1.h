#pragma once
#include "CWindow.h"
#include <d3d11.h>
class CreateDevice : public CWindow
{
	ID3D11Device*			m_pd3dDevice = nullptr;
	ID3D11DeviceContext*	m_pd3dDeviceContext = nullptr;
	ID3D11RenderTargetView* m_pd3dRenderTargetView = nullptr;
	IDXGISwapChain*			m_pSwapChain = nullptr;
public:
	bool Init()		override;
	bool Render()	override;
	bool Release()	override;
};