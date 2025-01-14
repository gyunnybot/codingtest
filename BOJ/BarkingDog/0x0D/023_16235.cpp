#include<iostream>
#include<algorithm> //sort
#include<vector>
using namespace std;

const int dy[] = { -1,-1,-1,0,0,1,1,1 };
const int dx[] = { -1,0,1,-1,1,-1,0,1 };
int n, m, k, y, x, z, ret, soil[11][11], a[11][11];
vector<int> tree[11][11];

void springSummer() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tree[i][j].size() == 0) continue;

			vector<int> v;
			int dead_tree = 0;

			//spring
			sort(tree[i][j].begin(), tree[i][j].end()); //나이가 어린 나무부터 양분을 먹는다

			for (int t : tree[i][j]) {
				if (soil[i][j] >= t) {
					soil[i][j] -= t;
					v.push_back(t + 1);
				}
				else {
					dead_tree += t / 2;
				}
			}

			tree[i][j] = v; //나이가 1 증가한 벡터 v로 tree[i][j]를 갱신

			//summer
			soil[i][j] += dead_tree;
		}
	}

	return;
}

void fall() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tree[i][j].size() == 0) continue;

			for (int t : tree[i][j]) {
				if (t % 5 == 0) {
					for (int dir = 0; dir < 8; dir++) {
						int ny = i + dy[dir];
						int nx = j + dx[dir];

						if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

						tree[ny][nx].push_back(1); //나이가 1인 나무가 생긴다
					}
				}
			}
		}
	}

 return;
}

void winter() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			soil[i][j] += a[i][j];
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(&soil[0][0], &soil[0][0] + 11 * 11, 5); //가장 처음에 양분은 모든 칸에 5만큼 들어있다

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> y >> x >> z;
		tree[y - 1][x - 1].push_back(z);
	}

	while (k--) {
		springSummer();
		fall();
		winter();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ret += tree[i][j].size();
		}
	}

	cout << ret;

	return 0;
}
