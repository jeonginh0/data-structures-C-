// 07_02.cpp
// 큐에서 데이터 3개 추출



#include "../CookHeader.h"

Array <string> queue = {"화사", "솔라", "문별", "None", "None"};
int front = -1; // 머리 (++ 머리를 증가시켜 값을 None으로 바꾸고 데이터를 삭제한다.)
int rear = 2; // 꼬리

int main() {
    println("-------------------- 큐 상태 --------------------");
    print("[출구] <-- ");
    for (int i = 0; i < len(queue); i++) {
        print(queue[i]);
    }
    println("<-- [입구] ");
    println("-------------------------------------------------");

    string data;
    
    front++;
    data = queue[front];
    queue[front] = "None";
    println("deQueue --> " + data);


    front++;
    data = queue[front];
    queue[front] = "None";
    println("deQueue --> " + data);

    front++;
    data = queue[front];
    queue[front] = "None";
    println("deQueue --> " + data);
    println("-------------------------------------------------");

    println("-------------------- 큐 상태 --------------------");
    print("[출구] <-- ");
    for (int i = 0; i < len(queue); i++) {
        print(queue[i]);
    }
    println("<-- [입구] ");
}