// CodePractice02

#include "../CookHeader.h"

int main() {
    Array <Array <int>> totalLotto;
    Array <int> lotto;
    int pickNum;
    int totCount;

    println("** 로또 번호 생성 시작 **");
    input(totCount, "몇 번을 뽑을까요?");

    randomInit(1, 45);
    for(int i = 0; i < totCount; i++) {
        lotto = {};
        while(true) {
            pickNum = cookRandom(gen);
            if(!(isInArray(lotto,pickNum))) {
                lotto.push_back(pickNum);
            }
            if(len(lotto) >= 0){
                break;
            }
        }
        totalLotto.push_back(lotto);
    }

    for (int i = 0; i < totCount; i++) {
        lotto = totalLotto[i];
        sortArray(lotto);
        print("자동번호 --> ");
        printArray(lotto);
    }
}