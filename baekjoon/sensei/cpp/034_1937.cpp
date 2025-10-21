#include<iostream>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, a[501][501], dp[501][501], ret;

int recur(int y, int x) {
    if (dp[y][x]) {
        return dp[y][x];
    }

    int cnt = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

        if (a[ny][nx] > a[y][x]) {
            cnt = max(cnt, recur(ny, nx) + 1);
        }
    }

    dp[y][x] = cnt;

    return dp[y][x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            recur(i, j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ret = max(ret, dp[i][j]);
        }
    }

    cout << ret;

    return 0;
}
