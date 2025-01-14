#include<iostream>
#include<vector>
#include<climits> //INT_MAX
using namespace std;

int n, L, a[101][101], b[101][101], ret;

void slope(int a[101][101]) {
    for (int i = 0; i < n; i++) {
        int cnt = 1; //현재 본인과 같은 높이의 블록의 수(3015번: 오아시스?)
        int j = 0; //열 계산을 위한 j를 행 scope에 선언

        for (j = 0; j < n - 1; j++) {
            if (a[i][j] == a[i][j + 1]) {
                cnt++; //본인과 같은 높이의 블록의 수 증가
            }
            else if (a[i][j] == a[i][j + 1] - 1 && cnt >= L) {
                cnt = 1; //높아진 블록에서 새로운 출발
            }
            else if (a[i][j] - 1 == a[i][j + 1] && cnt >= 0) {
                cnt = -L + 1; //L을 온전히 품을 때까지 cnt 조정
            }
            else {
                //올라가는 경사로의 길이만큼의 cnt가 없거나 (두 번째 조건문)
                //내려가는 경사로가 깔릴만큼의 배열의 길이가 없어 cnt = 0이 안된다면 (세 번째 조건문) break
                break;
            }
        }

        //cnt < 0일 경우 내려가는 경사로가 범위를 벗어난다
        if (j == n - 1 && cnt >= 0) {
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
            b[j][i] = a[i][j]; //R = C인 경우에만 가능한 transpos 연산
        }
    }

    slope(a);
    slope(b);

    cout << ret;

    return 0;
}
