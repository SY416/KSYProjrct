#include "CTimer.h"

bool CTimer::Init()
{
    m_dwTickStart = timeGetTime();// 1/1000�� ������ ���� DWORD��, 1�ʰ� ������ 1000����
    return true;
}

bool CTimer::Frame()
{
    m_dwTickEnd = timeGetTime();
    DWORD dwElapseTick = m_dwTickEnd - m_dwTickStart;// ��� �ð�

    m_fFramePerFrame = dwElapseTick / 1000.0f;
    m_fGameTimer += m_fFramePerFrame;

    m_iFPS++;
    m_dwTime += dwElapseTick;
    if (m_dwTime >= 1000)
    {
        m_msg = std::to_wstring(m_iFPS);
        m_msg += L"FPS\n";
        m_dwTime -= 1000;
        m_iFPS = 0;
    }
    m_dwTickStart = m_dwTickEnd;
    return true;
}

bool CTimer::Render()
{
    std::wstring outmsg = L"���� ��� �ð�: ";
    outmsg += std::to_wstring(m_fGameTimer);
    outmsg += L" ";
    outmsg += L" 1 ������ ��� �ð�: ";
    outmsg += std::to_wstring(m_fSecondPerFrame);
    outmsg += L" ";
    outmsg += L"�ʴ� ������: ";
    outmsg += m_msg;
    outmsg += L"\n";

    OutputDebugString(outmsg.c_str());
    return true;
}

bool CTimer::Release()
{
    return true;
}
