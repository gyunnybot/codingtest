#include<iostream>
#include<vector>
using namespace std;

vector<int> p(1000001, -1);
int n, m, q, a, b;

int find(int x) {
	if (p[x] < 0) {
		return x;
	}
	else {
		p[x] = find(p[x]);
		return p[x];
	}
}

void uni(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) {
		return;
	}

	if (p[u] > p[v]) { //v의 랭크가 더 큰 경우
		swap(u, v);
	}

	if (p[u] == p[v]) {
		p[u]--;
	}

	p[v] = u; //v를 u의 자식으로 만든다  

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	while (m--) {
		cin >> q >> a >> b;

		if (q == 0) {
			uni(a, b);
		}
		else {
			if (find(a) == find(b)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}

	return 0;
}
