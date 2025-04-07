#include<iostream>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, board[501][501], dp[501][501];

int recur(int y, int x) {
    if (y == n - 1 && x == m - 1) {
        return 1;
    }

    if (dp[y][x] != -1) { //dp의 초기값이 0이고 if(dp[y][x])의 경우 무한루프 발생
        return dp[y][x];
    }

    int ret = 0;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

        if (board[ny][nx] < board[y][x]) {
            ret += recur(ny, nx);
        }
    }

    dp[y][x] = ret; //해당 좌표에 도달하는 최소 경로의 갯수

    return dp[y][x];
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

    fill(&dp[0][0], &dp[0][0] + 501 * 501, -1);

    cout << recur(0, 0);

    return 0;
}
