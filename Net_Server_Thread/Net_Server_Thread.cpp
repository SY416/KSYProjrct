#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <winsock2.h>
#include <list>

const short port = 10000;
struct Tuser
{
    SOCKET clientsock;
    SOCKADDR_IN clientaddr;
    char name[100] = { 0 };
};
std::list<Tuser> userlist;

int main()
{
    WSADATA wsa;
    int iRet = 0;
    WSAStartup(MAKEWORD(2, 2), &wsa);
    if (iRet != 0) return 1;

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

    u_long on = TRUE;//1
    ioctlsocket(sock, FIONBIO, &on);//넌블럭

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

        char name[100] = { 0, };
        int iRecvname = recv(clientsock, name, 100, 0);

        if (clientsock == SOCKET_ERROR) {
            int iError = WSAGetLastError();
            if (iError != WSAEWOULDBLOCK) {//WSAEWOULDBLOCK = 아직 연결 요청을 받지 못함
                break;
            }
        }
        else {
            Tuser user;
            user.clientsock = clientsock; 
            user.clientaddr = clientaddr;
            
            userlist.push_back(user);
            printf("[%s]님이 입장하였습니다. ip = %s, Port:%d\n", user.name, inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));

        }

        for (std::list<Tuser>::iterator iter = userlist.begin(); iter != userlist.end();) {
            SOCKET ctSock = iter->clientsock;
            char buf[256] = { 0, };
            int iRecvByte = recv(ctSock, buf, 256, 0);
            
            if (iRecvByte == SOCKET_ERROR) {
                int iError = WSAGetLastError();
                
                if (iError != WSAEWOULDBLOCK) {
                    printf("클라이언트 접속해제 ip = %s, Port:%d\n", inet_ntoa(iter->clientaddr.sin_addr), ntohs(iter->clientaddr.sin_port));
                    printf("SOCKET_ERROR : %d\n", iError);
                    iter = userlist.erase(iter);
                    continue;
                }
            }
            else {
                if (iRecvByte == 0 || iRecvByte == SOCKET_ERROR) {
                    iter = userlist.erase(iter);
                    printf("[나감]");
                    continue;
                }
                printf("[받음] %s\n", buf);
                int iLen = strlen(buf);

                for (std::list<Tuser>::iterator iterSend = userlist.begin(); iterSend != userlist.end(); iterSend++) {
                    SOCKET ctSock = iterSend->clientsock;
                    int iSendByte = send(ctSock, buf, iLen, 0);
                    if (iSendByte == SOCKET_ERROR)
                    {
                        int iError = WSAGetLastError();
                        if (iError != WSAEWOULDBLOCK)
                        {
                            printf("오류 발생!!! SOCKET_ERROR : %d", iError);
                            break;
                        }
                    }
                }
            }
            iter++;
        }
        
        //closesocket(clientsock);
        
    }
    closesocket(sock);
    WSACleanup();
}


