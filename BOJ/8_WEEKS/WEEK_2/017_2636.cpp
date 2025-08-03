#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, a[101][101], ret;
bool visited[101][101];
vector<pair<int, int>> cheese_list_pos;

void bfs(int y, int x) {
	visited[y][x] = true;

	queue<pair<int, int>> q;
	q.push({ y,x });

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();

		if (a[cur.first][cur.second] == 1) { //치즈
			cheese_list_pos.push_back(cur);
		}
		else { //공기
			for (int i = 0; i < 4; i++) {
				int ny = cur.first + dy[i];
				int nx = cur.second + dx[i];

				if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

				if (!visited[ny][nx]) {
					visited[ny][nx] = true;
					q.push({ ny,nx });
				}
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
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	while (true) {
		fill(&visited[0][0], &visited[0][0] + 101 * 101, false);

		cheese_list_pos.clear();

		bfs(0, 0); //판의 가장자리에는 치즈가 놓여 있지 않다

		int cnt = cheese_list_pos.size(); //치즈가 놓여 있는 칸의 개수

		for (pair<int, int> c : cheese_list_pos) {
			a[c.first][c.second] = 0; //치즈 녹이기
		}

		ret++; //녹인 횟수 증가

		bool flag = false;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 1) { //남은 치즈가 존재한다면
					flag = true;
					break;
				}
			}

			if (flag) break;
		}

		if (!flag) { //남은 치즈가 없다면
			cout << ret << '\n' << cnt; //횟수, 마지막으로 남아있었던 치즈 개수
			break;
		}
	}

	return 0;
}
