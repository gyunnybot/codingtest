#include<iostream>
using namespace std;
typedef long long ll;

int a, b, c;

ll recur(int a, int b, int c) {
	if (b == 1) {
		return a % c;
	}

	if (b % 2) { //홀수 승수인 경우 한번 더 a % c 연산
		return (recur(a, b / 2, c) * recur(a, b / 2, c) % c) * a % c;
	}
	else {
		return (recur(a, b / 2, c) * recur(a, b / 2, c) % c);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b >> c;
	
	cout << recur(a, b, c);

	return 0;
}
