#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<string, int> ump;
string s, e, q, t, name;
int ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s >> e >> q;

    while (cin >> t >> name) {
        if (t <= s) {
            ump[name] = 1;
        }
        else if (e <= t && t <= q) {
            if (ump[name] == 1) {
                ump[name] = 2; //중복 방지를 위해
                ret++;
            }
        }
    }

    cout << ret;

    return 0;
}
