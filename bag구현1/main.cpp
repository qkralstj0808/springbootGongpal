#include <iostream>
#include "childStack.h"
#include "bag.h"

using namespace std;


int main()
{
	ChildStack cS(5);
	
	cS.Push(0);
	cS.Push(1);
	cS.Push(2);
	cS.Pop();
	cS.Push(4);
	cS.Element();

	return 0;
}

