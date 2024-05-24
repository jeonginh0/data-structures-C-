// Graph
// 무방향 그래프 응용
// 친구관계 기반으로 한 사용자 친구 추천 서비스

#include "../CookHeader.h" // CookHeader.h 파일을 include

typedef Array <Array <int>> Graph; // 2차원 배열을 사용하여 그래프를 정의하는 자료형을 만듦

//그래프 초기화 함수 정의
Graph initGraph(int size) {
    Graph G; // 그래프를 나타내는 2차원 배열
    Array<int> tmpAry; // 임시 배열
    for (int i = 0; i < size; i++) { // 그래프의 행 초기화
        tmpAry.clear(); // 임시 배열 비우기
        for (int k = 0; k < size; k++) {
            tmpAry.push_back(0); // 0으로 초기화된 배열을 임시 배열에 추가
        }
        G.push_back(tmpAry); // 임시 배열을 그래프에 추가하여 그래프의 행 생성
    }
    return G; // 초기화된 그래프 반환
}

int gSize = 5; // 그래프 크기
Graph G1; // 초기화된 그래프
Array<string> personAry = {"인호", "세원", "성준", "은규", "성윤"}; // 사용자 이름 배열
int 인호 = 0, 세원 = 1, 성준 = 2, 은규 = 3, 성윤 = 4; // 사용자 이름 인덱스

// 사용자 이름을 인덱스로 변환하는 함수
int getIndex(string name) {
    for (int i = 0; i < personAry.size(); ++i) {
        if (personAry[i] == name) { // 사용자 이름을 찾으면 해당 인덱스 반환
            return i;
        }
    }
    return -1; // 찾지 못한 경우
}

// 그래프 출력 함수
void printGraph(Graph g) { 
    print("     "); // 첫 번째 행에 공백 출력
    for (int v = 0; v < len(g); v++) { // 사용자 이름 출력
        print(personAry[v] + " ");
    }
    println(""); // 줄 바꿈
    for (int row = 0; row < gSize; row++) { // 그래프의 각 행을 출력
        print(personAry[row] + "  "); // 행의 이름 출력
        for (int col = 0; col < gSize; col++) {
            print(g[row][col]); // 그래프 값 출력
            print("   "); // 공백 출력
        }
        println(""); // 줄 바꿈
    }
    println(""); // 빈 줄 출력
}

// 연관되지 않은 친구를 추천친구로 출력하는 함수 (배열로 만들기 위해 Array<string> 선언)
Array<string> recommendFriends(string name) {
    int userIndex = getIndex(name); // 사용자의 인덱스 가져오기
    Array<string> recommendFriends; // 추천 친구를 담을 배열

    if (userIndex == -1) { // 사용자를 찾지 못한 경우
        println("사용자를 찾을 수 없습니다.");
        return recommendFriends; // 빈 배열 반환
    }

    for (int i = 0; i < gSize; ++i) { // 사용자와 연결되지 않은 친구 찾기
        if (G1[userIndex][i] == 0 && userIndex != i) {
            recommendFriends.push_back(personAry[i]); // 추천 친구 배열에 추가
        }
    }

    return recommendFriends; // 추천 친구 배열 반환
}

int main() {
    // 그래프 초기화
    G1 = initGraph(gSize); // 그래프 초기화 함수 호출
    G1[인호][세원] = 1; G1[인호][성준] = 1; G1[인호][성윤] = 1; // 관계 설정
    G1[세원][인호] = 1; G1[세원][성윤] = 1; // 관계 설정
    G1[성준][인호] = 1; G1[성준][성윤] = 1; // 관계 설정
    G1[성윤][성준] = 1; G1[성윤][세원] = 1; G1[성윤][인호] = 1; // 관계 설정

    // 그래프 출력
    printGraph(G1);

    // 사용자 이름 입력
    string userName;
    input(userName, "이름을 입력하세요 : ");

    // 추천 친구 출력
    Array<string> recommendedFriends = recommendFriends(userName); // 추천 친구 함수 호출
    print(userName + "의 추천 친구 :");
    printArray(recommendedFriends); // 추천 친구 출력

    return 0;
}
