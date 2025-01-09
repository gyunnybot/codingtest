#include<iostream>
using namespace std;
typedef long long ll;

int n;
ll dp[101][10]; //자릿수의 길이, 끝 자릿수

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= 9; i++) { //0으로 시작하는 수는 계단수가 아니다
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1] % 1000000000; //i자릿수의 끝이 0인 수는 반드시 i-1자릿수의 끝이 1인 수에서 파생된다

		for (int j = 1; j <= 8; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}

		dp[i][9] = dp[i - 1][8] % 1000000000; //i자릿수의 끝이 9인 수는 반드시 i-1자릿수의 끝이 8인 수에서 파생된다
	}
	
	ll ret = 0;

	for (int i = 0; i <= 9; i++) {
		ret = (ret + dp[n][i]) % 1000000000;
	}

	cout << ret;

	return 0;
}
