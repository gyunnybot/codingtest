/*
#include<iostream>
#include<climits> //INT_MAX
using namespace std;

int n, k, w[101], v[101];
int ret = INT_MIN;

void recur(int idx, int weight, int value) {
	if (weight > k) {
		return;
	}

	if (idx == n) {
		ret = max(ret, value);
		return;
	}

	recur(idx + 1, weight + w[idx], value + v[idx]);
	recur(idx + 1, weight, value);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}

	recur(0, 0, 0);

	cout << ret;

	return 0;
}
*/

#include<iostream>
#include<vector>
#include<climits> //INT_MAX
using namespace std;

int n, k, w[101], v[101];
int ret = INT_MIN;
vector<vector<int>> dp;

int recur(int idx, int weight) {
	if (weight > k) {
		return INT_MIN;
	}

	if (idx == n) {
		return 0;
	}

	if (dp[idx][weight] != -1) { //V(0 ≤ V ≤ 1,000)
		return dp[idx][weight];
	}

	dp[idx][weight] = max(recur(idx + 1, weight + w[idx]) + v[idx], recur(idx + 1, weight));

	return dp[idx][weight];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	dp.resize(n, vector<int>(k + 1, -1)); //V(0 ≤ V ≤ 1,000), init

	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}

	cout << recur(0, 0);

	return 0;
}
