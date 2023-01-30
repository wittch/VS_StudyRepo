
#include "SendMessage.h"

SendMessage::SendMessage()
{
	ServerSocket = socket(AF_INET, SOCK_STREAM, 0);
	ServerAddr.sin_family = PF_INET;
	ServerAddr.sin_port = htons(4848);
	ServerAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
}

SendMessage::~SendMessage()
{
}
void SendMessage::GetSendMessage()
{
		scanf_s("%s", InputBuffer);
		send(ServerSocket, InputBuffer, sizeof(InputBuffer), 0);	
}

void SendMessage::RecvMessage()
{
		recv(ServerSocket, OutputBuffer, sizeof(OutputBuffer), 0);
		cout<<"Server : " << OutputBuffer << '\n';
}
