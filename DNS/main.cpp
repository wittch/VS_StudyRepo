#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<iostream>
#include<WinSock2.h>

#pragma comment(lib, "WS2_32.lib")

using namespace std;

int main()
{
	WSAData WsaData;
	WSAStartup(MAKEWORD(2, 2), &WsaData);

	hostent* host = gethostbyname("yahoo.com");

	cout << host->h_name << '\n';

	for (int i = 0; host->h_aliases[i]; i++) 
	{
		cout << host->h_aliases << '\n';
	}

	cout << ((host->h_addrtype == AF_INET)? "AF_INET" : "AF_INET6") << '\n';
	//cout << host->h_length << '\n';
	for (int i = 0; host->h_addr_list[i]; i++)
	{
		cout << inet_ntoa(*(IN_ADDR*)host->h_addr_list[0]) << '\n';
	}

	char tmp[4] = { 0, };
	unsigned long ip = inet_addr("76.6.143.25");
	memcpy(tmp, &ip, 4);
	
	SOCKADDR_IN HostSockAddr;
	memset(&HostSockAddr, 0, sizeof(SOCKADDR_IN));
	HostSockAddr.sin_addr.S_un.S_addr = inet_addr("76.6.143.25");

	host = gethostbyaddr((char*)&HostSockAddr.sin_addr.S_un.S_addr, 4, AF_INET);

	cout << host->h_name << '\n';

	for (int i = 0; host->h_aliases[i]; i++)
	{
		cout << host->h_aliases << '\n';
	}

	cout << ((host->h_addrtype == AF_INET) ? "AF_INET" : "AF_INET6") << '\n';
	//cout << host->h_length << '\n';
	for (int i = 0; host->h_addr_list[i]; i++)
	{
		cout << inet_ntoa(*(IN_ADDR*)host->h_addr_list[0]) << '\n';
	}


	return 0;
}