#include<iostream>
#include<set>
using namespace std;

string s, ret;
set<string> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            ret += s[j];
            st.insert(ret);
        }

        ret = "";
    }

    cout << st.size();

    return 0;
}
