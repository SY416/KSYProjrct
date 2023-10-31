#include "Player.h"
Player::~Player() {
	std::cout << "Player ÇØÁ¦ÀÚ" << std::endl;
}

void Player::SetEXP(int s) {
	EXP = s;
}
int Player::GetEXP() {
	return EXP;
}


void Player::SetStr(int s) {
	Status::SetStr(s + 5000);
}
void Player::SetDex(int s) {
	Status::SetDex(s + 70000);
}
void Player::SetInt(int s) {
	Status::SetInt(s - 55000);
}
void Player::SetLuk(int s) {
	Status::SetLuk(s - 3000);
}


void Player::SetHP(int s) {
	Status::SetHP(s - 60000);
}
void Player::SetMP(int s) {
	Status::SetMP(s - 20000);
}


void Player::SetAttack(int s) {
	Status::SetAttack(s + 2000);
}
void Player::SetDefence(int s) {
	Status::SetDefence(s - 40000);
}


void Player::SetCriChance(int s) {
	Status::SetCriChance(s + 30);
}
void Player::SetCriDamage(int s) {
	Status::SetCriDamage(s + 20);
}

