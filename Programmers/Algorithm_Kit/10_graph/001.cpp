#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int visited[20001], max_dist;
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

int solution(int n, vector<vector<int>> edge) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < edge.size(); i++) {
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }

    bfs(1);

    int answer = 0;

    for (int i = 1; i <= n; i++) {
        if (visited[i] == max_dist) {
            answer++;
        }
    }

    return answer;
}
