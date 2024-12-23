#include<iostream>
#include<algorithm> //sort
using namespace std;

int n, a[100001], ret; //a[i]는 10,000을 넘지 않는 자연수

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        ret = max(ret, (n - i) * a[i]);
    }

    cout << ret;

    return 0;
}
