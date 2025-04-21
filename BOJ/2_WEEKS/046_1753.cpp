#include<iostream>
#include<vector>
#include<queue> //priority_queue
#include<climits> //INT_MAX
using namespace std;

vector<pair<int, int>> adj[20005];
int v, e, st, d[20005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> v >> e >> st;

	fill(d, d + v + 1, INT_MAX);

	for (int i = 0; i < e; i++) {
		int u, v, w;

		cin >> u >> v >> w;
		adj[u].push_back({ w,v }); //{u -> v로 가는 데 계산되는 가중치, 목적지 노드}
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //pq greater = 최소 힙

	d[st] = 0; //시작점에서 시작점으로 가는 최단 거리는 0
	pq.push({ d[st],st }); //{st -> st까지의 최단 거리, st}

	while (!pq.empty()) {
		pair<int, int> cur = pq.top(); pq.pop(); //{st -> 목적지 노드까지의 최단 거리, 목적지 노드}

		if (cur.first != d[cur.second]) continue;

		for (pair<int, int> next : adj[cur.second]) {
			if (d[next.second] <= d[cur.second] + next.first) continue;

			d[next.second] = d[cur.second] + next.first; //최단 거리로 갱신
			pq.push({ d[next.second], next.second });
		}
	}

	for (int i = 1; i <= v; i++) {
		if (d[i] == INT_MAX) {
			cout << "INF\n";
		}
		else {
			cout << d[i] << '\n';
		}
	}

	return 0;
}
