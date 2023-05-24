#ifndef RECTANGLE_H
#define RECTANGLE_H

using namespace std;

class Rectangle {
public:
    Rectangle(int, int, int, int, int);
    ~Rectangle();
    int GetNum();
    int GetHeight();
    int GetWidth();
    int GetArea();
    friend ostream& operator <<(ostream& os, Rectangle& r);

private:
    int rNum, xLow, yLow, height, width;
};


#endif