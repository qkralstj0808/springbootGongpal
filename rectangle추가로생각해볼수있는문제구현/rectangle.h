#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
public:
	Rectangle(int, int , int, int, int );
	int GetNum();
	int GetHeight();
	int GetWidth();
	int GetArea();
	int operator == (const Rectangle& s) ;
	

public:
	int rnum, xLow, yLow, height, width;
};
#endif  
