#include    <iostream>

/** 선택정렬 함수 */
void sort(int A[], int N)
{
    int tmp;    // 교환을 위한 임시 변수 temp

    for (int i = 0; i < N; i++) {
        int min = i;
        for (int j = i; j < N; j++)
            if (A[j] < A[min])      min = j;
        std::swap(A[i], A[min]); //라이브러리 함수 값교환 
    }
}

/** 배열 A에 대한 이원탐색 함수 
 * left ... right-1] 리턴값은 X 의 인덱스*/
int search(int X, int A[], int left, int right)
{
    if (X == A[left])
        return left;
    if (left + 1 == right)
        return -1;

    int mid = (left + right) / 2;
    if (X < A[mid])
        return search(X, A, left, mid);
    else
        return search(X, A, mid, right);
}

/** 배열 A를 출력하는 함수 [left ... right-1] */
void print(int A[], int left, int right)
{
    for (int i = left; i < right; i++)
        std::cout << A[i] << ' ';
    std::cout << std::endl;
}

int main()
{
    int N, X; //사용자로부터 입력 받을 N의 개수와 정수 X를 입력받을 변수
    std::cin >> N >> X;

    int A[N]; // 수열 A 변수 선언 
    for (int i = 0; i < N; i++) 
        std::cin >> A[i]; // 배열 A

    /** selection sort */
    sort(A, N); // sort 함수에 매개인자로 배열 A와 정수 N개를 넘김 
    //print(A, 0, N);       // for debugging

    /** binary search for X */
    int idx = search(X, A, 0, N);
    if (idx == -1) {
        std::cout << "Error" << std::endl;
        return 1;
    }

    /** print subsequent elements for X */
    print(A, idx + 1, N);
    
    return 0;
}