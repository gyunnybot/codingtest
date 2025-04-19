#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, m, a, b, ret, visited[501];
vector<int> adj[501];

void bfs(int here) {
	visited[here] = 1;

	queue<int> q;
	q.push(here);

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int next : adj[cur]) {
			if (!visited[next]) {
				visited[next] = visited[cur] + 1;
				q.push(next);
			}
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

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	/* 입력되는 친구 관계 ai, bi에서 (1 ≤ ai < bi ≤ n)이라는 조건이 없다면 정렬 필요
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	*/

	bfs(1);

	for (int i = 2; i <= n; i++) {
		if (2 <= visited[i] && visited[i] <= 3) { //자신의 친구(2)와 친구의 친구(3)
			ret++;
		}
	}

	cout << ret;

	return 0;
}
