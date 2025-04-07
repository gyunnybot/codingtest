#include<iostream>
using namespace std;

int n, t[16], p[16], dp[16];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> t[i] >> p[i];
	}

	for (int idx = n - 1; idx >= 0; idx--) {
		dp[idx] = max(dp[idx], dp[idx + 1]);

		if (idx + t[idx] <= n) {
			dp[idx] = max(dp[idx], dp[idx + t[idx]] + p[idx]);
		}
	}

	cout << dp[0];

	return 0;
}
