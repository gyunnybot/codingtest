#include<iostream>
using namespace std;

int n, dp[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	dp[1] = 0; //n이 1일 때

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1; //default

		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) { //visited가 없으므로 감소 폭이 작은 순으로 실행
			dp[i] = dp[i / 2] + 1;
		}

		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
			dp[i] = dp[i / 3] + 1;
		}
	}

	cout << dp[n];

	return 0;
}
