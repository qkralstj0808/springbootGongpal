#include <iostream>
#include "circularQueue.h"
#include "circularQueue.cpp"

using namespace std;


int main()
{
	CircularQueue<int> cq = CircularQueue<int>(4);
	cq.Push(3);
	cq.Push(4);
	cq.Push(5);
	cq.Push(6);
	cq.Push(7);
	cq.Push(8);
	cq.Push(9);
	cq.Pop();
	cq.Push(2);
	cq.Pop();
	cq.Pop();
	cq.Pop();
	cq.Pop();
	cq.Push(2);
	cq.Push(3);

	return 0;
}

