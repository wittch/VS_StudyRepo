#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<WinSock2.h>
#include<mutex>
#pragma comment(lib, "WS2_lib")
using namespace std;
class Message
{
public:
	SOCKET ServerSocket;
	SOCKADDR_IN ServerAddr;
	Message();
	~Message();
	mutex m1, m2;

	char InputBuffer[1024] = { 0, };
	char OutputBuffer[1024] = { 0, };
	void GetSendMessage();
	void RecvMessage();
};

