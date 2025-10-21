#include<iostream>
#include<algorithm> //sort
using namespace std;

int n, k, a[101], dp[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	for (int i = 1; i <= k; i++) {
		dp[i] = k + 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = a[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - a[i]] + 1); //최신 dp = min(기존 dp, 단위가 큰 동전을 뺀 dp + 1)
		}
	}

	if (dp[k] == k + 1) {
		cout << -1;
	}
	else {
		cout << dp[k];
	}

	return 0;
}
