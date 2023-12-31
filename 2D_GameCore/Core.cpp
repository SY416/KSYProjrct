#include "Core.h"
bool Core::CreateSampleState()
{
    D3D11_SAMPLER_DESC sd;
    ZeroMemory(&sd, sizeof(sd));
    sd.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
    sd.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
    sd.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
    sd.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;

    HRESULT hr = m_pd3dDevice->CreateSamplerState(&sd, &m_pDefaultSS);
    if (FAILED(hr)) return false;

    ZeroMemory(&sd, sizeof(sd));
    sd.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
    sd.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
    sd.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
    sd.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;

    hr = m_pd3dDevice->CreateSamplerState(&sd, &m_pDefaultSSPoint);
    return true;
}
bool Core::AlphaBlendState()
{
    D3D11_BLEND_DESC bsd;
    ZeroMemory(&bsd, sizeof(bsd));
    //bsd.AlphaToCoverageEnable = TRUE;
    bsd.RenderTarget[0].BlendEnable = TRUE;

    // rgb  
 //FINALCOLOR = DEST COLOR* (1-SRCALPHA) + SRC COLOR * SRC ALPAH
    bsd.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
    bsd.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
    bsd.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;

    // A
    bsd.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
    bsd.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
    bsd.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
    bsd.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;


    HRESULT hr = m_pd3dDevice->CreateBlendState(
        &bsd,
        &m_pAlphaBlendEnable);

    bsd.RenderTarget[0].BlendEnable = FALSE;
    hr = m_pd3dDevice->CreateBlendState(
        &bsd,
        &m_pAlphaBlendDisable);

    return true;
}
bool Core::GameInit()
{
    CreateDevice();

    SoundMgr::Get().Init();

    IDXGISurface* dxgiSurface;
    HRESULT hr = m_pSwapChain->GetBuffer(0, __uuidof(IDXGISurface), (void**)&dxgiSurface);
    if (SUCCEEDED(hr))
    {
        m_Write.Init(dxgiSurface);
        if (dxgiSurface)dxgiSurface->Release();
    }

    m_GameTimer.Init();
    Input::Get().Init();
    TextureMgr::Get().Set(m_pd3dDevice, m_pd3dContext);
    AlphaBlendState();
    CreateSampleState();

    m_DefaultPlane.m_pd3dDevice = m_pd3dDevice;
    m_DefaultPlane.m_pd3dContext = m_pd3dContext;
    m_DefaultPlane.m_rtClient = m_rtClient;

    m_DefaultPlane.m_VertexList.emplace_back(TVector3(0.0f, 0.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 0.0f));      // 0
    m_DefaultPlane.m_VertexList.emplace_back(TVector3(1366.0f, 0.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 0.0f));    // 1
    m_DefaultPlane.m_VertexList.emplace_back(TVector3(1366.0f, 768.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 1.0f));  // 2
    m_DefaultPlane.m_VertexList.emplace_back(TVector3(0.0f, 768.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 1.0f));    // 3
    if (!m_DefaultPlane.Create(L"DefaultPlane", L"../../data/bk1.png"))
    {
        return false;
    }

    Init();
    return true;
}
bool Core::GameFrame()
{
    m_GameTimer.Frame();
    Input::Get().Frame();
    SoundMgr::Get().Frame();
    m_UiObj.Frame();

    Frame();
    return true;
}
bool Core::GameRender()
{
    float clearColor[] = { 0.0f,0.0f,0.0f,1 };
    m_pd3dContext->ClearRenderTargetView(m_pRenderTargetView, clearColor);

    m_pd3dContext->PSSetSamplers(0, 1, &m_pDefaultSS);
    m_pd3dContext->OMSetBlendState(m_pAlphaBlendEnable, 0, -1);

    m_pd3dContext->UpdateSubresource(m_DefaultPlane.m_pVertexBuffer,
        0,
        nullptr,
        &m_DefaultPlane.m_VertexList.at(0),
        0,
        0);
    m_DefaultPlane.Render();

    Render();

    m_GameTimer.Render();
    Input::Get().Render();
    m_Write.Render();
    //m_UiObj.Render(m_pd3dContext);

    m_pSwapChain->Present(0, 0);
    return true;
}
bool Core::GameRelease()
{
    Release();
    if (m_pDefaultSS)m_pDefaultSS->Release();
    if (m_pDefaultSSPoint)m_pDefaultSSPoint->Release();
    if (m_pAlphaBlendEnable)m_pAlphaBlendEnable->Release();
    if (m_pAlphaBlendDisable)m_pAlphaBlendDisable->Release();

    m_DefaultPlane.Release();
    Input::Get().Release();
    m_GameTimer.Release();
    m_Write.Release();

    DeleteDevice();
    return true;
}