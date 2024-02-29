#pragma once
#include "std.h"
#include "../../include/DirectXTex.h"
//프로젝트 속성에서 C++-> 추가 포함 디렉토리에 ../../include 한다.
//#include "DirectXTex.h"

//프로젝트 속성에 링커->입력->추가종속성 d3d11.lib; d3dcompiler.lib; DirectXTex.lib;
//#pragma commnet을 이용하면 프로젝트으로 포함할 수 있다.
//#pragma comment (lib, "../../lib/DirectXTex.lib")//디버그
#pragma comment (lib, "../../lib/DirectXTexR.lib")//릴리즈
class Texture
{
public:
	std::unique_ptr<DirectX::ScratchImage> m_tex;
	ID3D11ShaderResourceView* m_pTextureSRV = nullptr;
public:
	bool		Load(ID3D11Device* pd3dDevice,
		ID3D11DeviceContext* pd3dContext,
		std::wstring loadfilename);
	bool		Release();
	Texture() {}
	virtual ~Texture() {}
};
class TextureMgr
{
	ID3D11Device* m_pd3dDevice = nullptr;
	ID3D11DeviceContext* m_pd3dContext = nullptr;
public:
	static TextureMgr& Get()
	{
		static TextureMgr mgr;
		return mgr;
	}
	std::map<std::wstring, std::shared_ptr<Texture>> m_list;
	Texture* Load(std::wstring loadfilename);
	bool   Release();
	void  Set(ID3D11Device* pd3dDevice,
		ID3D11DeviceContext* pd3dContext)
	{
		m_pd3dDevice = pd3dDevice;
		m_pd3dContext = pd3dContext;
	}
private:
	TextureMgr() {}
public:
	~TextureMgr();
};

