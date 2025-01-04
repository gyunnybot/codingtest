#include<iostream>
#include<algorithm> //sort
using namespace std;

int n, v, a[101], cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cin >> v;

	sort(a, a + n);

	cout << upper_bound(a, a + n, v) - lower_bound(a, a + n, v);

	return 0;
}
