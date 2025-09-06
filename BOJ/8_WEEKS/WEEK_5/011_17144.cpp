#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dy1[] = { 0,-1,0,1 };
int dx1[] = { 1,0,-1,0 };
int dy2[] = { 0,1,0,-1 };
int dx2[] = { 1,0,-1,0 };
int temp[54][54], a[54][54], r, c, t, ret;
bool flag;
vector<pair<int, int>> v1, v2;

void circulate(vector<pair<int, int>>& v) {
	for (int i = v.size() - 1; i > 0; i--) {
		a[v[i].first][v[i].second] = a[v[i - 1].first][v[i - 1].second];
	}

	a[v[0].first][v[0].second] = 0;

	return;
}

void spread() {
	fill(&temp[0][0], &temp[0][0] + 54 * 54, 0);

	queue<pair<int, int>> q;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (a[i][j] != -1 && a[i][j]) {
				q.push({ i,j });
			}
		}
	}

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();

		int dust = a[cur.first][cur.second] / 5;

		for (int i = 0; i < 4; i++) {
			int ny = cur.first + dy1[i]; //인접한 네 방향 확산. dy2를 사용해도 무방하다
			int nx = cur.second + dx1[i];

			if (ny < 0 || ny >= r || nx < 0 || nx >= c || a[ny][nx] == -1) continue;

			temp[ny][nx] += dust;
			a[cur.first][cur.second] -= dust;
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			a[i][j] += temp[i][j];
		}
	}

	return;
}

vector<pair<int, int>> circulate_list(int sy, int sx, int dy[], int dx[]) {
	vector<pair<int, int>> c_list;
	pair<int, int> cur = { sy,sx };

	int dir = 0;

	while (true) {
		int ny = cur.first + dy[dir];
		int nx = cur.second + dx[dir];

		if (ny == sy && nx == sx) break;

		if (ny < 0 || ny >= r || nx < 0 || nx >= c) {
			dir++; //방향을 바꿔서 ny, nx 좌표 다시 설정

			ny = cur.first + dy[dir];
			nx = cur.second + dx[dir];
		}

		c_list.push_back({ ny,nx });
		cur = { ny,nx };
	}

	return c_list;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c >> t;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];

			if (a[i][j] == -1) {
				if (!flag) {
					v1 = circulate_list(i, j, dy1, dx1);
					flag = true;
				}
				else {
					v2 = circulate_list(i, j, dy2, dx2);
				}
			}
		}
	}

	while (t--) {
		spread();
		circulate(v1);
		circulate(v2);
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (a[i][j] != -1 && a[i][j]) {
				ret += a[i][j];
			}
		}
	}

	cout << ret;

	return 0;
}
