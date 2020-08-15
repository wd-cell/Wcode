// CMap.cpp

#include "CMap.h"
#include <iostream>
#include <vector>
using namespace std;

CMap::CMap(int capacity)
{
	m_iCapacity = capacity;
	m_iNodeCount = 0;
	m_pNodeArray = new Node[m_iCapacity];
	m_pMatrix = new int[m_iCapacity * m_iCapacity];
	memset(m_pMatrix, 0, m_iCapacity * m_iCapacity * sizeof(int)); // ����ĳ�ʼ������Ϊ��
}

CMap::~CMap()
{
	delete[]m_pNodeArray;
	delete[]m_pMatrix;
}

bool CMap::addNode(Node* pNode)
{
	if (pNode == NULL)
	{
		return false;
	}
	m_pNodeArray[m_iNodeCount].m_cData = pNode->m_cData; // �����������Ϊ��������±꣬����洢����ÿ������������һ������ʵ��Ϊ�������m_cData��ֵ
	m_iNodeCount++;
	return true;
}

void CMap::resetNode()
{
	for (int i = 0; i>m_iCapacity || col > m_iCapacity;)
	{
		return false;
	}
	m_pMatrix[row * m_iCapacity + col] = val;

	return true;
}

bool CMap::setValueToMatrixForUndirectedGraph(int row, int col, int val)
{
	if (row < 0 || col < 0 || row > m_iCapacity || col > m_iCapacity)
	{
		return false;
	}
	m_pMatrix[row * m_iCapacity + col] = val;
	m_pMatrix[col * m_iCapacity + row] = val;

	return true;
}

void CMap::printMatrix()
{
	for (int i = 0; i < m_iCapacity; i++)
	{
		for (int j = 0; j < m_iCapacity; j++)
		{
			cout << m_pMatrix[i * m_iCapacity + j] << " ";
		}
		cout << endl;
	}
}

bool CMap::getValueFromMatrix(int row, int col, int &val)
{
	if (row < 0 || col < 0 || row > m_iCapacity || col > m_iCapacity)
	{
		return false;
	}
	val = m_pMatrix[row * m_iCapacity + col]; // ���ڴ������reference������val�ı��ˣ������valueֵҲ��ı�

	return true;
}

void CMap::depthFirstTraverse(int nodeIndex)
{
	int value = 0;
	cout << m_pNodeArray[nodeIndex].m_cData << " ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	// �����Ӿ����в�����������Ƿ���������������
	for (int i = 0; i < m_iCapacity; i++)
	{
		getValueFromMatrix(nodeIndex, i, value);
		if (value == 1)
		{
			if (m_pNodeArray[i].m_bIsVisited)
			{
				continue;
			}
			else
			{
				depthFirstTraverse(i);
			}
		}
		else
		{
			continue;
		}
	}
}

void CMap::breadthFirstTraverse(int nodeIndex)
{
	cout << m_pNodeArray[nodeIndex].m_cData << " ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	vector curVec; // �Ѷ�����������뵽������
	curVec.push_back(nodeIndex);
	breadthFirstTraverseImpl(curVec);
}

void CMap::breadthFirstTraverseImpl(vector preVec)
{
	int value = 0;
	vector curVec;

	for (int j = 0; j < preVec.size(); j++)
	{
		for (int i = 0; i < m_iCapacity; i++)
		{
			getValueFromMatrix(preVec[j], i, value);
			if (value == 1)
			{
				if (m_pNodeArray[i].m_bIsVisited)
				{
					continue;
				}
				else
				{
					cout << m_pNodeArray[i].m_cData << " ";
					m_pNodeArray[i].m_bIsVisited = true;
					curVec.push_back(i);
				}
			}
			else
			{
				continue;
			}
		}
	}
	if (curVec.empty())
	{
		return;
	}
	else
	{
		breadthFirstTraverseImpl(curVec);
	}
}