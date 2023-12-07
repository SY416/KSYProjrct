#pragma once
#include "CDevice.h"


struct TVertex
{
	float x;
	float y;
	float z;
	TVertex() { x = 0; y = 0; z = 0; }
	// z�� ������ 0 ~ 1 ������ �Ǿ� �ִ�.
	TVertex(float _x, float _y, float _z = 0.0f) { x = _x; y = _y; z = _z; }
};

class CreateDevice : public CDevice
{
	std::vector<TVertex>	m_VertexList; // �ý��� �޸�
	std::vector<DWORD>		m_IndexList;

	ID3D11Buffer*			m_pVertexbuffer; // ����ī�� �޸�
	ID3D11Buffer*			m_pIndexbuffer; // ����ī�� �޸�

	ID3DBlob*				m_pVertexShaderByteCode = nullptr;
	ID3DBlob*				m_pPixelShaderByteCode = nullptr;

	ID3D11VertexShader*		m_pVertexShader = nullptr;
	ID3D11PixelShader*		m_pPixelShader = nullptr;

	ID3D11InputLayout*		m_pVertexLayout = nullptr;

public:
	bool CreateVertexBuffer();
	bool CreateIndexBuffer();

	bool CreateVertexShader();
	bool CreatePixelShader();

	bool CreateInputLayout();
public:
	bool    Init()		override;
	bool    Render()	override;
	bool    Release()	override;
};
