#include "/Users/jeonginho/Desktop/cookcpp/CookHeader.h"

typedef struct _Node {
    string data;
    struct _Node* link = NULL;
} Node;

Array <Node*> memory;
Node* head, * current, * pre;
Array <string> dataArray = {"다현","정연","쯔위","사나","지효"};

void printNodes(Node* start){
    if (start == NULL) {
        return;
    }
    Node* current = start;
    print(current -> data);
    while(current -> link != NULL){
        current = current -> link;
        print(current -> data);
    }
    println("");
}

void freeMemory() { // 할당된 모든 노드의 메모리를 해제한다.
    for (int i = 0; i < len(memory); i++){
        delete memory[i];
    }
}
int main(){ 
    Node* node = new Node;
    node -> data = dataArray[0];
    head = node;
    memory.push_back(node);

    for (int i = 1; i < len(dataArray); i++) {
        string data = dataArray[i]; // 연결리스트에 저장할 데이터 추출
        pre = node; // 현재 노드를 이전 노드로 저장
        node = new Node;
        node -> data = data;
        pre -> link = node;
        memory.push_back(node);
    }

    printNodes(head);
    freeMemory();

}