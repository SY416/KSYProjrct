#include "Monster.h"
#include "Input.h"


bool    Monster::Create(TInitSet info, T_STR_VECTOR texFileName)
{
    m_InitSet = info;
    m_csName = info.name;
    m_vPos = info.p;
    PlaneShape::Create(m_csName, texFileName);
    return true;
}
bool Monster::CreateVertexBuffer()
{
    SetVB(m_InitSet.p, m_InitSet.size);
    PlaneShape::CreateVertexBuffer();
    return true;
}
bool   Monster::SetVB(TVector2 p,
    TVector2 size)
{
    m_VertexList.clear();

    m_VertexList.emplace_back(TVector3(p.x, p.y, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 0.0f));      // 0
    m_VertexList.emplace_back(TVector3(p.x + size.x, p.y, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 0.0f));    // 1
    m_VertexList.emplace_back(TVector3(p.x + size.x, p.y + size.y, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 1.0f));  // 2
    m_VertexList.emplace_back(TVector3(p.x, p.y + size.y, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 1.0f));    // 3

    return true;
}

void   Monster::SetPosion(TVector2 p)
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


void   Monster::SetPosion(float x, float y)
{

}
bool Monster::Frame()
{
    srand(time(NULL));

    int random = rand() % 9;

    if (random < 3 && m_vPos.x > 510)
    {
        m_vPos.x = m_vPos.x - g_fSecPerFrame * 100;
        rl = 1;
    }

    else if (random < 6 && m_vPos.x + m_InitSet.size.x < 628)
    {
        m_vPos.x = m_vPos.x + g_fSecPerFrame * 100;
        rl = 0;
    }

    else
    {
        m_vPos.x = m_vPos.x + g_fSecPerFrame * 0;
    }

    if (rightleft == 0) {
        g_uiState = 0;
    }
    else {
        g_uiState = 1;
    }


    if (m_pTexArray.size() > 0)
    {
        m_ptTex = m_pTexArray[g_uiState];
    }
    

    SetPosion(m_vPos);
    return true;
}