#include "Window.h"

HWND g_hWnd;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// 윈도우 메세지는 WM_로 시작
	switch (message)
	{
	case WM_SIZE:// 윈도우의 크기가 변화하면 발생하는 메세지
	{
		UINT width = LOWORD(lParam);
		UINT height = HIWORD(lParam);
		int k = 0;
	}break;
	case WM_CREATE: break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

BOOL Window::InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd = CreateWindowW(L"2D 게임 만들기",
		L"인내의 숲", WS_OVERLAPPEDWINDOW,
		0, 0, 1366, 768, nullptr, nullptr,
		hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}
	m_hWnd = hWnd;
	g_hWnd = hWnd;

	::GetWindowRect(m_hWnd, &m_rtWindow);
	::GetClientRect(m_hWnd, &m_rtClient);

	ShowWindow(hWnd, nCmdShow);//윈도우의 표시 상태 설정
	UpdateWindow(hWnd);

	return 0;
}

ATOM Window::MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;
	ZeroMemory(&wcex, sizeof(wcex));

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.hInstance = hInstance;
	wcex.lpszClassName = L"2D 게임 만들기";
	//wcex.hCursor = LoadCursor(NULL, IDC_CROSS);
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	return RegisterClassExW(&wcex);
}

void Window::SetWindow(HINSTANCE hInstance, int nCmdShow)
{
	m_hInstance = hInstance;
	MyRegisterClass(m_hInstance);
	InitInstance(hInstance, nCmdShow);
}

void Window::Run()
{
	GameInit();
	MSG msg;
	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			if (msg.message == WM_QUIT)
			{
				break;
			}
			else
			{
				GameRender();
			}
		}
	}
	GameRelease();
}

void Window::ReleaseAll()
{
}




