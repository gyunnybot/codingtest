#include<iostream>
using namespace std;

int n, dp[1000001]; //dynamic programming

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	//첫째 줄에 1보다 크거나 같고, 10^6보다 작거나 같은 정수 N이 주어진다
	//dp[0]을 물어보는 예제는 입력되지 않는다
	dp[1] = 0;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;

		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
	}

	cout << dp[n];

	return 0;
}
