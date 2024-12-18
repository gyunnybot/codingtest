#include<iostream>
using namespace std;

int n, s, a[21], ret;

void recur(int idx, int sum) {
    if (idx == n) {
        if (sum == s) {
            ret++;        
        }

        return;
    }

    recur(idx + 1, sum + a[idx]);
    recur(idx + 1, sum);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    recur(0, 0);

    if (s == 0) ret--; //부분 수열이므로 공집합은 제외

    cout << ret;

    return 0;
}
