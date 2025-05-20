#include <string>
#include <vector>
#include <algorithm> //max_element
#include <iostream>
using namespace std;

int cnt[3];

vector<int> solution(vector<int> answers) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> answer;
    
    vector<vector<int>> list = {
        {1, 2, 3, 4, 5},
        {2, 1, 2, 3, 2, 4, 2, 5},
        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    };
    
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == list[0][i % list[0].size()]) cnt[0]++;
        if (answers[i] == list[1][i % list[1].size()]) cnt[1]++;
        if (answers[i] == list[2][i % list[2].size()]) cnt[2]++;
    }
    
    int max_cnt = *max_element(cnt, cnt + 3);
    
    for (int i = 0; i < 3; i++) {
        if (cnt[i] == max_cnt) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}
