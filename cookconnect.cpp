#include "/Users/jeonginho/Desktop/cookcpp/CookHeader.h"

typedef struct _Node {
    int data;
    struct _Node* link = NULL;
} Node;

Array <Node*> memory;
Node* head, * current, * pre;

void printNodes(Node* start){
    if(start == NULL) {
        return;
    }
    Node* current = start;
    print(current -> data);
    while (current -> link != start) {
        current = current -> link;
        print(current -> data);
    }
    println("");
}

void freeMemory() {
    for (int i = 0; i < len(memory); i++){
        delete memory[i];
    }
}

Array <int> countOddEven() {
    Array <int> retData;
    int odd = 0, even = 0;

    current = head;
    while(true) {
        if(current -> data % 2 != 0){
            odd ++;
        }
        else{
            even ++;
        }
        if(current -> link == head){
            break;
        }
        current = current -> link;
    }
    retData = {odd, even};
    return retData;
}

void makeZeroNumber(int odd, int even) {
    int reminder;
    if(odd > even){
        reminder = 1;
    }
    else{
        reminder = 0;
    }

    current = head;
    while(true) {
        if(current -> data % 2 == reminder){
            current -> data *= -1;
        }
        if(current -> link == head){
            break;
        }
        current = current -> link;
    }
}

int main() {
    randomInit(1, 100);

    Array <int> dataArray;
    for(int i = 0; i < 7; i++){
        dataArray.push_back(cookRandom(gen));

        Node* node = new Node;
        node -> data = dataArray[0];
        head = node;
        node -> link = head;
        memory.push_back(node);

        for(int i = 1; i < len(dataArray); i++){
            int data = dataArray[i];
            pre = node;
            node = new Node;
            node -> data = data;
            pre -> link = node;
            node -> link = head;
            memory.push_back(node);
        }

        Array <int> retCount = countOddEven();
        int oddCount = retCount[0];
        int evenCount = retCount[1];

        println("양수 개수 -->" + to_string(oddCount));
        println("음수 개수 -->" + to_string(evenCount));
        
        makeZeroNumber(oddCount, evenCount);
        printNodes(head);

        freeMemory();
    }
}