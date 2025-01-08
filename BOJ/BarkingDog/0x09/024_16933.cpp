#include<iostream>
#include<queue>
using namespace std;

struct info {
    int y, x, broken;
    bool isNoon;
};

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int visited[1001][1001][11][2], n, m, k; //visited[y][x][벽을 부순 횟수][낮1 밤0]
char a[1001][1001];
string s;

int bfs() {
    visited[0][0][0][1] = 1;

    queue<info> q;
    q.push({ 0,0,0,1 });

    while (!q.empty()) {
        info cur = q.front(); q.pop();

        if (cur.y == n - 1 && cur.x == m - 1) {
            return visited[cur.y][cur.x][cur.broken][cur.isNoon];
        }

        //머무르는 경우
        if (!visited[cur.y][cur.x][cur.broken][!cur.isNoon]) {
            visited[cur.y][cur.x][cur.broken][!cur.isNoon] = visited[cur.y][cur.x][cur.broken][cur.isNoon] + 1;
            q.push({ cur.y, cur.x, cur.broken, !cur.isNoon });
        }

        for (int i = 0; i < 4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            int nb = cur.broken;
            bool nn = !cur.isNoon;

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

            //벽을 부수지 않고 이동하는 경우
            if (a[ny][nx] == '0' && !visited[ny][nx][nb][nn]) {
                visited[ny][nx][nb][nn] = visited[cur.y][cur.x][cur.broken][cur.isNoon] + 1;
                q.push({ ny,nx,nb,nn });
            }

            //벽을 부수고 이동하는 경우
            if (cur.isNoon) { //벽은 낮에만 부술 수 있다
                if (cur.broken < k && a[ny][nx] == '1') {
                    nb++;

                    if (!visited[ny][nx][nb][nn]) {
                        visited[ny][nx][nb][nn] = visited[cur.y][cur.x][cur.broken][cur.isNoon] + 1;
                        q.push({ ny,nx,nb,nn });
                    }
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
