#include "CreateDevice.h"
bool CreateDevice::CreateVertexBuffer()
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

bool CreateDevice::CreateIndexBuffer()
{
    D3D11_BUFFER_DESC bd;
    ZeroMemory(&bd, sizeof(bd));
    bd.ByteWidth = m_IndexList.size()*sizeof(TVertex);
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

bool CreateDevice::CreateVertexShader() {
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

bool CreateDevice::CreatePixelShader() {
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
bool CreateDevice::CreateInputLayout()
{
    const D3D11_INPUT_ELEMENT_DESC layout[] =
    {
        {"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
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
        &m_pVertexLayout
    );
    
    if (FAILED(hr))
    {
        return false;
    }

    return true;
}
bool    CreateDevice::Init()
{
    // v0       v1
    //
    // v3       v2
    //m_VertexList.emplace_back(0.0f, 0.0f);      // 0
    //m_VertexList.emplace_back(800.0f, 0.0f);    // 1
    //m_VertexList.emplace_back(800.0f, 600.0f);  // 2
    //m_VertexList.emplace_back(0.0f, 600.0f);    // 3


    m_VertexList.emplace_back(0.33f, 0.5f);     // 0
    m_VertexList.emplace_back(0.5f, 0.5f);      // 1
    m_VertexList.emplace_back(0.5f, 0.33f);     // 2
    m_VertexList.emplace_back(0.33f, 0.33f);    // 3

    //m_VertexList.emplace_back(0.0f, 1.0f);    // 0
    //m_VertexList.emplace_back(1.0f, 1.0f);    // 1
    //m_VertexList.emplace_back(1.0f, -1.0f);    // 2
    //m_VertexList.emplace_back(0.0f, -1.0f);    // 3

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
     
     return true;
}
bool    CreateDevice::Render()
{
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
    m_pd3dContext->DrawIndexed(m_IndexList.size(), 0, 0);


    return true;
}
bool    CreateDevice::Release()
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

//HINSTANCE : 운영체제가 관리하는 윈도우 프로세스ID
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    CreateDevice win;
    win.SetWindow(hInstance, nCmdShow);
    win.Run();
    return 0;
}


