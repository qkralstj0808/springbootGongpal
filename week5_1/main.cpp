#include <iostream>
#include "Poly.h"

using namespace std;


Poly GetPoly() {
    // 입력받은 정수들 배열로 다항식 객체를 구성 후 return

    int input[256] = { 0 }; // 정수 배열
    int size = 0;   // 정수 개수

    char str[256];  // 입력 문자열
    char* p;                    

    fgets(str, 256, stdin);    // 문자열 1줄 입력받음

    // 공백 기준으로 각 숫자를 받고, 정수 배열에 입력
    p = strtok(str, " ");   // strtok : 문자열 나누는 함수
    while (p != NULL) {
        input[size++] = atoi(p);
        p = strtok(NULL, " ");
    }

    // 정수 배열로 다항식 객체 구성 후 return
    return Poly(input, size);
}


// 입출력, 곱셈 모두 class 내 멤버함수로 구현
// 입력 오버로딩
istream& operator>>(istream& is, Poly& poly) {
    // 정수 배열 입력 받기
    int input[256] = { 0 };
    int size = 0;
    while (1) {
        int num;
        is >> num;
        input[size++] = num;
        if (is.peek() == '\n') break;
    }

    // 다항식 객체에 입력한 정수 배열을 넣어주기
    poly = Poly(input, size);
    return is;
}

// 출력 오버로딩
ostream& operator<<(ostream& os, const Poly& poly) {
    os << poly.String();
    return os;
}

int main() {
    Poly a, b, c;
    int x;

    // 다항식 A 입력
    cout << "A : ";
    cin >> a;

    // 다항식 B 입력
    cout << "B : ";
    cin >> b;

    // #1-(1) A, B 문자열 출력
    cout << "A : " << a << endl;
    cout << "B : " << b << endl;

    // #1-(2) 다항식 C(= A*B)에 입력 후, 결과 출력
    c.Mul(a, b);
    cout << "C = " << c << endl;

    // x 값 입력
    cout << "x = ";
    cin >> x;

    // #1-(3) 새로운 다항식 C에 입력받은 x값을 대입한 결과
    printf("C(%d) = %d \n", x, c.Eval(x));


    // #1-(4) 출력된 결과값이 50 미만이면 ‘A’를, 50 이상이면 ‘B’ 를 출력
    if (c.Eval(x) < 50)
        printf("A");
    else if (c.Eval(x) >= 50)
        printf("B");

    return 0;
}