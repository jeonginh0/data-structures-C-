// Code13-01.cpp
// SelfStudy 13-1
// 중복된 데이터가 여러개 있을 때, 위치 여러 개를 배열로 만들어서 반환하도록 코드 변경

#include "../CookHeader.h"

Array <int> dataAry = { 188, 50, 150, 168, 50, 162, 105, 120, 177, 50 };

Array<int> seqSearch(Array<int> ary, int fData) {
    int sz = len(ary);
    Array<int> positionAry;

    for (int i = 0; i < sz; i++) {
        if (ary[i] == fData) {
            positionAry.push_back(i);
        }
    }
    return positionAry;
}

int main() {
    int findData = 50;
    print("배열-->");
    printArray(dataAry);
    Array<int> positions = seqSearch(dataAry, findData);
    if (len(positions) == 0) {
        println(to_string(findData) + "이(가) 없네요.");
    }
    else {
        print(to_string(findData) + "이(가) 있는 위치 : ");
        printArray(positions);
    }
    return 0;
}