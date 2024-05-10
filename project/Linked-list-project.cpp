// linked-list project
// 단순연결리스트 응용문제 중 1번문제를 리팩토링한 코드 
// 이 프로그램은 총 5개의 정보(이름, 이메일)를 사용자로부터 입력받아 이메일 순서대로 정보를 출력하고 변경할 수 있는 프로그램입니다.

#include "../CookHeader.h"

typedef struct _Node {
    string data[2]; // 이름, 이메일
    struct _Node* link = NULL;
} Node;

Array <Node*> memory;
Node* head, *current, *pre;
int inputCount = 0; // 입력 받은 정보의 개수를 저장하는 변수


void printNodes(Node* start) {
    if(start == NULL) {
        return;
    }
    Node* current = start;
    print("[" + current -> data[0] + "," + current -> data[1] + "]");
    while (current -> link != NULL) {
        current = current -> link;
        print("[" + current -> data[0] + "," + current -> data[1] + "]");
    }
    println("");
}

void freeMemory() {
    for (int i = 0; i < len(memory); i++) {
        delete memory[i];
    }
}

void makeSimpleLinkedList(Array <string> nameEmail) {
    Node* node;
    node = new Node;
    node -> data[0] = nameEmail[0];
    node -> data[1] = nameEmail[1];
    memory.push_back(node);
    if(head == NULL) { // 첫 번째 노드일 때
        head = node;
        return;
    }
    if (head -> data[1] > nameEmail[1]) { // 첫 번째 노드보다 작을 때
        node -> link = head;
        head = node;
        return;
    }

    current = head;                     // 중간 모드로 삽입하는 경우
    while (current -> link != NULL) {
        pre = current;
        current = current -> link;
        if(current->data[0] > nameEmail[0]) {
            pre -> link = node;
            node -> link = current;
            return;
        }
    }

    current -> link = node;             // 삽입하는 노드가 가장 큰 경우
}

void updateNode(int position, string newName, string newEmail) {
    if (position < 1 || position > len(memory)) {
        println("잘못된 위치입니다.");
        return;
    }

    Node* current = head;
    for (int i = 1; i < position; i++) {
        current = current->link;
    }

    current->data[0] = newName;
    current->data[1] = newEmail;
}

int main() {
    string name, email;
    char update = 'y';
    println("이 프로그램은 총 5개의 정보(이름, 이메일)를 사용자로부터 입력받아 정보를 출력하고 변경할 수 있는 프로그램입니다.");
    while (update == 'y' || update == 'Y') {
        while (inputCount < 5) { // 총 5개의 정보만 입력받음
            input(name, "이름을 입력하세요: ");

            if (name == "x" || name == "X") {
                break;
            }
            input(email, "이메일을 입력하세요: ");
            makeSimpleLinkedList({ name, email });
            inputCount++;
        }

        // 5개의 정보를 입력받은 후 추가적인 입력은 불가능
        println(" ");
        println("<--입력된 정보 목록 출력-->");
        printNodes(head);
        println(" ");

        string userInput;// 사용자가 x, X를 입력할 수 있도록 문자열 변수 userInput 선언. if-else 문 내부에서 update를 위한 변수 형변환 예정.
        input(userInput, "수정할 위치 입력(1부터 " + to_string(inputCount) + "까지 (X/x: 종료)): ");

        if (userInput == "x" || userInput == "X") {
            println("<--입력된 정보 목록 출력-->");
            printNodes(head);

            println("프로그램을 종료합니다.");
            break;
        } else {
            int position = stoi(userInput);

            if((position >= 1 && position <= inputCount)) {
                string newName, newEmail;

                input(newName, "새로운 이름 입력: ");
                input(newEmail, "새로운 이메일 입력: ");
                println(" ");

                println("<--수정된 정보 목록 출력-->");
                updateNode(position, newName, newEmail);
                printNodes(head);

            } else {
                println("잘못된 위치입니다. 수정을 종료합니다.");
                println(" ");

                println("<--입력된 정보 목록 출력-->");
                printNodes(head);
            }  
        }
        println(" ");
        input(update, "계속해서 수정하시겠습니까? (Y/y: 계속, 다른 키: 종료): ");
    }
    freeMemory();
}