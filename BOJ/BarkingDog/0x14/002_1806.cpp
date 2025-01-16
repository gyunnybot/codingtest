#include<iostream>
#include<climits> //INT_MAX
using namespace std;

int n, s, a[100001];
int ret = INT_MAX;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int sum = a[0];
	int ed = 0;

	for (int st = 0; st < n; st++) {
		while (ed < n && sum < s) {
			sum += a[++ed];
		}

		if (ed == n) break;

		ret = min(ret, ed - st + 1);

		sum -= a[st];
	}

	cout << (ret == INT_MAX ? 0 : ret);

	return 0;
}