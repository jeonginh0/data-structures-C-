// 02_05.cpp
// 배열의 사용과 출력



using namespace std;
#include <iostream>
#include <string>
#include <vector>   // 가변 배열(=벡터)을 사용하기 위해 포함

#define println(data) cout << data << endl  

#define Array vector    // 배열을 선언할 때 vector 대신 Array 이름을 사용
#define len(ary) (int)ary.size()    // len(배열명) 매크로로 배열의 길이를 구하도록 정의
#define del(ary,position) ary.erase(ary.begin() + position) /*  del(배열명,위치) 매크로로 배열의 해당 위치의 항목을 삭제하도록 정의*/

#define printArray(ary) \   // 배열을 넘겨 받아 배열의 내용을[] 안에 출력, 14~15행에서 배열의 개수만큼 내용을 출력하고 한 칸씩 띄운다
			cout << "[ "; \
			for(int i = 0; i< (int)ary.size(); i++) \
				cout << ary[i] << " "; \
			cout << "]" << endl

int main() { 
    Array <int>myAry = {10, 20, 30};    // 배열을 정의하고 3건의 값을 초기값으로 넣는다.
    myAry.push_back(40);    // 배열에 4번재 값을 추가한다. 배열의 크기가 4로 늘어난다.

    printArray(myAry);  
    println("배열 크기 --> " + to_string(len(myAry)));  // len() 매크로 사용, 배열 크기 구하기
    del(myAry, 2);  // del() 매크로를 사용, 배열에서 두 번째 항목을 삭제
    printArray(myAry);
}