#pragma once
#include "Status.h"
class Player : public Status
{
public:
	virtual ~Player();

	int EXP;

	void SetEXP(int s);
	int GetEXP();

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
