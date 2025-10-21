#include<iostream>
#include<vector>
#include<algorithm> //rotate
using namespace std;

string g;
vector<vector<int>> gear(4, vector<int>(8, 0));
int k, num, wise, ret, dir[4];

void rotate_gear(int idx, int wise) {
	if (wise == 1) {
		rotate(gear[idx].rbegin(), gear[idx].rbegin() + 1, gear[idx].rend()); //시계 방향 회전
	}
	else {
		rotate(gear[idx].begin(), gear[idx].begin() + 1, gear[idx].end()); //반시계 방향 회전
	}

	return;
}

void check_rotate(int idx, int wise) {
	fill(&dir[0], &dir[0] + 4, 0);

	dir[idx] = wise;

	for (int i = idx; i < 3; i++) {
		if (gear[i][2] != gear[i + 1][6]) {
			dir[i + 1] = -dir[i];
		}
	}

	for (int i = idx; i > 0; i--) {
		if (gear[i][6] != gear[i - 1][2]) {
			dir[i - 1] = -dir[i];
		}
	}

	for (int i = 0; i < 4; i++) {
		if (dir[i] != 0) {
			rotate_gear(i, dir[i]);
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	
	for (int i = 0; i < 4; i++) {
		cin >> g;

		for (int j = 0; j < 8; j++) {
			gear[i][j] = g[j] - '0';
		}
	}

	cin >> k;

	while (k--) {
		cin >> num >> wise;
		check_rotate(num - 1, wise);
	}

	if (gear[0][0] == 1) ret += 1;
	if (gear[1][0] == 1) ret += 2;
	if (gear[2][0] == 1) ret += 4;
	if (gear[3][0] == 1) ret += 8;

	cout << ret;

	return 0;
}
