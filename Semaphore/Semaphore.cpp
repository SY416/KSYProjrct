#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
HWND hWndMain;
LPCTSTR lpszClass = TEXT("Semaphore");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow) {
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

HANDLE hSmp;
int Y = 0;

DWORD WINAPI ThreadDownload(LPVOID temp) {
	TCHAR str[256];
	HDC hdc;
	hdc = GetDC(hWndMain);

	int i, j, y, s;

	srand(GetTickCount());//난수생성
	s = rand() % 5 + 1;//1~5 난수

	Y += 30;
	y = Y;
	
	TextOut(hdc, 10, y, L"대기중", 6);
	GdiFlush();
	WaitForSingleObject(hSmp, INFINITE);

	for (i = 0; i < 100; i++) {
		wsprintf(str, L"다운중............   %d%%  ", i);
		for (j = 0; j < i; j++)
			lstrcat(str, L"|");
		TextOut(hdc, 10, y, str, lstrlen(str));//hdc, x, y, 출력할 문자열, 문자열 크기
		Sleep(20 * s);
	}
	lstrcpy(str, L"다운로드 완료");
	TextOut(hdc, 10, y, str, lstrlen(str));
	ReleaseSemaphore(hSmp, 1, NULL);
	ReleaseDC(hWndMain, hdc);
	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) {
	HDC hdc;
	PAINTSTRUCT ps;
	DWORD ThreadID;
	HANDLE hThread;
	const TCHAR* Mes = L"마우스 좌클릭시 다운로드 시작";

	switch (iMessage) {
	case WM_CREATE:
		hWndMain = hWnd;
		hSmp = CreateSemaphore(NULL, 3, 3, NULL);//NULL, 임계영역의 수, 임계영역 접근 수, NULL
		return 0;

	case WM_LBUTTONDOWN:
		hThread = CreateThread(NULL, 0, ThreadDownload, NULL, 0, &ThreadID);
		CloseHandle(hThread);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		TextOut(hdc, 10, 10, Mes, lstrlen(Mes));
		EndPaint(hWnd, &ps);
		return 0;

	case WM_DESTROY:
		CloseHandle(hSmp);
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}