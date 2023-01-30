#pragma once
#include<iostream>
#include<WinSock2.h>
#pragma comment(lib, "WS2_lib")
using namespace std;
class SendMessage
{
public:
	SOCKET ServerSocket;
	SOCKADDR_IN ServerAddr;
	SendMessage();
	~SendMessage();
	
	char InputBuffer[1024] = { 0, };
	char OutputBuffer[1024] = { 0, };
	void GetSendMessage();
	void RecvMessage();
};

