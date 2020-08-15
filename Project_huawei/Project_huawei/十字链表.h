#pragma once
/*********************十字链表实现有向图******************/
//边表节点
#include<iostream>
using namespace std;
#define MAX 100

template<class Type>
class EdgeNode
{
public:
	int tailvex;//弧起点在顶点表的下标
	int headvex;//弧终点在顶点表的下标
	//int weight;用于存储权值非网图不需要
	EdgeNode *headlink;//入边表指针域，指向相同终点的下一条边
	EdgeNode *taillink;//边表指针域，指向起点相同的下一条边
	EdgeNode(int tailv, int headv, EdgeNode *headl = nullptr, EdgeNode *taill = nullptr) :tailvex(tailv), headvex(headv), headlink(headl), taillink(taill) {}
};
//顶点表节点
template<class Type>
class VertexNode
{
public:
	Type data;//节点数据域
	EdgeNode<Type> *firstin;//指向入边表节点
	EdgeNode<Type> *firstout;//指向出边表节点
	VertexNode() {}
	VertexNode(Type d, EdgeNode<Type> *fir_in = nullptr, EdgeNode<Type> *fir_out = nullptr) :data(d), firstin(fir_in), firstout(fir_out) {}
};
//有向图类（十字链表）
template<class Type>
class DirectedGraph
{
private:
	VertexNode<Type> OrthogonalList[MAX];//有向图顶点集合
	int numVertexe;//当前图顶点数
	int numEdges;//当前图的弧数

	int getPosition(Type el);//获得el在顶点表中的位置
public:
	DirectedGraph();//构造图
	~DirectedGraph();//析构函数
	void print();
};
//析构函数
template<class Type>
DirectedGraph<Type>::~DirectedGraph()
{
	cout << "析构函数" << endl;
}
//获得el在顶点表中的位置
template<class Type>
int DirectedGraph<Type>::getPosition(Type el)
{
	int i;
	for (i = 0; i < this->numVertexe; i++)
	{
		if (this->OrthogonalList[i].data == el)
			return i;
	}
	return -1;
}
//创建图(使用十字链表法)
template<class Type>
DirectedGraph<Type>::DirectedGraph()
{
	Type c1, c2;
	int p1, p2;
	int i;
	EdgeNode<Type> *enode;//弧节点
	cout << "Input vertexe number: ";
	cin >> this->numVertexe;
	cout << "Input edge number: ";
	cin >> this->numEdges;
	//初始化顶点
	for (i = 0; i < this->numVertexe; i++)
	{
		cout << "Input a Type data(" << i + 1 << "): ";
		cin >> this->OrthogonalList[i].data;
		this->OrthogonalList[i].firstin = nullptr;
		this->OrthogonalList[i].firstout = nullptr;
	}
	//初始化弧
	//输入各弧并构造十字链表
	for (i = 0; i < this->numEdges; i++)
	{
		cout << "edge" << i << endl;
		cout << "Input arcHead: ";
		cin >> c1;
		cout << "Input arcTail: ";
		cin >> c2;

		p1 = getPosition(c1);
		p2 = getPosition(c2);

		enode = new EdgeNode<Type>(p1, p2, nullptr, nullptr);//边节点
		if (this->OrthogonalList[p1].firstout == nullptr)
			this->OrthogonalList[p1].firstout = enode;
		else
		{
			EdgeNode<Type> *move = this->OrthogonalList[p1].firstout;
			while (move->taillink != nullptr)
				move = move->taillink;
			move->taillink = enode;
		}
		if (this->OrthogonalList[p2].firstin == nullptr)
			this->OrthogonalList[p2].firstin = enode;
		else
		{
			EdgeNode<Type> *move = this->OrthogonalList[p2].firstin;
			while (move->headlink != nullptr)
				move = move->headlink;
			move->headlink = enode;
		}
	}
}
//打印十字链表
template<class Type>
void DirectedGraph<Type>::print()
{
	EdgeNode<Type> *move;
	cout << "打印出边表:" << endl;
	for (int i = 0; i < this->numVertexe; i++)
	{
		cout << "Vertexe( " << i << " ): ";
		move = this->OrthogonalList[i].firstout;
		while (move != nullptr)
		{
			cout << move->headvex << " ";
			move = move->taillink;
		}
		cout << endl;
	}
	cout << "打印入边表:" << endl;
	for (int i = 0; i < this->numVertexe; i++)
	{
		cout << "Vertexe( " << i << " ): ";
		move = this->OrthogonalList[i].firstin;
		while (move != nullptr)
		{
			cout << move->tailvex << " ";
			move = move->headlink;
		}
		cout << endl;
	}

}