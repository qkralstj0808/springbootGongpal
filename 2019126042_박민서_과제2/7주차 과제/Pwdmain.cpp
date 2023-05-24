#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> q; // 큐

    for(int i = 0; i<8; i++){
        int num;
        cin>>num;
        q.push(num);
    }

    int cnt = 1; // 1부터 순차적으로 감소시켜야 하기 때문에 cnt = 1로 초기화 
    while(!q.empty()){
        int front = q.front(); // 최상위 데이터 반환 
        q.pop();
        front -= cnt;
        
        if (front < 0) front = 0; // 0보다 작아지는 경우 0
        q.push(front);

        cnt++;
        if (cnt > 5) cnt = 1;  // cnt=6 부터는 다시 cnt가 1로 초기화 
        if(q.front()== 0) break;

    }
    cout << "#";
    while (!q.empty()){
        cout << q.front() << " ";
        q.pop();

    }
    cout <<endl;

    return 0;
}



