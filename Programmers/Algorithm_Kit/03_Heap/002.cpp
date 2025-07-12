#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm> //sort
using namespace std;

class cmp {
public:
    bool operator() (pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }

        return a.second > b.second; //오름차순 = pq greater = 최소 힙
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

int solution(vector<vector<int>> jobs) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int answer = 0;

    sort(jobs.begin(), jobs.end());

    int time = 0;
    int idx = 0;

    while (idx < jobs.size() || !pq.empty()) {
        while (idx < jobs.size() && jobs[idx][0] <= time) {
            pq.push({ jobs[idx][0], jobs[idx][1] });
            idx++;
        }

        if (!pq.empty()) {
            pair<int, int> cur = pq.top(); pq.pop();

            time += cur.second;
            answer += time - cur.first;
        }
        else {
            time = jobs[idx][0];  //다음 작업의 시작 시간으로 점프
        }
    }

    return answer / jobs.size();
}
