#include "Poly.h"
#include <math.h>
#include <string.h>
#include <stdio.h>

using namespace std;

Poly::Poly() {
    Clear();
}

// 정수 배열로 계수 배열 초기화
Poly::Poly(int* input, int size) {  // size ; 정수 개수
    Init(input, size);
}

Poly::Poly(const Poly& o) {
    Init(o.coefs);  // 복사 생성자 : 계수 배열 깊은 복사
}

Poly& Poly::operator = (const Poly& o) {
    Init(o.coefs);  // 대입 연산자 : 계수 배열 깊은 복사
    return *this;
}


// 계수 배열 0으로 초기화
void Poly::Clear() {
    for (int i = 0; i < 256; i++) {
        coefs[i] = 0;
    }
}

void Poly::Init(const int a_coefs[256]) {
    for (int i = 0; i < 256; i++) {
        coefs[i] = a_coefs[i];
    }
}

void Poly::Init(int* input, int size) {
    int coef, power;

    Clear();

    for (int i = 0; i < size; i += 2) {
        coef = input[i];    // 정수 배열의 짝수번 //계수
        power = input[i + 1];   // 정수 배열의 홀수번 // 거듭제곱

        coefs[power] += coef;
    }
}

const char* Poly::String() const {

    static char str[1024];      // 제공할 문자열
    char substr[32] = { 0 };    // sub 문자열
    bool everPrinted = false;   // str에 항이 하나라도 입력된 경우만 true
    char sign;  // 부호 (사실상 +만 고려)

    strcpy(str, "");    // 문자열 초기화

    for (int i = 255; i >= 0; i--) {
        if (coefs[i] != 0) {
            sign = coefs[i] > 0 ? '+' : '-';    // 부호 (조건에 상수를 빼서 자연수 1~10만 고려하면 됨..)

            if (everPrinted) {
                // 두 번째 항부터 부호, 계수 따로
                sprintf(substr, " %c %d", sign, abs(coefs[i]));
                strcat(str, substr);
            }
            else {
                // 첫번째 항 계수는 따로
                sprintf(substr, "%d", coefs[i]);
                strcat(str, substr);
            }

            if (i > 1) {
                // x와 거듭제곱 출력
                sprintf(substr, "x^%d", i);
                strcat(str, substr);
            }

            else if (i == 1) {
                // x^1 은 그냥 x로 출력
                sprintf(substr, "x");
                strcat(str, substr);
            }
            everPrinted = true;
        }
    }

    // 계수가 1일 때(1x), x로 출력되도록
    char* p = strstr(str, "1x");
    while (p != NULL) {
        strcpy(p, p + 1);
        p = strstr(p + 1, "1x");
    }

    // 다항식이 0 이면 문자열이 텅... 때문에 0 출력
    if (strlen(str) == 0) {
        strcpy(str, "0");
    }

    return str;
}


// 두 다항식의 곱
void Poly::Mul(const Poly& a, const Poly& b) {
    Clear();

    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            if (i + j < 256 && a.coefs[i] != 0 && b.coefs[j] != 0) {
                coefs[i + j] += (a.coefs[i] * b.coefs[j]);
            }
        }
    }
}

// C에 입력받은 x값 return
int Poly::Eval(int x) const {
    int sum = 0;

    for (int i = 0; i < 256; i++) {
        if (coefs[i] != 0) {    // 계수가 0이 아닐 때
            sum += coefs[i] * pow(x, i);    //sum에 각 항 결과 누적
        }
    }
    return sum;
}