#include<iostream>
#include<vector>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };

vector<pair<int, int>> blocks, ret_blocks;
string s;
char a[14][8];
bool visited[14][8];
int ret;

void dfs(int y, int x, char color) {
    visited[y][x] = 1;

    blocks.push_back({ y,x });

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
                    dfs(i, j, a[i][j]); //폭발 가능한 블록 덩어리 찾기

                    if (blocks.size() >= 4) {
                        flag = true; //폭발 가능

                        //폭발 가능한 블록들을 ret_blocks에 저장하기
                        for (pair<int, int> pos : blocks) {
                            ret_blocks.push_back(pos);
                        }
                    }

                    blocks.clear(); //블록 덩어리 초기화
                }
            }
        }

        //ret_blocks에 저장된 블록들을 '.'으로 바꾸기(폭발)
        for (int i = 0; i < ret_blocks.size(); i++) {
            a[ret_blocks[i].first][ret_blocks[i].second] = '.';
        }

        ret_blocks.clear();

        //한 칸씩 아래로 내리기
        for (int i = 11; i >= 0; i--) {
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

        if (flag) { //폭발이 발생했다면 연쇄 추가 후 while문 다시 진행
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
