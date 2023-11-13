#include "Packet.h"

Packet::Packet() {
	ZeroMemory(&m_uPacket, sizeof(UPACKET));
	m_pOffset = m_uPacket.msg;
}

void Packet::Put(const char* pData, int iSize) {
	m_uPacket.ph.len += iSize;
	memcpy(m_pOffset, pData, iSize);
	m_pOffset += iSize;
}
void Packet::Get(const char* pData, int iSize) {
	memcpy(const_cast<char*>(pData), m_pOffset, iSize);
	m_pOffset += iSize;
}

Packet& Packet::operator << (int data) {
	Put((char*)&data, sizeof(int));
	return *this;
}
Packet& Packet::operator << (byte data) {
	Put((char*)&data, sizeof(byte));
	return *this;
}
Packet& Packet::operator << (short data) {
	Put((char*)&data, sizeof(short));
	return *this;
}
Packet& Packet::operator << (long data) {
	Put((char*)&data, sizeof(long));
	return *this;
}
Packet& Packet::operator << (DWORD data) {
	Put((char*)&data, sizeof(DWORD));
	return *this;
}
Packet& Packet::operator << (WORD data) {
	Put((char*)&data, sizeof(WORD));
	return *this;
}
Packet& Packet::operator << (const char* data) {
	int iSize = strlen(data) + 1;
	Put(data, iSize);
	return *this;
}
Packet& Packet::operator << (std::string data) {
	Put(data.c_str(), data.size() + 1);
	return *this;
}



Packet& Packet::operator >> (int& data) {
	Get((char*)&data, sizeof(int));
	return *this;
}
Packet& Packet::operator >> (byte& data) {
	Get((char*)&data, sizeof(byte));
	return *this;
}
Packet& Packet::operator >> (short& data) {
	Get((char*)&data, sizeof(short));
	return *this;
}
Packet& Packet::operator >> (long& data) {
	Get((char*)&data, sizeof(long));
	return *this;
}
Packet& Packet::operator >> (DWORD& data) {
	Get((char*)&data, sizeof(DWORD));
	return *this;
}
Packet& Packet::operator >> (WORD& data) {
	Get((char*)&data, sizeof(WORD));
	return *this;
}
Packet& Packet::operator >> (const char* data) {
	int iSize = strlen(m_pOffset) + 1;
	Get(data, iSize);
	return *this;
}
Packet& Packet::operator >> (std::string& data) {
	int iSize = strlen(m_pOffset) + 1;
	data.resize(iSize);
	Get(data.c_str(), iSize);
	return *this;
}