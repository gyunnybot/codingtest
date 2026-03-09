/*
삼성 2016 하반기 1번 문제 - 정육면체 굴리기

  2
4 1 3
  5
  6

대단한거 생각하지 말고 무식하게 각 면을 변수로 할당하면 되는 문제

정육면체라고 못을 박았으니 떠오를 수 있는 발상
테트로미노도 4개의 블럭으로 만들 수 있는 모양이 정해져 있어, 미리 하드코딩하고 반복문 돌리는 것과 비슷한 맥락?

시간복잡도 O(N*M+K)
*/

#include <iostream>
#include <vector>
using namespace std;

const int dy[] = {0, 0, -1, 1}; // 동,서,북,남
const int dx[] = {1, -1, 0, 0}; // 동,서,북,남
int n, m, y, x, k, a[21][21], dir, temp;
int n1, n2, n3, n4, n5, n6; // 위, 뒤, 우, 좌, 앞, 아래

vector<int> v;

void do_dice(int dir) {
  int ny = y + dy[dir];
  int nx = x + dx[dir];

  if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
    if (dir == 0) { // 동
      temp = n1, n1 = n4, n4 = n6, n6 = n3, n3 = temp;
    } else if (dir == 1) { // 서
      temp = n1, n1 = n3, n3 = n6, n6 = n4, n4 = temp;
    } else if (dir == 2) { // 북
      temp = n1, n1 = n5, n5 = n6, n6 = n2, n2 = temp;
    } else if (dir == 3) { // 남
      temp = n1, n1 = n2, n2 = n6, n6 = n5, n5 = temp;
    }

    if (a[ny][nx] == 0) {
      a[ny][nx] = n6;
    } else {
      n6 = a[ny][nx];
      a[ny][nx] = 0;
    }

    // y, x -> ny, nx
    y = ny;
    x = nx;

    // 현재 윗면 저장
    v.push_back(n1);
  }

  // 범위를 넘어가면 무시한다

  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> n >> m >> y >> x >> k;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  while (k--) {
    cin >> dir;
    do_dice(dir - 1);
  }

  for (int i : v) {
    cout << i << '\n';
  }

  return 0;
}
