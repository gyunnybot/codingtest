#include<iostream>
#include<queue>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, t, a[301][301], temp[301][301];
bool visited[301][301];

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

            if (a[ny][nx] > 0 && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push({ ny,nx });
            }
        }
    }

    return;
}

void melt() {
    fill(&temp[0][0], &temp[0][0] + 301 * 301, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] > 0) {
                int sea_cnt = 0;

                pair<int, int> cur = { i,j };

                for (int d = 0; d < 4; d++) {
                    int ny = cur.first + dy[d];
                    int nx = cur.second + dx[d];

                    if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

                    if (a[ny][nx] == 0) {
                        sea_cnt++;
                    }
                }
                
                temp[cur.first][cur.second] = max(a[cur.first][cur.second] - sea_cnt, 0);
            }
        }
    }

    swap(a, temp); //swap : call by reference

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    while (true) {
        fill(&visited[0][0], &visited[0][0] + 301 * 301, false);

        int ret = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] && !visited[i][j]) {
                    bfs(i, j);
                    ret++;
                }
            }
        }

        if (ret > 1) { //빙하가 두 덩어리가 된다면 시간 출력
            cout << t;
            break;
        }
        
        if (ret == 0) { //빙하가 쪼개지지 않고 모두 녹았다면
            cout << 0;
            break;
        }

        melt();
        
        t++;
    }

    return 0;
}
