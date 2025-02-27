#include<iostream>
using namespace std;

int n, m, k, r, c, ret, a[42][42], paper[12][12];

void rotate() {
    int temp[12][12];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            temp[j][r - i - 1] = paper[i][j]; //clock wise
            //temp[c - j - 1][i] = paper[i][j]; //counter-clock wise
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            paper[i][j] = 0;
        }
    }

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            paper[i][j] = temp[i][j];
        }
    }

    swap(r, c);

    return;
}

bool postable(int y, int x) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[y + i][x + j] == 1 && paper[i][j] == 1) {
                return false;
            }
        }
    }

    return true;
}

void post(int y, int x) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (paper[i][j] == 1) {
                a[y + i][x + j] = 1;
            }
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;

    while (k--) {
        fill(&paper[0][0], &paper[0][0] + 12 * 12, 0);

        cin >> r >> c;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> paper[i][j];
            }
        }

        bool flag = false;

        for (int dir = 0; dir < 4; dir++) {
            for (int y = 0; y <= n - r; y++) {
                for (int x = 0; x <= m - c; x++) {
                    if (postable(y, x)) {                      
                        post(y, x);

                        flag = true;
												
                        break;
                    }
                }

                if (flag) break;
            }

            if (flag) break;

            rotate();
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ret += a[i][j];
        }
    }

    cout << ret;

    return 0;
}
