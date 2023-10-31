#pragma once
#include "TStatus.h"
class TNPC : public TStatus
{
public:
	virtual ~TNPC();

	void SetStr(int s);
	void SetDex(int s);
	void SetInt(int s);
	void SetLuk(int s);

	void SetHP(int s);
	void SetMP(int s);

	void SetAttack(int s);
	void SetDefence(int s);

	void SetCriChance(int s);
	void SetCriDamage(int s);
};
