#include<iostream>
#include<unordered_map>
using namespace std;

int t, n;
string a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;

    while (t--) {
        cin >> n;

        unordered_map<string, int> ump;

        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            
            ump[b]++;
        }

        int ret = 1; //곱셈 계산 결과를 위해 1로 초기화

        for (pair<string, int> pi : ump) {
            ret *= (pi.second + 1);
        }

        cout << ret - 1 << '\n';
    }

    return 0;
}
