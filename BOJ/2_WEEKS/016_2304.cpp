#include<iostream>
using namespace std;

int n, x, y, a[1001], s[1001];
int maxPos, maxVal;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;

		a[x] = y;

		if (y >= maxVal) {
			maxPos = x;
			maxVal = y;			
		}
	}

	for (int i = 2; i < maxPos; i++) {
		if (a[i - 1] >= a[i]) {
			a[i] = a[i - 1];
		}
	}

	for (int i = 999; i > maxPos; i--) {
		if (a[i + 1] > a[i]) {
			a[i] = a[i + 1];
		}
	}

	for (int i = 1; i <= 1000; i++) {
		s[i] = s[i - 1] + a[i];
	}

	cout << s[1000];

	return 0;
}
