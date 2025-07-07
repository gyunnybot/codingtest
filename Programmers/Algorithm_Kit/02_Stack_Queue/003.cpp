#include <string>
#include <iostream>
#include <stack>
using namespace std;

stack<char> stk;

bool solution(string s) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    bool answer = true;

    for (char c : s) {
        if (stk.empty()) {
            if (c == ')') {
                answer = false;
                break;
            }
            else {
                stk.push(c);
            }
        }
        else {
            if (c == ')' && stk.top() == '(') {
                stk.pop();
            }
            else {
                stk.push(c);
            }
        }
    }

    if (!stk.empty()) {
        answer = false;
    }

    return answer;
}
