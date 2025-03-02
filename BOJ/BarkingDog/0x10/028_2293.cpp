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

	dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = a[i]; j <= k; j++) {
			dp[j] = dp[j] + dp[j - a[i]];
		}
	}

	cout << dp[k];

	return 0;
}
