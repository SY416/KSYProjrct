#include "Sample.h"
#include <thread>

bool    Sample::Init()
{
    m_pBKSound = SoundMgr::Get().Load(L"../../data/BKSound.mp3");
    m_jumpSound = SoundMgr::Get().Load(L"../../data/jumpSound.ogg");
    m_pBKSound->Play();

    m_Player = std::make_shared<Player>();
    m_Player->m_pd3dDevice = m_pd3dDevice;
    m_Player->m_pd3dContext = m_pd3dContext;
    m_Player->m_rtClient = m_rtClient;

    TInitSet p_info = { L"Player",
                    {100.0f, 400.0f },
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

    m_NPC = std::make_shared<Block>();
    m_NPC->m_pd3dDevice = m_pd3dDevice;
    m_NPC->m_pd3dContext = m_pd3dContext;
    m_NPC->m_rtClient = m_rtClient;
    TInitSet NPC_info = { L"헤르샤",
                    {10.0f, 625.0f },
                    {98.0f, 80.0f} };
    if (!m_NPC->Create(NPC_info, L"../../data/헤르샤.png"))
    {
        return false;
    }
    m_PE = std::make_shared<Block>();
    m_PE->m_pd3dDevice = m_pd3dDevice;
    m_PE->m_pd3dContext = m_pd3dContext;
    m_PE->m_rtClient = m_rtClient;
    TInitSet PE_info = { L"말풍선",
                    {30.0f, 570.0f },
                    {52.0f, 51.0f} };
    if (!m_PE->Create(PE_info, L"../../data/말풍선52x51.png"))
    {
        return false;
    }

    m_TimeBox = std::make_shared<Block>();
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
    TInitSet b_info1 = { L"Ground",
                    {0.0f, 700.0f },
                    {1366.0f, 50.0f} };
    if (!m_block1->Create(b_info1, L"../../data/ground.png"))
    {
        return false;
    }
    m_BlockList.push_back(m_block1);

    m_block2 = std::make_shared<Block>();
    m_block2->m_pd3dDevice = m_pd3dDevice;
    m_block2->m_pd3dContext = m_pd3dContext;
    m_block2->m_rtClient = m_rtClient;
    TInitSet b_info2 = { L"Block2",
                    {150.0f, 640.0f },
                    {38.0f, 42.0f} };
    if (!m_block2->Create(b_info2, L"../../data/38x42.png"))
    {
        return false;
    }
    m_BlockList.push_back(m_block2);

    m_block4 = std::make_shared<Block>();
    m_block4->m_pd3dDevice = m_pd3dDevice;
    m_block4->m_pd3dContext = m_pd3dContext;
    m_block4->m_rtClient = m_rtClient;
    TInitSet b_info4 = { L"Block4",
                    {240.0f, 580.0f },
                    {38.0f, 42.0f} };
    if (!m_block4->Create(b_info4, L"../../data/38x42.png"))
    {
        return false;
    }
    m_BlockList.push_back(m_block4);

    m_block3 = std::make_shared<Block>();
    m_block3->m_pd3dDevice = m_pd3dDevice;
    m_block3->m_pd3dContext = m_pd3dContext;
    m_block3->m_rtClient = m_rtClient;
    TInitSet b_info3 = { L"Block3",//네키 올라가있는 블럭
                    {510.0f, 460.0f },
                    {128.0f, 43.0f} };
    if (!m_block3->Create(b_info3, L"../../data/128x43.png"))
    {
        return false;
    }
    m_BlockList.push_back(m_block3);

    m_monster1 = std::make_shared<Monster>();
    m_monster1->m_pd3dDevice = m_pd3dDevice;
    m_monster1->m_pd3dContext = m_pd3dContext;
    m_monster1->m_rtClient = m_rtClient;
    TInitSet m_info2 = { L"Monster",
                    {570.0f, 432.0f },
                    {28.0f, 28.0f} };
    T_STR_VECTOR mon_texArray = {
        L"../../data/네키1.png",
        L"../../data/네키2.png",
    };
    if (!m_monster1->Create(m_info2, mon_texArray))
    {
        return false;
    }

    m_block5 = std::make_shared<Block>();
    m_block5->m_pd3dDevice = m_pd3dDevice;
    m_block5->m_pd3dContext = m_pd3dContext;
    m_block5->m_rtClient = m_rtClient;
    TInitSet b_info5 = { L"Block5",///가시블럭
                    {330.0f, 520.0f },
                    {128.0f, 43.0f} };
    if (!m_block5->Create(b_info5, L"../../data/128x43.png"))
    {
        return false;
    }
    m_BlockList.push_back(m_block5);

    m_trap1 = std::make_shared<Block>();
    m_trap1->m_pd3dDevice = m_pd3dDevice;
    m_trap1->m_pd3dContext = m_pd3dContext;
    m_trap1->m_rtClient = m_rtClient;
    TInitSet t_info1 = { L"Trap1",
                    {400.0f, 500.0f },
                    {15.0f, 24.0f} };
    if (!m_trap1->Create(t_info1, L"../../data/가시.png"))
    {
        return false;
    }
    m_TrapList.push_back(m_trap1);

    
    m_block6 = std::make_shared<Block>();
    m_block6->m_pd3dDevice = m_pd3dDevice;
    m_block6->m_pd3dContext = m_pd3dContext;
    m_block6->m_rtClient = m_rtClient;
    TInitSet b_info6 = { L"Block6",
                    {690.0f, 400.0f },
                    {128.0f, 43.0f} };
    if (!m_block6->Create(b_info6, L"../../data/128x43.png"))
    {
        return false;
    }
    m_BlockList.push_back(m_block6);

    m_block7 = std::make_shared<Block>();
    m_block7->m_pd3dDevice = m_pd3dDevice;
    m_block7->m_pd3dContext = m_pd3dContext;
    m_block7->m_rtClient = m_rtClient;
    TInitSet b_info7 = { L"Block7",
                    {870.0f, 340.0f },
                    {128.0f, 43.0f} };
    if (!m_block7->Create(b_info7, L"../../data/128x43.png"))
    {
        return false;
    }
    m_BlockList.push_back(m_block7);

    m_block8 = std::make_shared<Block>();
    m_block8->m_pd3dDevice = m_pd3dDevice;
    m_block8->m_pd3dContext = m_pd3dContext;
    m_block8->m_rtClient = m_rtClient;
    TInitSet b_info8 = { L"Block8",
                    {1050.0f, 280.0f },
                    {128.0f, 43.0f} };
    if (!m_block8->Create(b_info8, L"../../data/128x43.png"))
    {
        return false;
    }
    m_BlockList.push_back(m_block8);

    m_block9 = std::make_shared<Block>();
    m_block9->m_pd3dDevice = m_pd3dDevice;
    m_block9->m_pd3dContext = m_pd3dContext;
    m_block9->m_rtClient = m_rtClient;
    TInitSet b_info9 = { L"Block9",
                    {0.0, 280.0f },
                    {128.0f, 43.0f} };
    if (!m_block9->Create(b_info9, L"../../data/128x43.png"))
    {
        return false;
    }
    m_BlockList.push_back(m_block9);

    m_Goal = std::make_shared<Block>();
    m_Goal->m_pd3dDevice = m_pd3dDevice;
    m_Goal->m_pd3dContext = m_pd3dContext;
    m_Goal->m_rtClient = m_rtClient;
    TInitSet g_info = { L"Goal",
                    {10.0f, 250.0f },
                    {122.0f, 36.0f} };
    if (!m_Goal->Create(g_info, L"../../data/goal.png"))
    {
        return false;
    }

    m_MB = std::make_shared<MovingBlock>();
    m_MB->m_pd3dDevice = m_pd3dDevice;
    m_MB->m_pd3dContext = m_pd3dContext;
    m_MB->m_rtClient = m_rtClient;
    TInitSet mb_info = { L"MovingBlock",
                    {100.0f, 280.0f },
                    {128.0f, 43.0f} };
    if (!m_MB->Create(mb_info, L"../../data/128x43.png"))
    {
        return false;
    }
    //m_BlockList.push_back(m_MB);

    /*m_message = std::make_shared<Message>();
    m_message->m_pd3dDevice = m_pd3dDevice;
    m_message->m_pd3dContext = m_pd3dContext;
    m_message->m_rtClient = m_rtClient;
    MInitSet m_info = { L"message",
    };
    if (!m_message->Create(m_info, L"../../data/메세지박스.png"))
    {
        return false;
    }*/
    

    return true;
}

bool	Sample::ThreadNPC()
{
    /*if (m_NPC->m_vPos.x - 20.0f < m_Player->m_vPos.x + m_Player->m_InitSet.size.x &&
        m_NPC->m_vPos.x + m_NPC->m_InitSet.size.x + 20.0f > m_Player->m_vPos.x)
    {
        if (m_NPC->m_vPos.y - 20.0f < m_Player->m_vPos.y + m_Player->m_InitSet.size.y &&
            m_NPC->m_vPos.y + m_NPC->m_InitSet.size.y + 20.0f > m_Player->m_vPos.y)
        {
            if (Input::Get().m_dwKeyState['E'] == KEY_PUSH)
            {
                MessageBox(g_hWnd, L"저기 꼭대기에 덤불에서 약초 좀 캐다 줘!", L"헤르샤", MB_OK);
            }
        }
    }*/
    return true;
}

bool    Sample::Frame()
{
    m_pBKSound->Frame();
    m_Player->Frame();
    m_monster1->Frame();
    m_MB->Frame();
    
    //std::thread t1(ThreadNPC);

    //t1.join();

    if (m_NPC->m_vPos.x - 20.0f < m_Player->m_vPos.x + m_Player->m_InitSet.size.x &&
        m_NPC->m_vPos.x + m_NPC->m_InitSet.size.x + 20.0f > m_Player->m_vPos.x)
    {
        if (m_NPC->m_vPos.y - 20.0f < m_Player->m_vPos.y + m_Player->m_InitSet.size.y &&
            m_NPC->m_vPos.y + m_NPC->m_InitSet.size.y + 20.0f > m_Player->m_vPos.y)
        {
            if (Input::Get().m_dwKeyState['E'] == KEY_PUSH)
            {
                
                MessageBox(g_hWnd, L"저기 꼭대기에 덤불에서 약초 좀 캐다 줘!\n좌우 방향키로 이동, \n스페이스바로 점프 할 수 있어", L"헤르샤", MB_OK);
            }
        }
    }

    int i = 0;
    int j = 0;
    int k = 0;

    float dropSpeed = 0.0f;
    
    //g_fSecPerFrame;
    /*if (m_jump && Input::Get().m_dwKeyState[VK_SPACE] == KEY_PUSH)
    {
        dropSpeed = -10000.0f;
        m_jump = false;
    }
    else
    {
        dropSpeed = 300.0f;
    }*/

    if (m_jump && Input::Get().m_dwKeyState[VK_SPACE] == KEY_PUSH)
    {
        m_jumptime = g_fTimer + 0.3;
        m_jumpSound->PlayEffect();
        m_jump = false;
    }
    if (g_fTimer < m_jumptime)
    {
        dropSpeed = -250.0f;
    }
    else
    {
        dropSpeed = 300.0f;
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

    if (dropSpeed >= 0.0f)
    {
        
            if (m_MB->m_vPos.x < m_Player->m_vPos.x + 34.0f &&//block left > player right
                m_MB->m_vPos.x + m_MB->m_InitSet.size.x > m_Player->m_vPos.x + 14.0f)
            {
                if (abs(m_MB->m_vPos.y - m_Player->m_vPos.y - m_Player->m_InitSet.size.y) < 3.0f)//땅위에 있으면
                {
                    dropSpeed = 0.0f;
                    m_jump = true;
                }
            }
            j++;
        
    }


    for (auto data : m_TrapList)
    {
        if (m_TrapList[i]->m_vPos.x < m_Player->m_vPos.x + 34.0f &&//block left < player right
            m_TrapList[i]->m_vPos.x + m_TrapList[i]->m_InitSet.size.x * 0.5 > m_Player->m_vPos.x + 14.0f)
        {
            if (m_TrapList[i]->m_vPos.y < m_Player->m_vPos.y + m_Player->m_InitSet.size.y &&
                m_TrapList[i]->m_vPos.y + m_TrapList[i]->m_InitSet.size.y > m_Player->m_vPos.y)
            {
                m_Player->m_vPos.x = m_Player->m_vPos.x + g_fSecPerFrame * (-10000.0f);
                dropSpeed = -5000.0f;
                break;
            }
        }
        if (m_TrapList[i]->m_vPos.x + m_TrapList[i]->m_InitSet.size.x * 0.5 < m_Player->m_vPos.x + 34.0f &&//block left < player right
            m_TrapList[i]->m_vPos.x + m_TrapList[i]->m_InitSet.size.x > m_Player->m_vPos.x + 14.0f)
        {
            if (m_TrapList[i]->m_vPos.y < m_Player->m_vPos.y + m_Player->m_InitSet.size.y &&
                m_TrapList[i]->m_vPos.y + m_TrapList[i]->m_InitSet.size.y > m_Player->m_vPos.y)
            {
                m_Player->m_vPos.x = m_Player->m_vPos.x + g_fSecPerFrame * 10000.0f;
                dropSpeed = -5000.0f;
                break;
            }
        }
        i++;
    }

    if (m_monster1->m_vPos.x < m_Player->m_vPos.x + 34.0f &&//block left < player right
        m_monster1->m_vPos.x + m_monster1->m_InitSet.size.x * 0.5 > m_Player->m_vPos.x + 14.0f)
    {
        if (m_monster1->m_vPos.y < m_Player->m_vPos.y + m_Player->m_InitSet.size.y &&
            m_monster1->m_vPos.y + m_monster1->m_InitSet.size.y > m_Player->m_vPos.y)
        {
            m_Player->m_vPos.x = m_Player->m_vPos.x + g_fSecPerFrame * (-10000.0f);
            dropSpeed = -5000.0f;
        }
    }
    if (m_monster1->m_vPos.x + m_monster1->m_InitSet.size.x * 0.5 < m_Player->m_vPos.x + 34.0f &&//block left < player right
        m_monster1->m_vPos.x + m_monster1->m_InitSet.size.x > m_Player->m_vPos.x + 14.0f)
    {
        if (m_monster1->m_vPos.y < m_Player->m_vPos.y + m_Player->m_InitSet.size.y &&
            m_monster1->m_vPos.y + m_monster1->m_InitSet.size.y > m_Player->m_vPos.y)
        {
            m_Player->m_vPos.x = m_Player->m_vPos.x + g_fSecPerFrame * 10000.0f;
            dropSpeed = -5000.0f;
        }
    }

    if (m_Goal->m_vPos.x + 19.0f < m_Player->m_vPos.x + 34.0f &&//block left > player right
        m_Goal->m_vPos.x + m_Goal->m_InitSet.size.x - 40.0f > m_Player->m_vPos.x + 14.0f)
    {
        if (m_Goal->m_vPos.y < m_Player->m_vPos.y + m_Player->m_InitSet.size.y &&
            m_Goal->m_vPos.y + m_Goal->m_InitSet.size.y > m_Player->m_vPos.y)
        {
            std::wstring Cleartext = L"굿!\n";
            if (int(g_fTimer) / 60 > 0)
            {
                Cleartext += std::to_wstring(int(g_fTimer) / 60);
                Cleartext += L" 분 ";
            }
            Cleartext += std::to_wstring(int(g_fTimer) % 60);
            Cleartext += L" 초 걸렸어\n재도전 할래?";
            LPCWSTR cleartext = Cleartext.c_str();
            if (MessageBox(g_hWnd, cleartext, L"헤르샤", MB_YESNO) == IDYES)
            {
                g_fTimer = 0;
                m_jumptime = 0;
                m_Player->m_vPos.x = 100;
                m_Player->m_vPos.y = 100;
            }
            else
            {
                exit(0);
            }
            
        }
    }
    
    

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

    if (m_monster1->rl == 0) {
        g_uiState = 0;
    }
    else {
        g_uiState = 1;
    }

    if (m_monster1->m_pTexArray.size() > 0)
    {
        m_monster1->m_ptTex = m_monster1->m_pTexArray[g_uiState];
    }


    return true;
}
bool    Sample::Render()
{
    

    m_block1->Render();
    m_block2->Render();
    m_block3->Render();
    m_block4->Render();
    m_block5->Render();
    m_block6->Render();
    m_block7->Render();
    m_block8->Render();
    m_block9->Render();


    m_trap1->Render();
    m_monster1->Render();
    m_MB->Render();

    m_NPC->Render();
    m_PE->Render();
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
    if (m_NPC)m_NPC->Release();
    if (m_PE)m_PE->Release();

    if (m_block1)m_block1->Release();
    if (m_block2)m_block1->Release();
    if (m_block3)m_block3->Release();
    if (m_block4)m_block4->Release();
    if (m_block5)m_block5->Release();
    if (m_block6)m_block6->Release();
    if (m_block7)m_block7->Release();
    if (m_block8)m_block8->Release();
    if (m_block9)m_block9->Release();

    if (m_trap1)m_trap1->Release();
    if (m_monster1)m_monster1->Release();
    if (m_MB)m_MB->Release();

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
