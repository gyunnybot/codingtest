#include<iostream>
#include<queue>
using namespace std;

struct Tomato {
    int y, x, h;
};
vector<Tomato> tomato;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
const int dh[] = { 1,-1 };
int n, m, h, ret, a[101][101][101], visited[101][101][101];
bool flag;

void bfs() {
    for (Tomato toma : tomato) {
        visited[toma.y][toma.x][toma.h] = 1;
    }

    queue<Tomato> q;
    for (Tomato toma : tomato) {
        q.push(toma);
    }

    while (!q.empty()) {
        Tomato cur = q.front(); q.pop();

        //같은 층
        for (int i = 0; i < 4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            int nh = cur.h; //height 고정

            if (ny < 0 || ny >= n || nx < 0 || nx >= m || nh < 0 || nh >= h) continue;
            if (a[ny][nx][nh] == -1) continue; //토마토가 들어있지 않은 경우
            if (visited[ny][nx][nh] >= 1) continue; //초기 토마토 또는 이미 익은 토마토           

            //익지 않은 토마토에 대해 bfs
            if (a[ny][nx][nh] == 0 && !visited[ny][nx][nh]) {
                visited[ny][nx][nh] = visited[cur.y][cur.x][cur.h] + 1;
                q.push({ ny,nx,nh });
            }
        }

        //위, 아래 층
        for (int i = 0; i < 2; i++) {
            int ny = cur.y; //y 고정
            int nx = cur.x; //x 고정
            int nh = cur.h + dh[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m || nh < 0 || nh >= h) continue;
            if (a[ny][nx][nh] == -1) continue; //토마토가 들어있지 않은 경우
            if (visited[ny][nx][nh] >= 1) continue; //초기 토마토 또는 이미 익은 토마토

            //익지 않은 토마토에 대해 bfs
            if (a[ny][nx][nh] == 0 && !visited[ny][nx][nh]) {
                visited[ny][nx][nh] = visited[cur.y][cur.x][cur.h] + 1;
                q.push({ ny,nx,nh });
            }
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> m >> n >> h;

    for (int height = 0; height < h; height++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j][height];

                if (a[i][j][height] == 1) {
                    tomato.push_back({ i,j,height });
                }
            }
        }
    }

    bfs();

    for (int height = 0; height < h; height++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j][height] == -1) continue; //토마토가 들어있지 않은 경우

                if (a[i][j][height] == 0 && !visited[i][j][height]) { //익지 않은 토마토가 있다면
                    flag = true;
                    break;
                }
                
                ret = max(ret, visited[i][j][height] - 1);
            }

            if (flag) break;
        }

        if (flag) break;
    }

    if (flag) {
        cout << -1;
    }
    else {
        cout << ret;
    }

    return 0;
}
