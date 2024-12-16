#include<iostream>
#include<queue>
using namespace std;

const int dy[] = { -2,-1,1,2,2,1,-1,-2 };
const int dx[] = { 1,2,2,1,-1,-2,-2,-1 };
int t, n, sy, sx, ey, ex, visited[301][301];

void bfs(int y, int x) {
    visited[y][x] = 1;

    queue<pair<int, int>> q;

    q.push({ y,x });

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for (int i = 0; i < 8; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

            if (!visited[ny][nx]) {
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

    cin >> t;

    while (t--) {
        fill(&visited[0][0], &visited[0][0] + 301 * 301, 0);

        cin >> n >> sy >> sx >> ey >> ex;

        bfs(sy, sx);

        cout << visited[ey][ex] - 1 << '\n';
    }

    return 0;
}
