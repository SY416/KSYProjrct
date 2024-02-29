#pragma once
#include "std.h"
#include "../../include/DirectXTex.h"
//������Ʈ �Ӽ����� C++-> �߰� ���� ���丮�� ../../include �Ѵ�.
//#include "DirectXTex.h"

//������Ʈ �Ӽ��� ��Ŀ->�Է�->�߰����Ӽ� d3d11.lib; d3dcompiler.lib; DirectXTex.lib;
//#pragma commnet�� �̿��ϸ� ������Ʈ���� ������ �� �ִ�.
//#pragma comment (lib, "../../lib/DirectXTex.lib")//�����
#pragma comment (lib, "../../lib/DirectXTexR.lib")//������
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

