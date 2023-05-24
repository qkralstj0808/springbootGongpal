#include "childStack.h"
#include <iostream>

ChildStack::ChildStack(int bagCapacity) : Bag(bagCapacity) {
}

ChildStack::~ChildStack() {
}

void ChildStack::Push(const int item) {
	if (top == capacity - 1) {
		cout << "Stack is Full" << endl;
		return;
;	}
	array_[++top] = item;
}

int ChildStack::Top() const {
	if (top == -1) {
		cout << "stack is empty" << endl;
	}
	return array_[top];
}

void ChildStack::Pop() {
	if (top == -1) {
		cout << "stack is empty" << endl;
	}

	top--;
}