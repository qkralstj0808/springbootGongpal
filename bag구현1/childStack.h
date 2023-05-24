#ifndef CHILDSTACK_H
#define CHILDSTACK_H
#include "bag.h"

class ChildStack : public Bag {
public:
	ChildStack(int bagCapacity = 10);
	virtual ~ChildStack();
	virtual int Top() const;
	virtual void Push(const int);
	virtual void Pop();
};

#endif