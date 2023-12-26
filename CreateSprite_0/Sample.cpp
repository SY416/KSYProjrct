#include "Sample.h"
#include "CTextureMgr.h"


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

bool Sample::Init()
{
    CreatePixelShader();

    // v0       v1
    //
    // v3       v2

    m_bk = std::make_shared<CUIObj>();
        m_bk->m_VertexList.emplace_back(TVector3(0.0f, 0.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 0.0f));      // 0
        m_bk->m_VertexList.emplace_back(TVector3(m_rtClient.right, 0.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 0.0f));    // 1
        m_bk->m_VertexList.emplace_back(TVector3(m_rtClient.right, m_rtClient.bottom, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 1.0f));  // 2
        m_bk->m_VertexList.emplace_back(TVector3(0.0f, m_rtClient.bottom, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 1.0f));    // 3
        m_bk->Create(L"BackGround", L"../../data/default.png");
    m_uiList.push_back(m_bk);

    //

    m_ui = std::make_shared<CUIObj>();
        m_ui->m_VertexList.emplace_back(TVector3(0.0f, 520.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 0.0f));      // 0
        m_ui->m_VertexList.emplace_back(TVector3(360.0f, 520.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 0.0f));    // 1
        m_ui->m_VertexList.emplace_back(TVector3(360.0f, 600.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 1.0f));  // 2
        m_ui->m_VertexList.emplace_back(TVector3(0.0f, 600.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 1.0f));    // 3
        m_ui->Create(L"Layout", L"../../data/layout.png");
    m_uiList.push_back(m_ui);
    //
   
    m_ui_0 = std::make_shared<CUIObj>();
        m_ui_0->m_VertexList.emplace_back(TVector3(10.0f, 530.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 0.0f));      // 0
        m_ui_0->m_VertexList.emplace_back(TVector3(70.0f, 530.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 0.0f));    // 1
        m_ui_0->m_VertexList.emplace_back(TVector3(70.0f, 590.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 1.0f));  // 2
        m_ui_0->m_VertexList.emplace_back(TVector3(10.0f, 590.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 1.0f));    // 3
        T_STR_VECTOR texArrayInven = {
            L"../../data/inven_nor.png"
            L"../../data/inven_pus.png"
            L"../../data/inven_sel.png"
            L"../../data/inven_dis.png"
        };
        if (!m_ui_0->Create(L"Inventory", texArrayInven))
        {
            return false;
        }
    m_uiList.push_back(m_ui_0);
   
    
    m_ui_1 = std::make_shared<CUIObj>();
        m_ui_1->m_VertexList.emplace_back(TVector3(80.0f, 530.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 0.0f));      // 0
        m_ui_1->m_VertexList.emplace_back(TVector3(140.0f, 530.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 0.0f));    // 1
        m_ui_1->m_VertexList.emplace_back(TVector3(140.0f, 590.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 1.0f));  // 2
        m_ui_1->m_VertexList.emplace_back(TVector3(80.0f, 590.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 1.0f));    // 3
        m_ui_1->Create(L"UpGrade", L"../../data/upgrade.png");
    m_uiList.push_back(m_ui_1);
    //
    m_number = std::make_shared<CUIObj>();
        m_number->m_VertexList.emplace_back(TVector3(0.0f, 0.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 0.0f));      // 0
        m_number->m_VertexList.emplace_back(TVector3(100.0f, 0.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 0.0f));    // 1
        m_number->m_VertexList.emplace_back(TVector3(100.0f, 100.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 1.0f));  // 2
        m_number->m_VertexList.emplace_back(TVector3(0.0f, 100.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 1.0f));    // 3
        if (!m_number->Create(L"Number", L"../../data/0.png"))
        {
            return false;
        }
    m_uiList.push_back(m_number);

    m_EffectA = std::make_shared<CEffect>();
    m_EffectA->m_VertexList.emplace_back(TVector3(200, 100.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 0.0f));      // 0
    m_EffectA->m_VertexList.emplace_back(TVector3(300.0f, 100.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 0.0f));    // 1
    m_EffectA->m_VertexList.emplace_back(TVector3(300.0f, 200, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 1.0f));  // 2
    m_EffectA->m_VertexList.emplace_back(TVector3(200.0f, 200, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 1.0f));    // 3
    if (!m_EffectA->Create(L"EffectA", L"../../data/effect.png", 4, 4, 1.0f))
    {
        return false;
    }
    return true;
}

