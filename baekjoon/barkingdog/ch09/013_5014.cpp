#include<iostream>
#include<queue>
using namespace std;

int f, s, g, u, d, visited[1000001];

void bfs(int here) {
    visited[here] = 1;

    queue<int> q;
    q.push(here);

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        if (cur == g) break;

        for (int next : {cur + u, cur - d}) {
            if (1 <= next && next <= f) {
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

    cin >> f >> s >> g >> u >> d;

    bfs(s);

    if (visited[g]) {
        cout << visited[g] - 1;
    }
    else {
        cout << "use the stairs";
    }

    return 0;
}
