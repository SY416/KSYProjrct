#include "Sample.h"

bool	   Sample::Init()
{

    m_bk = std::make_shared<UIobj>();
    m_bk->m_VertexList.emplace_back(TVector3(0.0f, 0.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 0.0f));      // 0
    m_bk->m_VertexList.emplace_back(TVector3(m_rtClient.right, 0.0f, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 0.0f));    // 1
    m_bk->m_VertexList.emplace_back(TVector3(m_rtClient.right, m_rtClient.bottom, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 1.0f));  // 2
    m_bk->m_VertexList.emplace_back(TVector3(0.0f, m_rtClient.bottom, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 1.0f));    // 3
    m_bk->Create(L"BackGround", L"../../data/default.png");
    m_uiList.push_back(m_bk);

    return true;
}

bool	   Sample::Render()
{
    return true;
}

bool	   Sample::Release()
{
    for (auto data : m_uiList)
    {
        data->Release();
    }
    return true;
}

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
