// 배열을 이용하여 행렬을 표현하는 2가지 방법
// 1. 2차원 배열을 이용해 전체요소를 저장하는 방법 -> 연산구현 간단하지만 메모리 공간 낭비 
// 2. 0이 아닌 요소들만 저장하는 방법 (위치, 요소) -> 메모리 공간 절약되지만, 연산구현 어려움

#include <cstdio>
#define N_MAX 100 // 행 크기 100 
#define M_MAX 100 // 열 크기 100

int A[N_MAX + 1][M_MAX + 1], R, C; // N_MAX + 1, M_MAX + 1 인 이유-> sparce matrix의 0번쩨 요소는 row, col, value에 대한 정보를 담기 때문 


/** input matrix */ // 행렬 입력 
void input_transpose_matrix()
{
    scanf("%d %d", &R, &C); // 공백을 기준으로 행 개수 R, 열 개수 C
    // 전치행렬이므로 열행 
    for (int x = 1; x <= C; x++) { 
        for (int y = 1; y <= R; y++) { 
            scanf("%d", &A[y][x]);  // 행렬 내 원소 채우기 
        }
    }
}



// sparcematrix 희소행렬  배열 내에서 0이 아닌 개수 세기 
int _count_non_zeros()
{
    int count = 0; 
     // 전치행렬이므로 열행 
    for (int y = 1; y <= R; y++) {  
        for (int x = 1; x <= C; x++) { 
            if (A[y][x] != 0) { // 행렬 
                count += 1; // count 변수에 0이 아닌 값의 개수를 세어 담는다. 
            }
        }
    }
    return count; // 0이 아닌 개수 리턴
}

// A[n][m] 과 희소행렬 중 효율 판단 bool (0 or 1)
bool is_dok_effecient()
{
    int non_zeros = _count_non_zeros(); // 변수 non_zeros에 0이 아닌 개수 저장 
    if (3 * non_zeros < R * C) { // 0이 아닌 행, 열, 값의 공간을 가지므로 공간 복잡도 3*t 
        return true; // 1
    } else {
        return false; // 0
    }
}

/** print matrix */
// A[n][m] 저장방식 (1)이 유리 할 때 전치행렬 
void print_matrix()
{
    for (int y = 1; y <= R; y++) {
        for (int x = 1; x <= C; x++) {
            printf("%d ", A[y][x]);
        }
        printf("\n");
    }
}
// 희소 행렬 저장 방식(2)이 유리할 때 전치행렬
void print_dok_matrix()
{
    for (int y = 1; y <= R; y++) { //열행
        for (int x = 1; x <= C; x++) {
            if (A[y][x] != 0) {
                printf("%d %d %d\n", y, x, A[y][x]);   
            }
        }
    }
}

int main()
{
    /** input matrix */ 
    input_transpose_matrix(); // 행렬 입력 

    /** metric -> print matrix */  
    if (is_dok_effecient()) { 
        printf("2\n"); // return 1 -> 희소배열 저장 방식이 유리하므로 2 출력 
        print_dok_matrix(); // 희소 행렬 저장 방식(2)이 유리할 때 전치행렬
    }
    else {
        printf("1\n"); // return 0 -> A[n][m] 저장방식이 유리하므로 1 출력
        print_matrix(); 
    }
}