#include<iostream>
using namespace std;

string s;
int a[5001], dp[5001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;

	if (s == "0") {
		cout << 0;
		return 0;
	}

	for (int i = 1; i <= s.size(); i++) {
		a[i] = s[i - 1] - '0';
	}

	dp[0] = 1; //init

	for (int i = 1; i <= s.size(); i++) {
		if (1 <= a[i] && a[i] <= 9) {
			dp[i] = dp[i - 1] + dp[i];
			dp[i] %= 1000000;
		}

		if (i == 1) continue;

		int temp = a[i] + a[i - 1] * 10;

		if (10 <= temp && temp <= 26) {
			dp[i] = dp[i - 2] + dp[i];
			dp[i] %= 1000000;
		}
	}

	cout << dp[s.size()];

	return 0;
}
