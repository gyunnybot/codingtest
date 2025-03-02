#include<iostream>
using namespace std;

int n, dp[1000001], pre[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	dp[1] = 0;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		pre[i] = i - 1;

		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
			dp[i] = dp[i / 2] + 1;
			pre[i] = i / 2;
		}

		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) { //visited가 없으므로 감소 폭이 큰 연산을 나중에 실행
			dp[i] = dp[i / 3] + 1;
			pre[i] = i / 3;
		}		
	}

	cout << dp[n] << '\n';

	int cur = n;

	while (true) {
		if (cur == 1) {
			cout << cur;
			break;
		}
		else {
			cout << cur << ' ';
			cur = pre[cur];
		}
	}

	return 0;
}
