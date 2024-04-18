// 07_04.cpp
// 큐에 데이터를 삽입하는 함수



#include "../CookHeader.h"

int SIZE = 5;
Array <string> queue = {"화사", "솔라", "문별", "휘인", "None"}; // rear ++
int front = -1; 
int rear = 3;

bool isQueueFull() {
    if (rear == SIZE - 1){
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
    rear ++;
    queue[rear] = data;
}

int main() {
    printArray(queue);
    enQueue("선미");
    printArray(queue);
    enQueue("재남");
}
