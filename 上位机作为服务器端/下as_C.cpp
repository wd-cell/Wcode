
#include "winsock2.h"  
#include <iostream>  
#pragma comment(lib, "ws2_32.lib")  
using namespace std;
BOOL    RecvLine(SOCKET s, char* buf);  //读取一行数据  
int main(int argc, char* argv[])
{
	const int BUF_SIZE = 64;
	WSADATA         wsd;            //WSADATA变量  
	SOCKET          sHost;          //服务器套接字  
	SOCKADDR_IN     servAddr;       //服务器地址  
	char            recBuf[BUF_SIZE];  //接收数据缓冲区  
	char            sendBuf[BUF_SIZE];
	int             retVal;         //返回值  

	//初始化套结字动态库  
	if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0)
	{
		cout << "WSAStartup failed!" << endl;
		return -1;
	}

	//创建套接字  
	sHost = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == sHost)
	{
		cout << "socket failed!" << endl;
		WSACleanup();//释放套接字资源  
		return  -1;
	}

	//设置服务器地址  
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr("192.168.1.113");
	servAddr.sin_port = htons((short)4999);
	int nServAddlen = sizeof(servAddr);

	//连接服务器  
	retVal = connect(sHost, (LPSOCKADDR)&servAddr, sizeof(servAddr));
	if (SOCKET_ERROR == retVal)
	{
		cout << "连接失败!" << endl;
		closesocket(sHost); //关闭套接字  
		WSACleanup();       //释放套接字资源  
		return -1;
	}
	while (true)
	{

		//接收上位机的数据  
		ZeroMemory(recBuf, BUF_SIZE);
		retVal = recv(sHost, recBuf, BUF_SIZE, 0);
		if (SOCKET_ERROR == retVal)
		{
			cout << "recv failed!" << endl;
			closesocket(sHost);   //关闭套接字  
			WSACleanup();          //释放套接字资源;  
			return -1;
		}
		cout << "上位机发送过来的数据: " << recBuf << endl;
		ZeroMemory(sendBuf, BUF_SIZE);
		cout << "向上位机发送数据: ";
		gets_s(sendBuf);
		retVal=send(sHost, sendBuf, strlen(sendBuf), 0);
		if (SOCKET_ERROR == retVal)
		{
			cout << "发送失败!" << endl;
			closesocket(sHost); //关闭套接字  
			WSACleanup();       //释放套接字资源  
			return -1;
		}
	}

	//退出  
	closesocket(sHost); //关闭套接字  
	WSACleanup();       //释放套接字资源  
	return 0;
}