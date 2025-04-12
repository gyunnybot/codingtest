#include<iostream>
using namespace std;

int n, dp[31];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;

	for (int i = 4; i <= n; i += 2) {
		dp[i] = dp[i - 2] * dp[2];

		for (int j = i - 4; j >= 0; j -= 2) {
			dp[i] = dp[i] + (dp[j] * 2);
		}
	}

	if (n % 2) {
		cout << 0;
	}
	else {
		cout << dp[n];
	}

	return 0;
}
