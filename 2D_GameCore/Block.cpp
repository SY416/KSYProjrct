#include "Block.h"

bool    Block::Create(TInitSet info, W_STR texFileName)
{
    m_InitSet = info;
    m_csName = info.name;
    m_vPos = info.p;
    PlaneShape::Create(m_csName, texFileName);
    return true;
}
bool Block::CreateVertexBuffer()
{
    SetVB(m_InitSet.p, m_InitSet.size);
    PlaneShape::CreateVertexBuffer();
    return true;
}
bool   Block::SetVB(TVector2 p,
    TVector2 size)
{
    m_VertexList.clear();

    m_VertexList.emplace_back(TVector3(p.x, p.y, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 0.0f));      // 0
    m_VertexList.emplace_back(TVector3(p.x + size.x, p.y, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 0.0f));    // 1
    m_VertexList.emplace_back(TVector3(p.x + size.x, p.y + size.y, 0.5f), TVector4(1, 1, 1, 1), TVector2(1.0f, 1.0f));  // 2
    m_VertexList.emplace_back(TVector3(p.x, p.y + size.y, 0.5f), TVector4(1, 1, 1, 1), TVector2(0.0f, 1.0f));    // 3

    return true;
}
