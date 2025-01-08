#include<iostream>
#include<map>
using namespace std;

int t, n;
string a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;

    while (t--) {
        cin >> n;

        map<string, int> mp;        

        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            mp[b]++;
        }

        int ret = 1;

        for (pair<string, int> pi : mp) {
            ret *= (pi.second + 1);
        }

        cout << ret - 1 << '\n';
    }

    return 0;
}
