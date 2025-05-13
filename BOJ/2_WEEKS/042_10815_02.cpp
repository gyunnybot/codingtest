#include<iostream>
#include<algorithm> //sort, binary_search
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

    //STL 이분탐색 활용. O(logN)
    for (int i = 0; i < m; i++) {
        if (binary_search(a, a + n, b[i])) {
            cout << 1 << ' ';
        }
        else {
            cout << 0 << ' ';
        }
    }

    return 0;
}
