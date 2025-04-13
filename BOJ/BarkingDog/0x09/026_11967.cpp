#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, x, y, a, b, ret;
bool visited[101][101], light[101][101];
vector<pair<int, int>> adj[101][101];

bool connected(pair<int, int> next) {
    for (int i = 0; i < 4; i++) {
        int nx = next.first + dx[i];
        int ny = next.second + dy[i];

        if (nx < 1 || nx > n || ny < 1 || ny > n) continue;

        if (visited[nx][ny] && light[nx][ny]) { //상하좌우 중 이미 한 번 방문한 곳이 있다면 true
            return true;
        }
    }

    return false;
}

void bfs() {
    queue<pair<int, int>> q;
    q.push({ 1,1 });

    visited[1][1] = true;
    light[1][1] = true;

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for (pair<int, int> next : adj[cur.first][cur.second]) {
            if (!light[next.first][next.second]) {
                //입력으로 주어진 next인 경우, 상하좌우로 인접하지 않더라도 불은 켤 수 있다
                light[next.first][next.second] = true;

                if (connected(next)) { //next 기준 상하좌우 중 이미 방문한 곳이 있는지 확인
                    visited[next.first][next.second] = true;
                    q.push({ next });
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;

            //상하좌우로 인접한 방 중 불이 켜져있다면
            if (!visited[nx][ny] && light[nx][ny]) {
                visited[nx][ny] = true;
                q.push({ nx,ny });
            }
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> x >> y >> a >> b;
        adj[x][y].push_back({ a,b });
    }

    bfs();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ret += light[i][j];
        }
    }

    cout << ret;

    return 0;
}
