#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, a[101][101], ret, visited[101][101];
vector<pair<int, int>> cheese_list_pos;

void bfs(int y, int x) {
	visited[y][x] = 1;

	queue<pair<int, int>> q;
	q.push({ y,x });

	while (!q.empty()) { //q에는 공기 좌표만 들어간다
		pair<int, int> cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

			if (a[ny][nx] == 1) { //인접한 좌표가 치즈라면
				visited[ny][nx]++; //치즈가 공기랑 맞닿은 변 증가

				if (visited[ny][nx] >= 2) { //공기가 두 개의 변 이상으로 맞닿아있다면
					cheese_list_pos.push_back({ ny,nx }); //녹아야 할 치즈 목록에 추가
				}
			}

			if (!visited[ny][nx]) { //치즈는 바로 위 조건문에 의해 방문처리되므로, 해당 ny, nx는 반드시 공기이다
				visited[ny][nx] = 1;
				q.push({ ny,nx }); //q에는 공기 좌표만 들어간다
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

		int cnt = cheese_list_pos.size(); //두 변 이상이 공기와 맞닿아 녹을 치즈가 놓여 있는 칸의 개수

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
			cout << ret; //횟수
			break;
		}
	}

	return 0;
}
