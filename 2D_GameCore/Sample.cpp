#include "Sample.h"

bool    Sample::Init()
{
    m_pBKSound = SoundMgr::Get().Load(L"../../data/BKSound.mp3");
    m_pBKSound->Play();

    m_Player = std::make_shared<Player>();

    m_Player->m_pd3dDevice = m_pd3dDevice;
    m_Player->m_pd3dContext = m_pd3dContext;
    m_Player->m_rtClient = m_rtClient;

    TInitSet p_info = { L"Player",
                    {380.0f, 300.0f },
                    {49.0f, 73.0f}};
    if (!m_Player->Create(p_info, L"../../data/¼­ÀÖ±â2.png"))
    {
        return false;
    }
    return true;
}
bool    Sample::Frame()
{
    m_pBKSound->Frame();
    m_Player->Frame();
    return true;
}
bool    Sample::Render()
{
    m_Player->Render();
    return true;
}
bool    Sample::Release()
{
    if (m_pBKSound)m_pBKSound->Release();
    if (m_Player)m_Player->Release();
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
