#include<iostream>
#include<queue>
using namespace std;

struct info {
    int y, x, dist;
};

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, board[101][101];
int ret = 10001;
bool visited[101][101];

void label_land(int y, int x, int cnt) {
    board[y][x] = cnt;

    queue<pair<int, int>> q;
    q.push({ y,x });

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

            if (board[ny][nx] == 1) {
                board[ny][nx] = cnt;
                q.push({ ny,nx });
            }
        }
    }

    return;
}

void bfs(int land_num) {
    queue<info> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == land_num) { //같은 섬이라면
                visited[i][j] = true;
                q.push({ i,j,0 }); //같은 섬끼리의 거리는 0
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

            //바다도 아니고 자신의 섬도 아니라면 다른 섬에 도착한 것이다
            if (board[ny][nx] != 0 && board[ny][nx] != land_num && !visited[ny][nx]) {
                ret = min(ret, cur.dist); //다리의 최소거리 구하기
                return; //다리를 놓았으므로 bfs return
            }
          
            //바다라면
            if (board[ny][nx] == 0 && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push({ ny,nx,ndist });
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
            cin >> board[i][j];
        }
    }

    int cnt = 2; //섬을 구분하기 위한 라벨링 변수 cnt

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1) {
                label_land(i, j, cnt);
                cnt++; //cnt를 증가시켜 다른 섬들과 구별
            }
        }
    }

    for (int i = 2; i < cnt; i++) {
        fill(&visited[0][0], &visited[0][0] + 101 * 101, false);
        bfs(i);
    }

    cout << ret;

    return 0;
}
