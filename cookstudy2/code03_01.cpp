// 03_01.cpp
// 배열을 이용한 선형 리스트 생성



#include "../CookHeader.h"

Array <string> katok;   // 빈 배열을 전역 변수로 설정

void add_data(string data) {    // 배열 맨 뒤에 데이터를 추가하는 함수 선언
    katok.push_back("None");    // 배열 맨 뒤 빈칸 생성
    int kLen = len(katok);      // 배열의 현재 크기를 구하여 kLen 변수에 저장
    katok[kLen - 1] = data;     // 배열 맨 뒤에 전달받은 매개변수 대입
}

int main() {
    add_data("다현");   // 데이터 차례대로 호출
    add_data("정연");
    add_data("쯔위");
    add_data("사나");
    add_data("지효");

    printArray(katok);  // 배열 출력
}
