#include<iostream>
#include<vector>
using namespace std;

int n, m, a, b, ret, tc;
bool visited[501], isTree;
vector<int> adj[501];

void dfs(int here, int prev) {
	for (int there : adj[here]) {
		if (there == prev) { //이전 정점으로 돌아가는 경우 cycle인지는 확인할 수 없으나 dfs는 중지
			continue;
		}

		if (visited[there]) { //확실한 cycle일 경우 트리 x
			isTree = false;
			continue;
		}

		visited[there] = true;
		dfs(there, here);
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (cin >> n >> m) {
		if (n == 0 && m == 0) break;

		fill(&visited[0], &visited[0] + 501, false);

		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}

		ret = 0;

		for (int i = 0; i < m; i++) {
			cin >> a >> b;

			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		for (int i = 1; i <= n; i++) {
			if (visited[i]) continue;

			visited[i] = true;
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
