#include<iostream>
using namespace std;

void insert(int idx, int num, int arr[], int& len) { //삽입할 인덱스 번호, 삽입할 값, 대상 배열, 배열의 길이
    for (int i = len; i > idx; i--) {
        arr[i] = arr[i - 1]; //마지막 원소부터 idx번째까지의 원소를 오른쪽으로 한 칸씩 이동
    }

    arr[idx] = num; //idx번째 요소에 num 삽입
    len++; //전체 배열의 길이 증가
    
    return;
}

void erase(int idx, int arr[], int& len) { //삭제할 인덱스 번호, 대상 배열, 배열의 길이
    len--; //전체 배열의 길이 감소

    for (int i = idx; i < len; i++) {
        arr[i] = arr[i + 1]; //idx + 1부터 끝까지의 원소를 순서대로, 왼쪽으로 한 칸씩 덮어쓰며 이동
    }

    return;
}

void printArr(int arr[], int& len) {
    for (int i = 0; i < len; i++) cout << arr[i] << ' ';
    cout << "\n\n";
}

void insert_test() {
    cout << "***** insert_test *****\n";
    int arr[10] = { 10, 20, 30 };
    int len = 3;
    insert(3, 40, arr, len); // 10 20 30 40
    printArr(arr, len);
    insert(1, 50, arr, len); // 10 50 20 30 40
    printArr(arr, len);
    insert(0, 15, arr, len); // 15 10 50 20 30 40
    printArr(arr, len);
}

void erase_test() {
    cout << "***** erase_test *****\n";
    int arr[10] = { 10, 50, 40, 30, 70, 20 };
    int len = 6;
    erase(4, arr, len); // 10 50 40 30 20
    printArr(arr, len);
    erase(1, arr, len); // 10 40 30 20
    printArr(arr, len);
    erase(3, arr, len); // 10 40 30
    printArr(arr, len);
}

int main(void) {
    insert_test();
    erase_test();
}