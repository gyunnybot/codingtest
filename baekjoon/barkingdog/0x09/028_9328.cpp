#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };

int t, h, w, ret;
char a[101][101];
bool visited[101][101];
set<char> keys;
string key_str, s;
queue<pair<int, int>> door[28]; //열쇠로 풀지 못한 문의 좌표를 알파벳별로 저장

void bfs() {
    queue<pair<int, int>> q;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                if (a[i][j] != '*') {
                    visited[i][j] = true;
                    q.push({ i,j }); //시작점 push
                }
            }
        }
    }

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        //문서 발견
        if (a[cur.first][cur.second] == '$') {
            a[cur.first][cur.second] = '.';
            ret++;
        }

        //열쇠 발견
        if ('a' <= a[cur.first][cur.second] && a[cur.first][cur.second] <= 'z') {
            if (keys.find(a[cur.first][cur.second]) == keys.end()) { //열쇠를 소유하고 있지 않다면.. set = st.end(), string = string::npos
                keys.insert(a[cur.first][cur.second]); //새로 얻은 열쇠를 열쇠꾸러미에 추가

                int key_idx = a[cur.first][cur.second] - 'a'; //새로 얻은 열쇠의 알파벳 순서 번호 찾기

                while (!door[key_idx].empty()) {
                    q.push(door[key_idx].front()); //새로 얻은 열쇠에 대응되는 알파벳 문의 모든 좌표를 큐에 저장
                    door[key_idx].pop();
                }
            }

            a[cur.first][cur.second] = '.'; //빈 공간으로 변경
        }

        //문 발견
        if ('A' <= a[cur.first][cur.second] && a[cur.first][cur.second] <= 'Z') {
            if (keys.find((a[cur.first][cur.second]) + ('a' - 'A')) == keys.end()) { //알파벳 문에 대응되는 열쇠가 없다면
                door[a[cur.first][cur.second] - 'A'].push(cur); //아직 열쇠가 없으므로 대응되는 알파벳 문 queue에 좌표 추가
                continue; //열쇠가 없으므로 cur에서의 로직 종료 후 최상위 while(!q.empty()) 반복문 재실행
            }
            else { //알파벳 문에 대응되는 열쇠가 있다면
                a[cur.first][cur.second] = '.'; //빈 공간으로 변경
            }
        }

        //인접한 곳 탐색
        for (int dir = 0; dir < 4; dir++) {
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];

            if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if (a[ny][nx] == '*') continue;

            if (!visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push({ ny,nx });
            }
        }
    }

    return;
}

void init() {
    keys.clear();

    ret = 0;

    fill(&visited[0][0], &visited[0][0] + 101 * 101, false);

    for (int i = 0; i < 26; i++) {
        queue<pair<int, int>> flush_door;
        swap(door[i], flush_door); //call by reference. O(1)
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;

    while (t--) {
        init();

        cin >> h >> w;

        for (int i = 0; i < h; i++) {
            cin >> s;

            for (int j = 0; j < w; j++) {
                a[i][j] = s[j];
            }
        }

        cin >> key_str;

        if (key_str != "0") {
            for (char c : key_str) {
                keys.insert(c);
            }
        }

        bfs();

        cout << ret << '\n';
    }

    return 0;
}
