#include<iostream>
#include<unordered_map>
using namespace std;

int n, m;
string s;
unordered_map<string, int> ump;
unordered_map<int, string> ump2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> s;

        ump[s] = i + 1;
        ump2[i + 1] = s;
    }

    for (int i = 0; i < m; i++) {
        cin >> s;

        if (atoi(s.c_str()) == 0) { //s가 문자열이라면
            cout << ump[s] << '\n';
        }
        else { //숫자라면
            cout << ump2[atoi(s.c_str())] << '\n';
        }
    }

    return 0;
}
