#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> answer;
    vector<int> days;

    for (int i = 0; i < progresses.size(); i++) {
        int remain = 100 - progresses[i];
        int day = remain / speeds[i];

        if (remain % speeds[i]) {
            day++;
        }

        days.push_back(day);
    }

    int deploy_day = days[0];
    int count = 1;
    
    for (int i = 1; i < days.size(); i++) {
        if (days[i] <= deploy_day) {
            count++;
        }
        else {
            answer.push_back(count);

            deploy_day = days[i];
            count = 1;
        }
    }

    answer.push_back(count);

    return answer;
}
