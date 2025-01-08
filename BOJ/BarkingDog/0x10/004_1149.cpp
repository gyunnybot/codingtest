#include<iostream>
using namespace std;

int n, r, g, b, house[1001][3], dp[1001][3], ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> r >> g >> b;

        house[i][0] = r;
        house[i][1] = g;
        house[i][2] = b;
    }
  
    for (int i = 0; i < 3; i++) {
        dp[0][i] = house[0][i];
    }

    //dp[행][색상] = 직전 행, 다른 색상의 집의 dp 중 최소 비용 + 현재 행, 현재 색상의 집의 비용
    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + house[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + house[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + house[i][2];
    }

    ret = min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);

    cout << ret;

    return 0;
}
