#include<iostream>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused_addr = 1; //원소를 저장할 번지. 1부터 시작

void insert(int addr, int num) { //addr번지 이후에 unused_addr번지 연결 후 데이터 num 삽입
    dat[unused_addr] = num; //dat[i]: 새로 추가된 i번지 원소의 값
    pre[unused_addr] = addr; //pre[i]: i번지의 이전 번지
    nxt[unused_addr] = nxt[addr]; //nxt[i]: i번지의 다음 번지

    if (nxt[addr] != -1) { //addr번지의 다음 번지가 있었다면
        pre[nxt[addr]] = unused_addr; //다음 번지의 이전 번지를 unused_addr로 변경
    }

    nxt[addr] = unused_addr; //addr번지의 다음 번지를 unused_addr로 변경
    unused_addr++;

    return;
}

void erase(int addr) { //addr번지의 데이터 삭제
    nxt[pre[addr]] = nxt[addr]; //addr 이전 번지의 다음 번지를 현재 addr의 다음 번지로 변경

    if (nxt[addr] != -1) { //addr번지의 다음 번지가 있었다면
        pre[nxt[addr]] = pre[addr]; //addr 다음 번지의 이전 번지를 현재 addr의 이전 번지로 변경
    }

    return;
}

void traverse() {
    int cur = nxt[0]; //더미 노드에서부터 시작

    while (cur != -1) {
        cout << dat[cur] << ' ';
        cur = nxt[cur];
    }

    cout << "\n\n";
}

void insert_test() {
    cout << "****** insert_test *****\n";
    insert(0, 10); // 10
    traverse();
    insert(0, 30); // 30 10
    traverse();
    insert(2, 40); // 30 40 10
    traverse();
    insert(1, 20); // 30 40 10 20
    traverse();
    insert(4, 70); // 30 40 10 20 70
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

/*
자료구조별 insert 사용법

list :
1. 이터레이터 활용
iterator insert(iterator position, const value_type& val); //list.insert(이터레이터, 값);

string :
1. 인덱스 활용(문자열 반환)
basic_string& insert(size_type index, size_type count, CharT ch);
basic_string& insert(size_type index, const CharT* s); //string.insert(인덱스 번호, "문자열");
basic_string& insert(size_type index, const basic_string& str);

2. 이터레이터 활용(이터레이터 반환)
iterator insert(const_iterator pos, CharT ch); //string.insert(이터레이터, '문자');
iterator insert(const_iterator pos, size_type count, CharT ch);
*/