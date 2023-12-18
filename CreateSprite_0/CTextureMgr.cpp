#include "CTextureMgr.h"

bool CTexture::Load(ID3D11Device* pd3dDevice, ID3D11DeviceContext* pd3dContext, std::wstring texFileName)
{
    m_tex = std::make_unique< DirectX::ScratchImage>();
    DirectX::TexMetadata metadata;
    HRESULT hr = DirectX::GetMetadataFromWICFile(texFileName.c_str(), DirectX::WIC_FLAGS_NONE, metadata);
    if (SUCCEEDED(hr))
    {
        hr = DirectX::LoadFromWICFile(texFileName.c_str(), DirectX::WIC_FLAGS_NONE, &metadata, *m_tex);
        if (SUCCEEDED(hr))
        {
            hr = DirectX::CreateShaderResourceView(
                pd3dDevice,
                m_tex->GetImages(),
                m_tex->GetImageCount(),
                metadata,
                &m_pTextureSRV);
            if (SUCCEEDED(hr))
            {
                return true;
            }
        }
    }

    //DDS 다이렉트SDK 전용 압축포맷
    hr = DirectX::GetMetadataFromDDSFile(texFileName.c_str(), DirectX::DDS_FLAGS_NONE, metadata);
    if (SUCCEEDED(hr))
    {
        hr = DirectX::LoadFromDDSFile(texFileName.c_str(), DirectX::DDS_FLAGS_NONE, &metadata, *m_tex);
        if (SUCCEEDED(hr))
        {
            hr = DirectX::CreateShaderResourceView(
                pd3dDevice,
                m_tex->GetImages(),
                m_tex->GetImageCount(),
                metadata,
                &m_pTextureSRV);
            if (SUCCEEDED(hr))
            {
                return true;
            }
        }
    }

    hr = DirectX::GetMetadataFromTGAFile(texFileName.c_str(), DirectX::TGA_FLAGS_NONE, metadata);
    if (SUCCEEDED(hr))
    {
        hr = DirectX::LoadFromTGAFile(texFileName.c_str(), DirectX::TGA_FLAGS_NONE, &metadata, *m_tex);
        if (SUCCEEDED(hr))
        {
            hr = DirectX::CreateShaderResourceView(
                pd3dDevice,
                m_tex->GetImages(),
                m_tex->GetImageCount(),
                metadata,
                &m_pTextureSRV);
            if (SUCCEEDED(hr))
            {
                return true;
            }
        }
    }

    hr = DirectX::GetMetadataFromHDRFile(texFileName.c_str(), metadata);
    if (SUCCEEDED(hr))
    {
        hr = DirectX::LoadFromHDRFile(texFileName.c_str(), &metadata, *m_tex);
        if (SUCCEEDED(hr))
        {
            hr = DirectX::CreateShaderResourceView(
                pd3dDevice,
                m_tex->GetImages(),
                m_tex->GetImageCount(),
                metadata,
                &m_pTextureSRV);
            if (SUCCEEDED(hr))
            {
                return true;
            }
        }
    }

    return false;
}

bool CTexture::Release()
{
    if (m_pTextureSRV)m_pTextureSRV->Release();
	return true;
}

CTexture* CTextureMgr::Load(std::wstring loadfilename)
{
    auto iter = m_list.find(loadfilename);
    if (iter != m_list.end())
    {
        return iter->second.get();
    }
    std::shared_ptr<CTexture> pTex = std::make_shared<CTexture>();
    if (pTex->Load(m_pd3dDevice, m_pd3dContext, loadfilename))
    {
        m_list.insert(std::make_pair(loadfilename, pTex));
        return pTex.get();
    }
	return nullptr;
}

bool CTextureMgr::Release()
{
    for (auto data : m_list)
    {
        data.second->Release();
    }
    m_list.clear();
	return true;
}

CTextureMgr::~CTextureMgr()
{
	Release();
}
