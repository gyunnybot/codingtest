#include<iostream>
#include<queue>
using namespace std;

struct info {
	int ry, rx, by, bx, cnt;
};
info start;

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };
int n, m;
int ret = -1;
bool visited[11][11][11][11];
char board[11][11];
string s;

void bead(info start) {
	visited[start.ry][start.rx][start.by][start.bx] = true;

	queue<info> q;
	q.push(start);

	while (!q.empty()) {
		info cur = q.front(); q.pop();

		if (cur.cnt > 10) break; //빼낼 수 없다면 break

		if (board[cur.ry][cur.rx] == 'O' && board[cur.by][cur.bx] != 'O') {
			ret = cur.cnt; //빼낼 수 있다면 ret 갱신 후 break
			break;
		}

		for (int dir = 0; dir < 4; dir++) {
			//본인이 벽이거나 구멍인지 우선적으로 확인한다
			//일반적인 ny = y + dy[i]의 경우, 시작하는 y가 구멍인데도 반복문이 수행되는 로직 오류가 발생한다
			int nry = cur.ry;
			int nrx = cur.rx;
			int nby = cur.by;
			int nbx = cur.bx;

			while (true) {
				if (board[nry][nrx] != '#' && board[nry][nrx] != 'O') {
					nry += dy[dir];
					nrx += dx[dir];
				}
				else {
					if (board[nry][nrx] == '#') {
						nry -= dy[dir];
						nrx -= dx[dir];

						break; //벽이라면 한 칸 뒤로 이동 후 break
					}

					break; //구멍이라면 break
				}
			}

			while (true) {
				if (board[nby][nbx] != '#' && board[nby][nbx] != 'O') {
					nby += dy[dir];
					nbx += dx[dir];
				}
				else {
					if (board[nby][nbx] == '#') {
						nby -= dy[dir];
						nbx -= dx[dir];

						break; //벽이라면 한 칸 뒤로 이동 후 break
					}

					break; //구멍이라면 break
				}
			}

			if (nry == nby && nrx == nbx) {
				if (board[nry][nrx] != 'O') { //겹쳤는데 구멍이 아닌 경우
					int r_dist = abs(cur.ry - nry) + abs(cur.rx - nrx);
					int b_dist = abs(cur.by - nby) + abs(cur.bx - nbx);

					//이전 위치에서의 거리를 구한 후 비교
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

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s;

		for (int j = 0; j < m; j++) {
			board[i][j] = s[j];

			if (board[i][j] == 'R') {
				start.ry = i;
				start.rx = j;
			}

			if (board[i][j] == 'B') {
				start.by = i;
				start.bx = j;
			}
		}
	}

	bead(start);

	cout << ret;

	return 0;
}
