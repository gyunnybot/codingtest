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
		int temp[21][21];

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

void recur(int idx, Board c) {
	if (idx == 5) {
		c.get_max();
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		Board d = c;

		d.push_blocks();

		recur(idx + 1, d);

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

	recur(0, c);

	cout << ret;

	return 0;
}
