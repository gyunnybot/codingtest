#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, x, y, a, b, ret;
bool visited[101][101], light[101][101];
vector<pair<int, int>> adj[101][101];

bool connected(pair<int, int> here) {
    for (int i = 0; i < 4; i++) {
        int nx = here.first + dx[i];
        int ny = here.second + dy[i];

        if (nx < 1 || nx > n || ny < 1 || ny > n) continue;

        //각 방에서는 상하좌우에 인접한 방으로 움직일 수 있다
        if (visited[nx][ny] && light[nx][ny]) { //here와 인접한 좌표가 먼저 켜져 있는가?
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
                light[next.first][next.second] = true; //일단 불을 킨다

                if (connected(next)) { //cur에서 next로 갈 수 있는가?
                    visited[next.first][next.second] = true;
                    q.push({ next });
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;

            if (!visited[nx][ny] && light[nx][ny]) { //불이 켜졌지만 방문하지 않은 곳이면 이동
                visited[nx][ny] = true;
                q.push({ nx,ny });
            }
        }
    }
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
