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
	bool addNode(Node* pNode); // ��ͼ�м��붥��
	void resetNode(); // ���ö��㣬�������ж��㶼����Ϊû�з��ʹ��� a.k.a bIsVisited = false
	bool setValueToMatrixForDirectedGraph(int row, int col, int val = 1); // Ϊ����ͼ�����ڽӾ��󣬼����û�
	bool setValueToMatrixForUndirectedGraph(int row, int col, int val = 1); // Ϊ����ͼ�����ڽӾ��󣬼����ñ�

	void printMatrix(); // ��ӡ�ڽӾ���

	void depthFirstTraverse(int nodeIndex); // ������ȱ���
	void breadthFirstTraverse(int nodeIndex); // ������ȱ���

	void breadthFirstTraverseImpl(vector<int> preVec);

private:
	int m_iCapacity; // ͼ���������ɵĶ�����
	int m_iNodeCount; // �Ѿ���ӵĶ������
	Node* m_pNodeArray; // ���ڴ�Ŷ�������飬��ŵ���ָ��
	int* m_pMatrix; // ��������ڽӾ���
	bool getValueFromMatrix(int row, int col, int& val);
};

#endif //C_EX_CMAP_H
