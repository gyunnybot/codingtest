#include<iostream>
#include<queue>
#include<vector>
#include<algorithm> //sort
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, k, sy, sx, ey, ex;
bool a[101][101], visited[101][101];
vector<int> v;

int bfs(int y, int x) {
	visited[y][x] = true;

	int ret = 1;

	queue<pair<int, int>> q;
	q.push({ y,x });

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];

			if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;

			if (a[ny][nx] == 0 && !visited[ny][nx]) {
				visited[ny][nx] = true;
				q.push({ ny,nx });

				ret++;
			}
		}
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n >> k;

	while (k--) {
		cin >> sx >> sy >> ex >> ey;

		for (int i = sy; i < ey; i++) {
			for (int j = sx; j < ex; j++) {
				a[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0 && !visited[i][j]) {
				v.push_back(bfs(i, j));
			}
		}
	}

	sort(v.begin(), v.end());

	cout << v.size() << '\n';

	for (int i : v) {
		cout << i << ' ';
	}

	return 0;
}
