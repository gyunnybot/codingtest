#include<iostream>
using namespace std;

int n, dp[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	dp[1] = 1;
	dp[2] = 0;
	dp[3] = 1;
	dp[4] = 1;
	dp[5] = 1;

	for (int i = 6; i <= n; i++) {
		if (!dp[i - 1] || !dp[i - 3] || !dp[i - 4]) {
			dp[i] = 1;
		}
		else {
			dp[i] = 0;
		}
	}

	if (dp[n] == 1) {
		cout << "SK\n";
	}
	else {
		cout << "CY\n";
	}

	return 0;
}
