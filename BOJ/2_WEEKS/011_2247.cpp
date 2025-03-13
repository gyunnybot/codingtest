#include<iostream>
using namespace std;

int n, ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 2; i <= n; i++) { //1 제외
		int cnt = n / i; //n!에서 i로 나눠지는 수는 몇 개인가?

		ret += (cnt - 1) * i; //i 본인을 제외한 개수 x 가중치 i
		ret %= 1000000; //mod 연산
	}

	cout << ret;

	return 0;
}
