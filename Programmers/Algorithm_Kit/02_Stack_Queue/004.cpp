#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int>> q;

int solution(vector<int> priorities, int location) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int answer = 0;

    for (int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
    }

    while (!q.empty()) {
        int cur_priority = q.front().first;
        int cur_index = q.front().second;
        
        q.pop();
        
        bool has_higher = false; //현재 작업보다 우선순위가 높은 작업이 큐 안에 있는지 확인
        
        for (int item : priorities) {
            if (item > cur_priority) {
                has_higher = true;
                break;
            }
        }

        if (has_higher) {
            q.push({cur_priority, cur_index});
        }
        else {
            answer++;
            priorities[cur_index] = -1;

            if (cur_index == location) {
                break;
            }
        }
    }

    return answer;
}
