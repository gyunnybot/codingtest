#include<iostream>
#include<algorithm> //sort
using namespace std;

int n, a[1001], b[1001], ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++) {
        b[i] = b[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++) {
        ret += b[i];
    }

    cout << ret;

    return 0;
}
