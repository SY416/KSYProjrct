﻿#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <winsock2.h>
#include <windows.h>
#include <iostream>
#include <thread>


const short port = 10000;

extern SOCKET sock;//extern = 외부에 있는 변수 사용

static void recvWork() {
    char recvbuf[256] = { 0, };
    int iRecvByte = recv(sock, recvbuf, 256, 0);
    if (iRecvByte == SOCKET_ERROR) {
        int iError = WSAGetLastError();
        if (iError != WSAEWOULDBLOCK) {
            closesocket(sock);
        }
    }
    else {
        printf("[받음]%s\n", recvbuf);
        OutputDebugStringA(recvbuf);//디버그시 인자값 출력
    }

}
static void sendWork() {
    while (1) {
        char buf[256] = { 0, };
        int iLen = strlen(buf);
        int iSendByte;

        ZeroMemory(buf, sizeof(char) * 256);
        fgets(buf, 256, stdin);

        if (buf[0] == '\n')break;
        iLen = strlen(buf);
        iSendByte = send(sock, buf, iLen, 0);
        if (iSendByte == SOCKET_ERROR) break;
        printf("%d 바이트를 전송했습니다", iSendByte);
    }
}

static int mainNet()
{
    /*char nickname[50];
    int inameLen = strlen(nickname);
    printf("닉네임 입력: ");
    fgets(nickname, 50, stdin);*/

    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    sock = socket(AF_INET, SOCK_STREAM, 0);
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

    std::thread sendthread(sendWork);
    sendthread.detach();

    return 1;