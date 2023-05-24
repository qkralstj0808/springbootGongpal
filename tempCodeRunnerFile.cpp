#include <iostream>
using namespace std;

class Node { // 연결리스트 노드 클래스 
public:
    int data; // 노드가 저장하는 데이터 
    Node* next; // 다음 노드를 가리키는 포인터 

    Node(int data = 0, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};




class LinkedList { // 연결 리스트 클래스 
public:
    Node* head; // 첫 번째 노드 

    LinkedList() {
        head = nullptr;
    }

    void insert(int data) { // 주어진 데이터를 연결 리스트에 삽입
        Node* new_node = new Node(data); 
        if (head == nullptr) {
            head = new_node;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    void reverse_print() { // 연결 리스트의 데이터를 거꾸로 출력
        Node* current = head;
        int values[1000], i = 0;
        while (current != nullptr) {
            values[i++] = current->data;
            current = current->next;
        }
        for (int j = i - 1; j >= 0; j--) {
            cout << values[j] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n; // 입력할 데이터의 개수 x
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        LinkedList ll;
        for (int j = 0; j < x; j++) {
            int data;
            cin >> data;
            ll.insert(data);
        }
        cout << "case " << i + 1 << endl;
        ll.reverse_print();
    }
    return 0;
}