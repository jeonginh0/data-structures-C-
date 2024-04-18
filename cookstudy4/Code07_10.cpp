// 07_10.cpp
// 큐 작동을 위한 통합 코드 (리팩터링 후)



#include "../CookHeader.h"

int SIZE;
Array <string> queue;
int front = -1, rear = -1;

bool isQueueFull() {
    if (rear != SIZE - 1){ // 만약 꼬리가 SIZE - 1(4) 와 같다면 true를 반환
        return false;
    } else if ((rear == SIZE - 1) && (front == -1)) {
        return true;
    } else {
        for (int i = front + 1; i < SIZE; i++) {
            queue[i - 1] = queue[i];
            queue[i] = "None";
        }
        front --;
        rear --;
        return false;
    }
}

bool isQueueEmpty() {
    if (front == rear) {
        return true;
    } else {
        return false;
    }
}

void enQueue(string data) {
    if (isQueueFull()) {
        println("큐가 꽉 찼습니다.");
        return;
    }
    rear++;
    queue[rear] = data;
}

string deQueue() {
    if (isQueueEmpty()) {
        println("큐가 비었습니다.");
        return "None";
    }
    front ++;
    string data = queue[front];
    queue[front] = "None";
    return data;
}

string peek() {
    if (isQueueEmpty()){
        println("큐가 비었습니다.");
        return "None";
    }
    return queue[front + 1];
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
            break;
        case 'E':
        case 'e':
            data = deQueue();
            println("추출한 데이터 --> " + data);
            print("큐 상태 : ");
            printArray(queue);
            break;
        case 'V':
        case 'v':
            data = peek();
            println("다음에 나올 데이터 확인 --> " + data);
            printArray(queue);
            break;
        default:
            println("입력이 잘못됨");
        }
        input(select, "삽입(I) / 추출(E) / 확인(V) / 종료(X) 중 하나를 선택 ==> ");
    }
    println("프로그램 종료");
}

