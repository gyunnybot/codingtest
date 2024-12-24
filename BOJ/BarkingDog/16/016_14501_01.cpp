#include<iostream>
using namespace std;

int n, t[16], p[16], dp[16], ret;

void recur(int day, int pay) {
    if (day > n) {
        return;
    }

    if (day == n) {
        ret = max(ret, pay);
        return;
    }

    recur(day + 1, pay);
    recur(day + t[day], pay + p[day]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t[i] >> p[i];
    }

    recur(0, 0);

    cout << ret;

    return 0;
}
