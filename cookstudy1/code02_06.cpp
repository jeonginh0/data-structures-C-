// 02_06.cpp
// 2차원 배열의 사용



using namespace std;

#include <iostream>
#include <vector>

#define Array vector

#define printArray2(ary2) \ 
			cout << "[ "; \
			for(int i = 0; i< (int)ary2.size(); i++) { \
				cout << "{ "; \
				for(int k = 0; k<(int)ary2[i].size(); k++) { \
					cout << ary2[i][k] << " "; \
				} \
				cout << "} "; \
			} \
			cout << "]" << endl /*2차원 배열을 출력하는 기능 정의*/

Array <Array <int>> emptyArray2(int row, int col) { // 행과 열 크기를 넘겨 받고, 해당 크기의 정수형 2차원 빈 배열을 생성해서 반환하는 emptyArray2()함수 선언
	Array <Array <int>> ary2;
	Array <int> tmp;
	for (int i = 0; i < row; i++) {
		tmp.clear();
		for (int k = 0; k < col; k++){
			tmp.push_back(0);
        }
		ary2.push_back(tmp);
	}
	return ary2;
}

int main() {
    Array <Array <string>> grade = {{"수학", "90"}, {"영어", "70"}, {"과학", "80"}};  // 문자열 2차원 배열을 만들고 값 초기화
    grade.push_back({"역사", "75"});    // 2차원 배열에 한 행을 추가.
    printArray2(grade); //2차원 배열 출력

    Array <Array <int>> empArray = emptyArray2(3, 4); // emptyArray2()함수 호출, 빈 2차원 정수형 배열 생성
    printArray2(empArray);
}