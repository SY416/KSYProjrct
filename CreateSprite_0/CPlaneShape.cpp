#include "CPlaneShape.h"

bool CPlaneShape::LoadTexture(std::wstring texFileName)
{
    m_ptTex = CTextureMgr::Get().Load(texFileName);
    if (m_ptTex != nullptr)
        return true;
    return false;
}

bool CPlaneShape::LoadTexture(T_STR_VECTOR texArray)
{
    for (int i = 0; i < texArray.size(); i++)
    {
        m_pTexArray.push_back(CTextureMgr::Get().Load(texArray[i]));
    }
    m_ptTex = m_pTexArray[0];
    return true;
}

bool CPlaneShape::CreateVertexBuffer()
{
    D3D11_BUFFER_DESC bd;
    ZeroMemory(&bd, sizeof(D3D11_BUFFER_DESC));
    bd.ByteWidth = m_VertexList.size() * sizeof(TVertex);//메모리 할당크기
    bd.Usage = D3D11_USAGE_DEFAULT;//버퍼의 저장소 및 접근권한 설정
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;//버퍼의 용도
    /*UINT CPUAccessFlags;
    UINT MiscFlags;
    UINT StructureByteStride;*/

    D3D11_SUBRESOURCE_DATA sd;
    ZeroMemory(&sd, sizeof(D3D11_SUBRESOURCE_DATA));
    sd.pSysMem = &m_VertexList.at(0);
    /*UINT SysMemPitch;
    UINT SysMemSlicePitch;*/


    HRESULT hr = m_pd3dDevice->CreateBuffer(&bd, &sd, &m_pVertexbuffer);

    if (FAILED(hr))
    {
        return false;
    }

    return true;
}

bool CPlaneShape::CreateIndexBuffer()
{
    D3D11_BUFFER_DESC bd;
    ZeroMemory(&bd, sizeof(bd));
    bd.ByteWidth = m_IndexList.size() * sizeof(DWORD);
    bd.Usage = D3D11_USAGE_DEFAULT;
    bd.BindFlags = D3D11_BIND_INDEX_BUFFER;

    D3D11_SUBRESOURCE_DATA sd;
    ZeroMemory(&sd, sizeof(sd));
    sd.pSysMem = &m_IndexList.at(0);

    HRESULT hr = m_pd3dDevice->CreateBuffer(&bd, &sd, &m_pIndexbuffer);

    if (FAILED(hr))
    {
        return false;
    }

    return true;
}

bool CPlaneShape::CreateVertexShader() {
    ID3DBlob* ppErrorMsg;
    HRESULT hr = D3DCompileFromFile(
        L"Shader.txt",
        nullptr,
        nullptr,
        "VS",
        "vs_5_0",
        0,
        0,
        &m_pVertexShaderByteCode,
        &ppErrorMsg);

    if (FAILED(hr))
    {
        MessageBoxA(NULL, (char*)ppErrorMsg->GetBufferPointer(), "Error", MB_OK);
        if (ppErrorMsg)ppErrorMsg->Release();
        return false;
    }
    if (ppErrorMsg)ppErrorMsg->Release();

    hr = m_pd3dDevice->CreateVertexShader(
        m_pVertexShaderByteCode->GetBufferPointer(),
        m_pVertexShaderByteCode->GetBufferSize(),
        nullptr,
        &m_pVertexShader);

    if (FAILED(hr))
    {
        return false;
    }

    return true;
}

bool CPlaneShape::CreatePixelShader() {
    ID3DBlob* ppErrorMsg;
    HRESULT hr = D3DCompileFromFile(
        L"Shader.txt",
        nullptr,
        nullptr,
        "PS",
        "ps_5_0",
        0,
        0,
        &m_pPixelShaderByteCode,
        &ppErrorMsg);

    if (FAILED(hr))
    {
        MessageBoxA(NULL, (char*)ppErrorMsg->GetBufferPointer(), "Error", MB_OK);
        if (ppErrorMsg)ppErrorMsg->Release();
        return false;
    }
    if (ppErrorMsg)ppErrorMsg->Release();

    hr = m_pd3dDevice->CreatePixelShader(
        m_pPixelShaderByteCode->GetBufferPointer(),
        m_pPixelShaderByteCode->GetBufferSize(),
        nullptr,
        &m_pPixelShader);

    if (FAILED(hr))
    {
        return false;
    }

    return true;
}

