#include<iostream>
#include<vector>
using namespace std;

vector<int> parent(1000001, -1);
int t, n, k, a, b, m, u, v;

int find(int x) {
	if (parent[x] < 0) {
		return x;
	}

	return find(parent[x]); //같은 루트를 가지는지 재귀적으로 탐색
}

bool uni(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return false; //두 정점의 루트가 같다면 이미 하나의 집합이므로 false

	if (parent[u] > parent[v]) { //v의 차수가 더 높다면(v의 트리 높이가 더 높다면)
		swap(u, v); //항상 u의 차수가 더 높도록 변경하기 1(parent[u] <= parent[v])
	}

	if (parent[u] == parent[v]) { //두 정점의 차수가 같다면(u와 v 트리 높이가 같다면)
		parent[u]--; //항상 u의 차수가 더 높도록 변경하기 2(parent[u] < parent[v])
	}

	parent[v] = u; //u를 v의 루트로 설정

	return true; //합친 후 true
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> k;

		fill(parent.begin(), parent.begin() + n, -1);
		
		while (k--) {
			cin >> a >> b;
			uni(a, b);
		}

		cin >> m;

		cout << "Scenario " << tc << ":" << '\n';

		while (m--) {
			cin >> u >> v;
			cout << (find(u) == find(v)) << '\n';
		}

		cout << '\n';
	}

	return 0;
}
