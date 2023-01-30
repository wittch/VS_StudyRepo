#include "Message.h"

Message::Message()
{
	ServerSocket = socket(AF_INET, SOCK_STREAM, 0);
	ServerAddr.sin_family = PF_INET;
	ServerAddr.sin_port = htons(4848);
	ServerAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
}

Message::~Message()
{
	closesocket(ServerSocket);
}
void Message::GetSendMessage()
{
	while (1){
		
		m1.lock();
		m2.lock();
		scanf_s("%s", InputBuffer);
		send(ServerSocket, InputBuffer, sizeof(InputBuffer), 0);		
		m2.unlock();
		m1.unlock();
	}
}

void Message::RecvMessage()
{
	while (1) {
		m2.lock();
		if (!m1.try_lock())
		{
			m2.unlock();
			continue;
		}
		recv(ServerSocket, OutputBuffer, sizeof(OutputBuffer), 0);
		cout << "Server : " << OutputBuffer << '\n';
		m1.unlock();
		m2.unlock();
		break;
	}
}

