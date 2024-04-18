#include "/Users/jeonginho/Desktop/cookcpp/CookHeader.h"

// 노드 구조체 정의
typedef struct _Node {
    int data;                // 노드의 데이터
    struct _Node* link = NULL; // 다음 노드를 가리키는 포인터. 초기값은 NULL
} Node;

Array <Node*> memory;       // 메모리 관리를 위한 배열
Node* head, * current, * pre; // 헤드 노드와 현재 노드, 이전 노드를 가리키는 포인터

// 원형 연결 리스트의 노드들을 출력하는 함수
void printNodes(Node* start) {
    if (start == NULL)
        return;
    Node* current = start;
    print(to_string(current -> data) + " ");
    while (current -> link != start) {
        current = current -> link;
        print(to_string(current -> data) + " ");
    }
    println("");
}

// 동적 할당된 메모리를 해제하는 함수
void freeMemory() {
    for (int i = 0; i < len(memory); i++)
        delete memory[i];
}

// 원형 연결 리스트에서 양수와 음수의 개수를 세는 함수
Array <int> countPositiveNegative() {
    Array <int> retData;
    int positive = 0, negative = 0;

    current = head;
    do {
        if (current->data > 0) {
            positive++; // 양수 개수 증가
        }
        else if (current->data < 0) {
            negative++; // 음수 개수 증가
        }
        current = current->link;
    } while (current != head);

    retData = { positive, negative };
    return retData;
}

// 원형 연결 리스트의 노드들을 양수 또는 음수로 변경하는 함수
void changesPosNetNumber(int positive, int negative) {
    int sign;
    
    // 양수가 더 많으면 1, 음수가 더 많으면 -1
    if(positive >= negative) {
        sign = 1;
    }else{
        sign = -1;
    }
    current = head;

    do {
        // 양수인 경우와 음수인 경우에 따라 부호를 변경
        if (current -> data > 0 && sign < 0) {
            current -> data *= -1;
        } else if (current -> data < 0 && sign > 0) {
            current -> data *= -1;
        }
        current = current->link;
    } while (current != head);
}

int main() {
    randomInit(-100, 100);  // 랜덤 함수 초기화, -100부터 100까지의 숫자 생성

    Array <int> dataArray;
    for (int i = 0; i < 7; i++){
        dataArray.push_back(cookRandom(gen)); // 랜덤 숫자 7개를 생성하여 배열에 저장
    }

    Node* node = new Node; // 첫 번째 노드 생성
    node -> data = dataArray[0]; // 첫 번째 노드에 데이터 저장
    head = node; // 헤드 노드로 설정
    node -> link = head; // 첫 번째 노드가 자기 자신을 가리키도록 설정
    memory.push_back(node); // 메모리 배열에 첫 번째 노드 포인터 추가

    for (int i = 1; i < len(dataArray); i++) {
        int data = dataArray[i];
        pre = node;
        node = new Node; // 새로운 노드 생성
        node -> data = data; // 노드에 데이터 저장
        pre -> link = node; // 이전 노드의 링크가 새로운 노드를 가리키도록 설정
        node -> link = head; // 새로운 노드가 헤드를 가리키도록 설정
        memory.push_back(node); // 메모리 배열에 새로운 노드 포인터 추가
    }

    print("원래 숫자 -->");
    printNodes(head); // 원래 숫자 출력

    Array <int> retCount = countPositiveNegative();
    int positiveCount = retCount[0];
    int negativeCount = retCount[1];

    println("양수 개수 -->" + to_string(positiveCount));
    println("음수 개수 -->" + to_string(negativeCount));

    changesPosNetNumber(positiveCount, negativeCount); // 양수와 음수의 개수에 따라 노드들을 양수 또는 음수로 변경

    print("변경 숫자 -->");
    printNodes(head); // 변경된 숫자 출력

    freeMemory(); // 동적 할당된 메모리 해제
}