// CodePractice01

#include "../CookHeader.h"

typedef struct _Node {
    string data;
    struct _Node* link = NULL;
} Node;

Array <Node*> memory;

int main() {
    Array <Array <string>> grade = { {"수학", "90"}, {"영어", "70"}, {"과학", "88"} };
    grade.push_back({"역사", "75"});
    printArray2(grade);

    Array <Array <int>> empArray = emptyArray2(3, 4);
    printArray2(empArray);
    
    // 구조체
    Node* node1 = new Node;
    node1 -> data = "자료구조";

    Node* node2 = new Node;
    node2 -> data = "알고리즘";
    node1 -> link = node2;

    Node* node3 = new Node;
    node3 -> data = "C언어";
    node2 -> link = node3;

    memory.push_back(node1);
    memory.push_back(node2);
    memory.push_back(node3);

    for (int i = 0; i < 3; i++){
        print(memory[i] -> data);
    }

    for (int i = 0; i < 3; i++){
        delete memory[i];
    }
}