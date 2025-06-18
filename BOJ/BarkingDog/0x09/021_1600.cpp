#include<iostream>
#include<queue>
using namespace std;

struct info {
    int y, x, used;
};

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
const int dy1[] = { -1,-2,-2,-1,1,2,2,1 };
const int dx1[] = { -2,-1,1,2,2,1,-1,-2 };
int k, n, m, a[201][201], visited[201][201][31];

int bfs() {
    visited[0][0][0] = 1;

    queue<info> q;
    q.push({ 0,0,0 });

    while (!q.empty()) {
        info cur = q.front(); q.pop();

        if (cur.y == n - 1 && cur.x == m - 1) {
            return visited[cur.y][cur.x][cur.used] - 1;
        }

        for (int i = 0; i < 4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            int nused = cur.used;

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
          
            if (a[ny][nx] == 0 && !visited[ny][nx][nused]) {
                visited[ny][nx][nused] = visited[cur.y][cur.x][cur.used] + 1;
                q.push({ ny,nx,nused });
            }
        }

        for (int i = 0; i < 8; i++) {
            int ny = cur.y + dy1[i];
            int nx = cur.x + dx1[i];
            int nused = cur.used + 1; //말처럼 움직인 횟수 추가

            if (nused > k) break;

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            
            if (a[ny][nx] == 0 && !visited[ny][nx][nused]) {
                visited[ny][nx][nused] = visited[cur.y][cur.x][cur.used] + 1;
                q.push({ ny,nx,nused });
            }
        }
    }

    return -1; //queue가 비었는데 목적지에 도달하지 못하면 -1 반환
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> k >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    cout << bfs();

    return 0;
}
