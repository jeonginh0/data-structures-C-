// ex02_01.cpp
// 자동 로또 번호 생성기



#include "../CookHeader.h"

int main(){
    Array <Array <int>> totalLotto;
    Array <int> lotto;
    int pickNum;
    int totCount;

    println("** 로또 번호 생성 시작. **");
    input(totCount, "몇 번을 뽑을까요? ");

    randomInit(1, 45);
    for(int i = 0; i < totCount; i++) {
        lotto = {}; // 각 회의 로또 번호 초기화
        while (true) {  // 뽑은 숫자가 중복되면 안됨.
            pickNum = cookRandom(gen);
            if(!(isInArray(lotto,pickNum))) {   // 추첨한 숫자가 중복되어 있지 않으면 1회 추첨번호로 추가
                lotto.push_back(pickNum);
            }
            if(len(lotto) >= 6) {    // 중복되지 않고 뽑힌 숫자가 6개 이상이 될 때 까지 무한 반복해서 숫자 추첨
                break;
            }
        }
        totalLotto.push_back(lotto);    // 1회 추첨된 번호를 전체 추첨번호 목록에 삽입
    }

    for(int i = 0; i < totCount; i++) { // 추첨된 2차원 목록을 형식에 맞춰 각 행렬로 출력
        lotto = totalLotto[i];
        sortArray(lotto);   // 각 회의 번호 정렬
        print("자동 번호 --> ");
        printArray(lotto);
    }
}