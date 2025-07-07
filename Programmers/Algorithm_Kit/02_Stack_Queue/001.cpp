#include <vector>
#include <iostream>
#include <stack>
#include <algorithm> //reverse
using namespace std;

stack<int> stk;

vector<int> solution(vector<int> arr) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
     
    vector<int> answer;

    reverse(arr.begin(), arr.end());

    for (int i : arr) {
        if (!stk.empty()) {
            if (stk.top() != i) {
                stk.push(i);
            }
        }
        else {
            stk.push(i);
        }
    }

    while (!stk.empty()) {
        answer.push_back(stk.top());
        stk.pop();
    }

    return answer;
}
