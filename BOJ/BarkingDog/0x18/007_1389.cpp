#include<iostream>
#include<vector>
#include<queue>
#include<climits> //INT_MAX
using namespace std;

int n, m, a, b, visited[101], ret, dist;
int min_dist = INT_MAX;
vector<int> adj[101];

int bfs(int n) {
	queue<int> q;
	q.push(n);

	int d = 0; //정점사이의 거리 총합
	visited[n] = 0; //시작점은 0으로 초기화

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int next : adj[cur]) {
			if (visited[next] == -1) {
				visited[next] = visited[cur] + 1;				
				q.push(next);

				d += visited[next];
			}
		}
	}

	return d;
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

	for (int i = 1; i <= n; i++) {
		fill(&visited[0], &visited[0] + 101, -1);

		dist = bfs(i);

		if (min_dist > dist) {
			min_dist = dist;
			ret = i;
		}
	}

	cout << ret;

	return 0;
}
