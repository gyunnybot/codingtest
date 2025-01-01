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

	fill(&dp[0], &dp[0] + 1001, 1); //본인을 시작점으로 둘 때 LIS의 길이는 항상 1 이상이다

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	for (int i = 0; i < n; i++) { //수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)
		ret = max(ret, dp[i]);
	}

	cout << ret;

	return 0;
}
