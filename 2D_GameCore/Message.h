#pragma once
#include "PlaneShape.h"

struct MInitSet
{
	W_STR name;
};


class Message : public PlaneShape
{
public:
	MInitSet	m_InitSet;

	TVector2    m_vPos;
public:
	bool   CreateVertexBuffer() override;
public:
	bool   Create(MInitSet info, W_STR texFileName);
	bool   SetVB(TVector2 p, TVector2 size);
};

