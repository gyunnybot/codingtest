#include<iostream>
#include<queue>
using namespace std;

struct info {
    int y, x, a;
};
queue<info> q[10];

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, p, s[10], area[10];
bool canExpend[1001][1001];
char a[1001][1001];
string str;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> p;

    for (int i = 1; i <= p; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> str;

        for (int j = 0; j < m; j++) {
            a[i][j] = str[j];

            if (a[i][j] == '.') {
                canExpend[i][j] = true;
            }
            else if (a[i][j] == '#') {
                canExpend[i][j] = false;
            }
            else {
                canExpend[i][j] = false;

                q[a[i][j] - '0'].push({ i,j,0 });
                area[a[i][j] - '0']++;
            }
        }
    }

    while (true) {
        bool expandable = false;

        for (int i = 1; i <= p; i++) {
            queue<info> next_q;

            while (!q[i].empty()) {
                info cur = q[i].front(); q[i].pop();

                if (cur.a >= s[i]) {
                    next_q.push({ cur.y,cur.x,0 });
                    continue;
                }

                for (int d = 0; d < 4; d++) {
                    int ny = cur.y + dy[d];
                    int nx = cur.x + dx[d];
                    int na = cur.a + 1;

                    if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                    if (!canExpend[ny][nx]) continue;

                    canExpend[ny][nx] = false;
                    q[i].push({ ny,nx,na });
                    
                    area[i]++;

                    expandable = true;
                }
            }

            q[i] = next_q;
        }

        if (!expandable) break;
    }

    for (int i = 1; i <= p; i++) {
        cout << area[i] << ' ';
    }
    
    return 0;
}
