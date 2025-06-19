#include<iostream>
#include<queue>
using namespace std;

int n, k, ret;
int mov = 1; //동생이 매초 갱신되어 이동할 거리이자, 동생을 찾는데 걸리는 시간
bool visited[2][500001];

void bfs(int n) {
    visited[0][n] = true;

    queue<int> q;
    q.push(n);

    while (!q.empty()) {
        k += mov;

        if (k > 500000) {
            ret = -1;
            break;
        }

        if (visited[mov % 2][k]) { //이전에 k를 홀수 또는 짝수 시각에 맞춰 방문한 경험이 있다면
            ret = mov;
            break;
        }

        int q_size = q.size();

        bool flag = false;

        while (q_size--) {
            int cur = q.front(); q.pop();

            for (int ncur : {cur - 1, cur + 1, cur * 2}) {
                if (ncur == k) { //다음에 방문할 곳이 k라면
                    ret = mov;

                    flag = true;

                    break;
                }

                if (0 <= ncur && ncur <= 500000) {
                    if (!visited[mov % 2][ncur]) {
                        visited[mov % 2][ncur] = true;
                        q.push(ncur);
                    }
                }
            }

            if (flag) break;
        }

        if (flag) break;

        mov++;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    if (n == k) {
        cout << 0;
    }
    else {
        bfs(n);
        cout << ret;
    }

    return 0;
}
