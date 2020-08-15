#pragma once
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<cstring>
#include<string>
#include<string>
#include<ctime>
#include<vector>
using namespace std;

//冒泡
void bubblesort(vector<int>& v) {
	int i, j;
	bool flag = true;
	for ( i = 0; i < v.size() && flag; ++i) {
		flag = false;
		for(j=v.size()-2;j>=i;--j)
			if (v[j] > v[j + 1]) {
				swap(v[j], v[j + 1]);
				flag = true;
			}
	}
}



//选择排序
void SelectionSort(int* h, size_t len)
{
	if (h == NULL) return;
	if (len <= 1) return;

	int minindex, i, j;
	//i是次数，也即排好的个数;j是继续排
	for (i = 0; i < len - 1; ++i)
	{
		minindex = i;
		for (j = i + 1; j < len; ++j)
			if (h[j] < h[minindex]) minindex = j;
		swap(h[i], h[minindex]);
	}

	return;
}



//插入排序
void InsertSort(int* h, size_t len)
{
	if (h == NULL) return;
	if (len <= 1) return;

	int i, j;
	//i是次数，也即排好的个数;j是继续排
	for (i = 1; i < len; ++i)
		for (j = i; j > 0; --j) {
			if (h[j] < h[j - 1]) 
				swap(h[j], h[j - 1]);
			else break;
		}
	return;
}



//希尔排序
void ShellSort(int* h, size_t len)
{
	if (h == NULL) return;
	if (len <= 1) return;

	int i;
	int increment = len;
	do {
		increment = increment / 3 + 1;
		for (i = increment; i < len; ++i) 
			if (h[i] < h[i - increment]) 
				swap(h[i], h[i - increment]);
	} while (increment > 1);

	return;
}



//堆排序
/*
大顶堆sort之后，数组为从小到大排序
*/
//====调整=====
void AdjustHeap(int* h, int node, int len)  //----node为需要调整的结点编号，从0开始编号;len为堆长度 
{
	int index = node;
	int child = 2 * index + 1; //左孩子，第一个节点编号为0 
	while (child < len)
	{
		//右子树 
		if (child + 1 < len && h[child] < h[child + 1])  //如果左孩子小于右孩子，child指向右孩子，找出孩子中最大值
			child++;
		if (h[index] >= h[child]) break;   //如果index已经是最大值则break
		swap(h[index], h[child]);
		index = child;
		child = 2 * index + 1;
	}
}
//====排序=====
void HeapSort(int* h, int len)
{
	//建堆
	for (int i = len / 2; i >= 0; --i)
		AdjustHeap(h, i, len);

	//排序
	for (int i = len - 1; i >= 0; --i)
	{
		swap(h[i], h[0]);
		AdjustHeap(h, 0, i);
	}
}



//归并排序
void Merge(int arr[], int l, int q, int r) {
	int n = r - l + 1;//临时数组存合并后的有序序列
	int* tmp = new int[n];
	int i = 0;
	int left = l;
	int right = q + 1;
	while (left <= q && right <= r)
		tmp[i++] = arr[left] <= arr[right] ? arr[left++] : arr[right++];
	while (left <= q)
		tmp[i++] = arr[left++];
	while (right <= r)
		tmp[i++] = arr[right++];

	for (int j = 0; j < n; ++j)
		arr[l + j] = tmp[j];
	delete[] tmp;//删掉堆区的内存
}
void MergeSort(int arr[], int l, int r) {
	if (l == r)
		return;  //递归基是让数组中的每个数单独成为长度为1的区间
	int q = (l + r) / 2;
	MergeSort(arr, l, q);
	MergeSort(arr, q + 1, r);
	Merge(arr, l, q, r);
}



//快排
int Parition(int a[], int low, int high) {
	int pivot = a[high];
	int i = low;
	for (int j = low; j < high; ++j)
	{
		//j指向当前遍历元素，如果大于等于pivot，继续向前
		//如果小于当前元素，则和i指向的元素交换
		if (a[j] < pivot) {
			swap(a[j], a[i]);
			i++;
		}
	}
	swap(a[i], a[high]);
	return i;
}
void QuickSort(int a[], int low, int high) {
	if (low < high)
	{
		int q = Parition(a, low, high);
		QuickSort(a, low, q - 1);
		QuickSort(a, q + 1, high);
	}
}



//KMP算法
vector<int> getNext(string T)   //求NEXT数组
{
	vector<int> next(T.size(), 0);            // next矩阵，含义参考王红梅版《数据结构》p84。
	next[0] = -1;                            // next矩阵的第0位为-1
	int k = 0;                            // k值
	for (int j = 2; j < T.size(); ++j)        // 从字符串T的第2个字符开始，计算每个字符的next值
	{
		while (k > 0 && T[j - 1] != T[k])
			k = next[k];   //最关键的回溯
		if (T[j - 1] == T[k])
			k++;           //满足条件时
		next[j] = k;
	}
	return next;                            // 返回next矩阵
}
int KMP(string S, string T)   //KMP算法
{
	vector<int> next = getNext(T);
	//for (int m : next)
	//	cout << m;
	//cout << endl;

	int i = 0, j = 0;
	while (S[i] != '\0' && T[j] != '\0')
	{
		if ( S[i] == T[j]){   //连续两次不满足S[i]==T[j]时，j=-1，T[j]会越界，此时应i++,j++，保证继续运行
			++i;
			++j;
		}
		else
			j = next[j];   //关键回溯

		if (j == -1) {
			++i;
			++j;
		}
	}
	if (T[j] == '\0')
		return i - j;
	else
		return -1;
}