bool    Sample::Frame()
{
    m_GameTime.Frame();
    CInput::Get().Frame();
   
    if (CInput::Get().m_dwKeyState['W'] == KEY_PUSH)
    {
        ::OutputDebugString(L"W[PUSH].\n");
    }
    if (CInput::Get().m_dwKeyState['W'] == KEY_HOLD)
    {
        ::OutputDebugString(L"W[HOLD].\n");
    }
    if (CInput::Get().m_dwKeyState['W'] == KEY_UP)
    {
        ::OutputDebugString(L"W[UP].\n");
    }
    if (CInput::Get().m_dwKeyState['A'] == KEY_PUSH)
    {
        ::OutputDebugString(L"A[PUSH].\n");
    }
    if (CInput::Get().m_dwKeyState['S'] == KEY_PUSH)
    {
        ::OutputDebugString(L"S[PUSH].\n");
    }
    if (CInput::Get().m_dwKeyState['D'] == KEY_PUSH)
    {
        ::OutputDebugString(L"D[PUSH].\n");
    }
    if (CInput::Get().m_dwKeyState[VK_LBUTTON] == KEY_UP)
    {
        g_bChange = !g_bChange;
    }
    if (CInput::Get().m_dwKeyState[VK_RBUTTON] == KEY_UP)
    {
        g_iChange++;
        if (g_iChange >= 10) g_iChange = 0;
    }

    for (auto data : m_uiList)
    {
        data->Frame(m_GameTime.m_fSecondPerFrame);
    }
    m_EffectA->Frame(m_GameTime.m_fSecondPerFrame);

    return true;
}

bool    Sample::Render()
{
    m_pd3dContext->PSSetSamplers(0, 1, &m_pDefaultSS);
    m_pd3dContext->OMSetBlendState(m_pAlphaBlendEnable, 0, -1);

#pragma region BK
    m_pd3dContext->UpdateSubresource(m_DefaultPlane.m_pVertexbuffer,
        0,
        nullptr,
        &m_bk->m_VertexList.at(0),
        0,
        0);
    m_DefaultPlane.PreRender();
    m_bk->Render(m_pd3dContext);
    m_DefaultPlane.PostRender();
#pragma endregion BK

    m_pd3dContext->OMSetBlendState(m_pAlphaBlendEnable, 0, -1);
    for (auto data : m_uiList)
    {
        m_pd3dContext->UpdateSubresource(m_DefaultPlane.m_pVertexbuffer,
            0,
            nullptr,
            &data->m_VertexList.at(0),
            0,
            0);
        m_DefaultPlane.PreRender();
            data->Render(m_pd3dContext);
        m_DefaultPlane.PostRender();
    }

#pragma region EFFECT

    m_pd3dContext->UpdateSubresource(m_DefaultPlane.m_pVertexbuffer,
        0,
        nullptr,
        &m_EffectA->m_VertexList.at(0),
        0,
        0);
    m_DefaultPlane.PreRender();
    m_pd3dContext->PSSetShader(m_pPixelShaderAlphaTest, NULL, 0);
    m_EffectA->Render(m_pd3dContext);
    m_DefaultPlane.PostRender();

#pragma endregion EFFECT

    m_dxWrite.Draw20(0, 30, m_GameTime.m_outmsg);

    return true;
}

bool    Sample::Release()
{
    if (m_pPixelShaderAlphaTest)m_pPixelShaderAlphaTest->Release();
    for (auto data : m_uiList)
    {
        data->Release();
    }

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
