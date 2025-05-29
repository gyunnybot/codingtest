#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;

    // 1. 각 작업이 완료되는 날짜 계산
    for (int i = 0; i < progresses.size(); ++i) {
        int remain = 100 - progresses[i];
        int day = (remain + speeds[i] - 1) / speeds[i]; // 올림 처리
        days.push_back(day);
    }

    // 2. 배포 기준일 설정 및 배포 수 계산
    int deploy_day = days[0];
    int count = 1;

    for (int i = 1; i < days.size(); ++i) {
        if (days[i] <= deploy_day) {
            count++;
        } else {
            answer.push_back(count);
            deploy_day = days[i];
            count = 1;
        }
    }

    answer.push_back(count); // 마지막 배포

    return answer;
}
