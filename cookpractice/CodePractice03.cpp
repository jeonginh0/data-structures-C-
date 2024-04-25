// CodePractice03 선형 리스트

#include "../CookHeader.h"

Array <string> katok;

int selectNum;

void add_data(string data) {
    katok.push_back("None");
    int kLen = len(katok);
    katok[kLen - 1] = data;
}

void insert_data(int position, string data) {
    if ((position < 0) || (position > len(katok))) {
        print("데이터를 삽입할 범위를 벗어났습니다.");
        return;
    }
    katok.push_back("None");
    int kLen  = len(katok);

    for (int i = kLen - 1; i> position; i--) {
        katok[i] = katok[i - 1];
        katok[i - 1] = "None";
    }

    katok[position] = data;
}

void delete_data(int position) {
    if ((position < 0) || (position > len(katok))) {
        println("데이터를 삭제할 범위를 벗어났습니다.");
        return;
    }

    int kLen  = len(katok);
    katok[position] = "None";

    for (int i = position + 1; i < kLen; i++) {
        katok[i-1] = katok[i];
        katok[i] = "None";
    }

    del(katok, kLen - 1);
}

int main() {

    string data;
    int pos;

    while (selectNum != 4) {
        input(selectNum, "선택해라 1(추가) 2(삽입) 3(삭제) 4(종료) --> ");

        switch(selectNum) {
            case 1:
                input(data, "추가 --> ");
                add_data(data);
                printArray(katok);
                break;
            case 2:
                input(pos, "삽입 위치 --> ");
                input(data, "삽입 --> ");
                insert_data(pos, data);
                printArray(katok);
                break;
            case 3:
                input(pos, "삭제 위치 --> ");
                delete_data(pos);
                printArray(katok);
                break;
            case 4:
                printArray(katok);
                return 0;
            default :
                println("1 ~ 4 중 선택해라");
                continue;
        }

    }
}