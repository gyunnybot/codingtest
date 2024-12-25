#include<iostream>
#include<algorithm> //sort
using namespace std;

pair<int, int> L[1000004];
int ret, l, r, n, st, ed;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> st >> ed;
		L[i] = { st,ed };
	}

	sort(L, L + n);

	l = L[0].first; r = L[0].second;

	for (int i = 1; i < n; i++) {
		if (r < L[i].first) {
			ret += r - l;

			l = L[i].first;
			r = L[i].second;
		}
		else if (L[i].first <= r && r <= L[i].second) { //겹칠 경우 r만 수정
			r = L[i].second;
		}
	}

	ret += r - l;

	cout << ret << '\n';

	return 0;
}
