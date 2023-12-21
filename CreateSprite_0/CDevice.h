#pragma once
#include "CWindow.h"
#include <d3d11.h>
#include <d3dcompiler.h>
#include <string>
#include <memory>
#include <vector>
#include <list>
#include <map>

class CDevice : public CWindow
{
public:
	ID3D11Device* m_pd3dDevice = nullptr;
	ID3D11DeviceContext* m_pd3dContext = nullptr;
	ID3D11RenderTargetView* m_pRenderTargetView = nullptr;
	IDXGISwapChain* m_pSwapChain = nullptr;
public:
	bool CreateDevice();
	bool DeleteDevice();
};
