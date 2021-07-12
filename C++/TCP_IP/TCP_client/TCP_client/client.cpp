#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <WinSock2.h>

#pragma comment(lib, "ws2_32")

#define PORT 4578
#define PACKET_SIZE 1024
#define SERVER_IP "192.168.137.1"

int main()
{
	char to_send_message[PACKET_SIZE];


	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET hSocket;
	hSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN tAddr = {};
	tAddr.sin_family = AF_INET;
	tAddr.sin_port = htons(PORT);
	tAddr.sin_addr.s_addr = inet_addr(SERVER_IP);

	connect(hSocket, (SOCKADDR*)&tAddr, sizeof(tAddr));

	for (;;)
	{
		std::cout << "Please enter the word >> ";
		std::cin >> to_send_message;
		char* cMsg = to_send_message;
		send(hSocket, cMsg, strlen(cMsg), 0);

		char cBuffer[PACKET_SIZE] = {};
		recv(hSocket, cBuffer, PACKET_SIZE, 0);

		//printf("Recv Msg : %s\n", cBuffer);
		std::cout << "Recv Msg : " << cBuffer << std::endl;

		if (_strcmpi(cMsg, "quit") == 0) break;
	}

	closesocket(hSocket);

	WSACleanup();
	return 0;
}