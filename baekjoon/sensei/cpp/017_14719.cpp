#include<iostream>
using namespace std;

int h, w, a[501], ret;
int maxPos, maxVal;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> h >> w;

	for (int i = 1; i <= w; i++) {
		cin >> a[i];

		if (a[i] >= maxVal) {
			maxPos = i;
			maxVal = a[i];
		}
	}

	for (int i = 2; i < maxPos; i++) {
		if (a[i - 1] > a[i]) {
			ret += a[i - 1] - a[i];
			a[i] = a[i - 1];
		}
	}

	for (int i = 499; i > maxPos; i--) {
		if (a[i + 1] > a[i]) {
			ret += a[i + 1] - a[i];
			a[i] = a[i + 1];
		}
	}

	cout << ret;

	return 0;
}
