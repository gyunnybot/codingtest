#include<iostream>
using namespace std;

int n, ret;

struct Board {
	int board[21][21];

	void rotate() {
		int temp[21][21];

		for (int i = 0; i < n; i++) { //행 r
			for (int j = 0; j < n; j++) { //열 c
				temp[j][n - i - 1] = board[i][j]; //시계 방향: temp[j][r - i - 1] = board[i][j];
				//temp[n - j - 1][i] = board[i][j]; //반시계 방향: temp[c - j - 1][i] = board[i][j];
			}
		}

		fill(&board[0][0], &board[0][0] + 21 * 21, 0);

		//swap(n, n); //swap(r, c); call by reference. deep copy
		for (int i = 0; i < n; i++) { //열 c
			for (int j = 0; j < n; j++) { //행 r
				board[i][j] = temp[i][j];
			}
		}

		return;
	}

	void get_max() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ret = max(ret, board[i][j]);
			}
		}

		return;
	}

	void push_blocks() {
		int temp[21][21];

		for (int i = 0; i < n; i++) { //각각의 행마다 밀기
			bool flag = false;
			int c = 0; //붙여넣을 좌표 행마다 초기화

			for (int j = 0; j < n; j++) {
				if (board[i][j] == 0) continue;

				if (flag && (board[i][j] == temp[i][c - 1])) {
					temp[i][c - 1] += board[i][j]; //밀어서 값 합치기
					flag = false; //한 번 합쳤다면 false
				}
				else {
					temp[i][c] = board[i][j]; //clone
					flag = true; //합칠 수 있는 flag 다시 true
					c++; //붙여넣을 좌표 증가
				}
			}

			while (c < n) { //더 이상 비교할 j가 없다면 단독으로 temp 완성
				temp[i][c] = 0;
				c++;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				board[i][j] = temp[i][j];
			}
		}

		return;
	}
};
Board c;

void recur(Board c, int here) {
	if (here == 5) {
		c.get_max();
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		Board d = c;

		d.push_blocks();

		recur(d, here + 1);

		c.rotate();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) { //행 r
		for (int j = 0; j < n; j++) { //열 c
			cin >> c.board[i][j];
		}
	}

	recur(c, 0);

	cout << ret;

	return 0;
}
