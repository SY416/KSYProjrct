#pragma once
#include "CPlaneShape.h"

class CUIObj
{
public:

	std::vector<TVertex>	m_VertexList; // 시스템 메모리
	CTexture* m_ptTex = nullptr;

public:
	bool    Init()
	{
		return true;
	};
	bool	Load(std::wstring texFileName)
	{
		m_ptTex = CTextureMgr::Get().Load(texFileName);
		if (m_ptTex != nullptr)
			return true;
		return false;
	};
	bool	PreRender() {
		return true;
	};
	virtual bool Frame(float fElapsTime) {
		return true;
	};
	virtual bool Render(ID3D11DeviceContext* pd3dContext) {
		pd3dContext->PSSetShaderResources(0, 1, &m_ptTex->m_pTextureSRV);
		return true;
	};
	bool	PostRender() {
		return true;
	};
	bool    RenderChange() {
		return true;
	};
	virtual bool    Release() {
		return true;
	};
};

class CUINumber : public CUIObj
{
public:
	std::vector<CTexture*>  m_pTexArray;
	UINT    m_iApplyIndex = 0;
	float   m_fTimer = 0.0f;
	float   m_fAnimationTime = 1.0f;
	float   m_fStepTime = 0.0f;

public:
	bool    Init()
	{
		return true;
	};
	bool    Load(std::wstring texFileName);

	bool	PreRender() {
		return true;
	};
	bool    Frame(float fElapsTime);
	bool    Render(ID3D11DeviceContext* pd3dContext);

	bool	PostRender() {
		return true;
	};
	virtual bool    Release() {
		CUIObj::Release();
		return true;
	};
};
