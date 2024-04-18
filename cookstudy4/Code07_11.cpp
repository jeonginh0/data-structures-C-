// 07_11.cpp
// 원형 큐 작동 통합 코드



#include "../CookHeader.h"

int SIZE;
Array <string> queue;
int front = 0, rear = 0;

bool isQueueFull() {
    if ((rear + 1) % SIZE == front) {
        return true;
    } else {
        return false;
    }
}

bool isQueueEmpty() {
    if (front == rear){
        return true;
    } else {
        return false;
    }
}

void enQueue(string data) {
    if (isQueueFull) {
        println("큐가 꽉 찼습니다.");
        return;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = data;
}

string deQueue() {
    if (isQueueEmpty()) {
        println("큐가 비었습니다.");
        return "None";
    }
    front = (front + 1) % SIZE;
    string data = queue[front];
    queue[front] = "None";
    return data;
}

string peek() {
    if (isQueueEmpty()) {
        println("큐가 비었습니다.");
        return "None";
    }
    return queue[(front + 1) % SIZE];
}

int main() {
    input(SIZE, "큐 크기를 입력하세요 ==> ");
    for (int i = 0; i < SIZE; i++) {
        queue.push_back("None");
    }
    
    char select;
    input(select, "삽입(I) / 추출(E) / 확인(V) / 종료(X) 중 하나를 선택 ==> ");

    string data;
    while (select != 'X' && select != 'x') {
        switch (select) {
        case 'I':
        case 'i':
            input(data, "입력할 데이터 --> ");
            enQueue(data);
            print("큐 상태 : ");
            printArray(queue);
            printArray("front : " + to_string(front) + ", rear : " + to_string(rear));
            break;
        case 'E':
        case 'e':
            data = deQueue();
            println("추출한 데이터 --> " + data);
            print("큐 상태 : ");
            printArray(queue);
            printArray("front : " + to_string(front) + ", rear : " + to_string(rear));
            break;
        case 'V':
        case 'v':
            data = peek();
            println("다음에 나올 데이터 확인 --> " + data);
            printArray(queue);
            printArray("front : " + to_string(front) + ", rear : " + to_string(rear));
            break;
        default:
            println("입력이 잘못됨");
        }
        input(select, "삽입(I) / 추출(E) / 확인(V) / 종료(X) 중 하나를 선택 ==> ");
    }
    println("프로그램 종료");
}