#include<iostream>
#include<queue>
#include<climits> //INT_MAX
using namespace std;

struct info {
	int ry, rx, by, bx, cnt;
};
info start;

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };
int n, m;
int ret = INT_MAX;
bool visited[11][11][11][11];
char a[11][11];
string s;

void bead(info start) {
	visited[start.ry][start.rx][start.by][start.bx] = true;

	queue<info> q;
	q.push(start);

	while (!q.empty()) {
		info cur = q.front(); q.pop();

		if (cur.cnt > 10) { //횟수가 10번을 넘었다면
			ret = -1;
			break;
		}

		if (a[cur.ry][cur.rx] == 'O' && a[cur.by][cur.bx] != 'O') { //빨간 구슬만 빼낼 수 있다면
			ret = min(ret, cur.cnt);
			break;
		}

		for (int dir = 0; dir < 4; dir++) {
			/**
			 * 본인이 벽이거나 구멍인지 우선적으로 확인
			 * 일반적인 ny = y + dy[i]로 진행하면, 초기 y가 구멍인데도 반복문이 수행되는 문제가 발생할 수 있다
			 */
			int nry = cur.ry;
			int nrx = cur.rx;
			int nby = cur.by;
			int nbx = cur.bx;
			
			while (true) {
				if (a[nry][nrx] != '#' && a[nry][nrx] != 'O') { //구멍이나 벽이 아니라면 dir 방향으로 이동
					nry += dy[dir];
					nrx += dx[dir];
				}
				else {
					if (a[nry][nrx] == '#') { //벽이라면 한 칸 뒤로 이동 후 break
						nry -= dy[dir];
						nrx -= dx[dir];
						break;
					}
					else { //구멍이라면 즉시 break
						break;
					}
				}
			}

			while (true) {
				if (a[nby][nbx] != '#' && a[nby][nbx] != 'O') { //구멍이나 벽이 아니라면 dir 방향으로 이동
					nby += dy[dir];
					nbx += dx[dir];
				}
				else {
					if (a[nby][nbx] == '#') { //벽이라면 한 칸 뒤로 이동 후 break
						nby -= dy[dir];
						nbx -= dx[dir];
						break;
					}
					else { //구멍이라면 즉시 break
						break;
					}
				}
			}

			if (nry == nby && nrx == nbx) { //구슬이 겹칠 때
				if (a[nry][nrx] != 'O') { //구멍이 아니라면
					int r_dist = abs(cur.ry - nry) + abs(cur.rx - nrx);
					int b_dist = abs(cur.by - nby) + abs(cur.bx - nbx);

					if (r_dist > b_dist) {
						nry -= dy[dir];
						nrx -= dx[dir];
					}
					else {
						nby -= dy[dir];
						nbx -= dx[dir];
					}
				}
			}

			if (!visited[nry][nrx][nby][nbx]) {
				visited[nry][nrx][nby][nbx] = true;
				q.push({ nry,nrx,nby,nbx,cur.cnt + 1 });
			}
		}
	}

	//큐가 비었는데도 갱신되지 않았다면 -1 반환
	if (ret == INT_MAX) {
		ret = -1;
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

			if (a[i][j] == 'R') {
				start.ry = i;
				start.rx = j;
			}

			if (a[i][j] == 'B') {
				start.by = i;
				start.bx = j;
			}
		}
	}

	bead(start);

	cout << ret;

	return 0;
}
