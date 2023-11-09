#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <winsock2.h>
#include <list>

const short port = 10000;
struct Tuser
{
    SOCKET clientsock;
    SOCKADDR_IN clientaddr;
    char name[50] = { 0 };
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

    FD_SET readSet;
    FD_SET sendSet;
    FD_SET exeptSet;
    timeval timeout;
    timeout.tv_sec = 1.0f;//초
    timeout.tv_usec = 0;//마이크로 초


    while (1) {
        FD_ZERO(&readSet);//변수의 모든 비트값을 0으로 만들어줌
        FD_ZERO(&sendSet);
        FD_ZERO(&exeptSet);
        FD_SET(sock, &readSet);//소켓에 해당하는 비트 값을 1로 변경

        for (std::list<Tuser>::iterator iter = userlist.begin(); iter != userlist.end(); iter++) {
            FD_SET(iter->clientsock, &readSet);
            FD_SET(iter->clientsock, &sendSet);
        }
        iRet = select(0, &readSet, &sendSet, NULL, &timeout);
        if (iRet == SOCKET_ERROR) break;
        if (iRet == 0) continue;

        if (FD_ISSET(sock, &readSet)) {//소켓에 해당하는 비트의 값이 SET되어 있으면 양수값 리턴->소켓이 있으면 accept
            int addlen = sizeof(clientaddr);
            ZeroMemory(&clientaddr, addlen);
            
            clientsock = accept(sock, (SOCKADDR*)&clientaddr, &addlen);
            if (clientsock == SOCKET_ERROR) {
                int iError = WSAGetLastError();
                if (iError != WSAEWOULDBLOCK) {
                    break;
                }
            }
            else {
                Tuser user;
                user.clientsock = clientsock;
                user.clientaddr = clientaddr;

                userlist.push_back(user);
                printf("ip = %s, Port:%d\n", inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));

            }
        }
        char nickname[50] = { 0, };

        for (std::list<Tuser>::iterator iter = userlist.begin(); iter != userlist.end();) {

            if (FD_ISSET(iter->clientsock, &readSet)) {
                SOCKET ctSock = iter->clientsock;
                char buf[256] = { 0, };
                int iRecvByte = recv(ctSock, buf, 256, 0);

                if (iRecvByte == SOCKET_ERROR) {
                    printf("클라이언트 접속해제 ip = %s, Port:%d\n", inet_ntoa(iter->clientaddr.sin_addr), ntohs(iter->clientaddr.sin_port));
                    closesocket(iter->clientsock);
                    iter = userlist.erase(iter);
                    continue;  
                }
                else {
                    if (iRecvByte == 0 || iRecvByte == SOCKET_ERROR) {
                        closesocket(iter->clientsock);
                        iter = userlist.erase(iter);
                        printf("[나감]");
                        continue;
                    }
                    printf("[받음] %s\n", buf);
                    int iLen = strlen(buf);

                    for (std::list<Tuser>::iterator iterSend = userlist.begin(); iterSend != userlist.end();) {
                        SOCKET ctSock = iterSend->clientsock;
                        int iSendByte = send(ctSock, buf, iLen, 0);
                        if (iSendByte == SOCKET_ERROR)
                        {
                            closesocket(iterSend->clientsock);
                            iterSend = userlist.erase(iterSend);
                            continue;
                        }
                        iterSend++;
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
