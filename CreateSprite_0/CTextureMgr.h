#pragma once
#include <memory>
#include <map>
#include <string>

#include "DirectXTex.h"

// ������Ʈ �Ӽ��� ��Ŀ->�Է�->�߰����Ӽ�
// #pragma commnet�� �̿��ϸ� ������Ʈ�� ������ �� �ִ�.
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dcompiler.lib")
#pragma comment (lib, "DirectXTex.lib")

class CTexture
{
public:
	std::unique_ptr<DirectX::ScratchImage> m_tex;
	ID3D11ShaderResourceView* m_pTextureSRV = nullptr;
public:
	bool Load(ID3D11Device* pd3dDevice,
		ID3D11DeviceContext* pd3dContext,
		std::wstring texFileName);
	bool Release();
	CTexture() {}
	virtual ~CTexture() {}
};

class CTextureMgr
{
	ID3D11Device* m_pd3dDevice = nullptr;
	ID3D11DeviceContext* m_pd3dContext = nullptr;
public:
	static CTextureMgr& Get()
	{
		static CTextureMgr mgr;
		return mgr;
	}
	std::map<std::wstring, std::shared_ptr<CTexture>> m_list;
	CTexture* Load(std::wstring texFileName);
	bool Release();
	void Set(ID3D11Device* pd3dDevice,
		ID3D11DeviceContext* pd3dContext)
	{
		m_pd3dDevice = pd3dDevice;
		m_pd3dContext = pd3dContext;
	}
private:
	CTextureMgr() {}
public:
	~CTextureMgr();
};