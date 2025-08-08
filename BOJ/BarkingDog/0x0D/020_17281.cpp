#include<iostream>
using namespace std;

int n, a[51][9], order[9], ret;
bool visited[9], bases[4];

void run() {
    int score = 0;
    int idx = 0;

    for (int inning = 0; inning < n; inning++) {
        fill(&bases[0], &bases[0] + 4, false);

        int out = 0;

        while (out < 3) {
            bases[0] = true;

            int move = a[inning][order[idx++]];

            if (idx == 9) {
                idx = 0;
            }

            if (!move) { //진루하지 못하면 아웃 카운트 증가
                out++;
                continue;
            }

            //득점 계산
            for (int i = 3; i >= 0; i--) {
                if (!bases[i]) continue;

                if (i + move >= 4) {
                    score++;
                }
                else {
                    bases[i + move] = true;
                }

                bases[i] = false;
            }
        }
    }

    ret = max(ret, score);

    return;
}

void recur(int k) {
    if (k == 9) { //모든 타석에 타자를 배치했다면
        run(); //점수 계산 시작
        return;
    }

    if (k == 3) { //아인타는 자신이 가장 좋아하는 선수인 1번 선수를 4번 타자로 미리 결정했다
        recur(k + 1);
        return;
    }

    for (int i = 1; i < 9; i++) { //i = 0인 선수는 1번 선수다. 4번 타자로 미리 결정
        if (visited[i]) continue;

        order[k] = i; //k 번째 타석의 선수 번호를 i로 결정
        visited[i] = true;

        recur(k + 1);

        visited[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> a[i][j];
        }
    }

    recur(0);

    cout << ret;

    return 0;
}
