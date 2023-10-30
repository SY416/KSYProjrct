#include "TNPC.h"
TNPC::~TNPC() {
	std::cout << "NPC ÇØÁ¦ÀÚ" << std::endl;
}

void TNPC::SetStr(int s) {
	TStatus::SetStr(s - 4000);
}
void TNPC::SetDex(int s) {
	TStatus::SetDex(s - 3000);
}
void TNPC::SetInt(int s) {
	TStatus::SetInt(s - 55000);
}
void TNPC::SetLuk(int s) {
	TStatus::SetLuk(s - 7000);
}

void TNPC::SetHP(int s) {
	TStatus::SetHP(s * 100000000);
}
void TNPC::SetMP(int s) {
	TStatus::SetMP(s * 0);
}

void TNPC::SetAttack(int s) {
	TStatus::SetAttack(s - 5000);
}
void TNPC::SetDefence(int s) {
	TStatus::SetDefence(s + 10000);
}


void TNPC::SetCriChance(int s) {
	TStatus::SetCriChance(s * 0);
}
void TNPC::SetCriDamage(int s) {
	TStatus::SetCriDamage(s * 0);
}
