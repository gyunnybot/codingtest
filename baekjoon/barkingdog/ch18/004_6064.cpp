#include<iostream>
using namespace std;

int t, n, m, x, y;

int gcd(int a, int b) {
	if (a == 0) {
		return b;
	}
	else {
		return gcd(b % a, a);
	}
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int check(int m, int n, int x, int y) {
	if (x == m) {
		x = 0;
	}

	if (y == n) {
		y = 0;
	}

	int L = lcm(m, n);

	for (int i = x; i <= L; i += m) {
		if (i == 0) continue;

		if (i % n == y) {
			return i;
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	while (t--) {
		cin >> m >> n >> x >> y;
		cout << check(m, n, x, y) << '\n';
	}

	return 0;
}