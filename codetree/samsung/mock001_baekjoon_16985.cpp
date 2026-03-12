/*
백준 16985 Maaaaaaaaaze

삼성 2024 하반기 오전 1번 문제 - 미지의 공간 탈출 대비
>> 정육면체 다 펼치는거 아니라고!

토마토 문제 덕분에 3차원 bfs는 할 수 있었는데,
5*5*5*1024 경우의 수를 전부 커버칠 수 있는 발상이 추가적으로 필요했다

낚시왕에서 상어 속도를 %, / 등으로 보정하는 작업이 있었는데,
이처럼 모든 경우의 수를 돌려야 할 때는 연산자를 활용해서 쉽게 풀 수 없는지 떠올려보기

do_maze 실행 시 dist 배열을 0으로 초기화했으므로, dist[0][0][0] = 1로 놓고 ret - 1 진행

시간 복잡도 O(5*5*5 * 4^5)
*/

#include <algorithm> // min, next_permutataion
#include <climits> // INT_MAX
#include <iostream>
#include <queue>
using namespace std;

const int dh[6] = {1, -1, 0, 0, 0, 0};
const int dy[6] = {0, 0, -1, 0, 1, 0};
const int dx[6] = {0, 0, 0, 1, 0, -1};
int a[4][5][5][5], maze_board[5][5][5], dist[5][5][5];

struct Pos {
  int h, y, x;
};

int do_maze() {
  fill(&dist[0][0][0], &dist[0][0][0] + 5 * 5 * 5, 0);

  if (maze_board[0][0][0] == 0 || maze_board[4][4][4] == 0) {
    return INT_MAX;
  }

  queue<Pos> q;
  q.push({0, 0, 0});

  dist[0][0][0] = 1;

  while (!q.empty()) {
    Pos cur = q.front(); q.pop();

    if (cur.h == 4 && cur.y == 4 && cur.x == 4) {
      return dist[cur.h][cur.y][cur.x] - 1;
    }

    for (int i = 0; i < 6; i++) {
      int nh = cur.h + dh[i];
      int ny = cur.y + dy[i];
      int nx = cur.x + dx[i];

      if (nh < 0 || nh >= 5 || ny < 0 || ny >= 5 || nx < 0 || nx >= 5) {
        continue;
      }

      if (maze_board[nh][ny][nx] == 0) {
        continue;
      }

      if (!dist[nh][ny][nx]) {
        dist[nh][ny][nx] = dist[cur.h][cur.y][cur.x] + 1;
        q.push({nh, ny, nx});
      }
    }
  }

  return INT_MAX;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  for (int h = 0; h < 5; h++) {
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> a[0][h][i][j]; // 회전, 층, 행, 열
      }
    }

    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        a[1][h][i][j] = a[0][h][5 - j - 1][i];
      }
    }

    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        a[2][h][i][j] = a[1][h][5 - j - 1][i];
      }
    }

    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        a[3][h][i][j] = a[2][h][5 - j - 1][i];
      }
    }
  }

  int order[5] = {0, 1, 2, 3, 4}; // 층을 구별하는 인덱스
  int ret = INT_MAX;

  do {
    for (int cnt = 0; cnt < 1024; cnt++) { // 큐브를 회전하는 모든 경우의 수 4^5 = 2^10 = 1024
      int temp = cnt;

      for (int h = 0; h < 5; h++) {
        int dir = temp % 4;

        for (int i = 0; i < 5; i++) {
          for (int j = 0; j < 5; j++) {
            maze_board[h][i][j] = a[dir][order[h]][i][j];
          }
        }

        temp /= 4;
      }

      ret = min(ret, do_maze());
    }
  } while (next_permutation(order, order + 5));

  if (ret == INT_MAX) {
    cout << -1;
  } else {
    cout << ret;
  }

  return 0;
}
