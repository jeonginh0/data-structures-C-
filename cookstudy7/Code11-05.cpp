// Code11-05.cpp
// 삽입 정렬의 구현


#include "../CookHeader.h"

Array <int> before = {188, 162, 168, 120, 50, 150, 177, 105};
Array <int> after = {};
Array <int> testAry = {};

int findInsertIdx(Array <int> ary, int data) {
    int findIdx = -1;
    for (int i = 0; i < len(ary); i++) {
        if (ary[i] > data) {
            findIdx = i;
            break;
        }
    }
    if (findIdx == -1) {
        return len(ary);
    } else {
        return findIdx;
    }
}

int main() {
    print("정렬 전 --> ");
    printArray(before);
    int arySize = len(before);

    for(int i = 0; i < arySize; i++) {
        int data = before[i];
        int insPos = findInsertIdx(after, data);
        print("진행 과정 --> ");
        printArray(after);
        insertArray(after, insPos, data);
    }

    print("정렬 후 --> ");
    printArray(after);
}