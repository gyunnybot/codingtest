#include<iostream>
#include<vector>
using namespace std;

int n, a[1025];
vector<int> ret[11];

void recur(int s, int e, int level) {
	if (s > e) return;

	if (s == e) {
		ret[level].push_back(a[s]);
		return;
	}

	int mid = (s + e) / 2;

	ret[level].push_back(a[mid]);

	recur(s, mid - 1, level + 1);
	recur(mid + 1, e, level + 1);

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	int e = (1 << n) - 1;

	for (int i = 0; i < e; i++) {
		cin >> a[i];
	}

	recur(0, e, 1);

	for (int i = 1; i <= n; i++) {
		for (int j : ret[i]) {
			cout << j << ' ';
		}

		cout << '\n';
	}

	return 0;
}
