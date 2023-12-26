#include "Core.h"

bool Core::GameInit()
{
	CreateDevice();
	
	m_DefaultTexture.m_pd3dDevice = m_pd3dDevice;
	m_DefaultTexture.m_pd3dDeviceContext = m_pd3dDeviceContext;
	//m_DefaultTexture.m_rtClient = m_rtClient;

	return true;
}

bool Core::GameRender()
{
	float clearColor[] = { 1,1,1, };
	m_pd3dDeviceContext->ClearRenderTargetView(m_pRenderTargetView, clearColor);
	m_pSwapChain->Present(0, 0);
	return true;
}

bool Core::GameRelease()
{
	Release();
	DeleteDevice();
	return true;
}
