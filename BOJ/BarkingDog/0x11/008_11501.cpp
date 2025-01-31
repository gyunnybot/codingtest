#include<iostream>
using namespace std;
typedef long long ll;

int t, n, a[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;

    while (t--) {
        cin >> n;

        fill(&a[0], &a[0] + 1000001, 0);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        ll ret = 0;
        int max_stock = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (a[i] < max_stock) {
                ret += (max_stock - a[i]);
            }
            else {
                max_stock = a[i];
            }
        }

        cout << ret << '\n';
    }

    return 0;
}
