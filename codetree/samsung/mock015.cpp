/*
삼성 2018 상반기 오후 1번 문제 - 드래곤 커브

for (int j = gen - 1; j >= 0; j--) 반복문 내 gen이 증가한다고 해서 초기식의 j가 바뀌지는 않는다

시간복잡도 O(n* 2^g + 10^4)
*/

#include <iostream>
using namespace std;

const int dy[] = {0, -1, 0, 1};
const int dx[] = {1, 0, -1, 0};

int n, y, x, d, g, curve[1024], ret;
bool a[101][101];

void dragon_curve(int y, int x, int d, int g) {
  fill(&curve[0], &curve[0] + 1024, 0);

  int gen = 0;

  curve[gen] = d;
  gen++;

  for (int i = 0; i < g; i++) {
    for (int j = gen - 1; j >= 0; j--) { // j = 0 / 10 / 3210 / 76543210 ...
      curve[gen] = (curve[j] + 1) % 4;
      gen++;
    }
  }

  a[y][x] = true;

  for (int i = 0; i < gen; i++) {
    int ny = y + dy[curve[i]];
    int nx = x + dx[curve[i]];

    a[ny][nx] = true;

    y = ny;
    x = nx;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> y >> x >> d >> g; // 세로축 y가 편해서 둘이 바꾸기. 문제의 전제를 전부 바꾸면 된다

    dragon_curve(y, x, d, g);
  }

  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      if (a[i][j] == 1 && a[i + 1][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j + 1] == 1) {
        ret++;
      }
    }
  }

  cout << ret;

  return 0;
}
