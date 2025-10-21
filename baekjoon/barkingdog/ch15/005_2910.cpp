#include<iostream>
#include<vector>
#include<unordered_map> //unordered_map
#include<algorithm> //sort
using namespace std;

int n, c, temp;
unordered_map<int, int> ump, ump2;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return ump2[a.first] < ump2[b.first];
	}
	else {
		return a.second > b.second;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		cin >> temp;

		ump[temp]++; //값 - 횟수

		if (!ump2[temp]) {
			ump2[temp] = i + 1; //값 - 순서
		}
	}

	for (pair<int, int> i : ump) {
		v.push_back(i);
	}

	sort(v.begin(), v.end(), cmp);

	for (pair<int, int> i : v) {
		for (int j = 0; j < i.second; j++) {
			cout << i.first << ' ';
		}
	}

	return 0;
}
