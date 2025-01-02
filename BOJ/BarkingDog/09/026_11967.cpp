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

        //상하좌우 중 cur가 있다면 next로 이동할 수 있다
        if (visited[nx][ny] && light[nx][ny]) { //{nx,ny}가 cur인 경우
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

        //입력으로 주어진 연결 관계인 경우 상하좌우로 인접하지 않아도 불은 킬 수 있다
        for (pair<int, int> next : adj[cur.first][cur.second]) {
            if (!light[next.first][next.second]) {
                light[next.first][next.second] = true; //일단 불을 킨다

                if (connected(next)) { //cur에서 next로 갈 수 있는가(상하좌우로 인접해있는가)?
                    visited[next.first][next.second] = true;
                    q.push({ next });
                }
            }
        }

        //입력으로 주어진 관계는 아니지만 상하좌우로 인접한 방 중 불이 켜져있는지 조사
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;

            //베시는 불이 켜져있는 방으로만 들어갈 수 있다
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
