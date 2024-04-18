// 02_04.cpp
// 문자열 처리와 변환



using namespace std;
#include <iostream>
#include <string> // to_string()함수를 사용하기 위해 포함.

#define println(data) cout << data << endl

int main() {
    string str1 = "IT CookBook";            // string, char* 형 문자열 선언
    const char* char1 = "자료구조와 알고리즘";

    println(str1);                          // 문자열 출력
    println(char1);

    string str2 = char1;                    // str2에 char*형을 대입하여 출력
    println(str2);

    const char* char2 = str1.c_str();       /* '문자열.size()' 함수를 이용 string 형의 문자 길이 출력
                                                char* 형은 string 형으로 변환 후 문자 길이 출력
                                                * 한글은 글자당 2바이트 차지 */
    println(((string)char1).size());

    str1 = "100";
    char1 = "200";
    println(str1 + char1);                  // 문자열 + 시 문자열을 잇는 효과를 준다.

    int value = stoi(str1) + stoi(char1);   /*  문자열을 stoi()함수를 이용해 정수로 변환, to_string(숫자) 
                                                함수를 사용해 다시 문자열로 변환 */
    println("합계는 " + to_string(value));
}