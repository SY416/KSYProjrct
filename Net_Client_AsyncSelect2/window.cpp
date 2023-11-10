#pragma once
#include "Net_Client_AsyncSelect2.cpp"
#include <list>

SOCKET sock;
HWND g_hWnd;
bool g_bConnect = false;
HWND g_hEdit;
HWND g_hButton;
HWND g_hList;

std::list<std::string>g_szMsgList;
static int recvWork() {
	char recvbuf[256] = { 0, };
	int iRecvByte = recv(sock, recvbuf, 256, 0);
	if (iRecvByte == SOCKET_ERROR) {
		int iError = WSAGetLastError();
		if (iError != WSAEWOULDBLOCK) {
			return -1;
		}
		else return 0;
	}
	else {
		printf("[받음]%s\n", recvbuf);
		OutputDebugStringA(recvbuf);//디버그시 인자값 출력
		g_szMsgList.push_back(recvbuf);
		if (g_szMsgList.size() > 20)
			g_szMsgList.pop_front();
		SendMessageA(g_hList, LB_RESETCONTENT, 0, 0);
		for (auto msg : g_szMsgList)
			SendMessageA(g_hList, LB_RESETCONTENT, 0, (LPARAM)msg.c_str());
	}
	return 1;
}
static int sendWork(const char* buf, int iLen) {
	char buf[256] = { 0, };
	int iLen = strlen(buf);
	int iSendByte;
	if (iSendByte == SOCKET_ERROR) {
		int iError = WSAGetLastError();
		if (iError != WSAEWOULDBLOCK) {
			return -1;
		}
		else return 0;
	}
	printf("%d 바이트를 전송했습니다", iSendByte);
	return iLen;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_COMMAND: {
		switch (LOWORD(wParam)) {
		case 200: {
			char buffer[MAX_PATH] = { 0, };
			SendMessageA(g_hEdit, WM_GETTEXT, MAX_PATH, (LPARAM)buffer);
			sendWork(buffer, strlen(buffer));
		}break;
		}
	}break;
	case NETWORK_MSG: {
		if (WSAGETSELECTERROR(lPARAM) != 0) PostQuitMessage(0);

		WORD dwSelect = WSAGETSELECTEVENT(lParam);
		switch (dwSelect) {
		case FD_CONNECT: {
			g_bConnect = true;
		}break;
		case FD_CLOSE: {
			int iRet = recvWork();
			if (iRet == -1) {
				g_bConnect = false;
				closesocket(sock);
			}
			if (iRet == 0) {
				PostMessage(g_hWnd, NETWORK_MSG, sock, FD_READ);
			}
		};
		case FD_WRITE: {

		}break;
		}

	}break;

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
		if (freopen_s(&console, "conin$", "rt", stdin)) {
			return 0;
		}
		if (freopen_s(&console, "conin$", "wt", stdout)) {
			return 0;
		}
		if (freopen_s(&console, "conin$", "wt", stderr)) {
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

