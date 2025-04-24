#include<iostream>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	int x = n;

	for (int i = 2; i * i <= n; i++) {
		while (x % i == 0) {
			cout << i << '\n';
			x /= i;
		}
	}

	if (x != 1) { //유일하게 n의 제곱근보다 큰 마지막인 소인수가 있다면
		cout << x;
	}

	return 0;
}

/*
n = p * q를 만족하면서 p > sqrt(n) && q > sqrt(n)인 소수쌍 (p, q)는 존재하지 않는다
제곱근보다 큰 소인수가 p, q 두 개 이상이라면 p * q * r * s... > n 이므로 모순이다

다시 말해 p > sqrt(n)라면 반드시 나머지 q는 전부 q < sqrt(n)이어야 한다. 또는 p = q = sqrt(n)

결론적으로 제곱근보다 큰 소인수는 많아봐야 최대 한 개이다
*/
