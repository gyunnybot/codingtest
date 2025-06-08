#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> answer;
    vector<int> days;

    //각 작업이 완료되는 날짜 계산
    for (int i = 0; i < progresses.size(); i++) {
        int remain = 100 - progresses[i];
        int day = remain / speeds[i];

        if (remain % speeds[i]) { //올림
            day++;
        }

        days.push_back(day);
    }

    //배포 기준일 설정 및 배포 수 계산
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

    answer.push_back(count); //마지막 배포 수 계산

    return answer;
}
