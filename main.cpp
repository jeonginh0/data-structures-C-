#include "/Users/jeonginho/Desktop/cookcpp/CookHeader.h"

typedef struct _Node {
    string data[2];
    struct _Node* link = NULL;
} Node2;

Array <Node2*> memory;
Node2* head, * current, * pre;
Array <Array <string>> dataArray = {{"165.2", "지민"}, {"170.2", "정국"}, {"172.0", "뷔"}, {"169.7", "슈가"},{"174.4","진"}};

void printNodes2(Node2* start){
    if (start == NULL){
        return;
    }
    Node2* current = start;
    print("[" + current -> data[0] + "," + current -> data[1] + "]");
    while (current -> link != NULL){
        current = current -> link;
        print("[" + current -> data[0] + "," + current -> data[1] + "]");
    }
    println("");
}

void freeMemory() {
    for (int i = 0; i < len(memory); i++){
        delete memory[i];
    }
}

void makeSimpleLinkedList(Array <string> namePhone){
    printNodes2(head);

    Node2* node;
    node = new Node2;
    node -> data[0] = namePhone[0];
    node -> data[1] = namePhone[1];
    memory.push_back(node);
    if(head == NULL){
        head = node;
        return;
    }
    if(head -> data[0] > namePhone[0]){
        node -> link = head;
        head = node;
        return;
    }
    current = head;
    while (current -> link != NULL){
        pre = current;
        current = current -> link;
        if(current -> data[0] > namePhone[0]){
            pre -> link = node;
            node -> link = current;
            return;
        }
    }
}

int main() {
    for (int i = 0; i < len(dataArray); i++){
        makeSimpleLinkedList(dataArray[i]);
    }
    printNodes2(head);
    freeMemory();
}