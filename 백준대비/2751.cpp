// N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
// 첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수가 주어진다. 이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.
// 첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
#include <iostream> 
#include <algorithm>
using namespace std;

int num[1000000];   // 배열의 크기가 크므로 전역범위에서 선언

int main() {
	int N;          // 수의 개수
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	sort(num, num + N); // num의 첫 번째 요소부터 N개의 요소를 오름차순으로 정렬

	for (int i = 0; i < N; i++) { 
		cout << num[i] << "\n";
	}

	return 0;

}