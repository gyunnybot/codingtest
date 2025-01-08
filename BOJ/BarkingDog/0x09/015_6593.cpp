#include<iostream>
#include<queue>
using namespace std;

struct Pos {
    int y, x, h;
};
Pos sPos, ePos;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
const int dh[] = { 1,-1 };
int l, r, c, answer, visited[31][31][31];
char a[31][31][31];
string s;

void bfs() {
    visited[sPos.y][sPos.x][sPos.h] = 1;

    queue<Pos> q;
    q.push(sPos);

    while (!q.empty()) {
        Pos cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            int nh = cur.h;

            if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if (a[ny][nx][nh] == '#') continue;

            if (!visited[ny][nx][nh]) {
                visited[ny][nx][nh] = visited[cur.y][cur.x][cur.h] + 1;
                q.push({ ny,nx,nh });
            }
        }

        for (int i = 0; i < 2; i++) {
            int ny = cur.y;
            int nx = cur.x;
            int nh = cur.h + dh[i];

            if (nh < 0 || nh >= l) continue;
            if (a[ny][nx][nh] == '#') continue;

            if (!visited[ny][nx][nh]) {
                visited[ny][nx][nh] = visited[cur.y][cur.x][cur.h] + 1;
                q.push({ ny,nx, nh });
            }
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true) {
        cin >> l >> r >> c;

        if (l == 0 && r == 0 && c == 0) break;

        fill(&visited[0][0][0], &visited[0][0][0] + 31 * 31 * 31, 0);

        for (int k = 0; k < l; k++) {
            for (int i = 0; i < r; i++) {
                cin >> s;

                for (int j = 0; j < c; j++) {
                    a[i][j][k] = s[j];

                    if (a[i][j][k] == 'S') {
                        sPos = { i,j,k };
                    }

                    if (a[i][j][k] == 'E') {
                        ePos = { i,j,k };
                    }
                }
            }
        }

        bfs();

        if (!visited[ePos.y][ePos.x][ePos.h]) {
            cout << "Trapped!" << '\n';
        }
        else {
            cout << "Escaped in " << visited[ePos.y][ePos.x][ePos.h] - 1 << " minute(s)." << '\n';
        }
    }

    return 0;
}
