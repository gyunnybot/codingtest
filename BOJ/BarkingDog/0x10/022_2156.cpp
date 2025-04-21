#include<iostream>
#include<algorithm> //max_element
using namespace std;

int n, a[10001], dp[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	dp[1] = a[1];
	dp[2] = a[1] + a[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2], a[i - 1] + dp[i - 3]) + a[i];
		dp[i] = max(dp[i], dp[i - 1]); //i번째 포도주의 양이 매우 적어 선택 시 오히려 손해인 경우
		//2579번 계단 오르기와 달리 dp[i]에서 반드시 i번째 값을 선택할 의무가 없다
	}

	cout << *max_element(dp + 1, dp + n + 1);

	return 0;
}
