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

        //예제 입력 2 : 17(init, k = 5), 16(k = 6), 15(k = 8), 16(k = 11), 15(k = 15)
        //2번째 이동에서 visited[0][15] = true
        //4번째 이동에서 동생의 위치가 15이므로 수빈이는 3, 4번째 이동을 앞뒤로 이동하면 동생을 만날 수 있다. 또한 최소 시간이다
        if (visited[mov % 2][k]) {
            ret = mov;
            break;
        }

        int q_size = q.size();

        bool flag = false;

        while (q_size--) { //depth에 따라 k가 변하므로 이중 while문 활용
            int cur = q.front(); q.pop();

            for (int ncur : {cur - 1, cur + 1, cur * 2}) {
                if (ncur == k) { //ncur에서 동생을 찾았다면 즉시 갱신 후 break
                    flag = true;
                    ret = mov;

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
