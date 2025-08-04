#include<iostream>
#include<queue>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, sy, sx, ey, ex, ret;
bool visited[301][301];
char a[301][301];
string s;

void bfs() {
    visited[sy][sx] = true;

    queue<pair<int, int>> q;
    q.push({ sy,sx });

    while (a[ey][ex] != '0') {
        queue<pair<int, int>> temp_q; ////'1' 또는 '#' 좌표 저장

        while (!q.empty()) {
            pair<int, int> cur = q.front(); q.pop();

            for (int i = 0; i < 4; i++) {
                int ny = cur.first + dy[i];
                int nx = cur.second + dx[i];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

                if (!visited[ny][nx]) {
                    visited[ny][nx] = true;

                    if (a[ny][nx] != '0') { //'1' 또는 '#'이라면
                        a[ny][nx] = '0'; //'0'으로 변경
                        temp_q.push({ ny,nx });
                    }
                    else { //'0'이라면
                        q.push({ ny,nx });
                    }
                }
            }
        }

        swap(q, temp_q); //swap: call-by-reference. O(1)

        ret++;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> sy >> sx >> ey >> ex;

    sy--, sx--, ey--, ex--;

    for (int i = 0; i < n; i++) {
        cin >> s;

        for (int j = 0; j < m; j++) {
            a[i][j] = s[j];
        }
    }

    bfs();

    cout << ret;

    return 0;
}
