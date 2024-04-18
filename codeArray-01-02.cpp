#include "/Users/jeonginho/Desktop/cookcpp/CookHeader.h"

int main() {
    Array <int> ary1 = {8,4,3,1,3,7,7,4,6,3,1,1,9};
    Array <int> ary2;

    sortArray(ary1);
    printArray(ary1);

    reverseArray(ary1);
    printArray(ary1);

    copyArray(ary1,ary2);
    printArray(ary2);

    insertArray(ary1, 2, 8888);
    printArray(ary1);

    setArray(ary1);
    printArray(ary1);

    bool yn = isInArray(ary1, 8888);
    println(yn);

    string myStr = "IT CookBook Algorithm";
    removeChar(myStr, 'o');
    println(myStr);

}