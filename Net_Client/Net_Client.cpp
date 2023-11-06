#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <winsock2.h>

const short port = 100000;

int main()
{
    //1)윈속 초기화
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);//TCP, IP프로토콜 사용
    //==socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)
    SOCKADDR_IN sa;//16바이트
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("192.168.0.93");
    sa.sin_port = htons(port);//호스트 투 네트워크 숏, 포트번호를 호스트 바이트 순서에서 네트워크 바이트 순서로 
    int ret = connect(sock, (SOCKADDR*)&sa, sizeof(sa));//연결요청,sock:소켓 아이디, &sa: 접속하고자 하는 ip와 port정보가 있는 sockaddr구조체, sockaddr구조체의 크기 지정
    //성공시 0리턴 실패시 0보다 작은값 리턴
    if (ret == 0) {
        printf("서버 접속 ip = %s, Port: %d 했습니다.\n", inet_ntoa(sa.sin_addr), ntohs(sa.sin_port));
    }
    else {
        printf("서버 접속 ip = %s, Port: %d 불가!!!\n", inet_ntoa(sa.sin_addr), ntohs(sa.sin_port));
    }

    char buf[256] = { 0, };
    int iLen = strlen(buf);
    int iSendByte;
    while (1) {
        ZeroMemory(buf, sizeof(char) * 256);//메모리를 0으로 채움
        fgets(buf, 256, stdin);
        if (buf[0] == '\n')break;
        iLen = strlen(buf);
        iSendByte = send(sock, buf, iLen, 0);
        printf("%d 바이트를 전송했습니다", iSendByte);
    }
    closesocket(sock);
    
    //) 윈속 해제
    WSACleanup();
    std::cout << "Hello World!\n";
}


