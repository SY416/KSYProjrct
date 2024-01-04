#pragma once
#include "Block.h"

class Monster : public Block
{
public:
	TVector2    m_vPos;

	float m_moving;
	int rl = 0;

public:

	bool   Frame() override;
public:
	bool   CreateVertexBuffer() override;
public:
	bool   Create(TInitSet info, T_STR_VECTOR texFileName);
	bool   SetVB(TVector2 p, TVector2 size);
	void   SetPosion(float x, float y);
	void   SetPosion(TVector2 p);
};

