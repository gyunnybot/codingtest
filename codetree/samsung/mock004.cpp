/*
삼성 2016 하반기 2번 문제 - 2048 게임

push 메서드에서 c 활용하는 발상. 보도블럭, 디버깅 문제에서도 적용 가능
무조건 for문을 타는 것이 아니라 조건에 맞을 때만 c를 통해 j++

시간복잡도 O(4^5 * 4 * N*N)
*/

#include <algorithm> // max
#include <iostream>
using namespace std;

int n, ret, a[21][21];

void push(int a[21][21]) {
  int temp[21][21] = {};

  for (int i = 0; i < n; i++) {
    bool flag = false;
    int c = 0;

    for (int j = 0; j < n; j++) {
      if (a[i][j] == 0) {
        continue;
      }

      if (flag && a[i][j] == temp[i][c - 1]) {
        temp[i][c - 1] += a[i][j];
        flag = false;
      } else {
        temp[i][c] = a[i][j];
        c++;
        flag = true;
      }
    }

    while (c < n) {
      temp[i][c] = 0;
      c++;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = temp[i][j];
    }
  }

  return;
}

void rotate(int a[21][21]) {
  int temp[21][21] = {};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      temp[i][j] = a[n - j - 1][i];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = temp[i][j];
    }
  }

  return;
}

int get_max(int a[21][21]) {
  int ret = -1;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ret = max(ret, a[i][j]);
    }
  }

  return ret;
}

void dfs(int a[21][21], int cnt) {
  if (cnt == 5) {
    ret = max(ret, get_max(a));
    return;
  }

  for (int i = 0; i < 4; i++) {
    int temp[21][21] = {};

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        temp[i][j] = a[i][j];
      }
    }

    push(temp);

    dfs(temp, cnt + 1);

    rotate(a);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  dfs(a, 0);

  cout << ret;

  return 0;
}
