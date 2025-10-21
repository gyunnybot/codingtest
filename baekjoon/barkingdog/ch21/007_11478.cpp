#include<iostream>
#include<unordered_set>
using namespace std;

string s;
unordered_set<string> ust;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        string ret = "";

        for (int j = i; j < s.size(); j++) {
            ret += s[j];
            ust.insert(ret);
        }
    }

    cout << ust.size();

    return 0;
}
