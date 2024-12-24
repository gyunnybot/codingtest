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

	for (int i = n - 1; i >= 0; i--) {
		dp[i] = dp[i + 1];

		if (i + t[i] <= n) {
			dp[i] = max(dp[i], dp[i + t[i]] + p[i]);
		}
	}

	cout << dp[0];

	return 0;
}
