//// main.cpp
//#include <iostream>
//#include "CMap.h"
//
//using namespace std;
//
//int main() {
//	CMap* pMap = new CMap(8);
//	Node* pNodeA = new Node('A');
//	Node* pNodeB = new Node('B');
//	Node* pNodeC = new Node('C');
//	Node* pNodeD = new Node('D');
//	Node* pNodeE = new Node('E');
//	Node* pNodeF = new Node('F');
//	Node* pNodeG = new Node('G');
//	Node* pNodeH = new Node('H');
//
//	pMap->addNode(pNodeA);
//	pMap->addNode(pNodeB);
//	pMap->addNode(pNodeC);
//	pMap->addNode(pNodeD);
//	pMap->addNode(pNodeE);
//	pMap->addNode(pNodeF);
//	pMap->addNode(pNodeG);
//	pMap->addNode(pNodeH);
//
//	delete pNodeA; //因为在CMap中已经定义了Node的位置，所以可以删掉，释放这里的内存
//	delete pNodeB;
//	delete pNodeC;
//	delete pNodeD;
//	delete pNodeE;
//	delete pNodeF;
//	delete pNodeG;
//	delete pNodeH;
//
//	pMap->setValueToMatrixForUndirectedGraph(0, 1); // 第三个参数有默认值为1，所以不需要设定
//	pMap->setValueToMatrixForUndirectedGraph(0, 3);
//	pMap->setValueToMatrixForUndirectedGraph(1, 2);
//	pMap->setValueToMatrixForUndirectedGraph(1, 5);
//	pMap->setValueToMatrixForUndirectedGraph(3, 6);
//	pMap->setValueToMatrixForUndirectedGraph(3, 7);
//	pMap->setValueToMatrixForUndirectedGraph(6, 7);
//	pMap->setValueToMatrixForUndirectedGraph(2, 4);
//	pMap->setValueToMatrixForUndirectedGraph(4, 5);
//
//	pMap->printMatrix();
//	cout << endl;
//
//	pMap->resetNode();
//
//	pMap->depthFirstTraverse(0);
//	pMap->resetNode();
//	cout << endl;
//
//	pMap->breadthFirstTraverse(0);
//	pMap->resetNode();
//
//	return 0;
//}



#include"十字链表.h"
int main()
{
	DirectedGraph<char> graph;
	graph.print();
	return 0;
}