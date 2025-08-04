#include<iostream>
#include<vector>
#include<algorithm> //sort
using namespace std;

int t, n, m, a[20001], b[20001];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	while (t--) {
		fill(a, a + 20001, 0); fill(b, b + 20001, 0);

		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}

		sort(a, a + n, cmp);
		sort(b, b + m);

		int cnt = 0;

		//O(N ^ 2)
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i] > b[j]) {
					cnt++;
				}
				else {
					break;
				}
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}
