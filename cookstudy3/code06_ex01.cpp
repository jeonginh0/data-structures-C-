// SELF-STUDY 6-1
// 코드 리팩토링, isStackFull() 함수를 사용하지 않고 기능 구현


#include "../CookHeader.h"

int SIZE = 5;
Array <string> stack = {"커피", "녹차", "꿀물", "콜라", "None"};
int top = 3;

/* bool isStackFull(string data) {
    if (top >= SIZE - 1) {
        return true;
    } else {
        return false;
    }
} */

void push(string data) {
    if(top >= SIZE - 1) {
        println("스택이 꽉 찼습니다.");
    } else {
        top++;
        stack[top] = data;
    }
}

int main() {
    printArray(stack);
    push("환타");
    printArray(stack);
    push("게토레이");
}