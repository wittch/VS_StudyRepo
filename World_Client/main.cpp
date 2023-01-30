#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<iostream>
#include<Winsock2.h>
#include<Windows.h>
#include<process.h>
#include<vector>
#include<string>
#include<conio.h>
#pragma comment(lib,"WS2_32.lib")


#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

using namespace std;
vector<SOCKET> UserList;
CRITICAL_SECTION CS;
int WorldMap[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,2,2,2,2,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};
pair<int, int> playerpos = { 1,1 };
unsigned WINAPI WorkThread(void* Args)
{
	InitializeCriticalSection(&CS);
	char Buffer[1024] = { 0, };
	SOCKET ClientSocket = *(SOCKET*)Args;
	vector<SOCKET>::iterator iter;
	string Buf;
	

	while (1)
	{
		int RecvBytes = recv(ClientSocket, Buffer, sizeof(Buffer), 0);
		if (RecvBytes <= 0)
		{
			cout << "Disconnected Server.\n";
			break;
		}
		else if (Buffer == "DELETE")
		{
			EnterCriticalSection(&CS);
			recv(ClientSocket, Buffer, sizeof(Buffer), 0);
			SOCKET deletesocket = stoi(Buffer);
			iter = find(UserList.begin(), UserList.end(), deletesocket);
			cout << "Delete Client ID : " << *iter << ".\n";
			UserList.erase(iter);
			LeaveCriticalSection(&CS);
		}
		else if (Buffer == "CREATE")
		{
			EnterCriticalSection(&CS);
			recv(ClientSocket, Buffer, sizeof(Buffer), 0);
			SOCKET createsocket = stoi(Buffer);
			UserList.push_back(createsocket);
			cout << "Create Client ID : " << createsocket << ".\n";
			LeaveCriticalSection(&CS);
		}
		else
		{
			EnterCriticalSection(&CS);
			cout << "Others : " << Buffer << '\n';
			LeaveCriticalSection(&CS);
			
		}
	}
	DeleteCriticalSection(&CS);
	return 0;
}
unsigned WINAPI InputThread(void* Args)
{
	SOCKET ServerSocket = *(SOCKET*)Args;
	//char Buffer[1024] = { 0, };
	char c;
	
	while (1)
	{
		//cin >> Buffer;

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if(playerpos.first == j && playerpos.second == i)
					cout << "@";
				if (WorldMap[i][j] == 1)
					cout << "*";
				else if (WorldMap[i][j] == 2)
					cout << "M";
				else
					cout << " ";
			}
			cout << '\n';
		}
		if (_kbhit())
		{
			c = _getch();
			if (c == -32)
			{
				c = _getch();
				char* buf;
				buf = &c;
				send(ServerSocket, buf, sizeof(buf), 0);
				switch (c)
				{
					case LEFT :
						if (playerpos.first - 1 >= 0)
							playerpos.first--;
						break;
					case RIGHT :
						if (playerpos.first +1 > 10)
							playerpos.first++;
						break;
					case UP :
						if (playerpos.second - 1 >= 0)
							playerpos.second--;
						break;
					case DOWN :
						if (playerpos.second + 1 > 10)
							playerpos.second++;
						break;
					default:
						break;
				}
			}
		}
	}
}
int main()
{
	
	WSAData wsaData;
	int Result = WSAStartup(MAKEWORD(2, 2), &wsaData);


	SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN ServerAddr;
	memset(&ServerAddr, 0, sizeof(SOCKADDR_IN));

	ServerAddr.sin_family = PF_INET;
	ServerAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	ServerAddr.sin_port = htons(4949);

	connect(ServerSocket, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));

	HANDLE WorkHandle = (HANDLE)_beginthreadex(nullptr, 0, WorkThread, (void*)&ServerSocket, 0, nullptr);
	HANDLE InputHandle = (HANDLE)_beginthreadex(nullptr, 0, InputThread, (void*)&ServerSocket, 0, nullptr);

	for (;;);

	closesocket(ServerSocket);
	WSACleanup();


	return 0;
}