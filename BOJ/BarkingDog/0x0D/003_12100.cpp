#include<iostream>
using namespace std;

int n, ret;

struct Board {
	int a[21][21];

	void rotate() {
		int temp[21][21];

		for (int i = 0; i < n; i++) { //행 r
			for (int j = 0; j < n; j++) { //열 c
				temp[j][n - i - 1] = a[i][j]; //시계 방향
				//temp[n - j - 1][i] = board[i][j]; //반시계 방향
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = 0;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = temp[i][j];
			}
		}

		//swap(n, n); //행, 열 바꾸기

		return;
	}

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

		for (int i = 0; i < n; i++) { //각 행마다 밀기 작업 수행
			bool flag = false;
			int c = 0; //temp에서 움직일 열 번호

			for (int j = 0; j < n; j++) {
				if (a[i][j] == 0) continue;

				if (flag && (a[i][j] == temp[i][c - 1])) {
					temp[i][c - 1] += a[i][j]; //밀어서 값 합치기
					flag = false; //한 번 합쳐진 수에 대해서는 중첩되어 합칠 수 없다
				}
				else {
					temp[i][c] = a[i][j]; //값 복사
					c++; //붙여넣을 좌표 증가

					flag = true; //합칠 수 없는 상태에서 c가 이동했으므로, 합칠 수 있는 flag = true로 변경
				}
			}

			while (c < n) { //c 입장에서 더 이상 비교할 j가 없다면 단독으로 temp 완성
				temp[i][c] = 0;
				c++;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = temp[i][j];
			}
		}

		return;
	}
};
Board c;

void go(Board& c, int cnt) {
	if (cnt == 5) {
		c.get_max();
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		Board d = c;

		d.push_blocks();

		go(d, cnt + 1);

		c.rotate();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) { //행 r
		for (int j = 0; j < n; j++) { //열 c
			cin >> c.a[i][j];
		}
	}

	go(c, 0);

	cout << ret;

	return 0;
}
