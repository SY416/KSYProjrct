#pragma once
#include "TextureMgr.h"

struct TVector2
{
	float x;
	float y;
	TVector2() { x = 0; y = 0; }
	TVector2(float _x, float _y) { x = _x; y = _y; }
};

struct TVector3
{
	float x;
	float y;
	float z;
	TVector3() { x = 0; y = 0; z = 0; }
	// z의 성분은 0 ~ 1 범위로 되어 있다.
	TVector3(float _x, float _y, float _z = 0.0f) { x = _x; y = _y; z = _z; }
};

struct TVector4
{
	float x;
	float y;
	float z;
	float w;
	TVector4() { x = 0; y = 0; z = 0; w = 0; }
	TVector4(float _x, float _y, float _z, float _w) { x = _x; y = _y; z = _z; w = _w; }
};

struct TVertex
{
	TVector3 pos;
	TVector4 color;
	TVector2 tex;
	TVertex() { }
	TVertex(TVector3 p, TVector4 c, TVector2 t) { pos = p; color = c; tex = t; }
};

class PlaneShape
{
public:
	W_STR                   m_csName;

	ID3D11Device* m_pd3dDevice = nullptr;
	ID3D11DeviceContext* m_pd3dDeviceContext = nullptr;
	RECT					m_rtClient;

	Texture* m_ptTex;//텍스쳐 가져오기
	ID3D11ShaderResourceView* m_pTextureSRV = nullptr;

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

	bool LoadTexture(std::wstring texFileName);
public:
	bool    Init();
	bool	Create(W_STR name, W_STR texFileName);
	bool    Render();
	bool    Release();
};
