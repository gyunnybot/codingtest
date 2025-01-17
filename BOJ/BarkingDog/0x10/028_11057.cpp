#include<iostream>
using namespace std;

int n, dp[1001][10], ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
			}
		}
	}

	for (int i = 0; i <= 9; i++) {
		ret = (ret + dp[n][i]) % 10007;
	}

	cout << ret % 10007;

	return 0;
}
