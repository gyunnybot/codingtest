#include<iostream>
#include<queue>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
char a[101][101];
bool visited[101][101];
int n, ret, ret_disabled;
string s;

void bfs_R(int y, int x) {
    visited[y][x] = true;

    queue<pair<int, int>> q;
    q.push({ y,x });

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

            if (a[ny][nx] == 'R' && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push({ ny,nx });
            }
        }
    }

    return;
}

void bfs_G(int y, int x) {
    visited[y][x] = true;

    queue<pair<int, int>> q;
    q.push({ y,x });

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

            if (a[ny][nx] == 'G' && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push({ ny,nx });
            }
        }
    }

    return;
}

void bfs_B(int y, int x) {
    visited[y][x] = true;

    queue<pair<int, int>> q;
    q.push({ y,x });

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

            if (a[ny][nx] == 'B' && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push({ ny,nx });
            }
        }
    }

    return;
}

void bfs_R_G(int y, int x) {
    visited[y][x] = true;

    queue<pair<int, int>> q;
    q.push({ y,x });

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

            if ((a[ny][nx] == 'R' || a[ny][nx] == 'G') && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push({ ny,nx });
            }
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;

        for (int j = 0; j < n; j++) {
            a[i][j] = s[j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 'R' && !visited[i][j]) {
                bfs_R(i, j); ret++;
            }
            else if (a[i][j] == 'G' && !visited[i][j]) {
                bfs_G(i, j); ret++;
            }
            else if (a[i][j] == 'B' && !visited[i][j]) {
                bfs_B(i, j); ret++;
            }
        }
    }

    fill(&visited[0][0], &visited[0][0] + 101 * 101, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((a[i][j] == 'R' || a[i][j] == 'G') && !visited[i][j]) {
                bfs_R_G(i, j);
                ret_disabled++;
            }
            else if (a[i][j] == 'B' && !visited[i][j]) {
                bfs_B(i, j);
                ret_disabled++;
            }
        }
    }

    cout << ret << ' ' << ret_disabled;

    return 0;
}
