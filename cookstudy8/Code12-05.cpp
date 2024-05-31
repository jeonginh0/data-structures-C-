// Code12-05.cpp
// 퀵 정렬의 일반적인 구현

#include "../CookHeader.h"

Array <int> dataAry = { 188, 150, 168, 162, 105, 120, 177, 50 };

void qSort(Array <int> &arr, int start, int end) {
    if (end <= start) {
        return;
    }
    
    int low = start;
    int high = end;

    int pivot = arr[(low + high) / 2];
    while(low <= high) {
        while (arr[low] < pivot) {
            low++;
        }
        while(arr[high] > pivot) {
            high--;
        }
        if(low <= high) {
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
            low++;
            high--;
        }
    }

    int mid = low;

    qSort(arr, start, mid - 1);
    qSort(arr, mid, end);
}

void quickSort(Array <int> &ary) {
    qSort(ary, 0, len(ary)-1);
}

int main() {
    print("정렬 전 --> ");
    printArray(dataAry);
    quickSort(dataAry);
    print("정렬 후 --> ");
    printArray(dataAry);
}
