#pragma once
#include "CUIObj.h"

class Sample : public CDevice
{
	CUIObj m_bk;
	CUIObj m_ui;
	CUIObj m_ui_0;
	CUIObj m_ui_1;

	CUINumber m_number;

public:
	bool Init() override;
	bool Render() override;
	bool Release() override;
};

