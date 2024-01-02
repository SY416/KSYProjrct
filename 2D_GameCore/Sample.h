#pragma once
#include "Core.h"
#include "Player.h"
class Sample : public Core
{
public:

	Sound* m_pBKSound = nullptr;

	std::shared_ptr<Player> m_Player;

	bool	CreatePixelShader();
public:
	bool    Init()		override;
	bool    Frame()		override;
	bool    Render()	override;
	bool    Release()	override;

};