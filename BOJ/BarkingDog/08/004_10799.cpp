#include<iostream>
#include<stack>
using namespace std;

int ret;
string s;
stack<char> stk;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            stk.push(s[i]);
        }

        if (s[i] == ')') {
            stk.pop();

            if (s[i - 1] == '(') { //직전 문자와 짝을 이룬다면
                ret += stk.size();
            }
            else {
                ret++;
            }
        }
    }

    cout << ret;

    return 0;
}
