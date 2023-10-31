#include "TStatus.h"

TStatus::~TStatus() {
	std::cout << "부모 해제자" << std::endl;
}

void TStatus::SetStr(int s) {
	this->stat.strength = s;
}
int TStatus::GetStr() {
	return stat.strength;
}
void TStatus::SetDex(int s) {
	this->stat.dexterity = s;
}
int TStatus::GetDex() {
	return stat.dexterity;
}
void TStatus::SetInt(int s) {
	this->stat.intelligence = s;
}
int TStatus::GetInt() {
	return stat.intelligence;
}
void TStatus::SetLuk(int s) {
	this->stat.luck = s;
}
int TStatus::GetLuk() {
	return stat.luck;
}

void TStatus::SetHP(int s) {
	this->stat.hp = s;
}
int TStatus::GetHP() {
	return stat.hp;
}
void TStatus::SetMP(int s) {
	this->stat.mp = s;
}
int TStatus::GetMP() {
	return stat.mp;
}

void TStatus::SetAttack(int s) {
	this->stat.attack = s;
}
int TStatus::GetAttack() {
	return stat.attack;
}
void TStatus::SetDefence(int s) {
	this->stat.defence = s;
}
int TStatus::GetDefence() {
	return stat.defence;
}

void TStatus::SetCriChance(int s) {
	this->stat.criChance = s;
}
int TStatus::GetCriChance() {
	return stat.criChance;
}
void TStatus::SetCriDamage(int s) {
	this->stat.criDamage = s;
}
int TStatus::GetCriDamage() {
	return stat.criDamage;
}

std::ostream& operator<<(std::ostream& os, const TStatus& t) {
	os << t.stat;
	return os;
}