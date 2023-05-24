#include "rectangle.h"
#include <iostream>

using namespace std;

Rectangle:: Rectangle(int r = 0, int x = 0, int y = 0, int h = 0, int w = 0)
{
	rnum = r, xLow = x, yLow = y, height = h, width = w;
}

int Rectangle::GetArea() {
	return height * width;
}

int Rectangle::GetHeight() {
	return height;
}

int Rectangle::GetNum() {
	return rnum;
}

int Rectangle::GetWidth() {
	return width;
}


//(리턴 타입) operator(연산자) (연산자가 받는 인자)
// bool operator==(MyString& str);



int Rectangle::operator == (const Rectangle& s) { // s->  Rectangle 객체를 참조하는 const 참조 매개변수
	if (this == &s) return 1; // 비교 대상이 같은 객체인지 확인합니다. 만약 같은 객체라면 1을 반환합니다. 여기서 this는 현재 객체를 가리키는 포인터
	if ((xLow == s.xLow) && (yLow == s.yLow) && (height == s.height) && (width == s.width)) return 1; // 두 객체의 속성들이 같은지 비교합니다. 만약 모든 속성이 같다면 1을 반환
	else return 0;

}
