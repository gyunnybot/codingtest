#include<iostream>
using namespace std;

int n, dp[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    dp[1] = 1;
    dp[2] = 2;

    for (int idx = 3; idx <= n; idx++) {
        dp[idx] = dp[idx - 1] + dp[idx - 2];
        dp[idx] %= 10007; //mod
    }

    cout << dp[n];

    return 0;
}
