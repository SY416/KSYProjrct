#include "CInput.h"
#include "Std.h"

bool CInput::Init()
{
    ZeroMemory(m_dwKeyState, sizeof(DWORD) * 256);
    return true;
}

bool CInput::Frame()
{
	GetCursorPos(&m_ptMouse); // ȭ�� ��ǥ�� ���콺
	ScreenToClient(g_hWnd, &m_ptMouse);

	for (DWORD dwKey = 0; dwKey < 256; dwKey++)
	{
		SHORT sKey = ::GetAsyncKeyState(dwKey);
		if (sKey & 0x8000) // 1000 0000 0000 0000
		{
			if (m_dwKeyState[dwKey] == KEY_FREE ||
				m_dwKeyState[dwKey] == KEY_UP)
				m_dwKeyState[dwKey] = KEY_PUSH;
			else
				m_dwKeyState[dwKey] = KEY_HOLD;
		}
		else
		{
			if (m_dwKeyState[dwKey] == KEY_PUSH ||
				m_dwKeyState[dwKey] == KEY_HOLD)
				m_dwKeyState[dwKey] = KEY_UP;
			else
				m_dwKeyState[dwKey] = KEY_FREE;
		}
	}
	return true;
}

bool CInput::Render()
{
    return true;
}

bool CInput::Release()
{
    return true;
}
