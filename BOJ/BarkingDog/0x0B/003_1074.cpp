#include<iostream>
using namespace std;
typedef long long ll;

int n;
ll r, c, ret;

ll recur(int n, int r, int c) {
	if (n == 0) {
		return 0;
	}

	ll half = (1 << n) / 2;

	if (r < half && c < half) {
		return recur(n - 1, r, c); //1사분면
	}
	else if (r < half && c >= half) {
		return half * half + recur(n - 1, r, c - half); //2사분면
	}
	else if (r >= half && c < half) {
		return 2 * half * half + recur(n - 1, r - half, c); //3사분면
	}
	else {
		return 3 * half * half + recur(n - 1, r - half, c - half); //4사분면
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> r >> c;

	cout << recur(n, r, c);

	return 0;
}