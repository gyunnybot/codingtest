#include<iostream>
#include<vector>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };

vector<pair<int, int>> cur_blocks, ret_blocks;
string s;
char a[14][8];
bool visited[14][8];
int ret;

void dfs(int y, int x, char color) {
    visited[y][x] = 1;

    cur_blocks.push_back({ y,x });

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= 12 || nx < 0 || nx >= 6) continue;

        if (a[ny][nx] == color && !visited[ny][nx]) {
            dfs(ny, nx, color);
        }
    }

    return;
}

void puyo() {
    while (true) {
        bool flag = false;

        fill(&visited[0][0], &visited[0][0] + 14 * 8, false);

        for (int i = 11; i >= 0; i--) {
            for (int j = 0; j < 6; j++) {
                if (a[i][j] != '.' && !visited[i][j]) {
                    dfs(i, j, a[i][j]); //터뜨릴 블록 덩어리 찾기

                    if (cur_blocks.size() >= 4) {
                        flag = true;

                        //터뜨릴 블록들을 ret_blocks에 저장
                        for (pair<int, int> pos : cur_blocks) {
                            ret_blocks.push_back(pos);
                        }
                    }

                    cur_blocks.clear(); //터뜨릴 블록 덩어리 초기화
                }
            }
        }

        //블록 터뜨리기 = ret_blocks에 저장된 블록들을 '.'으로 바꾸기
        for (int i = 0; i < ret_blocks.size(); i++) {
            a[ret_blocks[i].first][ret_blocks[i].second] = '.';
        }

        ret_blocks.clear(); //터뜨릴 전체 블록 모음 초기화

        //뿌요는 중력의 영향을 받아 아래에 바닥이나 다른 뿌요가 나올 때까지 아래로 떨어진다
        for (int i = 11; i >= 0; i--) { //맨 아래 행부터 계산
            for (int j = 0; j < 6; j++) {
                if (a[i][j] == '.') continue;

                int tmp = i;

                while (true) {
                    if (tmp == 11 || a[tmp + 1][j] != '.') { //바닥에 도달했거나 블록이 막고 있다면 break
                        break;
                    }
                    else {
                        a[tmp + 1][j] = a[tmp][j];
                        a[tmp][j] = '.';
                        tmp++;
                    }
                }
            }
        }

        if (flag) { //연쇄가 발생했다면 전체 while문 다시 실행하여 추가 연쇄 확인
            ret++;
        }
        else {
            break;
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 12; i++) {
        cin >> s;

        for (int j = 0; j < 6; j++) {
            a[i][j] = s[j];
        }
    }

    puyo();

    cout << ret;

    return 0;
}
