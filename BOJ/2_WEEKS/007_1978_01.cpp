#include<iostream>
using namespace std;

int n, num, ret;

bool check(int num) {
	if (num <= 1) return false;

	//제곱근 이하의 수는 항상 제곱근 이상의 수와 곱해져 num이 된다
	//따라서, 제곱근까지만 조사해도 전체 경우의 수를 탐색하게 된다
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
