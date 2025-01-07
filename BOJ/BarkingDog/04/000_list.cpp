#include<iostream>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num) { //삽입할 노드 번호(1부터 시작), 저장할 데이터 값
    dat[unused] = num; //새로 생성된 노드에 데이터 값 저장
    pre[unused] = addr; //생성된 노드를 가리키는 이전 노드 번호를 addr로 저장
    nxt[unused] = nxt[addr]; //생성된 노드가 가리킬 노드 번호를, 이전의 노드가 가리켰던 노드로 저장

    if (nxt[addr] != -1) { //기존의 이전 노드가 다음으로 가리키는 노드가 존재했다면
        pre[nxt[addr]] = unused; //해당 노드를 가리켰던 이전 노드를 생성된 노드로 변경
    }

    nxt[addr] = unused; //이전 노드가 가리킬 노드 번호를 unused로 변경
    unused++; //노드 번호를 증가시켜 다음 노드 번호로 사용

    return;
}

void erase(int addr) { //삭제할 노드 번호
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
