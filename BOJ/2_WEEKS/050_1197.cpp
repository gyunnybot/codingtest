#include<iostream>
#include<vector>
#include<algorithm> //sort
using namespace std;

struct Info {
	int a, b, weight;
};
vector<Info> info;

int v, e, a, b, w, cnt, ret;
vector<int> p(10001, -1);

bool cmp(Info a, Info b) {
	return a.weight < b.weight;
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
		cin >> a >> b >> w;
		info.push_back({ a,b,w });
	}

	sort(info.begin(), info.end(), cmp); //가중치 오름차순

	for (int i = 0; i < e; i++) {
		if (!uni(info[i].a, info[i].b)) continue; //이미 연결되어 있다면 continue

		ret += info[i].weight;
		cnt++;

		if (cnt == v - 1) break;
	}

	cout << ret;

	return 0;
}
