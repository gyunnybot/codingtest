#include<iostream>
#include<queue>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int t, n, m, k, x, y, a[51][51];
bool visited[51][51];

void bfs(int y, int x) {
    visited[y][x] = true;

    queue<pair<int, int>> q;
    q.push({ y,x });

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

            if (a[ny][nx] == 1 && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push({ ny,nx });
            }
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;

    while (t--) {
        fill(&a[0][0], &a[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, false);

        int ret = 0;

        cin >> m >> n >> k;

        while (k--) {
            cin >> x >> y;
            a[y][x] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1 && !visited[i][j]) {
                    bfs(i, j);
                    ret++;
                }
            }
        }

        cout << ret << '\n';
    }

    return 0;
}
