// 07_01.cpp
// 크기가 5칸인 큐의 생성과 데이터 3개 입력



#include "../CookHeader.h"

Array <string> queue = {"None", "None", "None", "None", "None"};
int front = -1; // 머리 
int rear = -1; // 꼬리 (++ 데이터 3개 입력을 위해 rear 변수를 늘림.)

int main() {
    rear++;
    queue[rear] = "화사";   // 배열의 첫 번째 자리에 화사 삽입
    
    rear++;
    queue[rear] = "솔라";   // 배열의 두 번째 자리에 솔라 삽입
    
    rear++;
    queue[rear] = "문별";   // 배열의 세 번째 자리에 문별 삽입

    println("------- 큐 상태 -------");
    print("[출구] <-- ");
    for (int i = 0; i < len(queue); i++) {
        print(queue[i]);
    }
    println("<-- [입구] ");
}