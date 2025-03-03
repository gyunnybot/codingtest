#include<iostream>
#include<vector>
using namespace std;

int n, r, q, a, b, ret[100001];
bool visited[100001];
vector<int> adj[100001];

int dfs(int here) {
	visited[here] = true;
	ret[here] = 1;

	for (int there : adj[here]) {
		if (visited[there]) continue;
		
		ret[here] += dfs(there);
	}

	return ret[here];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> r >> q;

	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(r);
	 
	for (int i = 0; i < q; i++) {
		cin >> r;
		cout << ret[r] << '\n';
	}

	return 0;
}
