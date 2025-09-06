#include<iostream>
#include<vector>
#include<climits> //INT_MAX
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m;
int ret = INT_MAX;
vector<pair<int, int>> cctv;

struct Board {
    int a[9][9];

    void get_area() {
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 0) {
                    cnt++;
                }
            }
        }

        ret = min(ret, cnt);

        return;
    }

    void operate_cctv(int cctv_idx, int dir) {
        pair<int, int> cur_pos = cctv[cctv_idx];

        if (a[cur_pos.first][cur_pos.second] == 1) {
            pair<int, int> cur = cur_pos;

            while (true) {
                int ny = cur.first + dy[dir];
                int nx = cur.second + dx[dir];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m) break;

                if (a[ny][nx] != 6) {
                    if (a[ny][nx] == 0) {
                        a[ny][nx] = 7;
                    }

                    cur = { ny,nx };
                }
                else {
                    break;
                }
            }
        }
        else if (a[cur_pos.first][cur_pos.second] == 2) {
            for (int i = 0; i <= 2; i += 2) {
                pair<int, int> cur = cur_pos;

                while (true) {
                    int ny = cur.first + dy[(dir + i) % 4];
                    int nx = cur.second + dx[(dir + i) % 4];

                    if (ny < 0 || ny >= n || nx < 0 || nx >= m) break;

                    if (a[ny][nx] != 6) {
                        if (a[ny][nx] == 0) {
                            a[ny][nx] = 7;
                        }

                        cur = { ny,nx };
                    }
                    else {
                        break;
                    }
                }
            }
        }
        else if (a[cur_pos.first][cur_pos.second] == 3) {
            for (int i = 0; i < 2; i++) {
                pair<int, int> cur = cur_pos;

                while (true) {
                    int ny = cur.first + dy[(dir + i) % 4];
                    int nx = cur.second + dx[(dir + i) % 4];

                    if (ny < 0 || ny >= n || nx < 0 || nx >= m) break;

                    if (a[ny][nx] != 6) {
                        if (a[ny][nx] == 0) {
                            a[ny][nx] = 7;
                        }

                        cur = { ny,nx };
                    }
                    else {
                        break;
                    }
                }
            }
        }
        else if (a[cur_pos.first][cur_pos.second] == 4) {
            for (int i = 0; i < 3; i++) {
                pair<int, int> cur = cur_pos;

                while (true) {
                    int ny = cur.first + dy[(dir + i) % 4];
                    int nx = cur.second + dx[(dir + i) % 4];

                    if (ny < 0 || ny >= n || nx < 0 || nx >= m) break;

                    if (a[ny][nx] != 6) {
                        if (a[ny][nx] == 0) {
                            a[ny][nx] = 7;
                        }

                        cur = { ny,nx };
                    }
                    else {
                        break;
                    }
                }
            }
        }
        else if (a[cur_pos.first][cur_pos.second] == 5) {
            for (int i = 0; i < 4; i++) {
                pair<int, int> cur = cur_pos;

                while (true) {
                    int ny = cur.first + dy[(dir + i) % 4];
                    int nx = cur.second + dx[(dir + i) % 4];

                    if (ny < 0 || ny >= n || nx < 0 || nx >= m) break;

                    if (a[ny][nx] != 6) {
                        if (a[ny][nx] == 0) {
                            a[ny][nx] = 7;
                        }

                        cur = { ny,nx };
                    }
                    else {
                        break;
                    }
                }
            }
        }

        return;
    }
};
Board c;

void search(int cctv_idx, Board c) {
    if (cctv_idx == cctv.size()) {
        c.get_area();
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        Board d = c; //deep copy. O(N)

        d.operate_cctv(cctv_idx, dir);

        search(cctv_idx + 1, d);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c.a[i][j];

            if (c.a[i][j] != 0 && c.a[i][j] != 6) {
                cctv.push_back({ i,j });
            }
        }
    }

    search(0, c);

    cout << ret;

    return 0;
}
