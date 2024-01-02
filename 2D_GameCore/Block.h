#pragma once

#include "PlaneShape.h"

struct TInitSet
{
	W_STR name;
	TVector2 p;
	TVector2 size;
};

class Block : public PlaneShape
{
public:
	TInitSet	m_InitSet;

	TVector2    m_vPos;

public:
	bool   CreateVertexBuffer() override;
public:
	bool   Create(TInitSet info, W_STR texFileName);
	bool   SetVB(TVector2 p, TVector2 size);
};

