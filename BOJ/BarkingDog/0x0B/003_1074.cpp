#include<iostream>
using namespace std;

int n, r, c, ret;

int recur(int n, int r, int c) {
	if (n == 0) {
		return 0; //문제에서는 첫 방문을 '0 번째 방문'으로 정의함
	}

	int half = (1 << n) / 2;

	if (r < half && c < half) {
		return recur(n - 1, r, c);
	}
	else if (r < half && c >= half) {
		return half * half + recur(n - 1, r, c - half);
	}
	else if (r >= half && c < half) {
		return 2 * half * half + recur(n - 1, r - half, c);
	}
	else {
		return 3 * half * half + recur(n - 1, r - half, c - half);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> r >> c;

	cout << recur(n, r, c);

	return 0;
}
