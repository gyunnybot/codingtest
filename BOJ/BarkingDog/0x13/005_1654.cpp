#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int k, n, a[10001];

bool cut_wire(ll x) {
    ll cur = 0;

    for (int i = 0; i < k; i++) {
        cur += a[i] / x;
    }

    return cur >= n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> k >> n;

    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }

    sort(a, a + k);

    ll st = 1;
    ll ed = *prev(a + k);

    while (st < ed) {
        ll mid = (st + ed + 1) / 2;

        if (cut_wire(mid)) {
            st = mid;
        }
        else {
            ed = mid - 1;
        }
    }

    cout << st;

    return 0;
}
