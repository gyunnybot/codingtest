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

        if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] == 0 && !visited[ny][nx]) {
            drive(ny, nx, dir);
            return; //진행 방향이 정해졌다면 즉시 종료
        }
    }

    //2번 과정
    int back_dir = (dir + 2) % 4;

    int ny = y + dy[back_dir];
    int nx = x + dx[back_dir];

    if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] == 0) {
        drive(ny, nx, dir); //바라보는 방향을 유지한 채로 한 칸 후진 후 다시 시도
    }
    else {
        return; //더 이상 후진할 수 없다면 종료
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
