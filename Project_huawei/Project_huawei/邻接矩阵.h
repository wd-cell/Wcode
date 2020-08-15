#pragma once
#include<iostream>
using namespace std;
#define SIZE 10
///////////////////////////////ͼ�ڽӾ���
class Graph
{
public:
	Graph()
	{
		MaxVertex = SIZE;
		NumVertex = NumEdge = 0;//�������ͱ�����ʼ��Ϊ0
		Vertex = new char[MaxVertex];
		Edge = new int*[MaxVertex];//int *Edge[10];
		int i, j;
		for (i = 0; i < MaxVertex; i++)
			Edge[i] = new int[MaxVertex]; //Edge[10][10]
		for (i = 0; i < MaxVertex; i++)
		{
			for (j = 0; j < MaxVertex; j++)
				Edge[i][j] = 0;
		}
	}
	void InsertVertex(char v)//����һ������v
	{
		if (NumVertex >= MaxVertex)
			return;
		Vertex[NumVertex++] = v;
	}
	int GetVertexI(char v)//����һ������v
	{
		int i;
		for (i = 0; i < NumVertex; i++)
		{
			if (Vertex[i] == v)
				return i;
		}
		return -1;
	}
	void InsertEdge(char v1, char v2)//����һ���ɵ�v1��v2��ɵı�
	{
		int p1 = GetVertexI(v1);
		int p2 = GetVertexI(v2);
		if (p1 == -1 || p2 == -1)
			return;
		Edge[p1][p2] = Edge[p2][p1] = 1;
		NumEdge++;
	}
	void ShowGraph()//��ӡ����
	{
		int i, j;
		cout << "  ";
		for (i = 0; i < NumVertex; i++)
			cout << Vertex[i] << " ";
		cout << endl;
		for (i = 0; i < NumVertex; i++)
		{
			cout << Vertex[i] << " ";
			for (j = 0; j < NumVertex; j++)
				cout << Edge[i][j] << " ";
			cout << endl;
		}
	}

	int GetEdgeNum(char v)//��ȡͼ�ı���
	{
		int p = GetVertexI(v);
		if (p == -1)
			return 0;
		int n = 0;
		for (int i = 0; i < NumVertex; i++)
		{
			if (Edge[p][i] == 1)
				n++;
		}
		return n;
	}
	void DeleteVertex(char v)//ɾ��һ������
	{
		int p = GetVertexI(v);
		if (p == -1)
			return;
		int i, j;
		int n = GetEdgeNum(v);
		for (i = p; i < NumVertex - 1; i++)  //������ɾ��
			Vertex[i] = Vertex[i + 1];

		for (i = p; i < NumVertex - 1; i++)  //������
		{
			for (j = 0; j < NumVertex; j++)
				Edge[i][j] = Edge[i + 1][j];
		}
		for (i = 0; i < NumVertex - 1; i++)  //������
		{
			for (j = p; j < NumVertex - 1; j++)
			{
				Edge[i][j] = Edge[i][j + 1];
			}
		}

		NumVertex--;
		NumEdge -= n;

	}
	void DeleteEdge(char v1, char v2)//ɾ������v1��v2֮��ı�
	{
		int p1 = GetVertexI(v1);
		int p2 = GetVertexI(v2);
		if (p1 == -1 || p2 == -1)
			return;
		if (Edge[p1][p2] == 0)
			return;
		Edge[p1][p2] = Edge[p2][p1] = 0;
		NumEdge--;
	}
	~Graph()
	{
		delete[]Vertex;
		Vertex = NULL;
		for (int i = 0; i < MaxVertex; i++)
		{
			delete[]Edge[i];
			Edge[i] = NULL;
		}
		delete[]Edge;
		Edge = NULL;
		NumVertex = 0;//���������ͷſռ�ɲ�д
	}
private:
	int MaxVertex;
	int NumVertex;
	int NumEdge;
	char *Vertex;
	int **Edge;
};