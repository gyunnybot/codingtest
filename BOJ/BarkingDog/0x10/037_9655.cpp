#include<iostream>
using namespace std;

int n;
int dp[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (i % 2) {
			dp[i] = 1;
		}
		else {
			dp[i] = 0;
		}
	}

	if (dp[n] == 1) {
		cout << "SK\n";
	}
	else {
		cout << "CY\n";
	}

	return 0;
}
