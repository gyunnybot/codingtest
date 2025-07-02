#include<iostream>
#include<vector>
using namespace std;

int n, m, a, b, ret, tc;
bool visited[501], isTree;
vector<int> adj[501];

void dfs(int here, int prev) {
    visited[here] = true;

    for (int there : adj[here]) {
        if (there == prev) { //원소가 부모 노드일 경우
            continue;
        }

        if (visited[there]) { //부모가 아닌데 재방문한 경우 cycle. 트리가 아니다
            isTree = false;
            break;
        }

        dfs(there, here);
    }

    return;
}

void init() {
    fill(&visited[0], &visited[0] + 501, false);

    for (int i = 0; i < 501; i++) {
        adj[i].clear();
    }

    ret = 0;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        init();

        for (int i = 0; i < m; i++) {
            cin >> a >> b;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for (int i = 1; i <= n; i++) {
            if (visited[i]) continue;

            isTree = true;

            dfs(i, -1);

            ret += isTree;
        }

        cout << "Case " << ++tc << ": ";

        if (ret == 0) {
            cout << "No trees." << '\n';
        }
        else if (ret == 1) {
            cout << "There is one tree." << '\n';
        }
        else {
            cout << "A forest of " << ret << " trees." << '\n';
        }
    }

    return 0;
}
