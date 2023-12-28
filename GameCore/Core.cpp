#include "Core.h"

bool Core::GameInit()
{
	CreateDevice();
	
	TextureMgr::Get().Set(m_pd3dDevice, m_pd3dDeviceContext);

	m_DefaultPlane.m_pd3dDevice = m_pd3dDevice;
	m_DefaultPlane.m_pd3dDeviceContext = m_pd3dDeviceContext;
	m_DefaultPlane.m_rtClient = m_rtClient;

	m_DefaultPlane.m_VertexList.emplace_back(TVector3(0.0f, 0.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 0.0f));      // 0
	m_DefaultPlane.m_VertexList.emplace_back(TVector3(1366, 0.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 0.0f));    // 1
	m_DefaultPlane.m_VertexList.emplace_back(TVector3(1366, 768, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 1.0f));  // 2
	m_DefaultPlane.m_VertexList.emplace_back(TVector3(0.0f, 768, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 1.0f));    // 3
	if (!m_DefaultPlane.Create(L"BackGround", L"../../data/bk.png"))
	{
		return false;
	}

	Init();

	return true;
}

bool Core::GameRender()
{
	float clearColor[] = { 1,1,1, };
	m_pd3dDeviceContext->ClearRenderTargetView(m_pRenderTargetView, clearColor);

	Render();

	m_pSwapChain->Present(0, 0);
	return true;
}

bool Core::GameRelease()
{
	Release();
	DeleteDevice();
	return true;
}
