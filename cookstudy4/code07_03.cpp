// 07_03.cpp
// 큐가 꽉 찼는지 확인하는 함수



#include "../CookHeader.h"

int SIZE = 5;
Array <string> queue = {"화사", "솔라", "문별", "휘인", "선미"};
int front = -1; // 머리
int rear = 4; // 꼬리

bool isQueueFull() {
    if (rear == SIZE - 1){ // 만약 꼬리가 SIZE - 1(4) 와 같다면 true를 반환
        return true;
    } else {
        return false; // 그렇지 않다면 false 를 반환
    }
}

int main() {
    print("큐가 꽉 찼는지 확인 --> ");
    println((isQueueFull() ? "true" : "false")); // 삼항연산자 | 0:false, 1:true 
    
    // 참이면 true, 거짓이면 false
}