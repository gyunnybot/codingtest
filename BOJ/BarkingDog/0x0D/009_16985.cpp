#include<iostream>
#include<climits> //INT_MAX
#include<algorithm> //next_permutataion
#include<queue>
using namespace std;

struct Info {
	int h, y, x;
};

const int dh[6] = { 1,-1,0,0,0,0 };
const int dy[6] = { 0,0,-1,0,1,0 };
const int dx[6] = { 0,0,0,1,0,-1 };
int a[4][5][5][5], maze[5][5][5], dist[5][5][5];

int do_maze() {
	fill(&dist[0][0][0], &dist[0][0][0] + 5 * 5 * 5, 0);

	if (maze[0][0][0] == 0 || maze[4][4][4] == 0) return INT_MAX;

	queue<Info> q;
	q.push({ 0,0,0 });

	dist[0][0][0] = 1;

	while (!q.empty()) {
		Info cur = q.front(); q.pop();

		if (cur.h == 4 && cur.y == 4 && cur.x == 4) {
			return dist[cur.h][cur.y][cur.x] - 1;
		}

		for (int i = 0; i < 6; i++) {
			int nh = cur.h + dh[i];
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			if (nh < 0 || nh >= 5 || nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
			if (maze[nh][ny][nx] == 0) continue;

			if (!dist[nh][ny][nx]) {
				dist[nh][ny][nx] = dist[cur.h][cur.y][cur.x] + 1;
				q.push({ nh,ny,nx });
			}
		}
	}

	return INT_MAX;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int h = 0; h < 5; h++) { //층
		for (int i = 0; i < 5; i++) { //행
			for (int j = 0; j < 5; j++) { //열
				cin >> a[0][h][i][j];
			}
		}

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				a[1][h][i][j] = a[0][h][5 - j - 1][i];
			}
		}

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				a[2][h][i][j] = a[1][h][5 - j - 1][i];
			}
		}

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				a[3][h][i][j] = a[2][h][5 - j - 1][i];
			}
		}
	}

	int order[5] = { 0,1,2,3,4 }; //층별 인덱스
	int ret = INT_MAX;

	do {
		for (int temp = 0; temp < 1024; temp++) { //4 ^ 5 = 1024
			int brute = temp;

			for (int h = 0; h < 5; h++) {
				int dir = brute % 4;

				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 5; j++) {
						maze[h][i][j] = a[dir][order[h]][i][j]; //회전 방향, 층, 행, 열
					}
				}

				brute /= 4;
			}

			ret = min(ret, do_maze());
		}
	} while (next_permutation(order, order + 5)); //판을 쌓는 순서도 자유롭게 정할 수 있다

	if (ret == INT_MAX) {
		cout << -1;
	}
	else {
		cout << ret;
	}

	return 0;
}
