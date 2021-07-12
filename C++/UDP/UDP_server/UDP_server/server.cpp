#include <WinSock2.h>
#include <iostream>

#pragma comment(lib, "ws2_32.lib")

#define PORT			7890
#define PACKET_LENGHT	1024

int main()
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET hSocket = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	// SOCK_DGRAM - UDP 프로토콜 전송 방식

	SOCKADDR_IN tAddr = {};
	tAddr.sin_family = AF_INET;
	tAddr.sin_port = htons(PORT);
	tAddr.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(hSocket, (SOCKADDR*)&tAddr, sizeof(tAddr));

	SOCKADDR_IN tDestAddr = {};
	int iDestLength = sizeof(tDestAddr);
	char Packet[PACKET_LENGHT] = {};

	recvfrom(hSocket, Packet, sizeof(Packet), 0, (SOCKADDR*)&tDestAddr, &iDestLength);

	std::cout << "I am Server : " << Packet << std::endl;

	memset(Packet, 0, PACKET_LENGHT);

	strcpy_s(Packet, "Send from Server");

	sendto(hSocket, Packet, sizeof(Packet), 0, (SOCKADDR*)&tDestAddr, iDestLength);

	closesocket(hSocket);

	WSACleanup();

	return 0;
}