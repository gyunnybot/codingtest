#include<iostream>
#include<vector>
#include<queue> //priority_queue
#include<climits> //INT_MAX
#include<algorithm> //reverse
using namespace std;

vector<pair<int, int>> adj[1001];
int v, e, st, ed, d[1001], pre[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> v >> e;

	fill(d, d + v + 1, INT_MAX);

	for (int i = 1; i <= e; i++) {
		int u, v, w;

		cin >> u >> v >> w;
		adj[u].push_back({ w,v }); //{가중치, 목적지 노드}
	}

	cin >> st >> ed;

	//pq greater = 최소 힙. {st에서 노드까지의 최소 거리, 현재 노드}
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	d[st] = 0;
	pq.push({ d[st],st });

	while (!pq.empty()) {
		pair<int, int> cur = pq.top(); pq.pop();

		if (cur.first != d[cur.second]) continue; //우선순위 큐에서 밀린 원소는 최단 경로가 아니다

		for (pair<int, int> next : adj[cur.second]) {
			if (d[next.second] <= d[cur.second] + next.first) continue;

			d[next.second] = d[cur.second] + next.first; //최단 거리 갱신
			pq.push({ d[next.second],next.second });

			pre[next.second] = cur.second; //최단 경로로 거쳐간 이전 도시 번호 저장
		}
	}

	cout << d[ed] << '\n';

	vector<int> v;

	int idx = ed;

	while (idx != st) {
		v.push_back(idx);
		idx = pre[idx];
	}

	v.push_back(idx);

	reverse(v.begin(), v.end());

	cout << v.size() << '\n';

	for (int i : v) {
		cout << i << ' ';
	}

	return 0;
}
