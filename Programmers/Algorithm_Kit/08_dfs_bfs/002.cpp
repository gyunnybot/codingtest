#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool visited[201];
vector<int> adj[201];

void dfs(int here) {
    visited[here] = true;

    for (int there : adj[here]) {
        if (!visited[there]) {
            dfs(there);
        }
    }

    return;
}

int solution(int n, vector<vector<int>> computers) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (computers[i][j] == 1) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    int answer = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            answer++;
        }
    }

    return answer;
}
