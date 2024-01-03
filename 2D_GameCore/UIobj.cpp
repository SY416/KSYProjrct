#include "UIobj.h"
#include "Input.h"

UINT			g_uiState;

bool    UIobj::Create(W_STR name, T_STR_VECTOR texFileName)
{
    m_csName = name;
    m_rtRect.left = m_VertexList[0].pos.x;
    m_rtRect.top = m_VertexList[0].pos.y;
    m_rtRect.right = m_VertexList[2].pos.x;
    m_rtRect.bottom = m_VertexList[2].pos.y;

    g_uiState = 1;
    LoadTexture(texFileName);
    return true;
}
bool    UIobj::Create(W_STR name, W_STR texFileName)
{
    m_csName = name;
    // p0, w, h
    // p0, p1, p2, p3
    m_rtRect.left = m_VertexList[0].pos.x;
    m_rtRect.top = m_VertexList[0].pos.y;
    m_rtRect.right = m_VertexList[2].pos.x;
    m_rtRect.bottom = m_VertexList[2].pos.y;

    g_uiState = 0;
    LoadTexture(texFileName);
    return true;
}
bool    UIobj::Init() {
    return true;
};
bool    UIobj::Load(std::wstring LoadFileName) {
    return true;
};
bool UIobj::LoadTexture(T_STR_VECTOR texArray)
{
    for (int i = 0; i < texArray.size(); i++)
    {
        m_pTexArray.push_back(TextureMgr::Get().Load(texArray[i]));
    }
    m_ptTex = m_pTexArray[g_uiState];
    return true;
}
bool    UIobj::LoadTexture(std::wstring texFileName) {
    m_ptTex = TextureMgr::Get().Load(texFileName);
    if (m_ptTex != nullptr)
        return true;
    return false;
};
bool    UIobj::PreRender() {
    return true;
};
bool    UIobj::Frame()
{
    return true;
};
bool    UIobj::Render(ID3D11DeviceContext* pd3dContext) {
    pd3dContext->PSSetShaderResources(0, 1, &m_ptTex->m_pTextureSRV);
    return true;
};
bool    UIobj::PostRender() { return true; };
bool    UIobj::Release() { return true; };




/// <summary>
/// 
/// </summary>
/// <param name="texFileName"></param>
/// <returns></returns>
bool    UINumber::Create(W_STR name, T_STR_VECTOR texArray)
{
    LoadTexture(texArray);
    return true;
}
bool    UINumber::Create(W_STR name)
{
    LoadTexture();
    return true;
}
bool UINumber::LoadTexture(T_STR_VECTOR texArray)
{
    UIobj::LoadTexture(texArray);

    m_iApplyIndex = 0;
    m_fTimer = 0.0f;
    m_fAnimationTime = 10.0f;
    m_fStepTime = m_fAnimationTime / m_pTexArray.size();
    return true;
}
bool UINumber::LoadTexture()
{
    for (int i = 0; i < 10; i++)
    {
        std::wstring filename = L"../../data/";
        filename += std::to_wstring(i);
        filename += L".png";
        m_pTexArray.push_back(TextureMgr::Get().Load(filename));
    }

    m_iApplyIndex = 0;
    m_fTimer = 0.0f;
    m_fAnimationTime = 10.0f;
    m_fStepTime = m_fAnimationTime / m_pTexArray.size();
    return true;
}
bool    UINumber::Frame()
{
    if (m_fAnimationTime <= 0.0f)
    {
        //m_bStop = true;
         //return true;
        m_iApplyIndex = 0;
        m_fAnimationTime = 10.0f;
        return true;
    }
    /*m_fAnimationTime -= fElapsTime;
    m_fTimer += fElapsTime;*/
    if (m_fTimer >= m_fStepTime)
    {
        m_iApplyIndex++;
        m_iApplyIndex = min(m_pTexArray.size() - 1, m_iApplyIndex);
        m_fTimer -= m_fStepTime;
    }
    return true;
}
bool    UINumber::Render(ID3D11DeviceContext* pd3dContext)
{
    pd3dContext->PSSetShaderResources(0, 1, &m_pTexArray[m_iApplyIndex]->m_pTextureSRV);
    return true;
};

bool    UINumber::Release()
{
    UIobj::Release();
    return true;
}