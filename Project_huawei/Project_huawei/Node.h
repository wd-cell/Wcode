#pragma once
// Node.h
#ifndef C_EX_NODE_H
#define C_EX_NODE_H
class Node
{
public:
	Node(char data = 0); // data Ϊ��ǰnode�����ֵ����������
	char m_cData;
	bool m_bIsVisited; // ��¼��ǰ�����Ƿ񱻷��ʹ�
};
#endif //C_EX_NODE_H