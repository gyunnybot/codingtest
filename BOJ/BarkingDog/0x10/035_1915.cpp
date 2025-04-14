#include<iostream>
using namespace std;

int n, m, a[1001][1001], dp[1001][1001], max_length;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> s;

		for (int j = 1; j <= m; j++) {
			a[i][j] = s[j - 1] - '0';
		}
	}

	dp[0][0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j]) {
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;

				if (dp[i][j] > max_length) {
					max_length = dp[i][j];
				}
			}
		}
	}

	cout << max_length * max_length;

	return 0;
}
