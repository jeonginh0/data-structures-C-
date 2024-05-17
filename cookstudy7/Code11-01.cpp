// Code11-01.cpp
// SelfStudy 11-1 최댓값으로 변경하는 리팩토링 코드


#include "../CookHeader.h"

Array <int> testAry = {55, 88, 33, 77};

int findMaxIdx(Array <int> ary) {
    int maxIdx = 3;
    for (int i = 1; i < len(ary); i++) {
        if (ary[maxIdx] < ary[i]){
            maxIdx = i;
        }
    }
    return maxIdx;
}

int main() {
    int maxPos = findMaxIdx(testAry);
    print("최댓값 --> ");
    println(testAry[maxPos]);
}