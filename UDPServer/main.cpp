#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include<iostream>
#include<winsock2.h>

#pragma comment(lib, "WS2_32.lib")
using namespace std;

int main()
{
	WSAData wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	SOCKET ServerSocket = socket(AF_INET, SOCK_DGRAM, 0);
	SOCKADDR_IN ServerSocketAddr;
	memset(&ServerSocketAddr, 0, sizeof(SOCKADDR_IN));
	ServerSocketAddr.sin_family = PF_INET;
	ServerSocketAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	ServerSocketAddr.sin_port = htons(4949);

	bind(ServerSocket, (SOCKADDR*)&ServerSocketAddr, sizeof(ServerSocketAddr));

	FILE* fp = fopen("b855c89991507d38.jpg", "rb");
	fseek(fp, 0, SEEK_END);
	int totalfilesize = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	int cnt = totalfilesize / 1023;

	char buf[1024];
	sprintf_s(buf, "%d", totalfilesize);
	int sendfilesize = 0;

	while (cnt--)
	{
		SOCKADDR_IN ClientSocketAddr;

		memset(&ClientSocketAddr, 0, sizeof(SOCKADDR_IN));
		int Clientsocketlength = sizeof(ClientSocketAddr);

		fread(buf, sizeof(char), 1023, fp);
		buf[1024] = (totalfilesize / 1023 - cnt) + '0';
		int sendbytes = sendto(ServerSocket, buf, strlen(buf),0,(SOCKADDR*)&ClientSocketAddr,Clientsocketlength);
		sendfilesize += sendbytes;
	}
	fclose(fp);


	//while (true)
	//{
	//	char Buffer[1024] = { 0, };
	//	int recvLength = recvfrom(ServerSocket, Buffer, sizeof(Buffer), 0, (SOCKADDR*)&ClientSocketAddr, &Clientsocketlength);
	//	cout << Buffer<<endl;
	//	//cin >> Buffer;
	//	int sendlength = sendto(ServerSocket, Buffer, recvLength, 0, (SOCKADDR*)&ClientSocketAddr, Clientsocketlength);
	//
	//}

	closesocket(ServerSocket);
	WSACleanup();

	return 0;
}

/*
* TPC
* STREAM
* 전화
*/

/*
* UDP
* 자료 패킹 DataGram
* 택배
*/