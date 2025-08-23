#include<iostream>
using namespace std;

const int UP = 0;
const int DOWN = 1;
const int FRONT = 2;
const int BACK = 3;
const int LEFT = 4;
const int RIGHT = 5;
int t, n;
char cube[6][3][3];
char color[] = { 'w', 'y', 'r', 'o', 'g', 'b' };
string s;

void rotate(int side, bool isClockwise) {
	int rot = 1; //시계 방향이면 1번 회전

	if (!isClockwise) { //반시계 방향이면 3번 회전(역으로 1번 회전)
		rot = 3;
	}

	while (rot--) {
		char tmp[3][3];

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				tmp[j][3 - i - 1] = cube[side][i][j]; //해당 side 시계 방향으로 회전
			}
		}

		swap(cube[side], tmp); //swap. call by reference, O(1)
	}

	return;
}

void rotate_side(int side, bool isClockwise) {
	rotate(side, isClockwise); //해당 side 회전

	//연결된 side 회전
	int rot = 1;

	if (!isClockwise) {
		rot = 3;
	}

	char tmp;

	while (rot--) {
		if (side == FRONT) {
			for (int i = 0; i < 3; i++) {
				tmp = cube[UP][2][i];
				cube[UP][2][i] = cube[LEFT][2 - i][2];
				cube[LEFT][2 - i][2] = cube[DOWN][0][2 - i];
				cube[DOWN][0][2 - i] = cube[RIGHT][i][0];
				cube[RIGHT][i][0] = tmp;
			}
		}
		else if (side == BACK) {
			for (int i = 0; i < 3; i++) {
				tmp = cube[UP][0][i];
				cube[UP][0][i] = cube[RIGHT][i][2];
				cube[RIGHT][i][2] = cube[DOWN][2][2 - i];
				cube[DOWN][2][2 - i] = cube[LEFT][2 - i][0];
				cube[LEFT][2 - i][0] = tmp;
			}
		}
		else if (side == LEFT) {
			for (int i = 0; i < 3; i++) {
				tmp = cube[UP][i][0];
				cube[UP][i][0] = cube[BACK][i][0];
				cube[BACK][i][0] = cube[DOWN][i][0];
				cube[DOWN][i][0] = cube[FRONT][i][0];
				cube[FRONT][i][0] = tmp;
			}
		}
		else if (side == RIGHT) {
			for (int i = 0; i < 3; i++) {
				tmp = cube[UP][i][2];
				cube[UP][i][2] = cube[FRONT][i][2];
				cube[FRONT][i][2] = cube[DOWN][i][2];
				cube[DOWN][i][2] = cube[BACK][i][2];
				cube[BACK][i][2] = tmp;
			}
		}
		else if (side == UP) {
			for (int i = 0; i < 3; ++i) {
				tmp = cube[FRONT][0][i];
				cube[FRONT][0][i] = cube[RIGHT][0][i];
				cube[RIGHT][0][i] = cube[BACK][2][2 - i];
				cube[BACK][2][2 - i] = cube[LEFT][0][i];
				cube[LEFT][0][i] = tmp;
			}
		}
		else { //DOWN
			for (int i = 0; i < 3; ++i) {
				tmp = cube[FRONT][2][i];
				cube[FRONT][2][i] = cube[LEFT][2][i];
				cube[LEFT][2][i] = cube[BACK][0][2 - i];
				cube[BACK][0][2 - i] = cube[RIGHT][2][i];
				cube[RIGHT][2][i] = tmp;
			}
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	while (t--) {
		for (int s = 0; s < 6; s++) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					cube[s][i][j] = color[s];
				}
			}
		}
		
		cin >> n;

		while (n--) {
			cin >> s;

			if (s[0] == 'F') rotate_side(FRONT, s[1] == '+');
			else if (s[0]=='B') rotate_side(BACK, s[1] == '+');
			else if (s[0] == 'U') rotate_side(UP, s[1] == '+');
			else if (s[0] == 'D') rotate_side(DOWN, s[1] == '+');
			else if (s[0] == 'L') rotate_side(LEFT, s[1] == '+');
			else rotate_side(RIGHT, s[1] == '+');
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << cube[UP][i][j]; //윗 면 출력
			}

			cout << '\n';
		}
	}

	return 0;
}
