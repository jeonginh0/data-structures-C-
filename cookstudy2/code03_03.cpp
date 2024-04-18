// 03_03.cpp
// 데이터 삭제 함수 



#include "../CookHeader.h"

Array <string> katok = {"다현", "정연", "쯔위", "사나", "지효"};    // 테스트용 데이터 삽입

void delete_data(int position) {    // 지정 위치 데이터 삭제 함수 선언, 매개변수 : 삭제할 위치
    if((position < 0) || (position > len(katok))) { // 삭제할 위치가 배열 범위안에 존재하지 않으면,
        println("데이터를 삭제할 범위를 벗어났습니다.");
        return;
    }   // 오류메시지 출력 및 함수 종료

    int kLen = len(katok);  // 현재 배열의 길이 계산
    katok[position] = "None";   // 삭제할 위치[position]의 데이터 삭제

    for (int i = position + 1; i < kLen; i++) { //삭제한 다음 위치(position + 1)부터 배열길이 -1 까지 1씩증가 시키면서 반복
        katok[i - 1] = katok[i];    // 한 칸씩 왼쪽으로 자리 이동
        katok[i] = "None";
    }

    del(katok, kLen - 1);   // 맨 뒤 빈칸 삭제
}

int main() {
    delete_data(1);
    printArray(katok);  // 삭제 후 출력
    delete_data(3);
    printArray(katok);
}