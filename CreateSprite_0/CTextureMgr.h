#pragma once
#include "CDevice.h"

#include "DirectXTex.h"

// 프로젝트 속성에 링커->입력->추가종속성
// #pragma commnet을 이용하면 프로젝트로 포함할 수 있다.
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
		std::wstring loadfilename);
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
	CTexture* Load(std::wstring loadfilename);
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

class CUIObj
{
public:
	ID3D11Device* m_pd3dDevice = nullptr;
	ID3D11DeviceContext* m_pd3dContext = nullptr;
	RECT					m_rtClient;


	std::unique_ptr<DirectX::ScratchImage> m_tex;
	ID3D11ShaderResourceView* m_pTextureSRV = nullptr;

	std::unique_ptr<DirectX::ScratchImage> m_texChange;
	ID3D11ShaderResourceView* m_pTextureSRVChange = nullptr;

	std::vector<TVertex>	m_VertexList; // 시스템 메모리
	std::vector<DWORD>		m_IndexList;

	ID3D11Buffer* m_pVertexbuffer; // 비디오카드 메모리
	ID3D11Buffer* m_pIndexbuffer; // 비디오카드 메모리

	ID3DBlob* m_pVertexShaderByteCode = nullptr;
	ID3DBlob* m_pPixelShaderByteCode = nullptr;

	ID3D11VertexShader* m_pVertexShader = nullptr;
	ID3D11PixelShader* m_pPixelShader = nullptr;

	ID3D11InputLayout* m_pVertexLayout = nullptr;

public:
	bool CreateVertexBuffer();
	bool CreateIndexBuffer();

	bool CreateVertexShader();
	bool CreatePixelShader();

	bool CreateInputLayout();

	virtual bool LoadTexture(std::wstring texFileName);
	bool LoadTextureChange(std::wstring texFileName);
public:
	bool    Init();
	bool	Load(std::wstring texFileName);
	bool	PreRender();
	bool    Render();
	bool	PostRender();
	bool    RenderChange();
	virtual bool    Release();
};

class CUINumber : public CUIObj
{
public:
	std::unique_ptr<DirectX::ScratchImage> m_texArray[10];
	ID3D11ShaderResourceView* m_pTextureSRVArray[10] = { nullptr, };
	bool	LoadTexture(std::wstring texFileName) override;
	bool    Release()
	{
		CUIObj::Release();
		for (int i = 0; i < 10; i++)
		{
			if (m_pTextureSRVArray[i])
			{
				m_pTextureSRVArray[i]->Release();
			}
		}
		return true;
	}
};
