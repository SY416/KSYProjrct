#pragma once
#include "Window.h"
class Device : public Window
{
public:
	ID3D11Device* m_pd3dDevice = nullptr; // 기능 지원 점검과 자원 할당에 사용
	ID3D11DeviceContext* m_pd3dDeviceContext = nullptr; // 렌더 대상을 설정하고, 자원을 그래픽 파이프 라인에 묶고, GPU가 수행할 렌더링 명령들을 지시하는데 사용
	ID3D11RenderTargetView* m_pRenderTargetView = nullptr; // 렌더링 중에 액세스 할 수 있는 렌저링 대상 하위 리소스를 
	IDXGISwapChain* m_pSwapChain = nullptr;
public:
	bool    CreateDevice();
	bool    DeleteDevice();
};

