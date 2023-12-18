#include "CUIObj.h"
#include "CInput.h"

bool CUIObj::Create(W_STR name, T_STR_VECTOR texFileName)
{
    m_csName = name;
    m_rtRect.left = m_VertexList[0].pos.x;
    m_rtRect.top = m_VertexList[0].pos.y;
    m_rtRect.right = m_VertexList[2].pos.x;
    m_rtRect.bottom = m_VertexList[2].pos.y;

    m_uiState = T_CONTROL_STATE::T_STATE_NORMAL;
    LoadTexture(texFileName);
    return true;
}

bool CUIObj::Create(W_STR name, W_STR texFileName)
{
    m_csName = name;
    m_rtRect.left = m_VertexList[0].pos.x;
    m_rtRect.top = m_VertexList[0].pos.y;
    m_rtRect.right = m_VertexList[2].pos.x;
    m_rtRect.bottom = m_VertexList[2].pos.y;

    m_uiState = T_CONTROL_STATE::T_STATE_NORMAL;
    LoadTexture(texFileName);
    return true;
}

bool CUINumber::Init()
{
    return true;
}

bool CUINumber::Load(std::wstring LoadFileName)
{
    return true;
}

bool CUINumber::Frame(float fElapsTime)
{
    if (m_fAnimationTime <= 0.0f)
    {
        m_iApplyIndex = 0;
        m_fAnimationTime = 10.0f;
        return true;
    }
    m_fAnimationTime -= fElapsTime;
    m_fTimer += fElapsTime;
    if (m_fTimer >= m_fStepTime)
    {
        m_iApplyIndex++;
        m_iApplyIndex = min(m_pTexArray.size() - 1, m_iApplyIndex);
        m_fTimer -= m_fStepTime;
    }
    return true;
}

bool CUINumber::Render(ID3D11DeviceContext* pd3dContext)
{
    pd3dContext->PSSetShaderResources(0, 1, &m_pTexArray[m_iApplyIndex]->m_pTextureSRV);
    return true;
}
