#include "Status.h"

Status::~Status() {
	std::cout << "부모 해제자" << std::endl;
}

void Status::SetStr(int s) {
	this->stat.strength = s;
}
int Status::GetStr() {
	return stat.strength;
}
void Status::SetDex(int s) {
	this->stat.dexterity = s;
}
int Status::GetDex() {
	return stat.dexterity;
}
void Status::SetInt(int s) {
	this->stat.intelligence = s;
}
int Status::GetInt() {
	return stat.intelligence;
}
void Status::SetLuk(int s) {
	this->stat.luck = s;
}
int Status::GetLuk() {
	return stat.luck;
}

void Status::SetHP(int s) {
	this->stat.hp = s;
}
int Status::GetHP() {
	return stat.hp;
}
void Status::SetMP(int s) {
	this->stat.mp = s;
}
int Status::GetMP() {
	return stat.mp;
}

void Status::SetAttack(int s) {
	this->stat.attack = s;
}
int Status::GetAttack() {
	return stat.attack;
}
void Status::SetDefence(int s) {
	this->stat.defence = s;
}
int Status::GetDefence() {
	return stat.defence;
}

void Status::SetCriChance(int s) {
	this->stat.criChance = s;
}
int Status::GetCriChance() {
	return stat.criChance;
}
void Status::SetCriDamage(int s) {
	this->stat.criDamage = s;
}
int Status::GetCriDamage() {
	return stat.criDamage;
}

std::ostream& operator<<(std::ostream& os, const Status& t) {
	os << t.stat;
	return os;
}