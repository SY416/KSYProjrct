#include "MovingBlock.h"
#include "Input.h"
int turn = 0;
int turn2 = 0;

bool    MovingBlock::Create(TInitSet info, W_STR texFileName)
{
    m_InitSet = info;
    m_csName = info.name;
    m_vPos = info.p;
    m_vSize = info.size;
    PlaneShape::Create(m_csName, texFileName);
    return true;
}
bool MovingBlock::CreateVertexBuffer()
{
    SetVB(m_InitSet.p, m_InitSet.size);
    PlaneShape::CreateVertexBuffer();
    return true;
}
bool   MovingBlock::SetVB(TVector2 p,
    TVector2 size)
{
    m_VertexList.clear();

    m_VertexList.emplace_back(TVector3(p.x, p.y, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 0.0f));      // 0
    m_VertexList.emplace_back(TVector3(p.x + size.x, p.y, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 0.0f));    // 1
    m_VertexList.emplace_back(TVector3(p.x + size.x, p.y + size.y, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 1.0f));  // 2
    m_VertexList.emplace_back(TVector3(p.x, p.y + size.y, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 1.0f));    // 3

    return true;
}

void   MovingBlock::SetPosion(TVector2 p)
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


void   MovingBlock::SetPosion(float x, float y)
{

}
bool MovingBlock::Frame()
{
    //  위치 = 현 위치 + 이동방향 * 시간의 동기화( 1초당 최대 거리 이동)
    //  g_fSecPerFrame * m_fSpeed;
    //  1프레임  -> 1초 * 300     -> 300
    //  10프레임 -> 0.1초 * 300   -> 300
    //  100프레임 -> 0.01초 *300  -> 300
    if (turn == 0 && m_vSize.x > 40)
    {
        m_vPos.x = m_vPos.x + g_fSecPerFrame * 200;
        if (m_vPos.x >= 700.0f) {
            turn = 1;
        }
    }
    
    else if  (turn == 1 && m_vSize.x > 40)
    {
        m_vPos.x = m_vPos.x - g_fSecPerFrame * 200;
        if (m_vPos.x <= 510.0f) {
            turn = 0;
        }
    }

    if (turn2 == 0 && m_vSize.x < 40)
    {
        m_vPos.x = m_vPos.x + g_fSecPerFrame * 400;
        if (m_vPos.x >= 1100.0f) {
            turn2 = 1;
        }
    }

    else if (turn2 == 1 && m_vSize.x < 40)
    {
        m_vPos.x = m_vPos.x - g_fSecPerFrame * 400;
        if (m_vPos.x <= 350.0f) {
            turn2 = 0;
        }
    }

    SetPosion(m_vPos);
    return true;
}

