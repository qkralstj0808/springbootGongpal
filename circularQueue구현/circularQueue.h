#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

using namespace std;

template <class T> // T는 템플릿으로 선언된 데이터 타입으로, 이후 클래스 내에서 T를 이용할 수 있음
class CircularQueue {
public:
	CircularQueue(int queueCapacity = 10); // 생성자, queueCapacity 값을 인자로 받아 초기화합니다. 기본값으로 10
	bool isEmpty() const; // 큐가 비어있는지 확인

	T& Front() const; // 큐의 맨 앞에 있는 값을 가져오는 메서드
	T& Rear() const; // 큐의 맨 뒤에 있는 값을 가져오는 메서드

	void Push(const T& item); // 큐에 값을 추가하는 메서드

	void Pop(); // 큐에서 값을 제거하는 메서드

private:
	T* circularQueue; // 원형 큐에 사용될 배열 포인터
	int front; // 원형 큐에 사용될 배열 포인터
	int rear; // 큐의 맨 뒤에 있는 인덱스를 저장
	int capacity; // 원형 큐의 용량을 저장
};
#endif 