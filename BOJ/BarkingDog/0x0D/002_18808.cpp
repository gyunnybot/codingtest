#include<iostream>
using namespace std;

int n, m, k, r, c, a[41][41], paper[11][11], ret;

void rotate() {
	int temp[11][11];

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			temp[j][r - i - 1] = paper[i][j];
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			paper[i][j] = 0;
		}
	}

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			paper[i][j] = temp[i][j];
		}
	}

	swap(r, c);

	return;
}

void post(int y, int x) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (paper[i][j]) {
				a[y + i][x + j] = paper[i][j];
			}
		}
	}

	return;
}

bool postable(int y, int x) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (a[y + i][x + j] && paper[i][j]) {
				return false;
			}
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;

	while (k--) {
		cin >> r >> c;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> paper[i][j];
			}
		}

		bool flag = false;

		for (int dir = 0; dir < 4; dir++) {
			for (int i = 0; i <= n - r; i++) {
				for (int j = 0; j <= m - c; j++) {
					if (postable(i, j)) {
						post(i, j);

						flag = true;

						break;
					}
				}

				if (flag) break;
			}

			if (flag) break;

			rotate();
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j]) {
				ret++;
			}
		}
	}

	cout << ret;

	return 0;
}
