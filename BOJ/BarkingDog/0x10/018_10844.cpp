#include<iostream>
using namespace std;
typedef long long ll;

int n;
int mod = 1000000000;
ll ret, dp[101][10]; //자릿수의 길이, 끝 자릿수

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= 9; i++) { //0으로 시작하는 수는 계단수가 아니다
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1] % mod; //길이가 i, 끝이 0인 수는 반드시 길이가 i - 1, 끝이 1인 수에서 파생된다

		for (int j = 1; j <= 8; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
		}

		dp[i][9] = dp[i - 1][8] % mod; //길이가 i, 끝이 9인 수는 반드시 길이가 i - 1, 끝이 8인 수에서 파생된다
	}

	for (int i = 0; i <= 9; i++) {
		ret = (ret + dp[n][i]) % mod;
	}

	cout << ret;

	return 0;
}
