#include<iostream>
#include<queue>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, answer, a[1001][1001], visited[1001][1001];
bool flag;
vector<pair<int, int>> tomato;

void bfs() {
    for (pair<int, int> toma : tomato) {
        visited[toma.first][toma.second] = 1;
    }

    queue <pair<int, int>> q;
    for (pair<int, int> toma : tomato) {
        q.push(toma);
    }

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (a[ny][nx] == -1) continue; //토마토가 들어있지 않은 경우
            if (visited[ny][nx] >= 1) continue; //초기 토마토(1) 또는 이미 익은 토마토          

            //익지 않은 토마토 bfs
            if (a[ny][nx] == 0 && !visited[ny][nx]) {
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

    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];

            if (a[i][j] == 1) {
                tomato.push_back({ i,j });
            }
        }
    }

    bfs();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == -1) continue; //토마토가 들어있지 않은 경우

            if (a[i][j] == 0 && !visited[i][j]) {
                flag = true; //bfs 이후 익지 않은 토마토가 있다면
            }
            else {
                answer = max(answer, visited[i][j] - 1);
            }
        }
    }

    if (flag) {
        cout << -1;
    }
    else {
        cout << answer;
    }

    return 0;
}
