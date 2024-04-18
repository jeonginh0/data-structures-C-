// 03_04.cpp
// 선형 리스트(완성) 처리 프로그램



#include "../CookHeader.h"

Array <string> katok;

int sel_num = -1;

void add_data(string data) {
    katok.push_back("None");
    int kLen = len(katok);
    katok[kLen - 1] = data;
}

void insert_data(int position, string data) {
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

void delete_data(int position) {
    if((position < 0) || (position >= len(katok))) { // 삭제할 위치가 배열 범위안에 존재하지 않으면,
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
    string data;
    int pos;

    while (sel_num != 4) {
        input(sel_num, "선택하세요(1: 추가, 2: 삽입, 3: 삭제, 4: 종료) --> ");

        switch (sel_num) {
            case 1:
                input(data, "추가할 데이터 --> ");
                add_data(data);
                printArray(katok);
                break;
            case 2:
                input(pos, "삽입할 위치 --> ");
                input(data, "삽입할 데이터 --> ");
                insert_data(pos, data);
                printArray(katok);
                break;
            case 3:
                input(pos, "삭제할 위치 --> ");
                delete_data(pos);
                printArray(katok);
                break;
            case 4:
                printArray(katok);
                return 0;
            default :
                println("1 ~ 4 중 하나를 입력하세요.");
                continue;
        }
    }
}