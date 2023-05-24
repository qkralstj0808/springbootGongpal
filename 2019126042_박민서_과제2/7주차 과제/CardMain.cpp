#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

// 카드 클래스
class Card {
public:
    char suit;  // 카드 모양 (S, D, H, C)
    int num;    // 카드 번호 (1~13)
    
    Card(char _suit, int _num) : suit(_suit), num(_num) {}
};

// deque 클래스
class MyDeque {
private:
    deque<Card> dq;  // deque 내부에 카드를 저장
public:
    void push(Card card) {
        // deque가 비어있으면 맨 앞에 카드 추가
        if (dq.empty()) {
            dq.push_front(card);
            return;
        }
        
        // 양 끝 카드와의 거리 계산
        int front_dist = card.num - dq.front().num;
        int back_dist = dq.back().num - card.num;
        
        // 거리가 동일할 경우
        if (front_dist == back_dist) {
            // push 방향에 제약 없음 -> front 쪽에 추가
            dq.push_front(card);
        } else if (front_dist < back_dist) {
            // 앞쪽 카드와의 거리가 더 가까우면 front 쪽에 추가
            dq.push_front(card);
        } else {
            // 뒤쪽 카드와의 거리가 더 가까우면 back 쪽에 추가
            dq.push_back(card);
        }
    }
    
    void sort() {
        std::sort(dq.begin(), dq.end(), [](const Card& a, const Card& b) {
            if (a.suit == b.suit) return a.num < b.num;
            else {
                if (a.suit == 'S') return true;
                else if (b.suit == 'S') return false;
                else if (a.suit == 'D') return true;
                else if (b.suit == 'D') return false;
                else if (a.suit == 'H') return true;
                else return false;
            }
        });
    }
    
    void print() {
        for (auto card : dq) {
            if (card.suit == 'S') cout << "♠";
            else if (card.suit == 'D') cout << "◆";
            else if (card.suit == 'H') cout << "♥";
            else cout << "♣";
            
            cout << card.num << " ";
        }
        cout << endl;
    }
};

int main() {
    int N;
    cin >> N;
    
    MyDeque mydeque;
    
    for (int i = 0; i < N; i++) {
        char suit;
        int num;
        cin >> suit >> num;
        Card card(suit, num);
        mydeque.push(card);
        mydeque.sort();
        mydeque.print();
    }
    
    return 0;
}
