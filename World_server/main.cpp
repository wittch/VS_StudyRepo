#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<iostream>
#include<Winsock2.h>
#include<Windows.h>
#include<process.h>
#include<vector>
#include<string>
#pragma comment(lib,"WS2_32.lib")

using namespace std;
vector<SOCKET> UserList;

unsigned WINAPI ClientThread(void* Args)
{
	SOCKET ClientSocket = *(SOCKET*)Args;
	vector<SOCKET>::iterator iter;
	char Buffer[1024] = { 0, };
	string Buf = "";

	int ListSize = UserList.size();

	cout << "Client ID : " << ClientSocket << " connect.\n";
	for (int i = 0; i < ListSize; i++)
	{
		SOCKET tmp = UserList[i];
		Buf = to_string(ClientSocket);

		if (tmp != ClientSocket)
		{
			send(tmp, "CREATE", sizeof("CREATE"), 0);
			send(tmp, Buf.c_str(), sizeof(Buf), 0);
		}
	}

	while (1) {
		ListSize = UserList.size();
		int RecvBytes = recv(ClientSocket, Buffer, sizeof(Buffer), 0);

		if (RecvBytes <= 0)
		{
			iter = find(UserList.begin(), UserList.end(), ClientSocket);

			for (int i = 0; i < ListSize; i++)
			{
				SOCKET tmp = UserList[i];
				Buf = to_string(tmp);

				if (tmp != ClientSocket)
				{
					send(tmp, "DELETE", sizeof("DELETE"), 0);
					send(tmp, Buf.c_str(), sizeof(Buf), 0);
				}
			}
			UserList.erase(iter);

			cout << "Disconnected Client ID : " << Buf << '\n';
			return 1;
		}
		else
		{
			cout << Buffer << '\n';
			for (int i = 0; i < ListSize; i++)
			{
				SOCKET tmp = UserList[i];
				if (tmp != ClientSocket)
				{
					//char buf[1024] = { 0, };
					//itoa(tmp, buf, 10);
					//send(tmp, buf, sizeof(buf), 0); // send socket num
					send(tmp, Buffer,sizeof(Buffer), 0); // send message
				}
			}
		}
	}
	return 0;
}

int main()
{
	WSAData wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN ServerAddr;
	memset(&ServerAddr, 0, sizeof(SOCKADDR_IN));
	ServerAddr.sin_family = PF_INET;
	ServerAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	ServerAddr.sin_port = htons(4949);


	bind(ServerSocket, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));
	listen(ServerSocket, 0);
	while (1)
	{
		SOCKADDR_IN ClientAddr;
		memset(&ClientAddr, 0, sizeof(SOCKADDR_IN));
		int ClientAddrLength = sizeof(ClientAddr);
		SOCKET ClientSocket = accept(ServerSocket, (SOCKADDR*)&ClientAddr, &ClientAddrLength);

		UserList.push_back(ClientSocket);

		HANDLE hThread = (HANDLE)_beginthreadex(nullptr, 0, ClientThread, (void*)&ClientSocket, 0, nullptr);

	}


	return 0;
}