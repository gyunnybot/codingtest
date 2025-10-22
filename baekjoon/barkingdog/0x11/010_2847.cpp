#include<iostream>
using namespace std;

int n, a[101], ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = n - 1; i > 0; i--) {
		if (a[i] <= a[i - 1]) {
			ret += (a[i - 1] - (a[i] - 1));
			a[i - 1] = a[i] - 1;
		}
	}

	cout << ret;

	return 0;
}
