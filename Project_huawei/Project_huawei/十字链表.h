#pragma once
/*********************ʮ������ʵ������ͼ******************/
//�߱�ڵ�
#include<iostream>
using namespace std;
#define MAX 100

template<class Type>
class EdgeNode
{
public:
	int tailvex;//������ڶ������±�
	int headvex;//���յ��ڶ������±�
	//int weight;���ڴ洢Ȩֵ����ͼ����Ҫ
	EdgeNode *headlink;//��߱�ָ����ָ����ͬ�յ����һ����
	EdgeNode *taillink;//�߱�ָ����ָ�������ͬ����һ����
	EdgeNode(int tailv, int headv, EdgeNode *headl = nullptr, EdgeNode *taill = nullptr) :tailvex(tailv), headvex(headv), headlink(headl), taillink(taill) {}
};
//�����ڵ�
template<class Type>
class VertexNode
{
public:
	Type data;//�ڵ�������
	EdgeNode<Type> *firstin;//ָ����߱�ڵ�
	EdgeNode<Type> *firstout;//ָ����߱�ڵ�
	VertexNode() {}
	VertexNode(Type d, EdgeNode<Type> *fir_in = nullptr, EdgeNode<Type> *fir_out = nullptr) :data(d), firstin(fir_in), firstout(fir_out) {}
};
//����ͼ�ࣨʮ������
template<class Type>
class DirectedGraph
{
private:
	VertexNode<Type> OrthogonalList[MAX];//����ͼ���㼯��
	int numVertexe;//��ǰͼ������
	int numEdges;//��ǰͼ�Ļ���

	int getPosition(Type el);//���el�ڶ�����е�λ��
public:
	DirectedGraph();//����ͼ
	~DirectedGraph();//��������
	void print();
};
//��������
template<class Type>
DirectedGraph<Type>::~DirectedGraph()
{
	cout << "��������" << endl;
}
//���el�ڶ�����е�λ��
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
//����ͼ(ʹ��ʮ������)
template<class Type>
DirectedGraph<Type>::DirectedGraph()
{
	Type c1, c2;
	int p1, p2;
	int i;
	EdgeNode<Type> *enode;//���ڵ�
	cout << "Input vertexe number: ";
	cin >> this->numVertexe;
	cout << "Input edge number: ";
	cin >> this->numEdges;
	//��ʼ������
	for (i = 0; i < this->numVertexe; i++)
	{
		cout << "Input a Type data(" << i + 1 << "): ";
		cin >> this->OrthogonalList[i].data;
		this->OrthogonalList[i].firstin = nullptr;
		this->OrthogonalList[i].firstout = nullptr;
	}
	//��ʼ����
	//�������������ʮ������
	for (i = 0; i < this->numEdges; i++)
	{
		cout << "edge" << i << endl;
		cout << "Input arcHead: ";
		cin >> c1;
		cout << "Input arcTail: ";
		cin >> c2;

		p1 = getPosition(c1);
		p2 = getPosition(c2);

		enode = new EdgeNode<Type>(p1, p2, nullptr, nullptr);//�߽ڵ�
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
//��ӡʮ������
template<class Type>
void DirectedGraph<Type>::print()
{
	EdgeNode<Type> *move;
	cout << "��ӡ���߱�:" << endl;
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
	cout << "��ӡ��߱�:" << endl;
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