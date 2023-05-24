#include "stack.h"
#include <iostream>

using namespace std;
template <class T>
void ChangeSize1D(T*& a, const int oldSize, const int newSize);


template <class T> // == templete <typename T> 
//  �������� �Ҵ�� �迭�� ũ�⸦ �����ϴ� �Լ� newSize�� �����̸� ���ܸ� �߻�
void ChangeSize1D(T* &a, const int oldSize, const int newSize) {
	if (newSize < 0) throw "New length must be >= 0";

	T* temp = new T[newSize];
	int minSize = min(oldSize, newSize);
	copy(a, a + minSize, temp); // copy �Լ��� �̿��Ͽ� ���� �迭�� ���� ���ο� �迭�� ������ ��, ���� �迭�� �����ϰ� ���ο� �迭�� ����
	delete[] a;
	a = temp;

	// cout << "?????? ?��?? ????????.\n";

}
// Stack Ŭ������ ���ø� Ŭ������ �����. 
// ������ �������� �Ҵ�� �迭�� �����Ǿ� ������, top ������ ������ ���� ���� �ִ� ��Ҹ� ����ŵ�ϴ�.
template <class T>
Stack<T>::Stack(int stackCapacity): capacity(stackCapacity) { //�����ڴ� ������ �뷮�� ���ڷ� ���� 
	if (capacity < 1) throw "Stack capacity must be >= 0"; //�뷮�� 1 �̸��� ��� ���ܸ� �߻���Ų��. 
	stack = new T[capacity];
	top = -1;
}

// isEmpty �Լ��� ������ ����ִ����� Ȯ���ϴ� �Լ�
template <class T>
bool Stack<T>::isEmpty() const {
	return top == -1;
}

// Top �Լ��� ������ ���� ���� �ִ� ��Ҹ� ��ȯ. Top �Լ� ���� ������ ������� ��� ���ܸ� �߻�
template <class T>
T& Stack<T>::Top() const {
	if (isEmpty()) throw "Stack is empty";
	return stack[top]; 
}
// Push �Լ��� ���ÿ� ���� �߰��ϴ� �Լ�.
// �뷮�� ���������� ChangeSize1D �Լ��� ȣ���Ͽ� �뷮�� 2��� �ø���, capacity ������ 2��� ������Ʈ
template <class T>
void Stack<T>::Push(const T& x) // ????? ????
{
	if (top == capacity - 1) {
		ChangeSize1D(stack, capacity, 2 * capacity);
		capacity *= 2;
	}
	stack[++top] = x;
}

// pop �Լ��� ���ÿ��� ���� ���� �ִ� ���� ����
// ������ ������� ��� ���ܸ� �߻���Ŵ. �̶�, ���ÿ��� ������ ���� �Ҹ��ڸ� �̿��Ͽ� �޸𸮿��� ����
template <class T>
void Stack<T>::pop() {
	if (isEmpty()) throw "Stack is empty. Cannot delete";
	stack[top--].~T();
}

