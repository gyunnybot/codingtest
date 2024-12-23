#include<iostream>
#include<algorithm> //sort
using namespace std;

int n, a[51], b[51], ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(a, a + n, less<int>());
    sort(b, b + n, greater<int>());

    for (int i = 0; i < n; i++) {
        ret += a[i] * b[i];
    }

    cout << ret;

    return 0;
}
