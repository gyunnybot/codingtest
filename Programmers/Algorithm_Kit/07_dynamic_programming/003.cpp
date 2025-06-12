#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int dy[] = { 1,0 };
const int dx[] = { 0,1 };
int a[101][101], dp[101][101];

int dfs(int m, int n, int y, int x) {
    if (a[n][m] == -1) {
        return 0;
    }

    if (y == n && x == m) {
        return 1;
    }

    if (dp[y][x] != -1) {
        return dp[y][x];
    }

    int cnt = 0;

    for (int i = 0; i < 2; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny<0 || ny>n || nx<0 || nx>m) continue;
        if (a[ny][nx] == -1) continue;

        cnt = (cnt + dfs(m, n, ny, nx)) % 1000000007;
    }

    dp[y][x] = cnt;

    return dp[y][x];
}

int solution(int m, int n, vector<vector<int>> puddles) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int answer = 0;

    for (vector<int> pd : puddles) {
        a[pd[1]][pd[0]] = -1;
    }

    fill(&dp[0][0], &dp[0][0] + 101 * 101, -1);

    answer = dfs(m, n, 1, 1);

    return answer;
}
