#include<iostream>
using namespace std;

struct Shark {
	int r, c, s, d, z;
	bool isDead;
};
Shark shark[10001]; //상어 목록 저장

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,1,-1 };
int r, c, m, a[101][101], temp[101][101], ret;

void get_fish() {
	for (int xpos = 0; xpos < c; xpos++) { //1. 낚시왕이 오른쪽으로 한 칸 이동한다
		for (int ypos = 0; ypos < r; ypos++) {
			if (a[ypos][xpos]) { //2. 제일 가까운 상어를 잡는다
				shark[a[ypos][xpos]].isDead = true;
				ret += shark[a[ypos][xpos]].z; //낚시왕이 잡은 상어 크기의 합 갱신
				a[ypos][xpos] = 0; //격자판에서 잡은 상어가 사라진다

				break; //해당 열에서는 더이상 작업을 하지 않는다
			}
		}

		//3. 상어가 이동한다
		fill(&temp[0][0], &temp[0][0] + 101 * 101, 0);

		for (int i = 1; i <= m; i++) {
			if (shark[i].isDead) continue;

			int y = shark[i].r;
			int x = shark[i].c;
			int s = shark[i].s;
			int d = shark[i].d;
			int z = shark[i].z;

			int ny, nx;

			while (true) { //최종적인 ny, nx 정하기
				ny = y + s * dy[d];
				nx = x + s * dx[d];

				if (ny >= 0 && ny < r && nx >= 0 && nx < c) break;

				if (d <= 1) {
					if (ny < 0) {
						s -= y;
						y = 0;
					}
					else {
						s -= (r - 1) - y;
						y = r - 1;
					}
				}
				else {
					if (nx < 0) {
						s -= x;
						x = 0;
					}
					else {
						s -= (c - 1) - x;
						x = c - 1;
					}
				}

				d ^= 1;
			}

			if (temp[ny][nx]) { //좌표에 이미 상어가 있다면 크기 비교 후 갱신
				if (shark[temp[ny][nx]].z < shark[i].z) {
					shark[temp[ny][nx]].isDead = true;
					temp[ny][nx] = i;
				}
				else {
					shark[i].isDead = true;
				}
			}
			else {
				temp[ny][nx] = i;
			}

			//i번째 상어의 정보 갱신
			shark[i].r = ny;
			shark[i].c = nx;
			shark[i].d = d;
			//a[i].s = s; 같은 속도 성분을 유지한다
			//shark[i].z = z; 크기 또한 변하지 않는다
		}

		swap(a, temp);
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c >> m;

	for (int i = 1; i <= m; i++) {
		cin >> shark[i].r >> shark[i].c >> shark[i].s >> shark[i].d >> shark[i].z;

		shark[i].r--, shark[i].c--, shark[i].d--;

		//격자 범위 내 표현 가능한 속도로 보정
		if (shark[i].d <= 1) shark[i].s %= (2 * (r - 1)); //위, 아래
		else shark[i].s %= (2 * (c - 1)); //좌, 우

		a[shark[i].r][shark[i].c] = i; //상어가 위치한 좌표에 상어의 인덱스 저장(1번부터)
	}

	get_fish();

	cout << ret;

	return 0;
}
