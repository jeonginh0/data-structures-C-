// Code10-03.cpp
// SelfStudy 10-1


#include "../CookHeader.h"

// num1과 num2 사이의 숫자들을 더하는 재귀 함수
int addNumber(int num1, int num2) {
    if (num1 > num2) {
        return addNumber(num2, num1);
    }
    if (num1 == num2) {
        return num1;
    }
    return num1 + addNumber(num1 + 1, num2);
}

int main() {
    int num1;
    int num2;
    input(num1, "숫자1 --> ");
    input(num2, "숫자2 --> ");

    int result = addNumber(num1, num2);
    println(result);
    return 0;
}
