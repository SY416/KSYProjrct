#include "Timer.h"

float g_fSecPerFrame = 0.0f;
float g_fTimer = 0.0f;

bool  Timer::Init()
{
	m_dwTickStart = timeGetTime();
	return true;
}
bool  Timer::Frame()
{
	m_dwTickEnd = timeGetTime();
	DWORD dwElapseTick = m_dwTickEnd - m_dwTickStart;

	g_fSecPerFrame = m_fSecondPerFrame = dwElapseTick / 1000.0f;
	m_fGameTimer += m_fSecondPerFrame;
	g_fTimer += m_fSecondPerFrame;

	m_iFPS++;
	m_dwTime += dwElapseTick;
	if (m_dwTime >= 1000)
	{
		m_msg = std::to_wstring(m_iFPS);
		m_msg += L" FPS\n";
		m_dwTime -= 1000;
		m_iFPS = 0;
	}

	m_dwTickStart = m_dwTickEnd;
	return true;
}
bool  Timer::Render()
{
	m_outmsg.clear();
	if (int(g_fTimer) / 60 < 10) {
		m_outmsg += L"0";
		m_outmsg += std::to_wstring(int(g_fTimer) / 60);
		m_outmsg += L" 분 ";
	}
	else
	{
		m_outmsg += std::to_wstring(int(g_fTimer) / 60);
		m_outmsg += L" 분 ";
	}

	if (int(g_fTimer) % 60 < 10) {
		m_outmsg += L"0";
		m_outmsg += std::to_wstring(int(g_fTimer) % 60);
		m_outmsg += L" 초 ";
	}
	else
	{
		m_outmsg += std::to_wstring(int(g_fTimer) % 60);
		m_outmsg += L" 초 ";
	}

	if (int(g_fTimer * 100) % 100 < 10) {
		m_outmsg += L"0";
		m_outmsg += std::to_wstring(int(g_fTimer * 100) % 100);
		m_outmsg += L"";
	}
	else
	{
		m_outmsg += std::to_wstring(int(g_fTimer * 100) % 100);
		m_outmsg += L"";
	}
	
	
	return true;
}
bool  Timer::Release()
{
	return true;
}
