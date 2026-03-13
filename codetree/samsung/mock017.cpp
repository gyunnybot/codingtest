/*
삼성 2018 하반기 오전 2번 문제 - 토스트 계란틀

시간복잡도 O(N^2)
*/

#include <algorithm> // abs
#include <iostream>
#include <vector>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, l, r, a[51][51], ret;
bool visited[51][51];
vector<pair<int, int>> eggs;

void distribute(vector<pair<int, int>> &eggs) {
  int eggs_sum = 0;

  for (pair<int, int> egg : eggs) {
    eggs_sum += a[egg.first][egg.second];
  }

  int eggs_avg = eggs_sum / eggs.size();

  for (pair<int, int> egg : eggs) {
    a[egg.first][egg.second] = eggs_avg;
  }

  return;
}

void dfs(pair<int, int> cur) {
  visited[cur.first][cur.second] = true;
  eggs.push_back(cur);

  for (int i = 0; i < 4; i++) {
    int ny = cur.first + dy[i];
    int nx = cur.second + dx[i];

    if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
      continue;
    }

    int diff = abs(a[cur.first][cur.second] - a[ny][nx]);

    if (l <= diff && diff <= r && !visited[ny][nx]) {
      dfs({ny, nx});
    }
  }

  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> n >> l >> r;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  while (true) {
    bool flag = false;
    fill(&visited[0][0], &visited[0][0] + 51 * 51, false);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (!visited[i][j]) {
          eggs.clear();

          dfs({i, j});

          if (eggs.size() > 1) {
            distribute(eggs);
            flag = true;
          }
        }
      }
    }

    if (!flag) {
      break;
    }

    ret++;
  }

  cout << ret;

  return 0;
}
