#pragma once
#include "Core.h"
#include "Player.h"
class Sample : public Core
{
public:

	Sound* m_pBKSound = nullptr;

	std::shared_ptr<Player> m_Player;

	std::shared_ptr<Block> m_Goal;

	std::shared_ptr<Block> m_TimeBox;

	std::vector<std::shared_ptr<Block>> m_BlockList;

	std::shared_ptr<Block> m_block1;
	std::shared_ptr<Block> m_block2;
	std::shared_ptr<Block> m_block3;
	std::shared_ptr<Block> m_block4;

	std::vector<std::shared_ptr<Block>> m_TrapList;

	std::shared_ptr<Block> m_trap1;
	std::shared_ptr<Block> m_trap2;
	std::shared_ptr<Block> m_trap3;
	std::shared_ptr<Block> m_trap4;
	
	bool	m_jump = false;

	bool	CreatePixelShader();
public:
	bool    Init()		override;
	bool    Frame()		override;
	bool    Render()	override;
	bool    Release()	override;

};