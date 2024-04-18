#include "/Users/jeonginho/Desktop/cookcpp/CookHeader.h"

typedef struct _Node {
    string data[2];
    struct _Node* link = NULL;
} Node2;

Array<Node2*> memory;
Node2* head = NULL;
Array<Array<string>> dataArray = {{"지민", "180"}, {"정국", "177"}, {"뷔", "183"}, 
                                {"슈가", "175"}, {"진","179"}};

void printNodes2(Node2* start) {
    if (start == NULL) {
        return;
    }
    Node2* current = start;
    print("[" + current->data[0] + "," + current->data[1] + "]");
    while (current->link != NULL) {
        current = current->link;
        print("[" + current->data[0] + "," + current->data[1] + "]");
    }
    println("");
}

void freeMemory() {
    for (int i = 0; i < len(memory); i++) {
        delete memory[i];
    }
}

void makeSimpleLinkedList(Array<string> nameHeight) {
    printNodes2(head);

    Node2* node = new Node2;
    node->data[0] = nameHeight[0];  // 이름
    node->data[1] = nameHeight[1];  // 키
    memory.push_back(node);
    if (head == NULL) {
        head = node;
        return;
    }
    if (head->data[1] > nameHeight[1]) { // 키 오름차순 정렬
        node->link = head;
        head = node;
        return;
    }
    Node2* current = head;
    Node2* pre = NULL;
    while (current->link != NULL) {
        pre = current;
        current = current->link;
        if (current->data[1] > nameHeight[1]) {
            pre->link = node;
            node->link = current;
            return;
        }
    }
    current->link = node;
}

int main() {
    
    for (int i = 0; i < len(dataArray); i++) {
        makeSimpleLinkedList(dataArray[i]);
    }
    printNodes2(head);
    freeMemory();

    return 0;
}
