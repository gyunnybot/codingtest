#include<iostream>
#include<algorithm> //sort
using namespace std;

int n, k, a[101], dp[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	dp[0] = 0; //0원을 만들 때 필요한 동전의 갯수 = 0개

	for (int i = 1; i <= k; i++) { //1원만 사용하는 경우가 최대 횟수이다
		dp[i] = k + 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = a[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - a[i]] + 1); //LIS와 비슷한 접근
		}
	}

	if (dp[k] == k + 1) {
		cout << -1;
	}
	else {
		cout << dp[k];
	}

	return 0;
}
