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

	dp[0] = 1; //0원을 만드는 경우의 수는 동전을 하나도 사용하지 않는 경우 단 1가지이다

	for (int i = 1; i <= n; i++) {
		for (int j = a[i]; j <= k; j++) {
			dp[j] = dp[j] + dp[j - a[i]]; //최신 dp = 기존 dp + 가치가 더 큰 동전을 한 번 사용한 경우의 수
		}
	}
	
	cout << dp[k];

	return 0;
}
