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

	fill(d + 1, d + v + 1, INT_MAX); //d[1] ~ d[v]

	for (int i = 0; i < e; i++) {
		int u, v, w;

		cin >> u >> v >> w;
		adj[u].push_back({ w,v }); //{가중치, 목적지 노드}
	}

	cin >> st >> ed;

	//pq greater = 최소 힙
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	d[st] = 0;
	pq.push({ d[st],st }); //{st에서 노드까지의 최소 거리, 현재 노드}

	while (!pq.empty()) {
		pair<int, int> cur = pq.top(); pq.pop();

		if (cur.first != d[cur.second]) continue; //cur.first가 이미 정해진 최소 거리 d[cur.second]가 아니라면

		for (pair<int, int> next : adj[cur.second]) { //연결된 노드로 나아가기
			if (d[next.second] <= d[cur.second] + next.first) continue;

			d[next.second] = d[cur.second] + next.first; //최단 거리로 갱신
			pq.push({ d[next.second],next.second });

			pre[next.second] = cur.second; //현재 도시 이전에 방문했던 도시 번호 저장
		}
	}

	cout << d[ed] << '\n';

	vector<int> ret_vector;
	int idx = ed;

	while (true) {
		if (idx == st) {
			ret_vector.push_back(idx);
			break;
		}

		ret_vector.push_back(idx);
		idx = pre[idx];
	}

	cout << ret_vector.size() << '\n';
	
	reverse(ret_vector.begin(), ret_vector.end());

	for (int i : ret_vector) {
		cout << i << ' ';
	}

	return 0;
}
