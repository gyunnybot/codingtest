#include<iostream>
using namespace std;

const int dy[] = { 0,-1,0,1 };
const int dx[] = { 1,0,-1,0 };
int n, x, y, d, g, ret, gen, curve[1024];
bool a[101][101];

void dragon_curve(int y, int x, int d, int g) {
    fill(&curve[0], &curve[0] + 1024, 0); //init
    gen = 0; //init

    curve[gen] = d; //입력된 d를 0세대 커브의 방향으로 저장
    gen++;

    //데칼코마니 전개
    for (int i = 0; i < g; i++) {
        for (int j = gen - 1; j >= 0; j--) {
            curve[gen] = (curve[j] + 1) % 4; //반시계 회전
            gen++;
        }
    }

    a[y][x] = true; //초기 드래곤 커브

    for (int i = 0; i < gen; i++) {
        int ny = y + dy[curve[i]];
        int nx = x + dx[curve[i]];

        if (ny < 0 || ny >= 101 || nx < 0 || nx >= 101) continue;

        a[ny][nx] = true;

        y = ny;
        x = nx;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y >> d >> g;
        dragon_curve(y, x, d, g);
    }

    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            if (a[i][j] && a[i][j + 1] && a[i + 1][j] && a[i + 1][j + 1]) {
                ret++;
            }
        }
    }

    cout << ret;

    return 0;
}
