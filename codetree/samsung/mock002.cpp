/*
삼성 2015 하반기 2번 문제 - 2개의 사탕

목적지로 이동해야 큐가 끝나는 것이 아니라, 해당 좌표가 정답인지 확인하는 유형

ny를 바로 cur.y + dy[i]로 박아버리면 cur.y 자체가 정답인 경우를 무시하게 되어 최소 횟수가 안나오게 됨

그럼 앞으로 모두 ny = cur.y? 문제마다 다른 것 같다

출발점이 있고 목적지가 있다면 ny = cur.y + dy[i], 현재 좌표가 조건에 맞는지 체크하는 경우 ny = cur.y

시간복잡도 O((N*M)^2)
*/

#include <iostream>
#include <queue>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
bool visited[11][11][11][11];
int n, m, ret;
char a[11][11];
string s;

struct Info {
  int ry, rx, by, bx, cnt;
};
Info start;

int bfs() {
  visited[start.ry][start.rx][start.by][start.bx] = 1;

  queue<Info> q;
  q.push(start);

  int temp = -1;

  while (!q.empty()) {
    Info cur = q.front(); q.pop();

    if (cur.cnt > 10) {
      break;
    }

    if (a[cur.ry][cur.rx] == 'O' && a[cur.by][cur.bx] != 'O') {
      temp = cur.cnt;
      break;
    }

    for (int i = 0; i < 4; i++) {
      int nry = cur.ry; // 시작점 자체가 구멍일 수 있다
      int nrx = cur.rx;
      int nby = cur.by;
      int nbx = cur.bx;

      while (true) {
        if (a[nry][nrx] != '#' && a[nry][nrx] != 'O') { // 'R', 'B', '.'
          nry += dy[i];
          nrx += dx[i];
        } else { // '#', 'O'
          if (a[nry][nrx] == '#') {
            nry -= dy[i];
            nrx -= dx[i];
          }

          break;
        }
      }

      while (true) {
        if (a[nby][nbx] != '#' && a[nby][nbx] != 'O') {
          nby += dy[i];
          nbx += dx[i];
        } else {
          if (a[nby][nbx] == '#') {
            nby -= dy[i];
            nbx -= dx[i];
          }

          break;
        }
      }

      if (nry == nby && nrx == nbx) { // 두 구슬이 겹치는 경우
        if (a[nry][nrx] != 'O') { // 출구가 아닌 경우
          int r_dist = abs(nry - cur.ry) + abs(nrx - cur.rx);
          int b_dist = abs(nby - cur.by) + abs(nbx - cur.bx);

          if (r_dist > b_dist) {
            nry -= dy[i];
            nrx -= dx[i];
          } else {
            nby -= dy[i];
            nbx -= dx[i];
          }
        }

        // 겹치면서 출구인 경우는 더 이상 queue에 들어갈 필요가 없다
      }

      if (!visited[nry][nrx][nby][nbx]) {
        visited[nry][nrx][nby][nbx] = 1;
        q.push({nry, nrx, nby, nbx, cur.cnt + 1});
      }
    }
  }

  return temp;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> s;

    for (int j = 0; j < m; j++) {
      a[i][j] = s[j];

      if (a[i][j] == 'R') {
        start.ry = i;
        start.rx = j;
      }

      if (a[i][j] == 'B') {
        start.by = i;
        start.bx = j;
      }
    }
  }

  start.cnt = 0;

  ret = bfs();

  cout << ret;

  return 0;
}
