#include<iostream>
#include<queue>
#include<climits> //INT_MAX
using namespace std;

struct Shark {
	int y, x, time;
};
Shark shark;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, a[21][21], shark_size, shark_eat;
bool visited[21][21];

void baby_shark() {
	bool flag = true;

	while (true) {
		if (!flag) break; //더 이상 먹을 수 있는 물고기가 없다면 break

		fill(&visited[0][0], &visited[0][0] + 21 * 21, 0);
		flag = false;

		a[shark.y][shark.x] = 0;

		visited[shark.y][shark.x] = true;

		queue<Shark> q;
		q.push(shark);

		//candidate
		Shark candi;
		candi.time = -1; candi.y = INT_MAX;

		while (!q.empty()) {
			Shark cur = q.front(); q.pop();

			//한 번 갱신된 candi의 시간보다 cur의 시간이 길다면 더 이상 후보자를 탐색하지 않는다
			if (candi.time != -1 && candi.time < cur.time) break;

			//먹을 수 있는 물고기가 있다면
			if (a[cur.y][cur.x] != 0 && a[cur.y][cur.x] < shark_size) {
				flag = true;

				//먹을 수 있는 물고기들 중 가장 적합한 물고기를 candi에 저장
				if (cur.y < candi.y || (cur.y == candi.y && cur.x < candi.x)) {
					candi = cur;
				}
			}

			for (int i = 0; i < 4; i++) {
				Shark next;

				next.y = cur.y + dy[i];
				next.x = cur.x + dx[i];
				next.time = cur.time + 1;

				if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n) continue;

				if (!visited[next.y][next.x] && a[next.y][next.x] <= shark_size) {
					visited[next.y][next.x] = true;
					q.push(next);
				}
			}
		}

		if (flag) {
			shark = candi; //deep copy(기본형, STL, struct, vector의 '=' 연산)
			shark_eat++;

			if (shark_eat == shark_size) {
				shark_size++;
				shark_eat = 0;
			}
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];

			if (a[i][j] == 9) {
				shark = { i,j,0 };

				shark_size = 2;
				shark_eat = 0;
			}
		}
	}

	baby_shark();

	cout << shark.time;

	return 0;
}
