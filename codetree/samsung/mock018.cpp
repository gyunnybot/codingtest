/*
삼성 2018 하반기 오후 1번 문제 - 바이러스 실험

격자 하나에 여러 바이러스가 들어갈 수 있음 vector + 2차원 = 3차원

시간복잡도 O(K * N*N*K(virus_reproduction))
*/
#include <algorithm> // sort
#include <iostream>
#include <vector>
using namespace std;

const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int n, m, k, r, c, year, nutrient[11][11], auto_feed_nutrient[11][11], ret;
vector<int> a[11][11];

void add_nutrient() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      nutrient[i][j] += auto_feed_nutrient[i][j];
    }
  }

  return;
}

void virus_reproduction() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j].size()) {
        for (int virus_age : a[i][j]) {
          if (virus_age % 5 == 0) {
            for (int d = 0; d < 8; d++) {
              int ny = i + dy[d];
              int nx = j + dx[d];

              if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
                continue;
              }

              a[ny][nx].push_back(1);
            }
          }
        }
      }
    }
  }

  return;
}

void virus_nutrient_cycle() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j].size()) {
        sort(a[i][j].begin(), a[i][j].end());

        vector<int> new_virus_age = {};
        int dead = 0;

        for (int virus_age : a[i][j]) {
          if (nutrient[i][j] >= virus_age) {
            nutrient[i][j] -= virus_age;

            new_virus_age.push_back(virus_age + 1);
          } else {
            dead += virus_age / 2;
          }
        }

        a[i][j] = new_virus_age; // O(N)

        nutrient[i][j] += dead;
      }
    }
  }

  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> n >> m >> k;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> auto_feed_nutrient[i][j];
    }
  }

  for (int i = 0; i < m; i++) {
    cin >> r >> c >> year;

    a[r - 1][c - 1].push_back(year);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      nutrient[i][j] = 5;
    }
  }

  while (k--) {
    virus_nutrient_cycle();

    virus_reproduction();

    add_nutrient();
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ret += a[i][j].size();
    }
  }

  cout << ret;

  return 0;
}
