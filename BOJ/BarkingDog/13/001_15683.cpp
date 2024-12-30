#include<iostream>
#include<vector>
#include<climits> //INT_MAX
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, a[10][10];
int ret = INT_MAX;
vector<pair<int, int>> cctv_list;

vector<pair<int, int>> spread(int cctv_cnt, int dir) {
	vector<pair<int, int>> ret;

	pair<int, int> cur_cctv = cctv_list[cctv_cnt];

	if (a[cur_cctv.first][cur_cctv.second] == 1) {
		pair<int, int> cur = cur_cctv;

		while (true) {
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];

			if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6) {
				if (a[ny][nx] == 0) {
					a[ny][nx] = 7;
					ret.push_back({ ny,nx });
				}

				cur = { ny,nx };
			}
			else {
				break;
			}
		}
	}
	else if (a[cur_cctv.first][cur_cctv.second] == 2) {
		for (int d = 0; d <= 2; d += 2) {
			pair<int, int> cur = cur_cctv;

			while (true) {
				int ny = cur.first + dy[(dir + d) % 4];
				int nx = cur.second + dx[(dir + d) % 4];

				if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6) {
					if (a[ny][nx] == 0) {
						a[ny][nx] = 7;
						ret.push_back({ ny,nx });
					}

					cur = { ny,nx };
				}
				else {
					break;
				}
			}
		}
	}
	else if (a[cur_cctv.first][cur_cctv.second] == 3) {
		for (int d = 0; d < 2; d++) {
			pair<int, int> cur = cur_cctv;

			while (true) {
				int ny = cur.first + dy[(dir + d) % 4];
				int nx = cur.second + dx[(dir + d) % 4];

				if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6) {
					if (a[ny][nx] == 0) {
						a[ny][nx] = 7;
						ret.push_back({ ny,nx });
					}

					cur = { ny,nx };
				}
				else {
					break;
				}
			}
		}
	}
	else if (a[cur_cctv.first][cur_cctv.second] == 4) {
		for (int d = 0; d < 3; d++) {
			pair<int, int> cur = cur_cctv;

			while (true) {
				int ny = cur.first + dy[(dir + d) % 4];
				int nx = cur.second + dx[(dir + d) % 4];

				if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6) {
					if (a[ny][nx] == 0) {
						a[ny][nx] = 7;
						ret.push_back({ ny,nx });
					}

					cur = { ny,nx };
				}
				else {
					break;
				}
			}
		}
	}
	else if (a[cur_cctv.first][cur_cctv.second] == 5) {
		for (int d = 0; d < 4; d++) {
			pair<int, int> cur = cur_cctv;

			while (true) {
				int ny = cur.first + dy[(dir + d) % 4];
				int nx = cur.second + dx[(dir + d) % 4];

				if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6) {
					if (a[ny][nx] == 0) {
						a[ny][nx] = 7;
						ret.push_back({ ny,nx });
					}

					cur = { ny,nx };
				}
				else {
					break;
				}
			}
		}
	}

	return ret;
}

void recur(int cctv_cnt) {
	if (cctv_cnt == cctv_list.size()) { //사각지대의 최소 크기이므로 최대한 많은 cctv를 켜야 유리하다
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 0) {
					cnt++; //사각지대 계산
				}
			}
		}

		ret = min(ret, cnt);

		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		vector<pair<int, int>> spreaded_area = spread(cctv_cnt, dir);

		recur(cctv_cnt + 1);

		for (pair<int, int> s : spreaded_area) {
			a[s.first][s.second] = 0; //원상 복구
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

			if (a[i][j] != 0 && a[i][j] != 6) {
				cctv_list.push_back({ i,j });
			}
		}
	}

	recur(0); //0번째 cctv부터 dfs

	cout << ret;

	return 0;
}
