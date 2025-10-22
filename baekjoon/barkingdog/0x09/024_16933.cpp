#include<iostream>
#include<queue>
using namespace std;

struct info {
    int y, x, broken, isNoon;
};

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, k, visited[1001][1001][11][2]; //visited[y][x][벽을 부순 횟수][낮 1 밤 0]
char a[1001][1001];
string s;

int bfs(int y, int x, int broken, int isNoon) { //broken : integer, isNoon : 1 or 0
    visited[y][x][broken][isNoon] = 1;

    queue<info> q;
    q.push({ y,x,broken,isNoon });

    while (!q.empty()) {
        info cur = q.front(); q.pop();

        if (cur.y == n - 1 && cur.x == m - 1) {
            return visited[cur.y][cur.x][cur.broken][cur.isNoon];
        }

        //이동 없이 머무른 후 진행. 이동 없이 벽을 부수는 경우는 존재하지 않으므로 따로 계산
        if (!visited[cur.y][cur.x][cur.broken][!cur.isNoon]) {
            visited[cur.y][cur.x][cur.broken][!cur.isNoon] = visited[cur.y][cur.x][cur.broken][cur.isNoon] + 1;
            q.push({ cur.y, cur.x, cur.broken, !cur.isNoon });
        }
        
        //이동 후 진행
        for (int i = 0; i < 4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            int nb = cur.broken;
            int nn = !cur.isNoon;

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

            //벽을 부수지 않고 진행
            if (a[ny][nx] == '0' && !visited[ny][nx][nb][nn]) {
                visited[ny][nx][nb][nn] = visited[cur.y][cur.x][cur.broken][cur.isNoon] + 1;
                q.push({ ny,nx,nb,nn });
            }

            //벽을 부수고 진행
            if (cur.isNoon) { //벽은 낮에만 부술 수 있다
                if (nb < k && a[ny][nx] == '1') {
                    nb = cur.broken + 1; //벽을 부순 횟수 증가

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

    cout << bfs(0, 0, 0, 1);

    return 0;
}
