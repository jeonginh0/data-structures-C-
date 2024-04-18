// 02_07.cpp
// 구조체, 구조체 배열, 구조체 포인터



using namespace std;
#include <iostream>
#include <vector>

#define Array vector
#define print(data) cout << data <<" ";

typedef struct _Node {  // Node 구조체 정의
    string data;
    struct _Node* link = NULL;
} Node;

Array <Node*> memory;   // Node* 구조체 형의 배열을 선언

int main() {
    Node* node1 = new Node; // Node* 형 구조체 변수 생성, 멤버 변수 data에 값을 대입.
    node1 -> data = "자료구조";
    
    Node* node2 = new Node;
    node2 -> data = "알고리즘";
    node1 -> link = node2;  // node1 의 멤버 변수 link에 node2를 대입.

    Node* node3 = new Node;
    node3 -> data = "C언어";
    node2 -> link = node3;

    memory.push_back(node1); // 가변 배열에 생성한 3개의 구조체 변수를 대입
    memory.push_back(node2);
    memory.push_back(node3);

    for (int i = 0; i < 3; i++) {   // 배열의 각 구조체 변수에 있는 멤버 변수 data를 출력한다.
        print(memory[i] -> data)
    }

    for (int i = 0; i < 3; i++) { // 배열 안의 구조체 변수를 해제한다.
    delete memory[i];
    }
}