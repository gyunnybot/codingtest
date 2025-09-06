#include<iostream>
using namespace std;

int n, ret;

struct Board {
	int a[21][21];

	void get_max() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ret = max(ret, a[i][j]);
			}
		}

		return;
	}

	void push_blocks() {
		int temp[21][21]; //지역 변수 -> 값이 할당되었는지 확인 후 연산 진행하기!

		for (int i = 0; i < n; i++) {
			bool flag = false;
			int c = 0;

			for (int j = 0; j < n; j++) {
				if (a[i][j] == 0) continue;

				if (flag && a[i][j] == temp[i][c - 1]) {
					temp[i][c - 1] += a[i][j];
					flag = false;
				}
				else {
					temp[i][c++] = a[i][j];
					flag = true;
				}
			}

			while (c < n) {
				temp[i][c++] = 0;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = temp[i][j];
			}
		}

		return;
	}

	void rotate() {
		int temp[21][21];

		for (int i = 0; i < n; i++) { //r
			for (int j = 0; j < n; j++) { //c
				temp[j][n - i - 1] = a[i][j];
			}
		}

		for (int i = 0; i < n; i++) { //r
			for (int j = 0; j < n; j++) { //c
				a[i][j] = 0;
			}
		}

		for (int i = 0; i < n; i++) { //c
			for (int j = 0; j < n; j++) { //r
				a[i][j] = temp[i][j];
			}
		}

		//swap(n, n) //swap(r, c)

		return;
	}
};
Board c;

void move(int idx, Board c) {
	if (idx == 5) {
		c.get_max();
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		Board d = c; //deep copy. O(N)

		d.push_blocks();

		move(idx + 1, d);

		c.rotate();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c.a[i][j];
		}
	}

	move(0, c);

	cout << ret;

	return 0;
}
