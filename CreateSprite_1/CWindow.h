#pragma once
#include <Windows.h>
#pragma comment (lib, "winmm.lib")

extern bool g_bChange;
extern int g_iChange;

class CWindow
{
public:
	HWND		m_hWnd;
	HINSTANCE	m_hInstance;
	RECT		m_rtWindow;
	RECT		m_rtClient;
public:
	void SetWindow(HINSTANCE hInstance, int nCmdShow);
	void Run();
	void ReleaseAll();
public:
	virtual bool GameInit() { return true; };
	virtual bool GameFrame() { return true; };
	virtual bool GameRender() { return true; };
	virtual bool GameRelease() { return true; };
public:
	BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);
	ATOM MyRegisterClass(HINSTANCE hInstance);
};

