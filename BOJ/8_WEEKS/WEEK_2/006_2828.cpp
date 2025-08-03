#include<iostream>
using namespace std;

int n, m, j, k, cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> j;

	int l = 1, r = l + m - 1;

	while (j--) {
		cin >> k;

		if (l <= k && k <= r) {
			continue;
		}
		else {
			if (k < l) {
				cnt += l - k;

				l = k;
				r = l + m - 1;
			}
			else if (r < k) {
				cnt += k - r;

				r = k;
				l = r - m + 1;
			}
		}
	}

	cout << cnt;

	return 0;
}
