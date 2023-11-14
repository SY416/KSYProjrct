#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <winsock2.h>
#include <windows.h>
#include <iostream>
#include <thread>

#define NETWORK_MSG (WM_USER+1)

const short port = 10000;

extern SOCKET sock;//extern = 외부에 있는 변수 사용
extern HWND g_hWnd;

static int mainNet()
{
    /*char nickname[50];
    int inameLen = strlen(nickname);
    printf("닉네임 입력: ");
    fgets(nickname, 50, stdin);*/

    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    WSAAsyncSelect(sock, g_hWnd, NETWORK_MSG,
        FD_READ | FD_WRITE | FD_CLOSE | FD_CONNECT);

    SOCKADDR_IN sa;
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("192.168.0.93");
    sa.sin_port = htons(port);

    int ret = connect(sock, (SOCKADDR*)&sa, sizeof(sa));
    if (ret == 0) {
        printf("서버 접속 ip = %s, Port: %d 했습니다.\n", inet_ntoa(sa.sin_addr), ntohs(sa.sin_port));
    }
    else {
        printf("서버 접속 ip = %s, Port: %d 불가!!!\n", inet_ntoa(sa.sin_addr), ntohs(sa.sin_port));
    }

    u_long on = TRUE;
    ioctlsocket(sock, FIONBIO, &on);

    return 1;
}