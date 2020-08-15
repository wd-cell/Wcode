#pragma once
// Node.h
#ifndef C_EX_NODE_H
#define C_EX_NODE_H
class Node
{
public:
	Node(char data = 0); // data 为当前node顶点的值，不是索引
	char m_cData;
	bool m_bIsVisited; // 记录当前顶点是否被访问过
};
#endif //C_EX_NODE_H