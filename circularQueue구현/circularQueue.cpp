#include "circularQueue.h"
#include <iostream>

using namespace std;

// template <class T>: ���ø� ��������, ���ø� �Ű����� T�� ���
template <class T>
void ReduceSize1D(T*& a, const int oldSize, const int newSize, const int front);


// ReduceSize1D �Լ�: ť���� �����͸� �����ϸ鼭 ũ�⸦ ���� �� ���Ǵ� �Լ�
// (���ø� �Լ��̹Ƿ� �ڷ����� ���� ���� �� �����ϵ� �� ����)
template <class T>
CircularQueue<T>::CircularQueue(int queueCapacity) : capacity(queueCapacity) { // CircularQueue Ŭ������ �����ڴ� ť�� �뷮(capacity)�� ���ڷ� ����
	if (capacity < 1) throw "CircularQueue must be >= 0";
	// capacity�� 1���� ������ ���ܸ� ����
	circularQueue = new T[capacity];
	// T�� ����(ť �迭)�� capacity��ŭ�� ũ��� �������� �Ҵ�
	front = 0;
	rear = 0;
	// front�� rear ������ �ʱ�ȭ
}
// isEmpty()�Լ�: ť�� ����ִ��� ���θ� ��ȯ�ϴ� �Լ�
template <class T>
bool CircularQueue<T>::isEmpty() const {
	return (front == rear);
	// front�� rear�� ������ ����ִٰ� �Ǵ�
}

// Front() �Լ�: ť�� �� �տ� �ִ� ���Ҹ� ��ȯ�ϴ� �Լ�
template <class T>
T& CircularQueue<T>::Front() const {
	if (isEmpty()) throw "empty";
	// ť�� ��������� ���ܸ� ���� 
	return circularQueue[(front + 1) % capacity];
	// front+1�� capacity�� ���� �������� �ε����� ��ȯ
	// ���� ť�̹Ƿ� front�� ��ġ�� �׻� rear�� ��ġ���� 1 �۾ƾ� ��
}


// Rear() �Լ�: ť�� �� �ڿ� �ִ� ���Ҹ� ��ȯ�ϴ� �Լ��Դϴ�.
template <class T>
T& CircularQueue<T>::Rear() const {
	if (isEmpty()) throw "empty";
	// ť�� ��������� ���ܸ� ����
	return circularQueue[rear];
	// rear�� �ε����� ��ȯ
}

// Push() �Լ�: ť�� �����͸� �߰� 

/* - �����ϴ� �������� front�� rear�� ��ġ�� �߿���.
   - front�� rear�� ���� ť�� �� �հ� �� �ڸ� ����Ű�� ������. 
   - front�� rear�� ���� ť���� ����Ű�� ��ġ�� �����ϸ鼭, �����͸� ���ο� ť�� �����ؾ� ��.
   - ����, ���� ť�� front�� rear�� ����Ű�� ��ġ�� ��������, ������ �����͸� �Űܾ� ��*/
template <class T>
void CircularQueue<T>::Push (const T& item) {
	if (((rear + 1) % capacity) == front) //rear�� front ������ ��ġ�ϴ� ���(�� �� ���)�� Ȯ��
	{
		T* newQueue = new T[capacity * 2]; // �׷��ٸ� ť�� �뷮�� �� ��� ����
		if (front < 1) {
			copy(circularQueue + front + 1, circularQueue + front + 1 + capacity - 1, newQueue); //  ���� ť�� �ִ� �����͸� ���ο� ť�� ������
		}
		else {
			copy(circularQueue + front + 1, circularQueue + capacity , newQueue);
			copy(circularQueue, circularQueue + rear + 1, newQueue + (capacity - (front+1)));
		}
		rear = capacity - 2;
		capacity = capacity * 2; // ���� ť�� �뷮�� �� ��� ������Ű��
		front = capacity - 1; //  front�� rear�� ���� ������Ʈ�մϴ�.
		delete[] circularQueue; // ���� ť�� �����ϰ�
		circularQueue = newQueue; // ���ο� ť�� ����Ŵ
		cout << "�迭�� ũ�⸦ 2��� ������ŵ�ϴ�.\n";
	}
	
	rear = (rear + 1) % capacity;
	circularQueue[rear] = item;
	cout << "Push()!! [";
	if ((front+1) % capacity > rear) {
		for (int i = (front + 1) % capacity; i < capacity; i++) {
			cout << circularQueue[i] << ", ";
		}

		for (int i = 0; i <= rear; i++) {
			cout << circularQueue[i];
			if (i < rear) {
				cout << ", ";
			}
		}
	}
	else {
		
		for (int i = (front + 1) % capacity; i <= rear; i++) {
			cout << circularQueue[i];
			if (i < rear) {
				cout << ", ";
			}
		}
	}
	cout << "]";
	cout << " capacity: " << capacity << " front: " << front << " " << "Rear: " << rear << " " <<  "\n";
}

// Pop() �Լ�: ť���� �����͸� ����
template <class T>
void CircularQueue<T>::Pop() {
	if (isEmpty()) throw "empty�� pop�� �� �����ϴ�.!"; // ���� ť�� ��������� ���ܸ� ����
	front = (front + 1) % capacity; // front�� ����
	circularQueue[front].~T(); // circularQueue[front]�� ����

	cout << "Pop()!!" << " front:" << front << " rear: " << rear << "\n";
}


