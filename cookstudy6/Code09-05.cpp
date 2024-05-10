//Code09-05.cpp
//최소 비용으로 자전거 도로를 건설하는 전체 코드

#include "../CookHeader.h"

typedef Array <Array <int>> Graph;
Graph initGraph(int size) {
    Graph G;
    Array <int> tmpAry;
    for (int i = 0; i < size; i++) {
        tmpAry.clear();
        for (int k = 0; k < size; k++) {
            tmpAry.push_back(0);        
        }
        G.push_back(tmpAry);
    }

    return G;
}

Graph G1;
int gSize = 6;
Array <string> nameAry = {"춘천", "서울", "속초", "대전", "광주", "부산"};
int 춘천 = 0, 서울 = 1, 속초 = 2, 대전 = 3, 광주 = 4, 부산 = 5;

void printGraph(Graph g) {
    print(" ");
    for (int v = 0; v < len(g); v++){
        print(nameAry[v] + " ");
    }
    println(" ");
    for (int row = 0; row < len(g); row ++) {
        print(nameAry[row] + " ");
        for (int col = 0; col < len(g[row]); col ++) {
            if (g[row][col] == 0) {
                print(" 0");
            } else {
                print(g[row][col]);
            }
            print(" ");
        }
        println("");
    }
    println("");
}

bool findVertex(Graph g, int findVtx){
    Array <int> stack;
    Array <int> visitedAry;

    int current = 0;
    stack.push_back(current);
    visitedAry.push_back(current);

    while(len(stack) != 0) {
        int next = -1;
        for (int vertex = 0; vertex < gSize; vertex++) {
            if (g[current][vertex] != 0) {
                if (isInArray(visitedAry, vertex)){
                } else {
                    next = vertex;
                    break;
                }
            }
        }
        if (next != -1) {
            current = next;
            stack.push_back(current);
            visitedAry.push_back(current);
        }
        else {
            current = stack[len(stack) - 1];
            stack.pop_back();
        }

        if (isInArray(visitedAry, findVtx)){
            return true;
        }
        else {
            return false;
        }
    }
} 

int main() {
    G1 = initGraph(gSize);
    G1[춘천][서울] = 10; G1[춘천][속초] = 15;
    G1[서울][춘천] = 10; G1[서울][속초] = 40; G1[서울][대전] = 11; G1[서울][광주] = 50;
    G1[속초][춘천] = 15; G1[속초][서울] = 40; G1[속초][대전] = 12;
    G1[대전][서울] = 11; G1[대전][속초] = 12; G1[대전][광주] = 20; G1[대전][부산] = 30;
    G1[광주][서울] = 50; G1[광주][대전] = 20; G1[광주][부산] = 25;
    G1[부산][대전] = 30; G1[부산][광주] = 25;

    println("## 자전거 도로 건설을 위한 전체 연결도 ##\n");
    printGraph(G1);

    Array <Array <int>> edgeAry;
    for (int i = 0; i < gSize; i++) {
        for (int k = 0; k < gSize; k++) {
            if (G1[i][k] != 0) {
                edgeAry.push_back({G1[i][k], i, k});
            }
        }
    }
    sortArray(edgeAry);
    reverseArray(edgeAry);

    Array <Array <int>> newAry;
    for (int i = 0; i < len(edgeAry); i += 2) {
        newAry.push_back(edgeAry[i]);
    }

    int index = 0;
    int start, end, saveCost;
    bool startYN, endYN;
    while (len(newAry) > gSize - 1 ) {
        start = newAry[index][1];
        end = newAry[index][2];
        saveCost = newAry[index][0];

        G1[start][end] = 0;
        G1[end][start] = 0;

        startYN = findVertex(G1, start);
        endYN = findVertex(G1, end);

        if (startYN && endYN) {
            del(newAry, index);
        }
        else {
            G1[start][end] = saveCost;
            G1[end][start] = saveCost;
            index++;
        }

        println("## 최소 비용의 자전거 도로 연결도 ##\n");
        printGraph(G1);
    }
}
