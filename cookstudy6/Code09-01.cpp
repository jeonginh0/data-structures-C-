// Code09-01 무방향 그래프 G1과 방향 그래프 G3의 구현

#include "../CookHeader.h"

typedef Array <Array <int>> Graph;

Graph initGraph(int size) {
    Graph G;

    Array <int> tmpAry;

    for (int i = 0; i < size; i++) {
        tmpAry.push_back(0);
        for (int k = 0; k < size; k++) {
            G.push_back(tmpAry);        
        }
    }

    return G;
}

Graph G1, G3;

int main() {
    G1 = initGraph(4); // 크기가 4인 인접행렬 생렬 (무방향 그래프)
    G1[0][1] = 1; G1[0][2] = 1; G1[0][3] = 1;
    G1[1][0] = 1; G1[1][2] = 1;
    G1[2][0] = 1; G1[2][1] = 1; G1[2][3] = 1;
    G1[3][0] = 1; G1[3][2] = 1;

    println("## G1 무방향 그래프 ##");
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            print(G1[row][col]);
        }
        println("");
    }

    G3 = initGraph(4); // 크기가 4인 인접행렬 생성 (방향 그래프)
    G3[0][1] = 1; G3[0][2] = 1;
    G3[3][0] = 1; G3[3][2] = 1;

    println("## G3 방향 그래프 ##");
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            print(G3[row][col]);
        }
        println("");
    }
}


