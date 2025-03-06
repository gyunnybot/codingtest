#include<iostream>
using namespace std;

int n, ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int a = 1; a <= n; a++) { //택희
		for (int b = 1; b <= n; b++) { //영훈
			for (int c = 1; c <= n; c++) { //남규
				if ((a + b + c == n) && (c >= b + 2) && (a % 2 == 0)) {
					ret++;
				}
			}
		}
	}

	cout << ret;

	return 0;
}
