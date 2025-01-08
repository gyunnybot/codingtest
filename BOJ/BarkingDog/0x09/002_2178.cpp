#include<iostream>
#include<queue>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, visited[101][101], ret;
bool a[101][101];
string s;

void bfs(int y, int x) {
    visited[y][x] = 1;

    queue<pair<int, int>> q;
    q.push({ y,x });

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        if (cur.first == n - 1 && cur.second == m - 1) {
            ret = visited[cur.first][cur.second];
            return;
        }

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

            if (a[ny][nx] == 1 && !visited[ny][nx]) {
                visited[ny][nx] = visited[cur.first][cur.second] + 1;
                q.push({ ny,nx });
            }
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
            a[i][j] = s[j] - '0';
        }
    }

    bfs(0, 0);

    cout << ret;

    return 0;
}
