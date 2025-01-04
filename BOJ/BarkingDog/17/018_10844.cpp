#include<iostream>
using namespace std;
typedef long long ll;

int n;
ll dp[101][10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1] % 1000000000;

		for (int j = 1; j <= 8; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}

		dp[i][9] = dp[i - 1][8] % 1000000000;
	}
	
	ll ret = 0;

	for (int i = 0; i <= 9; i++) {
		ret = (ret + dp[n][i]) % 1000000000;
	}

	cout << ret;

	return 0;
}
