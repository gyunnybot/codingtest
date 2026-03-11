/*
삼성 2017 상반기 오후 2번 문제 - 방화벽 설치하기

벽: 3개로 정해져 있어서 a에다가 1로 아예 세워버리기
불: visited 체크로 구현

시간복잡도가 충분하다면 완전탐색 + 변경 되돌리기가 가장 직관적. 완전탐색>백트래킹>DP

벽 3개 고르는 경우의 수 = 조합 n*mC3 = 64C3 = 64*63*62/3*2*1 = 대략 36000
경우의 수마다 2 * O(N*M) n,m 10이라고 쳐도 10^8/3

시간복잡도 O(n*mC3 * N*M)
*/

#include <algorithm> // max
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, a[10][10], ret;
bool visited[10][10];
vector<pair<int, int>> wall_list, fire_list;

int calculate_safe_zone() {
  int ret = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 0 && !visited[i][j]) {
        ret++;
      }
    }
  }

  return ret;
}

void bfs(int y, int x) {
  visited[y][x] = true;

  queue<pair<int, int>> q;
  q.push({y, x});

  while (!q.empty()) {
    pair<int, int> cur = q.front(); q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = cur.first + dy[i];
      int nx = cur.second + dx[i];

      if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
        continue;
      }

      if (a[ny][nx] == 0 && !visited[ny][nx]) {
        visited[ny][nx] = true;
        q.push({ny, nx});
      }
    }
  }

  return;
}

void spread_fire() {
  fill(&visited[0][0], &visited[0][0] + 10 * 10, false);

  for (pair<int, int> fire : fire_list) {
    bfs(fire.first, fire.second);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];

      if (a[i][j] == 0) {
        wall_list.push_back({i, j});
      } else if (a[i][j] == 2) {
        fire_list.push_back({i, j});
      }
    }
  }

  for (int i = 0; i < wall_list.size(); i++) {
    for (int j = 0; j < i; j++) {
      for (int k = 0; k < j; k++) {
        a[wall_list[i].first][wall_list[i].second] = 1;
        a[wall_list[j].first][wall_list[j].second] = 1;
        a[wall_list[k].first][wall_list[k].second] = 1;

        spread_fire();

        ret = max(ret, calculate_safe_zone());

        a[wall_list[i].first][wall_list[i].second] = 0;
        a[wall_list[j].first][wall_list[j].second] = 0;
        a[wall_list[k].first][wall_list[k].second] = 0;
      }
    }
  }

  cout << ret;

  return 0;
}
