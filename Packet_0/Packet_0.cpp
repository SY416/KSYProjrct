#include <iostream>
#include "Protocol.h"
#include "Packet.h"
#include <list>

std::list<UPACKET> sendPacketList;
std::list<UPACKET> recvPacketList;

int main()
{
    std::string msg = "하이요";
    std::string name = "동길홍";
    int ID = 999;

    Packet senddata;
    senddata << name << ID << "하이요";
    std::cout << "Hello World!\n";

    Packet recvdata = senddata;
    recvdata.m_pOffset = recvdata.m_uPacket.msg;
    CHAT_MSG chatmsg1;
    recvdata >> chatmsg1.szName >> chatmsg1.iID >> chatmsg1.szMsg;

    CHAT_MSG chatmsg;
    ZeroMemory(&chatmsg, sizeof(chatmsg));
    memcpy(chatmsg.szName, name.c_str(), name.size());
    chatmsg.iID = ID;
    memcpy(chatmsg.szMsg, msg.c_str(), msg.size());
}

