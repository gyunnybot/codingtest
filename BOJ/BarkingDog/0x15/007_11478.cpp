#include<iostream>
#include<set>
using namespace std;

string s;
set<string> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        string ret = "";

        for (int j = i; j < s.size(); j++) {
            ret += s[j];
            st.insert(ret);
        }     
    }

    cout << st.size();

    return 0;
}
