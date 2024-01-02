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
    if (!m_Player->Create(p_info, L"../../data/서있기2.png"))
    {
        return false;
    }

    m_block1 = std::make_shared<Block>();
    m_block1->m_pd3dDevice = m_pd3dDevice;
    m_block1->m_pd3dContext = m_pd3dContext;
    m_block1->m_rtClient = m_rtClient;
    TInitSet b_info1 = { L"Block1",
                    {0.0f, 700.0f },
                    {1366.0f, 68.0f} };
    if (!m_block1->Create(b_info1, L"../../data/block.png"))
    {
        return false;
    }
    m_BlockList.push_back(m_block1);

    m_block2 = std::make_shared<Block>();
    m_block2->m_pd3dDevice = m_pd3dDevice;
    m_block2->m_pd3dContext = m_pd3dContext;
    m_block2->m_rtClient = m_rtClient;
    TInitSet b_info2 = { L"Block2",
                    {300.0f, 600.0f },
                    {200.0f, 68.0f} };
    if (!m_block2->Create(b_info2, L"../../data/block.png"))
    {
        return false;
    }
    m_BlockList.push_back(m_block2);


    return true;
}
bool    Sample::Frame()
{
    m_pBKSound->Frame();
    m_Player->Frame();
    
    int i = 0;
    float dropSpeed = 0.0f;
    float gravity = 300.0f;

    if (m_jump && Input::Get().m_dwKeyState[VK_SPACE] == KEY_PUSH)
    {
        dropSpeed = -10000.0f;
        m_jump = false;
    }
    else
    {
        dropSpeed += gravity;
    }

    if (dropSpeed >= 0.0f)
    {
        
        for (auto data : m_BlockList)
        {
            if (m_BlockList[i]->m_vPos.x > m_Player->m_vPos.x + m_Player->m_InitSet.size.x &&//block left > player right
                m_BlockList[i]->m_vPos.x + m_BlockList[i]->m_InitSet.size.x < m_Player->m_vPos.x)
            {
                i++;
                continue;
            }
            if (m_BlockList[i]->m_vPos.y < m_Player->m_vPos.y + m_Player->m_InitSet.size.y)//block top < player bottom
            {
                i++;
                continue;
            }
            if (m_BlockList[i]->m_vPos.y < m_Player->m_vPos.y + m_Player->m_InitSet.size.y)
            {
                float gap = m_BlockList[i]->m_vPos.y - m_Player->m_vPos.y - m_Player->m_InitSet.size.y;
                dropSpeed = gap;
            }
            if (abs(m_BlockList[i]->m_vPos.y - m_Player->m_vPos.y - m_Player->m_InitSet.size.y) < 3.0f)//땅위에 있으면
            {
                dropSpeed = 0.0f;
                m_jump = true;
                break;
            }
            i++;
        }
        
    }

    m_Player->m_vPos.y = m_Player->m_vPos.y + g_fSecPerFrame * dropSpeed;
    return true;
}
bool    Sample::Render()
{
    m_Player->Render();
    m_block1->Render();
    m_block2->Render();
    return true;
}
bool    Sample::Release()
{
    if (m_pBKSound)m_pBKSound->Release();
    if (m_Player)m_Player->Release();
    if (m_block1)m_block1->Release();
    if (m_block2)m_block1->Release();

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
