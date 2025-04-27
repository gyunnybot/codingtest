#include<iostream>
#include<algorithm> //sort
using namespace std;
typedef long long ll;

int n, m, a[1000001], ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	int st = 0;
	int ed = *prev(a + n);

	while (st <= ed) {
		ll wood = 0;

		int cut = (st + ed + 1) / 2;	

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
