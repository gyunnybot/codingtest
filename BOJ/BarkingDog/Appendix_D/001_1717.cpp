#include<iostream>
#include<vector>
using namespace std;

vector<int> p(1000001, -1);
int n, m, q, a, b;

int find(int x) {
	if (p[x] < 0) {
		return x;
	}

	return find(p[x]); //같은 루트를 가지는지 재귀적으로 탐색
}

bool uni(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return false; //두 정점의 루트가 같다면 이미 하나의 집합이므로 false

	if (p[u] > p[v]) { //v의 차수가 더 높다면(v의 트리 높이가 더 높다면)
		swap(u, v); //항상 u의 차수가 더 높도록 변경하기(p[u] <= p[v])
	}

	if (p[u] == p[v]) { //두 정점의 차수가 같다면(u와 v 트리 높이가 같다면)
		p[u]--; //항상 u의 차수가 더 높도록 변경하기(p[u] < p[v])
	}

	p[v] = u; //u를 v의 루트로 설정

	return true; //합친 후 true
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> q >> a >> b;

		if (q == 0) {
			uni(a, b);
		}
		else {
			if (find(a) == find(b)) {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
	}

	return 0;
}
