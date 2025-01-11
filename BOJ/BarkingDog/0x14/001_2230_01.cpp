#include<iostream>
#include<algorithm> //sort
#include<climits> //INT_MAX
using namespace std;

int n, m, a[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	int ret = INT_MAX;

	int ed = 0;

	for (int st = 0; st < n; st++) {
		while (ed < n && a[ed] - a[st] < m) {
			ed++;
		}

		if (ed == n) break;

		ret = min(ret, a[ed] - a[st]);
	}

	cout << ret;

	return 0;
}