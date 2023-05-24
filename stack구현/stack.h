#ifndef STACK_H
#define STACK_H

// Stack은 클래스 탬플릿 

template <class T>
class Stack {
public:
	Stack(int stackCapacity = 10); // 생성자 
	bool isEmpty() const; // 생성자 -> 멤버 변수 상수화 
	T& Top() const; 

	void Push(const T& item);
	
	void pop();


private:
	T* stack;
	int top; // top은 스택의 가장 위에 있는 원소의 인덱스
	int capacity; //  capacity는 현재 스택이 담을 수 있는 원소의 최대 개수
};
#endif