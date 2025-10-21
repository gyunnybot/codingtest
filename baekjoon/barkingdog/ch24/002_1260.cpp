#include<iostream>
#include<vector>
#include<queue>
#include<algorithm> //sort
using namespace std;

int n, m, v, a, b, ret;
bool visited[1001];
vector<int> adj[1001];

void dfs(int here) {
	visited[here] = true;
	cout << here << ' ';

	for (int there : adj[here]) {
		if (!visited[there]) {
			dfs(there);
		}
	}

	return;
}

void bfs(int here) {
	visited[here] = true;
	cout << here << ' ';

	queue<int> q;
	q.push(here);

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int next : adj[cur]) {
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);

				cout << next << ' ';
			}
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	//연결된 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문한다
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	dfs(v);

	fill(&visited[0], &visited[0] + 1001, false); cout << '\n';	//dfs로 인한 방문 초기화

	bfs(v);

	return 0;
}
