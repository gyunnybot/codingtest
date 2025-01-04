#include<iostream>
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

	for (int i = 0; i < n; i++) {
		if (v == a[i]) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}
