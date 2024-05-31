// Code12-02.cpp
// 버블 정렬 구현 - SelfStudy 12-1
// 랜덤하게 0 ~ 200 까지 숫자 10개 생성 후 내림차순 정렬

#include "../CookHeader.h"

Array<int> dataAry = randomArray(10, 0, 200);

Array<int> bubbleSort(Array<int> ary) {
    int n = len(ary);
    for (int end = n - 1; end > 0; end--) {
        bool changeYN = false;
        print("#사이클 --> ");
        printArray(ary);
        for (int cur = 0; cur < end; cur++) {
            if (ary[cur] < ary[cur + 1]) {
                int tmp = ary[cur];
                ary[cur] = ary[cur + 1];
                ary[cur + 1] = tmp;
                changeYN = true;
            }
        }
        if (!changeYN) {
            break;
        }
    }
    return ary;
}

int main() {
    print("정렬 전 --> ");
    printArray(dataAry);
    dataAry = bubbleSort(dataAry);
    print("정렬 후 --> ");
    printArray(dataAry);
}
