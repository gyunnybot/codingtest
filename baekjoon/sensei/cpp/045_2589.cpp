#include<iostream>
#include<queue>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };

int n, m, visited[51][51], ret;
char a[51][51];
string s;

void bfs(int y, int x) {
	fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);

	visited[y][x] = 1;

	queue<pair<int, int>> q;
	q.push({ y,x });

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

			if (a[ny][nx] == 'L' && !visited[ny][nx]) {
				visited[ny][nx] = visited[cur.first][cur.second] + 1;
				q.push({ ny,nx });

				ret = max(ret, visited[ny][nx]);
			}
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s;

		for (int j = 0; j < m; j++) {
			a[i][j] = s[j];
		}
	}

    //O(N x M x N x M)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'L') {
				bfs(i, j);
			}
		}
	}

	cout << ret - 1;

	return 0;
}
