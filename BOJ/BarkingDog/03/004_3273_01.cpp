#include<iostream>
using namespace std;

int n, a[1000001], x, ret;
bool cnt[2000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cin >> x;

	for (int i = 0; i < n; i++) {
		if (x - a[i] >= 0 && cnt[x - a[i]]) {
			ret++;
		}

		cnt[a[i]] = true;
	}

	cout << ret;

	return 0;
}
