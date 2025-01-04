#include<iostream>
using namespace std;

int n, x, temp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> temp;

        if (temp < x) {
            cout << temp << ' ';
        }
    }

    return 0;
}
