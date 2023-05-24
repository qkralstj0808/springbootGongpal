#include "stack.h"
#include <iostream>

using namespace std;
template <class T>
void ChangeSize1D(T*& a, const int oldSize, const int newSize);


template <class T> // == templete <typename T> 
//  동적으로 할당된 배열의 크기를 변경하는 함수 newSize가 음수이면 예외를 발생
void ChangeSize1D(T* &a, const int oldSize, const int newSize) {
	if (newSize < 0) throw "New length must be >= 0";

	T* temp = new T[newSize];
	int minSize = min(oldSize, newSize);
	copy(a, a + minSize, temp); // copy 함수를 이용하여 이전 배열의 값을 새로운 배열로 복사한 후, 이전 배열을 삭제하고 새로운 배열로 변경
	delete[] a;
	a = temp;

	// cout << "?????? ?ι?? ????????.\n";

}
// Stack 클래스는 템플릿 클래스로 선언됨. 
// 스택은 동적으로 할당된 배열로 구현되어 있으며, top 변수는 스택의 가장 위에 있는 요소를 가리킵니다.
template <class T>
Stack<T>::Stack(int stackCapacity): capacity(stackCapacity) { //생성자는 스택의 용량을 인자로 받음 
	if (capacity < 1) throw "Stack capacity must be >= 0"; //용량이 1 미만일 경우 예외를 발생시킨다. 
	stack = new T[capacity];
	top = -1;
}

// isEmpty 함수는 스택이 비어있는지를 확인하는 함수
template <class T>
bool Stack<T>::isEmpty() const {
	return top == -1;
}

// Top 함수는 스택의 가장 위에 있는 요소를 반환. Top 함수 역시 스택이 비어있을 경우 예외를 발생
template <class T>
T& Stack<T>::Top() const {
	if (isEmpty()) throw "Stack is empty";
	return stack[top]; 
}
// Push 함수는 스택에 값을 추가하는 함수.
// 용량이 부족해지면 ChangeSize1D 함수를 호출하여 용량을 2배로 늘리고, capacity 변수도 2배로 업데이트
template <class T>
void Stack<T>::Push(const T& x) // ????? ????
{
	if (top == capacity - 1) {
		ChangeSize1D(stack, capacity, 2 * capacity);
		capacity *= 2;
	}
	stack[++top] = x;
}

// pop 함수는 스택에서 가장 위에 있는 값을 삭제
// 스택이 비어있을 경우 예외를 발생시킴. 이때, 스택에서 삭제된 값을 소멸자를 이용하여 메모리에서 해제
template <class T>
void Stack<T>::pop() {
	if (isEmpty()) throw "Stack is empty. Cannot delete";
	stack[top--].~T();
}

