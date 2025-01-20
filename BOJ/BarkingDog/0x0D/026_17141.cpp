#include<iostream>
#include<vector>
#include<queue>
#include<climits> //INT_MAX
#include<algorithm> //next_permutation
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, a[51][51], dist[51][51];
int ret = INT_MAX;
vector<pair<int, int>> virusList;
queue<pair<int, int>> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];

			if (a[i][j] == 2) {
				virusList.push_back({ i,j }); //바이러스가 될 수 있는 좌표
				a[i][j] = 0;
			}
		}
	}

	vector<int> brute((int)virusList.size());

	for (int i = m; i < virusList.size(); i++) {
		brute[i] = 1;
	}

	do {
		int t = 0;

		for (int i = 0; i < n; i++) {
			fill(dist[i], dist[i] + n, -1);
		}

		for (int i = 0; i < virusList.size(); i++) {
			if (!brute[i]) {
				q.push(virusList[i]);
				dist[virusList[i].first][virusList[i].second] = 0;
			}
		}

		while (!q.empty()) {
			pair<int, int> cur = q.front(); q.pop();

			for (int dir = 0; dir < 4; dir++) {
				int ny = cur.first + dy[dir];
				int nx = cur.second + dx[dir];

				if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
				if (a[ny][nx] != 0 || dist[ny][nx] >= 0) continue;

				dist[ny][nx] = dist[cur.first][cur.second] + 1;
				t = max(t, dist[ny][nx]);
				q.push({ ny,nx });
			}
		}

		bool flag = true;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 0 && dist[i][j] == -1) {
					flag = false;
				}
			}
		}

		if (flag) ret = min(ret, t);

	} while (next_permutation(brute.begin(), brute.end()));

	if (ret == INT_MAX) {
		cout << -1;
	}
	else {
		cout << ret;
	}

	return 0;
}
