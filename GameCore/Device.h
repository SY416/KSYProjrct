#pragma once
#include "Window.h"
class Device : public Window
{
public:
	ID3D11Device* m_pd3dDevice = nullptr; // ��� ���� ���˰� �ڿ� �Ҵ翡 ���
	ID3D11DeviceContext* m_pd3dDeviceContext = nullptr; // ���� ����� �����ϰ�, �ڿ��� �׷��� ������ ���ο� ����, GPU�� ������ ������ ��ɵ��� �����ϴµ� ���
	ID3D11RenderTargetView* m_pRenderTargetView = nullptr; // ������ �߿� �׼��� �� �� �ִ� ������ ��� ���� ���ҽ��� 
	IDXGISwapChain* m_pSwapChain = nullptr;
public:
	bool    CreateDevice();
	bool    DeleteDevice();
};

