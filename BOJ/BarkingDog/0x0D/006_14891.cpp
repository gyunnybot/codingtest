#include<iostream>
#include<vector>
#include<algorithm> //rotate
using namespace std;

string s;
int k, number, wise, ret;
vector<vector<int>> v(4, vector<int>(8, 0));

void rotate_gear(int number, int wise) {
    if (wise == 1) { //시계 방향 회전
        rotate(v[number].rbegin(), v[number].rbegin() + 1, v[number].rend());
    }
    else if (wise == -1) { //반시계 방향 회전
        rotate(v[number].begin(), v[number].begin() + 1, v[number].end());
    }

    return;
}

void set_and_rotate(int number, int wise) {
    int dir[4] = { 0,0,0,0 };

    dir[number] = wise; //현재 방향 저장

    for (int i = number; i < 3; i++) { //오른쪽 gear 방향 계산
        if (v[i][2] != v[i + 1][6]) {
            dir[i + 1] = -dir[i];
        }
    }

    for (int i = number; i > 0; i--) { //왼쪽 gear 방향 계산
        if (v[i][6] != v[i - 1][2]) {
            dir[i - 1] = -dir[i];
        }
    }

    for (int i = 0; i < 4; i++) { //rotate
        if (dir[i] != 0) {
            rotate_gear(i, dir[i]);
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 4; i++) {
        cin >> s;

        for (int j = 0; j < 8; j++) {
            v[i][j] = s[j] - '0';
        }
    }

    cin >> k;

    while (k--) {
        cin >> number >> wise;
        set_and_rotate(number - 1, wise);
    }

    if (v[0][0] == 1) ret += 1;
    if (v[1][0] == 1) ret += 2;
    if (v[2][0] == 1) ret += 4;
    if (v[3][0] == 1) ret += 8;

    cout << ret;

    return 0;
}
