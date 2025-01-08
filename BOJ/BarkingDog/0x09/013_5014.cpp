#include<iostream>
#include<queue>
using namespace std;

int f, s, g, u, d, visited[1000001];

void bfs(int start) {
    visited[start] = 1;

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int here = q.front(); q.pop();

        if (here == g) break;

        for (int next : {here + u, here - d}) {
            if (1 <= next && next <= f) {
                if (!visited[next]) {
                    visited[next] = visited[here] + 1;
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
