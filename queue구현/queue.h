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

	// ������ �����ε� - ���� ť �迭�� ����ִ� �͵�
	template <class T>
	friend ostream& operator<<(ostream& os, const Queue<T>& myself);

private:
	T* queue;
	int front;
	int rear;
	int capacity;
};


#endif