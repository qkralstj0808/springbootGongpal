#include "bag.h"
#include <iostream>

using namespace std;


Bag::Bag(int bagCapacity) : capacity(bagCapacity) {
	if (capacity < 1) {
		throw "Capacity must be > 0";
	}
	
	array_ = new int[capacity];
	top = -1;

}

Bag::~Bag() {
	delete[] array_;
}

int Bag::Size() const {
	return top + 1;
}

bool Bag::isEmpty() const {
	return top == -1;
}

int Bag::Element() const {
	cout << "[";
	for (int i = 0; i <= top; i++) {
		cout << array_[i];
		if (i < top) {
			cout << ", ";
		}
	}
	cout << "] top: " << top << " capacity: " << capacity << "\n";

	return 0;
}


void Bag::Push(const int item) {
	if (Size() == capacity) {
		int* newArray = new int[2 * capacity];
		for (int i = 0; i < capacity; i++) {
			newArray[i] = array_[i];
		}

		delete[] array_;
		array_ = newArray;
		capacity = 2 * capacity;
	}

	array_[++top] = item;
}

void Bag::Pop() {
	if (isEmpty()) {
		throw "Bag is empty";
	}
	top--;
}