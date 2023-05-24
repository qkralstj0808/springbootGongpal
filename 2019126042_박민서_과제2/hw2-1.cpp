#include    <cstdio>
#include    <cstring>   // memset(), memcpy() , strtok()
#include    <cmath>     // pow()
#define     LINESZ      1000
#define     TOKENSZ     100
#define     COEFSZ      30

using namespace std;


class Polynomial { 
public:
    int max_degree;         // 지수
    int coefs[COEFSZ + 1];  // 계수 배열 

    // 인자로 받은 coefs 배열을 복사하여 새로운 Polynomial 객체를 만든다. 
    Polynomial(int coefs[], int max_degree) {
        this->max_degree = max_degree;
        memcpy(this->coefs, coefs, sizeof(int) * (max_degree + 1));
    }

    

    // 다항식을 계수 배열(coefs)로 표현하고 최고차항에서 최저차항으로 내림차순으로 반복문을 수행
    
    void eval() { 
        for (int i = max_degree; i >= 0; i--) {
            if (coefs[i] == 0)      continue; // 계수가 0이 아니면, 현재 차수가 최고차항보다 작으면 더하기 기호(+)를 출력

            if (i < max_degree)     printf(" + ");

            if (coefs[i] != 1)      printf("%d", coefs[i]); // 1이 아니면 계수를 출력
            
            if (i == 1)             printf("x"); // 현재 차수가 1이면 변수 x를 출력
            else if (i > 1)         printf("x^%d", i); // 현재 차수가 1보다 크면 변수 x의 현재 차수를 지수로 하는 식을 출력합
        }
    }
    void operator()() { return this->eval(); }          // 연산자 오버로딩

    // f(1) = 1^2 + 2*1 = 3
    int eval(int x) {
        int sum = 0;
        for (int i = max_degree; i >= 0; i--)
            sum += coefs[i] * pow(x, i);   // x^i
        return sum;
    }
    int operator()(int x) { return this->eval(x); }     // 연산자 오버로딩

    // Polynominal(this) * Polynomial(p)

    Polynomial mul(Polynomial &p) { // class Polynomail 의 메서드 mul -> 다항식 곱을 반환 
        int max_degree = this->max_degree * p.max_degree;
        int coefs[max_degree + 1];
        memset(coefs, 0, sizeof(coefs));

        for (int i = this->max_degree; i >= 0; i--) {
            for (int j = p.max_degree; j >= 0; j--)
                coefs[i + j] += this->coefs[i] * p.coefs[j];
        }
        return Polynomial(coefs, max_degree);
    }
    Polynomial operator*(Polynomial &p) { return this->mul(p); }
};


// "1 2 3 4" -> ["1", "2", "3", "4"]
// 문자열 s를 받아서 토큰들로 나눠서 그것들을 tokens라는 리스트로 저장하고, 나눠진 토큰의 개수를 반환한다.
int _split(char *tokens[], char s[], const char *sep)
{
    int num_tokens = 0; // 나눠진 토큰의 개수 
    char *p; // 자른 문자열 

    p = strtok(s, sep); // strtok 함수(문자열, 구분자) / 문자열을 임시로 저장하기 위한 포인터 변수 p
    if (p != NULL) {  
        tokens[num_tokens++] = p;

        while ((p = strtok(NULL, sep)) != NULL) // s 문자열에서 이전에 잘려지지 않은 문자열의 다음 위치에서부터 구분자 sep을 찾아서 해당 위치에서부터 자른 문자열의 포인터를 반환 
            tokens[num_tokens++] = p; // strtok() 함수가 반환하는 포인터를 tokens 배열에 저장하고, num_tokens 변수를 증가시켜 나눠진 토큰의 개수를 세는 과정을 반복
    }

    return num_tokens; // strtok() 함수가 더 이상 자를 문자열이 없을 때, NULL을 반환하므로 이를 체크하여 반복문을 종료하고, 나눠진 토큰의 개수를 반환
}

// ["1", "2", "3", "4"] -> Coef([0, 0, 1, 0, 3]) (= 3x^4 + x^2)
// tokens 리스트로 토큰들을 받고, 계수 배열을 생성한다. 그리고 계수 배열의 유의미한 사이즈, 즉 최대 차수를 반환한다. (다항식의 문자열 표현에서 계수와 차수를 추출하고 이를 배열로 저장)
int _make_coefs(int coefs[], char *tokens[], int num_tokens)
{
    int max_degree = 0; // 다항식의 최고 차수 

    int degree, coef; // 차수, 걔수 
    for (int i = 0; i < num_tokens; i += 2) {
        coef = atoi(tokens[i]), degree = atoi(tokens[i + 1]); // atoi = char to int = 문자열을 정수 타입으로
        coefs[degree] = coef;

        if (degree > max_degree)    max_degree = degree;
    }

    return max_degree;
}

Polynomial input_polynomial() // class Polynomal의 메서드 input_polynomial -> 다항식 입력 시 계수, 지수 순서로 입력 받음 
{
    // 한 줄 받기 : "1 2 3 4"
    char line[LINESZ]; 
    fgets(line, LINESZ, stdin);     // 문자열 입력함수 fgets(저장할 배열, 행 최대 문자 수, 포인터 이름)를 사용하면 공백문자가 포함되어 있는 문장을 입력받아 저장할 수 있다.  , 행단위로 취득한 값은 문자열 배열로 저장
                                    // 즉 stdin(표준입력)으로 부터 문자열을 입력받아 배열 line에 저장하되, LINESZ의 길이 만큼만 저장
    // "1 2 3 4" -> ["1", "2", "3", "4"]'
    int num_tokens; // 문자열인 한 줄을 공백을 기준으로 자르기 위한 변수 num_tokens
    char *tokens[TOKENSZ]; // 포인터 tokens 
    num_tokens = _split(tokens, line, " "); // 공백을 기준으로 자른 문자열 저장 

    // ["1", "2", "3", "4"] -> Coef([0, 0, 1, 0, 3]) (= 3x^4 + x^2)
    int max_degree;
    int coefs[COEFSZ + 1]; // 계수를 저장하기ㅣ 위한 정수형 계수 배열 
    max_degree = _make_coefs(coefs, tokens, num_tokens); // 최고 차수 변수 max_degree

    return Polynomial(coefs, max_degree);
}


int main()
{
    // 2 1 1 2  (계수, 지수)
    Polynomial A = input_polynomial(); // 다항식 A

    // 1 1 3 2
    Polynomial B = input_polynomial(); // 다항식 B

    // x = 1
    int x; 
    printf("x = "), scanf("%d", &x);

    // A : 2x + x^2
    printf("A : "), A(), printf("\n");
    // B : x + 3x^2
    printf("B : "), B(), printf("\n");
    
    // C : 3x^4 + 7x^3 + 2x^2
    Polynomial C = A * B;           // A.mul(B);
    printf("C : "), C(), printf("\n");

    // 12
    int c = C(x);
    printf("%d\n", c);
    // A
    printf("%s\n", (c < 50) ? "A" : "B");
}
