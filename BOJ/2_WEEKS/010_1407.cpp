#include<iostream>
using namespace std;
typedef long long ll;

ll a, b;

ll solve(ll n) {
	ll ret = n; //n 이하의 자연수는 기본적으로 2 ^ 0 = 1을 승수로 가진다

	for (ll i = 2; i <= n; i *= 2) {
		ret += (n / i) * (i / 2); //n!에서 2가 몇 번 곱해져 있는가? x 가중치 i / 2
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;

	cout << solve(b) - solve(a - 1);

	return 0;
}

/*
int solve(int n) {
	int ret2 = 0, ret5 = 0; // init

	for (int i = 2; i <= n; i *= 2) {
		ret2 += (n / i); //n!에서 2가 몇 번 곱해져 있는가?
	}

	for (int i = 5; i <= n; i *= 5) {
		ret5 += (n / i); //n!에서 5가 몇 번 곱해져 있는가?
	}

	return min(ret2, ret5); //n!에서 10이 몇 번 곱해져 있는가?
}
*/
