#include<iostream>
#include<queue>
using namespace std;

int n, k, visited[100001];

void bfs(int n) {
    visited[n] = 1; //방문 여부

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

    cout << visited[k] - 1;

    return 0;
}
