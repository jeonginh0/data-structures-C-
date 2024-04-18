// 06_04(응용).cpp
// 스택 완성



#include "../CookHeader.h"

int SIZE;
Array <string> stack;
int top = -1;

bool isStackFull() {
    if (top >= SIZE - 1) {
        return true;
    } else {
        return false;
    }
}

bool isStackEmpty() {
    if (top == -1) {
        return true;
    } else {
        return false;
    }
}

void push(string data) {
    if (isStackFull()) {
        println("스택이 꽉 찼습니다.");
        return;
    }
    top++;
    stack[top] = data;
}

string pop() {
    if (isStackEmpty()) {
        println("스택이 비었습니다.");
        return "None";
    }
    string data = stack[top];
    stack[top] = "None";
    top--;
    return data;
}

string peek() {
    if(isStackEmpty()) {
        println("스택이 비었습니다.");
        return "None";
    }
    return stack[top];
}

int main() {
    input(SIZE, "스택 크기를 입력하세요 ==> ");
    for (int i = 0; i < SIZE; i++) {
        stack.push_back("None");
    }

    char select;
    input(select, "삽입(I) / 추출(E) / 확인(V) / 종료(X) 중 하나를 선택 ==> ");

    string data;
    while (select != 'X' && select != 'x') {
        switch (select)
        {
        case 'I':
        case 'i':
            input(data, "입력할 데이터 --> ");
            push(data);
            print("스택 상태 : ");
            printArray(stack);
            break;
        case 'E':
        case 'e':
            data = pop();
            println("추출한 데이터 --> " + data);
            print("스택 상태 : ");
            printArray(stack);
            break;
        case 'V':
        case 'v':
            data = peek();
            println("top의 데이터 확인 --> " + data);
            printArray(stack);
            break;
        default :
            println("입력이 잘못됨.");
        }
        input(select, "삽입(I) / 추출(E) / 확인(V) / 종료(X) 중 하나를 선택 ==> ");
    }
    println("프로그램 종료");
}