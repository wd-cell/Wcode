#include "winsock2.h"  
#pragma comment(lib, "ws2_32.lib") //windows socket依赖于系统的动态链接库 
#include <iostream>  
#include<string>
using namespace std;
int main(int argc, char* argv[])
{
	const int BUF_SIZE = 64;
	WSADATA         wsd;            //WSADATA变量  
	SOCKET          sServer;        //服务器套接字  
	SOCKET          sClient;        //客户端套接字  
	SOCKADDR_IN     addrServ;;      //服务器地址  
	char            recBuf[BUF_SIZE];  //接收数据缓冲区  
	char            sendBuf[BUF_SIZE];//返回给客户端的数据  
	int             retVal;         //返回值  

	//初始化套接字动态库  
	if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0)
	{
		cout << "WSAStartup failed!" << endl;
		return 1;
	}

	//创建套接字  
	sServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == sServer)
	{
		cout << "socket failed!" << endl;
		WSACleanup();//释放套接字资源;  
		return  -1;
	}

	//服务器套接字地址   
	addrServ.sin_family = AF_INET;
	addrServ.sin_port = htons(4999);
	addrServ.sin_addr.s_addr = INADDR_ANY;

	//绑定套接字  
	retVal = bind(sServer, (LPSOCKADDR)&addrServ, sizeof(SOCKADDR_IN));
	if (SOCKET_ERROR == retVal)
	{
		cout << "bind failed!" << endl;
		closesocket(sServer);   //关闭套接字  
		WSACleanup();           //释放套接字资源;  
		return -1;
	}

	//开始监听   
	retVal = listen(sServer, 1);//后面一个参数为请求队列的长度
	if (SOCKET_ERROR == retVal)
	{
		cout << "listen failed!" << endl;
		closesocket(sServer);   //关闭套接字  
		WSACleanup();           //释放套接字资源;  
		return -1;
	}

	//接受客户端请求  
	sockaddr_in addrClient;
	int addrClientlen = sizeof(addrClient);

	//accept() 返回一个新的套接字来和客户端通信，addrClient保存了客户端的IP地址和端口号
	sClient = accept(sServer, (sockaddr FAR*)&addrClient, &addrClientlen);
	if (INVALID_SOCKET == sClient)
	{
		cout << "accept failed!" << endl;
		closesocket(sServer);   //关闭套接字  
		WSACleanup();           //释放套接字资源;  
		return -1;
	}

	while (true){

		//向下位机发送数据  
		ZeroMemory(sendBuf, BUF_SIZE);
		cout << "------------------操作指令----------------" << endl;
		cout << "010 执行标定 011 结束标定 012 执行扫描 013 扫描结束回移 014 结束扫描" << endl;
		cout << "请发送指令:  ";
		cin >> sendBuf;
		retVal = send(sClient, sendBuf, strlen(sendBuf), 0);
		if (SOCKET_ERROR == retVal)
		{
			cout << "发送失败!" << endl;
			closesocket(sClient); //关闭套接字  
			WSACleanup();       //释放套接字资源  
			return -1;
		}

		//RecvLine(sHost, bufRecv);  
		ZeroMemory(recBuf, BUF_SIZE);
		recv(sClient, recBuf, BUF_SIZE, 0);     // 接收下位机的数据 
		string s(&recBuf[0], &recBuf[strlen(recBuf)]);
		if (s=="")
		{
			cout << "下位机没有发数据" << endl;
			break;
		}
		else
		{
			cout << "从下位机接收过来的数据：" << s<< endl;
		}
	}

	//退出  
	closesocket(sServer);   //关闭套接字  
	closesocket(sClient);   //关闭套接字  
	WSACleanup();           //释放套接字资源; 
	return 0;
}