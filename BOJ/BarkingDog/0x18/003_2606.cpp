#include<iostream>
#include<vector>
using namespace std;

int n, m, a, b;
bool visited[101];
vector<int> adj[101];

int dfs(int here) {
    visited[here] = true;

    int ret = 1;

    for (int there : adj[here]) {
        if (!visited[there]) {
            ret += dfs(there);
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        //무방향 그래프는 두 정점에 대해 모두 push_back
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << dfs(1) - 1;

    return 0;
}
