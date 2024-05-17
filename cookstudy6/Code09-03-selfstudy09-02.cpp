// SELF STUDY 9-2
// 무방향 그래프의 순회

#include "../CookHeader.h"
#include <string>

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

Array <string> nameAry = {"문별", "솔라", "쯔위", "휘인", "선미", "화사"};
int 문별 = 0; 
int 솔라 = 1; 
int 쯔위 = 2; 
int 휘인 = 3; 
int 선미 = 4;
int 화사 = 5;

Graph G1;

Array <int> stack;
Array <int> visitedAry;

int main() {
    G1 = initGraph(6);
    G1[문별][솔라] = 1; G1[문별][휘인] = 1;
    G1[솔라][쯔위] = 1; G1[솔라][문별] = 1;
    G1[휘인][쯔위] = 1; G1[휘인][문별] = 1;
    G1[쯔위][솔라] = 1; G1[쯔위][휘인] = 1; G1[쯔위][선미] = 1; G1[쯔위][화사] = 1;
    G1[선미][쯔위] = 1; G1[선미][화사] = 1;
    G1[화사][쯔위] = 1; G1[화사][선미] = 1;

    // println("## G1 무방향 그래프 ##");
    // for (int row = 0; row < 6; row ++) {
    //     for (int col = 0; col < 6; col ++) {
    //         print(G1[row][col]);
    //     }
    //     println("");
    // }

    int current = 0;
    stack.push_back(current);
    visitedAry.push_back(current);

    while(len(stack) != 0) {
        int next = -1;
        for (int vertex = 0; vertex < 6; vertex++) {
            if (G1[current][vertex] == 1) {
                if(isInArray(visitedAry, vertex)){
                } else {
                    next = vertex;
                    break;
                }
            }
        }
        if(next != -1) {
            current = next;
            stack.push_back(current);
            visitedAry.push_back(current);
        } else {
            current = stack[len(stack) - 1];
            stack.pop_back();
        }
    }
    
    print("방문 순서 -->");
    for(int i = 0; i < len(visitedAry); i++) {
        print(nameAry[i]);
    }

}