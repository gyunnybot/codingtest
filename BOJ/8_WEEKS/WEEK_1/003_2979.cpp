#include<iostream>
using namespace std;

int a, b, c, st, ed, ret, cnt[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b >> c;

	for (int i = 0; i < 3; i++) {
		cin >> st >> ed;

		for (int j = st; j < ed; j++) {
			cnt[j]++;
		}
	}

	for (int i = 1; i <= 100; i++) {
		if (cnt[i] == 1) {
			ret += cnt[i] * a;
		}
		else if (cnt[i] == 2) {
			ret += cnt[i] * b;
		}
		else if (cnt[i] == 3) {
			ret += cnt[i] * c;
		}
	}

	cout << ret;

	return 0;
}
