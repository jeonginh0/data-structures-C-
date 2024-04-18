// 02_09.cpp
// 프로그래밍 고급 문법



using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

#define Array vector
#define println(data) cout << data <<" ";
#define printArray(ary) \
             cout << "["; \
             for(int i = 0; i < (int)ary.size(); i++){ \
                cout << ary[i] << " "; \
             } \
             cout << "]" << endl

#define sortArray(ary) sort(ary.begin(), ary.end())
#define reverseArray(ary) reverse(ary.begin(), ary.end())
#define copyArray(source, target) target.assign(source.begin(), source.end())
#define insertArray(ary, position, data) ary.insert(ary.begin() + position, data)
#define isInArray(ary, data) find(ary.begin(), ary.end(), data) != ary.end() 
#define setArray(ary) ary.erase(unique(ary.begin(), ary.end()),ary.end())
#define removeChar(strr, chr) strr.erase(remove(strr.begin(), strr.end(), chr), strr.end())

int main() {
    Array <int> ary1 = {8, 4, 3, 1, 3, 7, 7, 4, 6, 3, 1, 1, 9};
    Array <int> ary2;

    sortArray(ary1);    // 오름차순 정렬
    printArray(ary1);

    reverseArray(ary1); // 내림차순 정렬
    printArray(ary1);

    copyArray(ary1, ary2);  // ary1의 배열 값들을 ary2에 복사
    printArray(ary2);

    insertArray(ary1, 2, 8888); // 배열의 두 번째 자리에 값(8888)삽입
    printArray(ary1);

    setArray(ary1); // 동일 값 제거
    printArray(ary1);

    bool yn = isInArray(ary1, 8888);    // 동일 값 개수 출력
    println(yn);

    string mystr = "IT CookBook Algorithm";
    removeChar(mystr, 'o'); // 변수에서 문자제거
    println(mystr);
}