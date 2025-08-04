#include<iostream>
#include<queue>
#include<set>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, ret;
bool visited[27];
char a[21][21];
string s;

void dfs(int y, int x, int cnt) {
    visited[a[y][x] - 'A'] = true;

    ret = max(ret, cnt);

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

        if (!visited[a[ny][nx] - 'A']) {
            dfs(ny, nx, cnt + 1);

            visited[a[ny][nx] - 'A'] = false;
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> s;

        for (int j = 0; j < m; j++) {
            a[i][j] = s[j];
        }
    }

    dfs(0, 0, 1);

    cout << ret;

    return 0;
}
