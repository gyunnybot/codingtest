#include<iostream>
using namespace std;

int gcd, lcm, ret_a, ret_b;

int getGCD(int a, int b) {
	if (a == 0) {
		return b;
	}

	return getGCD(b % a, a);
}

void solve(int gcd, int lcm) {
	int div = lcm / gcd; //a * b * gcd = lcm을 만족하는 서로소 관계인 두 수 a, b의 곱 div

	//두 자연수의 합이 최소가 되는 두 수를 출력한다 -> 반복문을 돌수록 a, b의 차이가 줄어든다
	for (int i = 1; i * i <= div; i++) { //div를 a, b로 분할
		if (div % i == 0) {
			int a = i;
			int b = div / i;

			if (getGCD(a, b) == 1) { //두 수 a, b가 서로소라면
				ret_a = a;
				ret_b = b;
			}
		}
	}

	//결정된 두 수에 최대 공약수를 곱해서 조건을 만족하는 두 자연수 완성
	ret_a *= gcd;
	ret_b *= gcd;

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> gcd >> lcm;

	solve(gcd, lcm);

	cout << ret_a << ' ' << ret_b;

	return 0;
}
