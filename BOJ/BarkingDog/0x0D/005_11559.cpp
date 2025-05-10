#include<iostream>
#include<vector>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
bool visited[13][7];
char a[13][7];
int ret;
vector<pair<int, int>> same_blocks_pos;
string s;

void slide_down() {
	for (int i = 11; i >= 0; i--) {
		for (int j = 0; j < 6; j++) {
			if (a[i][j] == '.') continue;

			int temp = i;

			while (true) {
				if (temp == 11 || a[temp + 1][j] != '.') {
					break;
				}
				else {
					a[temp + 1][j] = a[temp][j];
					a[temp][j] = '.';
					temp++;
				}
			}
		}
	}

	return;
}

void chain_reaction(vector<pair<int, int>>& same_block_pos) {
	for (pair<int, int> block : same_block_pos) {
		a[block.first][block.second] = '.';
	}

	return;
}

void dfs(int y, int x) {
	visited[y][x] = true;
	same_blocks_pos.push_back({ y,x });

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= 12 || nx < 0 || nx >= 6) continue;

		if (!visited[ny][nx] && a[ny][nx] == a[y][x]) {
			dfs(ny, nx);
		}
	}

	return;
}

void puyo() {
	while (true) {
		fill(&visited[0][0], &visited[0][0] + 13 * 7, false);

		bool flag = false;

		for (int i = 11; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (a[i][j] != '.') {
					same_blocks_pos.clear();

					dfs(i, j);

					if (same_blocks_pos.size() >= 4) {
						chain_reaction(same_blocks_pos);

						flag = true;
					}
				}
			}
		}

		if (!flag) break;

		slide_down();

		ret++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 12; i++) {
		cin >> s;

		for (int j = 0; j < 6; j++) {
			a[i][j] = s[j];
		}
	}

	puyo();

	cout << ret;

	return 0;
}
