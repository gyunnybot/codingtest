#include<iostream>
#include<algorithm> //sort
using namespace std;
typedef long long ll;

int n, m;
ll a[1001], ret; //long long 주의!!!!!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (m--) {
        sort(a, a + n);

        ll mix = a[0] + a[1];

        a[0] = mix;
        a[1] = mix;
    }

    for (ll i : a) {
        ret += i;
    }

    cout << ret;

    return 0;
}
