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
                    {380.0f, 100.0f },
                    {49.0f, 73.0f}};
    T_STR_VECTOR p_texArray = {
        L"../../data/서있기1.png",
        L"../../data/서있기2.png",
        L"../../data/점프1.png",
        L"../../data/점프2.png"
    };
    if (!m_Player->Create(p_info, p_texArray))
    {
        return false;
    }


    m_Goal = std::make_shared<Player>();
    m_Goal->m_pd3dDevice = m_pd3dDevice;
    m_Goal->m_pd3dContext = m_pd3dContext;
    m_Goal->m_rtClient = m_rtClient;
    TInitSet g_info = { L"Goal",
                    {1000.0f, 640.0f },
                    {244.0f, 73.0f} };
    if (!m_Goal->Create(g_info, L"../../data/goal.png"))
    {
        return false;
    }

    m_TimeBox = std::make_shared<Player>();
    m_TimeBox->m_pd3dDevice = m_pd3dDevice;
    m_TimeBox->m_pd3dContext = m_pd3dContext;
    m_TimeBox->m_rtClient = m_rtClient;
    TInitSet time_info = { L"TimeBox",
                    {543.0f, 0.0f },
                    {280.0f, 80.0f} };
    if (!m_TimeBox->Create(time_info, L"../../data/timebox.png"))
    {
        return false;
    }

    m_block1 = std::make_shared<Block>();
    m_block1->m_pd3dDevice = m_pd3dDevice;
    m_block1->m_pd3dContext = m_pd3dContext;
    m_block1->m_rtClient = m_rtClient;
    TInitSet b_info1 = { L"Block1",
                    {0.0f, 700.0f },
                    {1366.0f, 50.0f} };
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
                    {300.0f, 650.0f },
                    {200.0f, 50.0f} };
    if (!m_block2->Create(b_info2, L"../../data/block.png"))
    {
        return false;
    }
    m_BlockList.push_back(m_block2);

    m_trap1 = std::make_shared<Block>();
    m_trap1->m_pd3dDevice = m_pd3dDevice;
    m_trap1->m_pd3dContext = m_pd3dContext;
    m_trap1->m_rtClient = m_rtClient;
    TInitSet t_info1 = { L"Trap1",
                    {600.0f, 680.0f },
                    {20.0f, 20.0f} };
    if (!m_trap1->Create(t_info1, L"../../data/block.png"))
    {
        return false;
    }
    m_TrapList.push_back(m_trap1);


    return true;
}
bool    Sample::Frame()
{
    m_pBKSound->Frame();
    m_Player->Frame();
    
    int i = 0;
    int j = 0;
    int k = 0;

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
            if (m_BlockList[j]->m_vPos.x < m_Player->m_vPos.x + 34.0f &&//block left > player right
                m_BlockList[j]->m_vPos.x + m_BlockList[j]->m_InitSet.size.x > m_Player->m_vPos.x + 14.0f)
            {
                if (abs(m_BlockList[j]->m_vPos.y - m_Player->m_vPos.y - m_Player->m_InitSet.size.y) < 3.0f)//땅위에 있으면
                {
                    dropSpeed = 0.0f;
                    m_jump = true;
                    break;
                }
            }
            j++;
        }     
    }


    for (auto data : m_TrapList)
    {
        if (m_TrapList[i]->m_vPos.x < m_Player->m_vPos.x + 34.0f &&//block left < player right
            m_TrapList[i]->m_vPos.x + m_TrapList[i]->m_InitSet.size.x * 0.5 > m_Player->m_vPos.x + 14.0f)
        {
            if (m_TrapList[i]->m_vPos.y < m_Player->m_vPos.y + m_Player->m_InitSet.size.y &&
                m_TrapList[i]->m_vPos.y + m_TrapList[i]->m_InitSet.size.y > m_Player->m_vPos.y)
            {
                m_Player->m_vPos.x = m_Player->m_vPos.x + g_fSecPerFrame * (-6000.0f);
                dropSpeed = -10000.0f;
                break;
            }
        }
        if (m_TrapList[i]->m_vPos.x + m_TrapList[i]->m_InitSet.size.x * 0.5 < m_Player->m_vPos.x + 34.0f &&//block left < player right
            m_TrapList[i]->m_vPos.x + m_TrapList[i]->m_InitSet.size.x > m_Player->m_vPos.x + 14.0f)
        {
            if (m_TrapList[i]->m_vPos.y < m_Player->m_vPos.y + m_Player->m_InitSet.size.y &&
                m_TrapList[i]->m_vPos.y + m_TrapList[i]->m_InitSet.size.y > m_Player->m_vPos.y)
            {
                m_Player->m_vPos.x = m_Player->m_vPos.x + g_fSecPerFrame * 6000.0f;
                dropSpeed = -10000.0f;
                break;
            }
        }
        i++;
    }

    if (m_Goal->m_vPos.x + 19.0f < m_Player->m_vPos.x + 34.0f &&//block left > player right
        m_Goal->m_vPos.x + m_Goal->m_InitSet.size.x - 40.0f > m_Player->m_vPos.x + 14.0f)
    {
        if (m_Goal->m_vPos.y < m_Player->m_vPos.y + m_Player->m_InitSet.size.y &&
            m_Goal->m_vPos.y + m_Goal->m_InitSet.size.y > m_Player->m_vPos.y)
        {
            std::wstring Cleartext = L"클리어!!\n경과시간: ";
            if (int(g_fTimer) / 60 > 0)
            {
                Cleartext += std::to_wstring(int(g_fTimer) / 60);
                Cleartext += L" 분 ";
            }
            Cleartext += std::to_wstring(int(g_fTimer) % 60);
            Cleartext += L" 초";
            LPCWSTR cleartext = Cleartext.c_str();
            MessageBox(g_hWnd, cleartext, L" ", MB_OK);
        }
    }
    j++;

    m_Player->m_vPos.y = m_Player->m_vPos.y + g_fSecPerFrame * dropSpeed;
    
    if (m_jump==false) {
        if (rightleft == 0) {
            g_uiState = 2;
        }
        else {
            g_uiState = 3;
        }
    }
    else
    {
        if (rightleft == 0) {
            g_uiState = 0;
        }
        else {
            g_uiState = 1;
        }
    }

    if (m_Player->m_pTexArray.size() > 0)
    {
        m_Player->m_ptTex = m_Player->m_pTexArray[g_uiState];
    }


    return true;
}
bool    Sample::Render()
{
    

    m_block1->Render();
    m_block2->Render();

    m_trap1->Render();

    m_Goal->Render();
    m_Player->Render();

    m_TimeBox->Render();
    m_Write.DrawTime(553, 10, m_GameTimer.m_outmsg);
    return true;
}
bool    Sample::Release()
{
    if (m_pBKSound)m_pBKSound->Release();
    if (m_Player)m_Player->Release();
    if (m_TimeBox)m_TimeBox->Release();

    if (m_Goal)m_Goal->Release();

    if (m_block1)m_block1->Release();
    if (m_block2)m_block1->Release();

    if (m_trap1)m_trap1->Release();

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
