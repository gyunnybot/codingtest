#include<iostream>
#include<vector>
#include<queue>
#include<climits> //INT_MAX
using namespace std;

int n, a, b, ret[51], visited[51];
int min_val = INT_MAX;
vector<int> adj[51], v;

int bfs(int n) {
	visited[n] = 1;

	queue<int> q;
	q.push(n);

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int next : adj[cur]) {
			if (!visited[next]) {
				visited[next] = visited[cur] + 1;
				q.push(next);
			}
		}
	}

	int max_visited = 1;

	for (int i = 1; i <= 50; i++) {
		max_visited = max(max_visited, visited[i]);
	}

	return max_visited - 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (cin >> a >> b) {
		if (a == -1 && b == -1) {
			break;
		}

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		fill(&visited[0], &visited[0] + 51, 0);
		ret[i] = bfs(i);
	}
	
	for (int i = 1; i <= n; i++) {
		min_val = min(min_val, ret[i]);
	}

	for (int i = 1; i <= n; i++) {
		if (ret[i] == min_val) {
			v.push_back(i);
		}
	}

	cout << min_val << ' ' << v.size() << '\n';

	for (int i : v) {
		cout << i << ' ';
	}

	return 0;
}