bool CPlaneShape::CreateInputLayout()
{
    const D3D11_INPUT_ELEMENT_DESC layout[] =
    {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "TEX", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 28, D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };

    /*D3D11_INPUT_ELEMENT_DESC pInputElementDescs;
    LPCSTR SemanticName;
    UINT SemanticIndex;
    DXGI_FORMAT Format;
    UINT InputSlot;
    UINT AlignedByteOffset;
    D3D11_INPUT_CLASSIFICATION InputSlotClass;
    UINT InstanceDataStepRate;*/

    UINT iNumLayout = sizeof(layout) / sizeof(layout[0]);

    HRESULT hr = m_pd3dDevice->CreateInputLayout(
        layout,
        iNumLayout,
        m_pVertexShaderByteCode->GetBufferPointer(),
        m_pVertexShaderByteCode->GetBufferSize(),
        &m_pVertexLayout);

    if (FAILED(hr))
    {
        return false;
    }

    return true;
}
bool CPlaneShape::Init()
{
    return true;
}

bool CPlaneShape::Create(W_STR name, T_STR_VECTOR texFileName)
{
    m_csName = name;

    m_IndexList.push_back(0);
    m_IndexList.push_back(1);
    m_IndexList.push_back(2);

    m_IndexList.push_back(2);
    m_IndexList.push_back(3);
    m_IndexList.push_back(0);

    if (!CreateVertexBuffer() || !CreateIndexBuffer())
    {
        return false;
    }

    if (!CreateVertexShader() || !CreatePixelShader())
    {
        return false;
    }

    if (!CreateInputLayout())
    {
        return false;
    }
    if (!LoadTexture(texFileName))
    {
        return false;
    }

    return true;
}

bool CPlaneShape::Create(W_STR name, W_STR texFileName)
{
    m_csName = name;

    m_IndexList.push_back(0);
    m_IndexList.push_back(1);
    m_IndexList.push_back(2);

    m_IndexList.push_back(2);
    m_IndexList.push_back(3);
    m_IndexList.push_back(0);

    if (!CreateVertexBuffer() || !CreateIndexBuffer())
    {
        return false;
    }

    if (!CreateVertexShader() || !CreatePixelShader())
    {
        return false;
    }

    if (!CreateInputLayout())
    {
        return false;
    }
    if (!LoadTexture(texFileName))
    {
        return false;
    }

    return true;
}

bool CPlaneShape::Frame()
{
    return true;
}

bool    CPlaneShape::PreRender()
{
    m_pd3dContext->PSSetShaderResources(0, 1, &m_ptTex->m_pTextureSRV);
    m_pd3dContext->VSSetShader(m_pVertexShader, NULL, 0);
    m_pd3dContext->PSSetShader(m_pPixelShader, NULL, 0);
    m_pd3dContext->IASetInputLayout(m_pVertexLayout);
    m_pd3dContext->IASetIndexBuffer(m_pIndexbuffer, DXGI_FORMAT_R32_UINT, 0);

    UINT pStrides = sizeof(TVertex);
    UINT pOffsets = 0;

    m_pd3dContext->IASetVertexBuffers(
        0,
        1,
        &m_pVertexbuffer,
        &pStrides,
        &pOffsets);

    m_pd3dContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    return true;
}
bool    CPlaneShape::PostRender()
{
    m_pd3dContext->DrawIndexed(m_IndexList.size(), 0, 0);

    return true;
}
bool    CPlaneShape::Render()
{
    PreRender();
    PostRender();

    return true;
}

bool    CPlaneShape::Release()
{
    if (m_pVertexbuffer)m_pVertexbuffer->Release();
    if (m_pIndexbuffer)m_pIndexbuffer->Release();

    if (m_pVertexShaderByteCode)m_pVertexShaderByteCode->Release();
    if (m_pPixelShaderByteCode)m_pPixelShaderByteCode->Release();

    if (m_pVertexShader)m_pVertexShader->Release();
    if (m_pPixelShader)m_pPixelShader->Release();

    if (m_pVertexLayout)m_pVertexLayout->Release();
    return true;
}