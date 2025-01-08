#include<iostream>
#include<queue>
using namespace std;

int n, k;
int ret = -1;
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
        //2번째 이동에서 visited[0][15] = true. 4번째 이동에서 visited[0][15]를 검사하므로 이 때가 최소 시간이다
        if (visited[mov % 2][k]) {
            ret = mov;
            break;
        }

        int q_size = q.size();

        bool flag = false;

        while (q_size--) {
            int cur = q.front(); q.pop();

            for (int ncur : {cur - 1, cur + 1, cur * 2}) {
                if (ncur == k) { //ncur에서 동생을 찾는다면 즉시 갱신 후 break
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

        mov++;

        if (flag) break;
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
