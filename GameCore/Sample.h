#include "Core.h"

class Sample : public Core
{
public:
	std::vector<std::shared_ptr<UIobj>> m_uiList;
	std::shared_ptr<UIobj> m_bk;

public:
	bool    Init()		override;
	//bool    Frame()		override;
	bool    Render()	override;
	bool    Release()	override;
};