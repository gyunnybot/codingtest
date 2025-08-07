#include<iostream>
#include<queue>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, ret;
char a[21][21];
string s;

void dfs(int y, int x, int num, int cnt) {
    ret = max(ret, cnt);

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

        int next = 1 << (int)(a[ny][nx] - 'A');

        if (!(num & next)) {
            dfs(ny, nx, (num | next), cnt + 1);
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

    dfs(0, 0, 1 << (int)(a[0][0] - 'A'), 1);

    cout << ret;

    return 0;
}
