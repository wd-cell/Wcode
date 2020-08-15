#pragma once
#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;
#define INFINITY 65535

//����p227
typedef char VertexType;  //��������
typedef int EdgeType;  //��Ȩֵ����
#define MAXVEX 100
#define INFINTY 65535
struct MGraph {
	VertexType vexs[MAXVEX];  //�����
	EdgeType arc[MAXVEX][MAXVEX];  //�߱�
	int numVertexes, numEdges;  //�������ͱ���
};



//ͼ��
class Graph
{
public:
	//Graph();
	//~Graph();
	void CreateGraph();//����ͼ
	void MiniSpanTree_Prim();//��С������prim
	void MiniSpanTree_Kruskal();//��С������kruskal
private:
	vector<char> vexs; //�����
	vector<vector<int>>arc;//�ڽӾ���
	int numVertexes, numEdges;
	int Find(vector<int>&, int );
};
typedef struct {
	int begin;
	int end;
	int weight;
}Edge;

void Graph::CreateGraph()   //��������ͼΪ��
{
	cout << "���붥�����ͱ���:" << endl;
	cin >> numVertexes >> numEdges;
	cout << "���붥�㣺" << endl;
	int i, j, w;
	char ch;
	for (i = 0; i < numVertexes; i++)
	{
		cin >> ch;
		vexs.push_back(ch);
	}
	arc.resize(numVertexes, vector<int>(numVertexes));
	for (i = 0; i < numVertexes; i++) //��ʼ���ڽӾ���
		for (j = 0; j < numVertexes; j++)
		{
			if (i != j)arc[i][j] = INFINITY;
			else arc[i][j] = 0;
		}

	cout << "�����( vi ��vj)�ϵ��±�i,�±�j,��Ȩw :" << endl;
	for (int k = 0; k < numEdges; k++)
	{
		cin >> i >> j >> w;
		arc[i][j] = arc[j][i] = w;
	}
}

void Graph::MiniSpanTree_Prim()//Prim �㷨������С������
{
	vector<int> adjvex;//���涥���±�
	vector<int> lowcost;//���涥���ߵ�Ȩֵ
	int min, j, k;
	lowcost.push_back(0);
	adjvex.push_back(0);
	for (int i = 1; i < numVertexes; i++)
	{
		lowcost.push_back(arc[0][i]);
		adjvex.push_back(0);
	}
	for (int i = 1; i < numVertexes; i++)
	{
		min = INFINITY;
		j = 1; k = 0;
		while (j < numVertexes)
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;
			}
			j++;
		}
		cout << "(" << adjvex[k] << "," << k << ")" << endl;
		lowcost[k] = 0;
		for (j = 1; j < numVertexes; j++)
		{
			if (lowcost[j] != 0 && arc[k][j] < lowcost[j])
			{
				lowcost[j] = arc[k][j];
				adjvex[j] = k;
			}
		}
	}
}

bool comp(Edge a, Edge b)//�ȽϺ���
{
	return a.weight < b.weight;
}
void Graph::MiniSpanTree_Kruskal()//Kruskal�㷨������С������
{
	int n, m;
	vector<Edge> edges;
	Edge e;
	vector<int> parent;
	for (int i = 1; i < numVertexes; i++)//���ڽӾ���ת�����߼�����
	{
		for (int j = 0; j < i; j++)
		{
			if (arc[i][j] != 0 && arc[i][j] != INFINITY)
			{
				if (i < j)
				{
					e.begin = i;
					e.end = j;
				}
				else
				{
					e.begin = j;
					e.end = i;
				}
				e.weight = arc[i][j];
				edges.push_back(e);
			}
		}
	}
	sort(edges.begin(), edges.end(), comp);//�߼���������
	for (int i = 0; i < numVertexes; i++)
		parent.push_back(0);
	for (int i = 0; i < numEdges; i++)
	{
		n = Find(parent, edges[i].begin);
		m = Find(parent, edges[i].end);
		if (n != m)
		{
			parent[n] = m;
			cout << "(" << vexs[edges[i].begin] << "," << vexs[edges[i].end] << ")" << " " << edges[i].weight << endl;
		}
	}

}
int Graph::Find(vector<int> & parent, int f)
{
	while (parent[f] > 0)
		f = parent[f];
	return f;
}