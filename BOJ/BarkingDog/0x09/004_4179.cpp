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

void fire_bfs() {
    //fire_visited가 더 커야(나중에 방문) 지훈이가 이동할 수 있으므로 INT_MAX로 초기화
    //0으로 초기화된다면 불이 없을 때에도 지훈이는 어디로도 이동할 수 없게 된다
    fill(&fire_visited[0][0], &fire_visited[0][0] + 1001 * 1001, INT_MAX);

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

            if (fire_visited[ny][nx] == INT_MAX) {
                fire_visited[ny][nx] = fire_visited[cur.first][cur.second] + 1;
                q.push({ ny,nx });
            }
        }
    }

    return;
}

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
            if (fire_visited[ny][nx] <= j_visited[cur.first][cur.second] + 1) continue; //이미 불이 붙었다면

            if (a[ny][nx] == '.' && !j_visited[ny][nx]) {
                j_visited[ny][nx] = j_visited[cur.first][cur.second] + 1;
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

    fire_bfs();
    j_bfs(); //fire_visited가 필요하므로 fire_bfs보다 나중에 실행

    if (!ret) {
        cout << "IMPOSSIBLE";
    }
    else {       
        cout << ret;
    }

    return 0;
}
