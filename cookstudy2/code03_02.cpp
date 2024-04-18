// 03_02.cpp
// 데이터를 삽입하는 함수



#include "../CookHeader.h"

Array <string> katok = {"다현", "정연", "쯔위", "사나", "지효"};   // 테스트용 데이터


void insert_data(int position, string data){    // 매개변수 : 삽입위치, 데이터
    if ((position < 0) || (position > len(katok))) {    // 삽입할 위치가 배열 범위안에 있어야 함.
        print("데이터를 삽입할 범위를 벗어났습니다.");
        return;
    }

    katok.push_back("None");    // 빈칸을 하나 추가하고 현재 배열길이 계산
    int kLen = len(katok);

    for (int i = kLen - 1; i > position; i--){  // 마지막 위치(배열 길이 -1)부터 삽입할 위치(position) 까지 1씩 감소시키면서 반복 
        katok[i] = katok[i - 1];    // ex) i를 5번 반복할 시 , 4번을 5번 자리로 이동, 4번자리는 빈칸.
        katok[i - 1] = "None";
    }

    katok[position] = data; // position 위치에 넘겨받은 데이터를 삽입
}

int main() {
    insert_data(2, "솔라");
    printArray(katok);
    insert_data(6, "문별");
    printArray(katok);  // 배열 출력
}