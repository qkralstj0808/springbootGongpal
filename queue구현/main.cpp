#include <iostream>
#include "queue.h"
#include "queue.cpp"

using namespace std;


int main()
{
	Queue<int> queue = Queue<int>(4);

	queue.Push(3);
	queue.Push(4);
	queue.Push(5);
	queue.Push(6);
	queue.Push(7);
	queue.Pop();
	queue.Push(5);

	cout << queue;

	queue.Pop();
	queue.Pop(); // 이 지점에서 1/2 로 줄어든다
	cout << queue;
	queue.Push(3);

	queue.Pop();
	queue.Pop(); 
	queue.Pop(); // 이 지점에서 1/2 로 줄어든다
	queue.Push(2);



	return 0;
}

