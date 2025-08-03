#include<iostream>
#include<string> //to_string
using namespace std;

int n, cnt;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 666; cnt < n; i++) {
        s = to_string(i);

        if (s.find("666") != string::npos) {
            cnt++;
        }
    }

    cout << s;

    return 0;
}
