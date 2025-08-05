#include<iostream>
#include<climits> //INT_MAX
using namespace std;

int n, a[41];
int ret = INT_MAX;
string s;

void recur(int here) {
	if (here == n) {
		int sum = 0;

		for (int i = 1; i <= (1 << n - 1); i *= 2) {
			int cnt = 0;

			for (int j = 0; j < n; j++) {
				if (a[j] & i) { //a[j]가 'T'라면
					cnt++;
				}
			}

			sum += min(cnt, n - cnt);
		}

		ret = min(ret, sum);

		return;
	}

	recur(here + 1); //뒤집지 않고 재귀 탐색

	a[here] = ~a[here]; //뒤집기

	recur(here + 1); //뒤집은 후 재귀 탐색
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;

		int value = 1;

		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'T') {
				a[i] |= value;
			}

			value *= 2;
		}
	}

	recur(0);

	cout << ret;

	return 0;
}
