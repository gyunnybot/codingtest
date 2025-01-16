#include<iostream>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1; //데이터가 할당 될 때마다 증가. addr로 사용된다

void insert(int addr, int num) { //해당 addr 다음에 num 연결
    //새로운 리스트 원소 생성
    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];

    if (nxt[addr] != -1) { //기존의 addr 다음 원소가 있었다면
        pre[nxt[addr]] = unused; //다음 원소의 이전 addr를 현재 unused로 변경
    }

    nxt[addr] = unused; //기존 addr 다음 원소를 unused로 변경

    unused++; //다음 addr 할당을 위해 unused 증가

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

/* insert
list :
1. 이터레이터 활용
iterator insert (iterator position, const value_type& val);

string :
1. 인덱스 활용(문자열 반환)
basic_string& insert(size_type index, size_type count, CharT ch);
basic_string& insert(size_type index, const CharT* s);
basic_string& insert(size_type index, const basic_string& str);

2. 이터레이터 활용(이터레이터 반환)
iterator insert(const_iterator pos, CharT ch);
iterator insert(const_iterator pos, size_type count, CharT ch);
*/