#include<iostream>
#include<map>
using namespace std;

int n, m;
string s;
map<string, int> mp;
map<int, string> mp2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> s;

        mp[s] = i + 1;
        mp2[i + 1] = s;
    }

    for (int i = 0; i < m; i++) {
        cin >> s;

        if (atoi(s.c_str()) == 0) { //s가 문자열이라면
            cout << mp[s] << '\n';
        }
        else { //숫자라면
            cout << mp2[atoi(s.c_str())] << '\n';
        }
    }

    return 0;
}
