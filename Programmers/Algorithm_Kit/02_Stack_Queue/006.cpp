#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

stack<int> stk;

vector<int> solution(vector<int> prices) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n = prices.size();

    vector<int> answer(n, 0);
    
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && prices[stk.top()] > prices[i]) {
            int top = stk.top(); stk.pop();

            answer[top] = i - top;
        }

        stk.push(i);
    }

    while (!stk.empty()) {
        int top = stk.top(); stk.pop();

        answer[top] = n - 1 - top;
    }

    return answer;
}
