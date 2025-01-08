#include<iostream>
using namespace std;

int n, ret, col[16];

bool check(int r) {
    for (int i = 0; i < r; i++) { //r행 이전의 행들에 대하여 검사
        if (col[r] == col[i] || r - i == abs(col[r] - col[i])) { //열이 같거나 대각선이라면 false
            return false;
        }
    }

    return true;
}

void nQueen(int r) {
    if (r == n) {
        ret++;
        return;
    }    

    for (int c = 0; c < n; c++) {
        col[r] = c; //r행 c열에 퀸을 놓는다. r행에서 퀸이 놓이는 열은 c행이다

        if (check(r)) { //r행에 문제가 없다면
            nQueen(r + 1); //다음 행에 대한 nQueen 진행
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    nQueen(0);

    cout << ret;

    return 0;
}
