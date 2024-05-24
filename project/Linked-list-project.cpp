// linked-list project
// 단순연결리스트 응용문제 중 1번문제를 리팩토링한 코드 
// 이 프로그램은 총 5개의 정보(이름, 이메일)를 사용자로부터 입력받아 이메일 순서대로 정보를 출력하고 변경할 수 있는 프로그램입니다.

#include "../CookHeader.h"

typedef struct _Node { // 구조체 선언
    string data[2]; // 이름, 이메일을 받는 문자형 변수
    struct _Node* link = NULL; // 노드간 연결을 위한 link 포인터 _Node형 변수
} Node;

Array <Node*> memory; // 구조체 포인터 배열 메모리 선언
Node* head, *current, *pre; // 구조체 포인터형 head, current(현재), pre(이전) 변수 선언
int inputCount = 0; // 입력 받은 정보의 개수를 저장하는 변수


void printNodes(Node* start) {

    // 시작 노드가 NULL이면 함수 종료
    if(start == NULL) {
        return;
    }
    Node* current = start; // 현재 노드를 시작 노드로 지정.

    // 시작 노드부터 시작해서 연결된 모든 노드의 데이터를 출력
    print("[" + current -> data[0] + "," + current -> data[1] + "]");
    while (current -> link != NULL) { //while 루프는 현재 노드의 link가 NULL이 아닐동안에만 반복
        current = current -> link; // 다음 노드로 이동
        print("[" + current -> data[0] + "," + current -> data[1] + "]"); // 다음 노드로 이동 후 해당 노드의 데이터를 출력.
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
    node = new Node; // 새로운 노드 생성
    node -> data[0] = nameEmail[0]; // 이름 저장
    node -> data[1] = nameEmail[1]; // 이메일 저장
    memory.push_back(node); // 생성된 노드를 메모리에 추가
    if(head == NULL) { // 첫 번째 노드일 때
        head = node;
        return;
    }
    if (head -> data[1] > nameEmail[1]) { // 첫 번째 노드보다 작을 때
        node -> link = head;
        head = node;
        return;
    }

    current = head;                     // 중간으로 삽입하는 경우
    while (current -> link != NULL) { // 다음 노드가 NULL이 아닐때 까지 반복
        pre = current; // 현재 노드를 이전 노드로 설정
        current = current -> link; // 현재 노드는 다음 노드로 설정
        if(current->data[0] > nameEmail[0]) { // 현재 노드의 이름이 새로 삽입하려는 노드의 이름보다 큰 경우
            pre -> link = node; // 이전 노드와 새로운 노드를 연결 
            node -> link = current; // 새로운 노드와 현재 노드를 연결
            return;
        }
    }

    current -> link = node;             // 삽입하는 노드가 가장 큰 경우
}

void updateNode(int position, string newName, string newEmail) {
    if (position < 1 || position > len(memory)) { // position이 1보다 작거나 리스트의 길이보다 크다면 종료.
        println("잘못된 위치입니다.");
        return;
    }

    Node* current = head;
    for (int i = 1; i < position; i++) { // 위치가 유효한 경우 업데이트할 노드를 찾기위해 순회진행
        current = current->link;
    }

    // 위치를 찾은 후, 함수는 해당 노드의 데이터를 새로운 이름 newName, 새로운 이메일 newEmail로 업데이트.
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