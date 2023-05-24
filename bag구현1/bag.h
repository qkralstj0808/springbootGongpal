#ifndef BAG_H
#define BAG_H
#include <iostream>
using namespace std;

class Bag {
public:
	Bag(int bagCapacity = 10);
	virtual ~Bag();

	virtual int Size() const;
	virtual bool isEmpty() const;
	virtual int Element() const;
	virtual void Push(const int);
	virtual void Pop();

protected:
	int* array_;
	int capacity;
	int top;

};

#endif