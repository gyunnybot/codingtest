#include<iostream>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, y, x, d, board[51][51], ret;
bool visited[51][51];

void drive(int y, int x, int dir) {
    if (!visited[y][x]) { //1번 과정
        visited[y][x] = 1;
        ret++;
    }

    //3번 과정
    for (int i = 0; i < 4; i++) {
        dir = (dir + 3) % 4; //반시계 방향으로 90도 회전

        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny >= 0 && ny < n && nx >= 0 && nx < m && board[ny][nx] == 0 && !visited[ny][nx]) {
            drive(ny, nx, dir); //(ny, nx)로 전진 이동 후 drive 실행
            return; //이동했다면 (y, x)에서의 drive 역할은 종료된다
        }
    }

    //y, x에서 네 방향 모두 조건을 만족하지 않아 반환되지 않았다면 2번 과정 진행
    int back_dir = (dir + 2) % 4; //후진 방향 설정

    //후진 좌표 설정
    int ny = y + dy[back_dir];
    int nx = x + dx[back_dir];

    if (ny >= 0 && ny < n && nx >= 0 && nx < m && board[ny][nx] == 0) {
        drive(ny, nx, dir); //(ny, nx)로 후진 이동 후 drive 실행
    }
    else {
        return; //벽에 막혀 더 이상 후진할 수 없다면 종료
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> y >> x >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    drive(y, x, d);

    cout << ret;

    return 0;
}
