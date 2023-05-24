// rectangle 추가로 생각해볼 수 있는 문제 
#include <iostream>
#include "rectangle.h"
#include <math.h>

using namespace std;


int main()
{
	Rectangle* rp2 = new Rectangle();
	Rectangle r[5];

	// 겹치는 사각형 구하는 객체 r1, r2
	Rectangle r1 = Rectangle(0, 0, 3, 4, 3);  // Rectangle 클래스 객체 r1과 r2를 생성하고 좌표, 가로, 세로 길이, 번호를 인자로 전달 
	Rectangle r2 = Rectangle(1, 1, 2, 3, 4);


	// r1과 r2 사각형이 겹치는 부분의 넓이를 구하는 코드
	int x1 = max(r1.xLow, r2.xLow); // 겹치는 부분의 가로 길이를 구하기 위해 max 함수를 사용하여 r1과 r2 중에서 더 큰 xLow 값을 구합니다.
	int x2 = min(r1.xLow + r1.GetWidth(), r2.xLow + r2.GetWidth()); // 겹치는 부분의 세로 길이를 구하기 위해 min 함수를 사용하여 r1과 r2 중에서 더 작은 xLow + Width 값을 구함. 
	cout << r1.xLow << " " << r1.GetWidth() << " \n";
	cout << r1.xLow + r1.GetWidth() << " " << r2.xLow + r2.GetWidth() << "\n";
	int y1 = max(r1.yLow, r2.yLow);
	int y2 = min(r1.yLow + r1.GetHeight(), r2.yLow + r2.GetHeight());
	if (x1 > x2 || y1 > y2) { // x1과 x2, y1과 y2 사이에 겹치는 부분이 없다면 
		cout << "겹치는 부분이 없습니다.";
	}
	else { // 겹치는 부분의 가로 길이와 세로 길이를 출력하고 넓이를 계산하여 출력
		cout << "겹치는 부분의 넓이는: \n";
		cout << "x2: " << x2 << " x1: " << x1 << "\n";
		cout << "y2: " << y2 << " y1: " << y1 << "\n";
		cout << (x2 - x1) * (y2 - y1);
	}

		
	


	return 0;
}

