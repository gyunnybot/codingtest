#include<iostream>
using namespace std;

int n, a[301], dp[301];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	dp[1] = a[1];
	dp[2] = a[2] + a[1];

	for (int i = 3; i <= n; i++) {
		dp[i] = a[i] + max(dp[i - 2], dp[i - 3] + a[i - 1]);
	}
	
	cout << dp[n];

	return 0;
}
