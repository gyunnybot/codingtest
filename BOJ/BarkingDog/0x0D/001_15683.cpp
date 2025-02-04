#include<iostream>
#include<vector>
#include<climits> //INT_MAX
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, a[10][10];
int ret = INT_MAX;
vector<pair<int, int>> cctv;

vector<pair<int, int>> spread(int cctv_idx, int dir) {
    vector<pair<int, int>> temp;

    pair<int, int> cur_cctv = cctv[cctv_idx];

    if (a[cur_cctv.first][cur_cctv.second] == 1) {
        pair<int, int> cur = cur_cctv;

        while (true) {
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) break;

            if (a[ny][nx] != 6) {
                if (a[ny][nx] == 0) { //빈 칸이라면
                    a[ny][nx] = 7;
                    temp.push_back({ ny,nx });
                }

                cur = { ny,nx }; //벽만 아니라면 반복문 계속 진행
            }
            else { //벽이라면 break
                break;
            }
        }
    }
    else if (a[cur_cctv.first][cur_cctv.second] == 2) {
        for (int i = 0; i <= 2; i += 2) {
            pair<int, int> cur = cur_cctv; //방향만 바뀔 뿐, 시작점인 cur_cctv는 바뀌지 않는다

            while (true) {
                int ny = cur.first + dy[(dir + i) % 4];
                int nx = cur.second + dx[(dir + i) % 4];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m) break;

                if (a[ny][nx] != 6) {
                    if (a[ny][nx] == 0) {
                        a[ny][nx] = 7;
                        temp.push_back({ ny,nx });
                    }

                    cur = { ny,nx };
                }
                else {
                    break;
                }
            }
        }
    }
    else if (a[cur_cctv.first][cur_cctv.second] == 3) {
        for (int i = 0; i < 2; i++) {
            pair<int, int> cur = cur_cctv;

            while (true) {
                int ny = cur.first + dy[(dir + i) % 4];
                int nx = cur.second + dx[(dir + i) % 4];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m) break;

                if (a[ny][nx] != 6) {
                    if (a[ny][nx] == 0) {
                        a[ny][nx] = 7;
                        temp.push_back({ ny,nx });
                    }

                    cur = { ny,nx };
                }
                else {
                    break;
                }
            }
        }
    }
    else if (a[cur_cctv.first][cur_cctv.second] == 4) {
        for (int i = 0; i < 3; i++) {
            pair<int, int> cur = cur_cctv;

            while (true) {
                int ny = cur.first + dy[(dir + i) % 4];
                int nx = cur.second + dx[(dir + i) % 4];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m) break;

                if (a[ny][nx] != 6) {
                    if (a[ny][nx] == 0) {
                        a[ny][nx] = 7;
                        temp.push_back({ ny,nx });
                    }

                    cur = { ny,nx };
                }
                else {
                    break;
                }
            }
        }
    }
    else if (a[cur_cctv.first][cur_cctv.second] == 5) {
        for (int i = 0; i < 4; i++) {
            pair<int, int> cur = cur_cctv;

            while (true) {
                int ny = cur.first + dy[(dir + i) % 4];
                int nx = cur.second + dx[(dir + i) % 4];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m) break;

                if (a[ny][nx] != 6) {
                    if (a[ny][nx] == 0) {
                        a[ny][nx] = 7;
                        temp.push_back({ ny,nx });
                    }

                    cur = { ny,nx };
                }
                else {
                    break;
                }
            }
        }
    }

    return temp;
}

int get_min() {
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                cnt++; //사각지대 계산
            }
        }
    }

    return cnt;
}

void check(int cctv_idx) {
    if (cctv_idx == cctv.size()) { //모든 cctv를 조사했다면
        ret = min(ret, get_min()); //사각지대의 최솟값 갱신
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        vector<pair<int, int>> spreaded_area = spread(cctv_idx, dir); //cctv가 감시한 구역 저장

        check(cctv_idx + 1); //다음 cctv 조사

        for (pair<int, int> pi : spreaded_area) {
            a[pi.first][pi.second] = 0; //cctv가 감시한 구역 원상 복구
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];

            if (a[i][j] != 0 && a[i][j] != 6) {
                cctv.push_back({ i,j });
            }
        }
    }

    check(0); //0번째 cctv부터 조사

    cout << ret;

    return 0;
}
