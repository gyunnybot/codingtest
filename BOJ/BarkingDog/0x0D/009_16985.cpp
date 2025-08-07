#include<iostream>
#include<queue>
#include<climits> //INT_MAX
#include<algorithm> //next_permutation
using namespace std;

struct Info {
	int x, y, z;
};

const int dx[6] = { 1,0,0,0,0,-1 };
const int dy[6] = { 0,1,-1,0,0,0 };
const int dz[6] = { 0,0,0,1,-1,0 };
int a[5][5][5][5], maze[5][5][5], dist[5][5][5];

int do_maze() {
	fill(&dist[0][0][0], &dist[0][0][0] + 5 * 5 * 5, 0);

	if (maze[0][0][0] == 0 || maze[4][4][4] == 0) return INT_MAX;

	queue<Info> q;
	q.push({ 0,0,0 });

	dist[0][0][0] = 1;

	while (!q.empty()) {
		Info cur = q.front(); q.pop();

		for (int dir = 0; dir < 6; dir++) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			int nz = cur.z + dz[dir];

			if (nx == 4 && ny == 4 && nz == 4) {
				return dist[cur.x][cur.y][cur.z];
			}

			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5) continue;
			if (maze[nx][ny][nz] == 0) continue;

			if (!dist[nx][ny][nz]) {
				dist[nx][ny][nz] = dist[cur.x][cur.y][cur.z] + 1;
				q.push({ nx,ny,nz });
			}
		}
	}

	return INT_MAX;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 5; i++) { //층
		for (int j = 0; j < 5; j++) { //행
			for (int k = 0; k < 5; k++) { //열
				cin >> a[0][i][j][k];
			}
		}

		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				a[1][i][j][k] = a[0][i][5 - k - 1][j];
			}
		}

		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				a[2][i][j][k] = a[1][i][5 - k - 1][j];
			}
		}

		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				a[3][i][j][k] = a[2][i][5 - k - 1][j];
			}
		}
	}

	int order[5] = { 0,1,2,3,4 }; //층별 인덱스
	int ret = INT_MAX;

	do {
		for (int temp = 0; temp < 1024; temp++) { //4 ^ 5 = 1024
			int brute = temp;

			for (int i = 0; i < 5; i++) {
				int dir = brute % 4;

				for (int j = 0; j < 5; j++) {
					for (int k = 0; k < 5; k++) {
						maze[i][j][k] = a[dir][order[i]][j][k]; //회전 방향, 층, 행, 열
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
