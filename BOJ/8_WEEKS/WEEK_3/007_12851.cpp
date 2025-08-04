#include<iostream>
#include<queue>
using namespace std;

int n, k;
int visited[100001], cnt[100001];

void bfs(int n) {
    visited[n] = 1; //방문 여부
    cnt[n] = 1; //방문 횟수

    queue<int> q;
    q.push(n);

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        if (cur == k) break;

        for (int next : {cur - 1, cur + 1, cur * 2}) {
            if (0 <= next && next <= 100000) {
                if (!visited[next]) {
                    visited[next] = visited[cur] + 1;
                    q.push(next);

                    cnt[next] = cnt[cur];
                }
                else if (visited[next] == visited[cur] + 1) { //방문 여부가 이미 존재한다면
                    cnt[next] += cnt[cur];
                }
            }
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    bfs(n);

    cout << visited[k] - 1 << '\n' << cnt[k];

    return 0;
}
