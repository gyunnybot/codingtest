#include<iostream>
using namespace std;

string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;

    while (s.size()) {
        if (s.substr(0, 2) != "pi" && s.substr(0, 2) != "ka" && s.substr(0, 3) != "chu") break;

        if (s.substr(0, 2) == "pi" || s.substr(0, 2) == "ka") {
            s.erase(0, 2);
        }

        if (s.substr(0, 3) == "chu") {
            s.erase(0, 3);
        }
    }

    if (s.size()) {
        cout << "NO";
    }
    else {
        cout << "YES";
    }
    
    return 0;
}
