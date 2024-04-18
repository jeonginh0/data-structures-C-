// 02_08.cpp
// 랜덤 값 추출



using namespace std;
#include <iostream>
#include <random>   // 랜덤을 추출하기 위해 포함

#define print(data) cout << data << " ";

#define randomInit(start, end) \    
    random_device rd; \
    mt19937 gen(rd()); \
    uniform_int_distribution<int> cookRandom(start, end)   // 랜덤을 초기화 하는 randomInin() 매크로를 정의.\
                                                           // 시작값 start, 끝값 end를 전달받음.

int main() {
    randomInit(0, 9999);    // 초기화 수행, 0~9999까지 수 중 하나를 추출

    for(int i = 0; i < 5; i++){ // 5개의 랜덤한 값을 출력
        print(cookRandom(gen));
    }
}