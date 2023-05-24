#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

template <class T>
class Queue {
public:
	Queue(int queueCapacity = 10);
	bool isEmpty() const;

	T& Front() const;
	T& Rear() const;

	void Push(const T& item);

	void Pop();

	// 연산자 오버로딩 - 실제 큐 배열에 들어있는 것들
	template <class T>
	friend ostream& operator<<(ostream& os, const Queue<T>& myself);

private:
	T* queue;
	int front;
	int rear;
	int capacity;
};


#endif