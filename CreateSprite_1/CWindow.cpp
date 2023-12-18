#include "CWindow.h"

HWND g_hWnd;

bool g_bChange = true;
int g_iChange = 0;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_SIZE:
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

BOOL CWindow::InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    DWORD dwWindowsStyle = WS_OVERLAPPEDWINDOW;
    RECT rt = { 0, 0, 800, 600 };

    AdjustWindowRect(&rt, dwWindowsStyle, FALSE);

    HWND hWnd = CreateWindowW(L"KSY_WINDOWS",
        L"abcd", dwWindowsStyle,
        100, 100, rt.right - rt.left, rt.bottom - rt.top, nullptr, nullptr,
        hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }
    g_hWnd = hWnd;
    m_hWnd = hWnd;

    
    ::GetWindowRect(m_hWnd, &m_rtWindow);
    ::GetClientRect(m_hWnd, &m_rtClient);


    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}
ATOM CWindow::MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;
    ZeroMemory(&wcex, sizeof(wcex));

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.hInstance = hInstance;
    wcex.lpszClassName = L"KSY_WINDOWS";
    //wcex.hCursor = LoadCursor(NULL, IDC_CROSS);
    wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    return RegisterClassExW(&wcex);
}
void CWindow::SetWindow(HINSTANCE hInstance, int nCmdShow)
{
    m_hInstance = hInstance;
    MyRegisterClass(m_hInstance);
    InitInstance(hInstance, nCmdShow);
}

void CWindow::Run()
{
    GameInit();

    DWORD dwElapseTime = 0;
    DWORD dwFrame100 = 1000 / 100;
    DWORD dwTickStart = timeGetTime();

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
                DWORD dwTickEnd = timeGetTime();
                dwElapseTime += dwTickEnd - dwTickStart;

                if (dwElapseTime >= dwFrame100)
                {
                    GameFrame();
                    GameRender();
                    dwElapseTime -= dwFrame100;
                }
                dwTickStart = dwTickEnd;
            }
        }
    }
    GameRelease();
}

void CWindow::ReleaseAll()
{
}
