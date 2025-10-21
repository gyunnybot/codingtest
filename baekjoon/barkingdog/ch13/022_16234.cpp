#include<iostream>
#include<vector>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, l, r, a[51][51], ret;
bool visited[51][51];
vector<pair<int, int>> v;

void move_population(vector<pair<int, int>>& v) {
    int cnt = 0;

    for (pair<int, int> pi : v) {
        cnt += a[pi.first][pi.second];
    }

    for (pair<int, int> pi : v) {
        a[pi.first][pi.second] = cnt / v.size();
    }

    return;
}

void dfs(int y, int x) {
    visited[y][x] = true;
    v.push_back({ y,x });

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

        if (!visited[ny][nx] && l <= abs(a[ny][nx] - a[y][x]) && abs(a[ny][nx] - a[y][x]) <= r) {
            dfs(ny, nx);
        }
    }

    return;
}

void check_move() {
    while (true) {
        fill(&visited[0][0], &visited[0][0] + 51 * 51, false);

        bool flag = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    dfs(i, j);

                    if (v.size() > 1) {
                        move_population(v);
                        flag = true;
                    }

                    v.clear();
                }
            }
        }

        if (!flag) break;

        ret++;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> l >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    check_move();

    cout << ret;

    return 0;
}
