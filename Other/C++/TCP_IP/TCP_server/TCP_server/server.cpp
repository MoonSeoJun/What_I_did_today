#include <iostream>
#include <WinSock2.h>

#pragma comment(lib, "ws2_32")

#define PORT 4578
#define PACKET_SIZE 1024

int main()
{
	WSADATA wsaData; //  Windows의 소켓 초기화 정보를 저장하기위한 구조체
	WSAStartup(MAKEWORD(2, 2), &wsaData); // 윈도우즈에 어느 소켓을 활용할 것인지 알려줌.

	SOCKET hListen; // SOCKET 은 핸들. 핸들이란 운영체제가 관리하는 커널오브젝트의 한 종류
	hListen = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	//PF_INET = IPV4 타입, SOCK_STREAM = 연결지향형 소켓, IPPROTO_TCP = TCP를 지정

	SOCKADDR_IN tListenAddr = {}; // 주소정보를 담아두는 구조체
	tListenAddr.sin_family = AF_INET; // sin_family 는 반드시 AF_INET, AF_INET = 2
	tListenAddr.sin_port = htons(PORT); // 2바이트 안에서 표현
	tListenAddr.sin_addr.s_addr = htonl(INADDR_ANY); // 현재 동작되는 컴퓨터의 IP 주소

	bind(hListen, (SOCKADDR*)&tListenAddr, sizeof(tListenAddr)); // 소켓에 주소정보를 연결
	listen(hListen, SOMAXCONN); // 연결을 수신하는상태로 소켓의 상태를 변경
	// SOMAXCONN은 한꺼번에 요청 가능한 최대 접속승인 수

	SOCKADDR_IN tClntAddr = {};
	int iClntSize = sizeof(tClntAddr);
	SOCKET hClient = accept(hListen, (SOCKADDR*)&tClntAddr, &iClntSize); // 접속 요청을 수락

	for (;;)
	{
		char cBuffer[PACKET_SIZE] = {};
		recv(hClient, cBuffer, PACKET_SIZE, 0); // 보내온 정보를 받아주는 역할, flag를 활성화시키지 않을것이기에 0을 지정
		std::cout << "Recv Msg : " << cBuffer << std::endl;

		char* cMsg = cBuffer;
		send(hClient, cMsg, strlen(cMsg), 0); // 서버가 메세지를 클라이언트측에 전달

		if (_strcmpi(cMsg, "quit") == 0) break;
	}

	closesocket(hClient);
	closesocket(hListen);

	WSACleanup(); // 소멸자 
	return 0;
}