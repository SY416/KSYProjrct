#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <winsock2.h>

const short port = 10000;

int main()
{
    WSADATA wsa;
    int iRet = 0;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    SOCKADDR_IN sa;
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = htonl(INADDR_ANY);// inet_addr("192.168.0.93");
    sa.sin_port = htons(port);

    iRet = bind(sock, (SOCKADDR*)&sa, sizeof(sa));//ip와 포트번호를 통해 주소를 만듬
    if (iRet == SOCKET_ERROR) {
        int error = WSAGetLastError();
        printf("오류 발생!!! SOCKET_ERROR : %d", error);
        return 1;
    }
    iRet = listen(sock, SOMAXCONN);
    if (iRet == SOCKET_ERROR) {
        int error = WSAGetLastError();
        printf("오류 발생!!! SOCKET_ERROR : %d", error);
        return 1;
    }
    
    SOCKET clientsock;
    SOCKADDR_IN clientaddr;
    printf("서버 정상 작동 시작!!\n");

    while (1) {
        int addlen = sizeof(clientaddr);
        ZeroMemory(&clientaddr, addlen);
        clientsock = accept(sock, (SOCKADDR*)&clientaddr, &addlen);
        printf("클라이언트 접속 ip = %s, Port:%d\n", inet_ntoa(sa.sin_addr), ntohs(sa.sin_port));
        while (1) {
            char buf[256] = { 0, };
            int iRecvByte = recv(clientsock, buf, 256, 0);
            if (iRecvByte == 0) break;
            if (clientsock == SOCKET_ERROR) break;
            printf("[받음] %s\n", buf);
        }
        closesocket(clientsock);
        printf("클라이언트 접속해제 ip = %s, Port:%d\n", inet_ntoa(sa.sin_addr), ntohs(sa.sin_port));
    }
    closesocket(sock);
    WSACleanup();
    std::cout << "Hello World!\n";
}
