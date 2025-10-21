#include<iostream>
#include<algorithm> //mex_element
using namespace std;

int n, a[501][501], dp[501][501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) { //행
		for (int j = 1; j <= i; j++) { //열
			cin >> a[i][j];
		}
	}

	dp[1][1] = a[1][1];

	for (int i = 2; i <= n; i++) { //행
		for (int j = 1; j <= i; j++) { //열
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
		}
	}

	cout << *max_element(dp[n] + 1, dp[n] + n + 1); //dp[n][1] ~ dp[n][n]

	return 0;
}
