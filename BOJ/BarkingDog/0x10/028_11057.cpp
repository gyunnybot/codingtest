#include<iostream>
using namespace std;

int n, ret, dp[1001][10]; //[자릿 수][끝자리 수]

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) { //끝자리가 0인 경우는 자릿수가 늘어나도 1가지 밖에 없다
				dp[i][j] = 1;
			}
			else {
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
			}
		}
	}

	for (int i = 0; i <= 9; i++) {
		ret = (ret + dp[n][i]) % 10007;
	}

	cout << ret % 10007;

	return 0;
}
