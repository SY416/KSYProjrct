#include "Device.h"

bool Device::CreateDevice()
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
    sd.BufferDesc.Width = 1366;
    sd.BufferDesc.Height = 768;
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
    hr = m_pd3dDevice->CreateRenderTargetView(pBackBuffer, nullptr, &m_pRenderTargetView);
    if (pBackBuffer) pBackBuffer->Release();

    m_pd3dDeviceContext->OMSetRenderTargets(1, &m_pRenderTargetView, nullptr);
    return true;
}


//bool Device::Render()
//{
//    float clearColor[] = { 1,1,1, };
//    m_pd3dDeviceContext->ClearRenderTargetView(m_pRenderTargetView, clearColor);
//    m_pSwapChain->Present(0, 0);
//    return true;
//}


bool Device::DeleteDevice()
{
    if (m_pd3dDevice) m_pd3dDevice->Release();
    if (m_pd3dDeviceContext) m_pd3dDeviceContext->Release();
    if (m_pRenderTargetView) m_pRenderTargetView->Release();
    if (m_pSwapChain) m_pSwapChain->Release();

    m_pd3dDevice = nullptr;
    m_pd3dDeviceContext = nullptr;
    m_pRenderTargetView = nullptr;
    m_pSwapChain = nullptr;

    return true;
}