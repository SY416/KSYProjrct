#include "TPlayer.h"
TPlayer::~TPlayer() {
	std::cout << "Player ÇØÁ¦ÀÚ" << std::endl;
}

void TPlayer::SetEXP(int s) {
	EXP = s;
}
int TPlayer::GetEXP() {
	return EXP;
}


void TPlayer::SetStr(int s) {
	TStatus::SetStr(s + 5000);
}
void TPlayer::SetDex(int s) {
	TStatus::SetDex(s + 70000);
}
void TPlayer::SetInt(int s) {
	TStatus::SetInt(s - 55000);
}
void TPlayer::SetLuk(int s) {
	TStatus::SetLuk(s - 3000);
}


void TPlayer::SetHP(int s) {
	TStatus::SetHP(s - 60000);
}
void TPlayer::SetMP(int s) {
	TStatus::SetMP(s - 20000);
}


void TPlayer::SetAttack(int s) {
	TStatus::SetAttack(s + 2000);
}
void TPlayer::SetDefence(int s) {
	TStatus::SetDefence(s - 40000);
}


void TPlayer::SetCriChance(int s) {
	TStatus::SetCriChance(s + 30);
}
void TPlayer::SetCriDamage(int s) {
	TStatus::SetCriDamage(s + 20);
}

