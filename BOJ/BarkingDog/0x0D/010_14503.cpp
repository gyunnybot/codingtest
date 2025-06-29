#include<iostream>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, y, x, d, a[51][51], ret;
bool visited[51][51];

void drive(int y, int x, int dir) {
    //1번 과정
    if (!visited[y][x]) {
        visited[y][x] = 1;
        ret++;
    }

    //3번 과정
    for (int i = 0; i < 4; i++) {
        dir = (dir + 3) % 4; //반시계 방향으로 90도 회전

        int ny = y + dy[dir];
        int nx = x + dx[dir];

        //빈 칸이 있는 경우
        if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] == 0 && !visited[ny][nx]) {
            drive(ny, nx, dir);
            return; //y, x에서의 진행 즉시 종료
        }
    }

    //2번 과정
    int back_dir = (dir + 2) % 4; //후진 방향 설정

    int ny = y + dy[back_dir];
    int nx = x + dx[back_dir];

    if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] == 0) {
        drive(ny, nx, dir); //한 칸 후진 후 dir 방향으로 drive 다시 시도
    }
    else {
        return; //더 이상 후진할 수 없다면 drive 최종 종료
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> y >> x >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    drive(y, x, d);

    cout << ret;

    return 0;
}
