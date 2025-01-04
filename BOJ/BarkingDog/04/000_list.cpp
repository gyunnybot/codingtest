#include<iostream>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num) { //삽입할 부분의 인덱스, 데이터 값
    dat[unused] = num; //현재 인덱스(unused)에 데이터 값 저장
    pre[unused] = addr; //현재 인덱스에 대한 이전 인덱스를 addr로 변경
    nxt[unused] = nxt[addr]; //현재 인덱스에 대한 다음 인덱스를 기존의 addr이 다음으로 가리키고 있던 원소로 변경

    if (nxt[addr] != -1) { //기존의 addr가 다음으로 가리키는 원소가 존재했다면
        pre[nxt[addr]] = unused; //해당되는 원소의 이전 인덱스를 현재 인덱스(unused)로 저장
    }

    nxt[addr] = unused; //현재 인덱스를 기존의 addr가 다음으로 가리키는 인덱스로 변경
    unused++;

    return;
}

void erase(int addr) {
    nxt[pre[addr]] = nxt[addr];

    if (nxt[addr] != -1) {
        pre[nxt[addr]] = pre[addr];
    }

    return;
}

void traverse() {
    int cur = nxt[0];
    while (cur != -1) {
        cout << dat[cur] << ' ';
        cur = nxt[cur];
    }
    cout << "\n\n";
}

void insert_test() {
    cout << "****** insert_test *****\n";
    insert(0, 10); // 10(address=1)
    traverse();
    insert(0, 30); // 30(address=2) 10
    traverse();
    insert(2, 40); // 30 40(address=3) 10
    traverse();
    insert(1, 20); // 30 40 10 20(address=4)
    traverse();
    insert(4, 70); // 30 40 10 20 70(address=5)
    traverse();
}

void erase_test() {
    cout << "****** erase_test *****\n";
    erase(1); // 30 40 20 70
    traverse();
    erase(2); // 40 20 70
    traverse();
    erase(4); // 40 70
    traverse();
    erase(5); // 40
    traverse();
}

int main(void) {
    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);
    insert_test();
    erase_test();
}
