#include<iostream>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, k, ret;
char a[6][6];
bool visited[6][6];
string s;

void dfs(int y, int x, int cnt) {
	visited[y][x] = true;

	if (y == 0 && x == m - 1 && cnt == k) {
		ret++;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

		if (a[ny][nx] != 'T' && !visited[ny][nx]) {
			dfs(ny, nx, cnt + 1);

			visited[ny][nx] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		cin >> s;

		for (int j = 0; j < m; j++) {
			a[i][j] = s[j];
		}
	}

	dfs(n - 1, 0, 1);

	cout << ret;

	return 0;
}
