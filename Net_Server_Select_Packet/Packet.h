#pragma once
#include "Protocol.h"
#include <string>
class Packet
{
public:
	UPACKET   m_uPacket;
	char* m_pOffset = nullptr;
public:
	void Put(const char* pData, int iSize);
	void Get(const char* pData, int iSize);

	Packet& operator << (int data);
	Packet& operator << (byte data);
	Packet& operator << (short data);
	Packet& operator << (long data);
	Packet& operator << (DWORD data);
	Packet& operator << (WORD data);
	Packet& operator << (const char* data);
	Packet& operator << (std::string data);

	Packet& operator >> (int& data);
	Packet& operator >> (byte& data);
	Packet& operator >> (short& data);
	Packet& operator >> (long& data);
	Packet& operator >> (DWORD& data);
	Packet& operator >> (WORD& data);
	Packet& operator >> (const char* data);
	Packet& operator >> (std::string& data);

	Packet();
};

