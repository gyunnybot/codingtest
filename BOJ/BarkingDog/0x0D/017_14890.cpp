#include<iostream>
#include<vector>
#include<climits> //INT_MAX
using namespace std;

int n, L, a[101][101], b[101][101], ret;

void slope(int a[101][101]) {
    for (int i = 0; i < n; i++) {
        int cnt = 1; //현재 본인과 같은 높이의 블록의 수
        int j;

        for (j = 0; j < n - 1; j++) {
            if (a[i][j] == a[i][j + 1]) cnt++; //본인과 같은 높이의 블록의 수 증가
            else if (a[i][j] == a[i][j + 1] - 1 && cnt >= L) cnt = 1; //높아진 블록에서 새출발
            else if (a[i][j] == a[i][j + 1] + 1 && cnt >= 0) cnt = -L + 1; //L을 온전히 품을 때까지 cnt 조정
            else break;
            //올라가는 경사로의 길이만큼의 cnt가 없거나 (두 번째 if 문)
            //내려가는 경사로가 깔릴만큼의 배열의 길이가 없어 cnt = 0이 안된다면 (세 번째 if 문) break
        }

        if (j == n - 1 && cnt >= 0) { //cnt < 0일 경우 내려가는 경사로가 범위를 벗어난다
            ret++;
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> L;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];

            b[j][i] = a[i][j]; //transpos
        }
    }

    slope(a);
    slope(b);

    cout << ret;

    return 0;
}
