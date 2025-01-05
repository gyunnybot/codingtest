#include<iostream>
#include<vector>
#include<climits> //INT_MIN
using namespace std;

int t, w, dp[1004][2][34], pos[1004]; //dp[시간][위치][남은 횟수]

int plum(int idx, int tree, int cnt) {
    if (cnt < 0) {
        return INT_MIN; //횟수가 넘어가면 최솟값 반환
    }

    if (idx == t) {
        return 0; //입력된 시간에 도달하면 0 반환
    }

    if (dp[idx][tree][cnt] != -1) {
        return dp[idx][tree][cnt];
    }

    dp[idx][tree][cnt] = max(plum(idx + 1, tree ^ 1, cnt - 1), plum(idx + 1, tree, cnt)) + (tree == pos[idx] - 1);
    
    return dp[idx][tree][cnt];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    fill(&dp[0][0][0], &dp[0][0][0] + 1002 * 2 * 34, -1); //1520번 내리막길과 같은 논리

    cin >> t >> w;

    for (int i = 0; i < t; i++) {
        cin >> pos[i];
    }

    cout << max(plum(0, 0, w), plum(0, 1, w - 1));

    return 0;
}