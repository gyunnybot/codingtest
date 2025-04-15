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
		dp[i][i] = 1; //길이가 1인 모든 구간은 팰린드롬

		if (i != 1 && a[i - 1] == a[i]) {
			dp[i - 1][i] = 1; //연속된 두 숫자가 같으면 팰린드롬
		}
	}
	
	for (int i = 2; i < n; i++) { //i: 팰린드롬의 길이 - 1
		for (int j = 1; i + j <= n; j++) { //j: 시작 인덱스, i + j: 끝 인덱스
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
