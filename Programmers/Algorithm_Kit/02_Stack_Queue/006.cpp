#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

vector<int> solution(vector<int> prices) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> answer;

    for (int i = 0; i < prices.size(); i++) {
        q.push(prices[i]);
    }

    while (!q.empty()) {
        for (int i = 0; i < prices.size(); i++) {
            int cur = q.front(); q.pop();
            int cnt = 0;

            if (i + 1 < prices.size()) {
                for (int j = i + 1; j < prices.size(); j++) {
                    cnt++;

                    if (cur > prices[j]) break;
                }
            }

            answer.push_back(cnt);
        }
    }

    return answer;
}
