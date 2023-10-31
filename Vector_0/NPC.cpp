#include "NPC.h"
NPC::~NPC() {
	std::cout << "NPC ÇØÁ¦ÀÚ" << std::endl;
}

void NPC::SetStr(int s) {
	Status::SetStr(s - 4000);
}
void NPC::SetDex(int s) {
	Status::SetDex(s - 3000);
}
void NPC::SetInt(int s) {
	Status::SetInt(s - 55000);
}
void NPC::SetLuk(int s) {
	Status::SetLuk(s - 7000);
}

void NPC::SetHP(int s) {
	Status::SetHP(s * 1000000);
}
void NPC::SetMP(int s) {
	Status::SetMP(s * 0);
}

void NPC::SetAttack(int s) {
	Status::SetAttack(s - 5000);
}
void NPC::SetDefence(int s) {
	Status::SetDefence(s + 10000);
}


void NPC::SetCriChance(int s) {
	Status::SetCriChance(s * 0);
}
void NPC::SetCriDamage(int s) {
	Status::SetCriDamage(s * 0);
}

