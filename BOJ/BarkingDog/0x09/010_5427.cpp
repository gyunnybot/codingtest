#include<iostream>
#include<vector>
#include<queue>
#include<climits> //INT_MAX
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int t, n, m, fire_visited[1001][1001], s_visited[1001][1001], ret;
char a[1001][1001];
pair<int, int> s_pos;
vector<pair<int, int>> fire_Pos;
string s;

void fire_bfs() {
    //fire_visited가 더 커야(나중에 방문) 상근이가 이동할 수 있으므로 INT_MAX로 초기화
    //0으로 초기화된다면 불이 없을 때에도 상근이는 어디로도 이동할 수 없게 됩니다
    fill(&fire_visited[0][0], &fire_visited[0][0] + 1001 * 1001, INT_MAX);

    for (pair<int, int> fire : fire_Pos) {
        fire_visited[fire.first][fire.second] = 1;
    }

    queue<pair<int, int>> q;
    for (pair<int, int> fire : fire_Pos) {
        q.push(fire);
    }

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
            if (a[ny][nx] == '#') continue;

            if (fire_visited[ny][nx] == INT_MAX) {
                fire_visited[ny][nx] = fire_visited[cur.first][cur.second] + 1;
                q.push({ ny,nx });
            }
        }
    }

    return;
}

void s_bfs() {
    fill(&s_visited[0][0], &s_visited[0][0] + 1001 * 1001, 0);

    s_visited[s_pos.first][s_pos.second] = 1;

    queue<pair<int, int>> q;
    q.push(s_pos);

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        if (cur.first == 0 || cur.first == m - 1 || cur.second == 0 || cur.second == n - 1) {
            ret = s_visited[cur.first][cur.second];
            break;
        }

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
            if (a[ny][nx] == '#') continue;
            if (fire_visited[ny][nx] <= s_visited[cur.first][cur.second] + 1) continue; //이미 불이 붙었다면

            if (a[ny][nx] == '.' && !s_visited[ny][nx]) {
                s_visited[ny][nx] = s_visited[cur.first][cur.second] + 1;
                q.push({ ny,nx });
            }
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;

    while (t--) {
        fire_Pos.clear();
        ret = 0;

        cin >> n >> m;

        for (int i = 0; i < m; i++) {
            cin >> s;

            for (int j = 0; j < n; j++) {
                a[i][j] = s[j];

                if (a[i][j] == '@') {
                    s_pos = { i,j };
                }
                
                if (a[i][j] == '*') {
                    fire_Pos.push_back({ i,j });
                }
            }
        }

        fire_bfs();
        s_bfs(); //fire_visited가 필요하므로 fire_bfs보다 나중에 실행

        if (!ret) {
            cout << "IMPOSSIBLE" << '\n';
        }
        else {
            cout << ret << '\n';
        }
    }

    return 0;
}
