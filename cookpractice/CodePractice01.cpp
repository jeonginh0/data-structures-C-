// CodePractice01

#include "../CookHeader.h"

int main() {
    Array <int> myAry = { 10, 20, 30 };
    myAry.push_back(40);

    printArray(myAry);
    println("배열 크기 --> " + to_string(len(myAry)));
    del(myAry, 2);
    printArray(myAry);
}