#include<iostream>
#include<algorithm> //sort
#include<vector>
using namespace std;

int n, xpos, ypos;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}

	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> xpos >> ypos;
		v.push_back({ xpos,ypos });
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}

	return 0;
}
