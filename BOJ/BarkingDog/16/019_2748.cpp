#include<iostream>
using namespace std;
typedef long long ll;

int n;
ll dp[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	
	cin >> n;
	
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n];

	return 0;
}
