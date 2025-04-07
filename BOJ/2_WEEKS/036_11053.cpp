#include<iostream>
#include<climits> //INT_MIN
using namespace std;

int n, a[1001], dp[1001];
int ret = INT_MIN;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    fill(&dp[0], &dp[0] + n, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        ret = max(ret, dp[i]);
    }

    cout << ret;

    return 0;
}
