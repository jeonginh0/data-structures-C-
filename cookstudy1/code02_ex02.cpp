// ex02_02.cpp
// 가장 많이 나온 글자 세기



#include "../CookHeader.h"

int main() {
    string poet = "One little, Two little, Three little Indians \n";
    poet += "Four little, Five little, Six little Indians \n";
    poet += "Seven little, Eight little, Nine little Indians \n";
    poet += "Ten little Indians boys";

    Array <char> charAry;   // 문자배열
    Array <int> countAry;   // 문자 개수 배열

    for(int i = 0; i < len(poet); i++) {
        char ch = poet[i];
        if(('a' < ch and ch <= 'z') || ('A' <= ch and ch <= 'Z')){  // 영문자만 처리
            if(isInArray(charAry, ch)){ // 추출한 문자가 문자 배열에 있으면
                int index = find(charAry.begin(), charAry.end(), ch) - charAry.begin(); // 추출한 문자가 배열의 어느 위치에 있는지 첨자 계산
                countAry[index] ++; // 해당 위치의 개수 배열에 1개 증가시킴
            }
            else{   // 문자가 문자 배열에 없다면
                charAry.push_back(ch);  // 새로운 문자와 개수 1을 배열에 추가
                countAry.push_back(1);
            }
        }
    }

    println("[원문]");
    println("--> " + poet);
    println("---------------------------");
    println("문자 빈도수(10회 이상)");
    println("---------------------------");

    for(int i = 0; i < len(charAry); i++) { // 개수 배열에서 10 이상인 문자 및 개수를 출력
        if(countAry[i] >= 10) {
            print(charAry[i]);
            println("----> " + to_string(countAry[i]));
        }
    }
}   // 위 코드는 find()함수를 적극 활용한 코드이다.