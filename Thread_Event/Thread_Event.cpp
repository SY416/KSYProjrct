#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
HWND hWndMain;
LPCTSTR lpszClass = TEXT("Event");
HANDLE g_hMutex;
static int Y = 0;

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

HANDLE hEvent;

DWORD WINAPI ThreadDownload(LPVOID temp) {
	TCHAR str[256];
	HDC hdc = GetDC(hWndMain);//hWndMain윈도우의 DC를 만들어 hdv에 대입하고 이를이용해 해당윈도우에 그리기
	
	int i, j;
	int* iY = (int*)temp;//30
	int iYValue = *iY;
	
	for (i = 0; i < 100; i++) {
		wsprintf(str, L"다운중....... %d%%", i);
		for (j = 0; j < i; j++)
			lstrcat(str, L"|");
		TextOut(hdc, 10, 100 + (iYValue), str, lstrlen(str));//hdc, x, y, 출력할 문자열, 문자열 크기
		Sleep(100);
		INT iRet = WaitForSingleObject(hEvent, 0);//신호가 올때까지 대기
		if (iRet == WAIT_TIMEOUT) {//대기시간 초과시
			if (MessageBox(hWndMain, L"다운로드를 종료하시겠습니까?", L"알림", MB_YESNO) == IDYES) {
				lstrcpy(str, L"사용자의 요청에 따라 다운로드가 취소되었습니다");
				TextOut(hdc, 10, 100, str, lstrlen(str));
				ReleaseDC(hWndMain, hdc);
				return 0;
			}
			else {
				SetEvent(hEvent);
			}
		}	
	}
	lstrcpy(str, L"다운로드 완료");
	TextOut(hdc, 10, 100, str, lstrlen(str));
	ReleaseDC(hWndMain, hdc);
	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) {
	HDC hdc;
	PAINTSTRUCT ps;
	DWORD ThreadID;
	const TCHAR* Mes = L"마우스 좌클릭시 다운로드 시작, 우클릭시 다운로드 중지";

	switch (iMessage) {
	case WM_CREATE:
		hWndMain = hWnd;
		hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);//NULL, TRUE시 이벤트를 리셋시켜야 함, TRUE시 signal 상태, NULL
		return 0;

	case WM_LBUTTONDOWN:
		SetEvent(hEvent);

		Y += 30;

		CloseHandle(CreateThread(NULL, 0, ThreadDownload, &Y, 0, &ThreadID));
		//상속여부, 스택의 초기 크기(바이트) 0이면 스레드는 실행 파일의 기본크기 사용, 스레드에서 사용할 정의 함수, 스레드에 전달할 변수에 대한 포인터, 스레드 만들기를 제어하는 포인터
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;

	case WM_RBUTTONDOWN:
		ResetEvent(hEvent);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		TextOut(hdc, 10, 10, Mes, lstrlen(Mes));
		EndPaint(hWnd, &ps);
		return 0;

	case WM_DESTROY:
		CloseHandle(hEvent);
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

