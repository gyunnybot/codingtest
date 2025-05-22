#include<iostream>
using namespace std;

int n, m, a[501][501], ret;
int tet[19][3][2] = { //블록의 좌상단을 시작점으로 만들 수 있는 모양 좌표를 모두 생성
    {{0,1},{0,2},{0,3}}, {{1,0},{2,0},{3,0}}, //ㅣ 회전
    {{0,1},{1,0},{1,1}}, //ㅁ
    {{1,0},{2,0},{2,1}}, {{1,0},{0,1},{0,2}},{{0,1},{1,1},{2,1}},{{0,1},{0,2},{-1,2}}, //ㄴ 회전
    {{0,1},{1,0},{2,0}}, {{1,0},{1,1},{1,2}},{{0,1},{-1,1},{-2,1}},{{0,1},{0,2},{1,2}}, //ㄴ 대칭 후 회전
    {{1,0},{1,1},{2,1}},{{0,1},{-1,1},{-1,2}}, //ㄹ 회전
    {{1,0},{0,1},{-1,1}},{{0,1},{1,1},{1,2}}, //ㄹ 대칭 후 회전
    {{0,1},{0,2},{1,1}}, {{-1,1},{0,1},{1,1}},{{0,1},{0,2},{-1,1}},{{1,0},{2,0},{1,1}} //ㅏ 회전
};

int cal_score(int i, int j, int k) {
    int score = a[i][j]; //시작점 먼저 더하기

    bool flag = false;

    for (int t = 0; t < 3; t++) {
        int ny = i + tet[k][t][0];
        int nx = j + tet[k][t][1];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) { //범위를 벗어나 블록이 만들어지지 않는다면
            flag = true;
            break;
        }

        score += a[ny][nx];
    }

    if (flag) {
        return -1;
    }
    else {
        return score;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 19; k++) {
                ret = max(ret, cal_score(i, j, k));
            }
        }
    }

    cout << ret;

    return 0;
}
