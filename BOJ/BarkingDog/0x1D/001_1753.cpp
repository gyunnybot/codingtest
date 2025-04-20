#include<iostream>
#include<vector>
#include<queue> //priority_queue
#include<climits> //INT_MAX
using namespace std;

vector<pair<int, int>> adj[20005]; //{거리 비용, 정점 번호}
int v, e, st, d[20005]; //최단 거리 테이블

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> v >> e >> st;

	fill(d, d + v + 1, INT_MAX);

	for (int i = 0; i < e; i++) {
		int u, v, w;

		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	d[st] = 0; //시작점의 최단 거리는 0으로 고정
	pq.push({ d[st],st });

	while (!pq.empty()) {
		pair<int, int> cur = pq.top(); pq.pop(); //{거리 비용, 정점 번호}

		//해당 번호의 최단 거리와 번호까지의 거리 비용이 다르다면
		//cur.first가 d[cur.second]보다 크다면 d[번호]의 값을 바꿀 필요가 없음
		if (d[cur.second] != cur.first) continue;

		for (pair<int,int> next : adj[cur.second]) {
			if (d[next.second] <= d[cur.second] + next.first) continue;

			d[next.second] = d[cur.second] + next.first;
			pq.push({ d[next.second], next.second });
		}
	}

	for (int i = 1; i <= v; i++) {
		if (d[i] == INT_MAX) cout << "INF\n";
		else cout << d[i] << '\n';
	}

	return 0;
}