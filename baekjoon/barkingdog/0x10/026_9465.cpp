#include<iostream>
using namespace std;

int t, n, a[2][100001], dp[2][100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;

    while (t--) {
        cin >> n;

        fill(&a[0][0], &a[0][0] + 2 * 100001, 0);

        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }
        
        dp[0][1] = a[0][1];
        dp[1][1] = a[1][1];

        for (int i = 2; i <= n; i++) {
            dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + a[0][i];
            dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + a[1][i];
        }

        cout << max(dp[0][n], dp[1][n]) << '\n';
    }

    return 0;
}
