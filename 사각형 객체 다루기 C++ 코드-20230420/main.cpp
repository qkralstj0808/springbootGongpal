/* 
구현된 프로그램을 참조하여 다음의 조건을 만족하는 프로그램을 구현하시오.
1. 사각형 객체를 저장할 Rectangle 객체 배열 5칸을 생성
2. x, y 좌표와 가로, 세로 길이를 입력 받아서 입력받은 값으로 사각형 객체 생성
3. 사각형 객체를 생성할 때 생성하는 순서에 따라 사각형에 번호를 입력(hint : 파라미터를 추가해야 함)
4. 생성한 사각형 객체 5개 중에서 가장 넓이가 큰 사각형을 찾아서 출력 -> "0번째 사각형이 가장 크고, 그 넓이는 0이다."
*/

/* 추가로 생각해볼 수 있는 문제
1. 서로 겹치지 않는 사각형을 생성하는 방법
2. 두 개의 사각형이 겹치는 부분의 넓이를 구하는 방법
2. 객체를 포인터로 생성하고, 파괴하는 방법
*/


#include <iostream> 
#include "rectangle.h"

using namespace std;

main() {
    Rectangle *r[5]; // Rectangle 객체 배열 5칸
    int x, y, w, h;
    int largestRNum;
    int largestRArea;

// x, y, w, h 값을 입력받아 사각형 객체를 생성. 생성 순서에 따라 사각형에 번호를 입력
    for(int i = 0; i < 5; i++)
    {
        cout << i + 1 << "번 사각형" << endl;
        cout << "좌표 x : ";
        cin >> x;
        cout << "좌표 y : ";
        cin >> y;
        cout << "가로 : ";
        cin >> w;
        cout << "세로 : ";
        cin >> h;
        cout << endl;

        r[i] = new Rectangle(i+1, x, y, w, h);
    }

    for(int i = 0; i < 5; i++)
        cout << *r[i] << endl;

// 가장 넓이가 큰 사각형을 찾아 출력
// 화살표 연산자는 포인터를 통해 해당 객체의 멤버 함수를 호출

// r[i] 포인터가 가리키는 Rectangle 객체의 GetNum() 멤버 함수를 호출하는 것을 의미
// 포인터 연산자를 사용하지 않고 r[i].GetNum()을 사용하면 컴파일러가 r[i]를 Rectangle 객체로 인식하여 멤버 함수를 호출할 수 없다.
    largestRNum = r[0]-> GetNum();
    largestRArea = r[0]-> GetArea();

    for(int i = 1; i < 5; i++)
    {
        if(largestRArea < r[i]-> GetArea())
        {
            largestRNum = r[i]-> GetNum();
            largestRArea = r[i]-> GetArea();
        }
    }

    cout << largestRNum << "번 사각형이 가장 크고, 그 넓이는 " << largestRArea << "이다." << endl;
} 

