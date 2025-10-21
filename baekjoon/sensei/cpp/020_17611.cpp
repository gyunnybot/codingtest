#include<iostream>
#include<vector>
using namespace std;

int n, xpos, ypos, ret;
int a_x[1000001], a_y[1000001], s_x[1000001], s_y[1000001];
vector<pair<int, int>> pos;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> xpos >> ypos;

		xpos += 500000;
		ypos += 500000;

		pos.push_back({ xpos,ypos });
	}

	for (int i = 0; i < n; i++) {
		int x = pos[i].first;
		int y = pos[i].second;

		//마지막 좌표에 대한 nx, ny는 첫 번째 좌표로 돌아온다
		int nx = pos[(i + 1) % n].first;
		int ny = pos[(i + 1) % n].second;

		if (x == nx) {
			int max_y = max(y, ny);
			int min_y = min(y, ny);

			a_y[min_y]++;
			a_y[max_y]--;
		}
		else { //단순 직각사각형이므로 else = if (x != nx) = if (y == ny)
			int max_x = max(x, nx);
			int min_x = min(x, nx);

			a_x[min_x]++;
			a_x[max_x]--;
		}
	}

	for (int i = 1; i <= 1000001; i++) {
		s_x[i] = s_x[i - 1] + a_x[i - 1];
		s_y[i] = s_y[i - 1] + a_y[i - 1];
	}

	for (int i = 1; i <= 1000001; i++) {
		ret = max(ret, max(s_x[i], s_y[i]));
	}

	cout << ret;

	return 0;
}
