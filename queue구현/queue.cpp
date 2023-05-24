#include "queue.h"
#include <iostream>

using namespace std;

template <class T>
void ChangeSize1D(T*& a, const int oldSize, const int newSize);

template <class T>
void ReduceSize1D(T*& a, const int oldSize, const int newSize, const int front);

template <class T>
Queue<T>::Queue(int queueCapacity) : capacity(queueCapacity) {
	if (capacity < 1) throw "Queue must be >= 0";
	queue = new T[capacity];
	front = -1;
	rear = -1;
}

template <class T>
bool Queue<T>::isEmpty() const {
	return (front == rear);
}

template<class T>
T& Queue<T>::Front() const{
	if (isEmpty()) throw "empty";
	return queue[front+1];
}

template <class T>
T& Queue<T>::Rear() const {
	if (isEmpty()) throw "empty";
	return queue[rear];
}

template <class T>
void Queue<T>::Push(const T& item) {
	if (rear == capacity - 1) {
		ChangeSize1D(queue, capacity, 2 * capacity);
		capacity = 2 * capacity;
	}
	queue[++rear] = item;

	cout << "Push()!! ��µǴ� queue: [";
 	for (int i = front+1; i < rear+1; i++) {
		
		cout << queue[i];
		if (i < rear) {
			cout << ", ";
		}
	}
	cout << "] ";
	cout << "capacity: " << capacity << "\n";
;}

template <class T>
void Queue<T>::Pop() {
	if (isEmpty()) throw "Queue is empty. Cannot delete";

	cout << "Pop()!!\n";
	//queue[++front].~T();
	// ���� �޸𸮿��� �������� �ʴ´ٸ�
	++front;

	if ((rear - front) < capacity / 2) {
		ReduceSize1D(queue, rear - front, capacity / 2, front);
		capacity = capacity / 2;
		rear = rear - front - 1;
		front = -1;
	}
	
}

template <class T>
void ChangeSize1D(T*& a, const int oldSize, const int newSize) {
	if (newSize < 0) throw "New length must be >= 0";

	T* temp = new T[newSize];

	int minSize = min(oldSize, newSize);

	copy(a, a + minSize, temp);
	delete[] a;
	a = temp;
	cout << "����� �� ��� �����մϴ�." << "\n";
}

template <class T>
void ReduceSize1D(T*& a, const int oldSize, const int newSize, const int front) {
	T* temp = new T[newSize];
	copy(a + front + 1, a + front + 1 + oldSize, temp);
	delete[] a;
	a = temp;

	cout << "����� 1/2�� �����մϴ�." << "\n";

}

template <class U>
// ������ �����ε� - ���� ť �迭�� ����ִ� �͵�
ostream& operator<<(ostream& os,const Queue<U>& myself) {
	os << "������ �迭�� �� �ִ� ��: ";
	
	os << "[";
	for (int i = 0; i <= myself.rear; i++) {
		os << myself.queue[i];
		if (i < myself.rear) {
			os << ", ";
		}

	}
	os << "]" << "\n";
	return os;
}