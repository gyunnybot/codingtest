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

            if (idx == 9) { //타순이 한 바퀴 돌았다면
                idx = 0; //다시 1번 타순(idx = 0)으로 돌아가기
            }

            if (!move) {
                out++; //아웃 카운트 증가
                continue;
            }

            //점수와 진루 계산
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
    if (k == 9) { //타순이 모두 정해졌다면
        run(); //점수 계산 시작
        return;
    }

    if (k == 3) { //아인타는 자신이 가장 좋아하는 선수인 1번 선수를 4번 타자로 미리 결정했다
        recur(k + 1);
        return;
    }

    for (int i = 1; i < 9; i++) { //2번 ~ 9번 선수의 타순 정하기. 1번 선수(i = 0)는 4번 타순(k = 3)이다
        if (visited[i]) continue;

        order[k] = i; //k + 1 번째 타순에 i + 1번 선수가 등판한다
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
