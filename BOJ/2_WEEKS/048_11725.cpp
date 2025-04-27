#include<iostream>
#include<vector>
using namespace std;

int n, a, b, parent[100001];
bool visited[100001];
vector<int> adj[100001];

void dfs(int here) {
	visited[here] = true;

	for (int there : adj[here]) {
		if (!visited[there]) {
			parent[there] = here;
			dfs(there);
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}

	return 0;
}
