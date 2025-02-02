#include<iostream>
using namespace std;

int n, a[1001], dp[1001], ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	fill(&dp[0], &dp[0] + 1001, 1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j]) {
				dp[i] = max(dp[i], dp[j] + 1); //각 원소까지의 증가하는 부분 수열의 길이
			}
		}
	}

	for (int i = 0; i < n; i++) {
		ret = max(ret, dp[i]); //증가하는 부분 수열의 최대 길이
	}

	cout << ret;

	return 0;
}
