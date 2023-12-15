#include "Sample.h"

bool Sample::AlphaBlendState()
{
    D3D11_BLEND_DESC bsd;
    ZeroMemory(&bsd, sizeof(bsd));
    //bsd.AlphaToCoverageEnable = TRUE;

    bsd.RenderTarget[0].BlendEnable = TRUE;

    // rgb
    // FINALCOLOR = DEST COLOR* (1-SRCALPHA) + SRC COLOR * SRC ALPAH
    bsd.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
    bsd.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
    bsd.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;

    // A
    bsd.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
    bsd.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
    bsd.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
    bsd.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;// 모든 구성요소에 데이터 저장(rgba)


    HRESULT hr = m_pd3dDevice->CreateBlendState(
        &bsd,
        &m_pAlphaBlendEnable);
    if (FAILED(hr))
    {
        return false;
    }

    bsd.RenderTarget[0].BlendEnable = FALSE;
    hr = m_pd3dDevice->CreateBlendState(
        &bsd,
        &m_pAlphaBlendDisable);
    if (FAILED(hr))
    {
        return false;
    }

    m_pd3dContext->OMSetBlendState(m_pAlphaBlendEnable, 0, -1);

    return true;
}

bool Sample::CreatePixelShader()
{
    D3D11_SAMPLER_DESC sd;
    ZeroMemory(&sd, sizeof(sd));
    sd.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
    sd.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
    sd.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
    sd.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
    
    HRESULT hr = m_pd3dDevice->CreateSamplerState(
        &sd,
        &m_pDefaultSS);
    if (FAILED(hr))
    {
        return false;
    }

    ZeroMemory(&sd, sizeof(sd));
    sd.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
    sd.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
    sd.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
    sd.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;

    hr = m_pd3dDevice->CreateSamplerState(
        &sd,
        &m_pDefaultSSPoint);
    if (FAILED(hr))
    {
        return false;
    }

    ID3DBlob* pBlobByteCode;
    ID3DBlob* ppErrorMsg;
    hr = D3DCompileFromFile(
        L"DefaultShaderVSPS.txt",
        nullptr,
        nullptr,
        "PS",
        "ps_5_0",
        0,
        0,
        &pBlobByteCode,
        &ppErrorMsg);

    if (FAILED(hr))
    {
        MessageBoxA(NULL, (char*)ppErrorMsg->GetBufferPointer(), "Error", MB_OK);
        if (ppErrorMsg)ppErrorMsg->Release();
        return false;
    }
    if (ppErrorMsg)ppErrorMsg->Release();

    hr = m_pd3dDevice->CreatePixelShader(
        pBlobByteCode->GetBufferPointer(),
        pBlobByteCode->GetBufferSize(),
        nullptr,
        &m_pPixelShaderAlphaTest);

    if (pBlobByteCode)pBlobByteCode->Release();

    if (FAILED(hr))
    {
        return false;
    }

    return true;
}

bool Sample::CreateSampleState()
{
    D3D11_SAMPLER_DESC sd;
    ZeroMemory(&sd, sizeof(sd));
    sd.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
    sd.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
    sd.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
    sd.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;

    HRESULT hr = m_pd3dDevice->CreateSamplerState(
        &sd,
        &m_pDefaultSS);
    if (FAILED(hr))
    {
        return false;
    }

    ZeroMemory(&sd, sizeof(sd));
    sd.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
    sd.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
    sd.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
    sd.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;

    hr = m_pd3dDevice->CreateSamplerState(
        &sd,
        &m_pDefaultSSPoint);
    if (FAILED(hr))
    {
        return false;
    }
    return true;
}

