#pragma once
#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;
#define INFINITY 65535

//书上p227
typedef char VertexType;  //顶点类型
typedef int EdgeType;  //边权值类型
#define MAXVEX 100
#define INFINTY 65535
struct MGraph {
	VertexType vexs[MAXVEX];  //顶点表
	EdgeType arc[MAXVEX][MAXVEX];  //边表
	int numVertexes, numEdges;  //顶点数和边数
};



//图类
class Graph
{
public:
	//Graph();
	//~Graph();
	void CreateGraph();//创建图
	void MiniSpanTree_Prim();//最小生成树prim
	void MiniSpanTree_Kruskal();//最小生成树kruskal
private:
	vector<char> vexs; //顶点表
	vector<vector<int>>arc;//邻接矩阵
	int numVertexes, numEdges;
	int Find(vector<int>&, int );
};
typedef struct {
	int begin;
	int end;
	int weight;
}Edge;

void Graph::CreateGraph()   //以无向网图为例
{
	cout << "输入顶点数和边数:" << endl;
	cin >> numVertexes >> numEdges;
	cout << "输入顶点：" << endl;
	int i, j, w;
	char ch;
	for (i = 0; i < numVertexes; i++)
	{
		cin >> ch;
		vexs.push_back(ch);
	}
	arc.resize(numVertexes, vector<int>(numVertexes));
	for (i = 0; i < numVertexes; i++) //初始化邻接矩阵
		for (j = 0; j < numVertexes; j++)
		{
			if (i != j)arc[i][j] = INFINITY;
			else arc[i][j] = 0;
		}

	cout << "输入边( vi ，vj)上的下标i,下标j,和权w :" << endl;
	for (int k = 0; k < numEdges; k++)
	{
		cin >> i >> j >> w;
		arc[i][j] = arc[j][i] = w;
	}
}

void Graph::MiniSpanTree_Prim()//Prim 算法生成最小生成树
{
	vector<int> adjvex;//保存顶点下标
	vector<int> lowcost;//保存顶点间边的权值
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

bool comp(Edge a, Edge b)//比较函数
{
	return a.weight < b.weight;
}
void Graph::MiniSpanTree_Kruskal()//Kruskal算法生成最小生成树
{
	int n, m;
	vector<Edge> edges;
	Edge e;
	vector<int> parent;
	for (int i = 1; i < numVertexes; i++)//将邻接矩阵转化到边集数组
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
	sort(edges.begin(), edges.end(), comp);//边集数组排序
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