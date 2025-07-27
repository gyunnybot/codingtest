#include<iostream>
#include<queue>
using namespace std;

struct info {
    int y, x, dist;
};

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, a[101][101];
int ret = 10001;
bool visited[101][101];

void bfs(int land_num) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == land_num) {
                visited[i][j] = true;
            }
        }
    }

    queue<info> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == land_num) {
                q.push({ i,j,0 }); //같은 섬은 dist = 0
            }
        }
    }

    while (!q.empty()) {
        info cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            int ndist = cur.dist + 1;

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

            //처음 방문한 곳이 바다도 아니고 같은 번호도 아니라면? 다른 섬에 도착한 것이다!
            if (a[ny][nx] != 0 && a[ny][nx] != land_num && !visited[ny][nx]) {
                ret = min(ret, cur.dist); //다리의 최소거리 구하기
                return; //가장 짧은 다리를 놓았으므로 bfs 즉시 return
            }

            //바다라면
            if (a[ny][nx] == 0 && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push({ ny,nx,ndist });
            }
        }
    }

    return;
}

void label_land(int y, int x, int cnt) {
    a[y][x] = cnt;

    queue<pair<int, int>> q;
    q.push({ y,x });

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

            if (a[ny][nx] == 1) {
                a[ny][nx] = cnt;
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
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int cnt = 2; //섬을 구분하기 위한 라벨링 변수 cnt

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1) {
                label_land(i, j, cnt);
                cnt++; //cnt를 증가시켜 다른 섬들과 구별
            }
        }
    }

    for (int i = 2; i < cnt; i++) {
        fill(&visited[0][0], &visited[0][0] + 101 * 101, false); //visited 초기화
        
        bfs(i);
    }

    cout << ret;

    return 0;
}
