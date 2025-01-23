#include<iostream>
using namespace std;

int n, m, k, r, c, ret, board[42][42], paper[12][12];

void rotate() {
	int temp[12][12];

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			temp[j][r - i - 1] = paper[i][j]; //시계 방향
			//temp[c - j - 1][i] = paper[i][j]; //반시계 방향
		}
	}

	fill(&paper[0][0], &paper[0][0] + 12 * 12, 0);

	swap(r, c); //call by reference

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			paper[i][j] = temp[i][j];
		}
	}

	/* 아래 방법은 R x C 부분뿐만 아니라 전체를 덮어씌우기 때문에 잘못된 결과 반환
	fill(&paper[0][0], &paper[0][0] + 12 * 12, 0);
	swap(paper, temp);
	*/

	return;
}

//R x C 사이즈의 스티커가 좌상단 (y,x) 기준으로 온전히 붙여지는가?
bool postable(int y, int x) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[y + i][x + j] == 1 && paper[i][j] == 1) {
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

		//색종이 입력
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> paper[i][j];
			}
		}

		for (int dir = 0; dir < 4; dir++) {
			bool flag = false;

			for (int y = 0; y <= n - r; y++) {
				for (int x = 0; x <= m - c; x++) {
					if (postable(y, x)) {
						for (int i = 0; i < r; i++) { //검사 통과! R x C 사이즈의 스티커 붙이기
							for (int j = 0; j < c; j++) {
								if (paper[i][j] == 1) {
									board[y + i][x + j] = 1;
								}
							}
						}

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
			ret += board[i][j];
		}
	}

	cout << ret;

	return 0;
}