bool Sample::Init()
{
    AlphaBlendState();
    CreateSampleState();
    CreatePixelShader();

    // v0       v1
    //
    // v3       v2

    m_bk.m_pd3dDevice = m_pd3dDevice;
    m_bk.m_pd3dContext = m_pd3dContext;
    m_bk.m_rtClient = m_rtClient;

    m_bk.m_VertexList.emplace_back(TVector3(0.0f, 0.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 0.0f));      // 0
    m_bk.m_VertexList.emplace_back(TVector3(m_rtClient.right, 0.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 0.0f));    // 1
    m_bk.m_VertexList.emplace_back(TVector3(m_rtClient.right, m_rtClient.bottom, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 1.0f));  // 2
    m_bk.m_VertexList.emplace_back(TVector3(0.0f, m_rtClient.bottom, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 1.0f));    // 3
    
    m_bk.Init();
    m_bk.Load(L"../../data/default.png");
    //
    m_ui.m_pd3dDevice = m_pd3dDevice;
    m_ui.m_pd3dContext = m_pd3dContext;
    m_ui.m_rtClient = m_rtClient;
    
    m_ui.m_VertexList.emplace_back(TVector3(0.0f, 520.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 0.0f));      // 0
    m_ui.m_VertexList.emplace_back(TVector3(360.0f, 520.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 0.0f));    // 1
    m_ui.m_VertexList.emplace_back(TVector3(360.0f, 600.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 1.0f));  // 2
    m_ui.m_VertexList.emplace_back(TVector3(0.0f, 600.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 1.0f));    // 3
    
    m_ui.Init();
    m_ui.Load(L"../../data/layout.png");
    //
    m_ui_0.m_pd3dDevice = m_pd3dDevice;
    m_ui_0.m_pd3dContext = m_pd3dContext;
    m_ui_0.m_rtClient = m_rtClient;
    
    m_ui_0.m_VertexList.emplace_back(TVector3(10.0f, 530.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 0.0f));      // 0
    m_ui_0.m_VertexList.emplace_back(TVector3(70.0f, 530.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 0.0f));    // 1
    m_ui_0.m_VertexList.emplace_back(TVector3(70.0f, 590.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 1.0f));  // 2
    m_ui_0.m_VertexList.emplace_back(TVector3(10.0f, 590.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 1.0f));    // 3
    
    m_ui_0.Init();
    if (!m_ui_0.Load(L"../../data/inven.png"))
    {
        return false;
    }
    m_ui_0.LoadTextureChange(L"../../data/inven_2.png");
    //m_ui_0.Load(L"../../data/inven.png");
    //
    m_ui_1.m_pd3dDevice = m_pd3dDevice;
    m_ui_1.m_pd3dContext = m_pd3dContext;
    m_ui_1.m_rtClient = m_rtClient;

    m_ui_1.m_VertexList.emplace_back(TVector3(80.0f, 530.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 0.0f));      // 0
    m_ui_1.m_VertexList.emplace_back(TVector3(140.0f, 530.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 0.0f));    // 1
    m_ui_1.m_VertexList.emplace_back(TVector3(140.0f, 590.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 1.0f));  // 2
    m_ui_1.m_VertexList.emplace_back(TVector3(80.0f, 590.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 1.0f));    // 3

    m_ui_1.Init();
    m_ui_1.Load(L"../../data/upgrade.png");
    //
    m_number.m_pd3dDevice = m_pd3dDevice;
    m_number.m_pd3dContext = m_pd3dContext;
    m_number.m_rtClient = m_rtClient;
      
    m_number.m_VertexList.emplace_back(TVector3(0.0f, 0.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 0.0f));      // 0
    m_number.m_VertexList.emplace_back(TVector3(100.0f, 0.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 0.0f));    // 1
    m_number.m_VertexList.emplace_back(TVector3(100.0f, 100.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 1.0f));  // 2
    m_number.m_VertexList.emplace_back(TVector3(0.0f, 100.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 1.0f));    // 3
      
    m_number.Init();
    if (!m_number.Load(L"../../data/0.png"))
    {
        return false;
    }
    return true;
}

bool    Sample::Render()
{
    m_pd3dContext->PSSetSamplers(0, 1, &m_pDefaultSS);
    m_pd3dContext->OMSetBlendState(m_pAlphaBlendEnable, 0, -1);

    m_bk.Render();
    m_ui.Render();
    if (g_bChange)
        m_ui_0.Render();
    else
        m_ui_0.RenderChange();
    //m_ui_0.Render();
    m_ui_1.Render();

    
    m_pd3dContext->PSSetShaderResources(0, 1, &m_number.m_pTextureSRVArray[g_iChange]);
    UINT pStrides = sizeof(TVertex);
    UINT pOffsets = 0;
    m_pd3dContext->IASetVertexBuffers(
        0,
        1,
        &m_number.m_pVertexbuffer,
        &pStrides,
        &pOffsets);
    m_pd3dContext->DrawIndexed(m_number.m_IndexList.size(), 0, 0);

    return true;
}

bool    Sample::Release()
{
    if (m_pDefaultSS)m_pDefaultSS->Release();
    if (m_pDefaultSSPoint)m_pDefaultSSPoint->Release();
    if (m_pAlphaBlendEnable)m_pAlphaBlendEnable->Release();
    if (m_pAlphaBlendDisable)m_pAlphaBlendDisable->Release();
    if (m_pPixelShaderAlphaTest)m_pPixelShaderAlphaTest->Release();
    m_bk.Release();
    m_ui.Release();
    m_ui_0.Release();
    m_ui_1.Release();
    m_number.Release();
    return true;
}

//HINSTANCE : 운영체제가 관리하는 윈도우 프로세스ID
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    Sample win;
    win.SetWindow(hInstance, nCmdShow);
    win.Run();
    return 0;
}
