#include<iostream>
#include<queue>
using namespace std;

struct info {
    int y, x, broken;
};

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, k, visited[1001][1001][11]; //visited[y][x][벽을 부순 횟수]
char a[1001][1001];
string s;

int bfs() {
    visited[0][0][0] = 1;

    queue<info> q;
    q.push({ 0,0,0 });

    while (!q.empty()) {
        info cur = q.front(); q.pop();

        if (cur.y == n - 1 && cur.x == m - 1) {
            return visited[cur.y][cur.x][cur.broken];
        }

        for (int i = 0; i < 4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            int nb = cur.broken;

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

            //벽을 부수지 않고 진행
            if (a[ny][nx] == '0' && !visited[ny][nx][nb]) {
                visited[ny][nx][nb] = visited[cur.y][cur.x][cur.broken] + 1;
                q.push({ ny,nx,nb });
            }

            //벽을 부수고 진행
            if (cur.broken < k && a[ny][nx] == '1') {
                nb = cur.broken + 1; //벽을 부순 횟수 증가

                if (!visited[ny][nx][nb]) {
                    visited[ny][nx][nb] = visited[cur.y][cur.x][cur.broken] + 1;
                    q.push({ ny,nx,nb });
                }
            }
        }
    }

    return -1; //queue가 비었는데 목적지에 도달하지 못했다면 -1 반환
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> s;

        for (int j = 0; j < m; j++) {
            a[i][j] = s[j];
        }
    }

    cout << bfs();

    return 0;
}
