#include<iostream>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, board[501][501], ret;
bool visited[501][501];

void dfs(int y, int x, int cnt, int sum) {
    if (cnt == 4) {
        ret = max(ret, sum);
        return;
    }

    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

        if (!visited[ny][nx]) {
            dfs(ny, nx, cnt + 1, sum + board[ny][nx]);
        }
    }

    visited[y][x] = false;
}

//combi_dfs는 ㅗ,ㅜ,ㅏ,ㅓ로 뻗어나갈 수 없기 때문에 배열의 값을 직접 더해 해당 블록을 완성한다
void check_extra_shape(int y, int x) {
    if (y >= 1 && x >= 1 && x + 1 < m) {
        ret = max(ret, board[y][x] + board[y - 1][x] + board[y][x - 1] + board[y][x + 1]); //ㅗ
    }

    if (y + 1 < n && x >= 1 && x + 1 < m) {
        ret = max(ret, board[y][x] + board[y + 1][x] + board[y][x - 1] + board[y][x + 1]); //ㅜ
    }

    if (y >= 1 && y + 1 < n && x + 1 < m) {
        ret = max(ret, board[y][x] + board[y - 1][x] + board[y + 1][x] + board[y][x + 1]); //ㅏ
    }

    if (y >= 1 && y + 1 < n && x >= 1) {
        ret = max(ret, board[y][x] + board[y - 1][x] + board[y + 1][x] + board[y][x - 1]); //ㅓ
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dfs(i, j, 1, board[i][j]); //'ㅏ'를 제외한 모양을 dfs로 조사 후 점수 계산
            check_extra_shape(i, j); //dfs로 만들 수 없는 모양 'ㅏ' 조사 후 점수 계산
        }
    }

    cout << ret;

    return 0;
}
