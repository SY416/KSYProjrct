#include "CreateDevice1.h"

bool CreateDevice::Init()
{
    D3D_DRIVER_TYPE DriverType = D3D_DRIVER_TYPE_HARDWARE;
    UINT Flags = 0;
    D3D_FEATURE_LEVEL  pFeatureLevels[] =
    {
        D3D_FEATURE_LEVEL_11_0,
    };
    DXGI_SWAP_CHAIN_DESC sd;
    ZeroMemory(&sd, sizeof(sd));
    sd.BufferCount = 1;
    sd.BufferDesc.Width = 800;
    sd.BufferDesc.Height = 600;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = m_hWnd;
    sd.SampleDesc.Count = 1;
    sd.Windowed = true;
    //sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;;
    //sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
    //sd.SampleDesc.Quality = 0;
    //sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
    //sd.Flags = 0;
    
    HRESULT hr = D3D11CreateDeviceAndSwapChain(
        nullptr,
        DriverType,
        nullptr,
        Flags,
        pFeatureLevels,
        1,
        D3D11_SDK_VERSION,
        &sd,
        &m_pSwapChain,
        &m_pd3dDevice,
        nullptr,
        &m_pd3dDeviceContext);
    if (FAILED(hr))
    {
        return false;
    }

    ID3D11Texture2D* pBackBuffer = nullptr;
    hr = m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&pBackBuffer);
    hr = m_pd3dDevice->CreateRenderTargetView(pBackBuffer, nullptr, &m_pd3dRenderTargetView);
    if (pBackBuffer) pBackBuffer->Release();

    m_pd3dDeviceContext->OMSetRenderTargets(1, &m_pd3dRenderTargetView, nullptr);
    return true;
}


bool CreateDevice::Render()
{
    float clearColor[] = { 1,0,0,1 };
    m_pd3dDeviceContext->ClearRenderTargetView(m_pd3dRenderTargetView, clearColor);
    m_pSwapChain->Present(0, 0);
    return true;
}


bool CreateDevice::Release()
{
    if (m_pd3dDevice) m_pd3dDevice->Release();
    if (m_pd3dDeviceContext) m_pd3dDeviceContext->Release();
    if (m_pd3dRenderTargetView) m_pd3dRenderTargetView->Release();
    if (m_pSwapChain) m_pSwapChain->Release();

    m_pd3dDevice = nullptr;
    m_pd3dDeviceContext = nullptr;
    m_pd3dRenderTargetView = nullptr;
    m_pSwapChain = nullptr;

    return true;
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{

    CreateDevice win;

    win.SetWindow(hInstance, nCmdShow);
    win.Run();
    return 0;
}

