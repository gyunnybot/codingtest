#include<iostream>
using namespace std;

int n, k, w[101], v[101], dp[101][100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}

	for (int idx = n - 1; idx >= 0; idx--) {
		for (int weight = k; weight >= 0; weight--) {
			dp[idx][weight] = max(dp[idx][weight], dp[idx + 1][weight]);

			if (weight + w[idx] <= k) {
				dp[idx][weight] = max(dp[idx][weight], dp[idx + 1][weight + w[idx]] + v[idx]);
			}
		}
	}

	cout << dp[0][0];

	return 0;
}
