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

//ð��
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



//ѡ������
void SelectionSort(int* h, size_t len)
{
	if (h == NULL) return;
	if (len <= 1) return;

	int minindex, i, j;
	//i�Ǵ�����Ҳ���źõĸ���;j�Ǽ�����
	for (i = 0; i < len - 1; ++i)
	{
		minindex = i;
		for (j = i + 1; j < len; ++j)
			if (h[j] < h[minindex]) minindex = j;
		swap(h[i], h[minindex]);
	}

	return;
}



//��������
void InsertSort(int* h, size_t len)
{
	if (h == NULL) return;
	if (len <= 1) return;

	int i, j;
	//i�Ǵ�����Ҳ���źõĸ���;j�Ǽ�����
	for (i = 1; i < len; ++i)
		for (j = i; j > 0; --j) {
			if (h[j] < h[j - 1]) 
				swap(h[j], h[j - 1]);
			else break;
		}
	return;
}



//ϣ������
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



//������
/*
�󶥶�sort֮������Ϊ��С��������
*/
//====����=====
void AdjustHeap(int* h, int node, int len)  //----nodeΪ��Ҫ�����Ľ���ţ���0��ʼ���;lenΪ�ѳ��� 
{
	int index = node;
	int child = 2 * index + 1; //���ӣ���һ���ڵ���Ϊ0 
	while (child < len)
	{
		//������ 
		if (child + 1 < len && h[child] < h[child + 1])  //�������С���Һ��ӣ�childָ���Һ��ӣ��ҳ����������ֵ
			child++;
		if (h[index] >= h[child]) break;   //���index�Ѿ������ֵ��break
		swap(h[index], h[child]);
		index = child;
		child = 2 * index + 1;
	}
}
//====����=====
void HeapSort(int* h, int len)
{
	//����
	for (int i = len / 2; i >= 0; --i)
		AdjustHeap(h, i, len);

	//����
	for (int i = len - 1; i >= 0; --i)
	{
		swap(h[i], h[0]);
		AdjustHeap(h, 0, i);
	}
}



//�鲢����
void Merge(int arr[], int l, int q, int r) {
	int n = r - l + 1;//��ʱ�����ϲ������������
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
	delete[] tmp;//ɾ���������ڴ�
}
void MergeSort(int arr[], int l, int r) {
	if (l == r)
		return;  //�ݹ�����������е�ÿ����������Ϊ����Ϊ1������
	int q = (l + r) / 2;
	MergeSort(arr, l, q);
	MergeSort(arr, q + 1, r);
	Merge(arr, l, q, r);
}



//����
int Parition(int a[], int low, int high) {
	int pivot = a[high];
	int i = low;
	for (int j = low; j < high; ++j)
	{
		//jָ��ǰ����Ԫ�أ�������ڵ���pivot��������ǰ
		//���С�ڵ�ǰԪ�أ����iָ���Ԫ�ؽ���
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



//KMP�㷨
vector<int> getNext(string T)   //��NEXT����
{
	vector<int> next(T.size(), 0);            // next���󣬺���ο�����÷�桶���ݽṹ��p84��
	next[0] = -1;                            // next����ĵ�0λΪ-1
	int k = 0;                            // kֵ
	for (int j = 2; j < T.size(); ++j)        // ���ַ���T�ĵ�2���ַ���ʼ������ÿ���ַ���nextֵ
	{
		while (k > 0 && T[j - 1] != T[k])
			k = next[k];   //��ؼ��Ļ���
		if (T[j - 1] == T[k])
			k++;           //��������ʱ
		next[j] = k;
	}
	return next;                            // ����next����
}
int KMP(string S, string T)   //KMP�㷨
{
	vector<int> next = getNext(T);
	//for (int m : next)
	//	cout << m;
	//cout << endl;

	int i = 0, j = 0;
	while (S[i] != '\0' && T[j] != '\0')
	{
		if ( S[i] == T[j]){   //�������β�����S[i]==T[j]ʱ��j=-1��T[j]��Խ�磬��ʱӦi++,j++����֤��������
			++i;
			++j;
		}
		else
			j = next[j];   //�ؼ�����

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
