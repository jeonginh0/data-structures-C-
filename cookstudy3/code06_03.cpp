// 06_03.cpp
// 스택에서 top 위치의 데이터를 확인하는 함수



#include "../CookHeader.h"

int SIZE = 5;
Array <string> stack = {"커피", "녹차", "꿀물", "None", "None"};
int top = 2;

bool isStackEmpty() {
    if(top == -1) {
        return true;
    } else {
        return false;
    }
}

string peek() {
    if (isStackEmpty()) {
        println("스택이 비었습니다.");
        return "None";
    }
    return stack[top];
}

int main() {
    string retData;
    printArray(stack);
    retData = peek();
    println("top의 데이터 확인 --> " + retData);
    printArray(stack);
}