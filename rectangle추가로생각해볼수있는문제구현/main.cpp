// rectangle �߰��� �����غ� �� �ִ� ���� 
#include <iostream>
#include "rectangle.h"
#include <math.h>

using namespace std;


int main()
{
	Rectangle* rp2 = new Rectangle();
	Rectangle r[5];

	// ��ġ�� �簢�� ���ϴ� ��ü r1, r2
	Rectangle r1 = Rectangle(0, 0, 3, 4, 3);  // Rectangle Ŭ���� ��ü r1�� r2�� �����ϰ� ��ǥ, ����, ���� ����, ��ȣ�� ���ڷ� ���� 
	Rectangle r2 = Rectangle(1, 1, 2, 3, 4);


	// r1�� r2 �簢���� ��ġ�� �κ��� ���̸� ���ϴ� �ڵ�
	int x1 = max(r1.xLow, r2.xLow); // ��ġ�� �κ��� ���� ���̸� ���ϱ� ���� max �Լ��� ����Ͽ� r1�� r2 �߿��� �� ū xLow ���� ���մϴ�.
	int x2 = min(r1.xLow + r1.GetWidth(), r2.xLow + r2.GetWidth()); // ��ġ�� �κ��� ���� ���̸� ���ϱ� ���� min �Լ��� ����Ͽ� r1�� r2 �߿��� �� ���� xLow + Width ���� ����. 
	cout << r1.xLow << " " << r1.GetWidth() << " \n";
	cout << r1.xLow + r1.GetWidth() << " " << r2.xLow + r2.GetWidth() << "\n";
	int y1 = max(r1.yLow, r2.yLow);
	int y2 = min(r1.yLow + r1.GetHeight(), r2.yLow + r2.GetHeight());
	if (x1 > x2 || y1 > y2) { // x1�� x2, y1�� y2 ���̿� ��ġ�� �κ��� ���ٸ� 
		cout << "��ġ�� �κ��� �����ϴ�.";
	}
	else { // ��ġ�� �κ��� ���� ���̿� ���� ���̸� ����ϰ� ���̸� ����Ͽ� ���
		cout << "��ġ�� �κ��� ���̴�: \n";
		cout << "x2: " << x2 << " x1: " << x1 << "\n";
		cout << "y2: " << y2 << " y1: " << y1 << "\n";
		cout << (x2 - x1) * (y2 - y1);
	}

		
	


	return 0;
}

