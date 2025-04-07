#include<iostream>
#include<algorithm> //sort
#include<vector>
using namespace std;

int n, a, b, dp[101], ret;
vector<pair<int, int>> line;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		line.push_back({ a,b });
	}

	sort(line.begin(), line.end());

	fill(&dp[0], &dp[0] + 101, 1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (line[i].second > line[j].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		ret = max(ret, dp[i]);
	}

	cout << n - ret;

	return 0;
}
