#pragma once
#include "CDevice.h"
#include "CTextureMgr.h"

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

class CPlaneShape
{
public:
	W_STR m_csName;

	ID3D11Device* m_pd3dDevice = nullptr;
	ID3D11DeviceContext* m_pd3dContext = nullptr;
	RECT					m_rtClient;

	CTexture* m_ptTex;

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

	virtual bool	LoadTexture(std::wstring texFileName);
	virtual bool	LoadTexture(T_STR_VECTOR texFileName);

public:
	virtual bool    Init();
	virtual bool    Create(W_STR name, T_STR_VECTOR texFileName);
	virtual bool    Create(W_STR name, W_STR texFileName);
	virtual bool	PreRender();
	virtual bool    Render();
	virtual bool	PostRender();
	virtual bool    Release();
	
};

