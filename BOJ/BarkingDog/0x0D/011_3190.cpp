#include<iostream>
#include<vector>
#include<deque>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, k, y, x, L, t, dir, ret;
bool board[101][101], visited[101][101];
char c;
deque<pair<int, int>> t_list;

void snake() {
	visited[0][0] = true; //뱀은 처음에 맨위, 맨좌측에 위치, 길이는 1 이다

	deque<pair<int, int>> dq;
	dq.push_back({ 0,0 });

	dir = 1; //뱀은 처음에 오른쪽을 향한다

	while (!dq.empty()) {
		ret++;

		pair<int, int> cur = dq.front();

		int ny = cur.first + dy[dir];
		int nx = cur.second + dx[dir];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n) break; //벽에 부딪히는 경우
		if (visited[ny][nx]) break; //자기 자신의 몸과 부딪히는 경우

		dq.push_front({ ny,nx });
		visited[ny][nx] = true;

		if (board[ny][nx] == 1) { //사과가 있다면
			board[ny][nx] = 0;
		}
		else { //사과가 없다면 몸길이를 줄여서 '꼬리'가 위치한 칸을 비워준다
			visited[dq.back().first][dq.back().second] = 0;
			dq.pop_back();
		}

		if (!t_list.empty() && (ret == t_list.front().first)) { //입력한 시간이 되면 방향을 바꾼다
			dir = (dir + t_list.front().second) % 4;
			t_list.pop_front();
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		cin >> y >> x;
		board[y - 1][x - 1] = 1;
	}

	cin >> L;

	for (int i = 0; i < L; i++) {
		cin >> t >> c;

		if (c == 'D') {
			t_list.push_back({ t,1 });
		}
		else {
			t_list.push_back({ t,3 });
		}
	}

	snake();

	cout << ret;

	return 0;
}
