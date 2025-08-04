#include<iostream>
#include<vector>
#include<climits> //INT_MIN
using namespace std;

int t, w, a[1004], dp[1004][2][34]; //dp[시간][위치][남은 횟수]

int plum(int idx, int tree, int cnt) {
    if (cnt < 0) {
        return INT_MIN;
    }

    if (idx == t) {
        return 0;
    }
    
    if (dp[idx][tree][cnt] != -1) {
        return dp[idx][tree][cnt];
    }

    dp[idx][tree][cnt] = max(plum(idx + 1, tree ^ 1, cnt - 1), plum(idx + 1, tree, cnt)) + (tree == (a[idx] - 1));

    return dp[idx][tree][cnt];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t >> w;

    for (int i = 0; i < t; i++) {
        cin >> a[i];
    }

    //움직였는데도 불구하고 점수가 0인 경우와 이동이 없어 점수가 0인 경우를 구분하기 위해 -1로 초기화
    fill(&dp[0][0][0], &dp[0][0][0] + 1004 * 2 * 34, -1);

    cout << max(plum(0, 0, w), plum(0, 1, w - 1));

    return 0;
}
