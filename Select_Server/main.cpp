//#define _WINSOCK_DEPRECATED_NO_WARNINGS
//#include<iostream>
//#include<WinSock2.h>
//#include<map>
//#include"MessagePacket.h"
//
//
//#pragma comment(lib, "WS2_32.lib")
//
//using namespace std;
//map<SOCKET, pair<int,int>> PlayerList;
//CRITICAL_SECTION ServerCS;
//char Data[18] = { 0, };
//
//
//int main()
//{
//
//	WSAData wsaData;
//	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
//	SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, 0);
//
//	SOCKADDR_IN ServerSocketAddr;
//	memset(&ServerSocketAddr, 0, sizeof(SOCKADDR_IN));
//	ServerSocketAddr.sin_family = PF_INET;
//	ServerSocketAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
//	ServerSocketAddr.sin_port = htons(4949);
//
//	bind(ServerSocket, (SOCKADDR*)&ServerSocketAddr, sizeof(ServerSocketAddr));
//
//	listen(ServerSocket, 5);
//
//
//
//	fd_set Reads;
//	fd_set Copys;
//	FD_ZERO(&Reads);
//	FD_SET(ServerSocket, &Reads);
//
//	TIMEVAL Timeout;
//	Timeout.tv_sec = 3;
//	Timeout.tv_usec = 0;
//
//	
//	while (true)
//	{
//		Copys = Reads;
//		int fd_num = select(0, &Copys, 0, 0, &Timeout);
//		if (fd_num == SOCKET_ERROR)
//		{
//			cout << "Error : " << GetLastError() << '\n';
//			exit(-1);
//		}
//		else if (fd_num == 0)
//		{
//			cout << "Timeout.\n";
//		}
//		else
//		{
//			for (int i = 0; i < (int)Reads.fd_count; i++)
//			{
//				if (FD_ISSET(Reads.fd_array[i], &Copys))
//				{
//					if (Reads.fd_array[i] == ServerSocket) // 새로운 소켓 생성
//					{
//						SOCKADDR_IN ClientSocketAddr;
//						memset(&ClientSocketAddr, 0, sizeof(SOCKADDR_IN));
//						int ClientSockAddrLength = sizeof(ClientSocketAddr);
//						SOCKET ClientSocket = accept(ServerSocket, (SOCKADDR*)&ClientSocketAddr, &ClientSockAddrLength);
//						FD_SET(ClientSocket, &Reads);
//						
//						PlayerList[ClientSocket] = {0,0};
//						
//					}
//					else //이미 존재하는 소켓
//					{
//						
//						int RecvBytes = recv(Reads.fd_array[i], Data, sizeof(Data), 0);
//
//						if (RecvBytes <= 0)
//						{
//							SOCKET DisconnectSocket = Reads.fd_array[i];
//
//							//disconnect
//							
//							//EnterCriticalSection(&ServerCS);
//
//							unsigned short Code = htons((unsigned short)MessagePacket::S2C_Destroy);
//							int tmp = 0;
//							memcpy(&Data[0], &Code, sizeof(Code));
//							SOCKET FromID = 0;
//							tmp = htonl(DisconnectSocket);
//							memcpy(&Data[2], &tmp, sizeof(DisconnectSocket));
//							
//
//							cout << "Disconnected : " << DisconnectSocket << '\n';
//
//							for (auto Player : PlayerList)
//							{
//								int sentBytes = 0;
//								int TotalSentBytes = 0;
//								do {
//									sentBytes = send(Player.first, &Data[TotalSentBytes], sizeof(Data) - TotalSentBytes, 0);
//									TotalSentBytes += sentBytes;
//								} while (TotalSentBytes < sizeof(Data));
//							}
//							//LeaveCriticalSection(&ServerCS);
//
//
//							cout << "Socket ID " << DisconnectSocket << " Disconnected.\n";
//							PlayerList.erase(DisconnectSocket);
//							FD_CLR(DisconnectSocket, &Reads);
//							closesocket(DisconnectSocket);
//
//						}
//						else
//						{
//							for (int j = 0; j < (int)Reads.fd_count; j++)
//							{
//								if (Reads.fd_array[i] != ServerSocket) // 각 Client로 Data 전송
//								{
//									//packet parse, deserialize
//									unsigned short Code = 0;
//									memcpy(&Code, &Data[0], sizeof(Code));
//									SOCKET FromID = 0;
//									memcpy(&FromID, &Data[2], sizeof(FromID));
//
//									Code = ntohs(Code);
//									FromID = ntohll(FromID);
//
//									int X = 0;
//									int Y = 0;
//
//									switch ((MessagePacket)Code)
//									{
//									case MessagePacket::C2S_Move:
//									{
//										memcpy(&X, &Data[10], sizeof(X));
//										X = ntohl(X);
//										memcpy(&Y, &Data[14], sizeof(Y));
//										Y = ntohl(Y);
//
//										//update PlayerList
//										auto UpdatePlayer = PlayerList.find(FromID);
//										UpdatePlayer->second.first = X;
//										UpdatePlayer->second.second = Y;
//
//										unsigned short Code = htons((unsigned short)MessagePacket::S2C_Move);
//										memcpy(&Data[0], &Code, sizeof(Code));
//										SOCKET SendID = htonll(FromID);
//										memcpy(&Data[2], &SendID, sizeof(SendID));
//										int Temp = htonl(X);
//										memcpy(&Data[10], &Temp, sizeof(Temp));
//										Temp = htonl(Y);
//										memcpy(&Data[14], &Temp, sizeof(Temp));
//
//										//send
//										for (auto Player : PlayerList)
//										{
//											int sentBytes = 0;
//											int TotalSentBytes = 0;
//											do {
//												sentBytes = send(Player.first, &Data[TotalSentBytes], sizeof(Data) - TotalSentBytes, 0);
//												TotalSentBytes += sentBytes;
//											} while (TotalSentBytes < sizeof(Data));
//										}
//									}
//									break;
//
//									default:
//										break;
//									}
//
//								}
//								else // 서버 출력
//								{
//									cout << "Recived Data from : "<< Reads.fd_array[j]<< " Socket." << '\n';
//								}
//							}
//						}
//
//
//					}
//				}
//			}
//		}
//	}
//
//
//
//
//	return 0;
//}