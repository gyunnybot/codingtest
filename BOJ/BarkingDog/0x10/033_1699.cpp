#include<iostream>
using namespace std;

int n, dp[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		dp[i] = i; //전부 1인 경우 항이 최대개수가 된다

		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1); //제곱수를 하나씩 사용해서 항의 최소개수 찾기
		}
	}

	cout << dp[n];

	return 0;
}
