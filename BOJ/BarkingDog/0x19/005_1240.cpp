#include<iostream>
#include<vector>
using namespace std;

int n, m, a, b, dist, ret;
bool visited[1001];
vector<pair<int, int>> adj[1001];

void dfs(int from, int to, int dist) {
	visited[from] = true;

	if (from == to) {
		ret = dist;
		return;
	}

	for (pair<int, int> cur : adj[from]) {		
		int next = cur.first;
		int d = dist + cur.second;

		if (!visited[next]) {
			dfs(next, to, d);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> dist;

		adj[a].push_back({ b,dist });
		adj[b].push_back({ a,dist });
	}

	for (int i = 0; i < m; i++) {
		fill(&visited[0], &visited[0] + 1001, false);

		cin >> a >> b;

		dfs(a, b, 0);

		cout << ret << '\n';
	}

	return 0;
}
