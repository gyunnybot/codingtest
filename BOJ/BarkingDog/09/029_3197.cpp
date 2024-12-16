#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, ret;
char a[1501][1501];
bool visited[1501][1501], water_visited[1501][1501];
queue<pair<int, int>> water, next_water;
queue<pair<int, int>> swan_q, next_swan_q;
vector<pair<int, int>> swan;
string s;

bool meet() {
    while (!swan_q.empty()) {
        pair<int, int> cur = swan_q.front(); swan_q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

            if (!visited[ny][nx]) {
                visited[ny][nx] = true;

                if (a[ny][nx] == 'L') { //두 백조가 만났다면
                    return true;
                }
                else if (a[ny][nx] == '.') {
                    swan_q.push({ ny,nx }); //현재 백조가 실제로 다니는 경로(백조 또는 물)
                }
                else if (a[ny][nx] == 'X') {
                    next_swan_q.push({ ny,nx }); //얼음이 녹은 후 백조가 다닐 수 있는 좌표
                }
            }
        }
    }

    return false;
}

void melt() {
    while (!water.empty()) {
        pair<int, int> cur = water.front(); water.pop();

        water_visited[cur.first][cur.second] = true;

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

            if (!water_visited[ny][nx]) {
                water_visited[ny][nx] = true;

                if (a[ny][nx] == 'X') {
                    a[ny][nx] = '.'; //얼음 녹이기
                    next_water.push({ ny,nx }); //얼음이 녹은 후 백조가 다닐 수 있는 경로(물)
                }
            }
        }
    }

    return;
}

void bfs() {
    visited[swan[0].first][swan[0].second] = true;
    swan_q.push(swan[0]); //현재 백조가 실제로 다니는 경로(백조 또는 물)

    while (true) {
        if (meet()) {
            break;
        }

        melt();

        swap(swan_q, next_swan_q);
        swap(water, next_water);

        ret++;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> s;

        for (int j = 0; j < m; j++) {
            a[i][j] = s[j];

            if (a[i][j] != 'X') {
                water.push({ i,j }); //백조가 다닐 수 있는 경로(백조 또는 물)
            }

            if (a[i][j] == 'L') {
                swan.push_back({ i, j });
            }
        }
    }

    bfs();

    cout << ret;

    return 0;
}
