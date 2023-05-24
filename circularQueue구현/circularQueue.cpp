#include "circularQueue.h"
#include <iostream>

using namespace std;

// template <class T>: 템플릿 선언으로, 템플릿 매개변수 T를 사용
template <class T>
void ReduceSize1D(T*& a, const int oldSize, const int newSize, const int front);


// ReduceSize1D 함수: 큐에서 데이터를 삭제하면서 크기를 줄일 때 사용되는 함수
// (템플릿 함수이므로 자료형에 따라 여러 번 컴파일될 수 있음)
template <class T>
CircularQueue<T>::CircularQueue(int queueCapacity) : capacity(queueCapacity) { // CircularQueue 클래스의 생성자는 큐의 용량(capacity)을 인자로 받음
	if (capacity < 1) throw "CircularQueue must be >= 0";
	// capacity가 1보다 작으면 예외를 던짐
	circularQueue = new T[capacity];
	// T형 변수(큐 배열)를 capacity만큼의 크기로 동적으로 할당
	front = 0;
	rear = 0;
	// front와 rear 변수를 초기화
}
// isEmpty()함수: 큐가 비어있는지 여부를 반환하는 함수
template <class T>
bool CircularQueue<T>::isEmpty() const {
	return (front == rear);
	// front와 rear가 같으면 비어있다고 판단
}

// Front() 함수: 큐의 맨 앞에 있는 원소를 반환하는 함수
template <class T>
T& CircularQueue<T>::Front() const {
	if (isEmpty()) throw "empty";
	// 큐가 비어있으면 예외를 던짐 
	return circularQueue[(front + 1) % capacity];
	// front+1을 capacity로 나눈 나머지의 인덱스를 반환
	// 원형 큐이므로 front의 위치는 항상 rear의 위치보다 1 작아야 함
}


// Rear() 함수: 큐의 맨 뒤에 있는 원소를 반환하는 함수입니다.
template <class T>
T& CircularQueue<T>::Rear() const {
	if (isEmpty()) throw "empty";
	// 큐가 비어있으면 예외를 던짐
	return circularQueue[rear];
	// rear의 인덱스를 반환
}

// Push() 함수: 큐에 데이터를 추가 

/* - 복사하는 과정에서 front와 rear의 위치가 중요함.
   - front와 rear는 각각 큐의 맨 앞과 맨 뒤를 가리키는 포인터. 
   - front와 rear가 기존 큐에서 가리키는 위치를 유지하면서, 데이터를 새로운 큐에 복사해야 함.
   - 따라서, 기존 큐의 front와 rear가 가리키는 위치를 기준으로, 각각의 데이터를 옮겨야 함*/
template <class T>
void CircularQueue<T>::Push (const T& item) {
	if (((rear + 1) % capacity) == front) //rear가 front 다음에 위치하는 경우(꽉 찬 경우)를 확인
	{
		T* newQueue = new T[capacity * 2]; // 그렇다면 큐의 용량을 두 배로 증가
		if (front < 1) {
			copy(circularQueue + front + 1, circularQueue + front + 1 + capacity - 1, newQueue); //  기존 큐에 있는 데이터를 새로운 큐에 복사합
		}
		else {
			copy(circularQueue + front + 1, circularQueue + capacity , newQueue);
			copy(circularQueue, circularQueue + rear + 1, newQueue + (capacity - (front+1)));
		}
		rear = capacity - 2;
		capacity = capacity * 2; // 기존 큐의 용량을 두 배로 증가시키고
		front = capacity - 1; //  front와 rear의 값을 업데이트합니다.
		delete[] circularQueue; // 기존 큐를 삭제하고
		circularQueue = newQueue; // 새로운 큐를 가리킴
		cout << "배열의 크기를 2배로 증가시킵니다.\n";
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

// Pop() 함수: 큐에서 데이터를 삭제
template <class T>
void CircularQueue<T>::Pop() {
	if (isEmpty()) throw "empty라서 pop할 수 없습니다.!"; // 만약 큐가 비어있으면 예외를 던짐
	front = (front + 1) % capacity; // front를 증가
	circularQueue[front].~T(); // circularQueue[front]를 삭제

	cout << "Pop()!!" << " front:" << front << " rear: " << rear << "\n";
}


