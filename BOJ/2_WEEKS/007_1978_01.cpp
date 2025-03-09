#include<iostream>
using namespace std;

int n, num, ret;

bool check(int num) {
	if (num <= 1) return false;

	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) return false;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;

		if (check(num)) {
			ret++;
		}
	}

	cout << ret;

	return 0;
}
