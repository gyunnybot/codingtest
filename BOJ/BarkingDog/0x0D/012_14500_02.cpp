#include<iostream>
using namespace std;

int n, m, board[501][501], ret, sum;
int tet[19][3][2] = { //경우의 수로 나올 좌표를 미리 생성. 블록의 시작점은 좌상단으로 가정한다
    {{0,1},{0,2},{0,3}}, {{1,0},{2,0},{3,0}}, //ㅣ 회전
    {{0,1},{1,0},{1,1}}, //ㅁ
    {{1,0},{2,0},{2,1}}, {{1,0},{0,1},{0,2}},{{0,1},{1,1},{2,1}},{{0,1},{0,2},{-1,2}}, //ㄴ 회전
    {{0,1},{1,0},{2,0}}, {{1,0},{1,1},{1,2}},{{0,1},{-1,1},{-2,1}},{{0,1},{0,2},{1,2}}, //ㄴ 대칭 후 회전
    {{1,0},{1,1},{2,1}},{{0,1},{-1,1},{-1,2}}, //ㄹ 회전
    {{1,0},{0,1},{-1,1}},{{0,1},{1,1},{1,2}}, //ㄹ 대칭 후 회전
    {{0,1},{0,2},{1,1}}, {{-1,1},{0,1},{1,1}},{{0,1},{0,2},{-1,1}},{{1,0},{2,0},{1,1}} //ㅏ 회전
};

int get_score(int i, int j, int k) {
    int sum = board[i][j]; //기준점 먼저 더하기
    bool flag = false;

    for (int t = 0; t < 3; t++) {
        int ny = i + tet[k][t][0];
        int nx = j + tet[k][t][1];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) { //범위를 벗어나 블록이 만들어지지 않는다면
            flag = true;
            break; 
        }

        sum += board[ny][nx];
    }

    if (flag) {
        return -1;
    }
    else {
        return sum;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 19; k++) {
                sum = get_score(i, j, k);
                ret = max(ret, sum);
            }
        }
    }

    cout << ret;

    return 0;
}
