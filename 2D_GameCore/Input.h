#pragma once
#include <windows.h>

enum { KEY_FREE = 0, KEY_PUSH, KEY_HOLD, KEY_UP };

class Input
{
public:
	POINT	m_ptMouse;
	DWORD    m_dwKeyState[256];
	static Input& Get()
	{
		static Input mgr;
		return mgr;
	}
public:
	bool	 Init();
	bool	 Frame();
	bool	 Render();
	bool	 Release();
private:
	Input() {};
public:
	~Input() {}
};

