// Graph
// 무방향 그래프 응용
// 친구관계 기반으로 한 사용자 친구 추천 서비스

#include "../CookHeader.h"

typedef Array<Array<int>> Graph;

Graph initGraph(int size) {
    Graph G;
    Array<int> tmpAry;
    for (int i = 0; i < size; i++) {
        tmpAry.clear();
        for (int k = 0; k < size; k++) {
            tmpAry.push_back(0);
        }
        G.push_back(tmpAry);
    }
    return G;
}

const int gSize = 5;
Graph G1;
Array<string> personAry = {"인호", "세원", "성준", "은규", "성윤"};
const int 인호 = 0, 세원 = 1, 성준 = 2, 은규 = 3, 성윤 = 4;

// 사용자 이름을 인덱스로 변환하는 함수
int getIndex(const string& name) {
    for (int i = 0; i < personAry.size(); ++i) {
        if (personAry[i] == name) {
            return i;
        }
    }
    return -1; // 찾지 못한 경우
}

// 그래프 출력
void printGraph(const Graph& g) {
    print("      ");
    for (const auto& person : personAry) {
        print(person);
    }
    println("");
    for (int row = 0; row < gSize; row++) {
        print(personAry[row] + " ");
        for (int col = 0; col < gSize; col++) {
            print(g[row][col]);
            print("    ");
        }
        println("");
    }
    println("");
}

// 연관되지 않은 친구를 추천친구로 출력하는 함수
Array<string> recommendFriends(const string& name) {
    int userIndex = getIndex(name);
    Array<string> recommendFriends;

    if (userIndex == -1) {
        println("사용자를 찾을 수 없습니다.");
        return recommendFriends;
    }

    for (int i = 0; i < gSize; ++i) {
        // 연관되지 않은 친구를 찾음
        if (G1[userIndex][i] == 0 && userIndex != i) {
            recommendFriends.push_back(personAry[i]);
        }
    }

    return recommendFriends;
}

int main() {
    // 그래프 초기화
    G1 = initGraph(gSize);
    G1[인호][세원] = 1; G1[인호][성준] = 1; G1[인호][성윤] = 1;
    G1[세원][인호] = 1; G1[세원][성윤] = 1;
    G1[성준][인호] = 1; G1[성준][성윤] = 1;
    G1[성윤][성준] = 1; G1[성윤][세원] = 1; G1[성윤][인호] = 1;

    // 그래프 출력
    printGraph(G1);

    // 사용자 이름 입력
    string userName;
    input(userName, "이름을 입력하세요 : ");

    // 추천 친구 출력
    Array<string> recommendedFriends = recommendFriends(userName);
    print(userName + "의 추천 친구 :");
    printArray(recommendedFriends);

    return 0;
}