#include<iostream>
using namespace std;

int n, t[16], p[16], dp[16];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = max(dp[i], dp[i - 1]);

		if (i + t[i] <= n + 1) {
			dp[i + t[i] - 1] = max(dp[i + t[i] - 1], dp[i - 1] + p[i]);
		}
	}

	cout << dp[n];

	return 0;
}
