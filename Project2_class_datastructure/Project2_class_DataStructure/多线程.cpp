#include<thread>
#include<mutex>
#include<iostream>
#include<vector>
using namespace std;

//多线程与锁
mutex m;
void run(int n) {   
	for (int i = 0; i < 5; ++i) {
		cout << "thread " << n << endl;
	}
}

void run1(int n) {   //无法解决抛出异常。当cout抛出异常时，unlock会无法执行，为此可用lock_guard
	for (int i = 0; i < 5; ++i) {
		m.lock();
		cout << "thread " << n << endl;
		m.unlock();
	}
}

void run2(int n) {
	for (int i = 0; i < 5; ++i) {   
		//在线程进入临界区之前声明lock_guard变量，将mutex变量作为变量传入，在构造函数中会调用该变量的lock()，
		//在析构函数中调用unlock()，如此无论是正常运行结束还是临界区中出现异常都会正常执行锁操作。
		
		lock_guard<mutex> l(m);   
		//lock_guard优势是实现简单、使用方便，适用于大多数场景，但存在的问题是使用场景过于简单，无法处理一些精细操作。此时便需要使用unique_lock。
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
		threads.emplace_back(run3); //注意emplace_back的特殊用法
	for (auto& t : threads)
		t.join();
}



//条件变量：线程间的通知机制
mutex mtx;
condition_variable cv;
void run21() {
	unique_lock<mutex> lck(mtx);
	cout << "Waiting" << endl;
	cv.wait(lck);   //先解锁，后等待
	cout << "Wake up" << endl;
}
void run22() {
	lock_guard<mutex> lck(mtx);
	cout << "Notify" << endl;
	cv.notify_one();   //随机唤醒一个等待的线程
}
void testNotify() {
	thread t1(run21);
	thread t2(run22);
	//cv.notify_one();   //此处放到run2中会实现想要结果
	t1.join();
	t2.join();
}



class Semaphore {   //信号量
	mutex mMutex;
	condition_variable mCondVar;
	int64_t mAvailable;

public:
	explicit Semaphore(int64_t init) :mAvailable(init) {};
	void post() {
		{   //括号内为临界区
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
		//v.emplace_back(thread(run34,i)); //线程间会争夺屏幕资源
		v.emplace_back(run33); //通过信号量实现了线程同步，不争抢资源
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






// ThreadPool.cpp: 定义控制台应用程序的入口点。 线程池
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