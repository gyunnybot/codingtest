#include<iostream>
#include<queue>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
bool board[501][501], visited[501][501];
int n, m, maxVal, ret;

int bfs(int y, int x) {
	visited[y][x] = true;

	queue<pair<int, int>> q;
	q.push({ y,x });

	int area = 1; //그림의 넓이

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

			if (board[ny][nx] == 1 && !visited[ny][nx]) {
				visited[ny][nx] = true;
				q.push({ ny, nx });

				area++;
			}
		}
	}

	return area;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1 && !visited[i][j]) {
				maxVal = max(maxVal, bfs(i, j));
				ret++;
			}
		}
	}

	cout << ret << '\n' << maxVal;

	return 0;
}
