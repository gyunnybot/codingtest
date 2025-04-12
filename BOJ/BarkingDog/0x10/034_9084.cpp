#include<iostream>
using namespace std;

int t, n, k, a[101], dp[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	while (t--) {
		fill(&a[0], &a[0] + 101, 0);
		fill(&dp[0], &dp[0] + 10001, 0);

		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}

		cin >> k;

		dp[0] = 1; //동전을 하나도 쓰지 않는 경우

		for (int i = 1; i <= n; i++) {
			for (int j = a[i]; j <= k; j++) {
				dp[j] = dp[j] + dp[j - a[i]];
			}
		}

		cout << dp[k] << '\n';
	}

	return 0;
}
