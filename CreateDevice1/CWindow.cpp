#include "CWindow.h"

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
    HWND hWnd = CreateWindowW(L"KSY_WINDOWS",
        L"â", WS_OVERLAPPEDWINDOW,
        0, 0, 800, 600, nullptr, nullptr,
        hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }
    m_hWnd = hWnd;
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
    Init();
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
                Render();
            }
        }
    }
    Release();
}

void CWindow::ReleaseAll ()
{
}
