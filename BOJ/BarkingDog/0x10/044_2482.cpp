#include<iostream>
using namespace std;

int n, k, dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i <= n; i++) {
		dp[i][1] = i;
		dp[i][0] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= k; j++) {
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % 1000000003;
		}
	}

	cout << (dp[n - 1][k] + dp[n - 3][k - 1]) % 1000000003;

	return 0;
}
