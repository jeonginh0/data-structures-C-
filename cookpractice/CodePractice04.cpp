// CodePractice04

#include "../CookHeader.h"

typedef struct _Node {
    string data;
    struct _Node* link = NULL;
} Node;

void insert_data(int position, string data) {

}


int main() {
    Node* head;
    Node* node1 = new Node;
    node1 -> data = "다현";
    head = node1;

    Node* node2 = new Node;
    node2 -> data = "쯔위";
    node1 -> link = node2;

    Node* node3 = new Node;
    node3 -> data = "유나";
    node2 -> link = node3;

    Node* node4 = new Node;
    node4 -> data = "카리나";
    node3 -> link = node4;

    Node* node5 = new Node;
    node5 -> data = "윈터";
    node4 -> link = node5;

    Node* newNode = new Node;
    newNode -> data = "인호";
    newNode -> link = node3 -> link;
    node3 -> link = newNode;

    node3 -> link = node4 -> link;
    delete node4;

    Node* current = head;
    print(current -> data);
    while(current -> link != NULL) {
        current = current -> link;
        print(current -> data);
    }
}