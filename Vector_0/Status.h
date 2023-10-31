#pragma once
#include <iostream>

struct Stat {
	int strength = 4727, dexterity = 3373, intelligence = 55637, luck = 7363;
	int hp = 130207, mp = 51921;
	int attack = 5950;
	int defence = 52573;
	int criChance = 100;
	int criDamage = 95;
	friend std::ostream& operator<<(std::ostream& os, const Stat& t) {
		os << "  HP             " << t.hp << "  MP               " << t.mp
			<< "\n  STR            " << t.strength << "\n  DEX            " << t.dexterity << "\n  INT            " << t.intelligence << "\n  LUK            " << t.luck
			<< "\n  공격력         " << t.attack << "    방어력           " << t.defence
			<< "\n  크리티컬 확률  " << t.criChance << " %" << "   크리티컬 데미지  " << t.criDamage << " %\n\n" << std::endl;
		return os;
	}
};


class Status
{
public:
	Stat stat;
public:
	virtual ~Status();

	virtual void SetStr(int s);
	int GetStr();
	virtual void SetDex(int s);
	int GetDex();
	virtual void SetInt(int s);
	int GetInt();
	virtual void SetLuk(int s);
	int GetLuk();

	virtual void SetHP(int s);
	int GetHP();
	virtual void SetMP(int s);
	int GetMP();

	virtual void SetAttack(int s);
	int GetAttack();
	virtual void SetDefence(int s);
	int GetDefence();

	virtual void SetCriChance(int s);
	int GetCriChance();
	virtual void SetCriDamage(int s);
	int GetCriDamage();

	friend std::ostream& operator<<(std::ostream& os, const Status& t);
};

