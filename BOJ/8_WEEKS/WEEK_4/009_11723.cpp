#include<iostream>
#include<set>
using namespace std;

int m, x;
string s;
set<int> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> s;

        if (s == "add") {
            cin >> x;

            if (st.find(x) == st.end()) {
                st.insert(x);
            }
        }
        else if (s == "remove") {
            cin >> x;

            if (st.find(x) != st.end()) {
                st.erase(x);
            }
        }
        else if (s == "check") {
            cin >> x;

            if (st.find(x) != st.end()) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else if (s == "toggle") {
            cin >> x;

            if (st.find(x) != st.end()) {
                st.erase(x);
            }
            else {
                st.insert(x);
            }
        }
        else if (s == "all") {
            st = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
        }
        else if (s == "empty") {
            st.clear();
        }
    }

    return 0;
}
