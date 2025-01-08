#include<iostream>
using namespace std;

int n;
string dp[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (i % 2) {
			dp[i] = "SK";
		}
		else {
			dp[i] = "CY";
		}
	}

	cout << dp[n];

	return 0;
}