#pragma once
#include<iostream>
#include<WinSock2.h>
#include<string>

using namespace std;

class ASocket
{
	
	ASocket(string SocketAddrIn, u_short PortNum);
	~ASocket();
};

