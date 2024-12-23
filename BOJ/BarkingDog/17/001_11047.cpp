#include<iostream>
using namespace std;

int n, k, a[11], ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		if (k == 0) break;
		if (a[i] > k) continue;

		ret += k / a[i];
		k %= a[i];
	}

	cout << ret;

	return 0;
}
