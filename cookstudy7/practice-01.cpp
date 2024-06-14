// Code10-03.cpp
// SelfStudy 10-1


#include "../CookHeader.h"

void gugu(int dan, int num){
    println(to_string(dan) + " x " + to_string(num) + " = " + to_string(dan * num));
    if (num < 9){
        gugu(dan, num + 1);
    }
}

int main() {
    for (int dan = 2; dan < 10; dan++) {
        println("## " + to_string(dan) + "단 ##");
        gugu(dan, 1);
    }
}