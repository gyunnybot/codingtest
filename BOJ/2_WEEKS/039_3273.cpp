#include<iostream>
#include<algorithm> //sort
using namespace std;

int n, a[100001], x, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> x;

    sort(a, a + n);

    //two pointer
    int st = 0;
    int ed = n - 1;

    while (st < ed) { //ai + aj = x (1 ≤ i < j ≤ n)
        if (a[st] + a[ed] == x) {
            ret++;

			st++; //n개의 서로 다른 양의 정수
            ed--; //n개의 서로 다른 양의 정수
        }
        else if (a[st] + a[ed] > x) {
            ed--;
        }
        else if (a[st] + a[ed] < x) {
            st++;
        }
    }

    cout << ret;

    return 0;
}
