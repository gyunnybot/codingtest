#include<iostream>
#include<vector>
#include<algorithm> //reverse
using namespace std;

int n, a[1001], dp[1001], ret;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[i] = 1;
	}

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

	cout << ret << '\n';

	for (int i = n - 1; i >= 0; i--) {
		if (dp[i] == ret) {
			v.push_back(a[i]);
			ret--;
		}
	}

	reverse(v.begin(), v.end());

	for (int i : v) {
		cout << i << ' ';
	}

	return 0;
}
