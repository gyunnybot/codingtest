#include<iostream>
#include<vector>
#include<algorithm> //sort
using namespace std;

struct Info {
	int	cost, a, b;
};
vector<Info> info;

int v, e, a, b, c;
vector<int> p(10001, -1); //시작 노드의 차수는 1로 고정

bool cmp(Info a, Info b) {
	return a.cost < b.cost;
}

int find(int x) {
	if (p[x] < 0) {
		return x;
	}

	return find(p[x]);
}

bool uni(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return false;

	if (p[u] > p[v]) {
		swap(u, v);
	}

	if (p[u] == p[v]) {
		p[u]--;
	}

	p[v] = u;

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		info.push_back({ c,a,b });
	}
	
	sort(info.begin(), info.end(), cmp);

	int cnt = 0;
	int ret = 0;

	for (int i = 0; i < e; i++) {
		if (!uni(info[i].a, info[i].b)) continue;

		ret += info[i].cost;
		cnt++;

		if (cnt == v - 1) break;
	}

	cout << ret;

	return 0;
}
