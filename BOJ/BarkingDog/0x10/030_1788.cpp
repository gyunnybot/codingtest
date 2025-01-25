#include<iostream>
using namespace std;

int n, dp[1000001];
int mod = 1000000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= (int)abs(n); i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }   

    if (n > 0) {
        cout << 1 << '\n' << dp[n];
    }
    else if (n == 0) {
        cout << 0 << '\n' << 0;
    }
    else {
        n = (int)abs(n);

        if (n % 2 == 0) {
            cout << -1 << '\n' << dp[n];
        }
        else {
            cout << 1 << '\n' << dp[n];
        }
    }

    return 0;
}
