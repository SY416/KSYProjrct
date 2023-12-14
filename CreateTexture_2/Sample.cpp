#include "Sample.h"

bool Sample::Init()
{
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
    m_bk.Load(L"../../data/bk.png");
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

    return true;
}

bool    Sample::Render()
{
    m_bk.Render();
    m_ui.Render();
    if (g_bChange)
        m_ui_0.Render();
    else
        m_ui_0.RenderChange();
    //m_ui_0.Render();
    m_ui_1.Render();

    return true;
}

bool    Sample::Release()
{
    m_bk.Release();
    m_ui.Release();
    m_ui_0.Release();
    m_ui_1.Release();
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
