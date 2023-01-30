#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<iostream>
#include<WinSock2.h>

#pragma comment(lib, "WS2_32.lib")



using namespace std;
int main()
{
	WSAData wsaData;
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN ListenSocketAddr;
	memset(&ListenSocketAddr, 0, sizeof(SOCKADDR_IN));
	ListenSocketAddr.sin_family = PF_INET;
	ListenSocketAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	ListenSocketAddr.sin_port = htons(4949);

	bind(ListenSocket, (SOCKADDR*)&ListenSocketAddr, sizeof(ListenSocketAddr));

	listen(ListenSocket, 5);

	fd_set Reads;  // RecvList;
	fd_set Copys;
	FD_ZERO(&Reads); // √ ±‚»≠
	FD_SET(ListenSocket, &Reads);

	TIMEVAL TimeOut;
	TimeOut.tv_sec = 10;
	TimeOut.tv_usec = 0;

	while (true)
	{
		Copys = Reads;
		int fd_num = select(0, &Copys, 0, 0, &TimeOut);
		if (fd_num == SOCKET_ERROR)
		{
			cout << "ERROR: " << GetLastError() << '\n';
			exit(-1);
		}
		else if (fd_num == 0)
		{
			cout << "TimeOut." << '\n';
		}
		else
		{
			for (int i = 0; i < (int)Reads.fd_count; i++)
			{
				if (FD_ISSET(Reads.fd_array[i], &Copys))
				{
					if (Reads.fd_array[i] == ListenSocket)
					{
						SOCKADDR_IN ClientSockAddr;
						memset(&ClientSockAddr, 0, sizeof(ClientSockAddr));
						int Clientsocketaddrlength = sizeof(ClientSockAddr);
						SOCKET ClientSocket = accept(ListenSocket, (SOCKADDR*)&ClientSockAddr, &Clientsocketaddrlength);
						FD_SET(ClientSocket, &Reads);

					}
					else
					{
						char Buffer[1024] = { 0, };
						int RecvLength = recv(Reads.fd_array[i], Buffer, sizeof(Buffer), 0);

						if (RecvLength <= 0)
						{
							SOCKET DisconnectSocket = Reads.fd_array[i];
							FD_CLR(DisconnectSocket, &Reads);
							closesocket(DisconnectSocket);
						}
						else
						{
							for (int j = 0; j < (int)Reads.fd_count; j++)
							{
								if (Reads.fd_array[j] != ListenSocket)
									send(Reads.fd_array[j], Buffer, RecvLength, 0);
								else
									cout << Buffer << '\n';
							}
						}
					}
				}
			}
		}
	}
	return 0;
}