/*
삼성 2018 상반기 오전 1번 문제 - 이상한 체스

chessmen_list[idx]를 cur에 담아서 분기별로 처리. 다음 분기에 대한 오염 방지

시간복잡도 O(4^8 * (N*M))
*/

#include <algorithm> // min
#include <climits> // INT_MAX
#include <iostream>
#include <vector>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, a[10][10];
int ret = INT_MAX;
vector<pair<int, int>> chessmen_list;

vector<pair<int, int>> do_chess(int idx, int dir) {
  vector<pair<int, int>> ret;

  if (a[chessmen_list[idx].first][chessmen_list[idx].second] == 1) {
    pair<int, int> cur = chessmen_list[idx];

    while (true) {
      int ny = cur.first + dy[dir];
      int nx = cur.second + dx[dir];

      if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
        break;
      }

      if (a[ny][nx] == 6) {
        break;
      }

      if (a[ny][nx] == 0) {
        ret.push_back({ny, nx});
        a[ny][nx] = 7;
      }

      cur.first = ny;
      cur.second = nx;
    }
  } else if (a[chessmen_list[idx].first][chessmen_list[idx].second] == 2) {
    for (int i = 0; i <= 2; i += 2) {
      pair<int, int> cur = chessmen_list[idx];

      while (true) {
        int ny = cur.first + dy[(dir + i) % 4];
        int nx = cur.second + dx[(dir + i) % 4];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
          break;
        }

        if (a[ny][nx] == 6) {
          break;
        }

        if (a[ny][nx] == 0) {
          ret.push_back({ny, nx});
          a[ny][nx] = 7;
        }

        cur.first = ny;
        cur.second = nx;
      }
    }
  } else if (a[chessmen_list[idx].first][chessmen_list[idx].second] == 3) {
    for (int i = 0; i < 2; i++) {
      pair<int, int> cur = chessmen_list[idx];

      while (true) {
        int ny = cur.first + dy[(dir + i) % 4];
        int nx = cur.second + dx[(dir + i) % 4];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
          break;
        }

        if (a[ny][nx] == 6) {
          break;
        }

        if (a[ny][nx] == 0) {
          ret.push_back({ny, nx});
          a[ny][nx] = 7;
        }

        cur.first = ny;
        cur.second = nx;
      }
    }
  } else if (a[chessmen_list[idx].first][chessmen_list[idx].second] == 4) {
    for (int i = 0; i <= 2; i++) {
      pair<int, int> cur = chessmen_list[idx];

      while (true) {
        int ny = cur.first + dy[(dir + i) % 4];
        int nx = cur.second + dx[(dir + i) % 4];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
          break;
        }

        if (a[ny][nx] == 6) {
          break;
        }

        if (a[ny][nx] == 0) {
          ret.push_back({ny, nx});
          a[ny][nx] = 7;
        }

        cur.first = ny;
        cur.second = nx;
      }
    }
  } else if (a[chessmen_list[idx].first][chessmen_list[idx].second] == 5) {
    for (int i = 0; i <= 3; i++) {
      pair<int, int> cur = chessmen_list[idx];

      while (true) {
        int ny = cur.first + dy[(dir + i) % 4];
        int nx = cur.second + dx[(dir + i) % 4];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
          break;
        }

        if (a[ny][nx] == 6) {
          break;
        }

        if (a[ny][nx] == 0) {
          ret.push_back({ny, nx});
          a[ny][nx] = 7;
        }

        cur.first = ny;
        cur.second = nx;
      }
    }
  }

  return ret;
}

int get_min() {
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 0) {
        cnt++;
      }
    }
  }

  return cnt;
}

void dfs(int chessmen_list_idx) {
  if (chessmen_list_idx == chessmen_list.size()) {
    ret = min(ret, get_min());
    return;
  }

  for (int dir = 0; dir < 4; dir++) {
    vector<pair<int, int>> temp = do_chess(chessmen_list_idx, dir);

    dfs(chessmen_list_idx + 1);

    for (pair<int, int> t : temp) {
      a[t.first][t.second] = 0;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];

      if (a[i][j] != 0 && a[i][j] != 6) {
        chessmen_list.push_back({i, j});
      }
    }
  }

  dfs(0);

  cout << ret;

  return 0;
}
