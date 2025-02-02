#include<iostream>
#include<algorithm> //sort
using namespace std;
typedef long long ll;

int n, ret;
ll a[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	ll ret = a[0]; //(1 ≤ n ≤ 100,000)
	int maxVal = a[0]; //(1 ≤ n ≤ 100,000)
	int cnt = 1; //(1 ≤ n ≤ 100,000)

	for (int i = 1; i < n; i++) {
		if (a[i] == a[i - 1]) {
			cnt++;
		}
		else {
			cnt = 1;
		}

		if (maxVal < cnt) {
			maxVal = cnt;
			ret = a[i];
		}
	}

	cout << ret;

	return 0;
}
