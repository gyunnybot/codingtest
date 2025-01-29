#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, board[10][10], ret;
bool visited[10][10];
vector<pair<int, int>> virusList, wallList;

void bfs(int y, int x) {
	visited[y][x] = true;

	queue<pair<int, int>> q;
	q.push({ y,x });

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

			if (board[ny][nx] == 0 && !visited[ny][nx]) {
				visited[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
	}

	return;
}

int check_area() {
	for (pair<int, int> virus : virusList) {
		bfs(virus.first, virus.second);
	}

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0 && !visited[i][j]) {
				cnt++; //빈 칸이면서 바이러스가 퍼지지 않았다면
			}
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];

			if (board[i][j] == 0) {
				wallList.push_back({ i,j }); //빈 칸 = 벽이 될 가능성이 있는 좌표
			}
			else if (board[i][j] == 2) {
				virusList.push_back({ i,j }); //바이러스가 있는 좌표
			}
		}
	}

	for (int i = 0; i < wallList.size(); i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < j; k++) {
				fill(&visited[0][0], &visited[0][0] + 10 * 10, false); //방문처리 초기화

				//방문처리로 벽 세우기
				visited[wallList[i].first][wallList[i].second] = true;
				visited[wallList[j].first][wallList[j].second] = true;
				visited[wallList[k].first][wallList[k].second] = true;

				ret = max(ret, check_area());
			}
		}
	}

	cout << ret;

	return 0;
}
