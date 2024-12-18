#include<iostream>
#include<queue>
using namespace std;

struct info {
    int y, x, dist;
};
queue<info> q[10];

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, m, p, s[10], area[10];
bool expandable[1001][1001];
char a[1001][1001];
string input_string;

void bfs() {
    while (true) {
        bool flag = false;

        for (int i = 1; i <= p; i++) {
            queue<info> next_q;

            while (!q[i].empty()) {
                info cur = q[i].front(); q[i].pop();

                if (cur.dist >= s[i]) {
                    next_q.push({ cur.y,cur.x,0 });
                    continue;
                }

                for (int d = 0; d < 4; d++) {
                    int ny = cur.y + dy[d];
                    int nx = cur.x + dx[d];
                    int na = cur.dist + 1;

                    if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                    if (!expandable[ny][nx]) continue;

                    q[i].push({ ny,nx,na });
                    expandable[ny][nx] = false;

                    area[i]++;

                    flag = true;
                }
            }

            q[i] = next_q;
        }

        if (!flag) break;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> p;

    for (int i = 1; i <= p; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> input_string;

        for (int j = 0; j < m; j++) {
            a[i][j] = input_string[j];

            if (a[i][j] == '.') {
                expandable[i][j] = true; //확장 가능
            }
            else if (a[i][j] == '#') {
                expandable[i][j] = false; //확장 불가능
            }
            else { //숫자라면
                expandable[i][j] = false; //시작점은 재탈환 X. 확장 불가능

                q[a[i][j] - '0'].push({ i,j,0 }); //i번째 플레이어의 시작점을 각 queue에 저장
                area[a[i][j] - '0']++; //i번째 플레이어가 차지한 영역 초기화: 1부터 시작
            }
        }
    }

    bfs();

    for (int i = 1; i <= p; i++) {
        cout << area[i] << ' ';
    }

    return 0;
}
