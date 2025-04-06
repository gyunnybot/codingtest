#include<iostream>
#include<vector>
#include<climits> //INT_MAX
using namespace std;

struct info {
	int p, f, s, v, cost;
};
vector<info> ingre;

int n, mp, mf, ms, mv;
int p, f, s, v, cost;
int ret = INT_MAX;
vector<int> temp, mini;

void recur(int idx, int p, int f, int s, int v, int cost) {
	if (p >= mp && f >= mf && s >= ms && v >= mv) { //mini 조합을 완성하는 경우 idx가 n에 도달하기 전에 조건을 만족할 수 있다
		if (ret > cost) {
			ret = cost;
			mini = temp;
		}

		return;
	}

	if (idx == n) { //조건을 만족하는 답이 없을 경우 ret 갱신 없이 return
		return;
	}

	temp.push_back(idx + 1);

	recur(idx + 1, p + ingre[idx].p, f + ingre[idx].f, s + ingre[idx].s, v + ingre[idx].v, cost + ingre[idx].cost);

	temp.pop_back();

	recur(idx + 1, p, f, s, v, cost);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> mp >> mf >> ms >> mv;

	for (int i = 0; i < n; i++) {
		cin >> p >> f >> s >> v >> cost;
		ingre.push_back({ p,f,s,v,cost });
	}

	recur(0, 0, 0, 0, 0, 0);

	if (ret == INT_MAX) {
		cout << -1;
	}
	else {
		cout << ret << '\n';

		for (int i : mini) {
			cout << i << ' ';
		}
	}

	return 0;
}
