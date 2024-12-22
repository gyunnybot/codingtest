#include<iostream>
using namespace std;

int n, m, temp, dp[100001], s, e;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> temp;
        dp[i] = dp[i - 1] + temp;
    }

    while (m--) {
        cin >> s >> e;
        cout << dp[e] - dp[s - 1] << '\n';
    }

    return 0;
}
