#include <iostream>
using namespace std;

const int dy[] = { 0,-1,0,1 }; // 서 북 동 남
const int dx[] = { -1,0,1,0 };
int n, m, a[51][51], visited[51][51], compare_area[2501], cnt, max_area, max_room_size;

int dfs(int y, int x, int cnt) {
    if (visited[y][x]) {
        return 0;
    }

    visited[y][x] = cnt;

    int ret = 1;

    for (int i = 0; i < 4; i++) {
        if (!(a[y][x] & (1 << i))) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;

            ret += dfs(ny, nx, cnt);
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                cnt++; // 방의 개수

                compare_area[cnt] = dfs(i, j, cnt);

                max_area = max(max_area, compare_area[cnt]);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i + 1 < m && visited[i][j] != visited[i + 1][j]) {
                max_room_size = max(max_room_size, compare_area[visited[i][j]] + compare_area[visited[i + 1][j]]);
            }

            if (j + 1 < n && visited[i][j] != visited[i][j + 1]) {
                max_room_size = max(max_room_size, compare_area[visited[i][j]] + compare_area[visited[i][j + 1]]);
            }
        }
    }

    cout << cnt << '\n' << max_area << '\n' << max_room_size;

    return 0;
}
