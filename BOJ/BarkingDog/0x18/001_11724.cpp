#include<iostream>
#include<vector>
using namespace std;

int n, m, a, b, ret;
bool visited[1001];
vector<int> adj[1001];

void dfs(int here) {
	visited[here] = true;

	for (int there : adj[here]) {
		if (!visited[there]) {
			dfs(there);
		}
	}

	return;
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

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
			ret++;
		}
	}

	cout << ret;

	return 0;
}
