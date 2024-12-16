#include<iostream>
#include<climits> //INT_MAX
#include<queue>
#include<vector>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, fire_visited[1001][1001], j_visited[1001][1001], ret;
char a[1001][1001];
pair<int, int> j_pos;
vector<pair<int, int>> fire_pos;
string s;

void j_bfs() {
    j_visited[j_pos.first][j_pos.second] = 1;

    queue<pair<int, int>> q;
    q.push(j_pos);

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        if (cur.first == 0 || cur.second == 0 || cur.first == n - 1 || cur.second == m - 1) {
            ret = j_visited[cur.first][cur.second];
            break;
        }

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (a[ny][nx] == '#') continue;
            if (fire_visited[ny][nx] <= j_visited[cur.first][cur.second] + 1) continue; //좌표에 이미 불이 붙었을 때

            if (a[ny][nx] == '.' && !j_visited[ny][nx]) {
                j_visited[ny][nx] = j_visited[cur.first][cur.second] + 1;
                q.push({ ny,nx });
            }
        }
    }

    return;
}

void fire_bfs() {
    for (pair<int, int> i : fire_pos) {
        fire_visited[i.first][i.second] = 1;
    }

    queue<pair<int, int>> q;
    for (pair<int, int> fire : fire_pos) {
        q.push(fire);
    }

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (a[ny][nx] == '#') continue;

            if (a[ny][nx] == '.' && fire_visited[ny][nx] == INT_MAX) {
                fire_visited[ny][nx] = fire_visited[cur.first][cur.second] + 1;
                q.push({ ny,nx });
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
            a[i][j] = s[j];

            if (a[i][j] == 'J') {
                j_pos = { i,j };
            }

            if (a[i][j] == 'F') {
                fire_pos.push_back({ i,j });
            }
        }
    }

    fill(&fire_visited[0][0], &fire_visited[0][0] + 1001 * 1001, INT_MAX);

    fire_bfs();
    j_bfs();

    if (ret) {
        cout << ret;
    }
    else {
        cout << "IMPOSSIBLE";
    }

    return 0;
}
