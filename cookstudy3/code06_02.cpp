#include "../CookHeader.h"

Array<string> stack = {"커피", "녹차", "꿀물", "None", "None"};
int top = 2;

int main() {
    println("-----스택 상태-----");
    for (int i = len(stack) - 1; i > -1; i--) {
        println(stack[i]);  // stack의 각 원소를 출력
    }

    string data;
    println("-------------------");
    data = stack[top];
    stack[top] = "None";
    top --;
    println("pop --> "+ data);

    data = stack[top];
    stack[top] = "None";
    top --;
    println("pop --> " + data);

    data = stack[top];
    stack[top] = "None";
    top --;
    println("pop --> " + data);
    println("-------------------");

    println("-----스택 상태-----");
    for (int i = len(stack) - 1; i > -1; i--) {
        println(stack[i]);  // stack의 각 원소를 출력
    }
}
