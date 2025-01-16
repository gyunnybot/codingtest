#include<iostream>
using namespace std;

int n, m, temp, dp[1025][1025];
int from_y, from_x, to_y, to_x;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) { //y
        for (int j = 1; j <= n; j++) { //x
            cin >> temp;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + temp;
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> from_y >> from_x >> to_y >> to_x;
        cout << dp[to_y][to_x] - dp[to_y][from_x - 1] - dp[from_y - 1][to_x] + dp[from_y - 1][from_x - 1] << '\n';
    }

    return 0;
}
