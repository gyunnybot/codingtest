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

		dp[0] = 1; //0원을 만드는 경우의 수 = 동전을 하나도 사용하지 않는 경우 1가지

		for (int i = 1; i <= n; i++) {
			for (int j = a[i]; j <= k; j++) {
				dp[j] = dp[j] + dp[j - a[i]]; //최신 dp = 기존 dp + 가치가 더 큰 동전을 추가로 사용한 경우의 수
			}
		}

		cout << dp[k] << '\n';
	}

	return 0;
}
