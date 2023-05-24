#include <iostream>
#include "stack.h"
#include "stack.cpp"

using namespace std;
 

int main()
{
	Stack<int> stack = Stack<int>(4); //  int형 데이터를 저장하는 스택 객체를 생성하며, 스택의 용량을 4로 지정
	//  스택에 3, 4, 5, 6, 7 값을 차례로 추가하는 코드
	// but 이 스택의 용량은 4로 설정되어 있으므로, 스택이 꽉 차면 용량을 2배로 늘리고 값을 추가
	stack.Push(3);
	stack.Push(4);
	stack.Push(5);
	stack.Push(6); 
	stack.Push(7);
	stack.pop(); // 스택의 가장 위에 있는 값을 삭제
	stack.Push(5);
	cout << stack.Top(); // 스택의 가장 위에 있는 값을 출력

	
	cout << stack.Top();




	return 0;
}

