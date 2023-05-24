#include    <iostream>
#define     R_MAX                   10 // 행과 열의 크기 10으로 지정 
#define     C_MAX                   10


int A[R_MAX][C_MAX], R1, C1; // 전역 변수 행렬 A 
int B[R_MAX][C_MAX], R2, C2; // 전역 변수 행렬 B

// input 

// 3 3
// 2 3 4 
// 2 3 4
// 2 3 4
// 3 3 
// 4 5 6
// 4 5 6
// 4 5 6

// 행렬 add 함수 
void add()
{
    int r, c; 
 
    for (r = 0; r < R1; r++) {  // 사용자에게 입력 받은 행과 열까지 
        for (c = 0; c < C1; c++)
            std::cout << A[r][c] + B[r][c] << ' '; // + 연산  
        std::cout << std::endl; // 출력 
    }
}

// 헹렬 subtract 함수 
void sub()
{
    int r, c;

    for (r = 0; r < R1; r++) { // 사용자에게 입력 받은 행과 열까지 
        for (c = 0; c < C1; c++)
            std::cout << A[r][c] - B[r][c] << ' '; // - 연산 
        std::cout << std::endl;
    }
}

int main()
{
    int r, c; 

    std::cin >> R1 >> C1; // 사용자에게 행과 열의 크기를 입력 받음 (1)
    for (r = 0; r < R1; r++) // 행1
        for (c = 0; c < C1; c++) // 열1
            std::cin >> A[r][c]; // 사용자에게 입력받은 행과 열  A[r][c]에 저장 
    
    std::cin >> R2 >> C2; //  사용자에게 행과 열의 크기를 입력 받음 (2)
    for (r = 0; r < R2; r++) // 행2
        for (c = 0; c < C2; c++) //열2
            std::cin >> B[r][c]; // 사용자에게 입력받은 행과 열 B[r][c]에 저장 

    if (!(R1 == R2 && C1 == C2)) {  // 행과 열의 크기가 같지 않으면 계산오류 출력 후 return
        std::cout << "계산 오류" << std::endl;
        return 1;
    }

    add(), sub(); // 사용자에게 입력받은 행과 열의 크기가 같다면 add 함수 호출 후 sub 함수 호출 

    return 0; 
}