#include<iostream>
using namespace std;

int n, m, temp, a[41], dp[41];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}

	dp[0] = 1; //vip 좌석이 연속으로 붙어있을 때, 그 사이를 1로 생각해야 ret 곱셈 연산이 가능하다
	dp[1] = 1; //1
	dp[2] = 2; //1 2, 2 1

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	int ret = 1; //곱셈 연산을 위해 1로 초기화
	int st = 0;

	for (int i = 0; i < m; i++) {
		int ed = a[i];

		ret *= dp[ed - st - 1];
		st = ed;
	}

	ret *= dp[n - st];

	cout << ret;

	return 0;
}
