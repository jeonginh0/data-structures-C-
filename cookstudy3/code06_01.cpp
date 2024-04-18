// 06_01.cpp
// 크기가 5칸인 스택(stack)의 생성과 데이터 3개 입력



#include "../CookHeader.h"

Array <string> stack = {"None", "None", "None", "None", "None"}; // 크기가 5칸인 빈 스택
int top = -1; // 초깃값 -1

int main(){
    top ++; // top을 1씩 증가시키고 그 자리에 값을 넣는다.
    stack[top] = "커피";
       
    top ++;
    stack[top] = "녹차";

    top ++;
    stack[top] = "꿀물";

    println("-------- 스택 상태 --------");
    for(int i = 0; i < len(stack); i++){
        println(stack[i]);
    }
}