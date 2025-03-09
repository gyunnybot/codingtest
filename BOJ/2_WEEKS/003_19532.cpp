#include<iostream>
using namespace std;

int a, b, c, d, e, f;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b >> c >> d >> e >> f;

	for (int x = -999; x <= 999; x++) {
		for (int y = -999; y <= 999; y++) {
			if (a * x + b * y == c && d * x + e * y == f) {
				cout << x << ' ' << y;
				break; //방정식을 만족하는 해 (x, y)는 유일하게 존재한다
			}
		}
	}

	return 0;
}
