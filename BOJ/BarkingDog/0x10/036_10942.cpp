#include<iostream>
using namespace std;

int n, m, a[2001], dp[2001][2001], s, e;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		dp[i][i] = 1; //i부터 i까지. 한자리 수는 팰린드롬

		if (i != 1 && a[i - 1] == a[i]) {
			dp[i - 1][i] = 1; //두자리수가 같은 경우
		}
	}
	
	for (int i = 2; i < n; i++) {
		for (int j = 1; i + j <= n; j++) {
			if (a[j] == a[i + j] && dp[j + 1][i + j - 1] == 1) {
				dp[j][i + j] = 1;
			}
		}
	}

	cin >> m;

	while (m--) {
		cin >> s >> e;

		if (dp[s][e]) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
	return 0;
}
