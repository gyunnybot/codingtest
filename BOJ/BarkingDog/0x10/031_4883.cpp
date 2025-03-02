#include<iostream>
#include<climits> //INT_MAX
using namespace std;

int n, a[100001][3], dp[100001][3];
int t = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> n;

        if (n == 0) break;

        fill(&a[0][0], &a[0][0] + 100001 * 3, 0);
        fill(&dp[0][0], &dp[0][0] + 100001 * 3, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> a[i][j];
            }
        }

        dp[0][0] = INT_MAX;
        dp[0][1] = a[0][1];
        dp[0][2] = a[0][1] + a[0][2];

        for (int i = 1; i < n; i++) {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + a[i][0];
            dp[i][1] = min(min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]), dp[i][0]) + a[i][1];
            dp[i][2] = min(min(dp[i - 1][1], dp[i - 1][2]), dp[i][1]) + a[i][2];
        }

        cout << t << ". " << dp[n - 1][1] << '\n';

        t++;
    }

    return 0;
}
