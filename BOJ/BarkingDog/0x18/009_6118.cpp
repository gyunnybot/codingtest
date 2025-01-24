#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m, a, b, visited[20001], max_dist, cnt;
vector<int> adj[20001];

void bfs(int here) {
    visited[here] = 1;

    queue<int> q;
    q.push(here);

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int next : adj[cur]) {
            if (!visited[next]) {
                visited[next] = visited[cur] + 1;
                q.push(next);

                max_dist = visited[next];
            }
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1);

    for (int i = 1; i <= n; i++) {
        if (visited[i] == max_dist) {
            if (!cnt) {
                cout << i << ' ';
            }

            cnt++;
        }
    }

    cout << max_dist - 1 << ' ' << cnt;

    return 0;
}
