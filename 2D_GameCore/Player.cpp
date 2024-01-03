#include "Player.h"
#include "Input.h"

int rightleft=0;

bool    Player::Create(TInitSet info, T_STR_VECTOR texFileName)
{
    m_InitSet = info;
    m_csName = info.name;
    m_vPos = info.p;
    PlaneShape::Create(m_csName, texFileName);
    return true;
}
bool Player::CreateVertexBuffer()
{
    SetVB(m_InitSet.p, m_InitSet.size);
    PlaneShape::CreateVertexBuffer();
    return true;
}
bool   Player::SetVB(TVector2 p,
    TVector2 size)
{
    m_VertexList.clear();

    m_VertexList.emplace_back(TVector3(p.x, p.y, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 0.0f));      // 0
    m_VertexList.emplace_back(TVector3(p.x + size.x, p.y, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 0.0f));    // 1
    m_VertexList.emplace_back(TVector3(p.x + size.x, p.y + size.y, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 1.0f));  // 2
    m_VertexList.emplace_back(TVector3(p.x, p.y + size.y, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 1.0f));    // 3

    return true;
}

void   Player::SetPosion(TVector2 p)
{
    m_VertexList[0].pos = TVector3(p.x, p.y, 0.5f);
    m_VertexList[1].pos = TVector3(p.x + m_InitSet.size.x, p.y, 0.5f);
    m_VertexList[2].pos = TVector3(p.x + m_InitSet.size.x, p.y + m_InitSet.size.y, 0.5f);
    m_VertexList[3].pos = TVector3(p.x, p.y + m_InitSet.size.y, 0.5f);
    m_pd3dContext->UpdateSubresource(m_pVertexBuffer,
        0,
        nullptr,
        &m_VertexList.at(0),
        0,
        0);
}


void   Player::SetPosion(float x, float y)
{

}
bool Player::Frame()
{
    //  위치 = 현 위치 + 이동방향 * 시간의 동기화( 1초당 최대 거리 이동)
    //  g_fSecPerFrame * m_fSpeed;
    //  1프레임  -> 1초 * 300     -> 300
    //  10프레임 -> 0.1초 * 300   -> 300
    //  100프레임 -> 0.01초 *300  -> 300
    if (Input::Get().m_dwKeyState[VK_LEFT] == KEY_HOLD && m_vPos.x > 0)
    {
        m_vPos.x = m_vPos.x - g_fSecPerFrame * 300;
        rightleft = 1;
    }
    if (Input::Get().m_dwKeyState[VK_RIGHT] == KEY_HOLD && m_vPos.x + m_InitSet.size.x < 1366)
    {
        m_vPos.x = m_vPos.x + g_fSecPerFrame * 300;
        rightleft = 0;
    }
    
    if (Input::Get().m_dwKeyState[VK_DOWN] == KEY_UP)
    {
    }
    
    SetPosion(m_vPos);
    return true;
}


