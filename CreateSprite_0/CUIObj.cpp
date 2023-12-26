#include "CUIObj.h"
#include "CInput.h"

bool    CUIObj::Create(W_STR name, T_STR_VECTOR texFileName)
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

bool    CUIObj::Create(W_STR name, W_STR texFileName)
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

bool    CUIObj::Init() {
    return true;
};

bool    CUIObj::Load(std::wstring LoadFileName) {
    return true;
};

bool CUIObj::LoadTexture(std::wstring texFileName)
{
    m_ptTex = CTextureMgr::Get().Load(texFileName);
    if (m_ptTex != nullptr)
        return true;
    return false;
}

bool CUIObj::LoadTexture(T_STR_VECTOR texArray)
{
    for (int i = 0; i < texArray.size(); i++)
    {
        m_pTexArray.push_back(CTextureMgr::Get().Load(texArray[i]));
    }
    m_ptTex = m_pTexArray[m_uiState];
    return true;
}

bool CUIObj::Frame(float fElapsTime)
{
    if (m_uiState == T_STATE_PRESSED && m_pTexArray.size() > 0)
    {
        if (CInput::Get().m_dwKeyState[VK_LBUTTON] == KEY_UP)
        {
            m_isSelected = TRUE;
            MessageBox(NULL, m_csName.c_str(), L"Selected!", MB_OK);
            return true;
        }
    }//클릭시
    m_uiState = T_STATE_NORMAL;
    POINT tpMouse = CInput::Get().m_ptMouse;
    if (m_rtRect.left <= tpMouse.x && m_rtRect.right >= tpMouse.x)
    {
        if (m_rtRect.top <= tpMouse.y && m_rtRect.bottom >= tpMouse.y)
        {
            m_uiState = T_STATE_MOUSEOVER;
            if (CInput::Get().m_dwKeyState[VK_LBUTTON] == KEY_HOLD)
            {
                m_uiState = T_STATE_PRESSED;
            }
        }
    }//호버
    if (m_pTexArray.size() > 0)
    {
        m_ptTex = m_pTexArray[m_uiState];
    }
    return true;
}

bool CUIObj::PreRender()
{
    return true;
}

bool    CUIObj::Render(ID3D11DeviceContext* pd3dContext) {
    pd3dContext->PSSetShaderResources(0, 1, &m_ptTex->m_pTextureSRV);
    return true;
}

bool    CUIObj::PostRender() { return true; };

bool    CUIObj::Release() { return true; };



bool    CUINumber::Create(W_STR name, T_STR_VECTOR texArray)
{
    LoadTexture(texArray);
    return true;
}

bool    CUINumber::Create(W_STR name)
{
    LoadTexture();
    return true;
}

bool CUINumber::LoadTexture()
{
    for (int i = 0; i < 10; i++)
    {
        std::wstring filename = L"../../data/";
        filename += std::to_wstring(i);
        filename += L".png";
        m_pTexArray.push_back(CTextureMgr::Get().Load(filename));
    }

    m_iApplyIndex = 0;
    m_fTimer = 0.0f;
    m_fAnimationTime = 10.0f;
    m_fStepTime = m_fAnimationTime / m_pTexArray.size();
    return true;
}

bool CUINumber::LoadTexture(T_STR_VECTOR texArray)
{
    CUIObj::LoadTexture(texArray);

    m_iApplyIndex = 0;
    m_fTimer = 0.0f;
    m_fAnimationTime = 10.0f;
    m_fStepTime = m_fAnimationTime / m_pTexArray.size();
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

bool CUINumber::Release()
{
    CUIObj::Release();
    return true;
}
