#include<iostream>
#include "rectangle.h"

using namespace std;

// Rectangle 클래스의 멤버 함수 또는 멤버 변수에 대한 범위를 지정
Rectangle::Rectangle(int r = 0, int x = 0, int y = 0, int w = 0, int h = 0) // 생성자 함수
{ rNum = r; xLow=x; yLow=y; width=w; height=h; } // 멤버변수 

Rectangle::~Rectangle() // 객체가 소멸될 때 호출, delete 메모리를 반환
{ cout << "delete" << endl; }

int Rectangle::GetNum() { return rNum; } // rNum 멤버 변수 반환 
int Rectangle::GetHeight() { return height; } // height 멤버 변수 반환 
int Rectangle::GetWidth() { return width; } // width 멤버 변수 반환 
int Rectangle::GetArea() { return width*height; } // 사각형의 면적인 width * height 값을 반환

//(리턴 타입) operator(연산자) (연산자가 받는 인자)
// bool operator==(MyString& str);

// 연산자 오버로딩을 이용한 Rectangle 객체 출력을 위한 함수
ostream& operator <<(ostream& os, Rectangle& r) //두 번째 매개변수인 r은 출력하고자 하는 Rectangle 객체
{
    os << "---Rectangle Number " << r.rNum << "---" << endl;
    os << "Position is: [" << r.xLow << ", " << r.yLow << "]" << endl;
    os << "Width is: " << r.width << endl;
    os << "Height is: " << r.height << endl;
    
    return os;
}