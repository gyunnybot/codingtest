#include<iostream>
using namespace std;

int n, m, temp, dp[1025][1025];
int a1, a2, b1, b2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> temp;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + temp;
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> a1 >> b1 >> a2 >> b2;
        cout << dp[a2][b2] - dp[a2][b1 - 1] - dp[a1 - 1][b2] + dp[a1 - 1][b1 - 1] << '\n';
    }

    return 0;
}
