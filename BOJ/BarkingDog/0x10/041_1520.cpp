#include<iostream>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, board[501][501], dp[501][501];

int dfs(int y, int x) {
    if (y == n - 1 && x == m - 1) { //목적지 도착
        return 1;
    }

    if (dp[y][x] != -1) {
        return dp[y][x];
    }

    int ret = 0;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

        if (board[ny][nx] < board[y][x]) {
            ret += dfs(ny, nx);
        }
    }

    dp[y][x] = ret; //해당 좌표에서 목적지까지의 최단 경로 갯수

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

    cout << dfs(0, 0);

    return 0;
}
