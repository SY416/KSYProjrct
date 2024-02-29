#pragma once
#include "Core.h"
#include "Player.h"
#include "Monster.h"
#include "Message.h"
#include "MovingBlock.h"
class Sample : public Core
{
public:

	Sound* m_pBKSound = nullptr;
	Sound* m_jumpSound = nullptr;

	std::shared_ptr<Player> m_Player;

	std::shared_ptr<Block> m_Goal;
	std::shared_ptr<Block> m_BiSangGu;

	std::shared_ptr<Block> m_TimeBox;

	std::shared_ptr<Block> m_NPC;
	std::shared_ptr<Block> m_PE;

	std::vector<std::shared_ptr<Block>> m_BlockList;

	std::shared_ptr<Block> m_block1;
	std::shared_ptr<Block> m_block2;
	std::shared_ptr<Block> m_block3;
	std::shared_ptr<Block> m_block4;
	std::shared_ptr<Block> m_block5;
	std::shared_ptr<Block> m_block6;
	std::shared_ptr<Block> m_block7;
	std::shared_ptr<Block> m_block8;
	std::shared_ptr<Block> m_block9;
	std::shared_ptr<Block> m_block10;
	std::shared_ptr<Block> m_block11;
	std::shared_ptr<Block> m_block12;
	std::shared_ptr<Block> m_block13;
	std::shared_ptr<Block> m_block14;
	std::shared_ptr<Block> m_block15;

	std::vector<std::shared_ptr<Block>> m_TrapList;

	std::shared_ptr<Block> m_trap1;
	std::shared_ptr<Block> m_trap2;
	std::shared_ptr<Block> m_trap3;
	std::shared_ptr<Block> m_trap4;

	std::shared_ptr<Monster> m_monster1;

	std::shared_ptr<Message> m_message;

	std::shared_ptr<MovingBlock> m_MB;
	std::shared_ptr<MovingBlock> m_MT;
	
	bool	m_jump = false;
	float	m_jumptime = 0;

	bool	CreatePixelShader();

	bool	ThreadNPC();
public:
	bool    Init()		override;
	bool    Frame()		override;
	bool    Render()	override;
	bool    Release()	override;
};