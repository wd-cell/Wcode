#include<thread>
#include<mutex>
#include<iostream>
#include<vector>
using namespace std;

//���߳�����
mutex m;
void run(int n) {   
	for (int i = 0; i < 5; ++i) {
		cout << "thread " << n << endl;
	}
}

void run1(int n) {   //�޷�����׳��쳣����cout�׳��쳣ʱ��unlock���޷�ִ�У�Ϊ�˿���lock_guard
	for (int i = 0; i < 5; ++i) {
		m.lock();
		cout << "thread " << n << endl;
		m.unlock();
	}
}

void run2(int n) {
	for (int i = 0; i < 5; ++i) {   
		//���߳̽����ٽ���֮ǰ����lock_guard��������mutex������Ϊ�������룬�ڹ��캯���л���øñ�����lock()��
		//�����������е���unlock()������������������н��������ٽ����г����쳣��������ִ����������
		
		lock_guard<mutex> l(m);   
		//lock_guard������ʵ�ּ򵥡�ʹ�÷��㣬�����ڴ���������������ڵ�������ʹ�ó������ڼ򵥣��޷�����һЩ��ϸ��������ʱ����Ҫʹ��unique_lock��
		cout << "thread " << n << endl;
	}
}

void run3() {
	unique_lock<mutex> lck(m, try_to_lock);
	cout << (lck.owns_lock() ? '*' : 'x');
}

void testMutex() {
	//thread t1(run3, 1); //run1 , run2
	//thread t2(run3, 2);
	//t1.join();
	//t2.join();

	vector<thread> threads; //run3
	for (int i = 0; i < 50; ++i)
		threads.emplace_back(run3); //ע��emplace_back�������÷�
	for (auto& t : threads)
		t.join();
}



//�����������̼߳��֪ͨ����
mutex mtx;
condition_variable cv;
void run21() {
	unique_lock<mutex> lck(mtx);
	cout << "Waiting" << endl;
	cv.wait(lck);   //�Ƚ�������ȴ�
	cout << "Wake up" << endl;
}
void run22() {
	lock_guard<mutex> lck(mtx);
	cout << "Notify" << endl;
	cv.notify_one();   //�������һ���ȴ����߳�
}
void testNotify() {
	thread t1(run21);
	thread t2(run22);
	//cv.notify_one();   //�˴��ŵ�run2�л�ʵ����Ҫ���
	t1.join();
	t2.join();
}



class Semaphore {   //�ź���
	mutex mMutex;
	condition_variable mCondVar;
	int64_t mAvailable;

public:
	explicit Semaphore(int64_t init) :mAvailable(init) {};
	void post() {
		{   //������Ϊ�ٽ���
			unique_lock<mutex> lck(mMutex);
			cout << "post: " << ++mAvailable << endl;
		}
		mCondVar.notify_one();
	};
	void wait() {
		unique_lock<mutex> lck(mMutex);
		while (mAvailable <= 0)
			mCondVar.wait(lck);
		cout << "wait: " << --mAvailable << endl;
	};
};

Semaphore se(6);
void run31() {
	cout << "Waiting" << endl;
	cout << "Wake up" << endl;
	se.post();
}
void run32() {
	se.wait();
	cout << "Notify" << endl;
}
void run33() {
	se.wait();
}
void run34(int i) {
	cout << i << endl;
}
void run35() {
	se.post();
}
void testSemaphore() {
	vector<thread> v;
	for (int i = 0; i < 10; ++i)
		//v.emplace_back(thread(run34,i)); //�̼߳��������Ļ��Դ
		v.emplace_back(run33); //ͨ���ź���ʵ�����߳�ͬ������������Դ
	for (int i = 0; i < 10; ++i)
		v.emplace_back(run35);
	for (auto &i : v)
		i.join();
}
//void testSemaphore() {
//	thread t1(run31);
//	thread t2(run32);
//	t1.join();
//	t2.join();
//}






// ThreadPool.cpp: �������̨Ӧ�ó������ڵ㡣 �̳߳�
//#include "stdafx.h"
#include "ThreadPool.h"
#include <stdio.h>

class Task
{
public:
	static int Task1(PVOID p)
	{
		int i = 10;
		while (i >= 0)
		{
			printf("%d\n", i);
			Sleep(100);
			i--;
		}
		return i;
	}
};

class TaskCallback
{
public:
	static void TaskCallback1(int result)
	{
		printf("   %d\n", result);
	}
};

void testThreadPool()
{
	ThreadPool threadPool(2, 10);
	for (size_t i = 0; i < 30; i++)
	{
		threadPool.QueueTaskItem(Task::Task1, NULL, TaskCallback::TaskCallback1);
	}
	threadPool.QueueTaskItem(Task::Task1, NULL, TaskCallback::TaskCallback1, TRUE);
}






int main() {
	testSemaphore();
}