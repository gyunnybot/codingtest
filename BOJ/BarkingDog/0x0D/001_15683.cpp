#include<iostream>
#include<vector>
#include<climits> //INT_MAX
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, board[10][10];
int ret = INT_MAX;
vector<pair<int, int>> cctv;

vector<pair<int, int>> spread(int cnt, int dir) {
    vector<pair<int, int>> ret;

    pair<int, int> cur_cctv = cctv[cnt]; //현재 cctv의 좌표

    if (board[cur_cctv.first][cur_cctv.second] == 1) {
        pair<int, int> cur = cur_cctv;

        while (true) {
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) break;

            if (board[ny][nx] != 6) {
                if (board[ny][nx] == 0) {
                    board[ny][nx] = 7;
                    ret.push_back({ ny,nx });
                }

                cur = { ny,nx };
            }
            else {
                break;
            }                 
        }
    }
    else if (board[cur_cctv.first][cur_cctv.second] == 2) {
        for (int i = 0; i <= 2; i += 2) {
            pair<int, int> cur = cur_cctv;

            while (true) {
                int ny = cur.first + dy[(dir + i) % 4];
                int nx = cur.second + dx[(dir + i) % 4];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m) break;

                if (board[ny][nx] != 6) {
                    if (board[ny][nx] == 0) {
                        board[ny][nx] = 7;
                        ret.push_back({ ny,nx });
                    }

                    cur = { ny,nx };
                }
                else {
                    break;
                }
            }
        }
    }
    else if (board[cur_cctv.first][cur_cctv.second] == 3) {
        for (int i = 0; i < 2; i++) {
            pair<int, int> cur = cur_cctv;

            while (true) {
                int ny = cur.first + dy[(dir + i) % 4];
                int nx = cur.second + dx[(dir + i) % 4];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m) break;

                if (board[ny][nx] != 6) {
                    if (board[ny][nx] == 0) {
                        board[ny][nx] = 7;
                        ret.push_back({ ny,nx });
                    }

                    cur = { ny,nx };
                }
                else {
                    break;
                }
            }
        }
    }
    else if (board[cur_cctv.first][cur_cctv.second] == 4) {
        for (int i = 0; i < 3; i++) {
            pair<int, int> cur = cur_cctv;

            while (true) {
                int ny = cur.first + dy[(dir + i) % 4];
                int nx = cur.second + dx[(dir + i) % 4];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m) break;

                if (board[ny][nx] != 6) {
                    if (board[ny][nx] == 0) {
                        board[ny][nx] = 7;
                        ret.push_back({ ny,nx });
                    }

                    cur = { ny,nx };
                }
                else {
                    break;
                }
            }
        }
    }
    else if (board[cur_cctv.first][cur_cctv.second] == 5) {
        for (int i = 0; i < 4; i++) {
            pair<int, int> cur = cur_cctv;

            while (true) {
                int ny = cur.first + dy[(dir + i) % 4];
                int nx = cur.second + dx[(dir + i) % 4];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m) break;

                if (board[ny][nx] != 6) {
                    if (board[ny][nx] == 0) {
                        board[ny][nx] = 7;
                        ret.push_back({ ny,nx });
                    }

                    cur = { ny,nx };
                }
                else {
                    break;
                }
            }
        }
    }

    return ret;
}

void recur(int cnt) { //cnt = cctv의 인덱스
    if (cnt == cctv.size()) { //모든 cctv를 조사했다면
        int num = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 0) {
                    num++; //사각지대 계산
                }
            }
        }

        ret = min(ret, num); //사각지대의 최솟값 갱신

        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        vector<pair<int, int>> spreaded_list = spread(cnt, dir); //cnt 번째 cctv 작동시키기

        recur(cnt + 1); //다음 cctv 계산

        for (pair<int, int> pi : spreaded_list) {
            board[pi.first][pi.second] = 0; //cctv 회전 후 작동을 위한 원상 복구
        }
    }    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];

            if (board[i][j] != 0 && board[i][j] != 6) {
                cctv.push_back({ i,j });
            }
        }
    }

    recur(0); //0 번째 cctv부터 조사

    cout << ret;

    return 0;
}
