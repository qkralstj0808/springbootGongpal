#include <iostream>

using namespace std;

void sort(int *a, const int n);
int binarySearch(int *a, const int x, const int n); // 찾고자 하는 값, 배열의 크기는 달라지면 안되기 때문에 const , 함수가 int라면 반환값을 어떤 뱐수에 담아야 함 

int main()
{
    const int N = 10;

    //n개의 데이터를 가지는 배열 a를 선언하고, 임의의 데이터 n개로 초기화
    int a[N] = {5,6,7,8,9,10,1,2,3,4};
    //탐색할 데이터 입력, 탐색 결과를 반환하는 변수 선언
    int data, res;

    //탐색할 데이터 입력받아서 data 변수에 저장
    cout << "탐색할 데이터를 입력 : ";
    cin >> data;
    
    //정의한 배열과 데이터 갯수를 인자로 하여 정렬 함수 호출
    sort (a, N); 

    for(int i = 0 ; i <10 ; i++) { // (debugging)
        cout << a[i] << endl;
    }

    //정렬을 마친 배열과 탐색하고자 하는 데이터(값), 그리고 데이터 갯수를 인자로 하여 탐색 함수 호출
    //반환값은 선언한 결과 변수에 저장
    res = binarySearch(a,data,N); //  x는 찾고자 하는  data 
    

    //정렬된 배열을 띄어쓰기 하면서 출력
    for(int i = 0; i < N; i++)
        cout << a[i] << " ";
    cout << endl;

    //조건문을 통해서 출력을 조절
    //데이터를 찾지 못하면 -1이 반환되기 때문에, 결과값이 0보다 작으면 데이터 탐색 실패에 대한 메시지 출력
    if(res >= 0)
        cout << "데이터 " << data << "의 위치는 " << res  << "입니다." << endl;
    else
        cout << "데이터 " << data << "는 배열에 존재하지 않습니다." << endl;
}

/*
    1. 리스트의 첫 번째 위치를 선택합니다.
    2. 그 위치부터 시작하여 리스트 내의 모든 값을 탐색합니다.
    3. 탐색하면서 가장 작은 값을 찾아서 첫 번째 위치의 값과 교체합니다.
    4. 다음 위치를 선택하고, 위의 과정을 반복합니다.
    5. 모든 위치를 탐색한 후, 정렬이 완료됩니다.
*/

void sort(int *a, const int n) //정의. main에서 배열을 넘겨받았다는 것을 알 수 있음
{
    //메인함수에서 정의한 배열을 참조 호출로 가져옴
    //n개의 데이터로 이루어진 배열 a에 대해서 선택정렬 알고리즘 수행
    //강의자료 슬라이드 8 참조
    for(int i=0; i<n; i++) // i = location
    {
        int j = i;  //j=i=0  -> 가장 작은 수, 가장 작은 수의 위치 
        // a[i]와 a[n-1] 사이에 가장 작은 정수를 찾는다 (비교)
        for (int k=i+1; k<n; k++){  
            if(a[k] < a[j]) {
                j = k;
            }
        }
        // 교환
        swap(a[i], a[j]);
    }
}

/*
    1. 배열(a)의 첫 번째 인덱스(left)와 마지막 인덱스(right)를 정의합니다.
    2. 배열(a)의 중간 인덱스(middle)를 찾습니다. middle = (left + right) / 2
    3. 중간 인덱스(middle)의 데이터를 확인합니다.
    4. 찾고자 하는 데이터(x)가 중간 인덱스(middle)의 데이터보다 작다면, 배열(a)의 왼쪽 절반에서 데이터를 찾아나갑니다. 따라서, right = middle -   1로 갱신합니다.
    5.  찾고자 하는 데이터(x)가 중간 인덱스(middle)의 데이터보다 크다면, 배열(a)의 오른쪽 절반에서 데이터를 찾아나갑니다. 따라서, left = middle + 1로 갱신합니다.
    6. 찾고자 하는 데이터(x)가 중간 인덱스(middle)의 데이터와 같다면, 해당 위치(middle)를 반환합니다.
    7. 위 과정을 반복하며 데이터를 찾을 때까지 탐색합니다.

*/

// 이원탐색(Binary Search)은 정렬된 데이터에서 탐색하는 알고리즘으로, 데이터의 중간값을 기준으로 탐색 범위를 반으로 줄여가며 원하는 값을 찾는 방법이다. 

int binarySearch(int *a, const int x, const int n)
{
    //메인함수에서 정의하고, sort 함수를 통해서 정렬한 배열을 참조 호출로 가져옴
    //n개의 데이터로 이루어진 배열 a에 대해서, 데이터 x를 찾는 이원탐색 알고리즘 수행
    //강의자료 슬라이드 22 참조
    
    // 정렬된 배열 a[0],...a[n-1]에서 x를 탐색 
    int left = 0;  // 첫 번쨰 인덱스 
    int right = n-1; // 마지막 인덱스 

    while (left <= right) 
    {
         int middle = (left + right)/2; 
         if(x < a[middle]) right = middle - 1; // 찾고자 하는 데이터(x)가 중간 인덱스(middle)의 데이터보다 작다면, 배열(a)의 왼쪽 절반에서 데이터를 찾아나갑니다. 따라서, right = middle -   1
         else if(x>a[middle]) left = middle + 1;
         else return middle; // 찾았을 때 true 즉, middle 반환 
    }   
    return -1; 
}