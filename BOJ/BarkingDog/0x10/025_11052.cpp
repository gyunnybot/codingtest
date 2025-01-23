#include<iostream>
using namespace std;

int n, m, temp, a[1001], dp[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	dp[1] = a[1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + a[j]);
		}
	}

	cout << dp[n];

	return 0;
}
