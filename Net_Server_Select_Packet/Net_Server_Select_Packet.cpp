#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <winsock2.h>
#include <list>
#include "Protocol.h"

const short port = 10000;
//struct Tuser
//{
//    SOCKET clientsock;
//    SOCKADDR_IN clientaddr;
//    char name[50] = { 0 };
//};
//std::list<Tuser> userlist;
std::list<UPACKET>  g_userPacketlist;
std::list<SOCKET>  g_userlist;

int SendPacket(SOCKET sock, UPACKET& packet) {
    char* sendbuffer = (char*)&packet;

    int iSendByte = 0;
    int iTotalSendByte = 0;
    do {
        iSendByte = send(sock, &sendbuffer[iTotalSendByte], packet.ph.len - iTotalSendByte, 0);
        iTotalSendByte += iSendByte;
    } while (iTotalSendByte < packet.ph.len);
    return packet.ph.len;
}
bool Broadcastting(UPACKET& packet) {
    for (std::list<SOCKET>::iterator iterSend = g_userlist.begin(); iterSend != g_userlist.end();) {
        SOCKET cSock = *iterSend;

        int iSendByte = SendPacket(cSock, packet);
        if (iSendByte == SOCKET_ERROR)
        {
            closesocket(*iterSend);
            iterSend = g_userlist.erase(iterSend);
            continue;
        }
        iterSend++;
    }
    return true;
}

int RecvPacket(SOCKET sock) {
    char buffer[256] = { 0, };
    int iRecvByte = 0;
    int iRet = 0;

    while (1) {
        iRet = recv(sock, &buffer[iRecvByte], PACKET_HEADER_SIZE - iRecvByte, 0);
        if (iRet == 0)break;
        if (iRet == SOCKET_ERROR)break;
        iRecvByte += iRet;
        if (iRet != PACKET_HEADER_SIZE)continue;

        if (iRet == PACKET_HEADER_SIZE) {
            UPACKET packet;
            ZeroMemory(&packet, sizeof(packet));
            memcpy(&packet.ph, buffer, PACKET_HEADER_SIZE);

            int iMsgByte = 0;

            do {
                iRet = recv(sock, &packet.msg[iMsgByte], packet.ph.len - PACKET_HEADER_SIZE, 0);
                if (iRet == 0)break;
                if (iRet == SOCKET_ERROR)break;
                iMsgByte += iRet;
            } while (packet.ph.len - PACKET_HEADER_SIZE > iMsgByte);

            if (iRet != SOCKET_ERROR) {
                switch (packet.ph.type) {
                case PACKET_CHAT_MSG: {
                    Broadcastting(packet);
                }break;
                }
            }
            break;
        }
    }
    return iRet;
}

int main()
{
    WSADATA wsa;
    int iRet = 0;
    WSAStartup(MAKEWORD(2, 2), &wsa);
    if (iRet != 0) return 1;

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

    int SendbufSize = 0;
    int iLen = sizeof(SendbufSize);
    getsockopt(sock, SOL_SOCKET, SO_SNDBUF, (char*)&SendbufSize, &iLen);

    int RecvbufSize = 0;
    int iRecvLen = sizeof(RecvbufSize);
    getsockopt(sock, SOL_SOCKET, SO_RCVBUF, (char*)&RecvbufSize, &iRecvLen);

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

        for (std::list<SOCKET>::iterator iter = g_userlist.begin(); iter != g_userlist.end(); iter++) {
            FD_SET(*iter, &readSet);
            FD_SET(*iter, &sendSet);
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
                g_userlist.push_back(clientsock);
                printf("ip = %s, Port:%d\n", inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));

            }
        }
        char nickname[50] = { 0, };

        for (std::list<SOCKET>::iterator iter = g_userlist.begin(); iter != g_userlist.end();) {

            if (FD_ISSET(*iter, &readSet)) {
                SOCKET ctSock = *iter;
                char buf[256] = { 0, };
                int iRecvByte = recv(ctSock, buf, 256, 0);

                if (iRecvByte == SOCKET_ERROR) {
                    printf("클라이언트 접속해제 SOCKET = %d\n", *iter);
                    closesocket(*iter);
                    iter = g_userlist.erase(iter);
                    continue;
                }
                else {
                    if (iRecvByte == 0 || iRecvByte == SOCKET_ERROR) {
                        closesocket(*iter);
                        iter = g_userlist.erase(iter);
                        printf("클라이언트 접속해제 SOCKET = %d\n", *iter);
                        continue;
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