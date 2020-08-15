
#include "winsock2.h"  
#include <iostream>  
#pragma comment(lib, "ws2_32.lib")  
using namespace std;
BOOL    RecvLine(SOCKET s, char* buf);  //��ȡһ������  
int main(int argc, char* argv[])
{
	const int BUF_SIZE = 64;
	WSADATA         wsd;            //WSADATA����  
	SOCKET          sHost;          //�������׽���  
	SOCKADDR_IN     servAddr;       //��������ַ  
	char            recBuf[BUF_SIZE];  //�������ݻ�����  
	char            sendBuf[BUF_SIZE];
	int             retVal;         //����ֵ  

	//��ʼ���׽��ֶ�̬��  
	if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0)
	{
		cout << "WSAStartup failed!" << endl;
		return -1;
	}

	//�����׽���  
	sHost = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == sHost)
	{
		cout << "socket failed!" << endl;
		WSACleanup();//�ͷ��׽�����Դ  
		return  -1;
	}

	//���÷�������ַ  
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr("192.168.1.113");
	servAddr.sin_port = htons((short)4999);
	int nServAddlen = sizeof(servAddr);

	//���ӷ�����  
	retVal = connect(sHost, (LPSOCKADDR)&servAddr, sizeof(servAddr));
	if (SOCKET_ERROR == retVal)
	{
		cout << "����ʧ��!" << endl;
		closesocket(sHost); //�ر��׽���  
		WSACleanup();       //�ͷ��׽�����Դ  
		return -1;
	}
	while (true)
	{

		//������λ��������  
		ZeroMemory(recBuf, BUF_SIZE);
		retVal = recv(sHost, recBuf, BUF_SIZE, 0);
		if (SOCKET_ERROR == retVal)
		{
			cout << "recv failed!" << endl;
			closesocket(sHost);   //�ر��׽���  
			WSACleanup();          //�ͷ��׽�����Դ;  
			return -1;
		}
		cout << "��λ�����͹���������: " << recBuf << endl;
		ZeroMemory(sendBuf, BUF_SIZE);
		cout << "����λ����������: ";
		gets_s(sendBuf);
		retVal=send(sHost, sendBuf, strlen(sendBuf), 0);
		if (SOCKET_ERROR == retVal)
		{
			cout << "����ʧ��!" << endl;
			closesocket(sHost); //�ر��׽���  
			WSACleanup();       //�ͷ��׽�����Դ  
			return -1;
		}
	}

	//�˳�  
	closesocket(sHost); //�ر��׽���  
	WSACleanup();       //�ͷ��׽�����Դ  
	return 0;
}