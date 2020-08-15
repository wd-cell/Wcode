#pragma once
// CMap.h
#include<vector>

#ifndef C_EX_CMAP_H
#define C_EX_CMAP_H

#include <vector>
#include "Node.h"

using namespace std;

class CMap {
public:
	CMap(int capacity);
	~CMap();
	bool addNode(Node* pNode); // 向图中加入顶点
	void resetNode(); // 重置顶点，即将所有顶点都设置为没有访问过， a.k.a bIsVisited = false
	bool setValueToMatrixForDirectedGraph(int row, int col, int val = 1); // 为有向图设置邻接矩阵，即设置弧
	bool setValueToMatrixForUndirectedGraph(int row, int col, int val = 1); // 为无向图设置邻接矩阵，即设置边

	void printMatrix(); // 打印邻接矩阵

	void depthFirstTraverse(int nodeIndex); // 深度优先遍历
	void breadthFirstTraverse(int nodeIndex); // 广度优先遍历

	void breadthFirstTraverseImpl(vector<int> preVec);

private:
	int m_iCapacity; // 图中最多可容纳的顶点数
	int m_iNodeCount; // 已经添加的顶点个数
	Node* m_pNodeArray; // 用于存放顶点的数组，存放的是指针
	int* m_pMatrix; // 用来存放邻接矩阵
	bool getValueFromMatrix(int row, int col, int& val);
};

#endif //C_EX_CMAP_H
