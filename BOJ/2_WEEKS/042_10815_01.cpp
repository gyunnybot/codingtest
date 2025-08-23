#include<iostream>
#include<algorithm> //sort
using namespace std;

int n, m, a[500001], b[500001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a, a + n);

    //투 포인터 방식을 활용해 이분탐색 직접 구현. O(logN)
    for (int i = 0; i < m; i++) {
        int st = 0;
        int ed = n - 1;
        
        bool flag = false;

        while (st <= ed) {
            int mid = (st + ed + 1) / 2;

            if (a[mid] == b[i]) {
                flag = true;
                break;
            }
            else if (a[mid] > b[i]) {
                ed = mid - 1;
            }
            else if (a[mid] < b[i]) {
                st = mid + 1;
            }
        }

        if (flag) {
            cout << 1 << ' ';
        }
        else {
            cout << 0 << ' ';
        }
    }

    return 0;
}
