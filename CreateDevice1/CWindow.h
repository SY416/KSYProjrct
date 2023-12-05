#pragma once
#include <Windows.h>

class CWindow
{
public:
	HWND		m_hWnd;
	HINSTANCE	m_hInstance;
public:
	void SetWindow(HINSTANCE hInstance, int nCmdShow);
	void Run();
	void ReleaseAll();
public:
	virtual bool Init() { return true; };
	virtual bool Render() { return true; };
	virtual bool Release() { return true; };
public:
	BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);
	ATOM MyRegisterClass(HINSTANCE hInstance);
};

