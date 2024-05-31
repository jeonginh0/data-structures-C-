// Code13-02.cpp
// 13-2 SelfStudy
/* 랜덤하게 0과 10000 사이의 숫자 100000개 생성 후 0과 100000 사이의 숫자 하나를 랜덤하게
뽑아서 찾도록 코드를 작성.*/

#include "../CookHeader.h"

Array <int> dataAry = randomArray(100000, 0, 100000);
int searchCount = 0;

int binSearch(Array <int> ary, int fData) {
    int pos = -1;
    int start = 0;
    int end = len(ary) - 1;

    while (start <= end) {
        searchCount ++;
        int mid = (start + end) / 2;
        if(fData == ary[mid]) {
            return mid;
        } else if (fData > ary[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return pos;
}

int main () {
    int findData = 202;

    print("배열 일부 --> [");
    for (int i = 0; i < 5; ++i) {
        print(dataAry[i]);
        if (i < 4) {
            print(" ");
        }
    }
    print("] ... [");
    for (int i = len(dataAry) - 5; i < len(dataAry); ++i) {
        print(dataAry[i]);
        if (i < len(dataAry) - 1) {
            print(" ");
        }
    }
    println("]");

    int position = binSearch(dataAry, findData);

    if (position == -1) {
        println(to_string(findData) + "이(가) 없네요.");
    } else {
        println(to_string(findData) + "은(는) " + to_string(position) + " 위치에 있음");
    }

    println("## " + to_string(searchCount) + "회 검색함");
}