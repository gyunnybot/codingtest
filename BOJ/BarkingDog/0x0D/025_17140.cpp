#include<iostream>
using namespace std;

int r, c, k, a[101][101], pre_row, pre_col, cur_row, cur_col, ret;

void update_row(int y) {
	int bucket[101] = { 0, };

	for (int x = 1; x <= pre_col; x++) {
		bucket[a[y][x]]++;
	}

	int idx = 1;

	for (int cnt = 1; cnt <= 100; cnt++) { //횟수
		for (int val = 1; val <= 100; val++) { //값
			if (bucket[val] == cnt) { //횟수가 적게 나온 값을 우선으로 오름차순 출력
				a[y][idx++] = val; //값
				a[y][idx++] = cnt; //횟수

				if (idx > 100) break;
			}
		}

		if (idx > 100) break;
	}

	for (int x = idx; x <= pre_col; x++) {
		a[y][x] = 0;
	}

	if (cur_col < idx) {
		cur_col = idx;
	}

	return;
}

void update_col(int x) {
	int bucket[101] = { 0, };

	for (int y = 1; y <= pre_row; y++) {
		bucket[a[y][x]]++;
	}

	int idx = 1;

	for (int cnt = 1; cnt <= 100; cnt++) { //횟수
		for (int val = 1; val <= 100; val++) { //값
			if (bucket[val] == cnt) { //횟수가 적게 나온 값을 우선으로 오름차순 출력
				a[idx++][x] = val; //값
				a[idx++][x] = cnt; //횟수

				if (idx > 100) break;
			}
		}

		if (idx > 100) break;
	}

	for (int y = idx; y <= pre_row; y++) {
		a[y][x] = 0;
	}

	if (cur_row < idx) {
		cur_row = idx;
	}

	return;
}

void oper() {
	while (a[r][c] != k) {
		if (cur_row >= cur_col) {
			pre_col = cur_col;
			cur_col = 0;

			for (int y = 1; y <= cur_row; y++) {
				update_row(y);
			}
		}
		else {
			pre_row = cur_row;
			cur_row = 0;

			for (int x = 1; x <= cur_col; x++) {
				update_col(x);
			}
		}

		ret++;

		if (ret > 100) break;
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c >> k;

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> a[i][j];
		}
	}

	cur_row = 3;
	cur_col = 3;

	oper();

	if (ret > 100) {
		cout << -1;
	}
	else {
		cout << ret;
	}

	return 0;
}
