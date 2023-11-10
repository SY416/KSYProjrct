#pragma once
#include "Net_Client_AsyncSelect1.cpp"

SOCKET sock;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_SIZE: {
		UINT width = LOWORD(lParam);
		UINT height = HIWORD(lParam);
		int k = 0;
	}break;
	case WM_CREATE: break;
	case WM_DESTROY: {
		PostQuitMessage(0);
		break;
	}
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);
ATOM MyRegisterClass(HINSTANCE hInstance);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow) {
	if (AllocConsole() == TRUE) {
		FILE* console = nullptr;
		if (freopen_s(&console, "conin$", "rt", stdin)){
			return 0;
		}
		if (freopen_s(&console, "conin$", "wt", stdout)){
			return 0;
		}
		if (freopen_s(&console, "conin$", "wt", stderr)){
			return 0;
		}
	}
	MyRegisterClass(hInstance);
	InitInstance(hInstance, nCmdShow);
	mainNet();

	MSG msg;//맛소금

	while (1) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			if (msg.message == WM_QUIT) break;
		}
		else recvWork();
	}
	closesocket(sock);
	WSACleanup();

	return (int)msg.wParam;
}
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) {
	HWND hWnd = CreateWindowW(L"채팅창", L"채팅 서버", WS_OVERLAPPEDWINDOW, 0, 0, 800, 600, nullptr, nullptr, hInstance, nullptr);
	if (!hWnd) return FALSE;

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
}
ATOM MyRegisterClass(HINSTANCE hInstance) {
	WNDCLASSEXW wcex;
	ZeroMemory(&wcex, sizeof(wcex));

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.hInstance = hInstance;
	wcex.lpszClassName = L"채팅 윈도우";
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	return RegisterClassExW(&wcex);
}

