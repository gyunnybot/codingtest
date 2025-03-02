#include<iostream>
using namespace std;

int t, n, dp[41];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//init
	dp[0] = 0;
	dp[1] = 1;
	
	for (int i = 2; i <= 40; i++) { //문제에 제시된 pseudo code에 따라 dp table 완성하기
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cin >> t;

	while (t--) {
		cin >> n;

		if (n == 0) {
			cout << 1 << ' ' << 0 << '\n';
		}
		else if (n == 1) {
			cout << 0 << ' ' << 1 << '\n';
		}
		else {
			cout << dp[n - 1] << ' ' << dp[n] << '\n'; //도식화 후 규칙성을 찾고 dp와 연결
		}
	}

	return 0;
}
