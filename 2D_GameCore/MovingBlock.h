#pragma once
#include "Block.h"

class MovingBlock : public Block
{
public:
	TVector2    m_vPos;
	TVector2    m_vSize;
public:

	bool   Frame() override;
public:
	bool   CreateVertexBuffer() override;
public:
	bool   Create(TInitSet info, W_STR texFileName);
	bool   SetVB(TVector2 p, TVector2 size);
	void   SetPosion(float x, float y);
	void   SetPosion(TVector2 p);
};
