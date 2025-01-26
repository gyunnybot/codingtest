#include<iostream>
#include<vector>
#include<algorithm> //sort
using namespace std;

int n, s, e, t, ret;
vector<pair<int, int>> debate;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		debate.push_back({ s,e });
	}

	sort(debate.begin(), debate.end(), cmp);

	for (int i = 0; i < n; i++) {
		if (t > debate[i].first) continue;

		t = debate[i].second;
		ret++;
	}

	cout << ret;

	return 0;
}
