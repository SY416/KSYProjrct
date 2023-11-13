#pragma once
#include <windows.h>
#define PACKET_HEADER_SIZE 4
#pragma pack(push, 1)
typedef struct
{
	WORD  len;
	WORD  type;
}PACKET_HEADER;

typedef struct
{
	PACKET_HEADER  ph;
	char           msg[2048];
}UPACKET;

typedef struct
{
	byte   szName[13];  	
	int    iID;        
	char   szMsg[1024];   
}CHAT_MSG;
typedef struct
{
	byte   szName[13];
	int    iID;
	int    iData[10];
}ITEM_CREATE;

#pragma pack(pop)

#define PACKET_CHAT_MSG			1000
#define PACKET_GAME_START		2000
#define PACKET_GAME_END			3000
#define PACKET_CREATE_CHARACTER 4000
#define PACKET_MOVE_CHARACTER   5000