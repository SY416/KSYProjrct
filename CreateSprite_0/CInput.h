#pragma once
#include <windows.h>

enum { KEY_FREE = 0, KEY_PUSH, KEY_HOLD, KEY_UP};

class CInput
{
public:
	POINT m_ptMouse;
	DWORD m_dwKeyState[256];
	static CInput& Get()
	{
		static CInput mng
	}
};

