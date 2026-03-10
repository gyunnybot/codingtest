/*
삼성 2017 상반기 오후 1번 문제 - 자율주행 자동차

후진하는 것도 drive를 사용하기 때문에 ret이 또 증가할 수 있음. !visited 중복 검사 필수

반복문에서 바로 return

시간복잡도 O(4 * N^2)
*/

#include <iostream>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, y, x, d, a[51][51], ret;
bool visited[51][51];

void drive(int y, int x, int dir) {
  if (!visited[y][x]) {
    visited[y][x] = true;
    ret++;
  }

  for (int i = 0; i < 4; i++) {
    dir = (dir + 3) % 4;

    int ny = y + dy[dir];
    int nx = x + dx[dir];

    if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
      continue;
    }

    if (!visited[ny][nx] && a[ny][nx] == 0) {
      drive(ny, nx, dir);

      return; // 한 번 정해진 길로만 간다. break로 처리하면 후진도 진행하기 때문에 X
    }
  }

  int back_dir = (dir + 2) % 4;

  int ny = y + dy[back_dir];
  int nx = x + dx[back_dir];

  if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] == 0) {
    drive(ny, nx, dir);
  } else {
    return;
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
