#pragma once
#include <windows.h>

enum { KEY_FREE = 0, KEY_PUSH, KEY_HOLD, KEY_UP};

class CInput
{
public:
	DWORD    m_dwKeyState[256];
	static CInput& Get()
	{
		static CInput mgr;
		return mgr;
	}
public:
	bool	 Init();
	bool	 Frame();
	bool	 Render();
	bool	 Release();
private:
	CInput() {};
public:
	~CInput() {}
};

