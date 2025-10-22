#include<iostream>
#include<vector>
using namespace std;

int n, m, a, b, v[10001], ret;
bool visited[10001];
vector<int> adj[10001];

int dfs(int here) {
	visited[here] = true;

	int cnt = 1;

	for (int there : adj[here]) {
		if (!visited[there]) {
			cnt += dfs(there);
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		fill(&visited[0], &visited[0] + 10001, false);

		v[i] = dfs(i);
		ret = max(ret, v[i]);
	}

	for (int i = 1; i <= n; i++) {
		if (v[i] == ret) {
			cout << i << ' ';
		}
	}

	return 0;
}
