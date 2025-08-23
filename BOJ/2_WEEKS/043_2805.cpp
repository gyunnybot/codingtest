#include<iostream>
#include<algorithm> //sort
using namespace std;
typedef long long ll;

int n, m, a[1000001];
ll ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	ll st = 0;
	ll ed = *prev(a + n);

	while (st <= ed) {
		ll wood = 0;
		ll cut = (st + ed + 1) / 2;	

		for (int i = 0; i < n; i++) {
			if (a[i] - cut > 0) {
				wood += a[i] - cut;
			}
		}

		if (wood >= m) {
			ret = max(ret, cut);
			st = cut + 1;
		}
		else {
			ed = cut - 1;
		}
	}

	cout << ret;

	return 0;
}
