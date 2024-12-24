#include<iostream>
#include<climits> //INT_MIN
using namespace std;

int n, t[1500001][2];
int dp[1500001];

int recur(int day) {
    if (day > n) {
        return INT_MIN;
    }

    if (day == n) {
        return 0;
    }

    if (dp[day]) { //메모이제이션
        return dp[day];
    }

    dp[day] = max(recur(day + 1), recur(day + t[day][0]) + t[day][1]);

    return dp[day];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> t[i][j];
        }
    }

    cout << recur(0);

    return 0;
}
