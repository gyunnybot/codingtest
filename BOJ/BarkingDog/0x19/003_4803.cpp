#include<iostream>
#include<vector>
using namespace std;

int n, m, a, b, ret, tc;
bool visited[501], isTree;
vector<int> adj[501];

void dfs(int here, int prev) {
	visited[here] = true;

	for (int there : adj[here]) {
		if (there == prev) {
			continue; //there이 here의 부모일 경우 dfs 종료. here가 리프 노드가 된다
		}

		if (visited[there]) {
			isTree = false;
			break; //prev가 아닌데 이미 방문한 곳이라면 트리가 아니다
		}

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

			isTree = true; //init

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
