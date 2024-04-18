// SELF STUDY 6-2
// 코드 리팩토링, isStackEmpty() 함수를 사용하지 않고 코드 구현



#include "../CookHeader.h"

int SIZE = 5;
Array <string> stack = {"커피", "None", "None", "None", "None"}; // 스택 5개 생성
int top = 0; // 최상위 값 위치

/* bool isStackEmpty() {
    if (top == -1) {
        return true;
    } else {
        return false;
    }
} */

string pop() {
    if (top == -1) {    // 만약 최상위 위치가 -1이라면
        println("스택이 비었습니다."); 
        return "None";
    }
    else {  // 그렇지 않다면
        string data = stack[top];   
        stack[top] = "None";
        top --;
        return data;
    }
}

int main() {
    string retData;
    printArray(stack);
    retData = pop();
    println("추출한 데이터 --> " + retData);
    printArray(stack);
    retData = pop();
}